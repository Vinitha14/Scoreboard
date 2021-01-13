#include<string.h>
#include<stdio.h>

enum sb_stage {ISS=1, RD, EXE, WB};
enum reg {R1=1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14};
enum operation {LD=1,SD,MULD,DIVD,ADDD,SUBD,OR,AND};
enum functional_unit {none, INT=1, MUL1, MUL2, ADD, DIV};
enum fields {BUSY=1, OPN, FI, FJ, FK, QJ, QK, RJ, RK};

#define YES 1
#define NO 0

struct COMMAND
{
	int INS_NAME;
	int LATENCY;
	int DESTINATION;
	int SOURCE1;
	int SOURCE2;
};

extern int Func_Unit_Stat[6][10];
extern int Reg_Stat[15];
extern int Cyc_Count;

class COMMAND_STR
{
public:
	COMMAND *c;

	int command_stage[5];
	int func_unit;
	int lock;
	int iss_cycle;
	int rd_cycle;
	int exe_cycle;
	int wb_cycle;

	COMMAND_STR() //Constructor
	{
		this->c= new COMMAND;
		this->iss_cycle = 0;
		this->rd_cycle = 0;
		this->exe_cycle = 0;
		this->wb_cycle = 0;
		this->func_unit = 0;
		this->lock = 0;
		this->command_stage[0] = 0;
		this->command_stage[1] = 0;
		this->command_stage[2] = 0;
		this->command_stage[3] = 0;
		this->command_stage[4] = 0;
	}

	void stage_val(int m, int value);
	void func_unit_val(functional_unit value);
	void lock_val(int value);
	void iss_val(int value);
	void rd_val(int value);
	void exe_val(int value);
	void wb_val(int value);
	int func_unit_get();
	void Ins(char op_nam[], char reg_d[], char reg_src1[], char reg_src2[]);

	~COMMAND_STR() //Destructor
	{
		delete c;
	}
};
