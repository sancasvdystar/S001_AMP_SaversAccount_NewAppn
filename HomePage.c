HomePage()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	
	lr_start_transaction("S001_T001_AMPSavAcc_HomePage");

	web_reg_find("Search=Body",
		"Text=AMP is here to help",
		LAST);

	web_url("www.{P_Host}", 
		"URL=http://www.{P_Host}/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://www.{P_Host}/ddc/public/ui/assets/ddc-fonts/ddc-fonts.css", "Referer=https://www.{P_Host}/etc/designs/amp-au/clientlibs/clientlib-site.css", ENDITEM, 
		"Url=https://www.{P_Host}/etc/designs/amp-au/assets/aa8fe13f4c832769bd0ab2ea7e247013.svg", "Referer=https://www.{P_Host}/etc/designs/amp-au/clientlibs/clientlib-site.css", ENDITEM, 
		"Url=https://www.{P_Host}/etc/designs/amp-au/clientlibs/legacy-nps.js?_=1634859408956", "Referer=https://www.{P_Host}/", ENDITEM, 
		"Url=https://www.{P_Host}/etc/designs/amp-au/assets/819af3d3abdc9f135d49b80a91e2ff4c.woff2", "Referer=https://www.{P_Host}/etc/designs/amp-au/clientlibs/clientlib-site.css", ENDITEM, 
		"Url=https://www.{P_Host}/etc/designs/amp-au/assets/98c3ea22ad6bca213fa88175f7d9ffaf.woff2", "Referer=https://www.{P_Host}/etc/designs/amp-au/clientlibs/clientlib-site.css", ENDITEM, 
		"Url=https://www.{P_Host}/etc/designs/amp-au/assets/2525a15d1fb3ce824a7aad5e07ba2513.ttf", "Referer=https://www.{P_Host}/etc/designs/amp-au/clientlibs/clientlib-site.css", ENDITEM, 
		"Url=https://www.{P_Host}/etc/designs/amp-au/assets/ce62fa71a1a38af297b433e85d36d83f.woff2", "Referer=https://www.{P_Host}/etc/designs/amp-au/clientlibs/clientlib-site.css", ENDITEM, 
		"Url=https://www.{P_Host}/etc/designs/amp-au/assets/33543c5cc5d88f5695dd08c87d280dfd.woff2", "Referer=https://www.{P_Host}/etc/designs/amp-au/clientlibs/clientlib-site.css", ENDITEM, 
		"Url=https://www.{P_Host}/etc/designs/amp-au/assets/5c32de29c638fdf3bb4adc662a0ad595.woff2", "Referer=https://www.{P_Host}/etc/designs/amp-au/clientlibs/clientlib-site.css", ENDITEM, 
		"Url=https://www.{P_Host}/etc/designs/amp/assets/fonts/xtreme.woff", "Referer=https://www.{P_Host}/etc/designs/amp/clientLibraries/icons-libs.css", ENDITEM, 
		LAST);


	web_url("www.{P_Host}_2", 
		"URL=https://www.{P_Host}/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.{P_Host}/", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	
	lr_end_transaction("S001_T001_AMPSavAcc_HomePage", LR_AUTO);
	
	lr_think_time(t);

	return 0;
}