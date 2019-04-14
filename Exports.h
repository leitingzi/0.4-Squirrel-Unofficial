#pragma once
#include "main.h"
#include "SQModule.h"

void InitSQAPI();
void InitSQSTDAPI();

typedef HSQAPI * ( *Sq_GetSquirrelAPI ) ( void );
typedef HSQUIRRELVM * (*Sq_GetSquirrelVM) (void);
typedef HSQSTDAPI * (*Sq_GetSquirrelStdAPI) (void);

HSQAPI * pfGetSquirrelAPI();
HSQUIRRELVM * pfGetSquirrelVM();
HSQSTDAPI * pfGetSquirrelStdAPI();

struct SquirrelExports
{
	unsigned int		uStructSize;
	Sq_GetSquirrelAPI	GetSquirrelAPI;
	Sq_GetSquirrelVM	GetSquirrelVM;
	Sq_GetSquirrelStdAPI GetSquirrelStdAPI;
};
