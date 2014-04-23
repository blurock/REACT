
extern CHAR *GetNameArrheniusFormValue(ArrheniusFormValue *str)
{
     return(str->Name);
}

extern INT GetIDArrheniusFormValue(ArrheniusFormValue *str)
{
     return(str->ID);
}

extern ArrheniusFormValue *CreateArrheniusFormValue(ArrheniusFormValue *newstruct,
                                             INT id,
                                             CHAR *name,
                                             FLOAT  Aconstant,
                                             FLOAT  Energy,
                                             FLOAT  TempExp,
                                             FLOAT  SymmetryFactor)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Aconstant = Aconstant;
     newstruct->Energy = Energy;
     newstruct->TempExp = TempExp;
     newstruct->SymmetryFactor = SymmetryFactor;



     return(newstruct);
}


extern void CopyFullArrheniusFormValue(ArrheniusFormValue *newstruct, ArrheniusFormValue *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Aconstant = oldstruct->Aconstant;
     newstruct->Energy = oldstruct->Energy;
     newstruct->TempExp = oldstruct->TempExp;
     newstruct->SymmetryFactor = oldstruct->SymmetryFactor;



}
extern void PrintArrheniusFormValue(ArrheniusFormValue *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Arrhenius Constant:");
     printf("%f\n",eleptr->Aconstant);
     printf("The Activation Energy:");
     printf("%f\n",eleptr->Energy);
     printf("The Temperature Exponent:");
     printf("%f\n",eleptr->TempExp);
     printf(" The Symmetry Factor:");
     printf("%f\n",eleptr->SymmetryFactor);

}
extern void FreeArrheniusFormValue(ArrheniusFormValue *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinArrheniusFormValue(ArrheniusFormValue *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinFLOAT(&(eleptr->Aconstant),file);
     WriteBinFLOAT(&(eleptr->Energy),file);
     WriteBinFLOAT(&(eleptr->TempExp),file);
     WriteBinFLOAT(&(eleptr->SymmetryFactor),file);

}
extern INT ReadBinArrheniusFormValue(ArrheniusFormValue *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinFLOAT(&(eleptr->Aconstant),file);
     ReadBinFLOAT(&(eleptr->Energy),file);
     ReadBinFLOAT(&(eleptr->TempExp),file);
     ReadBinFLOAT(&(eleptr->SymmetryFactor),file);

     return(STRUCTURE_READ);
     }
extern void xdr_ArrheniusFormValue(XDR *stream, char **eleptrp)
{
     ArrheniusFormValue *eleptr;
     eleptr = (ArrheniusFormValue *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_FLOAT(stream,(char **) &(eleptr->Aconstant));
     xdr_FLOAT(stream,(char **) &(eleptr->Energy));
     xdr_FLOAT(stream,(char **) &(eleptr->TempExp));
     xdr_FLOAT(stream,(char **) &(eleptr->SymmetryFactor));

}

extern void *AllocArrheniusFormValue()
{
     return((void *) AllocateArrheniusFormValue);
}
