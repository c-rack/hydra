/*  =========================================================================
    hydra_msg - The Hydra Protocol
    
    Codec header for hydra_msg.

    ** WARNING *************************************************************
    THIS SOURCE FILE IS 100% GENERATED. If you edit this file, you will lose
    your changes at the next build cycle. This is great for temporary printf
    statements. DO NOT MAKE ANY CHANGES YOU WISH TO KEEP. The correct places
    for commits are:

     * The XML model used for this code generation: hydra_msg.xml, or
     * The code generation script that built this file: zproto_codec_c
    ************************************************************************
    Copyright (c) the Contributors as noted in the AUTHORS file.       
    This file is part of zbroker, the ZeroMQ broker project.           
                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           
    =========================================================================
*/

#ifndef __HYDRA_MSG_H_INCLUDED__
#define __HYDRA_MSG_H_INCLUDED__

/*  These are the hydra_msg messages:

    HELLO - Open new connection and ask for most recent post

    HELLO_OK - Return last post known for peer
        post_id             string      Post identifier

    GET_TAGS - Request list of tags known by peer

    GET_TAGS_OK - Return list of known tags
        tags                string      List of known tags

    GET_TAG - Request last post for a given tag
        tag                 string      Name of tag

    GET_TAG_OK - Return last post for given tag
        tag                 string      Name of tag
        post_id             string      Post identifier

    GET_POST - Fetch a given post
        post_id             string      Post identifier

    GET_POST_OK - Return a post details
        post_id             string      Post identifier
        reply_to            string      Parent post, if any
        previous            string      Previous post, if any
        tags                string      Post tags
        timestamp           number 8    Post creation timestamp
        type                string      Content type
        content             string      Content body

    GOODBYE - Close the connection politely

    GOODBYE_OK - Handshake a connection close

    INVALID - Command was invalid at this time

    FAILED - Command failed for some specific reason
        reason              string      Reason for failure
*/


#define HYDRA_MSG_HELLO                     1
#define HYDRA_MSG_HELLO_OK                  2
#define HYDRA_MSG_GET_TAGS                  3
#define HYDRA_MSG_GET_TAGS_OK               4
#define HYDRA_MSG_GET_TAG                   5
#define HYDRA_MSG_GET_TAG_OK                6
#define HYDRA_MSG_GET_POST                  7
#define HYDRA_MSG_GET_POST_OK               8
#define HYDRA_MSG_GOODBYE                   9
#define HYDRA_MSG_GOODBYE_OK                10
#define HYDRA_MSG_INVALID                   11
#define HYDRA_MSG_FAILED                    12

#include <czmq.h>

#ifdef __cplusplus
extern "C" {
#endif

//  Opaque class structure
#ifndef HYDRA_MSG_T_DEFINED
typedef struct _hydra_msg_t hydra_msg_t;
#define HYDRA_MSG_T_DEFINED
#endif

//  @interface
//  Create a new empty hydra_msg
hydra_msg_t *
    hydra_msg_new (void);

//  Destroy a hydra_msg instance
void
    hydra_msg_destroy (hydra_msg_t **self_p);

//  Receive a hydra_msg from the socket. Returns 0 if OK, -1 if
//  there was an error. Blocks if there is no message waiting.
int
    hydra_msg_recv (hydra_msg_t *self, zsock_t *input);

//  Send the hydra_msg to the output socket, does not destroy it
int
    hydra_msg_send (hydra_msg_t *self, zsock_t *output);
    
//  Print contents of message to stdout
void
    hydra_msg_print (hydra_msg_t *self);

//  Get/set the message routing id
zframe_t *
    hydra_msg_routing_id (hydra_msg_t *self);
void
    hydra_msg_set_routing_id (hydra_msg_t *self, zframe_t *routing_id);

//  Get the hydra_msg id and printable command
int
    hydra_msg_id (hydra_msg_t *self);
void
    hydra_msg_set_id (hydra_msg_t *self, int id);
const char *
    hydra_msg_command (hydra_msg_t *self);

//  Get/set the post_id field
const char *
    hydra_msg_post_id (hydra_msg_t *self);
void
    hydra_msg_set_post_id (hydra_msg_t *self, const char *value);

//  Get/set the tags field
const char *
    hydra_msg_tags (hydra_msg_t *self);
void
    hydra_msg_set_tags (hydra_msg_t *self, const char *value);

//  Get/set the tag field
const char *
    hydra_msg_tag (hydra_msg_t *self);
void
    hydra_msg_set_tag (hydra_msg_t *self, const char *value);

//  Get/set the reply_to field
const char *
    hydra_msg_reply_to (hydra_msg_t *self);
void
    hydra_msg_set_reply_to (hydra_msg_t *self, const char *value);

//  Get/set the previous field
const char *
    hydra_msg_previous (hydra_msg_t *self);
void
    hydra_msg_set_previous (hydra_msg_t *self, const char *value);

//  Get/set the timestamp field
uint64_t
    hydra_msg_timestamp (hydra_msg_t *self);
void
    hydra_msg_set_timestamp (hydra_msg_t *self, uint64_t timestamp);

//  Get/set the type field
const char *
    hydra_msg_type (hydra_msg_t *self);
void
    hydra_msg_set_type (hydra_msg_t *self, const char *value);

//  Get/set the content field
const char *
    hydra_msg_content (hydra_msg_t *self);
void
    hydra_msg_set_content (hydra_msg_t *self, const char *value);

//  Get/set the reason field
const char *
    hydra_msg_reason (hydra_msg_t *self);
void
    hydra_msg_set_reason (hydra_msg_t *self, const char *value);

//  Self test of this class
int
    hydra_msg_test (bool verbose);
//  @end

//  For backwards compatibility with old codecs
#define hydra_msg_dump      hydra_msg_print

#ifdef __cplusplus
}
#endif

#endif
