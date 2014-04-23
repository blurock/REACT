
extern CHAR *GetNameBindStructure(BindStructure *str)
{
     return(str->Name);
}

extern INT GetIDBindStructure(BindStructure *str)
{
     return(str->ID);
}

extern BindStructure *CreateBindStructure(BindStructure *newstruct,
                                   INT id,
                                   CHAR *name,
                                   INT  MaxNumberOfBoundStructures,
                                   INT  NumberOfBoundStructures,
                                   VOID *Structures,
                                   INT *Flags)
{
VOID *oldStructures,*newStructures;
INT *oldFlags,*newFlags;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->MaxNumberOfBoundStructures = MaxNumberOfBoundStructures;
     newstruct->NumberOfBoundStructures = NumberOfBoundStructures;

     newstruct->Structures = AllocArrayVOID(newstruct->MaxNumberOfBoundStructures);
     if(Structures != 0)
          {
          oldStructures = Structures;
          newStructures = newstruct->Structures;
          LOOPi(newstruct->MaxNumberOfBoundStructures)
               CopyFullVOID(newStructures++, oldStructures++);
          }

     newstruct->Flags = AllocArrayINT(newstruct->MaxNumberOfBoundStructures);
     if(Flags != 0)
          {
          oldFlags = Flags;
          newFlags = newstruct->Flags;
          LOOPi(newstruct->MaxNumberOfBoundStructures)
               CopyFullINT(newFlags++, oldFlags++);
          }



     return(newstruct);
}


extern void CopyFullBindStructure(BindStructure *newstruct, BindStructure *oldstruct)
{
VOID *oldStructures,*newStructures;
INT *oldFlags,*newFlags;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->MaxNumberOfBoundStructures = oldstruct->MaxNumberOfBoundStructures;
     newstruct->NumberOfBoundStructures = oldstruct->NumberOfBoundStructures;


     newstruct->Structures = AllocArrayVOID(newstruct->MaxNumberOfBoundStructures);
     if(oldstruct->Structures != 0)
          {
          oldStructures = oldstruct->Structures;
          newStructures = newstruct->Structures;
          LOOPi(newstruct->MaxNumberOfBoundStructures)
               CopyFullVOID(newStructures++, oldStructures++);
          }

     newstruct->Flags = AllocArrayINT(newstruct->MaxNumberOfBoundStructures);
     if(oldstruct->Flags != 0)
          {
          oldFlags = oldstruct->Flags;
          newFlags = newstruct->Flags;
          LOOPi(newstruct->MaxNumberOfBoundStructures)
               CopyFullINT(newFlags++, oldFlags++);
          }


}
extern void PrintBindStructure(BindStructure *eleptr)
{
VOID *ptrStructures;
INT *ptrFlags;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Maximum Number of Structures to be bound:");
     printf("%d\n",eleptr->MaxNumberOfBoundStructures);
     printf("The Number of Structures to be bound:");
     printf("%d\n",eleptr->NumberOfBoundStructures);

     printf("The Master Structures :\n");
     if(eleptr->Structures != 0)
          {
          ptrStructures = eleptr->Structures;
          LOOPi(eleptr->MaxNumberOfBoundStructures)
               PrintVOID(ptrStructures++);
          }


     printf("The List of Corresponding Flags for the Bound Structures:\n");
     if(eleptr->Flags != 0)
          {
          ptrFlags = eleptr->Flags;
          LOOPi(eleptr->MaxNumberOfBoundStructures)
               PrintINT(ptrFlags++);
          }


}
extern void FreeBindStructure(BindStructure *eleptr)
{
VOID *ptrStructures;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrStructures = eleptr->Structures;
     LOOPi(eleptr->MaxNumberOfBoundStructures)
          FreeVOID(ptrStructures++);
     Free(eleptr->Structures);

     Free(eleptr->Flags);

}
extern void WriteBinBindStructure(BindStructure *eleptr, DbaseLinkedList *file)
{
VOID *ptrStructures;
INT *ptrFlags;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->MaxNumberOfBoundStructures),file);
     WriteBinINT(&(eleptr->NumberOfBoundStructures),file);

     if(eleptr->Structures != 0)
          {
          ptrStructures = eleptr->Structures;
          LOOPi(eleptr->MaxNumberOfBoundStructures)
               WriteBinVOID(ptrStructures++,file);
          }

     if(eleptr->Flags != 0)
          {
          ptrFlags = eleptr->Flags;
          LOOPi(eleptr->MaxNumberOfBoundStructures)
               WriteBinINT(ptrFlags++,file);
          }

}
extern INT ReadBinBindStructure(BindStructure *eleptr,DbaseLinkedList *file)
     {
VOID *ptrStructures;
INT *ptrFlags;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->MaxNumberOfBoundStructures),file);
     ReadBinINT(&(eleptr->NumberOfBoundStructures),file);

          eleptr->Structures = AllocArrayVOID(eleptr->MaxNumberOfBoundStructures);
          ptrStructures = eleptr->Structures;
          LOOPi(eleptr->MaxNumberOfBoundStructures)
               ReadBinVOID(ptrStructures++,file);

          eleptr->Flags = AllocArrayINT(eleptr->MaxNumberOfBoundStructures);
          ptrFlags = eleptr->Flags;
          LOOPi(eleptr->MaxNumberOfBoundStructures)
               ReadBinINT(ptrFlags++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_BindStructure(XDR *stream, char **eleptrp)
{
     BindStructure *eleptr;
     eleptr = (BindStructure *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->MaxNumberOfBoundStructures));
     xdr_INT(stream,(char **) &(eleptr->NumberOfBoundStructures));

     xdr_array(stream,(char **) &(eleptr->Structures),
             (uint *) &(eleptr->MaxNumberOfBoundStructures),eleptr->MaxNumberOfBoundStructures,
               VOIDSize,(xdrproc_t) xdr_VOID);
     xdr_array(stream,(char **) &(eleptr->Flags),
             (uint *) &(eleptr->MaxNumberOfBoundStructures),eleptr->MaxNumberOfBoundStructures,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocBindStructure()
{
     return((void *) AllocateBindStructure);
}
