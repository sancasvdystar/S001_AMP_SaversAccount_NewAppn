CancelApplication()
{
	/* cancel application */
	
	lr_start_transaction("S001_T015_AMPSavAcc_CancelApplicaton");


	web_custom_request("cancel",
		"URL=https://secure.{P_Host}/ddc/public/api/forms/cancel?formId={C_formId}&checkSecurityToken={C_SecToken}&formName=SaverAccount&checkDob={P_DOB}&checkName={P_Lname}",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://secure.{P_Host}/ddc/public/ui/saver-account/",
		"Snapshot=t105.inf",
		"Mode=HTML",
		"EncType=application/json",
		"Body={}",
		LAST);


	web_reg_find("Search=Body",
		"Text=Contact us",
		LAST);

	web_url("amp-saver-account_2", 
		"URL=https://www.{P_Host}/banking/savings-accounts/amp-saver-account", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://secure.{P_Host}/", 
		"Snapshot=t106.inf", 
		"Mode=HTML", 
		LAST);

	

	lr_end_transaction("S001_T015_AMPSavAcc_CancelApplicaton", LR_AUTO);
	return 0;
}
