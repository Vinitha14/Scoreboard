#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include "fu.h"

using namespace std;

static COMMAND_STR com[30];

void Begin_Stat()	//Initialising the Functional Unit Status and Register Status with 0
{
	for (int m=0; m<6; m++)
	{
		for (int n=0; n<10; n++)
		{
			Func_Unit_Stat[m][n] = 0;
		}
	}

	for (int k=0; k<15; k++)
		Reg_Stat[k] = 0;
}

int Reading_Instructions()	//Reading Instructions from the user and stops reading when "nil" is encountered
{
	int num = 0;
	char opname[10] = "", regd[5] = "", reg1[5] = "", reg2[5] = "";
	cout << "Enter instruction "<<num+1<<"(Enter nil to stop reading instructions):" << endl;
	cin >> opname;
	while (strcmp(opname, "nil") != 0)
	{
		cin >> regd >> reg1 >> reg2;
		com[++num].Ins(opname, regd, reg1, reg2);
		cout << "Enter instruction "<<num+1<<"(Enter nil to stop reading instructions):" << endl;
		cin >> opname;
	}
	return num;
}

void Change_Stat(int func_unit, COMMAND *c, int n)	//Function that alters the Functional Unit Status
{
	Func_Unit_Stat[func_unit][BUSY] = YES;
	Func_Unit_Stat[func_unit][OPN] = c->INS_NAME;
	Func_Unit_Stat[func_unit][FI] = c->DESTINATION;
	Func_Unit_Stat[func_unit][FJ] = c->SOURCE1;
	Func_Unit_Stat[func_unit][FK] = c->SOURCE2;
	
	if (Func_Unit_Stat[func_unit][FJ] > 10 || Func_Unit_Stat[func_unit][FJ] == 0)
		Func_Unit_Stat[func_unit][RJ] = YES;
	if (Func_Unit_Stat[func_unit][FK] > 10 || Func_Unit_Stat[func_unit][FK] == 0)
		Func_Unit_Stat[func_unit][RK] = YES;
	
	int ctrl = 1;
	for (int k=1; k<n; k++)
	{
		if (Func_Unit_Stat[com[k].func_unit_get()][BUSY] == 1)
		{
			if (com[k].c->DESTINATION == c->SOURCE1)
			{
				ctrl = 0;
				Func_Unit_Stat[func_unit][QJ] = com[k].func_unit_get();
				break;
			}
		}
	}
	if (ctrl)
		Func_Unit_Stat[func_unit][RJ] = YES;
	ctrl = 1;
	for (int k=1; k<n; k++)
	{
		if (Func_Unit_Stat[com[k].func_unit_get()][BUSY] == 1)
		{
			if (com[k].c->DESTINATION == c->SOURCE2)
			{
				ctrl = 0;
				Func_Unit_Stat[func_unit][QK] = com[k].func_unit_get();
				break;
			}
		}
	}
	if (ctrl)
		Func_Unit_Stat[func_unit][RK] = YES;

	Reg_Stat[c->DESTINATION] = func_unit;
}

void Issue_Stage(int n, int num)	
{	
//To check whether instruction can be issued or not 
//1.Inorder issue of instructions
//2.Functional Unit available
//3.No WAW hazards
	for (int k=1; k<=n; k++)
	{
		if ((com[k].c->DESTINATION == com[n].c->SOURCE1) || (com[k].c->DESTINATION == com[n].c->SOURCE2))
		{
			if (Cyc_Count - com[k].command_stage[WB] <= 0)
				return;
		}
	}

	int t = n-1;
	switch (com[n].c->INS_NAME)
	{
	case LD:
		if ((Func_Unit_Stat[INT][BUSY] == NO) && (com[n].command_stage[ISS] == 0))
		{
			if ((t > 0 && (com[t].command_stage[ISS] != 0) && (Cyc_Count > com[t].iss_cycle) && (Cyc_Count != com[t].wb_cycle)) || t == 0)
			{
				com[n].func_unit_val(INT);
				
				for (int k = 1; k <= num; k++)
				{
					if (com[k].lock != 0)
					{
						if (com[k].c->DESTINATION == com[n].c->DESTINATION)
							return;
					}
				}
				
				Change_Stat(INT, com[n].c, n);
				break;
			}
			else
				return;
		}
		else
			return;
	case SD:
		if ((Func_Unit_Stat[INT][BUSY] == NO) && (com[n].command_stage[ISS] == 0))
		{
			if ((t > 0 && (com[t].command_stage[ISS] != 0) && (Cyc_Count > com[t].iss_cycle) && (Cyc_Count != com[t].wb_cycle)) || t == 0)
			{
				com[n].func_unit_val(INT);
				
				for (int k = 1; k <= num; k++)
				{
					if (com[k].lock != 0)
					{
						if (com[k].c->DESTINATION == com[n].c->DESTINATION)
							return;
					}
				}
				
				Change_Stat(INT, com[n].c, n);
				break;
			}
			else
				return;
		}
		else
			return;
	case OR:
		if ((Func_Unit_Stat[INT][BUSY] == NO) && (com[n].command_stage[ISS] == 0))
		{
			if ((t > 0 && (com[t].command_stage[ISS] != 0) && (Cyc_Count > com[t].iss_cycle) && (Cyc_Count != com[t].wb_cycle)) || t == 0)
			{
				com[n].func_unit_val(INT);
				
				for (int k = 1; k <= num; k++)
				{
					if (com[k].lock != 0)
					{
						if (com[k].c->DESTINATION == com[n].c->DESTINATION)
							return;
					}
				}
				
				Change_Stat(INT, com[n].c, n);
			ofstream file;				//Integration of verilog code (OR)
                        file.open ("ortesttb.v");
                        file<<"module ortb();";
                        file<<"\nreg a1,b1;";
                        file<<"\nwire out;";
                        file<<"\ninitial begin";
                        file<<"\n$dumpfile(\"ortest.vcd\");";
                        file<<"\n$dumpvars(0,ortb);";
			file<<"\n$display(\"in1,in2,out\");";
                        file<<"\n$monitor(\"%b,%b,%b\",a1,b1,out);"; 
			file<<"\n#20 a1=0;b1=1;";
                        file<<"\n#20 $finish;";
                        file<<"\nend";
                        file<<"\ncmos_or n(.a(a1),.b(b1),.y(out));";
                        file<<"\nendmodule";
                        file.close();
			system("iverilog -o or or.v ortesttb.v");
			system("vvp or");
				break;
			}
			else
				return;
		}
		else
			return;
	case AND:
		if ((Func_Unit_Stat[INT][BUSY] == NO) && (com[n].command_stage[ISS] == 0))
		{
			if ((t > 0 && (com[t].command_stage[ISS] != 0) && (Cyc_Count > com[t].iss_cycle) && (Cyc_Count != com[t].wb_cycle)) || t == 0)
			{
				com[n].func_unit_val(INT);
				
				for (int k = 1; k <= num; k++)
				{
					if (com[k].lock != 0)
					{
						if (com[k].c->DESTINATION == com[n].c->DESTINATION)
							return;
					}
				}
				
				Change_Stat(INT, com[n].c, n);
			ofstream file;				//Integration of verilog code (AND)
                        file.open ("andtesttb.v");
                        file<<"module andtb();";
                        file<<"\nreg a1,b1;";
                        file<<"\nwire out;";
                        file<<"\ninitial begin";
                        file<<"\n$dumpfile(\"andtest.vcd\");";
                        file<<"\n$dumpvars(0,andtb);";
			file<<"\n$display(\"in1,in2,out\");";
                        file<<"\n$monitor(\"%b,%b,%b\",a1,b1,out);"; 
			file<<"\n#20 a1=0;b1=1;";
                        file<<"\n#20 $finish;";
                        file<<"\nend";
                        file<<"\ncmos_and n(.a(a1),.b(b1),.y(out));";
                        file<<"\nendmodule";
                        file.close();
			system("iverilog -o and and.v andtesttb.v");
			system("vvp and");
				break;
			}
			else
				return;
		}
		else
			return;
	case MULD:
		if ((Func_Unit_Stat[MUL1][BUSY] == NO) && (com[n].command_stage[ISS] == 0))
		{
			if ((t > 0 && (com[t].command_stage[ISS] != 0) && (Cyc_Count > com[t].iss_cycle) && (Cyc_Count != com[t].wb_cycle)) || t == 0)
			{
				com[n].func_unit_val(MUL1);
	
				for (int k = 1; k <= num; k++)
				{
					if (com[k].lock != 0)
					{
						if (com[k].c->DESTINATION == com[n].c->DESTINATION)
							return;
					}
				}

				Change_Stat(MUL1, com[n].c, n);
			ofstream file;				//Integration of verilog code (Wallace Multiplier)
                        file.open ("testfmtb.v");
                        file<<"module top;";
                        file<<"\nreg [15:0]a;";
                        file<<"\nreg [15:0]b;";
                        file<<"\nwire [32:0]s;";
                        file<<"\nWalMul mi(a,b,s);";
                        file<<"\ninitial";
			file<<"\nbegin";
                        file<<"\na=2;"; 
			file<<"\nb=4;";
                        file<<"\nend";
                        file<<"\ninitial";
                        file<<"\nbegin";
                        file<<"\n$monitor(\"a=%d, b=%d, sum=%d\",a,b,s);";
                        file<<"\n$dumpfile(\"wallace_mul.vcd\");";
                        file<<"\n$dumpvars(0,top);";
			file<<"\nend";
			file<<"\nendmodule";
                        file.close();
			system("iverilog -o wal wallace.v testfmtb.v");
			system("vvp wal");
				break;
			}
			else
				return;
		}
		else if ((Func_Unit_Stat[MUL2][BUSY] == NO) && (com[n].command_stage[ISS] == 0))
		{
			if ((t > 0 && (com[t].command_stage[ISS] != 0) && (Cyc_Count > com[t].iss_cycle) && (Cyc_Count != com[t].wb_cycle)) || t == 0)
			{
				com[n].func_unit_val(MUL2);
						
				for (int k = 1; k <= num; k++)
				{
					if (com[k].lock != 0)
					{
						if (com[k].c->DESTINATION == com[n].c->DESTINATION)
							return;
					}
				}
				
				Change_Stat(MUL2, com[n].c, n);
				break;
			}
			else
				return;
		}
		else
			return;
	case SUBD:
		if ((Func_Unit_Stat[ADD][BUSY] == NO) && (com[n].command_stage[ISS] == 0))
		{
			if (t > 0 && (com[t].command_stage[ISS] != 0) && (Cyc_Count > com[t].iss_cycle) && (Cyc_Count != com[t].wb_cycle) || t == 0)
			{
				com[n].func_unit_val(ADD);
				
				for (int k = 1; k <= num; k++)
				{
					if (com[k].lock != 0)
					{
						if (com[k].c->DESTINATION == com[n].c->DESTINATION)
							return;
					}
				}

				Change_Stat(ADD, com[n].c, n);
				break;
			}
			else
				return;
		}
		else
			return;
	case DIVD:
		if ((Func_Unit_Stat[DIV][BUSY] == NO) && (com[n].command_stage[ISS] == 0))
		{
			if ((t > 0 && (com[t].command_stage[ISS] != 0) && (Cyc_Count > com[t].iss_cycle) && (Cyc_Count != com[t].wb_cycle)) || t == 0)
			{
				com[n].func_unit_val(DIV);
				
				for (int k = 1; k <= num; k++)
				{
					if (com[k].lock != 0)
					{
						if (com[k].c->DESTINATION == com[n].c->DESTINATION)
							return;
					}
				}

				Change_Stat(DIV, com[n].c, n);
				break;
			}
			else
				return;
		}
		else
			return;
	case ADDD:
		if ((Func_Unit_Stat[ADD][BUSY] == NO) && (com[n].command_stage[ISS] == 0))
		{
			if ((t > 0 && (com[t].command_stage[ISS] != 0) && (Cyc_Count > com[t].iss_cycle) && (Cyc_Count != com[t].wb_cycle)) || t == 0)
			{
				com[n].func_unit_val(ADD);
				
				for (int k = 1; k <= num; k++)
				{
					if (com[k].lock != 0)
					{
						if (com[k].c->DESTINATION == com[n].c->DESTINATION)
							return;
					}
				}

				Change_Stat(ADD, com[n].c, n);
			ofstream file;				//Integration of verilog code (CLA)
                        file.open ("testtb.v");
                        file<<"module top;";
                        file<<"\nreg [15:0]a;";
                        file<<"\nreg [15:0]b;";
                        file<<"\nwire [16:0]s;";
                        file<<"\nAdd cla_0(a,b,s);";
                        file<<"\ninitial";
			file<<"\nbegin";
                        file<<"\na=8;"; 
			file<<"\nb=2;";
                        file<<"\nend";
                        file<<"\ninitial";
                        file<<"\nbegin";
                        file<<"\n$monitor(\"a=%d, b=%d, sum=%d\",a,b,s);";
                        file<<"\n$dumpfile(\"cla_adder1.vcd\");";
                        file<<"\n$dumpvars(0,top);";
			file<<"\nend";
			file<<"\nendmodule";
                        file.close();
			system("iverilog -o cla KGP.v testtb.v");
			system("vvp cla");
				break;
			}
			else
				return;
		}
		else
			return;
	}

	com[n].iss_val(Cyc_Count);
	com[n].stage_val(ISS, Cyc_Count);
}

void RdOp_Stage(int n)		
{
//To check whether source registers are available and instruction can read operands
//Ensures no RAW hazards
	int func_unit = com[n].func_unit_get();
	int tRJ = Func_Unit_Stat[func_unit][RJ];
	int tRK = Func_Unit_Stat[func_unit][RK];


	for (int k=1; k<=n; k++)
	{
		if (com[k].lock != 0)
		{
			if ((com[k].c->DESTINATION == com[n].c->SOURCE1) || (com[k].c->DESTINATION == com[n].c->SOURCE2) || tRJ == 0 || tRK == 0)
			{
				return;
			}
		}
		
		else
		{
			if ((com[k].c->DESTINATION == com[n].c->SOURCE1) || (com[k].c->DESTINATION == com[n].c->SOURCE2))
			{
				if (com[k].c->DESTINATION == com[n].c->SOURCE1)
				{
					Func_Unit_Stat[func_unit][QJ] = 0;
					Func_Unit_Stat[func_unit][RJ] = YES;
				}
				if (com[k].c->DESTINATION == com[n].c->SOURCE2)
				{
					Func_Unit_Stat[func_unit][QK] = 0;
					Func_Unit_Stat[func_unit][RK] = YES;
				}
			}
		}
		
		if ((com[k].c->DESTINATION == com[n].c->SOURCE1) || (com[k].c->DESTINATION == com[n].c->SOURCE2) || com[k].lock == 0)
		{
			if (Cyc_Count - com[k].command_stage[WB] <= 0)
				return;
		}
	}

	com[n].rd_val(Cyc_Count);
	com[n].stage_val(RD, Cyc_Count);
	com[n].lock_val(1);					
}

void Execution_Stage(int n)
{
//Instruction proceeds for execution in functional unit if operands are read
	com[n].exe_val(Cyc_Count);
	com[n].stage_val(EXE, Cyc_Count);
}

void WriteBack_Stage(int n)
{
//Checks whether instruction is ready for writeback or not
//Ensures no WAR hazard occurs
	for (int k=1; k<=n; k++)
	{
		if (com[k].lock != 0)
		{
			if ((com[k].c->SOURCE1 == com[n].c->DESTINATION) || (com[k].c->SOURCE2 == com[n].c->DESTINATION))
				return;
		}
	}
	
	com[n].wb_val(Cyc_Count);
	com[n].stage_val(WB, Cyc_Count);
}

void scoreboard(int num, int flag = 0)	//Implementation of Scoreboard for the Instructions
{
  int ctrl = 1;
	while (ctrl)
	{
		for (int m=1; m<=num; m++)
		{
			if (com[m].command_stage[ISS] == 0)
			{
				Issue_Stage(m, num);
			}
			else
			{
				if (com[m].command_stage[RD] == 0)
				{
					RdOp_Stage(m);
				}
				else
				{
					if (com[m].command_stage[EXE] == 0 && Cyc_Count - com[m].rd_cycle == com[m].c->LATENCY)
					{
						Execution_Stage(m);
					}
					else
					{
						if (com[m].command_stage[EXE] != 0  && com[m].command_stage[WB] == 0)
						{
							WriteBack_Stage(m);
						}
					}
				}
			}

			if (com[m].command_stage[WB] != 0 && com[m].lock == 1)
			{
				int fu_temp = com[m].func_unit_get();
				Func_Unit_Stat[fu_temp][BUSY] = NO;
				com[m].lock_val(0);
				com[m].func_unit_val(none);
			}
		}

		int d;
		for (d = 1; d <= num; d++)
		{
			if (com[d].command_stage[WB] == 0)
			{
				ctrl = 1;
				break;
			}
		}
		
		if (d > num)
			ctrl = 0;

		if (flag != 0)
		{
			if (Cyc_Count == flag)
				return;
		}
		Cyc_Count++;
	}
}

void display_status(int num)		//Display the final Instruction Status
{
	cout << '\n';
	cout << "Instruction Status："<< endl;
	cout << "****************************************************************************" << endl;
	cout << "Issue   ReadOp  Execute Writeback\n";
	for (int n=1; n<=num; n++)
	{
		for (int k=1; k<5; k++)
		{
			if (com[n].command_stage[k] == 0)
				cout << " " << '\t';
			else
				cout << com[n].command_stage[k] << '\t';
		}
		cout << '\n';
	}
	cout << "****************************************************************************" << endl << endl;
}

int main()
{
Begin_Stat();
int num= Reading_Instructions();
scoreboard(num);
display_status(num);
return 0;
}
