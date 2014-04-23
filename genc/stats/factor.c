
extern CHAR *GetNameFactorAnalysis(FactorAnalysis *str)
{
     return(str->Name);
}

extern INT GetIDFactorAnalysis(FactorAnalysis *str)
{
     return(str->ID);
}

extern FactorAnalysis *CreateFactorAnalysis(FactorAnalysis *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  NumberOfFactors,
                                     FLOAT  Cutoff,
                                     FLOAT *Eigenvalues,
                                     FullMatrixFLT *Vector,
                                     FullMatrixFLT *Coordinates)
{
FLOAT *oldEigenvalues,*newEigenvalues;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfFactors = NumberOfFactors;
     newstruct->Cutoff = Cutoff;
     if(Vector != 0)
          {
          newstruct->Vector = AllocateFullMatrixFLT;
          CopyFullFullMatrixFLT(newstruct->Vector, Vector);
          }
     else
          newstruct->Vector = 0;
     if(Coordinates != 0)
          {
          newstruct->Coordinates = AllocateFullMatrixFLT;
          CopyFullFullMatrixFLT(newstruct->Coordinates, Coordinates);
          }
     else
          newstruct->Coordinates = 0;

     newstruct->Eigenvalues = AllocArrayFLOAT(newstruct->NumberOfFactors);
     if(Eigenvalues != 0)
          {
          oldEigenvalues = Eigenvalues;
          newEigenvalues = newstruct->Eigenvalues;
          LOOPi(newstruct->NumberOfFactors)
               CopyFullFLOAT(newEigenvalues++, oldEigenvalues++);
          }



     return(newstruct);
}


extern void CopyFullFactorAnalysis(FactorAnalysis *newstruct, FactorAnalysis *oldstruct)
{
FLOAT *oldEigenvalues,*newEigenvalues;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfFactors = oldstruct->NumberOfFactors;
     newstruct->Cutoff = oldstruct->Cutoff;

     if(oldstruct->Vector != 0)
          {
          newstruct->Vector = AllocateFullMatrixFLT;
          CopyFullFullMatrixFLT(newstruct->Vector, oldstruct->Vector);
          }
     else
          newstruct->Vector = 0;
     if(oldstruct->Coordinates != 0)
          {
          newstruct->Coordinates = AllocateFullMatrixFLT;
          CopyFullFullMatrixFLT(newstruct->Coordinates, oldstruct->Coordinates);
          }
     else
          newstruct->Coordinates = 0;

     newstruct->Eigenvalues = AllocArrayFLOAT(newstruct->NumberOfFactors);
     if(oldstruct->Eigenvalues != 0)
          {
          oldEigenvalues = oldstruct->Eigenvalues;
          newEigenvalues = newstruct->Eigenvalues;
          LOOPi(newstruct->NumberOfFactors)
               CopyFullFLOAT(newEigenvalues++, oldEigenvalues++);
          }


}
extern void PrintFactorAnalysis(FactorAnalysis *eleptr)
{
FLOAT *ptrEigenvalues;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number of Factors:");
     printf("%d\n",eleptr->NumberOfFactors);
     printf("     The Cutoff used:");
     printf("%f\n",eleptr->Cutoff);

     printf("The Transformation Vector (The eigenvector):\n");
     PrintFullMatrixFLT(eleptr->Vector);

     printf("The Transformed Coordinates:\n");
     PrintFullMatrixFLT(eleptr->Coordinates);

     printf("     The Eigenvalues:\n");
     if(eleptr->Eigenvalues != 0)
          {
          ptrEigenvalues = eleptr->Eigenvalues;
          LOOPi(eleptr->NumberOfFactors)
               PrintFLOAT(ptrEigenvalues++);
          }


}
extern void FreeFactorAnalysis(FactorAnalysis *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Eigenvalues);

     FreeFullMatrixFLT(eleptr->Vector);
     Free(eleptr->Vector);

     FreeFullMatrixFLT(eleptr->Coordinates);
     Free(eleptr->Coordinates);

}
extern void WriteBinFactorAnalysis(FactorAnalysis *eleptr, DbaseLinkedList *file)
{
FLOAT *ptrEigenvalues;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfFactors),file);
     WriteBinFLOAT(&(eleptr->Cutoff),file);

     WriteBinFullMatrixFLT(eleptr->Vector,file);

     WriteBinFullMatrixFLT(eleptr->Coordinates,file);

     if(eleptr->Eigenvalues != 0)
          {
          ptrEigenvalues = eleptr->Eigenvalues;
          LOOPi(eleptr->NumberOfFactors)
               WriteBinFLOAT(ptrEigenvalues++,file);
          }

}
extern INT ReadBinFactorAnalysis(FactorAnalysis *eleptr,DbaseLinkedList *file)
     {
FLOAT *ptrEigenvalues;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfFactors),file);
     ReadBinFLOAT(&(eleptr->Cutoff),file);

     eleptr->Vector = AllocateFullMatrixFLT;
     if(ReadBinFullMatrixFLT(eleptr->Vector,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Vector);
           eleptr->Vector = 0;
           }

     eleptr->Coordinates = AllocateFullMatrixFLT;
     if(ReadBinFullMatrixFLT(eleptr->Coordinates,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Coordinates);
           eleptr->Coordinates = 0;
           }

          eleptr->Eigenvalues = AllocArrayFLOAT(eleptr->NumberOfFactors);
          ptrEigenvalues = eleptr->Eigenvalues;
          LOOPi(eleptr->NumberOfFactors)
               ReadBinFLOAT(ptrEigenvalues++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_FactorAnalysis(XDR *stream, char **eleptrp)
{
     FactorAnalysis *eleptr;
     eleptr = (FactorAnalysis *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfFactors));
     xdr_FLOAT(stream,(char **) &(eleptr->Cutoff));

     xdr_pointer(stream,
          (char **) &(eleptr->Vector),
          FullMatrixFLTSize,
                 (xdrproc_t) xdr_FullMatrixFLT);
     xdr_pointer(stream,
          (char **) &(eleptr->Coordinates),
          FullMatrixFLTSize,
                 (xdrproc_t) xdr_FullMatrixFLT);
     xdr_array(stream,(char **) &(eleptr->Eigenvalues),
             (uint *) &(eleptr->NumberOfFactors),eleptr->NumberOfFactors,
               FLOATSize,(xdrproc_t) xdr_FLOAT);
}

extern void *AllocFactorAnalysis()
{
     return((void *) AllocateFactorAnalysis);
}
