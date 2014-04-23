
extern CHAR *GetNameAuxMolecules(AuxMolecules *str)
{
     return(str->Name);
}

extern INT GetIDAuxMolecules(AuxMolecules *str)
{
     return(str->ID);
}

extern AuxMolecules *CreateAuxMolecules(AuxMolecules *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  NumberOfMolecules,
                                 INT *Molecules)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfMolecules = NumberOfMolecules;
     if(Molecules != 0)
          {
          newstruct->Molecules = AllocateINT;
          CopyFullINT(newstruct->Molecules, Molecules);
          }
     else
          newstruct->Molecules = 0;



     return(newstruct);
}


extern void CopyFullAuxMolecules(AuxMolecules *newstruct, AuxMolecules *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfMolecules = oldstruct->NumberOfMolecules;

     if(oldstruct->Molecules != 0)
          {
          newstruct->Molecules = AllocateINT;
          CopyFullINT(newstruct->Molecules, oldstruct->Molecules);
          }
     else
          newstruct->Molecules = 0;


}
extern void PrintAuxMolecules(AuxMolecules *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of molecules:");
     printf("%d\n",eleptr->NumberOfMolecules);

     printf("The set of molecules:\n");
     PrintINT(eleptr->Molecules);

}
extern void FreeAuxMolecules(AuxMolecules *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Molecules);

}
extern void WriteBinAuxMolecules(AuxMolecules *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfMolecules),file);

     WriteBinINT(eleptr->Molecules,file);

}
extern INT ReadBinAuxMolecules(AuxMolecules *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfMolecules),file);

     eleptr->Molecules = AllocateINT;
     if(ReadBinINT(eleptr->Molecules,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Molecules);
           eleptr->Molecules = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_AuxMolecules(XDR *stream, char **eleptrp)
{
     AuxMolecules *eleptr;
     eleptr = (AuxMolecules *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfMolecules));

     xdr_pointer(stream,
          (char **) &(eleptr->Molecules),
          INTSize,
                 (xdrproc_t) xdr_INT);
}

extern void *AllocAuxMolecules()
{
     return((void *) AllocateAuxMolecules);
}

extern CHAR *GetNameChainSequenceElement(ChainSequenceElement *str)
{
     return(str->Name);
}

extern INT GetIDChainSequenceElement(ChainSequenceElement *str)
{
     return(str->ID);
}

extern ChainSequenceElement *CreateChainSequenceElement(ChainSequenceElement *newstruct,
                                                 INT id,
                                                 CHAR *name,
                                                 SetOfGraphs *Molecules,
                                                 TransformSet *Reactions)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(Molecules != 0)
          {
          newstruct->Molecules = AllocateSetOfGraphs;
          CopyFullSetOfGraphs(newstruct->Molecules, Molecules);
          }
     else
          newstruct->Molecules = 0;
     if(Reactions != 0)
          {
          newstruct->Reactions = AllocateTransformSet;
          CopyFullTransformSet(newstruct->Reactions, Reactions);
          }
     else
          newstruct->Reactions = 0;



     return(newstruct);
}


extern void CopyFullChainSequenceElement(ChainSequenceElement *newstruct, ChainSequenceElement *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->Molecules != 0)
          {
          newstruct->Molecules = AllocateSetOfGraphs;
          CopyFullSetOfGraphs(newstruct->Molecules, oldstruct->Molecules);
          }
     else
          newstruct->Molecules = 0;
     if(oldstruct->Reactions != 0)
          {
          newstruct->Reactions = AllocateTransformSet;
          CopyFullTransformSet(newstruct->Reactions, oldstruct->Reactions);
          }
     else
          newstruct->Reactions = 0;


}
extern void PrintChainSequenceElement(ChainSequenceElement *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The set of auxiliary molecule for reaction:\n");
     PrintSetOfGraphs(eleptr->Molecules);

     printf("The set of Transforms:\n");
     PrintTransformSet(eleptr->Reactions);

}
extern void FreeChainSequenceElement(ChainSequenceElement *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeSetOfGraphs(eleptr->Molecules);
     Free(eleptr->Molecules);

     FreeTransformSet(eleptr->Reactions);
     Free(eleptr->Reactions);

}
extern void WriteBinChainSequenceElement(ChainSequenceElement *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinSetOfGraphs(eleptr->Molecules,file);

     WriteBinTransformSet(eleptr->Reactions,file);

}
extern INT ReadBinChainSequenceElement(ChainSequenceElement *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->Molecules = AllocateSetOfGraphs;
     if(ReadBinSetOfGraphs(eleptr->Molecules,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Molecules);
           eleptr->Molecules = 0;
           }

     eleptr->Reactions = AllocateTransformSet;
     if(ReadBinTransformSet(eleptr->Reactions,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Reactions);
           eleptr->Reactions = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_ChainSequenceElement(XDR *stream, char **eleptrp)
{
     ChainSequenceElement *eleptr;
     eleptr = (ChainSequenceElement *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->Molecules),
          SetOfGraphsSize,
                 (xdrproc_t) xdr_SetOfGraphs);
     xdr_pointer(stream,
          (char **) &(eleptr->Reactions),
          TransformSetSize,
                 (xdrproc_t) xdr_TransformSet);
}

extern void *AllocChainSequenceElement()
{
     return((void *) AllocateChainSequenceElement);
}

extern CHAR *GetNameReadChainReactionStep(ReadChainReactionStep *str)
{
     return(str->Name);
}

extern INT GetIDReadChainReactionStep(ReadChainReactionStep *str)
{
     return(str->ID);
}

extern ReadChainReactionStep *CreateReadChainReactionStep(ReadChainReactionStep *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   ReadInReactionSet *Reactions,
                                                   ReadInMoleculeSet *Molecules)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(Reactions != 0)
          {
          newstruct->Reactions = AllocateReadInReactionSet;
          CopyFullReadInReactionSet(newstruct->Reactions, Reactions);
          }
     else
          newstruct->Reactions = 0;
     if(Molecules != 0)
          {
          newstruct->Molecules = AllocateReadInMoleculeSet;
          CopyFullReadInMoleculeSet(newstruct->Molecules, Molecules);
          }
     else
          newstruct->Molecules = 0;



     return(newstruct);
}


extern void CopyFullReadChainReactionStep(ReadChainReactionStep *newstruct, ReadChainReactionStep *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->Reactions != 0)
          {
          newstruct->Reactions = AllocateReadInReactionSet;
          CopyFullReadInReactionSet(newstruct->Reactions, oldstruct->Reactions);
          }
     else
          newstruct->Reactions = 0;
     if(oldstruct->Molecules != 0)
          {
          newstruct->Molecules = AllocateReadInMoleculeSet;
          CopyFullReadInMoleculeSet(newstruct->Molecules, oldstruct->Molecules);
          }
     else
          newstruct->Molecules = 0;


}
extern void PrintReadChainReactionStep(ReadChainReactionStep *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The set of reaction patterns:\n");
     PrintReadInReactionSet(eleptr->Reactions);

     printf("The set of step molecules:\n");
     PrintReadInMoleculeSet(eleptr->Molecules);

}
extern void FreeReadChainReactionStep(ReadChainReactionStep *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeReadInReactionSet(eleptr->Reactions);
     Free(eleptr->Reactions);

     FreeReadInMoleculeSet(eleptr->Molecules);
     Free(eleptr->Molecules);

}
extern void WriteBinReadChainReactionStep(ReadChainReactionStep *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinReadInReactionSet(eleptr->Reactions,file);

     WriteBinReadInMoleculeSet(eleptr->Molecules,file);

}
extern INT ReadBinReadChainReactionStep(ReadChainReactionStep *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->Reactions = AllocateReadInReactionSet;
     if(ReadBinReadInReactionSet(eleptr->Reactions,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Reactions);
           eleptr->Reactions = 0;
           }

     eleptr->Molecules = AllocateReadInMoleculeSet;
     if(ReadBinReadInMoleculeSet(eleptr->Molecules,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Molecules);
           eleptr->Molecules = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_ReadChainReactionStep(XDR *stream, char **eleptrp)
{
     ReadChainReactionStep *eleptr;
     eleptr = (ReadChainReactionStep *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->Reactions),
          ReadInReactionSetSize,
                 (xdrproc_t) xdr_ReadInReactionSet);
     xdr_pointer(stream,
          (char **) &(eleptr->Molecules),
          ReadInMoleculeSetSize,
                 (xdrproc_t) xdr_ReadInMoleculeSet);
}

extern void *AllocReadChainReactionStep()
{
     return((void *) AllocateReadChainReactionStep);
}

extern CHAR *GetNameReadChainSet(ReadChainSet *str)
{
     return(str->Name);
}

extern INT GetIDReadChainSet(ReadChainSet *str)
{
     return(str->ID);
}

extern ReadChainSet *CreateReadChainSet(ReadChainSet *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  NumberOfSteps,
                                 ReadChainReactionStep *Steps,
                                 ReadInMoleculeSet *ExtraMolecules,
                                 ReadInMoleculeSet *Molecules,
                                 ReadInReactionSet *Reactions)
{
ReadChainReactionStep *oldSteps,*newSteps;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfSteps = NumberOfSteps;
     if(ExtraMolecules != 0)
          {
          newstruct->ExtraMolecules = AllocateReadInMoleculeSet;
          CopyFullReadInMoleculeSet(newstruct->ExtraMolecules, ExtraMolecules);
          }
     else
          newstruct->ExtraMolecules = 0;
     if(Molecules != 0)
          {
          newstruct->Molecules = AllocateReadInMoleculeSet;
          CopyFullReadInMoleculeSet(newstruct->Molecules, Molecules);
          }
     else
          newstruct->Molecules = 0;
     if(Reactions != 0)
          {
          newstruct->Reactions = AllocateReadInReactionSet;
          CopyFullReadInReactionSet(newstruct->Reactions, Reactions);
          }
     else
          newstruct->Reactions = 0;

     newstruct->Steps = AllocArrayReadChainReactionStep(newstruct->NumberOfSteps);
     if(Steps != 0)
          {
          oldSteps = Steps;
          newSteps = newstruct->Steps;
          LOOPi(newstruct->NumberOfSteps)
               CopyFullReadChainReactionStep(newSteps++, oldSteps++);
          }



     return(newstruct);
}


extern void CopyFullReadChainSet(ReadChainSet *newstruct, ReadChainSet *oldstruct)
{
ReadChainReactionStep *oldSteps,*newSteps;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfSteps = oldstruct->NumberOfSteps;

     if(oldstruct->ExtraMolecules != 0)
          {
          newstruct->ExtraMolecules = AllocateReadInMoleculeSet;
          CopyFullReadInMoleculeSet(newstruct->ExtraMolecules, oldstruct->ExtraMolecules);
          }
     else
          newstruct->ExtraMolecules = 0;
     if(oldstruct->Molecules != 0)
          {
          newstruct->Molecules = AllocateReadInMoleculeSet;
          CopyFullReadInMoleculeSet(newstruct->Molecules, oldstruct->Molecules);
          }
     else
          newstruct->Molecules = 0;
     if(oldstruct->Reactions != 0)
          {
          newstruct->Reactions = AllocateReadInReactionSet;
          CopyFullReadInReactionSet(newstruct->Reactions, oldstruct->Reactions);
          }
     else
          newstruct->Reactions = 0;

     newstruct->Steps = AllocArrayReadChainReactionStep(newstruct->NumberOfSteps);
     if(oldstruct->Steps != 0)
          {
          oldSteps = oldstruct->Steps;
          newSteps = newstruct->Steps;
          LOOPi(newstruct->NumberOfSteps)
               CopyFullReadChainReactionStep(newSteps++, oldSteps++);
          }


}
extern void PrintReadChainSet(ReadChainSet *eleptr)
{
ReadChainReactionStep *ptrSteps;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number in the sequence:");
     printf("%d\n",eleptr->NumberOfSteps);

     printf("Auxiliary molecules for all steps:\n");
     PrintReadInMoleculeSet(eleptr->ExtraMolecules);

     printf("The set of molecules:\n");
     PrintReadInMoleculeSet(eleptr->Molecules);

     printf("The set of reactions:\n");
     PrintReadInReactionSet(eleptr->Reactions);

     printf("    The set of steps:\n");
     if(eleptr->Steps != 0)
          {
          ptrSteps = eleptr->Steps;
          LOOPi(eleptr->NumberOfSteps)
               PrintReadChainReactionStep(ptrSteps++);
          }


}
extern void FreeReadChainSet(ReadChainSet *eleptr)
{
ReadChainReactionStep *ptrSteps;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrSteps = eleptr->Steps;
     LOOPi(eleptr->NumberOfSteps)
          FreeReadChainReactionStep(ptrSteps++);
     Free(eleptr->Steps);

     FreeReadInMoleculeSet(eleptr->ExtraMolecules);
     Free(eleptr->ExtraMolecules);

     FreeReadInMoleculeSet(eleptr->Molecules);
     Free(eleptr->Molecules);

     FreeReadInReactionSet(eleptr->Reactions);
     Free(eleptr->Reactions);

}
extern void WriteBinReadChainSet(ReadChainSet *eleptr, DbaseLinkedList *file)
{
ReadChainReactionStep *ptrSteps;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfSteps),file);

     WriteBinReadInMoleculeSet(eleptr->ExtraMolecules,file);

     WriteBinReadInMoleculeSet(eleptr->Molecules,file);

     WriteBinReadInReactionSet(eleptr->Reactions,file);

     if(eleptr->Steps != 0)
          {
          ptrSteps = eleptr->Steps;
          LOOPi(eleptr->NumberOfSteps)
               WriteBinReadChainReactionStep(ptrSteps++,file);
          }

}
extern INT ReadBinReadChainSet(ReadChainSet *eleptr,DbaseLinkedList *file)
     {
ReadChainReactionStep *ptrSteps;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfSteps),file);

     eleptr->ExtraMolecules = AllocateReadInMoleculeSet;
     if(ReadBinReadInMoleculeSet(eleptr->ExtraMolecules,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->ExtraMolecules);
           eleptr->ExtraMolecules = 0;
           }

     eleptr->Molecules = AllocateReadInMoleculeSet;
     if(ReadBinReadInMoleculeSet(eleptr->Molecules,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Molecules);
           eleptr->Molecules = 0;
           }

     eleptr->Reactions = AllocateReadInReactionSet;
     if(ReadBinReadInReactionSet(eleptr->Reactions,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Reactions);
           eleptr->Reactions = 0;
           }

          eleptr->Steps = AllocArrayReadChainReactionStep(eleptr->NumberOfSteps);
          ptrSteps = eleptr->Steps;
          LOOPi(eleptr->NumberOfSteps)
               ReadBinReadChainReactionStep(ptrSteps++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_ReadChainSet(XDR *stream, char **eleptrp)
{
     ReadChainSet *eleptr;
     eleptr = (ReadChainSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfSteps));

     xdr_pointer(stream,
          (char **) &(eleptr->ExtraMolecules),
          ReadInMoleculeSetSize,
                 (xdrproc_t) xdr_ReadInMoleculeSet);
     xdr_pointer(stream,
          (char **) &(eleptr->Molecules),
          ReadInMoleculeSetSize,
                 (xdrproc_t) xdr_ReadInMoleculeSet);
     xdr_pointer(stream,
          (char **) &(eleptr->Reactions),
          ReadInReactionSetSize,
                 (xdrproc_t) xdr_ReadInReactionSet);
     xdr_array(stream,(char **) &(eleptr->Steps),
             (uint *) &(eleptr->NumberOfSteps),eleptr->NumberOfSteps,
               ReadChainReactionStepSize,(xdrproc_t) xdr_ReadChainReactionStep);
}

extern void *AllocReadChainSet()
{
     return((void *) AllocateReadChainSet);
}

extern CHAR *GetNameChainSequence(ChainSequence *str)
{
     return(str->Name);
}

extern INT GetIDChainSequence(ChainSequence *str)
{
     return(str->ID);
}

extern ChainSequence *CreateChainSequence(ChainSequence *newstruct,
                                   INT id,
                                   CHAR *name,
                                   INT  NumberOfSteps,
                                   ChainSequenceElement *Steps,
                                   SetOfGraphs *Molecules)
{
ChainSequenceElement *oldSteps,*newSteps;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfSteps = NumberOfSteps;
     if(Molecules != 0)
          {
          newstruct->Molecules = AllocateSetOfGraphs;
          CopyFullSetOfGraphs(newstruct->Molecules, Molecules);
          }
     else
          newstruct->Molecules = 0;

     newstruct->Steps = AllocArrayChainSequenceElement(newstruct->NumberOfSteps);
     if(Steps != 0)
          {
          oldSteps = Steps;
          newSteps = newstruct->Steps;
          LOOPi(newstruct->NumberOfSteps)
               CopyFullChainSequenceElement(newSteps++, oldSteps++);
          }



     return(newstruct);
}


extern void CopyFullChainSequence(ChainSequence *newstruct, ChainSequence *oldstruct)
{
ChainSequenceElement *oldSteps,*newSteps;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfSteps = oldstruct->NumberOfSteps;

     if(oldstruct->Molecules != 0)
          {
          newstruct->Molecules = AllocateSetOfGraphs;
          CopyFullSetOfGraphs(newstruct->Molecules, oldstruct->Molecules);
          }
     else
          newstruct->Molecules = 0;

     newstruct->Steps = AllocArrayChainSequenceElement(newstruct->NumberOfSteps);
     if(oldstruct->Steps != 0)
          {
          oldSteps = oldstruct->Steps;
          newSteps = newstruct->Steps;
          LOOPi(newstruct->NumberOfSteps)
               CopyFullChainSequenceElement(newSteps++, oldSteps++);
          }


}
extern void PrintChainSequence(ChainSequence *eleptr)
{
ChainSequenceElement *ptrSteps;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number in the Sequence:");
     printf("%d\n",eleptr->NumberOfSteps);

     printf("Auxiliary molecules for all steps:\n");
     PrintSetOfGraphs(eleptr->Molecules);

     printf("    The set of steps:\n");
     if(eleptr->Steps != 0)
          {
          ptrSteps = eleptr->Steps;
          LOOPi(eleptr->NumberOfSteps)
               PrintChainSequenceElement(ptrSteps++);
          }


}
extern void FreeChainSequence(ChainSequence *eleptr)
{
ChainSequenceElement *ptrSteps;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrSteps = eleptr->Steps;
     LOOPi(eleptr->NumberOfSteps)
          FreeChainSequenceElement(ptrSteps++);
     Free(eleptr->Steps);

     FreeSetOfGraphs(eleptr->Molecules);
     Free(eleptr->Molecules);

}
extern void WriteBinChainSequence(ChainSequence *eleptr, DbaseLinkedList *file)
{
ChainSequenceElement *ptrSteps;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfSteps),file);

     WriteBinSetOfGraphs(eleptr->Molecules,file);

     if(eleptr->Steps != 0)
          {
          ptrSteps = eleptr->Steps;
          LOOPi(eleptr->NumberOfSteps)
               WriteBinChainSequenceElement(ptrSteps++,file);
          }

}
extern INT ReadBinChainSequence(ChainSequence *eleptr,DbaseLinkedList *file)
     {
ChainSequenceElement *ptrSteps;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfSteps),file);

     eleptr->Molecules = AllocateSetOfGraphs;
     if(ReadBinSetOfGraphs(eleptr->Molecules,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Molecules);
           eleptr->Molecules = 0;
           }

          eleptr->Steps = AllocArrayChainSequenceElement(eleptr->NumberOfSteps);
          ptrSteps = eleptr->Steps;
          LOOPi(eleptr->NumberOfSteps)
               ReadBinChainSequenceElement(ptrSteps++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_ChainSequence(XDR *stream, char **eleptrp)
{
     ChainSequence *eleptr;
     eleptr = (ChainSequence *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfSteps));

     xdr_pointer(stream,
          (char **) &(eleptr->Molecules),
          SetOfGraphsSize,
                 (xdrproc_t) xdr_SetOfGraphs);
     xdr_array(stream,(char **) &(eleptr->Steps),
             (uint *) &(eleptr->NumberOfSteps),eleptr->NumberOfSteps,
               ChainSequenceElementSize,(xdrproc_t) xdr_ChainSequenceElement);
}

extern void *AllocChainSequence()
{
     return((void *) AllocateChainSequence);
}
