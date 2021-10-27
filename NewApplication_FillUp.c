NewApplication_FillUp()
{
	
	
	/* enter personal details */
	lr_start_transaction("S001_T008_AMPSavAcc_EnterPersonaldetails");

	
	web_reg_find("Search=Body",
		"Text=statusCode\":200",
		LAST);

	web_custom_request("save_3",
		"URL=https://secure.{P_Host}/ddc/public/api/forms/save?formId={C_formId}&checkSecurityToken={C_SecToken}&formName=SaverAccount&checkDob={P_DOB}&checkName={P_Lname}",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://secure.{P_Host}/ddc/public/ui/saver-account/",
		"Snapshot=t58.inf",
		"Mode=HTML",
		"EncType=application/json",
		"BodyBinary={\"welcome\":{\"tags\":\"[\\\\\"customer\\\\\"]\",\"continueApplication\":null,\"newApplication\":true},\"newOrExistingCustomer\":{\"customerType\":\"New\"},\"captcha\":{},\"adviser\":{},\"singleOrJoint\":{\"applicationType\":\"Individual\"},\"applicants\":[{\"personalDetails\":{\"basicInfo\":{\"firstName\":\"{P_Fname}\",\"surName\":\"{P_Lname}\",\"dateOfBirth\":\"{P_DOB}\",\"scvId\":null,\"hasAdpId\":null,\"title\":{\"SelectedItem\":\"Mr\",\"Query\":\"Mr\"},\"middleName\":\"{P_Mname}\"},\"contactDetails\":{\"emailAddress\":null,\"mobilePhone\":null,\"homePhone\":null},\"address\":{\"addresses\":{\"isAnyAddressInternational\":false,\"residentialAddress\":{\"isManualSearch\":false,\"search\":{\"selectedItem\":null,\"query\":null},\"manualAddress\":{\"country\":{\"SelectedItem\":\"AUS\",\"Query\":\"Australia\"},\"addressLine1\":null,\"addressLine2\":null,\"buildingName\":null,\"floorNumber\":null,\"unitNumber\":null,\"subBuildingNumber\":null,\"streetNumber\":null,\"streetName\":null,\"streetType\":{\"Select"
		"edItem\":null,\"Query\":null},\"poBox\":null,\"suburb\":null,\"state\":{\"SelectedItem\":null,\"Query\":null},\"ruralDelivery\":null,\"city\":null,\"province\":null,\"postCode\":null,\"dpid\":null,\"barcode\":null,\"isInternational\":false},\"isItPoBox\":null},\"postalAndResidentialAreSame\":true},\"editLocked\":null,\"externallyMaintainedAddress\":null}},\"furtherQuestions\":{\"taxFileNumber\":{\"hasTaxFileNumber\":null,\"ok\":null},\"foreignTaxResident\":{\"attempts\":0,\"addressFDN\":\"applicants.0.personalDetails.address\",\"crsStatus\":null,\"addresses\":[null,null],\"countries\":[\"AUS\",\"AUS\"],\"entityType\":\"individual\",\"isForeignTaxResident\":null},\"reasonablenessOutcome\":{\"ok\":null},\"amlQuestions\":{\"primarySourceOfWealth\":{\"SelectedItem\":null,\"Query\":null},\"sourceOfFundsForAccount\":{\"SelectedItem\":null,\"Query\":null},\"reasonForOpeningAccount\":{\"SelectedItem\":null,\"Query\":null}}},\"identityCheck\":{\"identity\":{\"greenIdIdentityCheck\":{\"verificationId\":null,\"verific"
		"ationStatus\":null},\"creditHeaderCheckbox\":null}},\"tmdQuestions\":{\"disclaimer\":{\"aemContent\":\"\\\\n"
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

	lr_end_transaction("S001_T008_AMPSavAcc_EnterPersonaldetails", LR_AUTO);

	lr_think_time(t);
	/* enter address */
		
	lr_start_transaction("S001_T009_AMPSavAcc_EnterAddress_ParentTxn");


	//save address into a variable
	strcpy(addresstemp,lr_eval_string("{P_address}"));      

	//read the length of the address
    addresslength = strlen(addresstemp);
    
    //Search starts after 3 characters
    
	 for(i=3;i <= addresslength;i++)
            
    {
    
	 //copy addresstemp into address	
	 strncpy(address, addresstemp, i);
	 
	 //save partial address as LR variable
	 lr_save_string(address, "addresspartial");
	
		
	/*Correlation comment - Do not change!  Original value='AUS|19d35d55-634d-47fc-9622-7a5358bb0988|7.730jOAUSHAjlBwAAAAAIAgEAAAAAGaWy0BAhAIIQACAAAAAAAAAzAAD..18AAAAA.....wAAAAAAAAAAAAAAAAAAADMvNDAgYmVhbWlzaCBzdHJlZXQsIGNhbXBzaWUAAAAAAA--$28' Name ='C_SelItem' Type ='Manual'*/
	web_reg_save_param_json(
		"ParamName=C_SelItem",
		"QueryString=$.payload.QAPicklist.PicklistEntry[0].Moniker",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"Notfound=warning",
		LAST);
		
	lr_start_transaction("S001_T009_AMPSavAcc_EnterAddress");

	web_custom_request("3%3A%3A%3ASLASH%3A%3A%3A4", 
		"URL=https://secure.{P_Host}/ddc/public/api/qas/doSearch/AUS/{addresspartial}?residentialOnly=true", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://secure.{P_Host}/ddc/public/ui/saver-account/", 
		"Snapshot=t59.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		LAST);
	lr_end_transaction("S001_T009_AMPSavAcc_EnterAddress", LR_AUTO);
	
	lr_think_time(t);

	 }
	 
	

/*Correlation comment - Do not change!  Original value='61209129' Name ='C_dpid' Type ='Manual'*/
	web_reg_save_param_json(
		"ParamName=C_dpid",
		"QueryString=$.payload.DDC.DPID/DID",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);
		
  web_reg_save_param("C_barcode",
                   "LB=AUSBAR\.\":\"",
                   "RB=\"",
                   "ord=1",
                   LAST);

  web_convert_param("C_SelItemurl",
                  "SourceString={C_SelItem}",    
                  "SourceEncoding=PLAIN",
                  "TargetEncoding=URL",
                  LAST);
                  
	web_custom_request("AUS%7C19d35d55-634d-47fc-9622-7a5358bb0988%7C7.730jOAUSHAjlBwAAAAAIAgEAAAAAGaWy0BAhAIIQACAAAAAAAAAzAAD..18AAAAA.....wAAAAAAAAAAAAAAAAAAADMvNDAgYmVhbWlzaCBzdHJlZXQsIGNhbXBzaWUAAAAAAA--$28", 
		"URL=https://secure.{P_Host}/ddc/public/api/qas/doGetAddress/AUS/{C_SelItemurl}?partialAddress={addresspartial}", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://secure.{P_Host}/ddc/public/ui/saver-account/", 
		"Snapshot=t84.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		LAST);

	lr_end_transaction("S001_T009_AMPSavAcc_EnterAddress_ParentTxn", LR_AUTO);
	
	lr_think_time(t);
	/* click ok */

	lr_start_transaction("S001_T010_AMPSavAcc_SelectAddress");

	web_reg_find("Search=Body",
		"Text=statusCode\":200",
		LAST);

	web_custom_request("save_4",
		"URL=https://secure.{P_Host}/ddc/public/api/forms/save?formId={C_formId}&checkSecurityToken={C_SecToken}&formName=SaverAccount&checkDob={P_DOB}&checkName={P_Lname}",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://secure.{P_Host}/ddc/public/ui/saver-account/",
		"Snapshot=t85.inf",
		"Mode=HTML",
		"EncType=application/json",
		"BodyBinary={\"welcome\":{\"tags\":\"[\\\\\"customer\\\\\"]\",\"continueApplication\":null,\"newApplication\":true},\"newOrExistingCustomer\":{\"customerType\":\"New\"},\"captcha\":{},\"adviser\":{},\"singleOrJoint\":{\"applicationType\":\"Individual\"},\"applicants\":[{\"personalDetails\":{\"basicInfo\":{\"firstName\":\"{P_Fname}\",\"surName\":\"{P_Lname}\",\"dateOfBirth\":\"{P_DOB}\",\"scvId\":null,\"hasAdpId\":null,\"title\":{\"SelectedItem\":\"Mr\",\"Query\":\"Mr\"},\"middleName\":\"{P_Mname}\"},\"contactDetails\":{\"emailAddress\":null,\"mobilePhone\":null,\"homePhone\":null},\"address\":{\"addresses\":{\"isAnyAddressInternational\":false,\"residentialAddress\":{\"isManualSearch\":false,\"search\":{\"selectedItem\":\"{C_SelItem}\",\"query\":\"{P_address}\"},\"manualAddress\":{\"country\":{\"SelectedItem\":\"AUS\",\"Query\":\"Australia\"},\"addressLine1\":null,\"addressLine2\":null,\"buildingName\":null,\"floorNumber\":null,\"unitNumber\":\"{P_Unitno}\",\"subBuildingNumber\":null,\"streetNumber\":\"{P_StreetNo}\",\"streetName\""
		":\"{P_StreetName}\",\"streetType\":{\"SelectedItem\":\"{P_StreetType}\",\"Query\":\"Street\"},\"poBox\":null,\"suburb\":\"{P_suburb}\",\"state\":{\"SelectedItem\":\"{P_state}\",\"Query\":\"{P_state}\"},\"ruralDelivery\":null,\"city\":null,\"province\":null,\"postCode\":\"{P_postcode}\",\"dpid\":\"{C_dpid}\",\"barcode\":\"{C_barcode}\",\"isInternational\":false},\"isItPoBox\":false},\"postalAndResidentialAreSame\":true},\"editLocked\":null,\"externallyMaintainedAddress\":null}},\"furtherQuestions\":{\"taxFileNumber\":{\"hasTaxFileNumber\":null,\"ok\":null},\"foreignTaxResident\":{\"attempts\":0,\"addressFDN\":\"applicants.0.personalDetails.address\",\"crsStatus\":null,\"addresses\":[\"{P_address}\",\"{P_address}\"],\"countries\":[\"AUS\",\"AUS\"],\"entityType\":\"individual\",\"isForeignTaxResident\":null},\"reasonablenessOutcome\":{\"ok\":null},\"amlQuestions\":{\"primarySourceOfWealth\":{\"SelectedItem\":null,\"Query\":null},\"sourceOfFundsForAccount\":{\"SelectedItem\":null,\"Query\":null},\"reasonForOpeningAccount\":{\"SelectedItem\":null,"
		"\"Query\":null}}},\"identityCheck\":{\"identity\":{\"greenIdIdentityCheck\":{\"verificationId\":null,\"verificationStatus\":null},\"creditHeaderCheckbox\":null}},\"tmdQuestions\":{\"disclaimer\":{\"aemContent\":\"\\\\n"
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



	web_reg_find("Search=Body",
		"Text=statusCode\":200",
		LAST);

	web_custom_request("save_5",
		"URL=https://secure.{P_Host}/ddc/public/api/forms/save?formId={C_formId}&checkSecurityToken={C_SecToken}&formName=SaverAccount&checkDob={P_DOB}&checkName={P_Lname}",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://secure.{P_Host}/ddc/public/ui/saver-account/",
		"Snapshot=t88.inf",
		"Mode=HTML",
		"EncType=application/json",
		"BodyBinary={\"welcome\":{\"tags\":\"[\\\\\"customer\\\\\"]\",\"continueApplication\":null,\"newApplication\":true},\"newOrExistingCustomer\":{\"customerType\":\"New\"},\"captcha\":{},\"adviser\":{},\"singleOrJoint\":{\"applicationType\":\"Individual\"},\"applicants\":[{\"personalDetails\":{\"basicInfo\":{\"firstName\":\"{P_Fname}\",\"surName\":\"{P_Lname}\",\"dateOfBirth\":\"{P_DOB}\",\"scvId\":null,\"hasAdpId\":null,\"title\":{\"SelectedItem\":\"Mr\",\"Query\":\"Mr\"},\"middleName\":\"{P_Mname}\"},\"contactDetails\":{\"emailAddress\":\"{P_email}\",\"mobilePhone\":\"{P_mob}\",\"homePhone\":null},\"address\":{\"addresses\":{\"isAnyAddressInternational\":false,\"residentialAddress\":{\"isManualSearch\":false,\"search\":{\"selectedItem\":\"{C_SelItem}\",\"query\":\"{P_address}\"},\"manualAddress\":{\"country\":{\"SelectedItem\":\"AUS\",\"Query\":\"Australia\"},\"addressLine1\":null,\"addressLine2\":null,\"buildingName\":null,\"floorNumber\":null,\"unitNumber\":\"{P_Unitno}\",\"subBuildingNumber\":null,\"streetNumb"
		"er\":\"40\",\"streetName\":\"{P_StreetName}\",\"streetType\":{\"SelectedItem\":\"{P_StreetType}\",\"Query\":\"Street\"},\"poBox\":null,\"suburb\":\"{P_suburb}\",\"state\":{\"SelectedItem\":\"{P_state}\",\"Query\":\"{P_state}\"},\"ruralDelivery\":null,\"city\":null,\"province\":null,\"postCode\":\"{P_postcode}\",\"dpid\":\"{C_dpid}\",\"barcode\":\"{C_barcode}\",\"isInternational\":false},\"isItPoBox\":false},\"postalAndResidentialAreSame\":true},\"editLocked\":null,\"externallyMaintainedAddress\":null}},\"furtherQuestions\":{\"taxFileNumber\":{\"hasTaxFileNumber\":null,\"ok\":null},\"foreignTaxResident\":{\"attempts\":0,\"addressFDN\":\"applicants.0.personalDetails.address\",\"crsStatus\":null,\"addresses\":[\"{P_address}\",\"{P_address}\"],\"countries\":[\"AUS\",\"AUS\"],\"entityType\":\"individual\",\"isForeignTaxResident\":null},\"reasonablenessOutcome\":{\"ok\":null},\"amlQuestions\":{\"primarySourceOfWealth\":{\"SelectedItem\":null,\"Query\":null},\"sourceOfFundsForAccount\":{\"SelectedItem\":null,\"Query\":null},\"reasonForOpeningAccount"
		"\":{\"SelectedItem\":null,\"Query\":null}}},\"identityCheck\":{\"identity\":{\"greenIdIdentityCheck\":{\"verificationId\":null,\"verificationStatus\":null},\"creditHeaderCheckbox\":null}},\"tmdQuestions\":{\"disclaimer\":{\"aemContent\":\"\\\\n"
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
	
	lr_end_transaction("S001_T010_AMPSavAcc_SelectAddress", LR_AUTO);

	lr_think_time(t);
	/* enter tax details */
	
	lr_start_transaction("S001_T011_AMPSavAcc_EnterTaxDetails");


	web_custom_request("save_6",
		"URL=https://secure.{P_Host}/ddc/public/api/forms/save?formId={C_formId}&checkSecurityToken={C_SecToken}&formName=SaverAccount&checkDob={P_DOB}&checkName={P_Lname}",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://secure.{P_Host}/ddc/public/ui/saver-account/",
		"Snapshot=t89.inf",
		"Mode=HTML",
		"EncType=application/json",
		"BodyBinary={\"welcome\":{\"tags\":\"[\\\\\"customer\\\\\"]\",\"continueApplication\":null,\"newApplication\":true},\"newOrExistingCustomer\":{\"customerType\":\"New\"},\"captcha\":{},\"adviser\":{},\"singleOrJoint\":{\"applicationType\":\"Individual\"},\"applicants\":[{\"personalDetails\":{\"basicInfo\":{\"firstName\":\"{P_Fname}\",\"surName\":\"{P_Lname}\",\"dateOfBirth\":\"{P_DOB}\",\"scvId\":null,\"hasAdpId\":null,\"title\":{\"SelectedItem\":\"Mr\",\"Query\":\"Mr\"},\"middleName\":\"{P_Mname}\"},\"contactDetails\":{\"emailAddress\":\"{P_email}\",\"mobilePhone\":\"{P_mob}\",\"homePhone\":null},\"address\":{\"addresses\":{\"isAnyAddressInternational\":false,\"residentialAddress\":{\"isManualSearch\":false,\"search\":{\"selectedItem\":\"{C_SelItem}\",\"query\":\"{P_address}\"},\"manualAddress\":{\"country\":{\"SelectedItem\":\"AUS\",\"Query\":\"Australia\"},\"addressLine1\":null,\"addressLine2\":null,\"buildingName\":null,\"floorNumber\":null,\"unitNumber\":\"{P_Unitno}\",\"subBuildingNumber\":null,\"streetNumb"
		"er\":\"40\",\"streetName\":\"{P_StreetName}\",\"streetType\":{\"SelectedItem\":\"{P_StreetType}\",\"Query\":\"Street\"},\"poBox\":null,\"suburb\":\"{P_suburb}\",\"state\":{\"SelectedItem\":\"{P_state}\",\"Query\":\"{P_state}\"},\"ruralDelivery\":null,\"city\":null,\"province\":null,\"postCode\":\"{P_postcode}\",\"dpid\":\"{C_dpid}\",\"barcode\":\"{C_barcode}\",\"isInternational\":false},\"isItPoBox\":false},\"postalAndResidentialAreSame\":true},\"editLocked\":null,\"externallyMaintainedAddress\":null}},\"furtherQuestions\":{\"taxFileNumber\":{\"hasTaxFileNumber\":false,\"ok\":true,\"noTaxFileNumberReason\":{\"SelectedItem\":\"ExemptForTFN\",\"Query\":\"Exempt for TFN\"}},\"foreignTaxResident\":{\"attempts\":0,\"addressFDN\":\"applicants.0.personalDetails.address\",\"crsStatus\":null,\"addresses\":[\"{P_address}\",\"{P_address}\"],\"countries\":[\"AUS\",\"AUS\"],\"entityType\":\"individual\",\"isForeignTaxResident\":null},\"reasonablenessOutcome\":{\"ok\":null},\"amlQuestions\":{\"primarySourceOfWealth\":{\"SelectedItem\":null,\"Query\":null},"
		"\"sourceOfFundsForAccount\":{\"SelectedItem\":null,\"Query\":null},\"reasonForOpeningAccount\":{\"SelectedItem\":null,\"Query\":null}}},\"identityCheck\":{\"identity\":{\"greenIdIdentityCheck\":{\"verificationId\":null,\"verificationStatus\":null},\"creditHeaderCheckbox\":null}},\"tmdQuestions\":{\"disclaimer\":{\"aemContent\":\"\\\\n"
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


	web_url("individual", 
		"URL=https://secure.{P_Host}/ddc/public/api/api-crs/AUS/individual?resCountry=AUS&postalCountry=AUS", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://secure.{P_Host}/ddc/public/ui/saver-account/", 
		"Snapshot=t90.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("save_7",
		"URL=https://secure.{P_Host}/ddc/public/api/forms/save?formId={C_formId}&checkSecurityToken={C_SecToken}&formName=SaverAccount&checkDob={P_DOB}&checkName={P_Lname}",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://secure.{P_Host}/ddc/public/ui/saver-account/",
		"Snapshot=t91.inf",
		"Mode=HTML",
		"EncType=application/json",
		"BodyBinary={\"welcome\":{\"tags\":\"[\\\\\"customer\\\\\"]\",\"continueApplication\":null,\"newApplication\":true},\"newOrExistingCustomer\":{\"customerType\":\"New\"},\"captcha\":{},\"adviser\":{},\"singleOrJoint\":{\"applicationType\":\"Individual\"},\"applicants\":[{\"personalDetails\":{\"basicInfo\":{\"firstName\":\"{P_Fname}\",\"surName\":\"{P_Lname}\",\"dateOfBirth\":\"{P_DOB}\",\"scvId\":null,\"hasAdpId\":null,\"title\":{\"SelectedItem\":\"Mr\",\"Query\":\"Mr\"},\"middleName\":\"{P_Mname}\"},\"contactDetails\":{\"emailAddress\":\"{P_email}\",\"mobilePhone\":\"{P_mob}\",\"homePhone\":null},\"address\":{\"addresses\":{\"isAnyAddressInternational\":false,\"residentialAddress\":{\"isManualSearch\":false,\"search\":{\"selectedItem\":\"{C_SelItem}\",\"query\":\"{P_address}\"},\"manualAddress\":{\"country\":{\"SelectedItem\":\"AUS\",\"Query\":\"Australia\"},\"addressLine1\":null,\"addressLine2\":null,\"buildingName\":null,\"floorNumber\":null,\"unitNumber\":\"{P_Unitno}\",\"subBuildingNumber\":null,\"streetNumb"
		"er\":\"40\",\"streetName\":\"{P_StreetName}\",\"streetType\":{\"SelectedItem\":\"{P_StreetType}\",\"Query\":\"Street\"},\"poBox\":null,\"suburb\":\"{P_suburb}\",\"state\":{\"SelectedItem\":\"{P_state}\",\"Query\":\"{P_state}\"},\"ruralDelivery\":null,\"city\":null,\"province\":null,\"postCode\":\"{P_postcode}\",\"dpid\":\"{C_dpid}\",\"barcode\":\"{C_barcode}\",\"isInternational\":false},\"isItPoBox\":false},\"postalAndResidentialAreSame\":true},\"editLocked\":null,\"externallyMaintainedAddress\":null}},\"furtherQuestions\":{\"taxFileNumber\":{\"hasTaxFileNumber\":false,\"ok\":true,\"noTaxFileNumberReason\":{\"SelectedItem\":\"ExemptForTFN\",\"Query\":\"Exempt for TFN\"},\"change\":null},\"foreignTaxResident\":{\"attempts\":0,\"addressFDN\":\"applicants.0.personalDetails.address\",\"crsStatus\":\"pass\",\"addresses\":[\"{P_address}\",\"{P_address}\"],\"countries\":[\"AUS\",\"AUS\"],\"entityType\":\"individual\",\"isForeignTaxResident\":false},\"reasonablenessOutcome\":{\"ok\":null},\"amlQuestions\":{\"primarySourceOfWealth\":{\"SelectedItem\":"
		"null,\"Query\":null},\"sourceOfFundsForAccount\":{\"SelectedItem\":null,\"Query\":null},\"reasonForOpeningAccount\":{\"SelectedItem\":null,\"Query\":null}}},\"identityCheck\":{\"identity\":{\"greenIdIdentityCheck\":{\"verificationId\":null,\"verificationStatus\":null},\"creditHeaderCheckbox\":null}},\"tmdQuestions\":{\"disclaimer\":{\"aemContent\":\"\\\\n"
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



	web_reg_find("Search=Body",
		"Text=statusCode\":200",
		LAST);

	web_custom_request("save_8",
		"URL=https://secure.{P_Host}/ddc/public/api/forms/save?formId={C_formId}&checkSecurityToken={C_SecToken}&formName=SaverAccount&checkDob={P_DOB}&checkName={P_Lname}",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://secure.{P_Host}/ddc/public/ui/saver-account/",
		"Snapshot=t92.inf",
		"Mode=HTML",
		"EncType=application/json",
		"BodyBinary={\"welcome\":{\"tags\":\"[\\\\\"customer\\\\\"]\",\"continueApplication\":null,\"newApplication\":true},\"newOrExistingCustomer\":{\"customerType\":\"New\"},\"captcha\":{},\"adviser\":{},\"singleOrJoint\":{\"applicationType\":\"Individual\"},\"applicants\":[{\"personalDetails\":{\"basicInfo\":{\"firstName\":\"{P_Fname}\",\"surName\":\"{P_Lname}\",\"dateOfBirth\":\"{P_DOB}\",\"scvId\":null,\"hasAdpId\":null,\"title\":{\"SelectedItem\":\"Mr\",\"Query\":\"Mr\"},\"middleName\":\"{P_Mname}\"},\"contactDetails\":{\"emailAddress\":\"{P_email}\",\"mobilePhone\":\"{P_mob}\",\"homePhone\":null},\"address\":{\"addresses\":{\"isAnyAddressInternational\":false,\"residentialAddress\":{\"isManualSearch\":false,\"search\":{\"selectedItem\":\"{C_SelItem}\",\"query\":\"{P_address}\"},\"manualAddress\":{\"country\":{\"SelectedItem\":\"AUS\",\"Query\":\"Australia\"},\"addressLine1\":null,\"addressLine2\":null,\"buildingName\":null,\"floorNumber\":null,\"unitNumber\":\"{P_Unitno}\",\"subBuildingNumber\":null,\"streetNumb"
		"er\":\"40\",\"streetName\":\"{P_StreetName}\",\"streetType\":{\"SelectedItem\":\"{P_StreetType}\",\"Query\":\"Street\"},\"poBox\":null,\"suburb\":\"{P_suburb}\",\"state\":{\"SelectedItem\":\"{P_state}\",\"Query\":\"{P_state}\"},\"ruralDelivery\":null,\"city\":null,\"province\":null,\"postCode\":\"{P_postcode}\",\"dpid\":\"{C_dpid}\",\"barcode\":\"{C_barcode}\",\"isInternational\":false},\"isItPoBox\":false},\"postalAndResidentialAreSame\":true},\"editLocked\":null,\"externallyMaintainedAddress\":null}},\"furtherQuestions\":{\"taxFileNumber\":{\"hasTaxFileNumber\":false,\"ok\":true,\"noTaxFileNumberReason\":{\"SelectedItem\":\"ExemptForTFN\",\"Query\":\"Exempt for TFN\"},\"change\":null},\"foreignTaxResident\":{\"attempts\":0,\"addressFDN\":\"applicants.0.personalDetails.address\",\"crsStatus\":\"pass\",\"addresses\":[\"{P_address}\",\"{P_address}\"],\"countries\":[\"AUS\",\"AUS\"],\"entityType\":\"individual\",\"isForeignTaxResident\":false},\"reasonablenessOutcome\":{\"ok\":null},\"amlQuestions\":{\"primarySourceOfWealth\":{\"SelectedItem\":"
		"\"WII\",\"Query\":\"Investment income (e.g. rent, dividends, pension)\"},\"sourceOfFundsForAccount\":{\"SelectedItem\":\"FII\",\"Query\":\"Investment income (e.g. rent, dividends, pension)\"},\"reasonForOpeningAccount\":{\"SelectedItem\":\"BW\",\"Query\":\"Building wealth (e.g. large initial deposit, using investment returns to grow your wealth over time)\"}}},\"identityCheck\":{\"identity\":{\"greenIdIdentityCheck\":{\"verificationId\":null,\"verificationStatus\":null},\"creditHeaderCheckbox\":null}},\"tmdQuestions\":{\"disclaimer\":{\"aemContent\":\"\\\\n"
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

	lr_end_transaction("S001_T011_AMPSavAcc_EnterTaxDetails", LR_AUTO);
	lr_think_time(t);

	return 0;
}
