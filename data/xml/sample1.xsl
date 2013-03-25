<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

	<xsl:template match="/">
		<html >
			<head dir="" lang= "" xml:lang=""></head>
			<body class="" style= "">
				<h2 class="" style= "">My CD Collection</h2>
				<table ><tr><td>Title</td><td>Artist</td></tr>
				<xsl:apply-templates select=""/>
			</table>
		</body>
	</html>
</xsl:template>

<xsl:template match="cd">
	<tr>
		<xsl:apply-templates select="title"/>
		<xsl:apply-templates select="artist"/>
	</tr>
</xsl:template>

<xsl:template match="title">
	<td><span class="" style="color:#ff0000">
	<xsl:value-of select="."/></span></td>
</xsl:template>

<xsl:template match="artist">
	<td><span  class="" style="color:#00ff00">
		<xsl:value-of select="."/></span></td>
	</xsl:template>

</xsl:stylesheet>