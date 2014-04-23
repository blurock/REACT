
extern CHAR *GetNameRegressionStat(RegressionStat *str)
{
     return(str->Name);
}

extern INT GetIDRegressionStat(RegressionStat *str)
{
     return(str->ID);
}

extern RegressionStat *CreateRegressionStat(RegressionStat *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  NumberOfVariables,
                                     INT *VariableSet,
                                     INT  DegreesOfFreedom,
                                     FLOAT  SError,
                                     DataSubSet *Outliers,
                                     FLOAT  FStat,
                                     FLAG  Allowed)
{
INT *oldVariableSet,*newVariableSet;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfVariables = NumberOfVariables;
     newstruct->DegreesOfFreedom = DegreesOfFreedom;
     newstruct->SError = SError;
     newstruct->FStat = FStat;
     newstruct->Allowed = Allowed;
     if(Outliers != 0)
          {
          newstruct->Outliers = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->Outliers, Outliers);
          }
     else
          newstruct->Outliers = 0;

     newstruct->VariableSet = AllocArrayINT(newstruct->NumberOfVariables);
     if(VariableSet != 0)
          {
          oldVariableSet = VariableSet;
          newVariableSet = newstruct->VariableSet;
          LOOPi(newstruct->NumberOfVariables)
               CopyFullINT(newVariableSet++, oldVariableSet++);
          }



     return(newstruct);
}


extern void CopyFullRegressionStat(RegressionStat *newstruct, RegressionStat *oldstruct)
{
INT *oldVariableSet,*newVariableSet;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfVariables = oldstruct->NumberOfVariables;
     newstruct->DegreesOfFreedom = oldstruct->DegreesOfFreedom;
     newstruct->SError = oldstruct->SError;
     newstruct->FStat = oldstruct->FStat;
     newstruct->Allowed = oldstruct->Allowed;

     if(oldstruct->Outliers != 0)
          {
          newstruct->Outliers = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->Outliers, oldstruct->Outliers);
          }
     else
          newstruct->Outliers = 0;

     newstruct->VariableSet = AllocArrayINT(newstruct->NumberOfVariables);
     if(oldstruct->VariableSet != 0)
          {
          oldVariableSet = oldstruct->VariableSet;
          newVariableSet = newstruct->VariableSet;
          LOOPi(newstruct->NumberOfVariables)
               CopyFullINT(newVariableSet++, oldVariableSet++);
          }


}
extern void PrintRegressionStat(RegressionStat *eleptr)
{
INT *ptrVariableSet;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number of Variables Removed:");
     printf("%d\n",eleptr->NumberOfVariables);
     printf("The Number of Degrees of Freedom:");
     printf("%d\n",eleptr->DegreesOfFreedom);
     printf("     The total error:");
     printf("%f\n",eleptr->SError);
     printf("     The F-Statistic:");
     printf("%f\n",eleptr->FStat);

     printf("The set of points over the maximum allowed error:\n");
     PrintDataSubSet(eleptr->Outliers);

     printf("The variable numbers of those removed:\n");
     if(eleptr->VariableSet != 0)
          {
          ptrVariableSet = eleptr->VariableSet;
          LOOPi(eleptr->NumberOfVariables)
               PrintINT(ptrVariableSet++);
          }


}
extern void FreeRegressionStat(RegressionStat *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->VariableSet);

     FreeDataSubSet(eleptr->Outliers);
     Free(eleptr->Outliers);

}
extern void WriteBinRegressionStat(RegressionStat *eleptr, DbaseLinkedList *file)
{
INT *ptrVariableSet;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfVariables),file);
     WriteBinINT(&(eleptr->DegreesOfFreedom),file);
     WriteBinFLOAT(&(eleptr->SError),file);
     WriteBinFLOAT(&(eleptr->FStat),file);

     WriteBinDataSubSet(eleptr->Outliers,file);

     if(eleptr->VariableSet != 0)
          {
          ptrVariableSet = eleptr->VariableSet;
          LOOPi(eleptr->NumberOfVariables)
               WriteBinINT(ptrVariableSet++,file);
          }

}
extern INT ReadBinRegressionStat(RegressionStat *eleptr,DbaseLinkedList *file)
     {
INT *ptrVariableSet;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfVariables),file);
     ReadBinINT(&(eleptr->DegreesOfFreedom),file);
     ReadBinFLOAT(&(eleptr->SError),file);
     ReadBinFLOAT(&(eleptr->FStat),file);

     eleptr->Outliers = AllocateDataSubSet;
     if(ReadBinDataSubSet(eleptr->Outliers,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Outliers);
           eleptr->Outliers = 0;
           }

          eleptr->VariableSet = AllocArrayINT(eleptr->NumberOfVariables);
          ptrVariableSet = eleptr->VariableSet;
          LOOPi(eleptr->NumberOfVariables)
               ReadBinINT(ptrVariableSet++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_RegressionStat(XDR *stream, char **eleptrp)
{
     RegressionStat *eleptr;
     eleptr = (RegressionStat *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfVariables));
     xdr_INT(stream,(char **) &(eleptr->DegreesOfFreedom));
     xdr_FLOAT(stream,(char **) &(eleptr->SError));
     xdr_FLOAT(stream,(char **) &(eleptr->FStat));

     xdr_pointer(stream,
          (char **) &(eleptr->Outliers),
          DataSubSetSize,
                 (xdrproc_t) xdr_DataSubSet);
     xdr_array(stream,(char **) &(eleptr->VariableSet),
             (uint *) &(eleptr->NumberOfVariables),eleptr->NumberOfVariables,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocRegressionStat()
{
     return((void *) AllocateRegressionStat);
}

extern CHAR *GetNameRegression(Regression *str)
{
     return(str->Name);
}

extern INT GetIDRegression(Regression *str)
{
     return(str->ID);
}

extern Regression *CreateRegression(Regression *newstruct,
                             INT id,
                             CHAR *name,
                             INT  NumberOfVariables,
                             INT *Variables,
                             INT  ResultVariable,
                             DataSubSet *Points,
                             FLOAT  AllowedError,
                             DataSubSet *Outliers,
                             FLOAT  TotalError,
                             FullMatrixFLT *Coefficients,
                             INT  SysSamVectorSetID)
{
INT *oldVariables,*newVariables;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfVariables = NumberOfVariables;
     newstruct->ResultVariable = ResultVariable;
     newstruct->AllowedError = AllowedError;
     newstruct->TotalError = TotalError;
     newstruct->SysSamVectorSetID = SysSamVectorSetID;
     if(Points != 0)
          {
          newstruct->Points = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->Points, Points);
          }
     else
          newstruct->Points = 0;
     if(Outliers != 0)
          {
          newstruct->Outliers = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->Outliers, Outliers);
          }
     else
          newstruct->Outliers = 0;
     if(Coefficients != 0)
          {
          newstruct->Coefficients = AllocateFullMatrixFLT;
          CopyFullFullMatrixFLT(newstruct->Coefficients, Coefficients);
          }
     else
          newstruct->Coefficients = 0;

     newstruct->Variables = AllocArrayINT(newstruct->NumberOfVariables);
     if(Variables != 0)
          {
          oldVariables = Variables;
          newVariables = newstruct->Variables;
          LOOPi(newstruct->NumberOfVariables)
               CopyFullINT(newVariables++, oldVariables++);
          }



     return(newstruct);
}


extern void CopyFullRegression(Regression *newstruct, Regression *oldstruct)
{
INT *oldVariables,*newVariables;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfVariables = oldstruct->NumberOfVariables;
     newstruct->ResultVariable = oldstruct->ResultVariable;
     newstruct->AllowedError = oldstruct->AllowedError;
     newstruct->TotalError = oldstruct->TotalError;
     newstruct->SysSamVectorSetID = oldstruct->SysSamVectorSetID;

     if(oldstruct->Points != 0)
          {
          newstruct->Points = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->Points, oldstruct->Points);
          }
     else
          newstruct->Points = 0;
     if(oldstruct->Outliers != 0)
          {
          newstruct->Outliers = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->Outliers, oldstruct->Outliers);
          }
     else
          newstruct->Outliers = 0;
     if(oldstruct->Coefficients != 0)
          {
          newstruct->Coefficients = AllocateFullMatrixFLT;
          CopyFullFullMatrixFLT(newstruct->Coefficients, oldstruct->Coefficients);
          }
     else
          newstruct->Coefficients = 0;

     newstruct->Variables = AllocArrayINT(newstruct->NumberOfVariables);
     if(oldstruct->Variables != 0)
          {
          oldVariables = oldstruct->Variables;
          newVariables = newstruct->Variables;
          LOOPi(newstruct->NumberOfVariables)
               CopyFullINT(newVariables++, oldVariables++);
          }


}
extern void PrintRegression(Regression *eleptr)
{
INT *ptrVariables;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number Of Variables:");
     printf("%d\n",eleptr->NumberOfVariables);
     printf("The Variable Number to Predict:");
     printf("%d\n",eleptr->ResultVariable);
     printf("The Maximum Allowed Error:");
     printf("%f\n",eleptr->AllowedError);
     printf("     The Total Error:");
     printf("%f\n",eleptr->TotalError);
     printf("The SysSamVectorSet ID:");
     printf("%d\n",eleptr->SysSamVectorSetID);

     printf("The Set of DataPoints:\n");
     PrintDataSubSet(eleptr->Points);

     printf("The Set of Points over this error:\n");
     PrintDataSubSet(eleptr->Outliers);

     printf("    The Coefficients:\n");
     PrintFullMatrixFLT(eleptr->Coefficients);

     printf("The Set of Variable Numbers:\n");
     if(eleptr->Variables != 0)
          {
          ptrVariables = eleptr->Variables;
          LOOPi(eleptr->NumberOfVariables)
               PrintINT(ptrVariables++);
          }


}
extern void FreeRegression(Regression *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Variables);

     FreeDataSubSet(eleptr->Points);
     Free(eleptr->Points);

     FreeDataSubSet(eleptr->Outliers);
     Free(eleptr->Outliers);

     FreeFullMatrixFLT(eleptr->Coefficients);
     Free(eleptr->Coefficients);

}
extern void WriteBinRegression(Regression *eleptr, DbaseLinkedList *file)
{
INT *ptrVariables;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfVariables),file);
     WriteBinINT(&(eleptr->ResultVariable),file);
     WriteBinFLOAT(&(eleptr->AllowedError),file);
     WriteBinFLOAT(&(eleptr->TotalError),file);
     WriteBinINT(&(eleptr->SysSamVectorSetID),file);

     WriteBinDataSubSet(eleptr->Points,file);

     WriteBinDataSubSet(eleptr->Outliers,file);

     WriteBinFullMatrixFLT(eleptr->Coefficients,file);

     if(eleptr->Variables != 0)
          {
          ptrVariables = eleptr->Variables;
          LOOPi(eleptr->NumberOfVariables)
               WriteBinINT(ptrVariables++,file);
          }

}
extern INT ReadBinRegression(Regression *eleptr,DbaseLinkedList *file)
     {
INT *ptrVariables;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfVariables),file);
     ReadBinINT(&(eleptr->ResultVariable),file);
     ReadBinFLOAT(&(eleptr->AllowedError),file);
     ReadBinFLOAT(&(eleptr->TotalError),file);
     ReadBinINT(&(eleptr->SysSamVectorSetID),file);

     eleptr->Points = AllocateDataSubSet;
     if(ReadBinDataSubSet(eleptr->Points,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Points);
           eleptr->Points = 0;
           }

     eleptr->Outliers = AllocateDataSubSet;
     if(ReadBinDataSubSet(eleptr->Outliers,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Outliers);
           eleptr->Outliers = 0;
           }

     eleptr->Coefficients = AllocateFullMatrixFLT;
     if(ReadBinFullMatrixFLT(eleptr->Coefficients,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Coefficients);
           eleptr->Coefficients = 0;
           }

          eleptr->Variables = AllocArrayINT(eleptr->NumberOfVariables);
          ptrVariables = eleptr->Variables;
          LOOPi(eleptr->NumberOfVariables)
               ReadBinINT(ptrVariables++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_Regression(XDR *stream, char **eleptrp)
{
     Regression *eleptr;
     eleptr = (Regression *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfVariables));
     xdr_INT(stream,(char **) &(eleptr->ResultVariable));
     xdr_FLOAT(stream,(char **) &(eleptr->AllowedError));
     xdr_FLOAT(stream,(char **) &(eleptr->TotalError));
     xdr_INT(stream,(char **) &(eleptr->SysSamVectorSetID));

     xdr_pointer(stream,
          (char **) &(eleptr->Points),
          DataSubSetSize,
                 (xdrproc_t) xdr_DataSubSet);
     xdr_pointer(stream,
          (char **) &(eleptr->Outliers),
          DataSubSetSize,
                 (xdrproc_t) xdr_DataSubSet);
     xdr_pointer(stream,
          (char **) &(eleptr->Coefficients),
          FullMatrixFLTSize,
                 (xdrproc_t) xdr_FullMatrixFLT);
     xdr_array(stream,(char **) &(eleptr->Variables),
             (uint *) &(eleptr->NumberOfVariables),eleptr->NumberOfVariables,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocRegression()
{
     return((void *) AllocateRegression);
}

extern CHAR *GetNameRegressionSet(RegressionSet *str)
{
     return(str->Name);
}

extern INT GetIDRegressionSet(RegressionSet *str)
{
     return(str->ID);
}

extern RegressionSet *CreateRegressionSet(RegressionSet *newstruct,
                                   INT id,
                                   CHAR *name,
                                   Regression *Original,
                                   INT  NumberOfReductions,
                                   RegressionStat *SetOfReductions)
{
RegressionStat *oldSetOfReductions,*newSetOfReductions;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfReductions = NumberOfReductions;
     if(Original != 0)
          {
          newstruct->Original = AllocateRegression;
          CopyFullRegression(newstruct->Original, Original);
          }
     else
          newstruct->Original = 0;

     newstruct->SetOfReductions = AllocArrayRegressionStat(newstruct->NumberOfReductions);
     if(SetOfReductions != 0)
          {
          oldSetOfReductions = SetOfReductions;
          newSetOfReductions = newstruct->SetOfReductions;
          LOOPi(newstruct->NumberOfReductions)
               CopyFullRegressionStat(newSetOfReductions++, oldSetOfReductions++);
          }



     return(newstruct);
}


extern void CopyFullRegressionSet(RegressionSet *newstruct, RegressionSet *oldstruct)
{
RegressionStat *oldSetOfReductions,*newSetOfReductions;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfReductions = oldstruct->NumberOfReductions;

     if(oldstruct->Original != 0)
          {
          newstruct->Original = AllocateRegression;
          CopyFullRegression(newstruct->Original, oldstruct->Original);
          }
     else
          newstruct->Original = 0;

     newstruct->SetOfReductions = AllocArrayRegressionStat(newstruct->NumberOfReductions);
     if(oldstruct->SetOfReductions != 0)
          {
          oldSetOfReductions = oldstruct->SetOfReductions;
          newSetOfReductions = newstruct->SetOfReductions;
          LOOPi(newstruct->NumberOfReductions)
               CopyFullRegressionStat(newSetOfReductions++, oldSetOfReductions++);
          }


}
extern void PrintRegressionSet(RegressionSet *eleptr)
{
RegressionStat *ptrSetOfReductions;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number of Reductions:");
     printf("%d\n",eleptr->NumberOfReductions);

     printf("The Original Regression:\n");
     PrintRegression(eleptr->Original);

     printf("The Set of Reductions:\n");
     if(eleptr->SetOfReductions != 0)
          {
          ptrSetOfReductions = eleptr->SetOfReductions;
          LOOPi(eleptr->NumberOfReductions)
               PrintRegressionStat(ptrSetOfReductions++);
          }


}
extern void FreeRegressionSet(RegressionSet *eleptr)
{
RegressionStat *ptrSetOfReductions;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrSetOfReductions = eleptr->SetOfReductions;
     LOOPi(eleptr->NumberOfReductions)
          FreeRegressionStat(ptrSetOfReductions++);
     Free(eleptr->SetOfReductions);

     FreeRegression(eleptr->Original);
     Free(eleptr->Original);

}
extern void WriteBinRegressionSet(RegressionSet *eleptr, DbaseLinkedList *file)
{
RegressionStat *ptrSetOfReductions;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfReductions),file);

     WriteBinRegression(eleptr->Original,file);

     if(eleptr->SetOfReductions != 0)
          {
          ptrSetOfReductions = eleptr->SetOfReductions;
          LOOPi(eleptr->NumberOfReductions)
               WriteBinRegressionStat(ptrSetOfReductions++,file);
          }

}
extern INT ReadBinRegressionSet(RegressionSet *eleptr,DbaseLinkedList *file)
     {
RegressionStat *ptrSetOfReductions;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfReductions),file);

     eleptr->Original = AllocateRegression;
     if(ReadBinRegression(eleptr->Original,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Original);
           eleptr->Original = 0;
           }

          eleptr->SetOfReductions = AllocArrayRegressionStat(eleptr->NumberOfReductions);
          ptrSetOfReductions = eleptr->SetOfReductions;
          LOOPi(eleptr->NumberOfReductions)
               ReadBinRegressionStat(ptrSetOfReductions++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_RegressionSet(XDR *stream, char **eleptrp)
{
     RegressionSet *eleptr;
     eleptr = (RegressionSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfReductions));

     xdr_pointer(stream,
          (char **) &(eleptr->Original),
          RegressionSize,
                 (xdrproc_t) xdr_Regression);
     xdr_array(stream,(char **) &(eleptr->SetOfReductions),
             (uint *) &(eleptr->NumberOfReductions),eleptr->NumberOfReductions,
               RegressionStatSize,(xdrproc_t) xdr_RegressionStat);
}

extern void *AllocRegressionSet()
{
     return((void *) AllocateRegressionSet);
}
