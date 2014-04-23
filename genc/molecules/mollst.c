
extern CHAR *GetNameReadInMolecule(ReadInMolecule *str)
{
     return(str->Name);
}

extern INT GetIDReadInMolecule(ReadInMolecule *str)
{
     return(str->ID);
}

extern ReadInMolecule *CreateReadInMolecule(ReadInMolecule *newstruct,
                                     INT id,
                                     CHAR *name,
                                     STRING *Rest,
                                     ASCIIProperties *Properties)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(Rest != 0)
          {
          newstruct->Rest = AllocateSTRING;
          CopyFullSTRING(newstruct->Rest, Rest);
          }
     else
          newstruct->Rest = 0;
     if(Properties != 0)
          {
          newstruct->Properties = AllocateASCIIProperties;
          CopyFullASCIIProperties(newstruct->Properties, Properties);
          }
     else
          newstruct->Properties = 0;



     return(newstruct);
}


extern void CopyFullReadInMolecule(ReadInMolecule *newstruct, ReadInMolecule *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->Rest != 0)
          {
          newstruct->Rest = AllocateSTRING;
          CopyFullSTRING(newstruct->Rest, oldstruct->Rest);
          }
     else
          newstruct->Rest = 0;
     if(oldstruct->Properties != 0)
          {
          newstruct->Properties = AllocateASCIIProperties;
          CopyFullASCIIProperties(newstruct->Properties, oldstruct->Properties);
          }
     else
          newstruct->Properties = 0;


}
extern void PrintReadInMolecule(ReadInMolecule *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The rest of the line (Auxillary information):\n");
     PrintSTRING(eleptr->Rest);

     printf("The set of properties (if applicaable) following the line:\n");
     PrintASCIIProperties(eleptr->Properties);

}
extern void FreeReadInMolecule(ReadInMolecule *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeSTRING(eleptr->Rest);

     FreeASCIIProperties(eleptr->Properties);
     Free(eleptr->Properties);

}
extern void WriteBinReadInMolecule(ReadInMolecule *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinSTRING(eleptr->Rest,file);

     WriteBinASCIIProperties(eleptr->Properties,file);

}
extern INT ReadBinReadInMolecule(ReadInMolecule *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->Rest = AllocateSTRING;
     if(ReadBinSTRING(eleptr->Rest,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Rest);
           eleptr->Rest = 0;
           }

     eleptr->Properties = AllocateASCIIProperties;
     if(ReadBinASCIIProperties(eleptr->Properties,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Properties);
           eleptr->Properties = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_ReadInMolecule(XDR *stream, char **eleptrp)
{
     ReadInMolecule *eleptr;
     eleptr = (ReadInMolecule *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->Rest),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_pointer(stream,
          (char **) &(eleptr->Properties),
          ASCIIPropertiesSize,
                 (xdrproc_t) xdr_ASCIIProperties);
}

extern void *AllocReadInMolecule()
{
     return((void *) AllocateReadInMolecule);
}

extern CHAR *GetNameReadInMoleculeSet(ReadInMoleculeSet *str)
{
     return(str->Name);
}

extern INT GetIDReadInMoleculeSet(ReadInMoleculeSet *str)
{
     return(str->ID);
}

extern ReadInMoleculeSet *CreateReadInMoleculeSet(ReadInMoleculeSet *newstruct,
                                           INT id,
                                           CHAR *name,
                                           INT  NumberOfMolecules,
                                           ReadInMolecule *Molecules)
{
ReadInMolecule *oldMolecules,*newMolecules;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfMolecules = NumberOfMolecules;

     newstruct->Molecules = AllocArrayReadInMolecule(newstruct->NumberOfMolecules);
     if(Molecules != 0)
          {
          oldMolecules = Molecules;
          newMolecules = newstruct->Molecules;
          LOOPi(newstruct->NumberOfMolecules)
               CopyFullReadInMolecule(newMolecules++, oldMolecules++);
          }



     return(newstruct);
}


extern void CopyFullReadInMoleculeSet(ReadInMoleculeSet *newstruct, ReadInMoleculeSet *oldstruct)
{
ReadInMolecule *oldMolecules,*newMolecules;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfMolecules = oldstruct->NumberOfMolecules;


     newstruct->Molecules = AllocArrayReadInMolecule(newstruct->NumberOfMolecules);
     if(oldstruct->Molecules != 0)
          {
          oldMolecules = oldstruct->Molecules;
          newMolecules = newstruct->Molecules;
          LOOPi(newstruct->NumberOfMolecules)
               CopyFullReadInMolecule(newMolecules++, oldMolecules++);
          }


}
extern void PrintReadInMoleculeSet(ReadInMoleculeSet *eleptr)
{
ReadInMolecule *ptrMolecules;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of molecules in the list:");
     printf("%d\n",eleptr->NumberOfMolecules);

     printf("The set of molecules:\n");
     if(eleptr->Molecules != 0)
          {
          ptrMolecules = eleptr->Molecules;
          LOOPi(eleptr->NumberOfMolecules)
               PrintReadInMolecule(ptrMolecules++);
          }


}
extern void FreeReadInMoleculeSet(ReadInMoleculeSet *eleptr)
{
ReadInMolecule *ptrMolecules;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrMolecules = eleptr->Molecules;
     LOOPi(eleptr->NumberOfMolecules)
          FreeReadInMolecule(ptrMolecules++);
     Free(eleptr->Molecules);

}
extern void WriteBinReadInMoleculeSet(ReadInMoleculeSet *eleptr, DbaseLinkedList *file)
{
ReadInMolecule *ptrMolecules;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfMolecules),file);

     if(eleptr->Molecules != 0)
          {
          ptrMolecules = eleptr->Molecules;
          LOOPi(eleptr->NumberOfMolecules)
               WriteBinReadInMolecule(ptrMolecules++,file);
          }

}
extern INT ReadBinReadInMoleculeSet(ReadInMoleculeSet *eleptr,DbaseLinkedList *file)
     {
ReadInMolecule *ptrMolecules;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfMolecules),file);

          eleptr->Molecules = AllocArrayReadInMolecule(eleptr->NumberOfMolecules);
          ptrMolecules = eleptr->Molecules;
          LOOPi(eleptr->NumberOfMolecules)
               ReadBinReadInMolecule(ptrMolecules++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_ReadInMoleculeSet(XDR *stream, char **eleptrp)
{
     ReadInMoleculeSet *eleptr;
     eleptr = (ReadInMoleculeSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfMolecules));

     xdr_array(stream,(char **) &(eleptr->Molecules),
             (uint *) &(eleptr->NumberOfMolecules),eleptr->NumberOfMolecules,
               ReadInMoleculeSize,(xdrproc_t) xdr_ReadInMolecule);
}

extern void *AllocReadInMoleculeSet()
{
     return((void *) AllocateReadInMoleculeSet);
}
