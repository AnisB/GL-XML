<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

	<xsl:template match="/">
		<html>
			<body>
				<h2>Titre : <xsl:value-of select="rapport/titre"/></h2>
				<br/>
				<h4>Auteur</h4>
				<xsl:value-of select="rapport/auteur/prenom"/>
				<xsl:value-of select="rapport/auteur/nom"/>
				<br/><br/>
				Resumé : <xsl:value-of select="rapport/resume"/>
				<br/>
				<xsl:for-each select="rapport/chapitre">
					<h5><xsl:value-of select="titre"/></h5>
					<xsl:for-each select="section">
						<xsl:value-of select="titre"/>
						<br/><br/>
						<xsl:value-of select="p"/>
						<br/><br/>
					</xsl:for-each>

				</xsl:for-each>

			</body>
		</html>
	</xsl:template>

</xsl:stylesheet> 