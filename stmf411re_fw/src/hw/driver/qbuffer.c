/*
 * qbuffer.c
 *
 *  Created on: 2022. 12. 21.
 *      Author: USER
 */


#include "qbuffer.h"

void qbufferInit(void)
{

}

bool qbufferCreate(qbuffer_t *p_node, uint8_t *p_buf, uint32_t length)
{
	/*Making buffer is index initializing */
	bool ret = true;

	p_node->in 		= 0;
	p_node->out	  = 0;
	p_node->len   = length;
	p_node->p_buf = p_buf;

	return ret;
}
/*
 * for this time, just write and read with out "in" function.
 * */
bool qbufferWrite(qbuffer_t *p_node, uint8_t *p_data, uint32_t length)
{
	bool ret = true;
	uint32_t next_in;

	for(int i=0; i<length; i++)
	{
		next_in = (p_node->in + 1) & p_node->len;

		if(next_in != p_node->out)
		{
			if(p_node->p_buf != NULL)
			{
				p_node->p_buf[p_node->in] = p_data[i];
			}
			/* index update even when data is NULL */
			p_node->in = next_in;
		}
		else
		{
			ret = false;
			break;
		}
	}

	return ret;
}

/* Read qbuffer and input to p_data. */
bool qbufferRead(qbuffer_t *p_node, uint8_t *p_data, uint32_t length)
{
	bool ret = true;
	for(int i = 0; i < length; i++)
	{
		if(p_node->p_buf != NULL)
		{
			p_data[i] = p_node->p_buf[p_node->out];
		}
		if(p_node->out != p_node->in)
		{
			/* index update */
			p_node->out = (p_node->out + 1) % p_node->len;
		}
		else /*when in idx = out idx*/
		{
			ret = false;
			break;
		}
	}
	return ret;
}

/*transmit struct pointer, receive current buffer's data number*/
uint32_t qbufferAvailable(qbuffer_t *p_node)
{
	uint32_t ret;

	ret = (p_node->in - p_node->out) % p_node->len;

	return ret;
}
void qbufferFlush(qbuffer_t *p_node)
{
	p_node->in  = 0;
	p_node->out = 0;
}















