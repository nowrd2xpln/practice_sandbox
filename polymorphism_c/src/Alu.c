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
	pObj->Display = Alu_Display;
}
