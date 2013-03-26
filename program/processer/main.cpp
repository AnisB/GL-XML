#include <boost/program_options.hpp>
#include <parse/parser.h>
#include <parse/checker.h>
#include <xsl/xsldocument.h>
#include <fstream>
#include <sstream>
namespace po = boost::program_options;

#include <iterator>
using namespace std;

std::string extractFileName( const std::string path )
{
    string result= path.substr( 0,path.find_last_of( '/' )+1 );

    return result;
}



int main(int ac, char* av[])
{
    try {

        po::options_description desc("Options");
        desc.add_options()
        ("help", "produce  the help message")
        ("grammarxml", po::value<string>(), "--grammarxml <filename> is the file you want to check (XML)")
        ("grammardtd", po::value<string>(), "--grammarsts <filename> is the file you want to check (DTD)")
        ("xml", po::value< vector<string> >(), "--xml <filename> [<filename>]* [--ckxml], The Xml files you want to analyse ")
        ("ckxml", "--ckxml, Check XML: If you want to check that it respects it's DTD")
        ("xsl", po::value<string>(), "--xsl <filename> -html <filename> [<filename>]*, The xsl file you want to use")
        ("ckhtmlxsl", "--ckhtmlxsl, Check XSL is for an HTML ouput; If you want to check that it respects it's standard xsl DTD")
        ("html",po::value< vector<string> >(), "--html <output> [<ouput>]*, Mandatory if you introduced an xsl file, you should specify a file name for each input")
        ;

        po::variables_map vm;        
        po::store(po::parse_command_line(ac, av, desc), vm);
        po::notify(vm);    
        if (vm.count("help")) {
            cout << desc << "\n";
            return 1;
        }


        if (vm.count("grammarxml")) {
            try
            {
                std::pair<string*,XMLDocument*> xmlparseResult;
                xmlparseResult = Parser::parseXML(vm["grammarxml"].as<string>());
            }
            catch(int e)
            {
                cout<<"Error while parsing this xml, it could mean file not found or it's not respecting the xml grammar"<<endl;
                return -1;
            }
            return 1;
        }
        if (vm.count("grammardtd")) {
            try
            {
                DTDDocument* dtdparseResult;
                dtdparseResult = Parser::parseDTD(vm["grammardtd"].as<string>());
            }
            catch(int e)
            {
                cout<<"Error while parsing this dtd, it could mean file not found or it's not respecting the dtd grammar"<<endl;
                return -1;
            }
            return 1;
        }
        if (vm.count("xml")) 
        {
            std::vector<std::pair<string*,XMLDocument*> > xmlFileList;
            std::vector<std::string> list=(vm["xml"].as< vector<string> >()) ;
            for(std::vector<string>::iterator it =list.begin(); it!=list.end();it++)
            {
                try
                {
                    std::pair<string*,XMLDocument*> xmlparseResult;
                    xmlparseResult = Parser::parseXML((*it));
                    xmlFileList.push_back(xmlparseResult);
                }
                catch(int e)
                {
                    cout<<"Error while parsing an xml, it could mean file not found or it's not respecting the xml grammar"<<endl;
                    return -1;
                }
            }
            if (vm.count("ckxml")) 
            {
                int i=0;
                for(std::vector<std::pair<string*,XMLDocument*> >::iterator it =xmlFileList.begin(); it!=xmlFileList.end();it++)
                {
                    if((it->first)==NULL)
                    {
                        cerr<<"No DTD for a file, error quitting"<<endl;
                        return -1;
                    }

                    DTDDocument* dtdparseResult ;

                    try
                    {
                        dtdparseResult = Parser::parseDTD(extractFileName(vm["xml"].as< vector<string> >()[i])+(*(it->first))); 
                    }
                    catch(int e)
                    {
                        cout<<"Error while parsing dtd, it could mean file not found or it's not respecting the dtd grammar"<<endl;
                        return -1;
                    }

                    if(Checker::check(it->second,dtdparseResult))
                    {
                        std::cout<<"The file "<<vm["xml"].as< vector<string> >()[i]<<" is correctly constructed"<<endl;
                    }
                    else
                    {
                        std::cout<<"Warning: The file "<<vm["xml"].as< vector<string> >()[i]<<" isn't correctly constructed"<<endl;
                    }
                    i++;
                }

            }
            if (vm.count("xsl")) 
            {
                std::pair<string*,XMLDocument*> xslparseResult;                
                try
                {
                    xslparseResult = Parser::parseXML(vm["xsl"].as<string>());
                }
                catch(int e)
                {
                    cout<<"Error while parsing the xsl, it could mean file not found or it's not respecting the xml grammar"<<endl;
                    return -1;
                }
                if (vm.count("ckhtmlxsl")) 
                {
                    DTDDocument* dtdparseResult ;

                    try
                    {
                        dtdparseResult = Parser::parseDTD("../../../data/htmldtd/html.dtd"); 

                    }
                    catch(int e)
                    {
                        cout<<"Error while parsing dtd, it could mean file not found or it's not respecting the xml grammar"<<endl;
                        return -1;
                    }


                    if(Checker::check(xslparseResult.second,dtdparseResult))
                    {
                        std::cout<<"The file "<<vm["xsl"].as<string>()<<" is correctly constructed"<<endl;
                    }
                    else
                    {
                        std::cout<<"Warning: The file "<<vm["xsl"].as<string>()<<" isn't correctly constructed"<<endl;
                    }
                }

                if (vm.count("html")) 
                {
                    if (vm["html"].as< vector<string> >().size()!=vm["xml"].as< vector<string> >().size())
                    {
                        cerr<< "The number of input and output aren't equal."<<endl;
                        return -1;
                    }
                    int i=0;
                    for(std::vector<std::pair<string*,XMLDocument*> >::iterator it =xmlFileList.begin(); it!=xmlFileList.end();it++)
                    {
                        XSLDocument newDoc(xslparseResult.second,it->second);
                        std::string result = newDoc.process();
                        ofstream myfile;
                        myfile.open (vm["html"].as< vector<string> >()[i].c_str());
                        myfile <<result;
                        myfile.close();
                        std::cout<<"Note: The file "<<vm["html"].as< vector<string> >()[i].c_str()<<" was generated"<<endl;
                        i++;

                    }
                    return 0;
                }
            }
        }
        else
        {
            cerr<< "You can't use this option without the previous required"<<endl;
            return -1;
        }

    }
    catch(exception& e) {
        cerr << "error: " << e.what() << "\n";
        return 1;
    }
    catch(...) {
        cerr << "Exception of unknown type!\n";
    }

    return 0;
}