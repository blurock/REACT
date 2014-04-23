
extern CHAR *GetNameBaseArgumentType(BaseArgumentType *str)
{
     return(str->Name);
}

extern INT GetIDBaseArgumentType(BaseArgumentType *str)
{
     return(str->ID);
}

extern BaseArgumentType *CreateBaseArgumentType(BaseArgumentType *newstruct,
                                         INT id,
                                         CHAR *name,
                                         INT  Type,
                                         INT  Integer_Value,
                                         FLOAT  Float_Value,
                                         STRING *String_Value)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Type = Type;
     newstruct->Integer_Value = Integer_Value;
     newstruct->Float_Value = Float_Value;
     if(String_Value != 0)
          {
          newstruct->String_Value = AllocateSTRING;
          CopyFullSTRING(newstruct->String_Value, String_Value);
          }
     else
          newstruct->String_Value = 0;



     return(newstruct);
}


extern void CopyFullBaseArgumentType(BaseArgumentType *newstruct, BaseArgumentType *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Type = oldstruct->Type;
     newstruct->Integer_Value = oldstruct->Integer_Value;
     newstruct->Float_Value = oldstruct->Float_Value;

     if(oldstruct->String_Value != 0)
          {
          newstruct->String_Value = AllocateSTRING;
          CopyFullSTRING(newstruct->String_Value, oldstruct->String_Value);
          }
     else
          newstruct->String_Value = 0;


}
extern void PrintBaseArgumentType(BaseArgumentType *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("  The type of Vector:");
     printf("%d\n",eleptr->Type);
     printf("      An Integer    :");
     printf("%d\n",eleptr->Integer_Value);
     printf(" A Floating Point Number:");
     printf("%f\n",eleptr->Float_Value);

     printf("   A String Variable:\n");
     PrintSTRING(eleptr->String_Value);

}
extern void FreeBaseArgumentType(BaseArgumentType *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeSTRING(eleptr->String_Value);

}
extern void WriteBinBaseArgumentType(BaseArgumentType *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->Type),file);
     WriteBinINT(&(eleptr->Integer_Value),file);
     WriteBinFLOAT(&(eleptr->Float_Value),file);

     WriteBinSTRING(eleptr->String_Value,file);

}
extern INT ReadBinBaseArgumentType(BaseArgumentType *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->Type),file);
     ReadBinINT(&(eleptr->Integer_Value),file);
     ReadBinFLOAT(&(eleptr->Float_Value),file);

     eleptr->String_Value = AllocateSTRING;
     if(ReadBinSTRING(eleptr->String_Value,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->String_Value);
           eleptr->String_Value = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_BaseArgumentType(XDR *stream, char **eleptrp)
{
     BaseArgumentType *eleptr;
     eleptr = (BaseArgumentType *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->Type));
     xdr_INT(stream,(char **) &(eleptr->Integer_Value));
     xdr_FLOAT(stream,(char **) &(eleptr->Float_Value));

     xdr_pointer(stream,
          (char **) &(eleptr->String_Value),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
}

extern void *AllocBaseArgumentType()
{
     return((void *) AllocateBaseArgumentType);
}

extern CHAR *GetNameBaseArgumentTypeArray(BaseArgumentTypeArray *str)
{
     return(str->Name);
}

extern INT GetIDBaseArgumentTypeArray(BaseArgumentTypeArray *str)
{
     return(str->ID);
}

extern BaseArgumentTypeArray *CreateBaseArgumentTypeArray(BaseArgumentTypeArray *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   INT  NumberOfValues,
                                                   BaseArgumentType *Set)
{
BaseArgumentType *oldSet,*newSet;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfValues = NumberOfValues;

     newstruct->Set = AllocArrayBaseArgumentType(newstruct->NumberOfValues);
     if(Set != 0)
          {
          oldSet = Set;
          newSet = newstruct->Set;
          LOOPi(newstruct->NumberOfValues)
               CopyFullBaseArgumentType(newSet++, oldSet++);
          }



     return(newstruct);
}


extern void CopyFullBaseArgumentTypeArray(BaseArgumentTypeArray *newstruct, BaseArgumentTypeArray *oldstruct)
{
BaseArgumentType *oldSet,*newSet;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfValues = oldstruct->NumberOfValues;


     newstruct->Set = AllocArrayBaseArgumentType(newstruct->NumberOfValues);
     if(oldstruct->Set != 0)
          {
          oldSet = oldstruct->Set;
          newSet = newstruct->Set;
          LOOPi(newstruct->NumberOfValues)
               CopyFullBaseArgumentType(newSet++, oldSet++);
          }


}
extern void PrintBaseArgumentTypeArray(BaseArgumentTypeArray *eleptr)
{
BaseArgumentType *ptrSet;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number of Values:");
     printf("%d\n",eleptr->NumberOfValues);

     printf("   The Set of Values:\n");
     if(eleptr->Set != 0)
          {
          ptrSet = eleptr->Set;
          LOOPi(eleptr->NumberOfValues)
               PrintBaseArgumentType(ptrSet++);
          }


}
extern void FreeBaseArgumentTypeArray(BaseArgumentTypeArray *eleptr)
{
BaseArgumentType *ptrSet;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrSet = eleptr->Set;
     LOOPi(eleptr->NumberOfValues)
          FreeBaseArgumentType(ptrSet++);
     Free(eleptr->Set);

}
extern void WriteBinBaseArgumentTypeArray(BaseArgumentTypeArray *eleptr, DbaseLinkedList *file)
{
BaseArgumentType *ptrSet;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfValues),file);

     if(eleptr->Set != 0)
          {
          ptrSet = eleptr->Set;
          LOOPi(eleptr->NumberOfValues)
               WriteBinBaseArgumentType(ptrSet++,file);
          }

}
extern INT ReadBinBaseArgumentTypeArray(BaseArgumentTypeArray *eleptr,DbaseLinkedList *file)
     {
BaseArgumentType *ptrSet;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfValues),file);

          eleptr->Set = AllocArrayBaseArgumentType(eleptr->NumberOfValues);
          ptrSet = eleptr->Set;
          LOOPi(eleptr->NumberOfValues)
               ReadBinBaseArgumentType(ptrSet++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_BaseArgumentTypeArray(XDR *stream, char **eleptrp)
{
     BaseArgumentTypeArray *eleptr;
     eleptr = (BaseArgumentTypeArray *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfValues));

     xdr_array(stream,(char **) &(eleptr->Set),
             (uint *) &(eleptr->NumberOfValues),eleptr->NumberOfValues,
               BaseArgumentTypeSize,(xdrproc_t) xdr_BaseArgumentType);
}

extern void *AllocBaseArgumentTypeArray()
{
     return((void *) AllocateBaseArgumentTypeArray);
}

extern CHAR *GetNameVariableName(VariableName *str)
{
     return(str->Name);
}

extern INT GetIDVariableName(VariableName *str)
{
     return(str->ID);
}

extern VariableName *CreateVariableName(VariableName *newstruct,
                                 INT id,
                                 CHAR *name)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;



     return(newstruct);
}


extern void CopyFullVariableName(VariableName *newstruct, VariableName *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);



}
extern void PrintVariableName(VariableName *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

}
extern void FreeVariableName(VariableName *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinVariableName(VariableName *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

}
extern INT ReadBinVariableName(VariableName *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     return(STRUCTURE_READ);
     }
extern void xdr_VariableName(XDR *stream, char **eleptrp)
{
     VariableName *eleptr;
     eleptr = (VariableName *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

}

extern void *AllocVariableName()
{
     return((void *) AllocateVariableName);
}

extern CHAR *GetNameFunctionInfo(FunctionInfo *str)
{
     return(str->Name);
}

extern INT GetIDFunctionInfo(FunctionInfo *str)
{
     return(str->ID);
}

extern FunctionInfo *CreateFunctionInfo(FunctionInfo *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  (*FunctCall)())
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->FunctCall = FunctCall;



     return(newstruct);
}


extern void CopyFullFunctionInfo(FunctionInfo *newstruct, FunctionInfo *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->FunctCall = oldstruct->FunctCall;



}
extern void PrintFunctionInfo(FunctionInfo *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

}
extern void FreeFunctionInfo(FunctionInfo *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinFunctionInfo(FunctionInfo *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

}
extern INT ReadBinFunctionInfo(FunctionInfo *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     return(STRUCTURE_READ);
     }
extern void xdr_FunctionInfo(XDR *stream, char **eleptrp)
{
     FunctionInfo *eleptr;
     eleptr = (FunctionInfo *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

}

extern void *AllocFunctionInfo()
{
     return((void *) AllocateFunctionInfo);
}

extern CHAR *GetNameTitleInfo(TitleInfo *str)
{
     return(str->Name);
}

extern INT GetIDTitleInfo(TitleInfo *str)
{
     return(str->ID);
}

extern TitleInfo *CreateTitleInfo(TitleInfo *newstruct,
                           INT id,
                           CHAR *name)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;



     return(newstruct);
}


extern void CopyFullTitleInfo(TitleInfo *newstruct, TitleInfo *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);



}
extern void PrintTitleInfo(TitleInfo *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

}
extern void FreeTitleInfo(TitleInfo *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinTitleInfo(TitleInfo *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

}
extern INT ReadBinTitleInfo(TitleInfo *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     return(STRUCTURE_READ);
     }
extern void xdr_TitleInfo(XDR *stream, char **eleptrp)
{
     TitleInfo *eleptr;
     eleptr = (TitleInfo *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

}

extern void *AllocTitleInfo()
{
     return((void *) AllocateTitleInfo);
}

extern CHAR *GetNameVariableNameSet(VariableNameSet *str)
{
     return(str->Name);
}

extern INT GetIDVariableNameSet(VariableNameSet *str)
{
     return(str->ID);
}

extern VariableNameSet *CreateVariableNameSet(VariableNameSet *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NumberOfNames,
                                       VariableName *Names)
{
VariableName *oldNames,*newNames;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfNames = NumberOfNames;

     newstruct->Names = AllocArrayVariableName(newstruct->NumberOfNames);
     if(Names != 0)
          {
          oldNames = Names;
          newNames = newstruct->Names;
          LOOPi(newstruct->NumberOfNames)
               CopyFullVariableName(newNames++, oldNames++);
          }



     return(newstruct);
}


extern void CopyFullVariableNameSet(VariableNameSet *newstruct, VariableNameSet *oldstruct)
{
VariableName *oldNames,*newNames;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfNames = oldstruct->NumberOfNames;


     newstruct->Names = AllocArrayVariableName(newstruct->NumberOfNames);
     if(oldstruct->Names != 0)
          {
          oldNames = oldstruct->Names;
          newNames = newstruct->Names;
          LOOPi(newstruct->NumberOfNames)
               CopyFullVariableName(newNames++, oldNames++);
          }


}
extern void PrintVariableNameSet(VariableNameSet *eleptr)
{
VariableName *ptrNames;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("  The Number of Names:");
     printf("%d\n",eleptr->NumberOfNames);

     printf("    The set of names:\n");
     if(eleptr->Names != 0)
          {
          ptrNames = eleptr->Names;
          LOOPi(eleptr->NumberOfNames)
               PrintVariableName(ptrNames++);
          }


}
extern void FreeVariableNameSet(VariableNameSet *eleptr)
{
VariableName *ptrNames;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrNames = eleptr->Names;
     LOOPi(eleptr->NumberOfNames)
          FreeVariableName(ptrNames++);
     Free(eleptr->Names);

}
extern void WriteBinVariableNameSet(VariableNameSet *eleptr, DbaseLinkedList *file)
{
VariableName *ptrNames;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfNames),file);

     if(eleptr->Names != 0)
          {
          ptrNames = eleptr->Names;
          LOOPi(eleptr->NumberOfNames)
               WriteBinVariableName(ptrNames++,file);
          }

}
extern INT ReadBinVariableNameSet(VariableNameSet *eleptr,DbaseLinkedList *file)
     {
VariableName *ptrNames;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfNames),file);

          eleptr->Names = AllocArrayVariableName(eleptr->NumberOfNames);
          ptrNames = eleptr->Names;
          LOOPi(eleptr->NumberOfNames)
               ReadBinVariableName(ptrNames++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_VariableNameSet(XDR *stream, char **eleptrp)
{
     VariableNameSet *eleptr;
     eleptr = (VariableNameSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfNames));

     xdr_array(stream,(char **) &(eleptr->Names),
             (uint *) &(eleptr->NumberOfNames),eleptr->NumberOfNames,
               VariableNameSize,(xdrproc_t) xdr_VariableName);
}

extern void *AllocVariableNameSet()
{
     return((void *) AllocateVariableNameSet);
}

extern CHAR *GetNameTitleInfoSet(TitleInfoSet *str)
{
     return(str->Name);
}

extern INT GetIDTitleInfoSet(TitleInfoSet *str)
{
     return(str->ID);
}

extern TitleInfoSet *CreateTitleInfoSet(TitleInfoSet *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  NumberOfTitles,
                                 TitleInfo *Titles)
{
TitleInfo *oldTitles,*newTitles;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfTitles = NumberOfTitles;

     newstruct->Titles = AllocArrayTitleInfo(newstruct->NumberOfTitles);
     if(Titles != 0)
          {
          oldTitles = Titles;
          newTitles = newstruct->Titles;
          LOOPi(newstruct->NumberOfTitles)
               CopyFullTitleInfo(newTitles++, oldTitles++);
          }



     return(newstruct);
}


extern void CopyFullTitleInfoSet(TitleInfoSet *newstruct, TitleInfoSet *oldstruct)
{
TitleInfo *oldTitles,*newTitles;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfTitles = oldstruct->NumberOfTitles;


     newstruct->Titles = AllocArrayTitleInfo(newstruct->NumberOfTitles);
     if(oldstruct->Titles != 0)
          {
          oldTitles = oldstruct->Titles;
          newTitles = newstruct->Titles;
          LOOPi(newstruct->NumberOfTitles)
               CopyFullTitleInfo(newTitles++, oldTitles++);
          }


}
extern void PrintTitleInfoSet(TitleInfoSet *eleptr)
{
TitleInfo *ptrTitles;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("  The Number of Titles:");
     printf("%d\n",eleptr->NumberOfTitles);

     printf("   The set of titles:\n");
     if(eleptr->Titles != 0)
          {
          ptrTitles = eleptr->Titles;
          LOOPi(eleptr->NumberOfTitles)
               PrintTitleInfo(ptrTitles++);
          }


}
extern void FreeTitleInfoSet(TitleInfoSet *eleptr)
{
TitleInfo *ptrTitles;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrTitles = eleptr->Titles;
     LOOPi(eleptr->NumberOfTitles)
          FreeTitleInfo(ptrTitles++);
     Free(eleptr->Titles);

}
extern void WriteBinTitleInfoSet(TitleInfoSet *eleptr, DbaseLinkedList *file)
{
TitleInfo *ptrTitles;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfTitles),file);

     if(eleptr->Titles != 0)
          {
          ptrTitles = eleptr->Titles;
          LOOPi(eleptr->NumberOfTitles)
               WriteBinTitleInfo(ptrTitles++,file);
          }

}
extern INT ReadBinTitleInfoSet(TitleInfoSet *eleptr,DbaseLinkedList *file)
     {
TitleInfo *ptrTitles;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfTitles),file);

          eleptr->Titles = AllocArrayTitleInfo(eleptr->NumberOfTitles);
          ptrTitles = eleptr->Titles;
          LOOPi(eleptr->NumberOfTitles)
               ReadBinTitleInfo(ptrTitles++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_TitleInfoSet(XDR *stream, char **eleptrp)
{
     TitleInfoSet *eleptr;
     eleptr = (TitleInfoSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfTitles));

     xdr_array(stream,(char **) &(eleptr->Titles),
             (uint *) &(eleptr->NumberOfTitles),eleptr->NumberOfTitles,
               TitleInfoSize,(xdrproc_t) xdr_TitleInfo);
}

extern void *AllocTitleInfoSet()
{
     return((void *) AllocateTitleInfoSet);
}

extern CHAR *GetNameKeyWordInfo(KeyWordInfo *str)
{
     return(str->Name);
}

extern INT GetIDKeyWordInfo(KeyWordInfo *str)
{
     return(str->ID);
}

extern KeyWordInfo *CreateKeyWordInfo(KeyWordInfo *newstruct,
                               INT id,
                               CHAR *name,
                               VariableName *KeyFlagName)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(KeyFlagName != 0)
          {
          newstruct->KeyFlagName = AllocateVariableName;
          CopyFullVariableName(newstruct->KeyFlagName, KeyFlagName);
          }
     else
          newstruct->KeyFlagName = 0;



     return(newstruct);
}


extern void CopyFullKeyWordInfo(KeyWordInfo *newstruct, KeyWordInfo *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->KeyFlagName != 0)
          {
          newstruct->KeyFlagName = AllocateVariableName;
          CopyFullVariableName(newstruct->KeyFlagName, oldstruct->KeyFlagName);
          }
     else
          newstruct->KeyFlagName = 0;


}
extern void PrintKeyWordInfo(KeyWordInfo *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("  The Key Flag Length:\n");
     PrintVariableName(eleptr->KeyFlagName);

}
extern void FreeKeyWordInfo(KeyWordInfo *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeVariableName(eleptr->KeyFlagName);
     Free(eleptr->KeyFlagName);

}
extern void WriteBinKeyWordInfo(KeyWordInfo *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinVariableName(eleptr->KeyFlagName,file);

}
extern INT ReadBinKeyWordInfo(KeyWordInfo *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->KeyFlagName = AllocateVariableName;
     if(ReadBinVariableName(eleptr->KeyFlagName,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->KeyFlagName);
           eleptr->KeyFlagName = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_KeyWordInfo(XDR *stream, char **eleptrp)
{
     KeyWordInfo *eleptr;
     eleptr = (KeyWordInfo *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->KeyFlagName),
          VariableNameSize,
                 (xdrproc_t) xdr_VariableName);
}

extern void *AllocKeyWordInfo()
{
     return((void *) AllocateKeyWordInfo);
}

extern CHAR *GetNameKeyWordSetInfo(KeyWordSetInfo *str)
{
     return(str->Name);
}

extern INT GetIDKeyWordSetInfo(KeyWordSetInfo *str)
{
     return(str->ID);
}

extern KeyWordSetInfo *CreateKeyWordSetInfo(KeyWordSetInfo *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  NumberOfKeys,
                                     KeyWordInfo *Keys)
{
KeyWordInfo *oldKeys,*newKeys;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfKeys = NumberOfKeys;

     newstruct->Keys = AllocArrayKeyWordInfo(newstruct->NumberOfKeys);
     if(Keys != 0)
          {
          oldKeys = Keys;
          newKeys = newstruct->Keys;
          LOOPi(newstruct->NumberOfKeys)
               CopyFullKeyWordInfo(newKeys++, oldKeys++);
          }



     return(newstruct);
}


extern void CopyFullKeyWordSetInfo(KeyWordSetInfo *newstruct, KeyWordSetInfo *oldstruct)
{
KeyWordInfo *oldKeys,*newKeys;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfKeys = oldstruct->NumberOfKeys;


     newstruct->Keys = AllocArrayKeyWordInfo(newstruct->NumberOfKeys);
     if(oldstruct->Keys != 0)
          {
          oldKeys = oldstruct->Keys;
          newKeys = newstruct->Keys;
          LOOPi(newstruct->NumberOfKeys)
               CopyFullKeyWordInfo(newKeys++, oldKeys++);
          }


}
extern void PrintKeyWordSetInfo(KeyWordSetInfo *eleptr)
{
KeyWordInfo *ptrKeys;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("  The Number of Keys:");
     printf("%d\n",eleptr->NumberOfKeys);

     printf("     The set of keys:\n");
     if(eleptr->Keys != 0)
          {
          ptrKeys = eleptr->Keys;
          LOOPi(eleptr->NumberOfKeys)
               PrintKeyWordInfo(ptrKeys++);
          }


}
extern void FreeKeyWordSetInfo(KeyWordSetInfo *eleptr)
{
KeyWordInfo *ptrKeys;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrKeys = eleptr->Keys;
     LOOPi(eleptr->NumberOfKeys)
          FreeKeyWordInfo(ptrKeys++);
     Free(eleptr->Keys);

}
extern void WriteBinKeyWordSetInfo(KeyWordSetInfo *eleptr, DbaseLinkedList *file)
{
KeyWordInfo *ptrKeys;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfKeys),file);

     if(eleptr->Keys != 0)
          {
          ptrKeys = eleptr->Keys;
          LOOPi(eleptr->NumberOfKeys)
               WriteBinKeyWordInfo(ptrKeys++,file);
          }

}
extern INT ReadBinKeyWordSetInfo(KeyWordSetInfo *eleptr,DbaseLinkedList *file)
     {
KeyWordInfo *ptrKeys;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfKeys),file);

          eleptr->Keys = AllocArrayKeyWordInfo(eleptr->NumberOfKeys);
          ptrKeys = eleptr->Keys;
          LOOPi(eleptr->NumberOfKeys)
               ReadBinKeyWordInfo(ptrKeys++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_KeyWordSetInfo(XDR *stream, char **eleptrp)
{
     KeyWordSetInfo *eleptr;
     eleptr = (KeyWordSetInfo *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfKeys));

     xdr_array(stream,(char **) &(eleptr->Keys),
             (uint *) &(eleptr->NumberOfKeys),eleptr->NumberOfKeys,
               KeyWordInfoSize,(xdrproc_t) xdr_KeyWordInfo);
}

extern void *AllocKeyWordSetInfo()
{
     return((void *) AllocateKeyWordSetInfo);
}

extern CHAR *GetNameArgumentInfo(ArgumentInfo *str)
{
     return(str->Name);
}

extern INT GetIDArgumentInfo(ArgumentInfo *str)
{
     return(str->ID);
}

extern ArgumentInfo *CreateArgumentInfo(ArgumentInfo *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  Type,
                                 VariableName *FlagName,
                                 TitleInfo *Title,
                                 BaseArgumentType *Default,
                                 BaseArgumentType *UpperBound,
                                 BaseArgumentType *LowerBound,
                                 INT  SetFlag)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Type = Type;
     newstruct->SetFlag = SetFlag;
     if(FlagName != 0)
          {
          newstruct->FlagName = AllocateVariableName;
          CopyFullVariableName(newstruct->FlagName, FlagName);
          }
     else
          newstruct->FlagName = 0;
     if(Title != 0)
          {
          newstruct->Title = AllocateTitleInfo;
          CopyFullTitleInfo(newstruct->Title, Title);
          }
     else
          newstruct->Title = 0;
     if(Default != 0)
          {
          newstruct->Default = AllocateBaseArgumentType;
          CopyFullBaseArgumentType(newstruct->Default, Default);
          }
     else
          newstruct->Default = 0;
     if(UpperBound != 0)
          {
          newstruct->UpperBound = AllocateBaseArgumentType;
          CopyFullBaseArgumentType(newstruct->UpperBound, UpperBound);
          }
     else
          newstruct->UpperBound = 0;
     if(LowerBound != 0)
          {
          newstruct->LowerBound = AllocateBaseArgumentType;
          CopyFullBaseArgumentType(newstruct->LowerBound, LowerBound);
          }
     else
          newstruct->LowerBound = 0;



     return(newstruct);
}


extern void CopyFullArgumentInfo(ArgumentInfo *newstruct, ArgumentInfo *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Type = oldstruct->Type;
     newstruct->SetFlag = oldstruct->SetFlag;

     if(oldstruct->FlagName != 0)
          {
          newstruct->FlagName = AllocateVariableName;
          CopyFullVariableName(newstruct->FlagName, oldstruct->FlagName);
          }
     else
          newstruct->FlagName = 0;
     if(oldstruct->Title != 0)
          {
          newstruct->Title = AllocateTitleInfo;
          CopyFullTitleInfo(newstruct->Title, oldstruct->Title);
          }
     else
          newstruct->Title = 0;
     if(oldstruct->Default != 0)
          {
          newstruct->Default = AllocateBaseArgumentType;
          CopyFullBaseArgumentType(newstruct->Default, oldstruct->Default);
          }
     else
          newstruct->Default = 0;
     if(oldstruct->UpperBound != 0)
          {
          newstruct->UpperBound = AllocateBaseArgumentType;
          CopyFullBaseArgumentType(newstruct->UpperBound, oldstruct->UpperBound);
          }
     else
          newstruct->UpperBound = 0;
     if(oldstruct->LowerBound != 0)
          {
          newstruct->LowerBound = AllocateBaseArgumentType;
          CopyFullBaseArgumentType(newstruct->LowerBound, oldstruct->LowerBound);
          }
     else
          newstruct->LowerBound = 0;


}
extern void PrintArgumentInfo(ArgumentInfo *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("   The Argument Type:");
     printf("%d\n",eleptr->Type);
     printf("  The Flag denoting whether a set of arguments :");
     printf("%d\n",eleptr->SetFlag);

     printf("       The Flag Name:\n");
     PrintVariableName(eleptr->FlagName);

     printf("           The Title:\n");
     PrintTitleInfo(eleptr->Title);

     printf("   The Default Value:\n");
     PrintBaseArgumentType(eleptr->Default);

     printf("     The Upper Bound:\n");
     PrintBaseArgumentType(eleptr->UpperBound);

     printf("     The Lower Bound:\n");
     PrintBaseArgumentType(eleptr->LowerBound);

}
extern void FreeArgumentInfo(ArgumentInfo *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeVariableName(eleptr->FlagName);
     Free(eleptr->FlagName);

     FreeTitleInfo(eleptr->Title);
     Free(eleptr->Title);

     FreeBaseArgumentType(eleptr->Default);
     Free(eleptr->Default);

     FreeBaseArgumentType(eleptr->UpperBound);
     Free(eleptr->UpperBound);

     FreeBaseArgumentType(eleptr->LowerBound);
     Free(eleptr->LowerBound);

}
extern void WriteBinArgumentInfo(ArgumentInfo *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->Type),file);
     WriteBinINT(&(eleptr->SetFlag),file);

     WriteBinVariableName(eleptr->FlagName,file);

     WriteBinTitleInfo(eleptr->Title,file);

     WriteBinBaseArgumentType(eleptr->Default,file);

     WriteBinBaseArgumentType(eleptr->UpperBound,file);

     WriteBinBaseArgumentType(eleptr->LowerBound,file);

}
extern INT ReadBinArgumentInfo(ArgumentInfo *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->Type),file);
     ReadBinINT(&(eleptr->SetFlag),file);

     eleptr->FlagName = AllocateVariableName;
     if(ReadBinVariableName(eleptr->FlagName,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->FlagName);
           eleptr->FlagName = 0;
           }

     eleptr->Title = AllocateTitleInfo;
     if(ReadBinTitleInfo(eleptr->Title,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Title);
           eleptr->Title = 0;
           }

     eleptr->Default = AllocateBaseArgumentType;
     if(ReadBinBaseArgumentType(eleptr->Default,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Default);
           eleptr->Default = 0;
           }

     eleptr->UpperBound = AllocateBaseArgumentType;
     if(ReadBinBaseArgumentType(eleptr->UpperBound,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->UpperBound);
           eleptr->UpperBound = 0;
           }

     eleptr->LowerBound = AllocateBaseArgumentType;
     if(ReadBinBaseArgumentType(eleptr->LowerBound,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->LowerBound);
           eleptr->LowerBound = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_ArgumentInfo(XDR *stream, char **eleptrp)
{
     ArgumentInfo *eleptr;
     eleptr = (ArgumentInfo *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->Type));
     xdr_INT(stream,(char **) &(eleptr->SetFlag));

     xdr_pointer(stream,
          (char **) &(eleptr->FlagName),
          VariableNameSize,
                 (xdrproc_t) xdr_VariableName);
     xdr_pointer(stream,
          (char **) &(eleptr->Title),
          TitleInfoSize,
                 (xdrproc_t) xdr_TitleInfo);
     xdr_pointer(stream,
          (char **) &(eleptr->Default),
          BaseArgumentTypeSize,
                 (xdrproc_t) xdr_BaseArgumentType);
     xdr_pointer(stream,
          (char **) &(eleptr->UpperBound),
          BaseArgumentTypeSize,
                 (xdrproc_t) xdr_BaseArgumentType);
     xdr_pointer(stream,
          (char **) &(eleptr->LowerBound),
          BaseArgumentTypeSize,
                 (xdrproc_t) xdr_BaseArgumentType);
}

extern void *AllocArgumentInfo()
{
     return((void *) AllocateArgumentInfo);
}

extern CHAR *GetNameArgumentSetInfo(ArgumentSetInfo *str)
{
     return(str->Name);
}

extern INT GetIDArgumentSetInfo(ArgumentSetInfo *str)
{
     return(str->ID);
}

extern ArgumentSetInfo *CreateArgumentSetInfo(ArgumentSetInfo *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NumberOfArguments,
                                       ArgumentInfo *Set,
                                       BaseArgumentType *Values)
{
ArgumentInfo *oldSet,*newSet;
BaseArgumentType *oldValues,*newValues;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfArguments = NumberOfArguments;

     newstruct->Set = AllocArrayArgumentInfo(newstruct->NumberOfArguments);
     if(Set != 0)
          {
          oldSet = Set;
          newSet = newstruct->Set;
          LOOPi(newstruct->NumberOfArguments)
               CopyFullArgumentInfo(newSet++, oldSet++);
          }

     newstruct->Values = AllocArrayBaseArgumentType(newstruct->NumberOfArguments);
     if(Values != 0)
          {
          oldValues = Values;
          newValues = newstruct->Values;
          LOOPi(newstruct->NumberOfArguments)
               CopyFullBaseArgumentType(newValues++, oldValues++);
          }



     return(newstruct);
}


extern void CopyFullArgumentSetInfo(ArgumentSetInfo *newstruct, ArgumentSetInfo *oldstruct)
{
ArgumentInfo *oldSet,*newSet;
BaseArgumentType *oldValues,*newValues;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfArguments = oldstruct->NumberOfArguments;


     newstruct->Set = AllocArrayArgumentInfo(newstruct->NumberOfArguments);
     if(oldstruct->Set != 0)
          {
          oldSet = oldstruct->Set;
          newSet = newstruct->Set;
          LOOPi(newstruct->NumberOfArguments)
               CopyFullArgumentInfo(newSet++, oldSet++);
          }

     newstruct->Values = AllocArrayBaseArgumentType(newstruct->NumberOfArguments);
     if(oldstruct->Values != 0)
          {
          oldValues = oldstruct->Values;
          newValues = newstruct->Values;
          LOOPi(newstruct->NumberOfArguments)
               CopyFullBaseArgumentType(newValues++, oldValues++);
          }


}
extern void PrintArgumentSetInfo(ArgumentSetInfo *eleptr)
{
ArgumentInfo *ptrSet;
BaseArgumentType *ptrValues;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("  Number of Arguments:");
     printf("%d\n",eleptr->NumberOfArguments);

     printf("  The set of argument info:\n");
     if(eleptr->Set != 0)
          {
          ptrSet = eleptr->Set;
          LOOPi(eleptr->NumberOfArguments)
               PrintArgumentInfo(ptrSet++);
          }


     printf("  The Value of the argument:\n");
     if(eleptr->Values != 0)
          {
          ptrValues = eleptr->Values;
          LOOPi(eleptr->NumberOfArguments)
               PrintBaseArgumentType(ptrValues++);
          }


}
extern void FreeArgumentSetInfo(ArgumentSetInfo *eleptr)
{
ArgumentInfo *ptrSet;
BaseArgumentType *ptrValues;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrSet = eleptr->Set;
     LOOPi(eleptr->NumberOfArguments)
          FreeArgumentInfo(ptrSet++);
     Free(eleptr->Set);

     ptrValues = eleptr->Values;
     LOOPi(eleptr->NumberOfArguments)
          FreeBaseArgumentType(ptrValues++);
     Free(eleptr->Values);

}
extern void WriteBinArgumentSetInfo(ArgumentSetInfo *eleptr, DbaseLinkedList *file)
{
ArgumentInfo *ptrSet;
BaseArgumentType *ptrValues;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfArguments),file);

     if(eleptr->Set != 0)
          {
          ptrSet = eleptr->Set;
          LOOPi(eleptr->NumberOfArguments)
               WriteBinArgumentInfo(ptrSet++,file);
          }

     if(eleptr->Values != 0)
          {
          ptrValues = eleptr->Values;
          LOOPi(eleptr->NumberOfArguments)
               WriteBinBaseArgumentType(ptrValues++,file);
          }

}
extern INT ReadBinArgumentSetInfo(ArgumentSetInfo *eleptr,DbaseLinkedList *file)
     {
ArgumentInfo *ptrSet;
BaseArgumentType *ptrValues;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfArguments),file);

          eleptr->Set = AllocArrayArgumentInfo(eleptr->NumberOfArguments);
          ptrSet = eleptr->Set;
          LOOPi(eleptr->NumberOfArguments)
               ReadBinArgumentInfo(ptrSet++,file);

          eleptr->Values = AllocArrayBaseArgumentType(eleptr->NumberOfArguments);
          ptrValues = eleptr->Values;
          LOOPi(eleptr->NumberOfArguments)
               ReadBinBaseArgumentType(ptrValues++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_ArgumentSetInfo(XDR *stream, char **eleptrp)
{
     ArgumentSetInfo *eleptr;
     eleptr = (ArgumentSetInfo *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfArguments));

     xdr_array(stream,(char **) &(eleptr->Set),
             (uint *) &(eleptr->NumberOfArguments),eleptr->NumberOfArguments,
               ArgumentInfoSize,(xdrproc_t) xdr_ArgumentInfo);
     xdr_array(stream,(char **) &(eleptr->Values),
             (uint *) &(eleptr->NumberOfArguments),eleptr->NumberOfArguments,
               BaseArgumentTypeSize,(xdrproc_t) xdr_BaseArgumentType);
}

extern void *AllocArgumentSetInfo()
{
     return((void *) AllocateArgumentSetInfo);
}

extern CHAR *GetNameKeyArgumentInfo(KeyArgumentInfo *str)
{
     return(str->Name);
}

extern INT GetIDKeyArgumentInfo(KeyArgumentInfo *str)
{
     return(str->ID);
}

extern KeyArgumentInfo *CreateKeyArgumentInfo(KeyArgumentInfo *newstruct,
                                       INT id,
                                       CHAR *name,
                                       VariableName *KeySetName,
                                       VariableName *ArgumentName,
                                       TitleInfo *Title)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(KeySetName != 0)
          {
          newstruct->KeySetName = AllocateVariableName;
          CopyFullVariableName(newstruct->KeySetName, KeySetName);
          }
     else
          newstruct->KeySetName = 0;
     if(ArgumentName != 0)
          {
          newstruct->ArgumentName = AllocateVariableName;
          CopyFullVariableName(newstruct->ArgumentName, ArgumentName);
          }
     else
          newstruct->ArgumentName = 0;
     if(Title != 0)
          {
          newstruct->Title = AllocateTitleInfo;
          CopyFullTitleInfo(newstruct->Title, Title);
          }
     else
          newstruct->Title = 0;



     return(newstruct);
}


extern void CopyFullKeyArgumentInfo(KeyArgumentInfo *newstruct, KeyArgumentInfo *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->KeySetName != 0)
          {
          newstruct->KeySetName = AllocateVariableName;
          CopyFullVariableName(newstruct->KeySetName, oldstruct->KeySetName);
          }
     else
          newstruct->KeySetName = 0;
     if(oldstruct->ArgumentName != 0)
          {
          newstruct->ArgumentName = AllocateVariableName;
          CopyFullVariableName(newstruct->ArgumentName, oldstruct->ArgumentName);
          }
     else
          newstruct->ArgumentName = 0;
     if(oldstruct->Title != 0)
          {
          newstruct->Title = AllocateTitleInfo;
          CopyFullTitleInfo(newstruct->Title, oldstruct->Title);
          }
     else
          newstruct->Title = 0;


}
extern void PrintKeyArgumentInfo(KeyArgumentInfo *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("    The Key Set Name:\n");
     PrintVariableName(eleptr->KeySetName);

     printf("   The Argument Name:\n");
     PrintVariableName(eleptr->ArgumentName);

     printf("           The Title:\n");
     PrintTitleInfo(eleptr->Title);

}
extern void FreeKeyArgumentInfo(KeyArgumentInfo *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeVariableName(eleptr->KeySetName);
     Free(eleptr->KeySetName);

     FreeVariableName(eleptr->ArgumentName);
     Free(eleptr->ArgumentName);

     FreeTitleInfo(eleptr->Title);
     Free(eleptr->Title);

}
extern void WriteBinKeyArgumentInfo(KeyArgumentInfo *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinVariableName(eleptr->KeySetName,file);

     WriteBinVariableName(eleptr->ArgumentName,file);

     WriteBinTitleInfo(eleptr->Title,file);

}
extern INT ReadBinKeyArgumentInfo(KeyArgumentInfo *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->KeySetName = AllocateVariableName;
     if(ReadBinVariableName(eleptr->KeySetName,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->KeySetName);
           eleptr->KeySetName = 0;
           }

     eleptr->ArgumentName = AllocateVariableName;
     if(ReadBinVariableName(eleptr->ArgumentName,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->ArgumentName);
           eleptr->ArgumentName = 0;
           }

     eleptr->Title = AllocateTitleInfo;
     if(ReadBinTitleInfo(eleptr->Title,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Title);
           eleptr->Title = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_KeyArgumentInfo(XDR *stream, char **eleptrp)
{
     KeyArgumentInfo *eleptr;
     eleptr = (KeyArgumentInfo *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->KeySetName),
          VariableNameSize,
                 (xdrproc_t) xdr_VariableName);
     xdr_pointer(stream,
          (char **) &(eleptr->ArgumentName),
          VariableNameSize,
                 (xdrproc_t) xdr_VariableName);
     xdr_pointer(stream,
          (char **) &(eleptr->Title),
          TitleInfoSize,
                 (xdrproc_t) xdr_TitleInfo);
}

extern void *AllocKeyArgumentInfo()
{
     return((void *) AllocateKeyArgumentInfo);
}

extern CHAR *GetNameKeyArgumentSet(KeyArgumentSet *str)
{
     return(str->Name);
}

extern INT GetIDKeyArgumentSet(KeyArgumentSet *str)
{
     return(str->ID);
}

extern KeyArgumentSet *CreateKeyArgumentSet(KeyArgumentSet *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  NumberOfKeys,
                                     KeyArgumentInfo *KeyArguments)
{
KeyArgumentInfo *oldKeyArguments,*newKeyArguments;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfKeys = NumberOfKeys;

     newstruct->KeyArguments = AllocArrayKeyArgumentInfo(newstruct->NumberOfKeys);
     if(KeyArguments != 0)
          {
          oldKeyArguments = KeyArguments;
          newKeyArguments = newstruct->KeyArguments;
          LOOPi(newstruct->NumberOfKeys)
               CopyFullKeyArgumentInfo(newKeyArguments++, oldKeyArguments++);
          }



     return(newstruct);
}


extern void CopyFullKeyArgumentSet(KeyArgumentSet *newstruct, KeyArgumentSet *oldstruct)
{
KeyArgumentInfo *oldKeyArguments,*newKeyArguments;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfKeys = oldstruct->NumberOfKeys;


     newstruct->KeyArguments = AllocArrayKeyArgumentInfo(newstruct->NumberOfKeys);
     if(oldstruct->KeyArguments != 0)
          {
          oldKeyArguments = oldstruct->KeyArguments;
          newKeyArguments = newstruct->KeyArguments;
          LOOPi(newstruct->NumberOfKeys)
               CopyFullKeyArgumentInfo(newKeyArguments++, oldKeyArguments++);
          }


}
extern void PrintKeyArgumentSet(KeyArgumentSet *eleptr)
{
KeyArgumentInfo *ptrKeyArguments;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("  The Number Of keys:");
     printf("%d\n",eleptr->NumberOfKeys);

     printf("     The Set of Keys:\n");
     if(eleptr->KeyArguments != 0)
          {
          ptrKeyArguments = eleptr->KeyArguments;
          LOOPi(eleptr->NumberOfKeys)
               PrintKeyArgumentInfo(ptrKeyArguments++);
          }


}
extern void FreeKeyArgumentSet(KeyArgumentSet *eleptr)
{
KeyArgumentInfo *ptrKeyArguments;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrKeyArguments = eleptr->KeyArguments;
     LOOPi(eleptr->NumberOfKeys)
          FreeKeyArgumentInfo(ptrKeyArguments++);
     Free(eleptr->KeyArguments);

}
extern void WriteBinKeyArgumentSet(KeyArgumentSet *eleptr, DbaseLinkedList *file)
{
KeyArgumentInfo *ptrKeyArguments;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfKeys),file);

     if(eleptr->KeyArguments != 0)
          {
          ptrKeyArguments = eleptr->KeyArguments;
          LOOPi(eleptr->NumberOfKeys)
               WriteBinKeyArgumentInfo(ptrKeyArguments++,file);
          }

}
extern INT ReadBinKeyArgumentSet(KeyArgumentSet *eleptr,DbaseLinkedList *file)
     {
KeyArgumentInfo *ptrKeyArguments;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfKeys),file);

          eleptr->KeyArguments = AllocArrayKeyArgumentInfo(eleptr->NumberOfKeys);
          ptrKeyArguments = eleptr->KeyArguments;
          LOOPi(eleptr->NumberOfKeys)
               ReadBinKeyArgumentInfo(ptrKeyArguments++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_KeyArgumentSet(XDR *stream, char **eleptrp)
{
     KeyArgumentSet *eleptr;
     eleptr = (KeyArgumentSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfKeys));

     xdr_array(stream,(char **) &(eleptr->KeyArguments),
             (uint *) &(eleptr->NumberOfKeys),eleptr->NumberOfKeys,
               KeyArgumentInfoSize,(xdrproc_t) xdr_KeyArgumentInfo);
}

extern void *AllocKeyArgumentSet()
{
     return((void *) AllocateKeyArgumentSet);
}

extern CHAR *GetNameSysLstArgumentInfo(SysLstArgumentInfo *str)
{
     return(str->Name);
}

extern INT GetIDSysLstArgumentInfo(SysLstArgumentInfo *str)
{
     return(str->ID);
}

extern SysLstArgumentInfo *CreateSysLstArgumentInfo(SysLstArgumentInfo *newstruct,
                                             INT id,
                                             CHAR *name,
                                             VariableName *SysLstKey)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(SysLstKey != 0)
          {
          newstruct->SysLstKey = AllocateVariableName;
          CopyFullVariableName(newstruct->SysLstKey, SysLstKey);
          }
     else
          newstruct->SysLstKey = 0;



     return(newstruct);
}


extern void CopyFullSysLstArgumentInfo(SysLstArgumentInfo *newstruct, SysLstArgumentInfo *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->SysLstKey != 0)
          {
          newstruct->SysLstKey = AllocateVariableName;
          CopyFullVariableName(newstruct->SysLstKey, oldstruct->SysLstKey);
          }
     else
          newstruct->SysLstKey = 0;


}
extern void PrintSysLstArgumentInfo(SysLstArgumentInfo *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("  The System List Key Name:\n");
     PrintVariableName(eleptr->SysLstKey);

}
extern void FreeSysLstArgumentInfo(SysLstArgumentInfo *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeVariableName(eleptr->SysLstKey);
     Free(eleptr->SysLstKey);

}
extern void WriteBinSysLstArgumentInfo(SysLstArgumentInfo *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinVariableName(eleptr->SysLstKey,file);

}
extern INT ReadBinSysLstArgumentInfo(SysLstArgumentInfo *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->SysLstKey = AllocateVariableName;
     if(ReadBinVariableName(eleptr->SysLstKey,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->SysLstKey);
           eleptr->SysLstKey = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_SysLstArgumentInfo(XDR *stream, char **eleptrp)
{
     SysLstArgumentInfo *eleptr;
     eleptr = (SysLstArgumentInfo *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->SysLstKey),
          VariableNameSize,
                 (xdrproc_t) xdr_VariableName);
}

extern void *AllocSysLstArgumentInfo()
{
     return((void *) AllocateSysLstArgumentInfo);
}

extern CHAR *GetNameSysLstArgumentSet(SysLstArgumentSet *str)
{
     return(str->Name);
}

extern INT GetIDSysLstArgumentSet(SysLstArgumentSet *str)
{
     return(str->ID);
}

extern SysLstArgumentSet *CreateSysLstArgumentSet(SysLstArgumentSet *newstruct,
                                           INT id,
                                           CHAR *name,
                                           INT  NumSysLst,
                                           SysLstArgumentInfo *SysLstArguments)
{
SysLstArgumentInfo *oldSysLstArguments,*newSysLstArguments;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumSysLst = NumSysLst;

     newstruct->SysLstArguments = AllocArraySysLstArgumentInfo(newstruct->NumSysLst);
     if(SysLstArguments != 0)
          {
          oldSysLstArguments = SysLstArguments;
          newSysLstArguments = newstruct->SysLstArguments;
          LOOPi(newstruct->NumSysLst)
               CopyFullSysLstArgumentInfo(newSysLstArguments++, oldSysLstArguments++);
          }



     return(newstruct);
}


extern void CopyFullSysLstArgumentSet(SysLstArgumentSet *newstruct, SysLstArgumentSet *oldstruct)
{
SysLstArgumentInfo *oldSysLstArguments,*newSysLstArguments;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumSysLst = oldstruct->NumSysLst;


     newstruct->SysLstArguments = AllocArraySysLstArgumentInfo(newstruct->NumSysLst);
     if(oldstruct->SysLstArguments != 0)
          {
          oldSysLstArguments = oldstruct->SysLstArguments;
          newSysLstArguments = newstruct->SysLstArguments;
          LOOPi(newstruct->NumSysLst)
               CopyFullSysLstArgumentInfo(newSysLstArguments++, oldSysLstArguments++);
          }


}
extern void PrintSysLstArgumentSet(SysLstArgumentSet *eleptr)
{
SysLstArgumentInfo *ptrSysLstArguments;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("  The number of SysLst Arguments:");
     printf("%d\n",eleptr->NumSysLst);

     printf("  The Set of SysLst Arguments:\n");
     if(eleptr->SysLstArguments != 0)
          {
          ptrSysLstArguments = eleptr->SysLstArguments;
          LOOPi(eleptr->NumSysLst)
               PrintSysLstArgumentInfo(ptrSysLstArguments++);
          }


}
extern void FreeSysLstArgumentSet(SysLstArgumentSet *eleptr)
{
SysLstArgumentInfo *ptrSysLstArguments;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrSysLstArguments = eleptr->SysLstArguments;
     LOOPi(eleptr->NumSysLst)
          FreeSysLstArgumentInfo(ptrSysLstArguments++);
     Free(eleptr->SysLstArguments);

}
extern void WriteBinSysLstArgumentSet(SysLstArgumentSet *eleptr, DbaseLinkedList *file)
{
SysLstArgumentInfo *ptrSysLstArguments;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumSysLst),file);

     if(eleptr->SysLstArguments != 0)
          {
          ptrSysLstArguments = eleptr->SysLstArguments;
          LOOPi(eleptr->NumSysLst)
               WriteBinSysLstArgumentInfo(ptrSysLstArguments++,file);
          }

}
extern INT ReadBinSysLstArgumentSet(SysLstArgumentSet *eleptr,DbaseLinkedList *file)
     {
SysLstArgumentInfo *ptrSysLstArguments;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumSysLst),file);

          eleptr->SysLstArguments = AllocArraySysLstArgumentInfo(eleptr->NumSysLst);
          ptrSysLstArguments = eleptr->SysLstArguments;
          LOOPi(eleptr->NumSysLst)
               ReadBinSysLstArgumentInfo(ptrSysLstArguments++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SysLstArgumentSet(XDR *stream, char **eleptrp)
{
     SysLstArgumentSet *eleptr;
     eleptr = (SysLstArgumentSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumSysLst));

     xdr_array(stream,(char **) &(eleptr->SysLstArguments),
             (uint *) &(eleptr->NumSysLst),eleptr->NumSysLst,
               SysLstArgumentInfoSize,(xdrproc_t) xdr_SysLstArgumentInfo);
}

extern void *AllocSysLstArgumentSet()
{
     return((void *) AllocateSysLstArgumentSet);
}

extern CHAR *GetNameCommandInfo(CommandInfo *str)
{
     return(str->Name);
}

extern INT GetIDCommandInfo(CommandInfo *str)
{
     return(str->ID);
}

extern CommandInfo *CreateCommandInfo(CommandInfo *newstruct,
                               INT id,
                               CHAR *name,
                               VariableName *FlagName,
                               FunctionInfo *Function,
                               TitleInfo *Comment,
                               ArgumentSetInfo *Arguments,
                               KeyArgumentSet *Keys,
                               SysLstArgumentSet *SysLstSet,
                               KeyWordSetInfo *KeySetInfo,
                               SysLstArgumentSet *Output,
                               SysLstArgumentSet *Checks,
                               INT  NumSubCommands,
                               CommandInfo *SubCommands)
{
CommandInfo *oldSubCommands,*newSubCommands;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumSubCommands = NumSubCommands;
     if(FlagName != 0)
          {
          newstruct->FlagName = AllocateVariableName;
          CopyFullVariableName(newstruct->FlagName, FlagName);
          }
     else
          newstruct->FlagName = 0;
     if(Function != 0)
          {
          newstruct->Function = AllocateFunctionInfo;
          CopyFullFunctionInfo(newstruct->Function, Function);
          }
     else
          newstruct->Function = 0;
     if(Comment != 0)
          {
          newstruct->Comment = AllocateTitleInfo;
          CopyFullTitleInfo(newstruct->Comment, Comment);
          }
     else
          newstruct->Comment = 0;
     if(Arguments != 0)
          {
          newstruct->Arguments = AllocateArgumentSetInfo;
          CopyFullArgumentSetInfo(newstruct->Arguments, Arguments);
          }
     else
          newstruct->Arguments = 0;
     if(Keys != 0)
          {
          newstruct->Keys = AllocateKeyArgumentSet;
          CopyFullKeyArgumentSet(newstruct->Keys, Keys);
          }
     else
          newstruct->Keys = 0;
     if(SysLstSet != 0)
          {
          newstruct->SysLstSet = AllocateSysLstArgumentSet;
          CopyFullSysLstArgumentSet(newstruct->SysLstSet, SysLstSet);
          }
     else
          newstruct->SysLstSet = 0;
     if(KeySetInfo != 0)
          {
          newstruct->KeySetInfo = AllocateKeyWordSetInfo;
          CopyFullKeyWordSetInfo(newstruct->KeySetInfo, KeySetInfo);
          }
     else
          newstruct->KeySetInfo = 0;
     if(Output != 0)
          {
          newstruct->Output = AllocateSysLstArgumentSet;
          CopyFullSysLstArgumentSet(newstruct->Output, Output);
          }
     else
          newstruct->Output = 0;
     if(Checks != 0)
          {
          newstruct->Checks = AllocateSysLstArgumentSet;
          CopyFullSysLstArgumentSet(newstruct->Checks, Checks);
          }
     else
          newstruct->Checks = 0;

     newstruct->SubCommands = AllocArrayCommandInfo(newstruct->NumSubCommands);
     if(SubCommands != 0)
          {
          oldSubCommands = SubCommands;
          newSubCommands = newstruct->SubCommands;
          LOOPi(newstruct->NumSubCommands)
               CopyFullCommandInfo(newSubCommands++, oldSubCommands++);
          }



     return(newstruct);
}


extern void CopyFullCommandInfo(CommandInfo *newstruct, CommandInfo *oldstruct)
{
CommandInfo *oldSubCommands,*newSubCommands;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumSubCommands = oldstruct->NumSubCommands;

     if(oldstruct->FlagName != 0)
          {
          newstruct->FlagName = AllocateVariableName;
          CopyFullVariableName(newstruct->FlagName, oldstruct->FlagName);
          }
     else
          newstruct->FlagName = 0;
     if(oldstruct->Function != 0)
          {
          newstruct->Function = AllocateFunctionInfo;
          CopyFullFunctionInfo(newstruct->Function, oldstruct->Function);
          }
     else
          newstruct->Function = 0;
     if(oldstruct->Comment != 0)
          {
          newstruct->Comment = AllocateTitleInfo;
          CopyFullTitleInfo(newstruct->Comment, oldstruct->Comment);
          }
     else
          newstruct->Comment = 0;
     if(oldstruct->Arguments != 0)
          {
          newstruct->Arguments = AllocateArgumentSetInfo;
          CopyFullArgumentSetInfo(newstruct->Arguments, oldstruct->Arguments);
          }
     else
          newstruct->Arguments = 0;
     if(oldstruct->Keys != 0)
          {
          newstruct->Keys = AllocateKeyArgumentSet;
          CopyFullKeyArgumentSet(newstruct->Keys, oldstruct->Keys);
          }
     else
          newstruct->Keys = 0;
     if(oldstruct->SysLstSet != 0)
          {
          newstruct->SysLstSet = AllocateSysLstArgumentSet;
          CopyFullSysLstArgumentSet(newstruct->SysLstSet, oldstruct->SysLstSet);
          }
     else
          newstruct->SysLstSet = 0;
     if(oldstruct->KeySetInfo != 0)
          {
          newstruct->KeySetInfo = AllocateKeyWordSetInfo;
          CopyFullKeyWordSetInfo(newstruct->KeySetInfo, oldstruct->KeySetInfo);
          }
     else
          newstruct->KeySetInfo = 0;
     if(oldstruct->Output != 0)
          {
          newstruct->Output = AllocateSysLstArgumentSet;
          CopyFullSysLstArgumentSet(newstruct->Output, oldstruct->Output);
          }
     else
          newstruct->Output = 0;
     if(oldstruct->Checks != 0)
          {
          newstruct->Checks = AllocateSysLstArgumentSet;
          CopyFullSysLstArgumentSet(newstruct->Checks, oldstruct->Checks);
          }
     else
          newstruct->Checks = 0;

     newstruct->SubCommands = AllocArrayCommandInfo(newstruct->NumSubCommands);
     if(oldstruct->SubCommands != 0)
          {
          oldSubCommands = oldstruct->SubCommands;
          newSubCommands = newstruct->SubCommands;
          LOOPi(newstruct->NumSubCommands)
               CopyFullCommandInfo(newSubCommands++, oldSubCommands++);
          }


}
extern void PrintCommandInfo(CommandInfo *eleptr)
{
CommandInfo *ptrSubCommands;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("  The number of Sub commands:");
     printf("%d\n",eleptr->NumSubCommands);

     printf("      The Flag name :\n");
     PrintVariableName(eleptr->FlagName);

     printf("  The Function Parameters:\n");
     PrintFunctionInfo(eleptr->Function);

     printf("  This is the info about the function (text):\n");
     PrintTitleInfo(eleptr->Comment);

     printf("  The Set of Arguments:\n");
     PrintArgumentSetInfo(eleptr->Arguments);

     printf("     The Set of keys:\n");
     PrintKeyArgumentSet(eleptr->Keys);

     printf("  Set of SysLst Arguments:\n");
     PrintSysLstArgumentSet(eleptr->SysLstSet);

     printf("  KeyWord definitions:\n");
     PrintKeyWordSetInfo(eleptr->KeySetInfo);

     printf("  Set of Ouput Arguments:\n");
     PrintSysLstArgumentSet(eleptr->Output);

     printf("  Set of Extra Checks:\n");
     PrintSysLstArgumentSet(eleptr->Checks);

     printf("  The set of SubCommands:\n");
     if(eleptr->SubCommands != 0)
          {
          ptrSubCommands = eleptr->SubCommands;
          LOOPi(eleptr->NumSubCommands)
               PrintCommandInfo(ptrSubCommands++);
          }


}
extern void FreeCommandInfo(CommandInfo *eleptr)
{
CommandInfo *ptrSubCommands;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrSubCommands = eleptr->SubCommands;
     LOOPi(eleptr->NumSubCommands)
          FreeCommandInfo(ptrSubCommands++);
     Free(eleptr->SubCommands);

     FreeVariableName(eleptr->FlagName);
     Free(eleptr->FlagName);

     FreeFunctionInfo(eleptr->Function);
     Free(eleptr->Function);

     FreeTitleInfo(eleptr->Comment);
     Free(eleptr->Comment);

     FreeArgumentSetInfo(eleptr->Arguments);
     Free(eleptr->Arguments);

     FreeKeyArgumentSet(eleptr->Keys);
     Free(eleptr->Keys);

     FreeSysLstArgumentSet(eleptr->SysLstSet);
     Free(eleptr->SysLstSet);

     FreeKeyWordSetInfo(eleptr->KeySetInfo);
     Free(eleptr->KeySetInfo);

     FreeSysLstArgumentSet(eleptr->Output);
     Free(eleptr->Output);

     FreeSysLstArgumentSet(eleptr->Checks);
     Free(eleptr->Checks);

}
extern void WriteBinCommandInfo(CommandInfo *eleptr, DbaseLinkedList *file)
{
CommandInfo *ptrSubCommands;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumSubCommands),file);

     WriteBinVariableName(eleptr->FlagName,file);

     WriteBinFunctionInfo(eleptr->Function,file);

     WriteBinTitleInfo(eleptr->Comment,file);

     WriteBinArgumentSetInfo(eleptr->Arguments,file);

     WriteBinKeyArgumentSet(eleptr->Keys,file);

     WriteBinSysLstArgumentSet(eleptr->SysLstSet,file);

     WriteBinKeyWordSetInfo(eleptr->KeySetInfo,file);

     WriteBinSysLstArgumentSet(eleptr->Output,file);

     WriteBinSysLstArgumentSet(eleptr->Checks,file);

     if(eleptr->SubCommands != 0)
          {
          ptrSubCommands = eleptr->SubCommands;
          LOOPi(eleptr->NumSubCommands)
               WriteBinCommandInfo(ptrSubCommands++,file);
          }

}
extern INT ReadBinCommandInfo(CommandInfo *eleptr,DbaseLinkedList *file)
     {
CommandInfo *ptrSubCommands;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumSubCommands),file);

     eleptr->FlagName = AllocateVariableName;
     if(ReadBinVariableName(eleptr->FlagName,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->FlagName);
           eleptr->FlagName = 0;
           }

     eleptr->Function = AllocateFunctionInfo;
     if(ReadBinFunctionInfo(eleptr->Function,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Function);
           eleptr->Function = 0;
           }

     eleptr->Comment = AllocateTitleInfo;
     if(ReadBinTitleInfo(eleptr->Comment,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Comment);
           eleptr->Comment = 0;
           }

     eleptr->Arguments = AllocateArgumentSetInfo;
     if(ReadBinArgumentSetInfo(eleptr->Arguments,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Arguments);
           eleptr->Arguments = 0;
           }

     eleptr->Keys = AllocateKeyArgumentSet;
     if(ReadBinKeyArgumentSet(eleptr->Keys,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Keys);
           eleptr->Keys = 0;
           }

     eleptr->SysLstSet = AllocateSysLstArgumentSet;
     if(ReadBinSysLstArgumentSet(eleptr->SysLstSet,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->SysLstSet);
           eleptr->SysLstSet = 0;
           }

     eleptr->KeySetInfo = AllocateKeyWordSetInfo;
     if(ReadBinKeyWordSetInfo(eleptr->KeySetInfo,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->KeySetInfo);
           eleptr->KeySetInfo = 0;
           }

     eleptr->Output = AllocateSysLstArgumentSet;
     if(ReadBinSysLstArgumentSet(eleptr->Output,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Output);
           eleptr->Output = 0;
           }

     eleptr->Checks = AllocateSysLstArgumentSet;
     if(ReadBinSysLstArgumentSet(eleptr->Checks,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Checks);
           eleptr->Checks = 0;
           }

          eleptr->SubCommands = AllocArrayCommandInfo(eleptr->NumSubCommands);
          ptrSubCommands = eleptr->SubCommands;
          LOOPi(eleptr->NumSubCommands)
               ReadBinCommandInfo(ptrSubCommands++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_CommandInfo(XDR *stream, char **eleptrp)
{
     CommandInfo *eleptr;
     eleptr = (CommandInfo *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumSubCommands));

     xdr_pointer(stream,
          (char **) &(eleptr->FlagName),
          VariableNameSize,
                 (xdrproc_t) xdr_VariableName);
     xdr_pointer(stream,
          (char **) &(eleptr->Function),
          FunctionInfoSize,
                 (xdrproc_t) xdr_FunctionInfo);
     xdr_pointer(stream,
          (char **) &(eleptr->Comment),
          TitleInfoSize,
                 (xdrproc_t) xdr_TitleInfo);
     xdr_pointer(stream,
          (char **) &(eleptr->Arguments),
          ArgumentSetInfoSize,
                 (xdrproc_t) xdr_ArgumentSetInfo);
     xdr_pointer(stream,
          (char **) &(eleptr->Keys),
          KeyArgumentSetSize,
                 (xdrproc_t) xdr_KeyArgumentSet);
     xdr_pointer(stream,
          (char **) &(eleptr->SysLstSet),
          SysLstArgumentSetSize,
                 (xdrproc_t) xdr_SysLstArgumentSet);
     xdr_pointer(stream,
          (char **) &(eleptr->KeySetInfo),
          KeyWordSetInfoSize,
                 (xdrproc_t) xdr_KeyWordSetInfo);
     xdr_pointer(stream,
          (char **) &(eleptr->Output),
          SysLstArgumentSetSize,
                 (xdrproc_t) xdr_SysLstArgumentSet);
     xdr_pointer(stream,
          (char **) &(eleptr->Checks),
          SysLstArgumentSetSize,
                 (xdrproc_t) xdr_SysLstArgumentSet);
     xdr_array(stream,(char **) &(eleptr->SubCommands),
             (uint *) &(eleptr->NumSubCommands),eleptr->NumSubCommands,
               CommandInfoSize,(xdrproc_t) xdr_CommandInfo);
}

extern void *AllocCommandInfo()
{
     return((void *) AllocateCommandInfo);
}
