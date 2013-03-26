<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/">
    <html>
      <body>
        <h2>My CD Collection</h2>
        <table border="1">
          <tr bgcolor="#9acd32">
            <th>Title</th>
            <th>Artist</th>
            <th>Country</th>
            <th>Company</th>
            <th>Price</th>
            <th>Year</th>
          </tr>
          <xsl:for-each select="catalog/cd">
            <tr>
              <td><xsl:value-of select="title"/></td>
              <td><xsl:value-of select="artist"/></td>
              <td><xsl:value-of select="country"/></td>
              <td><xsl:value-of select="company"/></td>
              <xsl:choose>
                <xsl:when test="price &gt; 10">
                 <td bgcolor="#ff00ff">
                   <xsl:value-of select="price"/>
                 </td>
               </xsl:when>
               <xsl:otherwise>
                 <td bgcolor="b4f892">
                   <xsl:value-of select="price"/></td>
                 </xsl:otherwise>
               </xsl:choose>
               <td><xsl:value-of select="year"/></td>
             </tr>
           </xsl:for-each>
         </table>
       </body>
     </html>
   </xsl:template>
 </xsl:stylesheet>