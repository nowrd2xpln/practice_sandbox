#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alu.h>

Alu *new_Alu(const char *const pOps)
{
	Alu *pObj = NULL;
	
	// Allocate memory
	pObj = (Alu *) malloc(sizeof(Alu));
	if (pObj == NULL) {
		return NULL;
	}

	strcpy(pObj->pOps, pOps);

	// Initialize interface for access to functions
	pObj->Delete = delete_Alu;
	pObj->Display = Alu_DisplayOps;
}

void delete_Alu(Alu *const pAluObj)
{
	free(pAluObj->pDerivedObj);
	free(pAluObj->pOps);
	free(pAluObj);
}

void Alu_DisplayOps(Alu *const pAluObj)
{
	printf("Supported Operations: %s\n", pAluObj->pOps);
}
