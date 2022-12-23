/*
 * qbuffer.h
 *
 *  Created on: 2022. 12. 21.
 *      Author: USER
 */

#ifndef SRC_COMMON_CORE_QBUFFER_H_
#define SRC_COMMON_CORE_QBUFFER_H_

/* common buffer of UART module*/

#ifdef __cplusplus
extern "C" {
#endif

#include "def.h"

typedef struct
{
	uint32_t in;
	uint32_t out;
	uint32_t len;

	uint8_t *p_buf;/*undecided buffer size for customer*/
}qbuffer_t;

void		 	qbufferInit(void);
bool			qbufferCreate(qbuffer_t *p_node, uint8_t *p_buf, uint32_t length);
bool 			qbufferWrite(qbuffer_t *p_node, uint8_t *p_data, uint32_t length);
bool 			qbufferRead(qbuffer_t *p_node, uint8_t *p_data, uint32_t length);
uint32_t  qbufferAvailable(qbuffer_t *p_node);/*transmit struct pointer, receive current buffer's data number*/
void 			qbufferFlush(qbuffer_t *p_node);


#ifdef __cplusplus
}
#endif
#endif /* SRC_COMMON_CORE_QBUFFER_H_ */
