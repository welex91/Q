/* Following from bash
str="{ \"_id\" : \"333\", \"company\" : \"LinkedIn Corp\" }"
echo $str > _tempf
str=`cat _tempf`
rm -f _tempf
echo "Posting [$str]"
curl -X POST http://127.0.0.1:5984/rameshdb/ \
	-H "Content-Type: application/json"  \
	-d "$str"
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "constants.h"
#include "macros.h"

/* from command line

	 doc=123456; curl -X PUT localhost:5984/rameshdb/$docid
	 --data-urlencode '{"_id":"$docid","data":"Foo"}'

	 */

int 
add_to_couchdb(
		char *server,
		char *port,
		char *database,
		char *docid,
		char *document
		)
{
  int status = 0;
  CURL *ch = NULL;
  CURLcode curl_res;
  CURLINFO info;
  long http_code;
  double c_length;  
	char *url  = NULL;
	int url_len = strlen(server) + strlen(port) + strlen(database) +
		strlen(docid);
	url_len = ((url_len / 32) + 2)*32;
	url = malloc(url_len * sizeof(char));
	for ( int i = 0; i < url_len; i++ ) { url[i] = '\0'; }
	sprintf(url, "http://%s:%s/%s/%s", server, port, database, docid);

  fprintf(stderr, "url=\"%s\"\n", url);
  printf("init curl session\n");
  ch = curl_easy_init();
  printf("set url to download\n");
  curl_easy_setopt(ch, CURLOPT_URL, url);
   // follow redirects
  curl_easy_setopt(ch, CURLOPT_FOLLOWLOCATION, 1);
  // insecure is okay
  curl_easy_setopt(ch, CURLOPT_SSL_VERIFYHOST, 0);
  curl_easy_setopt(ch, CURLOPT_SSL_VERIFYPEER, 0);
  curl_res = curl_easy_perform(ch);
  if ( curl_res != 0 ) { go_BYE(-1); }
  printf("get http return code\n");
  curl_easy_getinfo(ch, CURLINFO_RESPONSE_CODE, &http_code);
  printf("http code: %lu\n", http_code);
BYE:
  curl_easy_cleanup(ch);
	free_if_non_null(url);
  return status ;
}

int 
main(
		int argc,
		char **argv
		)
{
	int status = 0;
	char *server = "localhost";
	char *port = "5894"; 
	char *database = "rameshdb";
	char *docid = "1";
	char *document = "/tmp/1.json";
	status = add_to_couchdb(server, port, database, docid, document);
	cBYE(status);
BYE:
	return(status);
}

