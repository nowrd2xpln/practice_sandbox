#ifndef _ALU_H
#define _ALU_H

typedef struct _alu Alu;

// Pointers to function
typedef void (*fptrDisplayOps)(Alu *obj);
typedef void (*fptrDelete)(Alu *obj);

typedef struct _alu {
	void *pDerivedObj;
	char *pOps;
	fptrDisplayOps Display;
	fptrDelete Delete;
}

Alu *new_Alu(const char* const pOps);	// Constructor
void delete_Alu(Alu *const pAluObj);	// Destructor
void Alu_DisplayOps(Alu *const pAluObj);

#define _ALU_H
#endif // !_ALU_H
