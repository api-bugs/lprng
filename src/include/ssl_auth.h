/***************************************************************************
 * LPRng - An Extended Print Spooler System
 *
 * Copyright 1988-2003, Patrick Powell, San Diego, CA
 *     papowell@lprng.com
 * See LICENSE for conditions of use.
 ***************************************************************************/



#ifndef _SSL_AUTH_H_
#define _SSL_AUTH_H_ 1


#ifdef SSL_ENABLE

#ifndef WITHPLUGINS
extern const struct security ssl_auth;
#endif

#include <openssl/ssl.h>
#include <openssl/err.h>


/* PROTOTYPES (used by IPP SSL) */

int SSL_Initialize_ctx(SSL_CTX **ctx_ret, char *errmsg, int errlen);
void Destroy_ctx(SSL_CTX *ctx);
int Accept_SSL_connection( int sock, int timeout, SSL_CTX *ctx, SSL **ssl_ret,
	struct line_list *info, char *errmsg, int errlen );
int Write_SSL_connection( int timeout, SSL *ssl, char *buffer, int len,
	char *errmsg, int errlen );
int Read_SSL_connection( int timeout, SSL *ssl, char *inbuffer, int *len,
	char *errmsg, int errlen );

int Close_SSL_connection( int sock, SSL *ssl );

int Ssl_send( int *sock,
	int transfer_timeout,
	char *tempfile,
	char *errmsg, int errlen,
	const struct security *security, struct line_list *info );
int Ssl_receive( int *sock, int transfer_timeout,
	char *user, char *jobsize, int from_server, char *authtype,
	struct line_list *info,
	char *errmsg, int errlen,
	struct line_list *header_info,
	const struct security *security, char *tempfile,
	SECURE_WORKER_PROC do_secure_work);

#endif

#endif
