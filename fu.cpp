#include "fu.h"

int Func_Unit_Stat[6][10];
int Reg_Stat[15];
int Cyc_Count = 1;				

void COMMAND_STR::Ins(char op_nam[], char reg_d[], char reg_src1[], char reg_src2[])
{
	if (!strcmp("LD", op_nam))
	{
		c->INS_NAME = LD;
		c->LATENCY = 1;
	}

	if (!strcmp("SD", op_nam))
	{
		c->INS_NAME = SD;
		c->LATENCY = 1;
	}

	if (!strcmp("MULD", op_nam))
	{
		c->INS_NAME = MULD;
		c->LATENCY = 8;
	}

	if (!strcmp("DIVD", op_nam))
	{
		c->INS_NAME = DIVD;
		c->LATENCY = 40;
	}

	if (!strcmp("ADDD", op_nam))
	{
		c->INS_NAME = ADDD;
		c->LATENCY = 2;
	}

	if (!strcmp("SUBD", op_nam))
	{
		c->INS_NAME = SUBD;
		c->LATENCY = 2;
	}

	if (!strcmp("OR", op_nam))
	{
		c->INS_NAME = OR;
		c->LATENCY = 1;
	}

	if (!strcmp("AND", op_nam))
	{
		c->INS_NAME = AND;
		c->LATENCY = 1;
	}

	if (!strcmp("R1", reg_d))
		c->DESTINATION = R1;

	if (!strcmp("R2", reg_d))
		c->DESTINATION = R2;

	if (!strcmp("R3", reg_d))
		c->DESTINATION = R3;

	if (!strcmp("R4", reg_d))
		c->DESTINATION = R4;

	if (!strcmp("R5", reg_d))
		c->DESTINATION = R5;

	if (!strcmp("R6", reg_d))
		c->DESTINATION = R6;

	if (!strcmp("R7", reg_d))
		c->DESTINATION = R7;

	if (!strcmp("R8", reg_d))
		c->DESTINATION = R8;

	if (!strcmp("R9", reg_d))
		c->DESTINATION = R9;

	if (!strcmp("R10", reg_d))
		c->DESTINATION = R10;

	if (!strcmp("R11", reg_d))
		c->DESTINATION = R11;

	if (!strcmp("R12", reg_d))
		c->DESTINATION = R12;

	if (!strcmp("R13", reg_d))
		c->DESTINATION = R13;

	if (!strcmp("R14", reg_d))
		c->DESTINATION = R14;


	if (!strcmp("R1", reg_src1))
		c->SOURCE1 = R1;

	if (!strcmp("R2", reg_src1))
		c->SOURCE1 = R2;

	if (!strcmp("R3", reg_src1))
		c->SOURCE1 = R3;

	if (!strcmp("R4", reg_src1))
		c->SOURCE1 = R4;

	if (!strcmp("R5", reg_src1))
		c->SOURCE1 = R5;

	if (!strcmp("R6", reg_src1))
		c->SOURCE1 = R6;

	if (!strcmp("R7", reg_src1))
		c->SOURCE1 = R7;

	if (!strcmp("R8", reg_src1))
		c->SOURCE1 = R8;

	if (!strcmp("R9", reg_src1))
		c->SOURCE1 = R9;

	if (!strcmp("R10", reg_src1))
		c->SOURCE1 = R10;

	if (!strcmp("R11", reg_src1))
		c->SOURCE1 = R11;

	if (!strcmp("R12", reg_src1))
		c->SOURCE1 = R12;

	if (!strcmp("R13", reg_src1))
		c->SOURCE1 = R13;

	if (!strcmp("R14", reg_src1))
		c->SOURCE1 = R14;

	if (!strcmp("SR1", reg_src2))
		c->SOURCE2 = R1;

	if (!strcmp("R2", reg_src2))
		c->SOURCE2 = R2;

	if (!strcmp("R3", reg_src2))
		c->SOURCE2 = R3;

	if (!strcmp("R4", reg_src2))
		c->SOURCE2 = R4;

	if (!strcmp("R5", reg_src2))
		c->SOURCE2 = R5;

	if (!strcmp("R6", reg_src2))
		c->SOURCE2 = R6;

	if (!strcmp("R7", reg_src2))
		c->SOURCE2 = R7;

	if (!strcmp("R8", reg_src2))
		c->SOURCE2 = R8;

	if (!strcmp("R9", reg_src2))
		c->SOURCE2 = R9;

	if (!strcmp("R10", reg_src2))
		c->SOURCE2 = R10;

	if (!strcmp("R11", reg_src2))
		c->SOURCE2 = R11;

	if (!strcmp("R12", reg_src2))
		c->SOURCE2 = R12;

	if (!strcmp("R13", reg_src2))
		c->SOURCE2 = R13;

	if (!strcmp("R14", reg_src2))
		c->SOURCE2 = R14;

	
	if (!strcmp("0", reg_src1))
		c->SOURCE1 = 0;

	if (!strcmp("0", reg_src2))
		c->SOURCE2 = 0;
}	

void COMMAND_STR::func_unit_val(functional_unit value)
{
	this->func_unit = value;
}

void COMMAND_STR::stage_val(int m, int value)
{
	this->command_stage[m] = value;
}

void COMMAND_STR::lock_val(int value)
{
	this->lock = value;
}

void COMMAND_STR::iss_val(int value)
{
	this->iss_cycle = value;
}

void COMMAND_STR::rd_val(int value)
{
	this->rd_cycle = value;
}

void COMMAND_STR::exe_val(int value)
{
	this->exe_cycle = value;
}

void COMMAND_STR::wb_val(int value)
{
	this->wb_cycle = value;
}

int COMMAND_STR::func_unit_get()
{
	return this->func_unit;
}
