
extern CHAR *GetNameDatMatConstants(DatMatConstants *str)
{
     return(str->Name);
}

extern INT GetIDDatMatConstants(DatMatConstants *str)
{
     return(str->ID);
}

extern DatMatConstants *CreateDatMatConstants(DatMatConstants *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  ReadDebug,
                                       INT  MaxNames,
                                       INT  GoalMissing,
                                       STRING *SubSetRanges,
                                       INT  SubSetNumRanges,
                                       INT  TrainPercent,
                                       INT  RandomPercent,
                                       STRING *DataDirectory,
                                       STRING *VarDirectory,
                                       INT  LatexPrint,
                                       STRING *ControlFile,
                                       STRING *DescrList,
                                       STRING *GoalList)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->ReadDebug = ReadDebug;
     newstruct->MaxNames = MaxNames;
     newstruct->GoalMissing = GoalMissing;
     newstruct->SubSetNumRanges = SubSetNumRanges;
     newstruct->TrainPercent = TrainPercent;
     newstruct->RandomPercent = RandomPercent;
     newstruct->LatexPrint = LatexPrint;
     if(SubSetRanges != 0)
          {
          newstruct->SubSetRanges = AllocateSTRING;
          CopyFullSTRING(newstruct->SubSetRanges, SubSetRanges);
          }
     else
          newstruct->SubSetRanges = 0;
     if(DataDirectory != 0)
          {
          newstruct->DataDirectory = AllocateSTRING;
          CopyFullSTRING(newstruct->DataDirectory, DataDirectory);
          }
     else
          newstruct->DataDirectory = 0;
     if(VarDirectory != 0)
          {
          newstruct->VarDirectory = AllocateSTRING;
          CopyFullSTRING(newstruct->VarDirectory, VarDirectory);
          }
     else
          newstruct->VarDirectory = 0;
     if(ControlFile != 0)
          {
          newstruct->ControlFile = AllocateSTRING;
          CopyFullSTRING(newstruct->ControlFile, ControlFile);
          }
     else
          newstruct->ControlFile = 0;
     if(DescrList != 0)
          {
          newstruct->DescrList = AllocateSTRING;
          CopyFullSTRING(newstruct->DescrList, DescrList);
          }
     else
          newstruct->DescrList = 0;
     if(GoalList != 0)
          {
          newstruct->GoalList = AllocateSTRING;
          CopyFullSTRING(newstruct->GoalList, GoalList);
          }
     else
          newstruct->GoalList = 0;



     return(newstruct);
}


extern void CopyFullDatMatConstants(DatMatConstants *newstruct, DatMatConstants *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->ReadDebug = oldstruct->ReadDebug;
     newstruct->MaxNames = oldstruct->MaxNames;
     newstruct->DescriptorMissing = oldstruct->DescriptorMissing;
     newstruct->GoalMissing = oldstruct->GoalMissing;
     newstruct->SubSetNumRanges = oldstruct->SubSetNumRanges;
     newstruct->TrainPercent = oldstruct->TrainPercent;
     newstruct->RandomPercent = oldstruct->RandomPercent;
     newstruct->LatexPrint = oldstruct->LatexPrint;

     if(oldstruct->SubSetRanges != 0)
          {
          newstruct->SubSetRanges = AllocateSTRING;
          CopyFullSTRING(newstruct->SubSetRanges, oldstruct->SubSetRanges);
          }
     else
          newstruct->SubSetRanges = 0;
     if(oldstruct->DataDirectory != 0)
          {
          newstruct->DataDirectory = AllocateSTRING;
          CopyFullSTRING(newstruct->DataDirectory, oldstruct->DataDirectory);
          }
     else
          newstruct->DataDirectory = 0;
     if(oldstruct->VarDirectory != 0)
          {
          newstruct->VarDirectory = AllocateSTRING;
          CopyFullSTRING(newstruct->VarDirectory, oldstruct->VarDirectory);
          }
     else
          newstruct->VarDirectory = 0;
     if(oldstruct->ControlFile != 0)
          {
          newstruct->ControlFile = AllocateSTRING;
          CopyFullSTRING(newstruct->ControlFile, oldstruct->ControlFile);
          }
     else
          newstruct->ControlFile = 0;
     if(oldstruct->DescrList != 0)
          {
          newstruct->DescrList = AllocateSTRING;
          CopyFullSTRING(newstruct->DescrList, oldstruct->DescrList);
          }
     else
          newstruct->DescrList = 0;
     if(oldstruct->GoalList != 0)
          {
          newstruct->GoalList = AllocateSTRING;
          CopyFullSTRING(newstruct->GoalList, oldstruct->GoalList);
          }
     else
          newstruct->GoalList = 0;


}
extern void PrintDatMatConstants(DatMatConstants *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("      The Debug Flag:");
     printf("%d\n",eleptr->ReadDebug);
     printf("The Maximum number of variable names:");
     printf("%d\n",eleptr->MaxNames);
     printf("Flag to eliminate Missing Descriptor points:");
     printf("%d\n",eleptr->DescriptorMissing);
     printf("Flag to eliminate missing Goal points:");
     printf("%d\n",eleptr->GoalMissing);
     printf("The maximum number of ranges allowed:");
     printf("%d\n",eleptr->SubSetNumRanges);
     printf("The Percent of points to be used for training:");
     printf("%d\n",eleptr->TrainPercent);
     printf("The Percent of random points:");
     printf("%d\n",eleptr->RandomPercent);
     printf("Print as latex document:");
     printf("%d\n",eleptr->LatexPrint);

     printf("The set of Ranges to use (as a string):\n");
     PrintSTRING(eleptr->SubSetRanges);

     printf("The Default Data Directory:\n");
     PrintSTRING(eleptr->DataDirectory);

     printf("The Default Variable Directory:\n");
     PrintSTRING(eleptr->VarDirectory);

     printf("The ControlFile Name:\n");
     PrintSTRING(eleptr->ControlFile);

     printf("The Name of the Descriptor List:\n");
     PrintSTRING(eleptr->DescrList);

     printf("The Name of the GoalList:\n");
     PrintSTRING(eleptr->GoalList);

}
extern void FreeDatMatConstants(DatMatConstants *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeSTRING(eleptr->SubSetRanges);

     FreeSTRING(eleptr->DataDirectory);

     FreeSTRING(eleptr->VarDirectory);

     FreeSTRING(eleptr->ControlFile);

     FreeSTRING(eleptr->DescrList);

     FreeSTRING(eleptr->GoalList);

}
extern void WriteBinDatMatConstants(DatMatConstants *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->ReadDebug),file);
     WriteBinINT(&(eleptr->MaxNames),file);
     WriteBinINT(&(eleptr->DescriptorMissing),file);
     WriteBinINT(&(eleptr->GoalMissing),file);
     WriteBinINT(&(eleptr->SubSetNumRanges),file);
     WriteBinINT(&(eleptr->TrainPercent),file);
     WriteBinINT(&(eleptr->RandomPercent),file);
     WriteBinINT(&(eleptr->LatexPrint),file);

     WriteBinSTRING(eleptr->SubSetRanges,file);

     WriteBinSTRING(eleptr->DataDirectory,file);

     WriteBinSTRING(eleptr->VarDirectory,file);

     WriteBinSTRING(eleptr->ControlFile,file);

     WriteBinSTRING(eleptr->DescrList,file);

     WriteBinSTRING(eleptr->GoalList,file);

}
extern INT ReadBinDatMatConstants(DatMatConstants *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->ReadDebug),file);
     ReadBinINT(&(eleptr->MaxNames),file);
     ReadBinINT(&(eleptr->DescriptorMissing),file);
     ReadBinINT(&(eleptr->GoalMissing),file);
     ReadBinINT(&(eleptr->SubSetNumRanges),file);
     ReadBinINT(&(eleptr->TrainPercent),file);
     ReadBinINT(&(eleptr->RandomPercent),file);
     ReadBinINT(&(eleptr->LatexPrint),file);

     eleptr->SubSetRanges = AllocateSTRING;
     if(ReadBinSTRING(eleptr->SubSetRanges,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->SubSetRanges);
           eleptr->SubSetRanges = 0;
           }

     eleptr->DataDirectory = AllocateSTRING;
     if(ReadBinSTRING(eleptr->DataDirectory,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->DataDirectory);
           eleptr->DataDirectory = 0;
           }

     eleptr->VarDirectory = AllocateSTRING;
     if(ReadBinSTRING(eleptr->VarDirectory,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->VarDirectory);
           eleptr->VarDirectory = 0;
           }

     eleptr->ControlFile = AllocateSTRING;
     if(ReadBinSTRING(eleptr->ControlFile,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->ControlFile);
           eleptr->ControlFile = 0;
           }

     eleptr->DescrList = AllocateSTRING;
     if(ReadBinSTRING(eleptr->DescrList,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->DescrList);
           eleptr->DescrList = 0;
           }

     eleptr->GoalList = AllocateSTRING;
     if(ReadBinSTRING(eleptr->GoalList,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->GoalList);
           eleptr->GoalList = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_DatMatConstants(XDR *stream, char **eleptrp)
{
     DatMatConstants *eleptr;
     eleptr = (DatMatConstants *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->ReadDebug));
     xdr_INT(stream,(char **) &(eleptr->MaxNames));
     xdr_INT(stream,(char **) &(eleptr->DescriptorMissing));
     xdr_INT(stream,(char **) &(eleptr->GoalMissing));
     xdr_INT(stream,(char **) &(eleptr->SubSetNumRanges));
     xdr_INT(stream,(char **) &(eleptr->TrainPercent));
     xdr_INT(stream,(char **) &(eleptr->RandomPercent));
     xdr_INT(stream,(char **) &(eleptr->LatexPrint));

     xdr_pointer(stream,
          (char **) &(eleptr->SubSetRanges),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_pointer(stream,
          (char **) &(eleptr->DataDirectory),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_pointer(stream,
          (char **) &(eleptr->VarDirectory),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_pointer(stream,
          (char **) &(eleptr->ControlFile),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_pointer(stream,
          (char **) &(eleptr->DescrList),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_pointer(stream,
          (char **) &(eleptr->GoalList),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
}

extern void *AllocDatMatConstants()
{
     return((void *) AllocateDatMatConstants);
}

extern CHAR *GetNameDatMatMaster(DatMatMaster *str)
{
     return(str->Name);
}

extern INT GetIDDatMatMaster(DatMatMaster *str)
{
     return(str->ID);
}

extern DatMatMaster *CreateDatMatMaster(DatMatMaster *newstruct,
                                 INT id,
                                 CHAR *name,
                                 SysSamVectorSet *SysSamVectorSetElement,
                                 DataSubSet *DataSubSetStandard,
                                 DataSubSet *DataSubSetElement,
                                 SystemVariablePair *SystemVariablePairElement,
                                 DataTestBlock *DataTestBlockElement,
                                 DatMatConstants *Constants)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(SysSamVectorSetElement != 0)
          {
          newstruct->SysSamVectorSetElement = AllocateSysSamVectorSet;
          CopyFullSysSamVectorSet(newstruct->SysSamVectorSetElement, SysSamVectorSetElement);
          }
     else
          newstruct->SysSamVectorSetElement = 0;
     if(DataSubSetStandard != 0)
          {
          newstruct->DataSubSetStandard = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->DataSubSetStandard, DataSubSetStandard);
          }
     else
          newstruct->DataSubSetStandard = 0;
     if(DataSubSetElement != 0)
          {
          newstruct->DataSubSetElement = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->DataSubSetElement, DataSubSetElement);
          }
     else
          newstruct->DataSubSetElement = 0;
     if(SystemVariablePairElement != 0)
          {
          newstruct->SystemVariablePairElement = AllocateSystemVariablePair;
          CopyFullSystemVariablePair(newstruct->SystemVariablePairElement, SystemVariablePairElement);
          }
     else
          newstruct->SystemVariablePairElement = 0;
     if(DataTestBlockElement != 0)
          {
          newstruct->DataTestBlockElement = AllocateDataTestBlock;
          CopyFullDataTestBlock(newstruct->DataTestBlockElement, DataTestBlockElement);
          }
     else
          newstruct->DataTestBlockElement = 0;
     if(Constants != 0)
          {
          newstruct->Constants = AllocateDatMatConstants;
          CopyFullDatMatConstants(newstruct->Constants, Constants);
          }
     else
          newstruct->Constants = 0;



     return(newstruct);
}


extern void CopyFullDatMatMaster(DatMatMaster *newstruct, DatMatMaster *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->SysSamVectorSetElement != 0)
          {
          newstruct->SysSamVectorSetElement = AllocateSysSamVectorSet;
          CopyFullSysSamVectorSet(newstruct->SysSamVectorSetElement, oldstruct->SysSamVectorSetElement);
          }
     else
          newstruct->SysSamVectorSetElement = 0;
     if(oldstruct->DataSubSetStandard != 0)
          {
          newstruct->DataSubSetStandard = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->DataSubSetStandard, oldstruct->DataSubSetStandard);
          }
     else
          newstruct->DataSubSetStandard = 0;
     if(oldstruct->DataSubSetElement != 0)
          {
          newstruct->DataSubSetElement = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->DataSubSetElement, oldstruct->DataSubSetElement);
          }
     else
          newstruct->DataSubSetElement = 0;
     if(oldstruct->SystemVariablePairElement != 0)
          {
          newstruct->SystemVariablePairElement = AllocateSystemVariablePair;
          CopyFullSystemVariablePair(newstruct->SystemVariablePairElement, oldstruct->SystemVariablePairElement);
          }
     else
          newstruct->SystemVariablePairElement = 0;
     if(oldstruct->DataTestBlockElement != 0)
          {
          newstruct->DataTestBlockElement = AllocateDataTestBlock;
          CopyFullDataTestBlock(newstruct->DataTestBlockElement, oldstruct->DataTestBlockElement);
          }
     else
          newstruct->DataTestBlockElement = 0;
     if(oldstruct->Constants != 0)
          {
          newstruct->Constants = AllocateDatMatConstants;
          CopyFullDatMatConstants(newstruct->Constants, oldstruct->Constants);
          }
     else
          newstruct->Constants = 0;


}
extern void PrintDatMatMaster(DatMatMaster *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("     The Data Points:\n");
     PrintSysSamVectorSet(eleptr->SysSamVectorSetElement);

     printf("    The Raw Data Set:\n");
     PrintDataSubSet(eleptr->DataSubSetStandard);

     printf("The Current DataSubSet:\n");
     PrintDataSubSet(eleptr->DataSubSetElement);

     printf("The Set of Variables to use:\n");
     PrintSystemVariablePair(eleptr->SystemVariablePairElement);

     printf("The Test and Training SubSets:\n");
     PrintDataTestBlock(eleptr->DataTestBlockElement);

     printf("The set of constants to be used:\n");
     PrintDatMatConstants(eleptr->Constants);

}
extern void FreeDatMatMaster(DatMatMaster *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeSysSamVectorSet(eleptr->SysSamVectorSetElement);
     Free(eleptr->SysSamVectorSetElement);

     FreeDataSubSet(eleptr->DataSubSetStandard);
     Free(eleptr->DataSubSetStandard);

     FreeDataSubSet(eleptr->DataSubSetElement);
     Free(eleptr->DataSubSetElement);

     FreeSystemVariablePair(eleptr->SystemVariablePairElement);
     Free(eleptr->SystemVariablePairElement);

     FreeDataTestBlock(eleptr->DataTestBlockElement);
     Free(eleptr->DataTestBlockElement);

     FreeDatMatConstants(eleptr->Constants);
     Free(eleptr->Constants);

}
extern void WriteBinDatMatMaster(DatMatMaster *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinSysSamVectorSet(eleptr->SysSamVectorSetElement,file);

     WriteBinDataSubSet(eleptr->DataSubSetStandard,file);

     WriteBinDataSubSet(eleptr->DataSubSetElement,file);

     WriteBinSystemVariablePair(eleptr->SystemVariablePairElement,file);

     WriteBinDataTestBlock(eleptr->DataTestBlockElement,file);

     WriteBinDatMatConstants(eleptr->Constants,file);

}
extern INT ReadBinDatMatMaster(DatMatMaster *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->SysSamVectorSetElement = AllocateSysSamVectorSet;
     if(ReadBinSysSamVectorSet(eleptr->SysSamVectorSetElement,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->SysSamVectorSetElement);
           eleptr->SysSamVectorSetElement = 0;
           }

     eleptr->DataSubSetStandard = AllocateDataSubSet;
     if(ReadBinDataSubSet(eleptr->DataSubSetStandard,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->DataSubSetStandard);
           eleptr->DataSubSetStandard = 0;
           }

     eleptr->DataSubSetElement = AllocateDataSubSet;
     if(ReadBinDataSubSet(eleptr->DataSubSetElement,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->DataSubSetElement);
           eleptr->DataSubSetElement = 0;
           }

     eleptr->SystemVariablePairElement = AllocateSystemVariablePair;
     if(ReadBinSystemVariablePair(eleptr->SystemVariablePairElement,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->SystemVariablePairElement);
           eleptr->SystemVariablePairElement = 0;
           }

     eleptr->DataTestBlockElement = AllocateDataTestBlock;
     if(ReadBinDataTestBlock(eleptr->DataTestBlockElement,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->DataTestBlockElement);
           eleptr->DataTestBlockElement = 0;
           }

     eleptr->Constants = AllocateDatMatConstants;
     if(ReadBinDatMatConstants(eleptr->Constants,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Constants);
           eleptr->Constants = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_DatMatMaster(XDR *stream, char **eleptrp)
{
     DatMatMaster *eleptr;
     eleptr = (DatMatMaster *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->SysSamVectorSetElement),
          SysSamVectorSetSize,
                 (xdrproc_t) xdr_SysSamVectorSet);
     xdr_pointer(stream,
          (char **) &(eleptr->DataSubSetStandard),
          DataSubSetSize,
                 (xdrproc_t) xdr_DataSubSet);
     xdr_pointer(stream,
          (char **) &(eleptr->DataSubSetElement),
          DataSubSetSize,
                 (xdrproc_t) xdr_DataSubSet);
     xdr_pointer(stream,
          (char **) &(eleptr->SystemVariablePairElement),
          SystemVariablePairSize,
                 (xdrproc_t) xdr_SystemVariablePair);
     xdr_pointer(stream,
          (char **) &(eleptr->DataTestBlockElement),
          DataTestBlockSize,
                 (xdrproc_t) xdr_DataTestBlock);
     xdr_pointer(stream,
          (char **) &(eleptr->Constants),
          DatMatConstantsSize,
                 (xdrproc_t) xdr_DatMatConstants);
}

extern void *AllocDatMatMaster()
{
     return((void *) AllocateDatMatMaster);
}

extern CHAR *GetNameGoalValueElements(GoalValueElements *str)
{
     return(str->Name);
}

extern INT GetIDGoalValueElements(GoalValueElements *str)
{
     return(str->ID);
}

extern GoalValueElements *CreateGoalValueElements(GoalValueElements *newstruct,
                                           INT id,
                                           CHAR *name,
                                           INT  NumberOfValues,
                                           BaseType *Values,
                                           FLOAT *FValues)
{
BaseType *oldValues,*newValues;
FLOAT *oldFValues,*newFValues;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfValues = NumberOfValues;

     newstruct->Values = AllocArrayBaseType(newstruct->NumberOfValues);
     if(Values != 0)
          {
          oldValues = Values;
          newValues = newstruct->Values;
          LOOPi(newstruct->NumberOfValues)
               CopyFullBaseType(newValues++, oldValues++);
          }

     newstruct->FValues = AllocArrayFLOAT(newstruct->NumberOfValues);
     if(FValues != 0)
          {
          oldFValues = FValues;
          newFValues = newstruct->FValues;
          LOOPi(newstruct->NumberOfValues)
               CopyFullFLOAT(newFValues++, oldFValues++);
          }



     return(newstruct);
}


extern void CopyFullGoalValueElements(GoalValueElements *newstruct, GoalValueElements *oldstruct)
{
BaseType *oldValues,*newValues;
FLOAT *oldFValues,*newFValues;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfValues = oldstruct->NumberOfValues;


     newstruct->Values = AllocArrayBaseType(newstruct->NumberOfValues);
     if(oldstruct->Values != 0)
          {
          oldValues = oldstruct->Values;
          newValues = newstruct->Values;
          LOOPi(newstruct->NumberOfValues)
               CopyFullBaseType(newValues++, oldValues++);
          }

     newstruct->FValues = AllocArrayFLOAT(newstruct->NumberOfValues);
     if(oldstruct->FValues != 0)
          {
          oldFValues = oldstruct->FValues;
          newFValues = newstruct->FValues;
          LOOPi(newstruct->NumberOfValues)
               CopyFullFLOAT(newFValues++, oldFValues++);
          }


}
extern void PrintGoalValueElements(GoalValueElements *eleptr)
{
BaseType *ptrValues;
FLOAT *ptrFValues;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of values:");
     printf("%d\n",eleptr->NumberOfValues);

     printf("The Set of Values (as base types .. for printing):\n");
     if(eleptr->Values != 0)
          {
          ptrValues = eleptr->Values;
          LOOPi(eleptr->NumberOfValues)
               PrintBaseType(ptrValues++);
          }


     printf("The set of Values  (as floats .. for ordering):\n");
     if(eleptr->FValues != 0)
          {
          ptrFValues = eleptr->FValues;
          LOOPi(eleptr->NumberOfValues)
               PrintFLOAT(ptrFValues++);
          }


}
extern void FreeGoalValueElements(GoalValueElements *eleptr)
{
BaseType *ptrValues;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrValues = eleptr->Values;
     LOOPi(eleptr->NumberOfValues)
          FreeBaseType(ptrValues++);
     Free(eleptr->Values);

     Free(eleptr->FValues);

}
extern void WriteBinGoalValueElements(GoalValueElements *eleptr, DbaseLinkedList *file)
{
BaseType *ptrValues;
FLOAT *ptrFValues;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfValues),file);

     if(eleptr->Values != 0)
          {
          ptrValues = eleptr->Values;
          LOOPi(eleptr->NumberOfValues)
               WriteBinBaseType(ptrValues++,file);
          }

     if(eleptr->FValues != 0)
          {
          ptrFValues = eleptr->FValues;
          LOOPi(eleptr->NumberOfValues)
               WriteBinFLOAT(ptrFValues++,file);
          }

}
extern INT ReadBinGoalValueElements(GoalValueElements *eleptr,DbaseLinkedList *file)
     {
BaseType *ptrValues;
FLOAT *ptrFValues;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfValues),file);

          eleptr->Values = AllocArrayBaseType(eleptr->NumberOfValues);
          ptrValues = eleptr->Values;
          LOOPi(eleptr->NumberOfValues)
               ReadBinBaseType(ptrValues++,file);

          eleptr->FValues = AllocArrayFLOAT(eleptr->NumberOfValues);
          ptrFValues = eleptr->FValues;
          LOOPi(eleptr->NumberOfValues)
               ReadBinFLOAT(ptrFValues++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_GoalValueElements(XDR *stream, char **eleptrp)
{
     GoalValueElements *eleptr;
     eleptr = (GoalValueElements *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfValues));

     xdr_array(stream,(char **) &(eleptr->Values),
             (uint *) &(eleptr->NumberOfValues),eleptr->NumberOfValues,
               BaseTypeSize,(xdrproc_t) xdr_BaseType);
     xdr_array(stream,(char **) &(eleptr->FValues),
             (uint *) &(eleptr->NumberOfValues),eleptr->NumberOfValues,
               FLOATSize,(xdrproc_t) xdr_FLOAT);
}

extern void *AllocGoalValueElements()
{
     return((void *) AllocateGoalValueElements);
}

extern CHAR *GetNameDatMatGoalValues(DatMatGoalValues *str)
{
     return(str->Name);
}

extern INT GetIDDatMatGoalValues(DatMatGoalValues *str)
{
     return(str->ID);
}

extern DatMatGoalValues *CreateDatMatGoalValues(DatMatGoalValues *newstruct,
                                         INT id,
                                         CHAR *name,
                                         INT  NumberOfElements,
                                         GoalValueElements *Elements)
{
GoalValueElements *oldElements,*newElements;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfElements = NumberOfElements;

     newstruct->Elements = AllocArrayGoalValueElements(newstruct->NumberOfElements);
     if(Elements != 0)
          {
          oldElements = Elements;
          newElements = newstruct->Elements;
          LOOPi(newstruct->NumberOfElements)
               CopyFullGoalValueElements(newElements++, oldElements++);
          }



     return(newstruct);
}


extern void CopyFullDatMatGoalValues(DatMatGoalValues *newstruct, DatMatGoalValues *oldstruct)
{
GoalValueElements *oldElements,*newElements;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfElements = oldstruct->NumberOfElements;


     newstruct->Elements = AllocArrayGoalValueElements(newstruct->NumberOfElements);
     if(oldstruct->Elements != 0)
          {
          oldElements = oldstruct->Elements;
          newElements = newstruct->Elements;
          LOOPi(newstruct->NumberOfElements)
               CopyFullGoalValueElements(newElements++, oldElements++);
          }


}
extern void PrintDatMatGoalValues(DatMatGoalValues *eleptr)
{
GoalValueElements *ptrElements;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of elements:");
     printf("%d\n",eleptr->NumberOfElements);

     printf(" The set of elements:\n");
     if(eleptr->Elements != 0)
          {
          ptrElements = eleptr->Elements;
          LOOPi(eleptr->NumberOfElements)
               PrintGoalValueElements(ptrElements++);
          }


}
extern void FreeDatMatGoalValues(DatMatGoalValues *eleptr)
{
GoalValueElements *ptrElements;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrElements = eleptr->Elements;
     LOOPi(eleptr->NumberOfElements)
          FreeGoalValueElements(ptrElements++);
     Free(eleptr->Elements);

}
extern void WriteBinDatMatGoalValues(DatMatGoalValues *eleptr, DbaseLinkedList *file)
{
GoalValueElements *ptrElements;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfElements),file);

     if(eleptr->Elements != 0)
          {
          ptrElements = eleptr->Elements;
          LOOPi(eleptr->NumberOfElements)
               WriteBinGoalValueElements(ptrElements++,file);
          }

}
extern INT ReadBinDatMatGoalValues(DatMatGoalValues *eleptr,DbaseLinkedList *file)
     {
GoalValueElements *ptrElements;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfElements),file);

          eleptr->Elements = AllocArrayGoalValueElements(eleptr->NumberOfElements);
          ptrElements = eleptr->Elements;
          LOOPi(eleptr->NumberOfElements)
               ReadBinGoalValueElements(ptrElements++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_DatMatGoalValues(XDR *stream, char **eleptrp)
{
     DatMatGoalValues *eleptr;
     eleptr = (DatMatGoalValues *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfElements));

     xdr_array(stream,(char **) &(eleptr->Elements),
             (uint *) &(eleptr->NumberOfElements),eleptr->NumberOfElements,
               GoalValueElementsSize,(xdrproc_t) xdr_GoalValueElements);
}

extern void *AllocDatMatGoalValues()
{
     return((void *) AllocateDatMatGoalValues);
}
