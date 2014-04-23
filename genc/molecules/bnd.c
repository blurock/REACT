
extern CHAR *GetNameBondOrderMatrix(BondOrderMatrix *str)
{
     return(str->Name);
}

extern INT GetIDBondOrderMatrix(BondOrderMatrix *str)
{
     return(str->ID);
}

extern BondOrderMatrix *CreateBondOrderMatrix(BondOrderMatrix *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  Size,
                                       INT  TotalSize,
                                       INT *Matrix)
{
INT *oldMatrix,*newMatrix;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Size = Size;
     newstruct->TotalSize = TotalSize;

     newstruct->Matrix = AllocArrayINT(newstruct->TotalSize);
     if(Matrix != 0)
          {
          oldMatrix = Matrix;
          newMatrix = newstruct->Matrix;
          LOOPi(newstruct->TotalSize)
               CopyFullINT(newMatrix++, oldMatrix++);
          }



     return(newstruct);
}


extern void CopyFullBondOrderMatrix(BondOrderMatrix *newstruct, BondOrderMatrix *oldstruct)
{
INT *oldMatrix,*newMatrix;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Size = oldstruct->Size;
     newstruct->TotalSize = oldstruct->TotalSize;


     newstruct->Matrix = AllocArrayINT(newstruct->TotalSize);
     if(oldstruct->Matrix != 0)
          {
          oldMatrix = oldstruct->Matrix;
          newMatrix = newstruct->Matrix;
          LOOPi(newstruct->TotalSize)
               CopyFullINT(newMatrix++, oldMatrix++);
          }


}
extern void PrintBondOrderMatrix(BondOrderMatrix *eleptr)
{
INT *ptrMatrix;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("Number of Columns , Rows:");
     printf("%d\n",eleptr->Size);
     printf("Total Size of Matrix:");
     printf("%d\n",eleptr->TotalSize);

     printf("    The Matrix Array:\n");
     if(eleptr->Matrix != 0)
          {
          ptrMatrix = eleptr->Matrix;
          LOOPi(eleptr->TotalSize)
               PrintINT(ptrMatrix++);
          }


}
extern void FreeBondOrderMatrix(BondOrderMatrix *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Matrix);

}
extern void WriteBinBondOrderMatrix(BondOrderMatrix *eleptr, DbaseLinkedList *file)
{
INT *ptrMatrix;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->Size),file);
     WriteBinINT(&(eleptr->TotalSize),file);

     if(eleptr->Matrix != 0)
          {
          ptrMatrix = eleptr->Matrix;
          LOOPi(eleptr->TotalSize)
               WriteBinINT(ptrMatrix++,file);
          }

}
extern INT ReadBinBondOrderMatrix(BondOrderMatrix *eleptr,DbaseLinkedList *file)
     {
INT *ptrMatrix;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->Size),file);
     ReadBinINT(&(eleptr->TotalSize),file);

          eleptr->Matrix = AllocArrayINT(eleptr->TotalSize);
          ptrMatrix = eleptr->Matrix;
          LOOPi(eleptr->TotalSize)
               ReadBinINT(ptrMatrix++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_BondOrderMatrix(XDR *stream, char **eleptrp)
{
     BondOrderMatrix *eleptr;
     eleptr = (BondOrderMatrix *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->Size));
     xdr_INT(stream,(char **) &(eleptr->TotalSize));

     xdr_array(stream,(char **) &(eleptr->Matrix),
             (uint *) &(eleptr->TotalSize),eleptr->TotalSize,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocBondOrderMatrix()
{
     return((void *) AllocateBondOrderMatrix);
}
