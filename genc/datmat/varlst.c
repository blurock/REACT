
extern CHAR *GetNameVarInfo(VarInfo *str)
{
     return(str->Name);
}

extern INT GetIDVarInfo(VarInfo *str)
{
     return(str->ID);
}

extern VarInfo *CreateVarInfo(VarInfo *newstruct,
                       INT id,
                       CHAR *name,
                       INT  Length,
                       CHAR *Info)
{
CHAR *oldInfo,*newInfo;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Length = Length;

     newstruct->Info = AllocArrayCHAR(newstruct->Length);
     if(Info != 0)
          {
          oldInfo = Info;
          newInfo = newstruct->Info;
          LOOPi(newstruct->Length)
               CopyFullCHAR(newInfo++, oldInfo++);
          }



     return(newstruct);
}


extern void CopyFullVarInfo(VarInfo *newstruct, VarInfo *oldstruct)
{
CHAR *oldInfo,*newInfo;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Length = oldstruct->Length;


     newstruct->Info = AllocArrayCHAR(newstruct->Length);
     if(oldstruct->Info != 0)
          {
          oldInfo = oldstruct->Info;
          newInfo = newstruct->Info;
          LOOPi(newstruct->Length)
               CopyFullCHAR(newInfo++, oldInfo++);
          }


}
extern void PrintVarInfo(VarInfo *eleptr)
{
CHAR *ptrInfo;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The length of the information string:");
     printf("%d\n",eleptr->Length);

     printf("The Information String:\n");
     if(eleptr->Info != 0)
          {
          ptrInfo = eleptr->Info;
          LOOPi(eleptr->Length)
               PrintCHAR(ptrInfo++);
          }


}
extern void FreeVarInfo(VarInfo *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Info);

}
extern void WriteBinVarInfo(VarInfo *eleptr, DbaseLinkedList *file)
{
CHAR *ptrInfo;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->Length),file);

     if(eleptr->Info != 0)
          {
          ptrInfo = eleptr->Info;
          LOOPi(eleptr->Length)
               WriteBinCHAR(ptrInfo++,file);
          }

}
extern INT ReadBinVarInfo(VarInfo *eleptr,DbaseLinkedList *file)
     {
CHAR *ptrInfo;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->Length),file);

          eleptr->Info = AllocArrayCHAR(eleptr->Length);
          ptrInfo = eleptr->Info;
          LOOPi(eleptr->Length)
               ReadBinCHAR(ptrInfo++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_VarInfo(XDR *stream, char **eleptrp)
{
     VarInfo *eleptr;
     eleptr = (VarInfo *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->Length));

     xdr_array(stream,(char **) &(eleptr->Info),
             (uint *) &(eleptr->Length),eleptr->Length,
               CHARSize,(xdrproc_t) xdr_CHAR);
}

extern void *AllocVarInfo()
{
     return((void *) AllocateVarInfo);
}

extern CHAR *GetNameVarName(VarName *str)
{
     return(str->Name);
}

extern INT GetIDVarName(VarName *str)
{
     return(str->ID);
}

extern VarName *CreateVarName(VarName *newstruct,
                       INT id,
                       CHAR *name,
                       INT  Length,
                       CHAR *Variable)
{
CHAR *oldVariable,*newVariable;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Length = Length;

     newstruct->Variable = AllocArrayCHAR(newstruct->Length);
     if(Variable != 0)
          {
          oldVariable = Variable;
          newVariable = newstruct->Variable;
          LOOPi(newstruct->Length)
               CopyFullCHAR(newVariable++, oldVariable++);
          }



     return(newstruct);
}


extern void CopyFullVarName(VarName *newstruct, VarName *oldstruct)
{
CHAR *oldVariable,*newVariable;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Length = oldstruct->Length;


     newstruct->Variable = AllocArrayCHAR(newstruct->Length);
     if(oldstruct->Variable != 0)
          {
          oldVariable = oldstruct->Variable;
          newVariable = newstruct->Variable;
          LOOPi(newstruct->Length)
               CopyFullCHAR(newVariable++, oldVariable++);
          }


}
extern void PrintVarName(VarName *eleptr)
{
CHAR *ptrVariable;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The length of the name string:");
     printf("%d\n",eleptr->Length);

     printf("           The Name :\n");
     if(eleptr->Variable != 0)
          {
          ptrVariable = eleptr->Variable;
          LOOPi(eleptr->Length)
               PrintCHAR(ptrVariable++);
          }


}
extern void FreeVarName(VarName *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Variable);

}
extern void WriteBinVarName(VarName *eleptr, DbaseLinkedList *file)
{
CHAR *ptrVariable;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->Length),file);

     if(eleptr->Variable != 0)
          {
          ptrVariable = eleptr->Variable;
          LOOPi(eleptr->Length)
               WriteBinCHAR(ptrVariable++,file);
          }

}
extern INT ReadBinVarName(VarName *eleptr,DbaseLinkedList *file)
     {
CHAR *ptrVariable;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->Length),file);

          eleptr->Variable = AllocArrayCHAR(eleptr->Length);
          ptrVariable = eleptr->Variable;
          LOOPi(eleptr->Length)
               ReadBinCHAR(ptrVariable++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_VarName(XDR *stream, char **eleptrp)
{
     VarName *eleptr;
     eleptr = (VarName *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->Length));

     xdr_array(stream,(char **) &(eleptr->Variable),
             (uint *) &(eleptr->Length),eleptr->Length,
               CHARSize,(xdrproc_t) xdr_CHAR);
}

extern void *AllocVarName()
{
     return((void *) AllocateVarName);
}

extern CHAR *GetNameVarNames(VarNames *str)
{
     return(str->Name);
}

extern INT GetIDVarNames(VarNames *str)
{
     return(str->ID);
}

extern VarNames *CreateVarNames(VarNames *newstruct,
                         INT id,
                         CHAR *name,
                         VarName *Variable,
                         INT  Number,
                         VarInfo *Information)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Number = Number;
     if(Variable != 0)
          {
          newstruct->Variable = AllocateVarName;
          CopyFullVarName(newstruct->Variable, Variable);
          }
     else
          newstruct->Variable = 0;
     if(Information != 0)
          {
          newstruct->Information = AllocateVarInfo;
          CopyFullVarInfo(newstruct->Information, Information);
          }
     else
          newstruct->Information = 0;



     return(newstruct);
}


extern void CopyFullVarNames(VarNames *newstruct, VarNames *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Number = oldstruct->Number;

     if(oldstruct->Variable != 0)
          {
          newstruct->Variable = AllocateVarName;
          CopyFullVarName(newstruct->Variable, oldstruct->Variable);
          }
     else
          newstruct->Variable = 0;
     if(oldstruct->Information != 0)
          {
          newstruct->Information = AllocateVarInfo;
          CopyFullVarInfo(newstruct->Information, oldstruct->Information);
          }
     else
          newstruct->Information = 0;


}
extern void PrintVarNames(VarNames *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf(" The Variable Number:");
     printf("%d\n",eleptr->Number);

     printf("   The Variable Name:\n");
     PrintVarName(eleptr->Variable);

     printf("The Corresponding Information:\n");
     PrintVarInfo(eleptr->Information);

}
extern void FreeVarNames(VarNames *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeVarName(eleptr->Variable);
     Free(eleptr->Variable);

     FreeVarInfo(eleptr->Information);
     Free(eleptr->Information);

}
extern void WriteBinVarNames(VarNames *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->Number),file);

     WriteBinVarName(eleptr->Variable,file);

     WriteBinVarInfo(eleptr->Information,file);

}
extern INT ReadBinVarNames(VarNames *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->Number),file);

     eleptr->Variable = AllocateVarName;
     if(ReadBinVarName(eleptr->Variable,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Variable);
           eleptr->Variable = 0;
           }

     eleptr->Information = AllocateVarInfo;
     if(ReadBinVarInfo(eleptr->Information,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Information);
           eleptr->Information = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_VarNames(XDR *stream, char **eleptrp)
{
     VarNames *eleptr;
     eleptr = (VarNames *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->Number));

     xdr_pointer(stream,
          (char **) &(eleptr->Variable),
          VarNameSize,
                 (xdrproc_t) xdr_VarName);
     xdr_pointer(stream,
          (char **) &(eleptr->Information),
          VarInfoSize,
                 (xdrproc_t) xdr_VarInfo);
}

extern void *AllocVarNames()
{
     return((void *) AllocateVarNames);
}

extern CHAR *GetNameSystemVariableList(SystemVariableList *str)
{
     return(str->Name);
}

extern INT GetIDSystemVariableList(SystemVariableList *str)
{
     return(str->ID);
}

extern SystemVariableList *CreateSystemVariableList(SystemVariableList *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  NumberOfVariables,
                                             VarNames *Variables)
{
VarNames *oldVariables,*newVariables;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfVariables = NumberOfVariables;

     newstruct->Variables = AllocArrayVarNames(newstruct->NumberOfVariables);
     if(Variables != 0)
          {
          oldVariables = Variables;
          newVariables = newstruct->Variables;
          LOOPi(newstruct->NumberOfVariables)
               CopyFullVarNames(newVariables++, oldVariables++);
          }



     return(newstruct);
}


extern void CopyFullSystemVariableList(SystemVariableList *newstruct, SystemVariableList *oldstruct)
{
VarNames *oldVariables,*newVariables;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfVariables = oldstruct->NumberOfVariables;


     newstruct->Variables = AllocArrayVarNames(newstruct->NumberOfVariables);
     if(oldstruct->Variables != 0)
          {
          oldVariables = oldstruct->Variables;
          newVariables = newstruct->Variables;
          LOOPi(newstruct->NumberOfVariables)
               CopyFullVarNames(newVariables++, oldVariables++);
          }


}
extern void PrintSystemVariableList(SystemVariableList *eleptr)
{
VarNames *ptrVariables;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number of Variables:");
     printf("%d\n",eleptr->NumberOfVariables);

     printf("The variable information:\n");
     if(eleptr->Variables != 0)
          {
          ptrVariables = eleptr->Variables;
          LOOPi(eleptr->NumberOfVariables)
               PrintVarNames(ptrVariables++);
          }


}
extern void FreeSystemVariableList(SystemVariableList *eleptr)
{
VarNames *ptrVariables;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrVariables = eleptr->Variables;
     LOOPi(eleptr->NumberOfVariables)
          FreeVarNames(ptrVariables++);
     Free(eleptr->Variables);

}
extern void WriteBinSystemVariableList(SystemVariableList *eleptr, DbaseLinkedList *file)
{
VarNames *ptrVariables;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfVariables),file);

     if(eleptr->Variables != 0)
          {
          ptrVariables = eleptr->Variables;
          LOOPi(eleptr->NumberOfVariables)
               WriteBinVarNames(ptrVariables++,file);
          }

}
extern INT ReadBinSystemVariableList(SystemVariableList *eleptr,DbaseLinkedList *file)
     {
VarNames *ptrVariables;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfVariables),file);

          eleptr->Variables = AllocArrayVarNames(eleptr->NumberOfVariables);
          ptrVariables = eleptr->Variables;
          LOOPi(eleptr->NumberOfVariables)
               ReadBinVarNames(ptrVariables++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SystemVariableList(XDR *stream, char **eleptrp)
{
     SystemVariableList *eleptr;
     eleptr = (SystemVariableList *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfVariables));

     xdr_array(stream,(char **) &(eleptr->Variables),
             (uint *) &(eleptr->NumberOfVariables),eleptr->NumberOfVariables,
               VarNamesSize,(xdrproc_t) xdr_VarNames);
}

extern void *AllocSystemVariableList()
{
     return((void *) AllocateSystemVariableList);
}

extern CHAR *GetNameSystemVariablePair(SystemVariablePair *str)
{
     return(str->Name);
}

extern INT GetIDSystemVariablePair(SystemVariablePair *str)
{
     return(str->ID);
}

extern SystemVariablePair *CreateSystemVariablePair(SystemVariablePair *newstruct,
                                             INT id,
                                             CHAR *name,
                                             SystemVariableList *Descriptors,
                                             SystemVariableList *Goals)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(Descriptors != 0)
          {
          newstruct->Descriptors = AllocateSystemVariableList;
          CopyFullSystemVariableList(newstruct->Descriptors, Descriptors);
          }
     else
          newstruct->Descriptors = 0;
     if(Goals != 0)
          {
          newstruct->Goals = AllocateSystemVariableList;
          CopyFullSystemVariableList(newstruct->Goals, Goals);
          }
     else
          newstruct->Goals = 0;



     return(newstruct);
}


extern void CopyFullSystemVariablePair(SystemVariablePair *newstruct, SystemVariablePair *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->Descriptors != 0)
          {
          newstruct->Descriptors = AllocateSystemVariableList;
          CopyFullSystemVariableList(newstruct->Descriptors, oldstruct->Descriptors);
          }
     else
          newstruct->Descriptors = 0;
     if(oldstruct->Goals != 0)
          {
          newstruct->Goals = AllocateSystemVariableList;
          CopyFullSystemVariableList(newstruct->Goals, oldstruct->Goals);
          }
     else
          newstruct->Goals = 0;


}
extern void PrintSystemVariablePair(SystemVariablePair *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The Descriptor Variables:\n");
     PrintSystemVariableList(eleptr->Descriptors);

     printf("  The Goal Variables:\n");
     PrintSystemVariableList(eleptr->Goals);

}
extern void FreeSystemVariablePair(SystemVariablePair *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeSystemVariableList(eleptr->Descriptors);
     Free(eleptr->Descriptors);

     FreeSystemVariableList(eleptr->Goals);
     Free(eleptr->Goals);

}
extern void WriteBinSystemVariablePair(SystemVariablePair *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinSystemVariableList(eleptr->Descriptors,file);

     WriteBinSystemVariableList(eleptr->Goals,file);

}
extern INT ReadBinSystemVariablePair(SystemVariablePair *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->Descriptors = AllocateSystemVariableList;
     if(ReadBinSystemVariableList(eleptr->Descriptors,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Descriptors);
           eleptr->Descriptors = 0;
           }

     eleptr->Goals = AllocateSystemVariableList;
     if(ReadBinSystemVariableList(eleptr->Goals,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Goals);
           eleptr->Goals = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_SystemVariablePair(XDR *stream, char **eleptrp)
{
     SystemVariablePair *eleptr;
     eleptr = (SystemVariablePair *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->Descriptors),
          SystemVariableListSize,
                 (xdrproc_t) xdr_SystemVariableList);
     xdr_pointer(stream,
          (char **) &(eleptr->Goals),
          SystemVariableListSize,
                 (xdrproc_t) xdr_SystemVariableList);
}

extern void *AllocSystemVariablePair()
{
     return((void *) AllocateSystemVariablePair);
}
