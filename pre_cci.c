# 1 "c:\\lr\\script\\s001_amp_saversaccount_newappn\\\\combined_S001_AMP_SaversAccount_NewAppn.c"
# 1 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/lrun.h" 1
 
 












 











# 103 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/lrun.h"





















































		


		typedef unsigned size_t;
	
	
        
	

















	

 



















 
 
 
 
 


 
 
 
 
 
 














int     lr_start_transaction   (char * transaction_name);
int lr_start_sub_transaction          (char * transaction_name, char * trans_parent);
long lr_start_transaction_instance    (char * transaction_name, long parent_handle);
int   lr_start_cross_vuser_transaction		(char * transaction_name, char * trans_id_param); 



int     lr_end_transaction     (char * transaction_name, int status);
int lr_end_sub_transaction            (char * transaction_name, int status);
int lr_end_transaction_instance       (long transaction, int status);
int   lr_end_cross_vuser_transaction	(char * transaction_name, char * trans_id_param, int status);


 
typedef char* lr_uuid_t;
 



lr_uuid_t lr_generate_uuid();

 


int lr_generate_uuid_free(lr_uuid_t uuid);

 



int lr_generate_uuid_on_buf(lr_uuid_t buf);

   
# 273 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/lrun.h"
int lr_start_distributed_transaction  (char * transaction_name, lr_uuid_t correlator, long timeout  );

   







int lr_end_distributed_transaction  (lr_uuid_t correlator, int status);


double lr_stop_transaction            (char * transaction_name);
double lr_stop_transaction_instance   (long parent_handle);


void lr_resume_transaction           (char * trans_name);
void lr_resume_transaction_instance  (long trans_handle);


int lr_update_transaction            (const char *trans_name);


 
void lr_wasted_time(long time);


 
int lr_set_transaction(const char *name, double duration, int status);
 
long lr_set_transaction_instance(const char *name, double duration, int status, long parent_handle);


int   lr_user_data_point                      (char *, double);
long lr_user_data_point_instance                   (char *, double, long);
 



int lr_user_data_point_ex(const char *dp_name, double value, int log_flag);
long lr_user_data_point_instance_ex(const char *dp_name, double value, long parent_handle, int log_flag);


int lr_transaction_add_info      (const char *trans_name, char *info);
int lr_transaction_instance_add_info   (long trans_handle, char *info);
int lr_dpoint_add_info           (const char *dpoint_name, char *info);
int lr_dpoint_instance_add_info        (long dpoint_handle, char *info);


double lr_get_transaction_duration       (char * trans_name);
double lr_get_trans_instance_duration    (long trans_handle);
double lr_get_transaction_think_time     (char * trans_name);
double lr_get_trans_instance_think_time  (long trans_handle);
double lr_get_transaction_wasted_time    (char * trans_name);
double lr_get_trans_instance_wasted_time (long trans_handle);
int    lr_get_transaction_status		 (char * trans_name);
int	   lr_get_trans_instance_status		 (long trans_handle);

 



int lr_set_transaction_status(int status);

 



int lr_set_transaction_status_by_name(int status, const char *trans_name);
int lr_set_transaction_instance_status(int status, long trans_handle);


typedef void* merc_timer_handle_t;
 

merc_timer_handle_t lr_start_timer();
double lr_end_timer(merc_timer_handle_t timer_handle);


 
 
 
 
 
 











 



int   lr_rendezvous  (char * rendezvous_name);
 




int   lr_rendezvous_ex (char * rendezvous_name);



 
 
 
 
 
char *lr_get_vuser_ip (void);
void   lr_whoami (int *vuser_id, char ** sgroup, int *scid);
char *	  lr_get_host_name (void);
char *	  lr_get_master_host_name (void);

 
long     lr_get_attrib_long	(char * attr_name);
char *   lr_get_attrib_string	(char * attr_name);
double   lr_get_attrib_double      (char * attr_name);

char * lr_paramarr_idx(const char * paramArrayName, unsigned int index);
char * lr_paramarr_random(const char * paramArrayName);
int    lr_paramarr_len(const char * paramArrayName);

int	lr_param_unique(const char * paramName);
int lr_param_sprintf(const char * paramName, const char * format, ...);


 
 
static void *ci_this_context = 0;






 








void lr_continue_on_error (int lr_continue);
char *   lr_unmask (const char *EncodedString);
char *   lr_decrypt (const char *EncodedString);


 
 
 
 
 
 



 







 















void   lr_abort (void);
void lr_exit(int exit_option, int exit_status);
void lr_abort_ex (unsigned long flags);

void   lr_peek_events (void);


 
 
 
 
 


void   lr_think_time (double secs);

 


void lr_force_think_time (double secs);


 
 
 
 
 



















int   lr_msg (char * fmt, ...);
int   lr_debug_message (unsigned int msg_class,
									    char * format,
										...);
# 513 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/lrun.h"
void   lr_new_prefix (int type,
                                 char * filename,
                                 int line);
# 516 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/lrun.h"
int   lr_log_message (char * fmt, ...);
int   lr_message (char * fmt, ...);
int   lr_error_message (char * fmt, ...);
int   lr_output_message (char * fmt, ...);
int   lr_vuser_status_message (char * fmt, ...);
int   lr_error_message_without_fileline (char * fmt, ...);
int   lr_fail_trans_with_error (char * fmt, ...);

 
 
 
 
 
# 540 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/lrun.h"

 
 
 
 
 





int   lr_next_row ( char * table);
int lr_advance_param ( char * param);



														  
														  

														  
														  

													      
 


char *   lr_eval_string (char * str);
int   lr_eval_string_ext (const char *in_str,
                                     unsigned long const in_len,
                                     char ** const out_str,
                                     unsigned long * const out_len,
                                     unsigned long const options,
                                     const char *file,
								     long const line);
# 574 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/lrun.h"
void   lr_eval_string_ext_free (char * * pstr);

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
int lr_param_increment (char * dst_name,
                              char * src_name);
# 597 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/lrun.h"













											  
											  

											  
											  
											  

int	  lr_save_var (char *              param_val,
							  unsigned long const param_val_len,
							  unsigned long const options,
							  char *			  param_name);
# 621 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/lrun.h"
int   lr_save_string (const char * param_val, const char * param_name);



int   lr_set_custom_error_message (const char * param_val, ...);

int   lr_remove_custom_error_message ();


int   lr_free_parameter (const char * param_name);
int   lr_save_int (const int param_val, const char * param_name);
int   lr_save_timestamp (const char * tmstampParam, ...);
int   lr_save_param_regexp (const char *bufferToScan, unsigned int bufSize, ...);

int   lr_convert_double_to_integer (const char *source_param_name, const char * target_param_name);
int   lr_convert_double_to_double (const char *source_param_name, const char *format_string, const char * target_param_name);

 
 
 
 
 
 
# 700 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/lrun.h"
void   lr_save_datetime (const char *format, int offset, const char *name);









 











 
 
 
 
 






 



char * lr_error_context_get_entry (char * key);

 



long   lr_error_context_get_error_id (void);


 
 
 

int lr_table_get_rows_num (char * param_name);

int lr_table_get_cols_num (char * param_name);

char * lr_table_get_cell_by_col_index (char * param_name, int row, int col);

char * lr_table_get_cell_by_col_name (char * param_name, int row, const char* col_name);

int lr_table_get_column_name_by_index (char * param_name, int col, 
											char * * const col_name,
											size_t * col_name_len);
# 761 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/lrun.h"

int lr_table_get_column_name_by_index_free (char * col_name);

 
 
 
 
# 776 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/lrun.h"
int   lr_zip (const char* param1, const char* param2);
int   lr_unzip (const char* param1, const char* param2);

 
 
 
 
 
 
 
 

 
 
 
 
 
 
int   lr_param_substit (char * file,
                                   int const line,
                                   char * in_str,
                                   size_t const in_len,
                                   char * * const out_str,
                                   size_t * const out_len);
# 800 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/lrun.h"
void   lr_param_substit_free (char * * pstr);


 
# 812 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/lrun.h"





char *   lrfnc_eval_string (char * str,
                                      char * file_name,
                                      long const line_num);
# 820 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/lrun.h"


int   lrfnc_save_string ( const char * param_val,
                                     const char * param_name,
                                     const char * file_name,
                                     long const line_num);
# 826 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/lrun.h"

int   lrfnc_free_parameter (const char * param_name );







typedef struct _lr_timestamp_param
{
	int iDigits;
}lr_timestamp_param;

extern const lr_timestamp_param default_timestamp_param;

int   lrfnc_save_timestamp (const char * param_name, const lr_timestamp_param* time_param);

int lr_save_searched_string(char * buffer, long buf_size, unsigned int occurrence,
			    char * search_string, int offset, unsigned int param_val_len, 
			    char * param_name);

 
char *   lr_string (char * str);

 
# 929 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/lrun.h"

int   lr_save_value (char * param_val,
                                unsigned long const param_val_len,
                                unsigned long const options,
                                char * param_name,
                                char * file_name,
                                long const line_num);
# 936 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/lrun.h"


 
 
 
 
 











int   lr_printf (char * fmt, ...);
 
int   lr_set_debug_message (unsigned int msg_class,
                                       unsigned int swtch);
# 958 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/lrun.h"
unsigned int   lr_get_debug_message (void);


 
 
 
 
 

void   lr_double_think_time ( double secs);
void   lr_usleep (long);


 
 
 
 
 
 




int *   lr_localtime (long offset);


int   lr_send_port (long port);


# 1034 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/lrun.h"



struct _lr_declare_identifier{
	char signature[24];
	char value[128];
};

int   lr_pt_abort (void);

void vuser_declaration (void);






# 1063 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/lrun.h"


# 1075 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/lrun.h"
















 
 
 
 
 







int    _lr_declare_transaction   (char * transaction_name);


 
 
 
 
 







int   _lr_declare_rendezvous  (char * rendezvous_name);

 
 
 
 
 


typedef int PVCI;






typedef int VTCERR;









PVCI   vtc_connect(char * servername, int portnum, int options);
VTCERR   vtc_disconnect(PVCI pvci);
VTCERR   vtc_get_last_error(PVCI pvci);
VTCERR   vtc_query_column(PVCI pvci, char * columnName, int columnIndex, char * *outvalue);
VTCERR   vtc_query_row(PVCI pvci, int rowIndex, char * **outcolumns, char * **outvalues);
VTCERR   vtc_send_message(PVCI pvci, char * column, char * message, unsigned short *outRc);
VTCERR   vtc_send_if_unique(PVCI pvci, char * column, char * message, unsigned short *outRc);
VTCERR   vtc_send_row1(PVCI pvci, char * columnNames, char * messages, char * delimiter, unsigned char sendflag, unsigned short *outUpdates);
VTCERR   vtc_search_row(PVCI pvci, char * columnNames, char * messages, char * delimiter, char * **outcolumns, char * **outvalues);
VTCERR   vtc_update_message(PVCI pvci, char * column, int index , char * message, unsigned short *outRc);
VTCERR   vtc_update_message_ifequals(PVCI pvci, char * columnName, int index,	char * message, char * ifmessage, unsigned short 	*outRc);
VTCERR   vtc_update_row1(PVCI pvci, char * columnNames, int index , char * messages, char * delimiter, unsigned short *outUpdates);
VTCERR   vtc_retrieve_message(PVCI pvci, char * column, char * *outvalue);
VTCERR   vtc_retrieve_messages1(PVCI pvci, char * columnNames, char * delimiter, char * **outvalues);
VTCERR   vtc_retrieve_row(PVCI pvci, char * **outcolumns, char * **outvalues);
VTCERR   vtc_rotate_message(PVCI pvci, char * column, char * *outvalue, unsigned char sendflag);
VTCERR   vtc_rotate_messages1(PVCI pvci, char * columnNames, char * delimiter, char * **outvalues, unsigned char sendflag);
VTCERR   vtc_rotate_row(PVCI pvci, char * **outcolumns, char * **outvalues, unsigned char sendflag);
VTCERR   vtc_increment(PVCI pvci, char * column, int index , int incrValue, int *outValue);
VTCERR   vtc_clear_message(PVCI pvci, char * column, int index , unsigned short *outRc);
VTCERR   vtc_clear_column(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_ensure_index(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_drop_index(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_clear_row(PVCI pvci, int rowIndex, unsigned short *outRc);
VTCERR   vtc_create_column(PVCI pvci, char * column,unsigned short *outRc);
VTCERR   vtc_column_size(PVCI pvci, char * column, int *size);
void   vtc_free(char * msg);
void   vtc_free_list(char * *msglist);
VTCERR   vtc_update_all_message_ifequals(PVCI pvci, char * columnNames, char * message, char * ifmessage, char * delimiter, unsigned short *outRc);

VTCERR   lrvtc_connect(char * servername, int portnum, int options);
VTCERR   lrvtc_connect_ex(char * vtc_first_param, ...);
VTCERR   lrvtc_connect_ex_no_ellipsis(const char *vtc_first_param, char ** arguments, int argCount);
VTCERR   lrvtc_disconnect();
VTCERR   lrvtc_query_column(char * columnName, int columnIndex);
VTCERR   lrvtc_query_row(int columnIndex);
VTCERR   lrvtc_send_message(char * columnName, char * message);
VTCERR   lrvtc_send_if_unique(char * columnName, char * message);
VTCERR   lrvtc_send_row1(char * columnNames, char * messages, char * delimiter, unsigned char sendflag);
VTCERR   lrvtc_search_row(char * columnNames, char * messages, char * delimiter);
VTCERR   lrvtc_update_message(char * columnName, int index , char * message);
VTCERR   lrvtc_update_message_ifequals(char * columnName, int index, char * message, char * ifmessage);
VTCERR   lrvtc_update_row1(char * columnNames, int index , char * messages, char * delimiter);
VTCERR   lrvtc_retrieve_message(char * columnName);
VTCERR   lrvtc_retrieve_messages1(char * columnNames, char * delimiter);
VTCERR   lrvtc_retrieve_row();
VTCERR   lrvtc_rotate_message(char * columnName, unsigned char sendflag);
VTCERR   lrvtc_rotate_messages1(char * columnNames, char * delimiter, unsigned char sendflag);
VTCERR   lrvtc_rotate_row(unsigned char sendflag);
VTCERR   lrvtc_increment(char * columnName, int index , int incrValue);
VTCERR   lrvtc_noop();
VTCERR   lrvtc_clear_message(char * columnName, int index);
VTCERR   lrvtc_clear_column(char * columnName); 
VTCERR   lrvtc_ensure_index(char * columnName); 
VTCERR   lrvtc_drop_index(char * columnName); 
VTCERR   lrvtc_clear_row(int rowIndex);
VTCERR   lrvtc_create_column(char * columnName);
VTCERR   lrvtc_column_size(char * columnName);
VTCERR   lrvtc_update_all_message_ifequals(char * columnNames, char * message, char * ifmessage, char * delimiter);



 
 
 
 
 

 
int lr_enable_ip_spoofing();
int lr_disable_ip_spoofing();


 




int lr_convert_string_encoding(char * sourceString, char * fromEncoding, char * toEncoding, char * paramName);
int lr_read_file(const char *filename, const char *outputParam, int continueOnError);

int lr_get_char_count(const char * string);


 
int lr_db_connect (char * pFirstArg, ...);
int lr_db_disconnect (char * pFirstArg,	...);
int lr_db_executeSQLStatement (char * pFirstArg, ...);
int lr_db_dataset_action(char * pFirstArg, ...);
int lr_checkpoint(char * pFirstArg,	...);
int lr_db_getvalue(char * pFirstArg, ...);







 
 



















# 1 "c:\\lr\\script\\s001_amp_saversaccount_newappn\\\\combined_S001_AMP_SaversAccount_NewAppn.c" 2

# 1 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/SharedParameter.h" 1



 
 
 
 
# 100 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/SharedParameter.h"






typedef int PVCI2;






typedef int VTCERR2;


 
 
 

 
extern PVCI2    vtc_connect(char *servername, int portnum, int options);
extern VTCERR2  vtc_disconnect(PVCI2 pvci);
extern VTCERR2  vtc_get_last_error(PVCI2 pvci);

 
extern VTCERR2  vtc_query_column(PVCI2 pvci, char *columnName, int columnIndex, char **outvalue);
extern VTCERR2  vtc_query_row(PVCI2 pvci, int columnIndex, char ***outcolumns, char ***outvalues);
extern VTCERR2  vtc_send_message(PVCI2 pvci, char *column, char *message, unsigned short *outRc);
extern VTCERR2  vtc_send_if_unique(PVCI2 pvci, char *column, char *message, unsigned short *outRc);
extern VTCERR2  vtc_send_row1(PVCI2 pvci, char *columnNames, char *messages, char *delimiter,  unsigned char sendflag, unsigned short *outUpdates);
extern VTCERR2  vtc_search_row(PVCI2 pvci, char *columnNames, char *messages, char *delimiter, char ***outcolumns, char ***outvalues);
extern VTCERR2  vtc_update_message(PVCI2 pvci, char *column, int index , char *message, unsigned short *outRc);
extern VTCERR2  vtc_update_message_ifequals(PVCI2 pvci, char	*columnName, int index,	char *message, char	*ifmessage,	unsigned short 	*outRc);
extern VTCERR2  vtc_update_row1(PVCI2 pvci, char *columnNames, int index , char *messages, char *delimiter, unsigned short *outUpdates);
extern VTCERR2  vtc_retrieve_message(PVCI2 pvci, char *column, char **outvalue);
extern VTCERR2  vtc_retrieve_messages1(PVCI2 pvci, char *columnNames, char *delimiter, char ***outvalues);
extern VTCERR2  vtc_retrieve_row(PVCI2 pvci, char ***outcolumns, char ***outvalues);
extern VTCERR2  vtc_rotate_message(PVCI2 pvci, char *column, char **outvalue, unsigned char sendflag);
extern VTCERR2  vtc_rotate_messages1(PVCI2 pvci, char *columnNames, char *delimiter, char ***outvalues, unsigned char sendflag);
extern VTCERR2  vtc_rotate_row(PVCI2 pvci, char ***outcolumns, char ***outvalues, unsigned char sendflag);
extern VTCERR2	vtc_increment(PVCI2 pvci, char *column, int index , int incrValue, int *outValue);
extern VTCERR2  vtc_clear_message(PVCI2 pvci, char *column, int index , unsigned short *outRc);
extern VTCERR2  vtc_clear_column(PVCI2 pvci, char *column, unsigned short *outRc);

extern VTCERR2  vtc_clear_row(PVCI2 pvci, int rowIndex, unsigned short *outRc);

extern VTCERR2  vtc_create_column(PVCI2 pvci, char *column,unsigned short *outRc);
extern VTCERR2  vtc_column_size(PVCI2 pvci, char *column, int *size);
extern VTCERR2  vtc_ensure_index(PVCI2 pvci, char *column, unsigned short *outRc);
extern VTCERR2  vtc_drop_index(PVCI2 pvci, char *column, unsigned short *outRc);

extern VTCERR2  vtc_noop(PVCI2 pvci);

 
extern void vtc_free(char *msg);
extern void vtc_free_list(char **msglist);

 


 




 




















 




 
 
 

extern VTCERR2  lrvtc_connect(char *servername, int portnum, int options);
 
 
extern VTCERR2  lrvtc_disconnect();
extern VTCERR2  lrvtc_query_column(char *columnName, int columnIndex);
extern VTCERR2  lrvtc_query_row(int columnIndex);
extern VTCERR2  lrvtc_send_message(char *columnName, char *message);
extern VTCERR2  lrvtc_send_if_unique(char *columnName, char *message);
extern VTCERR2  lrvtc_send_row1(char *columnNames, char *messages, char *delimiter,  unsigned char sendflag);
extern VTCERR2  lrvtc_search_row(char *columnNames, char *messages, char *delimiter);
extern VTCERR2  lrvtc_update_message(char *columnName, int index , char *message);
extern VTCERR2  lrvtc_update_message_ifequals(char *columnName, int index, char 	*message, char *ifmessage);
extern VTCERR2  lrvtc_update_row1(char *columnNames, int index , char *messages, char *delimiter);
extern VTCERR2  lrvtc_retrieve_message(char *columnName);
extern VTCERR2  lrvtc_retrieve_messages1(char *columnNames, char *delimiter);
extern VTCERR2  lrvtc_retrieve_row();
extern VTCERR2  lrvtc_rotate_message(char *columnName, unsigned char sendflag);
extern VTCERR2  lrvtc_rotate_messages1(char *columnNames, char *delimiter, unsigned char sendflag);
extern VTCERR2  lrvtc_rotate_row(unsigned char sendflag);
extern VTCERR2  lrvtc_increment(char *columnName, int index , int incrValue);
extern VTCERR2  lrvtc_clear_message(char *columnName, int index);
extern VTCERR2  lrvtc_clear_column(char *columnName);
extern VTCERR2  lrvtc_clear_row(int rowIndex);
extern VTCERR2  lrvtc_create_column(char *columnName);
extern VTCERR2  lrvtc_column_size(char *columnName);
extern VTCERR2  lrvtc_ensure_index(char *columnName);
extern VTCERR2  lrvtc_drop_index(char *columnName);

extern VTCERR2  lrvtc_noop();

 
 
 

                               


 
 
 





















# 2 "c:\\lr\\script\\s001_amp_saversaccount_newappn\\\\combined_S001_AMP_SaversAccount_NewAppn.c" 2

# 1 "globals.h" 1



 
 

# 1 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/web_api.h" 1







# 1 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/as_web.h" 1



























































 




 



 











 





















 
 
 

  int
	web_add_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_add_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
	
  int
	web_add_auto_header(
		const char *		mpszHeader,
		const char *		mpszValue);

  int
	web_add_header(
		const char *		mpszHeader,
		const char *		mpszValue);
  int
	web_add_cookie(
		const char *		mpszCookie);
  int
	web_cleanup_auto_headers(void);
  int
	web_cleanup_cookies(void);
  int
	web_concurrent_end(
		const char * const	mpszReserved,
										 
		...								 
	);
  int
	web_concurrent_start(
		const char * const	mpszConcurrentGroupName,
										 
										 
		...								 
										 
	);
  int
	web_create_html_param(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim);
  int
	web_create_html_param_ex(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim,
		const char *		mpszNum);
  int
	web_custom_request(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	spdy_custom_request(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_disable_keep_alive(void);
  int
	web_enable_keep_alive(void);
  int
	web_find(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_get_int_property(
		const int			miHttpInfoType);
  int
	web_image(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_image_check(
		const char *		mpszName,
		...);
  int
	web_java_check(
		const char *		mpszName,
		...);
  int
	web_link(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

	
  int
	web_global_verification(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
  int
	web_reg_find(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
				
  int
	web_reg_save_param(
		const char *		mpszParamName,
		...);							 
										 
										 
										 
										 
										 
										 

  int
	web_convert_param(
		const char * 		mpszParamName, 
										 
		...);							 
										 
										 


										 

										 
  int
	web_remove_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
				
  int
	web_remove_auto_header(
		const char *		mpszHeaderName,
		...);							 
										 



  int
	web_remove_cookie(
		const char *		mpszCookie);

  int
	web_save_header(
		const char *		mpszType,	 
		const char *		mpszName);	 
  int
	web_set_certificate(
		const char *		mpszIndex);
  int
	web_set_certificate_ex(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_set_connections_limit(
		const char *		mpszLimit);
  int
	web_set_max_html_param_len(
		const char *		mpszLen);
  int
	web_set_max_retries(
		const char *		mpszMaxRetries);
  int
	web_set_proxy(
		const char *		mpszProxyHost);
  int
	web_set_pac(
		const char *		mpszPacUrl);
  int
	web_set_proxy_bypass(
		const char *		mpszBypass);
  int
	web_set_secure_proxy(
		const char *		mpszProxyHost);
  int
	web_set_sockets_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue
	);
  int
	web_set_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue,
		...								 
	);
  int
	web_set_timeout(
		const char *		mpszWhat,
		const char *		mpszTimeout);
  int
	web_set_user(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);

  int
	web_sjis_to_euc_param(
		const char *		mpszParamName,
										 
		const char *		mpszParamValSjis);
										 

  int
	web_submit_data(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	spdy_submit_data(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_submit_form(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_url(
		const char *		mpszUrlName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	spdy_url(
		const char *		mpszUrlName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_set_proxy_bypass_local(
		const char * mpszNoLocal
		);

  int 
	web_cache_cleanup(void);

  int
	web_create_html_query(
		const char* mpszStartQuery,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_create_radio_button_param(
		const char *NameFiled,
		const char *NameAndVal,
		const char *ParamName
		);

  int
	web_convert_from_formatted(
		const char * mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										
  int
	web_convert_to_formatted(
		const char * mpszArg1,
		...);							 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_ex(
		const char * mpszParamName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_xpath(
		const char * mpszParamName,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_json(
		const char * mpszParamName,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_regexp(
		 const char * mpszParamName,
		 ...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_attrib(
		const char * mpszParamName,
		...);
										 
										 
										 
										 
										 
										 
										 		
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_js_run(
		const char * mpszCode,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_js_reset(void);

  int
	web_convert_date_param(
		const char * 		mpszParamName,
		...);










# 789 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/as_web.h"


# 802 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/as_web.h"



























# 840 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/as_web.h"

 
 
 


  int
	FormSubmit(
		const char *		mpszFormName,
		...);
  int
	InitWebVuser(void);
  int
	SetUser(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);
  int
	TerminateWebVuser(void);
  int
	URL(
		const char *		mpszUrlName);
























# 908 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/as_web.h"


  int
	web_rest(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 

  int
web_stream_open(
	const char *		mpszArg1,
	...
);
  int
	web_stream_wait(
		const char *		mpszArg1,
		...
	);

  int
	web_stream_close(
		const char *		mpszArg1,
		...
	);

  int
web_stream_play(
	const char *		mpszArg1,
	...
	);

  int
web_stream_pause(
	const char *		mpszArg1,
	...
	);

  int
web_stream_seek(
	const char *		mpszArg1,
	...
	);

  int
web_stream_get_param_int(
	const char*			mpszStreamID,
	const int			miStateType
	);

  double
web_stream_get_param_double(
	const char*			mpszStreamID,
	const int			miStateType
	);

  int
web_stream_get_param_string(
	const char*			mpszStreamID,
	const int			miStateType,
	const char*			mpszParameterName
	);

  int
web_stream_set_param_int(
	const char*			mpszStreamID,
	const int			miStateType,
	const int			miStateValue
	);

  int
web_stream_set_param_double(
	const char*			mpszStreamID,
	const int			miStateType,
	const double		mdfStateValue
	);

  int
web_stream_set_custom_mpd(
	const char*			mpszStreamID,
	const char*			aMpdBuf
	);

 
 
 






# 9 "C:\\Program Files (x86)\\Micro Focus\\Virtual User Generator\\include/web_api.h" 2

















 







 















  int
	web_reg_add_cookie(
		const char *		mpszCookie,
		...);							 
										 

  int
	web_report_data_point(
		const char *		mpszEventType,
		const char *		mpszEventName,
		const char *		mpszDataPointName,
		const char *		mpszLAST);	 
										 
										 
										 

  int
	web_text_link(
		const char *		mpszStepName,
		...);

  int
	web_element(
		const char *		mpszStepName,
		...);

  int
	web_image_link(
		const char *		mpszStepName,
		...);

  int
	web_static_image(
		const char *		mpszStepName,
		...);

  int
	web_image_submit(
		const char *		mpszStepName,
		...);

  int
	web_button(
		const char *		mpszStepName,
		...);

  int
	web_edit_field(
		const char *		mpszStepName,
		...);

  int
	web_radio_group(
		const char *		mpszStepName,
		...);

  int
	web_check_box(
		const char *		mpszStepName,
		...);

  int
	web_list(
		const char *		mpszStepName,
		...);

  int
	web_text_area(
		const char *		mpszStepName,
		...);

  int
	web_map_area(
		const char *		mpszStepName,
		...);

  int
	web_eval_java_script(
		const char *		mpszStepName,
		...);

  int
	web_reg_dialog(
		const char *		mpszArg1,
		...);

  int
	web_reg_cross_step_download(
		const char *		mpszArg1,
		...);

  int
	web_browser(
		const char *		mpszStepName,
		...);

  int
	web_control(
		const char *		mpszStepName,
		...);

  int
	web_set_rts_key(
		const char *		mpszArg1,
		...);

  int
	web_save_param_length(
		const char * 		mpszParamName,
		...);

  int
	web_save_timestamp_param(
		const char * 		mpszParamName,
		...);

  int
	web_load_cache(
		const char *		mpszStepName,
		...);							 
										 

  int
	web_dump_cache(
		const char *		mpszStepName,
		...);							 
										 
										 

  int
	web_reg_find_in_log(
		const char *		mpszArg1,
		...);							 
										 
										 

  int
	web_get_sockets_info(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 

  int
	web_add_cookie_ex(
		const char *		mpszArg1,
		...);							 
										 
										 
										 

  int
	web_hook_java_script(
		const char *		mpszArg1,
		...);							 
										 
										 
										 

 
 
 
 
 
 
 
 
 
 
 
 
  int
	web_reg_async_attributes(
		const char *		mpszArg,
		...
	);

 
 
 
 
 
 
  int
	web_sync(
		 const char *		mpszArg1,
		 ...
	);

 
 
 
 
  int
	web_stop_async(
		const char *		mpszArg1,
		...
	);

 
 
 
 
 

 
 
 

typedef enum WEB_ASYNC_CB_RC_ENUM_T
{
	WEB_ASYNC_CB_RC_OK,				 

	WEB_ASYNC_CB_RC_ABORT_ASYNC_NOT_ERROR,
	WEB_ASYNC_CB_RC_ABORT_ASYNC_ERROR,
										 
										 
										 
										 
	WEB_ASYNC_CB_RC_ENUM_COUNT
} WEB_ASYNC_CB_RC_ENUM;

 
 
 

typedef enum WEB_CONVERS_CB_CALL_REASON_ENUM_T
{
	WEB_CONVERS_CB_CALL_REASON_BUFFER_RECEIVED,
	WEB_CONVERS_CB_CALL_REASON_END_OF_TASK,

	WEB_CONVERS_CB_CALL_REASON_ENUM_COUNT
} WEB_CONVERS_CB_CALL_REASON_ENUM;

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

typedef
int														 
	(*RequestCB_t)();

typedef
int														 
	(*ResponseBodyBufferCB_t)(
		  const char *		aLastBufferStr,
		  int				aLastBufferLen,
		  const char *		aAccumulatedStr,
		  int				aAccumulatedLen,
		  int				aHttpStatusCode);

typedef
int														 
	(*ResponseCB_t)(
		  const char *		aResponseHeadersStr,
		  int				aResponseHeadersLen,
		  const char *		aResponseBodyStr,
		  int				aResponseBodyLen,
		  int				aHttpStatusCode);

typedef
int														 
	(*ResponseHeadersCB_t)(
		  int				aHttpStatusCode,
		  const char *		aAccumulatedHeadersStr,
		  int				aAccumulatedHeadersLen);



 
 
 

typedef enum WEB_CONVERS_UTIL_RC_ENUM_T
{
	WEB_CONVERS_UTIL_RC_OK,
	WEB_CONVERS_UTIL_RC_CONVERS_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_TASK_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_INFO_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_INFO_UNAVIALABLE,
	WEB_CONVERS_UTIL_RC_INVALID_ARGUMENT,

	WEB_CONVERS_UTIL_RC_ENUM_COUNT
} WEB_CONVERS_UTIL_RC_ENUM;

 
 
 

  int					 
	web_util_set_request_url(
		  const char *		aUrlStr);

  int					 
	web_util_set_request_body(
		  const char *		aRequestBodyStr);

  int					 
	web_util_set_formatted_request_body(
		  const char *		aRequestBodyStr);


 
 
 
 
 

 
 
 
 
 

 
 
 
 
 
 
 
 

 
 
  int
web_websocket_connect(
		 const char *	mpszArg1,
		 ...
		 );


 
 
 
 
 																						
  int
web_websocket_send(
	   const char *		mpszArg1,
		...
	   );

 
 
 
 
 
 
  int
web_websocket_close(
		const char *	mpszArg1,
		...
		);

 
typedef
void														
(*OnOpen_t)(
			  const char* connectionID,  
			  const char * responseHeader,  
			  int length  
);

typedef
void														
(*OnMessage_t)(
	  const char* connectionID,  
	  int isbinary,  
	  const char * data,  
	  int length  
	);

typedef
void														
(*OnError_t)(
	  const char* connectionID,  
	  const char * message,  
	  int length  
	);

typedef
void														
(*OnClose_t)(
	  const char* connectionID,  
	  int isClosedByClient,  
	  int code,  
	  const char* reason,  
	  int length  
	 );
 
 
 
 
 





# 7 "globals.h" 2

# 1 "lrw_custom_body.h" 1
 




# 8 "globals.h" 2



 
 
	int i, addresslength;
	
	char addresstemp[70]="";
	char address[70]="";	
	char addresspartial[70]="";
	
	 
	int t = 2;
	

# 3 "c:\\lr\\script\\s001_amp_saversaccount_newappn\\\\combined_S001_AMP_SaversAccount_NewAppn.c" 2

# 1 "vuser_init.c" 1
vuser_init()
{
	
		
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
		
	return 0;
}
# 4 "c:\\lr\\script\\s001_amp_saversaccount_newappn\\\\combined_S001_AMP_SaversAccount_NewAppn.c" 2

# 1 "HomePage.c" 1
HomePage()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	
	lr_start_transaction("S001_T001_AMPSavAcc_HomePage");

	web_reg_find("Search=Body",
		"Text=AMP is here to help",
		"LAST");

	web_url("www.{P_Host}", 
		"URL=http://www.{P_Host}/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		"EXTRARES", 
		"Url=https://www.{P_Host}/ddc/public/ui/assets/ddc-fonts/ddc-fonts.css", "Referer=https://www.{P_Host}/etc/designs/amp-au/clientlibs/clientlib-site.css", "ENDITEM", 
		"Url=https://www.{P_Host}/etc/designs/amp-au/assets/aa8fe13f4c832769bd0ab2ea7e247013.svg", "Referer=https://www.{P_Host}/etc/designs/amp-au/clientlibs/clientlib-site.css", "ENDITEM", 
		"Url=https://www.{P_Host}/etc/designs/amp-au/clientlibs/legacy-nps.js?_=1634859408956", "Referer=https://www.{P_Host}/", "ENDITEM", 
		"Url=https://www.{P_Host}/etc/designs/amp-au/assets/819af3d3abdc9f135d49b80a91e2ff4c.woff2", "Referer=https://www.{P_Host}/etc/designs/amp-au/clientlibs/clientlib-site.css", "ENDITEM", 
		"Url=https://www.{P_Host}/etc/designs/amp-au/assets/98c3ea22ad6bca213fa88175f7d9ffaf.woff2", "Referer=https://www.{P_Host}/etc/designs/amp-au/clientlibs/clientlib-site.css", "ENDITEM", 
		"Url=https://www.{P_Host}/etc/designs/amp-au/assets/2525a15d1fb3ce824a7aad5e07ba2513.ttf", "Referer=https://www.{P_Host}/etc/designs/amp-au/clientlibs/clientlib-site.css", "ENDITEM", 
		"Url=https://www.{P_Host}/etc/designs/amp-au/assets/ce62fa71a1a38af297b433e85d36d83f.woff2", "Referer=https://www.{P_Host}/etc/designs/amp-au/clientlibs/clientlib-site.css", "ENDITEM", 
		"Url=https://www.{P_Host}/etc/designs/amp-au/assets/33543c5cc5d88f5695dd08c87d280dfd.woff2", "Referer=https://www.{P_Host}/etc/designs/amp-au/clientlibs/clientlib-site.css", "ENDITEM", 
		"Url=https://www.{P_Host}/etc/designs/amp-au/assets/5c32de29c638fdf3bb4adc662a0ad595.woff2", "Referer=https://www.{P_Host}/etc/designs/amp-au/clientlibs/clientlib-site.css", "ENDITEM", 
		"Url=https://www.{P_Host}/etc/designs/amp/assets/fonts/xtreme.woff", "Referer=https://www.{P_Host}/etc/designs/amp/clientLibraries/icons-libs.css", "ENDITEM", 
		"LAST");


	web_url("www.{P_Host}_2", 
		"URL=https://www.{P_Host}/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.{P_Host}/", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		"LAST");

	
	lr_end_transaction("S001_T001_AMPSavAcc_HomePage", 2);
	
	lr_think_time(t);

	return 0;
}
# 5 "c:\\lr\\script\\s001_amp_saversaccount_newappn\\\\combined_S001_AMP_SaversAccount_NewAppn.c" 2

# 1 "NavigateTo_NewApplication.c" 1
NavigateTo_NewApplication()
{
	
	lr_start_transaction("S001_T002_AMPSavAcc_Banking");
	
	web_reg_find("Search=Body",
		"Text=control of your money",
		"LAST");

	web_url("banking", 
		"URL=https://www.{P_Host}/banking", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.{P_Host}/", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		"EXTRARES", 
		"Url=/content/dam/amp-au/authoring/promotion-banner/banner-background-1.jpg", "ENDITEM", 
		"Url=/content/dam/amp-au/images/banking-hub/banners/kombi_van_product_promo.jpg", "ENDITEM", 
		"Url=/etc/designs/amp-au/clientlibs/legacy-nps.js?_=1634859451120", "ENDITEM", 
		"LAST");


	lr_end_transaction("S001_T002_AMPSavAcc_Banking", 2);
	
	lr_think_time(t);	
	
	lr_start_transaction("S001_T003_AMPSavAcc_SavingsAccount");

	 

	
	web_reg_find("Search=Body",
		"Text=High Interest Saving Accounts",
		"LAST");

	web_url("savings-accounts", 
		"URL=https://www.{P_Host}/banking/savings-accounts", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.{P_Host}/banking", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		"EXTRARES", 
		"Url=../content/dam/amp-au/images/thumbnail/my-amp.jpg", "ENDITEM", 
		"Url=../content/dam/amp-au/images/thumbnail/debit-card.jpg", "ENDITEM", 
		"Url=../content/dam/amp-au/images/thumbnail/savings-calculator.jpg", "ENDITEM", 
		"Url=../etc/designs/amp-au/clientlibs/legacy-nps.js?_=1634859466075", "ENDITEM", 
		"LAST");

	lr_end_transaction("S001_T003_AMPSavAcc_SavingsAccount", 2);
	
	lr_think_time(t);
	 	
	
	lr_start_transaction("S001_T004_AMPSavAcc_Learnmore");


	web_reg_find("Search=Body",
		"Text=The AMP Saver is an award-winning",
		"LAST");

	web_url("amp-saver-account", 
		"URL=https://www.{P_Host}/banking/savings-accounts/amp-saver-account", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.{P_Host}/banking/savings-accounts", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		"EXTRARES", 
		"Url=/etc/designs/amp-au/clientlibs/legacy-nps.js?_=1634859487325", "ENDITEM", 
		"LAST");


	lr_end_transaction("S001_T004_AMPSavAcc_Learnmore", 2);

	lr_think_time(t);
	 
	
	lr_start_transaction("S001_T005_AMPSavAcc_OpenAnAccount");



	web_reg_find("Search=Body",
		"Text=AMP Saver Account",
		"LAST");

	web_url("saver-account", 
		"URL=https://secure.{P_Host}/ddc/public/ui/saver-account/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.{P_Host}/banking/savings-accounts/amp-saver-account", 
		"Snapshot=t38.inf", 
		"Mode=HTML", 
		"EXTRARES", 
		"Url=https://www.{P_Host}/etc/designs/amp/clientLibraries/icons-libs.min.css", "Referer=https://secure.{P_Host}/", "ENDITEM", 
		"Url=../assets/ddc-fonts/ddc-fonts.css", "ENDITEM", 
		"Url=styles.0761fd239214ab23c67e.css", "ENDITEM", 
		"Url=config.js", "ENDITEM", 
		"Url=runtime.a5b4734854bf1bbfa0a2.js", "ENDITEM", 
		"Url=https://www.{P_Host}/fonts/282695/EFFED685B8BB01EC4.css", "Referer=https://secure.{P_Host}/", "ENDITEM", 
		"Url=polyfills.7a1195e67f8d2d0712cb.js", "ENDITEM", 
		"Url=main.f7ae96794faee45a389f.js", "ENDITEM", 
		"LAST");



	web_url("saver-account_2", 
		"URL=https://secure.{P_Host}/ddc/public/ui/saver-account/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://secure.{P_Host}/ddc/public/ui/saver-account/", 
		"Snapshot=t41.inf", 
		"Mode=HTML", 
		"EXTRARES", 
		"Url=../assets/ddc-fonts/ddc-fonts.css", "ENDITEM", 
		"Url=assets/images/Intro-background_min.jpg", "ENDITEM", 
		"LAST");



 
	web_reg_save_param_json(
		"ParamName=C_updateddate",
		"QueryString=$.cq:lastModified",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=No",
		"LAST");

	web_url("_jcr_content.json", 
		"URL=https://www.{P_Host}/content/amp-secure/my-amp/ddc/saver-account/DDO/_jcr_content.json", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://secure.{P_Host}/", 
		"Snapshot=t44.inf", 
		"Mode=HTML", 
		"LAST");


	web_custom_request("usersession", 
		"URL=https://secure.{P_Host}/services/secure/ddc/1.0.0/usersession", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://secure.{P_Host}/ddc/public/ui/saver-account/", 
		"Snapshot=t47.inf", 
		"Mode=HTML", 
		"LAST");

	
	web_custom_request("usersession_2", 
		"URL=https://secure.{P_Host}/services/secure/ddc/1.0.0/usersession", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://secure.{P_Host}/ddc/public/ui/saver-account/", 
		"Snapshot=t48.inf", 
		"Mode=HTML", 
		"EXTRARES", 
		"Url=https://www.{P_Host}/content/dam/amp/digitalhub/common/images/systems/ddc/amp-blue.png", "Referer=https://secure.{P_Host}/", "ENDITEM", 
		"LAST");


	web_custom_request("countries", 
		"URL=https://secure.{P_Host}/ddc/public/api/refdata/countries", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://secure.{P_Host}/ddc/public/ui/saver-account/", 
		"Snapshot=t49.inf", 
		"Mode=HTML", 
		"EXTRARES", 
		"Url=https://www.googleadservices.com/pagead/conversion_async.js", "Referer=https://secure.{P_Host}/", "ENDITEM", 
		"LAST");

	lr_end_transaction("S001_T005_AMPSavAcc_OpenAnAccount", 2);

	lr_think_time(t);
	
	

	
	 
	
	web_reg_save_param("C_SecToken",
		"LB=SAVERACCOUNT\",\"securityToken\":\"",
		"RB=\",\"marketingCorrelationIds\":",
		"LAST");	  
	

 
	web_reg_save_param_json(
		"ParamName=C_formId",
		"QueryString=$.payload.meta.id",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=No",
		"LAST");

	web_reg_find("Search=Body",
		"Text=SaverAccount",
		"LAST");
		
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
		"LAST");


	lr_end_transaction("S001_T006_AMPSavAcc_SelectJustMe", 2);

	lr_think_time(t);
	 

	lr_start_transaction("S001_T007_AMPSavAcc_Proceed");


	web_reg_find("Search=Body",
		"Text=statusCode\":200",
		"LAST");

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
		"LAST");


	lr_end_transaction("S001_T007_AMPSavAcc_Proceed", 2);
	return 0;
}
# 6 "c:\\lr\\script\\s001_amp_saversaccount_newappn\\\\combined_S001_AMP_SaversAccount_NewAppn.c" 2

# 1 "NewApplication_FillUp.c" 1
NewApplication_FillUp()
{
	
	
	 
	lr_start_transaction("S001_T008_AMPSavAcc_EnterPersonaldetails");

	
	web_reg_find("Search=Body",
		"Text=statusCode\":200",
		"LAST");

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
		"LAST");

	lr_end_transaction("S001_T008_AMPSavAcc_EnterPersonaldetails", 2);

	lr_think_time(t);
	 
		
	lr_start_transaction("S001_T009_AMPSavAcc_EnterAddress_ParentTxn");


	 
	strcpy(addresstemp,lr_eval_string("{P_address}"));      

	 
    addresslength = strlen(addresstemp);
    
     
    
	 for(i=3;i <= addresslength;i++)
            
    {
    
	  
	 strncpy(address, addresstemp, i);
	 
	  
	 lr_save_string(address, "addresspartial");
	
		
	 
	web_reg_save_param_json(
		"ParamName=C_SelItem",
		"QueryString=$.payload.QAPicklist.PicklistEntry[0].Moniker",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=No",
		"Notfound=warning",
		"LAST");
		
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
		"LAST");
	lr_end_transaction("S001_T009_AMPSavAcc_EnterAddress", 2);
	
	lr_think_time(t);

	 }
	 
	

 
	web_reg_save_param_json(
		"ParamName=C_dpid",
		"QueryString=$.payload.DDC.DPID/DID",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=No",
		"LAST");
		
  web_reg_save_param("C_barcode",
                   "LB=AUSBAR\.\":\"",
                   "RB=\"",
                   "ord=1",
                   "LAST");

  web_convert_param("C_SelItemurl",
                  "SourceString={C_SelItem}",    
                  "SourceEncoding=PLAIN",
                  "TargetEncoding=URL",
                  "LAST");
                  
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
		"LAST");

	lr_end_transaction("S001_T009_AMPSavAcc_EnterAddress_ParentTxn", 2);
	
	lr_think_time(t);
	 

	lr_start_transaction("S001_T010_AMPSavAcc_SelectAddress");

	web_reg_find("Search=Body",
		"Text=statusCode\":200",
		"LAST");

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
		"LAST");



	web_reg_find("Search=Body",
		"Text=statusCode\":200",
		"LAST");

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
		"LAST");
	
	lr_end_transaction("S001_T010_AMPSavAcc_SelectAddress", 2);

	lr_think_time(t);
	 
	
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
		"LAST");


	web_url("individual", 
		"URL=https://secure.{P_Host}/ddc/public/api/api-crs/AUS/individual?resCountry=AUS&postalCountry=AUS", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://secure.{P_Host}/ddc/public/ui/saver-account/", 
		"Snapshot=t90.inf", 
		"Mode=HTML", 
		"LAST");

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
		"LAST");



	web_reg_find("Search=Body",
		"Text=statusCode\":200",
		"LAST");

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
		"LAST");

	lr_end_transaction("S001_T011_AMPSavAcc_EnterTaxDetails", 2);
	lr_think_time(t);

	return 0;
}
# 7 "c:\\lr\\script\\s001_amp_saversaccount_newappn\\\\combined_S001_AMP_SaversAccount_NewAppn.c" 2

# 1 "IdentityCheck.c" 1
IdentityCheck()
{
	 

	lr_start_transaction("S001_T012_AMPSavAcc_IdentityCheck");


 
	web_reg_save_param_json(
		"ParamName=C_verifiId",
		"QueryString=$.payload.verificationId",
		"SEARCH_FILTERS",
		"Scope=Body",
		"IgnoreRedirections=No",
		"LAST");

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
		"LAST");

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
		"LAST");


	web_add_auto_header("Origin", 
		"https://secure.{P_Host}");

	web_add_auto_header("Sec-Fetch-Site", 
		"cross-site");


	lr_end_transaction("S001_T012_AMPSavAcc_IdentityCheck", 2);

	lr_think_time(t);
	 
	
	lr_start_transaction("S001_T013_AMPSavAcc_IdentityCheck_Skip");



	web_reg_find("Search=Body",
		"Text=statusCode\":200",
		"LAST");

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
		"LAST");

	lr_end_transaction("S001_T013_AMPSavAcc_IdentityCheck_Skip", 2);
	lr_think_time(t);
	
	return 0;
}
# 8 "c:\\lr\\script\\s001_amp_saversaccount_newappn\\\\combined_S001_AMP_SaversAccount_NewAppn.c" 2

# 1 "Declaration.c" 1
Declaration()
{
	 
	
	lr_start_transaction("S001_T014_AMPSavAcc_TickDeclarations");


	web_reg_find("Search=Body",
		"Text=statusCode\":200",
		"LAST");

	web_custom_request("save_10",
		"URL=https://secure.{P_Host}/ddc/public/api/forms/save?formId={C_formId}&checkSecurityToken={C_SecToken}&formName=SaverAccount&checkDob={P_DOB}&checkName={P_Lname}",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://secure.{P_Host}/ddc/public/ui/saver-account/",
		"Snapshot=t104.inf",
		"Mode=HTML",
		"EncType=application/json",
		"BodyBinary={\"welcome\":{\"tags\":\"[\\\\\"customer\\\\\"]\",\"continueApplication\":null,\"newApplication\":true},\"newOrExistingCustomer\":{\"customerType\":\"New\"},\"captcha\":{},\"adviser\":{},\"singleOrJoint\":{\"applicationType\":\"Individual\"},\"applicants\":[{\"personalDetails\":{\"basicInfo\":{\"firstName\":\"{P_Fname}\",\"surName\":\"{P_Lname}\",\"dateOfBirth\":\"{P_DOB}\",\"scvId\":null,\"hasAdpId\":null,\"title\":{\"SelectedItem\":\"Mr\",\"Query\":\"Mr\"},\"middleName\":\"{P_Mname}\"},\"contactDetails\":{\"emailAddress\":\"{P_email}\",\"mobilePhone\":\"{P_mob}\",\"homePhone\":null},\"address\":{\"addresses\":{\"isAnyAddressInternational\":false,\"residentialAddress\":{\"isManualSearch\":false,\"search\":{\"selectedItem\":\"{C_SelItem}\",\"query\":\"{P_address}\"},\"manualAddress\":{\"country\":{\"SelectedItem\":\"AUS\",\"Query\":\"Australia\"},\"addressLine1\":null,\"addressLine2\":null,\"buildingName\":null,\"floorNumber\":null,\"unitNumber\":\"{P_Unitno}\",\"subBuildingNumber\":null,\"streetNumb"
		"er\":\"40\",\"streetName\":\"{P_StreetName}\",\"streetType\":{\"SelectedItem\":\"{P_StreetType}\",\"Query\":\"Street\"},\"poBox\":null,\"suburb\":\"{P_suburb}\",\"state\":{\"SelectedItem\":\"{P_state}\",\"Query\":\"{P_state}\"},\"ruralDelivery\":null,\"city\":null,\"province\":null,\"postCode\":\"{P_postcode}\",\"dpid\":\"{C_dpid}\",\"barcode\":\"{C_barcode}\",\"isInternational\":false},\"isItPoBox\":false},\"postalAndResidentialAreSame\":true},\"editLocked\":null,\"externallyMaintainedAddress\":null}},\"furtherQuestions\":{\"taxFileNumber\":{\"hasTaxFileNumber\":false,\"ok\":true,\"noTaxFileNumberReason\":{\"SelectedItem\":\"ExemptForTFN\",\"Query\":\"Exempt for TFN\"},\"change\":null},\"foreignTaxResident\":{\"attempts\":0,\"addressFDN\":\"applicants.0.personalDetails.address\",\"crsStatus\":\"pass\",\"addresses\":[\"{P_address}\",\"{P_address}\"],\"countries\":[\"AUS\",\"AUS\"],\"entityType\":\"individual\",\"isForeignTaxResident\":false},\"reasonablenessOutcome\":{\"ok\":null},\"amlQuestions\":{\"primarySourceOfWealth\":{\"SelectedItem\":"
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
		"\",\"productSelection\":\"Proceed\",\"updatedDate\":\"{C_updateddate}\"}}}],\"accountDetails\":{\"preferences\":{},\"declarations\":{\"lastStep\":{\"privacyDeclaration\":true,\"acceptTandCsDeclaration\":true,\"acceptCRSDeclaration\":true}}},\"review\":{},\"personalOrSoleTrader\":{\"accountType\":\"personal\"}}",
		"LAST");

	lr_end_transaction("S001_T014_AMPSavAcc_TickDeclarations", 2);
	lr_think_time(t);
	
	return 0;
}
# 9 "c:\\lr\\script\\s001_amp_saversaccount_newappn\\\\combined_S001_AMP_SaversAccount_NewAppn.c" 2

# 1 "CancelApplication.c" 1
CancelApplication()
{
	 
	
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
		"LAST");


	web_reg_find("Search=Body",
		"Text=Contact us",
		"LAST");

	web_url("amp-saver-account_2", 
		"URL=https://www.{P_Host}/banking/savings-accounts/amp-saver-account", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://secure.{P_Host}/", 
		"Snapshot=t106.inf", 
		"Mode=HTML", 
		"LAST");

	

	lr_end_transaction("S001_T015_AMPSavAcc_CancelApplicaton", 2);
	return 0;
}
# 10 "c:\\lr\\script\\s001_amp_saversaccount_newappn\\\\combined_S001_AMP_SaversAccount_NewAppn.c" 2

# 1 "vuser_end.c" 1
vuser_end()
{
	return 0;
}
# 11 "c:\\lr\\script\\s001_amp_saversaccount_newappn\\\\combined_S001_AMP_SaversAccount_NewAppn.c" 2

