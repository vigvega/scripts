#################################
#	PDF CONVERTER		#
#################################

#! /bin/bash

pacg=$(which ghostscript)
pacl=$(which lowriter)

if [ "$pacg" = "" ] || [ "$pacl" = "" ]
then
	echo "Error. Try: sudo apt-get install libreoffice && sudo apt-get install ghostscript"
else
	ls
	read -p "File to convert:" file
	# Compruebo si existe el fichero
	if [ -f "$file" ]
	then
		echo -e "\e[0;32mProcessing...\e[0m"
		# Convierto el archivo a pdf
		lowriter --convert-to pdf $file
		echo -e "\e[0;32mDone\e[0m"
	else
		echo "File not found :("
	fi
fi
