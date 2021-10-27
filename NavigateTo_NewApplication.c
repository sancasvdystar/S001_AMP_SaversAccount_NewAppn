NavigateTo_NewApplication()
{
	
	lr_start_transaction("S001_T002_AMPSavAcc_Banking");
	
	web_reg_find("Search=Body",
		"Text=control of your money",
		LAST);

	web_url("banking", 
		"URL=https://www.{P_Host}/banking", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.{P_Host}/", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/content/dam/amp-au/authoring/promotion-banner/banner-background-1.jpg", ENDITEM, 
		"Url=/content/dam/amp-au/images/banking-hub/banners/kombi_van_product_promo.jpg", ENDITEM, 
		"Url=/etc/designs/amp-au/clientlibs/legacy-nps.js?_=1634859451120", ENDITEM, 
		LAST);


	lr_end_transaction("S001_T002_AMPSavAcc_Banking", LR_AUTO);
	
	lr_think_time(t);	
	
	lr_start_transaction("S001_T003_AMPSavAcc_SavingsAccount");

	/* click savings account */

	
	web_reg_find("Search=Body",
		"Text=High Interest Saving Accounts",
		LAST);

	web_url("savings-accounts", 
		"URL=https://www.{P_Host}/banking/savings-accounts", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.{P_Host}/banking", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../content/dam/amp-au/images/thumbnail/my-amp.jpg", ENDITEM, 
		"Url=../content/dam/amp-au/images/thumbnail/debit-card.jpg", ENDITEM, 
		"Url=../content/dam/amp-au/images/thumbnail/savings-calculator.jpg", ENDITEM, 
		"Url=../etc/designs/amp-au/clientlibs/legacy-nps.js?_=1634859466075", ENDITEM, 
		LAST);

	lr_end_transaction("S001_T003_AMPSavAcc_SavingsAccount", LR_AUTO);
	
	lr_think_time(t);
	/* learn more */	
	
	lr_start_transaction("S001_T004_AMPSavAcc_Learnmore");


	web_reg_find("Search=Body",
		"Text=The AMP Saver is an award-winning",
		LAST);

	web_url("amp-saver-account", 
		"URL=https://www.{P_Host}/banking/savings-accounts/amp-saver-account", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.{P_Host}/banking/savings-accounts", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/etc/designs/amp-au/clientlibs/legacy-nps.js?_=1634859487325", ENDITEM, 
		LAST);


	lr_end_transaction("S001_T004_AMPSavAcc_Learnmore", LR_AUTO);

	lr_think_time(t);
	/* open an account */
	
	lr_start_transaction("S001_T005_AMPSavAcc_OpenAnAccount");



	web_reg_find("Search=Body",
		"Text=AMP Saver Account",
		LAST);

	web_url("saver-account", 
		"URL=https://secure.{P_Host}/ddc/public/ui/saver-account/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.{P_Host}/banking/savings-accounts/amp-saver-account", 
		"Snapshot=t38.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://www.{P_Host}/etc/designs/amp/clientLibraries/icons-libs.min.css", "Referer=https://secure.{P_Host}/", ENDITEM, 
		"Url=../assets/ddc-fonts/ddc-fonts.css", ENDITEM, 
		"Url=styles.0761fd239214ab23c67e.css", ENDITEM, 
		"Url=config.js", ENDITEM, 
		"Url=runtime.a5b4734854bf1bbfa0a2.js", ENDITEM, 
		"Url=https://www.{P_Host}/fonts/282695/EFFED685B8BB01EC4.css", "Referer=https://secure.{P_Host}/", ENDITEM, 
		"Url=polyfills.7a1195e67f8d2d0712cb.js", ENDITEM, 
		"Url=main.f7ae96794faee45a389f.js", ENDITEM, 
		LAST);



	web_url("saver-account_2", 
		"URL=https://secure.{P_Host}/ddc/public/ui/saver-account/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://secure.{P_Host}/ddc/public/ui/saver-account/", 
		"Snapshot=t41.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../assets/ddc-fonts/ddc-fonts.css", ENDITEM, 
		"Url=assets/images/Intro-background_min.jpg", ENDITEM, 
		LAST);



/*Correlation comment - Do not change!  Original value='Fri Sep 24 2021 13:59:44 GMT+1000' Name ='C_updateddate' Type ='Manual'*/
	web_reg_save_param_json(
		"ParamName=C_updateddate",
		"QueryString=$.cq:lastModified",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);

	web_url("_jcr_content.json", 
		"URL=https://www.{P_Host}/content/amp-secure/my-amp/ddc/saver-account/DDO/_jcr_content.json", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://secure.{P_Host}/", 
		"Snapshot=t44.inf", 
		"Mode=HTML", 
		LAST);


	

	lr_end_transaction("S001_T005_AMPSavAcc_OpenAnAccount", LR_AUTO);

	lr_think_time(t);
	
	

	
	//"SAVERACCOUNT","securityToken":"802cd689-f4ce-4b13-9113-501f678392f1","marketingCorrelationIds":
	
	web_reg_save_param("C_SecToken",
		"LB=SAVERACCOUNT\",\"securityToken\":\"",
		"RB=\",\"marketingCorrelationIds\":",
		LAST);	  
	

/*Correlation comment - Do not change!  Original value='5077086245' Name ='C_formId' Type ='Manual'*/
	web_reg_save_param_json(
		"ParamName=C_formId",
		"QueryString=$.payload.meta.id",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);

	web_reg_find("Search=Body",
		"Text=SaverAccount",
		LAST);
		
	lr_start_transaction("S001_T006_AMPSavAcc_SelectJustMe");

	web_custom_request("save", 
		"URL=https://secure.{P_Host}/ddc/public/api/forms/save?&formName=SaverAccount", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://secure.{P_Host}/ddc/public/ui/saver-account/", 
		"Snapshot=t50.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"welcome\":{\"tags\":\"[\\\"customer\\\"]\",\"continueApplication\":null,\"newApplication\":true},\"newOrExistingCustomer\":{\"customerType\":\"New\"},\"captcha\":{},\"adviser\":{},\"singleOrJoint\":{\"applicationType\":\"Individual\"},\"applicants\":[{\"personalDetails\":{\"basicInfo\":{\"firstName\":null,\"surName\":null,\"dateOfBirth\":null,\"scvId\":null,\"hasAdpId\":null,\"title\":{\"SelectedItem\":null,\"Query\":null},\"middleName\":null},\"contactDetails\":{\"emailAddress\":null,\""
		"mobilePhone\":null,\"homePhone\":null},\"address\":{\"addresses\":{\"isAnyAddressInternational\":false,\"residentialAddress\":{\"isManualSearch\":false,\"search\":{\"selectedItem\":null,\"query\":null},\"manualAddress\":{\"country\":{\"SelectedItem\":\"AUS\",\"Query\":\"Australia\"},\"addressLine1\":null,\"addressLine2\":null,\"buildingName\":null,\"floorNumber\":null,\"unitNumber\":null,\"subBuildingNumber\":null,\"streetNumber\":null,\"streetName\":null,\"streetType\":{\"SelectedItem\":null,\""
		"Query\":null},\"poBox\":null,\"suburb\":null,\"state\":{\"SelectedItem\":null,\"Query\":null},\"ruralDelivery\":null,\"city\":null,\"province\":null,\"postCode\":null,\"dpid\":null,\"barcode\":null,\"isInternational\":false},\"isItPoBox\":null},\"postalAndResidentialAreSame\":true},\"editLocked\":null,\"externallyMaintainedAddress\":null}},\"furtherQuestions\":{\"taxFileNumber\":{\"hasTaxFileNumber\":null,\"ok\":null},\"foreignTaxResident\":{\"attempts\":0,\"addressFDN\":\""
		"applicants.0.personalDetails.address\",\"crsStatus\":null,\"addresses\":[null,null],\"countries\":[\"AUS\",\"AUS\"],\"entityType\":\"individual\",\"isForeignTaxResident\":null},\"reasonablenessOutcome\":{\"ok\":null},\"amlQuestions\":{\"primarySourceOfWealth\":{\"SelectedItem\":null,\"Query\":null},\"sourceOfFundsForAccount\":{\"SelectedItem\":null,\"Query\":null},\"reasonForOpeningAccount\":{\"SelectedItem\":null,\"Query\":null}}},\"identityCheck\":{\"identity\":{\"greenIdIdentityCheck\":{\""
		"verificationId\":null,\"verificationStatus\":null},\"creditHeaderCheckbox\":null}},\"tmdQuestions\":{}}],\"accountDetails\":{\"preferences\":{},\"declarations\":{\"lastStep\":{\"privacyDeclaration\":null,\"acceptTandCsDeclaration\":null,\"acceptCRSDeclaration\":null}}},\"review\":{},\"personalOrSoleTrader\":{\"accountType\":\"personal\"}}", 
		LAST);


	lr_end_transaction("S001_T006_AMPSavAcc_SelectJustMe", LR_AUTO);

	lr_think_time(t);
	/* proceed */

	lr_start_transaction("S001_T007_AMPSavAcc_Proceed");


	web_reg_find("Search=Body",
		"Text=statusCode\":200",
		LAST);

	web_custom_request("save_2",
		"URL=https://secure.{P_Host}/ddc/public/api/forms/save?formId={C_formId}&checkSecurityToken={C_SecToken}&formName=SaverAccount",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://secure.{P_Host}/ddc/public/ui/saver-account/",
		"Snapshot=t53.inf",
		"Mode=HTML",
		"EncType=application/json",
		"BodyBinary={\"welcome\":{\"tags\":\"[\\\\\"customer\\\\\"]\",\"continueApplication\":null,\"newApplication\":true},\"newOrExistingCustomer\":{\"customerType\":\"New\"},\"captcha\":{},\"adviser\":{},\"singleOrJoint\":{\"applicationType\":\"Individual\"},\"applicants\":[{\"personalDetails\":{\"basicInfo\":{\"firstName\":null,\"surName\":null,\"dateOfBirth\":null,\"scvId\":null,\"hasAdpId\":null,\"title\":{\"SelectedItem\":null,\"Query\":null},\"middleName\":null},\"contactDetails\":{\"emailAddress\":null,\"mobilePhone\":null,\"homePhone\":null},\"address\":{\"addresses\":{\"isAnyAddressInternational\":false,\"residentialAddress\":{\"isManualSearch\":false,\"search\":{\"selectedItem\":null,\"query\":null},\"manualAddress\":{\"country\":{\"SelectedItem\":\"AUS\",\"Query\":\"Australia\"},\"addressLine1\":null,\"addressLine2\":null,\"buildingName\":null,\"floorNumber\":null,\"unitNumber\":null,\"subBuildingNumber\":null,\"streetNumber\":null,\"streetName\":null,\"streetType\":{\"SelectedItem\":null,\"Query\":null}"
		",\"poBox\":null,\"suburb\":null,\"state\":{\"SelectedItem\":null,\"Query\":null},\"ruralDelivery\":null,\"city\":null,\"province\":null,\"postCode\":null,\"dpid\":null,\"barcode\":null,\"isInternational\":false},\"isItPoBox\":null},\"postalAndResidentialAreSame\":true},\"editLocked\":null,\"externallyMaintainedAddress\":null}},\"furtherQuestions\":{\"taxFileNumber\":{\"hasTaxFileNumber\":null,\"ok\":null},\"foreignTaxResident\":{\"attempts\":0,\"addressFDN\":\"applicants.0.personalDetails.address\",\"crsStatus\":null,\"addresses\":[null,null],\"countries\":[\"AUS\",\"AUS\"],\"entityType\":\"individual\",\"isForeignTaxResident\":null},\"reasonablenessOutcome\":{\"ok\":null},\"amlQuestions\":{\"primarySourceOfWealth\":{\"SelectedItem\":null,\"Query\":null},\"sourceOfFundsForAccount\":{\"SelectedItem\":null,\"Query\":null},\"reasonForOpeningAccount\":{\"SelectedItem\":null,\"Query\":null}}},\"identityCheck\":{\"identity\":{\"greenIdIdentityCheck\":{\"verificationId\":null,\"verificationStatus\":null},\"creditH"
		"eaderCheckbox\":null}},\"tmdQuestions\":{\"disclaimer\":{\"aemContent\":\"\\\\n"
		"AMP Saver Account\\\\n"
		"This product includes\\\\n"
		"\\\\n"
		"A competitive savings rate\\\\n"
		"Easy online access to your money\\\\n"
		"The requirement to deposit at least $250 each month to receive the bonus interest rate\\\\n"
		"The ability to link your savings account to an everyday transaction account\\\\n"
		"\\\\n"
		"This product doesn\\xE2\\x80\\x99t include\\\\n"
		"\\\\n"
		"The bonus interest rate if you deposit less than $250 each month\\\\n"
		"A cheque book, Bank@Post or digital wallet facilities\\\\n"
		"No restriction on pay anyone amounts\\\\n"
		"\\\\n"
		"A target market determination for this product is available at www.{P_Host}/bank/tmd\\\\n"
		"The product issuer is AMP Bank Limited ABN 15081 596 009,\\xC2\\xA0 AFSL and Australian Credit Licence 234517. \\xC2\\xA9 Copyright 2021 AMP Limited. All rights reserved.\\\\n"
		"\",\"productSelection\":\"Proceed\",\"updatedDate\":\"{C_updateddate}\"}}}],\"accountDetails\":{\"preferences\":{},\"declarations\":{\"lastStep\":{\"privacyDeclaration\":null,\"acceptTandCsDeclaration\":null,\"acceptCRSDeclaration\":null}}},\"review\":{},\"personalOrSoleTrader\":{\"accountType\":\"personal\"}}",
		LAST);


	lr_end_transaction("S001_T007_AMPSavAcc_Proceed", LR_AUTO);
	return 0;
}
