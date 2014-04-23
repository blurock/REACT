
extern CHAR *GetNameFullMatrixFLT(FullMatrixFLT *str)
{
     return(str->Name);
}

extern INT GetIDFullMatrixFLT(FullMatrixFLT *str)
{
     return(str->ID);
}

extern FullMatrixFLT *CreateFullMatrixFLT(FullMatrixFLT *newstruct,
                                   INT id,
                                   CHAR *name,
                                   INT  Dim1,
                                   INT  Dim2,
                                   INT  TotalDim,
                                   FLOAT *Elements)
{
FLOAT *oldElements,*newElements;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Dim1 = Dim1;
     newstruct->Dim2 = Dim2;
     newstruct->TotalDim = TotalDim;

     newstruct->Elements = AllocArrayFLOAT(newstruct->TotalDim);
     if(Elements != 0)
          {
          oldElements = Elements;
          newElements = newstruct->Elements;
          LOOPi(newstruct->TotalDim)
               CopyFullFLOAT(newElements++, oldElements++);
          }



     return(newstruct);
}


extern void CopyFullFullMatrixFLT(FullMatrixFLT *newstruct, FullMatrixFLT *oldstruct)
{
FLOAT *oldElements,*newElements;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Dim1 = oldstruct->Dim1;
     newstruct->Dim2 = oldstruct->Dim2;
     newstruct->TotalDim = oldstruct->TotalDim;


     newstruct->Elements = AllocArrayFLOAT(newstruct->TotalDim);
     if(oldstruct->Elements != 0)
          {
          oldElements = oldstruct->Elements;
          newElements = newstruct->Elements;
          LOOPi(newstruct->TotalDim)
               CopyFullFLOAT(newElements++, oldElements++);
          }


}
extern void PrintFullMatrixFLT(FullMatrixFLT *eleptr)
{
FLOAT *ptrElements;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("  The number of Rows:");
     printf("%d\n",eleptr->Dim1);
     printf("The number of Columns:");
     printf("%d\n",eleptr->Dim2);
     printf(" The total Dimension:");
     printf("%d\n",eleptr->TotalDim);

     printf("The Array as Vector of Floating Points:\n");
     if(eleptr->Elements != 0)
          {
          ptrElements = eleptr->Elements;
          LOOPi(eleptr->TotalDim)
               PrintFLOAT(ptrElements++);
          }


}
extern void FreeFullMatrixFLT(FullMatrixFLT *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Elements);

}
extern void WriteBinFullMatrixFLT(FullMatrixFLT *eleptr, DbaseLinkedList *file)
{
FLOAT *ptrElements;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->Dim1),file);
     WriteBinINT(&(eleptr->Dim2),file);
     WriteBinINT(&(eleptr->TotalDim),file);

     if(eleptr->Elements != 0)
          {
          ptrElements = eleptr->Elements;
          LOOPi(eleptr->TotalDim)
               WriteBinFLOAT(ptrElements++,file);
          }

}
extern INT ReadBinFullMatrixFLT(FullMatrixFLT *eleptr,DbaseLinkedList *file)
     {
FLOAT *ptrElements;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->Dim1),file);
     ReadBinINT(&(eleptr->Dim2),file);
     ReadBinINT(&(eleptr->TotalDim),file);

          eleptr->Elements = AllocArrayFLOAT(eleptr->TotalDim);
          ptrElements = eleptr->Elements;
          LOOPi(eleptr->TotalDim)
               ReadBinFLOAT(ptrElements++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_FullMatrixFLT(XDR *stream, char **eleptrp)
{
     FullMatrixFLT *eleptr;
     eleptr = (FullMatrixFLT *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->Dim1));
     xdr_INT(stream,(char **) &(eleptr->Dim2));
     xdr_INT(stream,(char **) &(eleptr->TotalDim));

     xdr_array(stream,(char **) &(eleptr->Elements),
             (uint *) &(eleptr->TotalDim),eleptr->TotalDim,
               FLOATSize,(xdrproc_t) xdr_FLOAT);
}

extern void *AllocFullMatrixFLT()
{
     return((void *) AllocateFullMatrixFLT);
}

extern CHAR *GetNameSymmetricEigenMath(SymmetricEigenMath *str)
{
     return(str->Name);
}

extern INT GetIDSymmetricEigenMath(SymmetricEigenMath *str)
{
     return(str->ID);
}

extern SymmetricEigenMath *CreateSymmetricEigenMath(SymmetricEigenMath *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  NumberOfRows,
                                             FullMatrixFLT *Elements,
                                             FLOAT *Eigenvalues,
                                             FullMatrixFLT *Eigenvectors)
{
FLOAT *oldEigenvalues,*newEigenvalues;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfRows = NumberOfRows;
     if(Elements != 0)
          {
          newstruct->Elements = AllocateFullMatrixFLT;
          CopyFullFullMatrixFLT(newstruct->Elements, Elements);
          }
     else
          newstruct->Elements = 0;
     if(Eigenvectors != 0)
          {
          newstruct->Eigenvectors = AllocateFullMatrixFLT;
          CopyFullFullMatrixFLT(newstruct->Eigenvectors, Eigenvectors);
          }
     else
          newstruct->Eigenvectors = 0;

     newstruct->Eigenvalues = AllocArrayFLOAT(newstruct->NumberOfRows);
     if(Eigenvalues != 0)
          {
          oldEigenvalues = Eigenvalues;
          newEigenvalues = newstruct->Eigenvalues;
          LOOPi(newstruct->NumberOfRows)
               CopyFullFLOAT(newEigenvalues++, oldEigenvalues++);
          }



     return(newstruct);
}


extern void CopyFullSymmetricEigenMath(SymmetricEigenMath *newstruct, SymmetricEigenMath *oldstruct)
{
FLOAT *oldEigenvalues,*newEigenvalues;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfRows = oldstruct->NumberOfRows;

     if(oldstruct->Elements != 0)
          {
          newstruct->Elements = AllocateFullMatrixFLT;
          CopyFullFullMatrixFLT(newstruct->Elements, oldstruct->Elements);
          }
     else
          newstruct->Elements = 0;
     if(oldstruct->Eigenvectors != 0)
          {
          newstruct->Eigenvectors = AllocateFullMatrixFLT;
          CopyFullFullMatrixFLT(newstruct->Eigenvectors, oldstruct->Eigenvectors);
          }
     else
          newstruct->Eigenvectors = 0;

     newstruct->Eigenvalues = AllocArrayFLOAT(newstruct->NumberOfRows);
     if(oldstruct->Eigenvalues != 0)
          {
          oldEigenvalues = oldstruct->Eigenvalues;
          newEigenvalues = newstruct->Eigenvalues;
          LOOPi(newstruct->NumberOfRows)
               CopyFullFLOAT(newEigenvalues++, oldEigenvalues++);
          }


}
extern void PrintSymmetricEigenMath(SymmetricEigenMath *eleptr)
{
FLOAT *ptrEigenvalues;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("  The number of rows:");
     printf("%d\n",eleptr->NumberOfRows);

     printf("The matrix of elements:\n");
     PrintFullMatrixFLT(eleptr->Elements);

     printf("    The Eigenvectors:\n");
     PrintFullMatrixFLT(eleptr->Eigenvectors);

     printf("     The eigenvalues:\n");
     if(eleptr->Eigenvalues != 0)
          {
          ptrEigenvalues = eleptr->Eigenvalues;
          LOOPi(eleptr->NumberOfRows)
               PrintFLOAT(ptrEigenvalues++);
          }


}
extern void FreeSymmetricEigenMath(SymmetricEigenMath *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Eigenvalues);

     FreeFullMatrixFLT(eleptr->Elements);
     Free(eleptr->Elements);

     FreeFullMatrixFLT(eleptr->Eigenvectors);
     Free(eleptr->Eigenvectors);

}
extern void WriteBinSymmetricEigenMath(SymmetricEigenMath *eleptr, DbaseLinkedList *file)
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
     WriteBinINT(&(eleptr->NumberOfRows),file);

     WriteBinFullMatrixFLT(eleptr->Elements,file);

     WriteBinFullMatrixFLT(eleptr->Eigenvectors,file);

     if(eleptr->Eigenvalues != 0)
          {
          ptrEigenvalues = eleptr->Eigenvalues;
          LOOPi(eleptr->NumberOfRows)
               WriteBinFLOAT(ptrEigenvalues++,file);
          }

}
extern INT ReadBinSymmetricEigenMath(SymmetricEigenMath *eleptr,DbaseLinkedList *file)
     {
FLOAT *ptrEigenvalues;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfRows),file);

     eleptr->Elements = AllocateFullMatrixFLT;
     if(ReadBinFullMatrixFLT(eleptr->Elements,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Elements);
           eleptr->Elements = 0;
           }

     eleptr->Eigenvectors = AllocateFullMatrixFLT;
     if(ReadBinFullMatrixFLT(eleptr->Eigenvectors,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Eigenvectors);
           eleptr->Eigenvectors = 0;
           }

          eleptr->Eigenvalues = AllocArrayFLOAT(eleptr->NumberOfRows);
          ptrEigenvalues = eleptr->Eigenvalues;
          LOOPi(eleptr->NumberOfRows)
               ReadBinFLOAT(ptrEigenvalues++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SymmetricEigenMath(XDR *stream, char **eleptrp)
{
     SymmetricEigenMath *eleptr;
     eleptr = (SymmetricEigenMath *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfRows));

     xdr_pointer(stream,
          (char **) &(eleptr->Elements),
          FullMatrixFLTSize,
                 (xdrproc_t) xdr_FullMatrixFLT);
     xdr_pointer(stream,
          (char **) &(eleptr->Eigenvectors),
          FullMatrixFLTSize,
                 (xdrproc_t) xdr_FullMatrixFLT);
     xdr_array(stream,(char **) &(eleptr->Eigenvalues),
             (uint *) &(eleptr->NumberOfRows),eleptr->NumberOfRows,
               FLOATSize,(xdrproc_t) xdr_FLOAT);
}

extern void *AllocSymmetricEigenMath()
{
     return((void *) AllocateSymmetricEigenMath);
}
