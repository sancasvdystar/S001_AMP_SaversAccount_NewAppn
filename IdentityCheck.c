IdentityCheck()
{
	/* Identity check */

	lr_start_transaction("S001_T012_AMPSavAcc_IdentityCheck");


/*Correlation comment - Do not change!  Original value='X5Cmwyuq' Name ='C_verifiId' Type ='Manual'*/
	web_reg_save_param_json(
		"ParamName=C_verifiId",
		"QueryString=$.payload.verificationId",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);

	web_custom_request("register", 
		"URL=https://secure.{P_Host}/ddc/public/api/green-id/register", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://secure.{P_Host}/ddc/public/ui/saver-account/", 
		"Snapshot=t96.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"title\":\"Mr\",\"firstName\":\"{P_Fname}\",\"middleNames\":\"{P_Mname}\",\"lastName\":\"{P_Lname}\",\"dateOfBirth\":\"{P_DOB}\",\"email\":\"{P_email}\",\"address\":{\"country\":\"AU\",\"state\":\"{P_state}\",\"streetName\":\"{P_StreetName}\",\"flatNumber\":\"{P_Unitno}\",\"streetNumber\":\"{P_StreetNo}\",\"suburb\":\"{P_suburb}\",\"postcode\":\"{P_postcode}\",\"streetType\":\"{P_StreetType}\",\"townCity\":\"\"},\"extraData\":[{\"name\":\"dnb-credit-header-consent-given\",\"value\":\"true\"}]}", 
		LAST);

	web_custom_request("token",
		"URL=https://secure.{P_Host}/ddc/public/api/green-id/token?verificationId={C_verifiId}",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://secure.{P_Host}/ddc/public/ui/saver-account/",
		"Snapshot=t97.inf",
		"Mode=HTML",
		"EncType=application/json",
		LAST);


	web_add_auto_header("Origin", 
		"https://secure.{P_Host}");

	web_add_auto_header("Sec-Fetch-Site", 
		"cross-site");


	lr_end_transaction("S001_T012_AMPSavAcc_IdentityCheck", LR_AUTO);

	lr_think_time(t);
	/* skip id check */
	
	lr_start_transaction("S001_T013_AMPSavAcc_IdentityCheck_Skip");



	web_reg_find("Search=Body",
		"Text=statusCode\":200",
		LAST);

	web_custom_request("save_9",
		"URL=https://secure.{P_Host}/ddc/public/api/forms/save?formId={C_formId}&checkSecurityToken={C_SecToken}&formName=SaverAccount&checkDob={P_DOB}&checkName={P_Lname}",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://secure.{P_Host}/ddc/public/ui/saver-account/",
		"Snapshot=t103.inf",
		"Mode=HTML",
		"EncType=application/json",
		"BodyBinary={\"welcome\":{\"tags\":\"[\\\\\"customer\\\\\"]\",\"continueApplication\":null,\"newApplication\":true},\"newOrExistingCustomer\":{\"customerType\":\"New\"},\"captcha\":{},\"adviser\":{},\"singleOrJoint\":{\"applicationType\":\"Individual\"},\"applicants\":[{\"personalDetails\":{\"basicInfo\":{\"firstName\":\"{P_Fname}\",\"surName\":\"{P_Lname}\",\"dateOfBirth\":\"{P_DOB}\",\"scvId\":null,\"hasAdpId\":null,\"title\":{\"SelectedItem\":\"Mr\",\"Query\":\"Mr\"},\"middleName\":\"{P_Mname}\"},\"contactDetails\":{\"emailAddress\":\"{P_email}\",\"mobilePhone\":\"{P_mob}\",\"homePhone\":null},\"address\":{\"addresses\":{\"isAnyAddressInternational\":false,\"residentialAddress\":{\"isManualSearch\":false,\"search\":{\"selectedItem\":\"{C_SelItem}\",\"query\":\"{P_address}\"},\"manualAddress\":{\"country\":{\"SelectedItem\":\"AUS\",\"Query\":\"Australia\"},\"addressLine1\":null,\"addressLine2\":null,\"buildingName\":null,\"floorNumber\":null,\"unitNumber\":\"{P_Unitno}\",\"subBuildingNumber\":null,\"streetNumb"
		"er\":\"{P_StreetNo}\",\"streetName\":\"{P_StreetName}\",\"streetType\":{\"SelectedItem\":\"{P_StreetType}\",\"Query\":\"Street\"},\"poBox\":null,\"suburb\":\"{P_suburb}\",\"state\":{\"SelectedItem\":\"{P_state}\",\"Query\":\"{P_state}\"},\"ruralDelivery\":null,\"city\":null,\"province\":null,\"postCode\":\"{P_postcode}\",\"dpid\":\"{C_dpid}\",\"barcode\":\"{C_barcode}\",\"isInternational\":false},\"isItPoBox\":false},\"postalAndResidentialAreSame\":true},\"editLocked\":null,\"externallyMaintainedAddress\":null}},\"furtherQuestions\":{\"taxFileNumber\":{\"hasTaxFileNumber\":false,\"ok\":true,\"noTaxFileNumberReason\":{\"SelectedItem\":\"ExemptForTFN\",\"Query\":\"Exempt for TFN\"},\"change\":null},\"foreignTaxResident\":{\"attempts\":0,\"addressFDN\":\"applicants.0.personalDetails.address\",\"crsStatus\":\"pass\",\"addresses\":[\"{P_address}\",\"{P_address}\"],\"countries\":[\"AUS\",\"AUS\"],\"entityType\":\"individual\",\"isForeignTaxResident\":false},\"reasonablenessOutcome\":{\"ok\":null},\"amlQuestions\":{\"primarySourceOfWealth\":{\"SelectedItem\":"
		"\"WII\",\"Query\":\"Investment income (e.g. rent, dividends, pension)\"},\"sourceOfFundsForAccount\":{\"SelectedItem\":\"FII\",\"Query\":\"Investment income (e.g. rent, dividends, pension)\"},\"reasonForOpeningAccount\":{\"SelectedItem\":\"BW\",\"Query\":\"Building wealth (e.g. large initial deposit, using investment returns to grow your wealth over time)\"}}},\"identityCheck\":{\"identity\":{\"greenIdIdentityCheck\":{\"verificationId\":\"{C_verifiId}\",\"verificationStatus\":\"IN_PROGRESS\"}}},\"tmdQuestions\":{\"disclaimer\":{\"aemContent\":\"\\\\n"
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

	lr_end_transaction("S001_T013_AMPSavAcc_IdentityCheck_Skip", LR_AUTO);
	lr_think_time(t);
	
	return 0;
}
