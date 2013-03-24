#include <boost/program_options.hpp>
#include <parse/parser.h>
#include <parse/checker.h>
namespace po = boost::program_options;

#include <iterator>
using namespace std;

int main(int ac, char* av[])
{
    try {

        po::options_description desc("Options");
        desc.add_options()
        ("help", "produce  the help message")
        ("xml", po::value< vector<string> >(), "--xml <filename> [<filename>]* [--ckxml], The Xml files you want to analyse ")
        ("ckxml", "--ckxml, Check XML: If you want to check that it respects it's DTD")
        ("xsl", po::value<string>(), "--xsl <filename> -mop <filename> [<filename>]*, The xsl file you want to use")
        ("ckxsl", "--ckxsl, Check XSL; If you want to check that it respects it's standard xsl DTD")
        ("mop",po::value< vector<string> >(), "--mop <filename> [<filename>]*, Mandatory if you introduced an xsl file, you should specify a file name for each input")
        ;

        po::variables_map vm;        
        po::store(po::parse_command_line(ac, av, desc), vm);
        po::notify(vm);    
        if (vm.count("help")) {
            cout << desc << "\n";
            return 1;
        }
        if (vm.count("xml")) 
        {
            // std::vector<string>::iterator it= (vm["xml"].as<vector<string> >());
            cout << "Input files are: " 
            << (vm["xml"].as< vector<string> >())[0] << "\n";
            std::string xmlNameFile=(vm["xml"].as< vector<string> >())[0] ;
            std::pair<string*,XMLDocument*> xmlparseResult;
            try
            {
                xmlparseResult = Parser::parseXML(xmlNameFile);
            }
            catch(int e)
            {
                cout<<"Error while parsing, it could mean file not found or it's not respecting the xml grammar"<<endl;
            }
            if (vm.count("ckxml")) 
            {
                DTDDocument* dtdparseResult = Parser::parseDTD(*(xmlparseResult.first)); 
                if(Checker::check(xmlparseResult.second,dtdparseResult))
                    std::cout<<"The file "<<xmlNameFile<<" is correctly constructed"<<endl;
                else
                    std::cout<<"The file "<<xmlNameFile<<" isn't correctly constructed"<<endl;;


            }
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