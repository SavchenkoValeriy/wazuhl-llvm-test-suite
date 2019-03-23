
/****
    Copyright (C) 1996 McGill University.
    Copyright (C) 1996 McCAT System Group.
    Copyright (C) 1996 ACAPS Benchmark Administrator
                       benadmin@acaps.cs.mcgill.ca

    This program is free software; you can redistribute it and/or modify
    it provided this copyright notice is maintained.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
****/

#include <stdio.h>
#include "IOtest.h"

/* slow version */

static void initminBC(char_t *res)
{
  setac(0);
  *res=255;
}

static void initmaxBC(char_t *res)
{
  setac(0);
  *res=0;
}

static void initaddBC(char_t *res)
{
  setac(0);
  *res=0;
}

static void initmultBC(char_t *res)
{
  setac(0);
  *res=1;
}


static void stepminBC(char_t *res)
/* {{{  */

{
  register char_t t;
  unsigned long i;
  t=array(getac());
  *res=min(*res,t);
  i=getac()+4097;
  setac(i);
}

/* }}} */

static void stepmaxBC(char_t *res)
/* {{{  */
{
  register char_t t;
  unsigned long i;
  t=array(getac());
  *res=max(*res,t);
  i=getac()+4097 ;
  setac(i);
}
/* }}} */

static void stepaddBC(char_t *res)
/* {{{  */
{
  register char_t t;
  unsigned long i;
  t=array(getac());
  *res=add(*res,t);
  i=getac()+4097;
  setac(i);
}
/* }}} */

static void stepmultBC(char_t *res)
/* {{{  */

{
  register char_t t;
  unsigned long i;
  t=array(getac());
  *res=mult(*res,t);
  i=getac()+4097;
  setac(i);
}

/* }}} */


void testC()
{
  struct global_result res;

  initarray();

  loop((void (*)(void *))&initminBC,(void (*)(void *))&stepminBC,&(res.min));

  loop((void (*)(void *))&initmaxBC,(void (*)(void *))&stepmaxBC,&(res.max));

  loop((void (*)(void *))&initaddBC,(void (*)(void *))&stepaddBC,&(res.add));

  loop((void (*)(void *))&initmultBC,(void (*)(void *))&stepmultBC,&(res.mult));

  printf("C %d min %d max %d add %d mult \n",res.min,res.max,res.add,res.mult);

}
