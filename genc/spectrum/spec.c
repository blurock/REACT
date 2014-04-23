
extern CHAR *GetNameSpectrumPair(SpectrumPair *str)
{
     return(str->Name);
}

extern INT GetIDSpectrumPair(SpectrumPair *str)
{
     return(str->ID);
}

extern SpectrumPair *CreateSpectrumPair(SpectrumPair *newstruct,
                                 INT id,
                                 CHAR *name,
                                 FLOAT  Frequency,
                                 FLOAT  PeakHeight)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Frequency = Frequency;
     newstruct->PeakHeight = PeakHeight;



     return(newstruct);
}


extern void CopyFullSpectrumPair(SpectrumPair *newstruct, SpectrumPair *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Frequency = oldstruct->Frequency;
     newstruct->PeakHeight = oldstruct->PeakHeight;



}
extern void PrintSpectrumPair(SpectrumPair *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("  Frequency of Point:");
     printf("%f\n",eleptr->Frequency);
     printf("         Peak Height:");
     printf("%f\n",eleptr->PeakHeight);

}
extern void FreeSpectrumPair(SpectrumPair *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinSpectrumPair(SpectrumPair *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinFLOAT(&(eleptr->Frequency),file);
     WriteBinFLOAT(&(eleptr->PeakHeight),file);

}
extern INT ReadBinSpectrumPair(SpectrumPair *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinFLOAT(&(eleptr->Frequency),file);
     ReadBinFLOAT(&(eleptr->PeakHeight),file);

     return(STRUCTURE_READ);
     }
extern void xdr_SpectrumPair(XDR *stream, char **eleptrp)
{
     SpectrumPair *eleptr;
     eleptr = (SpectrumPair *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_FLOAT(stream,(char **) &(eleptr->Frequency));
     xdr_FLOAT(stream,(char **) &(eleptr->PeakHeight));

}

extern void *AllocSpectrumPair()
{
     return((void *) AllocateSpectrumPair);
}

extern CHAR *GetNameSpectrum(Spectrum *str)
{
     return(str->Name);
}

extern INT GetIDSpectrum(Spectrum *str)
{
     return(str->ID);
}

extern Spectrum *CreateSpectrum(Spectrum *newstruct,
                         INT id,
                         CHAR *name,
                         INT  NumberOfPoints,
                         SpectrumPair *Points)
{
SpectrumPair *oldPoints,*newPoints;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfPoints = NumberOfPoints;

     newstruct->Points = AllocArraySpectrumPair(newstruct->NumberOfPoints);
     if(Points != 0)
          {
          oldPoints = Points;
          newPoints = newstruct->Points;
          LOOPi(newstruct->NumberOfPoints)
               CopyFullSpectrumPair(newPoints++, oldPoints++);
          }



     return(newstruct);
}


extern void CopyFullSpectrum(Spectrum *newstruct, Spectrum *oldstruct)
{
SpectrumPair *oldPoints,*newPoints;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfPoints = oldstruct->NumberOfPoints;


     newstruct->Points = AllocArraySpectrumPair(newstruct->NumberOfPoints);
     if(oldstruct->Points != 0)
          {
          oldPoints = oldstruct->Points;
          newPoints = newstruct->Points;
          LOOPi(newstruct->NumberOfPoints)
               CopyFullSpectrumPair(newPoints++, oldPoints++);
          }


}
extern void PrintSpectrum(Spectrum *eleptr)
{
SpectrumPair *ptrPoints;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("Number of Points in Spectrum:");
     printf("%d\n",eleptr->NumberOfPoints);

     printf("       Set of Points:\n");
     if(eleptr->Points != 0)
          {
          ptrPoints = eleptr->Points;
          LOOPi(eleptr->NumberOfPoints)
               PrintSpectrumPair(ptrPoints++);
          }


}
extern void FreeSpectrum(Spectrum *eleptr)
{
SpectrumPair *ptrPoints;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrPoints = eleptr->Points;
     LOOPi(eleptr->NumberOfPoints)
          FreeSpectrumPair(ptrPoints++);
     Free(eleptr->Points);

}
extern void WriteBinSpectrum(Spectrum *eleptr, DbaseLinkedList *file)
{
SpectrumPair *ptrPoints;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfPoints),file);

     if(eleptr->Points != 0)
          {
          ptrPoints = eleptr->Points;
          LOOPi(eleptr->NumberOfPoints)
               WriteBinSpectrumPair(ptrPoints++,file);
          }

}
extern INT ReadBinSpectrum(Spectrum *eleptr,DbaseLinkedList *file)
     {
SpectrumPair *ptrPoints;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfPoints),file);

          eleptr->Points = AllocArraySpectrumPair(eleptr->NumberOfPoints);
          ptrPoints = eleptr->Points;
          LOOPi(eleptr->NumberOfPoints)
               ReadBinSpectrumPair(ptrPoints++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_Spectrum(XDR *stream, char **eleptrp)
{
     Spectrum *eleptr;
     eleptr = (Spectrum *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfPoints));

     xdr_array(stream,(char **) &(eleptr->Points),
             (uint *) &(eleptr->NumberOfPoints),eleptr->NumberOfPoints,
               SpectrumPairSize,(xdrproc_t) xdr_SpectrumPair);
}

extern void *AllocSpectrum()
{
     return((void *) AllocateSpectrum);
}

extern CHAR *GetNameSpectrumSetData(SpectrumSetData *str)
{
     return(str->Name);
}

extern INT GetIDSpectrumSetData(SpectrumSetData *str)
{
     return(str->ID);
}

extern SpectrumSetData *CreateSpectrumSetData(SpectrumSetData *newstruct,
                                       INT id,
                                       CHAR *name,
                                       FLOAT  LargestSetFrequency,
                                       FLOAT  SmallestSetFrequency,
                                       FLOAT  LargestSetHeight,
                                       FLOAT  SmallestSetHeight,
                                       FLOAT  Interval)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->LargestSetFrequency = LargestSetFrequency;
     newstruct->SmallestSetFrequency = SmallestSetFrequency;
     newstruct->LargestSetHeight = LargestSetHeight;
     newstruct->SmallestSetHeight = SmallestSetHeight;
     newstruct->Interval = Interval;



     return(newstruct);
}


extern void CopyFullSpectrumSetData(SpectrumSetData *newstruct, SpectrumSetData *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->LargestSetFrequency = oldstruct->LargestSetFrequency;
     newstruct->SmallestSetFrequency = oldstruct->SmallestSetFrequency;
     newstruct->LargestSetHeight = oldstruct->LargestSetHeight;
     newstruct->SmallestSetHeight = oldstruct->SmallestSetHeight;
     newstruct->Interval = oldstruct->Interval;



}
extern void PrintSpectrumSetData(SpectrumSetData *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("   Largest Frequency:");
     printf("%f\n",eleptr->LargestSetFrequency);
     printf("  Smallest Frequency:");
     printf("%f\n",eleptr->SmallestSetFrequency);
     printf("      Largest Height:");
     printf("%f\n",eleptr->LargestSetHeight);
     printf("     Smallest Height:");
     printf("%f\n",eleptr->SmallestSetHeight);
     printf("Minimum Allowed Interval:");
     printf("%f\n",eleptr->Interval);

}
extern void FreeSpectrumSetData(SpectrumSetData *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinSpectrumSetData(SpectrumSetData *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinFLOAT(&(eleptr->LargestSetFrequency),file);
     WriteBinFLOAT(&(eleptr->SmallestSetFrequency),file);
     WriteBinFLOAT(&(eleptr->LargestSetHeight),file);
     WriteBinFLOAT(&(eleptr->SmallestSetHeight),file);
     WriteBinFLOAT(&(eleptr->Interval),file);

}
extern INT ReadBinSpectrumSetData(SpectrumSetData *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinFLOAT(&(eleptr->LargestSetFrequency),file);
     ReadBinFLOAT(&(eleptr->SmallestSetFrequency),file);
     ReadBinFLOAT(&(eleptr->LargestSetHeight),file);
     ReadBinFLOAT(&(eleptr->SmallestSetHeight),file);
     ReadBinFLOAT(&(eleptr->Interval),file);

     return(STRUCTURE_READ);
     }
extern void xdr_SpectrumSetData(XDR *stream, char **eleptrp)
{
     SpectrumSetData *eleptr;
     eleptr = (SpectrumSetData *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_FLOAT(stream,(char **) &(eleptr->LargestSetFrequency));
     xdr_FLOAT(stream,(char **) &(eleptr->SmallestSetFrequency));
     xdr_FLOAT(stream,(char **) &(eleptr->LargestSetHeight));
     xdr_FLOAT(stream,(char **) &(eleptr->SmallestSetHeight));
     xdr_FLOAT(stream,(char **) &(eleptr->Interval));

}

extern void *AllocSpectrumSetData()
{
     return((void *) AllocateSpectrumSetData);
}

extern CHAR *GetNameSpectrumSetStandard(SpectrumSetStandard *str)
{
     return(str->Name);
}

extern INT GetIDSpectrumSetStandard(SpectrumSetStandard *str)
{
     return(str->ID);
}

extern SpectrumSetStandard *CreateSpectrumSetStandard(SpectrumSetStandard *newstruct,
                                               INT id,
                                               CHAR *name,
                                               FLOAT  BeginFrequency,
                                               FLOAT  EndFrequency,
                                               INT  NumberOfIntervals,
                                               FLOAT  Interval)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->BeginFrequency = BeginFrequency;
     newstruct->EndFrequency = EndFrequency;
     newstruct->NumberOfIntervals = NumberOfIntervals;
     newstruct->Interval = Interval;



     return(newstruct);
}


extern void CopyFullSpectrumSetStandard(SpectrumSetStandard *newstruct, SpectrumSetStandard *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->BeginFrequency = oldstruct->BeginFrequency;
     newstruct->EndFrequency = oldstruct->EndFrequency;
     newstruct->NumberOfIntervals = oldstruct->NumberOfIntervals;
     newstruct->Interval = oldstruct->Interval;



}
extern void PrintSpectrumSetStandard(SpectrumSetStandard *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("     Begin Frequency:");
     printf("%f\n",eleptr->BeginFrequency);
     printf("       End Frequency:");
     printf("%f\n",eleptr->EndFrequency);
     printf(" Number of Intervals:");
     printf("%d\n",eleptr->NumberOfIntervals);
     printf("       Interval Size:");
     printf("%f\n",eleptr->Interval);

}
extern void FreeSpectrumSetStandard(SpectrumSetStandard *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinSpectrumSetStandard(SpectrumSetStandard *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinFLOAT(&(eleptr->BeginFrequency),file);
     WriteBinFLOAT(&(eleptr->EndFrequency),file);
     WriteBinINT(&(eleptr->NumberOfIntervals),file);
     WriteBinFLOAT(&(eleptr->Interval),file);

}
extern INT ReadBinSpectrumSetStandard(SpectrumSetStandard *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinFLOAT(&(eleptr->BeginFrequency),file);
     ReadBinFLOAT(&(eleptr->EndFrequency),file);
     ReadBinINT(&(eleptr->NumberOfIntervals),file);
     ReadBinFLOAT(&(eleptr->Interval),file);

     return(STRUCTURE_READ);
     }
extern void xdr_SpectrumSetStandard(XDR *stream, char **eleptrp)
{
     SpectrumSetStandard *eleptr;
     eleptr = (SpectrumSetStandard *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_FLOAT(stream,(char **) &(eleptr->BeginFrequency));
     xdr_FLOAT(stream,(char **) &(eleptr->EndFrequency));
     xdr_INT(stream,(char **) &(eleptr->NumberOfIntervals));
     xdr_FLOAT(stream,(char **) &(eleptr->Interval));

}

extern void *AllocSpectrumSetStandard()
{
     return((void *) AllocateSpectrumSetStandard);
}

extern CHAR *GetNameSpectrumStandard(SpectrumStandard *str)
{
     return(str->Name);
}

extern INT GetIDSpectrumStandard(SpectrumStandard *str)
{
     return(str->ID);
}

extern SpectrumStandard *CreateSpectrumStandard(SpectrumStandard *newstruct,
                                         INT id,
                                         CHAR *name,
                                         INT  NumberOfFrequencies,
                                         FLOAT *Heights)
{
FLOAT *oldHeights,*newHeights;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfFrequencies = NumberOfFrequencies;

     newstruct->Heights = AllocArrayFLOAT(newstruct->NumberOfFrequencies);
     if(Heights != 0)
          {
          oldHeights = Heights;
          newHeights = newstruct->Heights;
          LOOPi(newstruct->NumberOfFrequencies)
               CopyFullFLOAT(newHeights++, oldHeights++);
          }



     return(newstruct);
}


extern void CopyFullSpectrumStandard(SpectrumStandard *newstruct, SpectrumStandard *oldstruct)
{
FLOAT *oldHeights,*newHeights;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfFrequencies = oldstruct->NumberOfFrequencies;


     newstruct->Heights = AllocArrayFLOAT(newstruct->NumberOfFrequencies);
     if(oldstruct->Heights != 0)
          {
          oldHeights = oldstruct->Heights;
          newHeights = newstruct->Heights;
          LOOPi(newstruct->NumberOfFrequencies)
               CopyFullFLOAT(newHeights++, oldHeights++);
          }


}
extern void PrintSpectrumStandard(SpectrumStandard *eleptr)
{
FLOAT *ptrHeights;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("Number of Frequencies:");
     printf("%d\n",eleptr->NumberOfFrequencies);

     printf("      Set of Heights:\n");
     if(eleptr->Heights != 0)
          {
          ptrHeights = eleptr->Heights;
          LOOPi(eleptr->NumberOfFrequencies)
               PrintFLOAT(ptrHeights++);
          }


}
extern void FreeSpectrumStandard(SpectrumStandard *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Heights);

}
extern void WriteBinSpectrumStandard(SpectrumStandard *eleptr, DbaseLinkedList *file)
{
FLOAT *ptrHeights;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfFrequencies),file);

     if(eleptr->Heights != 0)
          {
          ptrHeights = eleptr->Heights;
          LOOPi(eleptr->NumberOfFrequencies)
               WriteBinFLOAT(ptrHeights++,file);
          }

}
extern INT ReadBinSpectrumStandard(SpectrumStandard *eleptr,DbaseLinkedList *file)
     {
FLOAT *ptrHeights;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfFrequencies),file);

          eleptr->Heights = AllocArrayFLOAT(eleptr->NumberOfFrequencies);
          ptrHeights = eleptr->Heights;
          LOOPi(eleptr->NumberOfFrequencies)
               ReadBinFLOAT(ptrHeights++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SpectrumStandard(XDR *stream, char **eleptrp)
{
     SpectrumStandard *eleptr;
     eleptr = (SpectrumStandard *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfFrequencies));

     xdr_array(stream,(char **) &(eleptr->Heights),
             (uint *) &(eleptr->NumberOfFrequencies),eleptr->NumberOfFrequencies,
               FLOATSize,(xdrproc_t) xdr_FLOAT);
}

extern void *AllocSpectrumStandard()
{
     return((void *) AllocateSpectrumStandard);
}

extern CHAR *GetNameSpectrumName(SpectrumName *str)
{
     return(str->Name);
}

extern INT GetIDSpectrumName(SpectrumName *str)
{
     return(str->ID);
}

extern SpectrumName *CreateSpectrumName(SpectrumName *newstruct,
                                 INT id,
                                 CHAR *name)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;



     return(newstruct);
}


extern void CopyFullSpectrumName(SpectrumName *newstruct, SpectrumName *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);



}
extern void PrintSpectrumName(SpectrumName *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

}
extern void FreeSpectrumName(SpectrumName *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinSpectrumName(SpectrumName *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

}
extern INT ReadBinSpectrumName(SpectrumName *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     return(STRUCTURE_READ);
     }
extern void xdr_SpectrumName(XDR *stream, char **eleptrp)
{
     SpectrumName *eleptr;
     eleptr = (SpectrumName *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

}

extern void *AllocSpectrumName()
{
     return((void *) AllocateSpectrumName);
}

extern CHAR *GetNameSpectrumSetOrder(SpectrumSetOrder *str)
{
     return(str->Name);
}

extern INT GetIDSpectrumSetOrder(SpectrumSetOrder *str)
{
     return(str->ID);
}

extern SpectrumSetOrder *CreateSpectrumSetOrder(SpectrumSetOrder *newstruct,
                                         INT id,
                                         CHAR *name,
                                         INT  NumberOfSpectra,
                                         SpectrumName *Names)
{
SpectrumName *oldNames,*newNames;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfSpectra = NumberOfSpectra;

     newstruct->Names = AllocArraySpectrumName(newstruct->NumberOfSpectra);
     if(Names != 0)
          {
          oldNames = Names;
          newNames = newstruct->Names;
          LOOPi(newstruct->NumberOfSpectra)
               CopyFullSpectrumName(newNames++, oldNames++);
          }



     return(newstruct);
}


extern void CopyFullSpectrumSetOrder(SpectrumSetOrder *newstruct, SpectrumSetOrder *oldstruct)
{
SpectrumName *oldNames,*newNames;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfSpectra = oldstruct->NumberOfSpectra;


     newstruct->Names = AllocArraySpectrumName(newstruct->NumberOfSpectra);
     if(oldstruct->Names != 0)
          {
          oldNames = oldstruct->Names;
          newNames = newstruct->Names;
          LOOPi(newstruct->NumberOfSpectra)
               CopyFullSpectrumName(newNames++, oldNames++);
          }


}
extern void PrintSpectrumSetOrder(SpectrumSetOrder *eleptr)
{
SpectrumName *ptrNames;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("    NumberOfSpectrum:");
     printf("%d\n",eleptr->NumberOfSpectra);

     printf("Ordered List of Names:\n");
     if(eleptr->Names != 0)
          {
          ptrNames = eleptr->Names;
          LOOPi(eleptr->NumberOfSpectra)
               PrintSpectrumName(ptrNames++);
          }


}
extern void FreeSpectrumSetOrder(SpectrumSetOrder *eleptr)
{
SpectrumName *ptrNames;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrNames = eleptr->Names;
     LOOPi(eleptr->NumberOfSpectra)
          FreeSpectrumName(ptrNames++);
     Free(eleptr->Names);

}
extern void WriteBinSpectrumSetOrder(SpectrumSetOrder *eleptr, DbaseLinkedList *file)
{
SpectrumName *ptrNames;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfSpectra),file);

     if(eleptr->Names != 0)
          {
          ptrNames = eleptr->Names;
          LOOPi(eleptr->NumberOfSpectra)
               WriteBinSpectrumName(ptrNames++,file);
          }

}
extern INT ReadBinSpectrumSetOrder(SpectrumSetOrder *eleptr,DbaseLinkedList *file)
     {
SpectrumName *ptrNames;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfSpectra),file);

          eleptr->Names = AllocArraySpectrumName(eleptr->NumberOfSpectra);
          ptrNames = eleptr->Names;
          LOOPi(eleptr->NumberOfSpectra)
               ReadBinSpectrumName(ptrNames++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SpectrumSetOrder(XDR *stream, char **eleptrp)
{
     SpectrumSetOrder *eleptr;
     eleptr = (SpectrumSetOrder *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfSpectra));

     xdr_array(stream,(char **) &(eleptr->Names),
             (uint *) &(eleptr->NumberOfSpectra),eleptr->NumberOfSpectra,
               SpectrumNameSize,(xdrproc_t) xdr_SpectrumName);
}

extern void *AllocSpectrumSetOrder()
{
     return((void *) AllocateSpectrumSetOrder);
}

extern CHAR *GetNameSpectrumStandardSet(SpectrumStandardSet *str)
{
     return(str->Name);
}

extern INT GetIDSpectrumStandardSet(SpectrumStandardSet *str)
{
     return(str->ID);
}

extern SpectrumStandardSet *CreateSpectrumStandardSet(SpectrumStandardSet *newstruct,
                                               INT id,
                                               CHAR *name,
                                               INT  NumberOfSpectra,
                                               SpectrumStandard *Standard,
                                               SpectrumStandard *Difference)
{
SpectrumStandard *oldStandard,*newStandard;
SpectrumStandard *oldDifference,*newDifference;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfSpectra = NumberOfSpectra;

     newstruct->Standard = AllocArraySpectrumStandard(newstruct->NumberOfSpectra);
     if(Standard != 0)
          {
          oldStandard = Standard;
          newStandard = newstruct->Standard;
          LOOPi(newstruct->NumberOfSpectra)
               CopyFullSpectrumStandard(newStandard++, oldStandard++);
          }

     newstruct->Difference = AllocArraySpectrumStandard(newstruct->NumberOfSpectra);
     if(Difference != 0)
          {
          oldDifference = Difference;
          newDifference = newstruct->Difference;
          LOOPi(newstruct->NumberOfSpectra)
               CopyFullSpectrumStandard(newDifference++, oldDifference++);
          }



     return(newstruct);
}


extern void CopyFullSpectrumStandardSet(SpectrumStandardSet *newstruct, SpectrumStandardSet *oldstruct)
{
SpectrumStandard *oldStandard,*newStandard;
SpectrumStandard *oldDifference,*newDifference;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfSpectra = oldstruct->NumberOfSpectra;


     newstruct->Standard = AllocArraySpectrumStandard(newstruct->NumberOfSpectra);
     if(oldstruct->Standard != 0)
          {
          oldStandard = oldstruct->Standard;
          newStandard = newstruct->Standard;
          LOOPi(newstruct->NumberOfSpectra)
               CopyFullSpectrumStandard(newStandard++, oldStandard++);
          }

     newstruct->Difference = AllocArraySpectrumStandard(newstruct->NumberOfSpectra);
     if(oldstruct->Difference != 0)
          {
          oldDifference = oldstruct->Difference;
          newDifference = newstruct->Difference;
          LOOPi(newstruct->NumberOfSpectra)
               CopyFullSpectrumStandard(newDifference++, oldDifference++);
          }


}
extern void PrintSpectrumStandardSet(SpectrumStandardSet *eleptr)
{
SpectrumStandard *ptrStandard;
SpectrumStandard *ptrDifference;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("     NumberOfSpectra:");
     printf("%d\n",eleptr->NumberOfSpectra);

     printf("   Standard Spectrum:\n");
     if(eleptr->Standard != 0)
          {
          ptrStandard = eleptr->Standard;
          LOOPi(eleptr->NumberOfSpectra)
               PrintSpectrumStandard(ptrStandard++);
          }


     printf("The Difference Spectra:\n");
     if(eleptr->Difference != 0)
          {
          ptrDifference = eleptr->Difference;
          LOOPi(eleptr->NumberOfSpectra)
               PrintSpectrumStandard(ptrDifference++);
          }


}
extern void FreeSpectrumStandardSet(SpectrumStandardSet *eleptr)
{
SpectrumStandard *ptrStandard;
SpectrumStandard *ptrDifference;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrStandard = eleptr->Standard;
     LOOPi(eleptr->NumberOfSpectra)
          FreeSpectrumStandard(ptrStandard++);
     Free(eleptr->Standard);

     ptrDifference = eleptr->Difference;
     LOOPi(eleptr->NumberOfSpectra)
          FreeSpectrumStandard(ptrDifference++);
     Free(eleptr->Difference);

}
extern void WriteBinSpectrumStandardSet(SpectrumStandardSet *eleptr, DbaseLinkedList *file)
{
SpectrumStandard *ptrStandard;
SpectrumStandard *ptrDifference;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfSpectra),file);

     if(eleptr->Standard != 0)
          {
          ptrStandard = eleptr->Standard;
          LOOPi(eleptr->NumberOfSpectra)
               WriteBinSpectrumStandard(ptrStandard++,file);
          }

     if(eleptr->Difference != 0)
          {
          ptrDifference = eleptr->Difference;
          LOOPi(eleptr->NumberOfSpectra)
               WriteBinSpectrumStandard(ptrDifference++,file);
          }

}
extern INT ReadBinSpectrumStandardSet(SpectrumStandardSet *eleptr,DbaseLinkedList *file)
     {
SpectrumStandard *ptrStandard;
SpectrumStandard *ptrDifference;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfSpectra),file);

          eleptr->Standard = AllocArraySpectrumStandard(eleptr->NumberOfSpectra);
          ptrStandard = eleptr->Standard;
          LOOPi(eleptr->NumberOfSpectra)
               ReadBinSpectrumStandard(ptrStandard++,file);

          eleptr->Difference = AllocArraySpectrumStandard(eleptr->NumberOfSpectra);
          ptrDifference = eleptr->Difference;
          LOOPi(eleptr->NumberOfSpectra)
               ReadBinSpectrumStandard(ptrDifference++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SpectrumStandardSet(XDR *stream, char **eleptrp)
{
     SpectrumStandardSet *eleptr;
     eleptr = (SpectrumStandardSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfSpectra));

     xdr_array(stream,(char **) &(eleptr->Standard),
             (uint *) &(eleptr->NumberOfSpectra),eleptr->NumberOfSpectra,
               SpectrumStandardSize,(xdrproc_t) xdr_SpectrumStandard);
     xdr_array(stream,(char **) &(eleptr->Difference),
             (uint *) &(eleptr->NumberOfSpectra),eleptr->NumberOfSpectra,
               SpectrumStandardSize,(xdrproc_t) xdr_SpectrumStandard);
}

extern void *AllocSpectrumStandardSet()
{
     return((void *) AllocateSpectrumStandardSet);
}

extern CHAR *GetNameSpectrumSet(SpectrumSet *str)
{
     return(str->Name);
}

extern INT GetIDSpectrumSet(SpectrumSet *str)
{
     return(str->ID);
}

extern SpectrumSet *CreateSpectrumSet(SpectrumSet *newstruct,
                               INT id,
                               CHAR *name,
                               INT  NumberOfSpectra,
                               Spectrum *Spectra,
                               SpectrumSetData *Data,
                               SpectrumSetStandard *Standard,
                               SpectrumStandardSet *Standards,
                               SpectrumSetOrder *Order)
{
Spectrum *oldSpectra,*newSpectra;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfSpectra = NumberOfSpectra;
     if(Data != 0)
          {
          newstruct->Data = AllocateSpectrumSetData;
          CopyFullSpectrumSetData(newstruct->Data, Data);
          }
     else
          newstruct->Data = 0;
     if(Standard != 0)
          {
          newstruct->Standard = AllocateSpectrumSetStandard;
          CopyFullSpectrumSetStandard(newstruct->Standard, Standard);
          }
     else
          newstruct->Standard = 0;
     if(Standards != 0)
          {
          newstruct->Standards = AllocateSpectrumStandardSet;
          CopyFullSpectrumStandardSet(newstruct->Standards, Standards);
          }
     else
          newstruct->Standards = 0;
     if(Order != 0)
          {
          newstruct->Order = AllocateSpectrumSetOrder;
          CopyFullSpectrumSetOrder(newstruct->Order, Order);
          }
     else
          newstruct->Order = 0;

     newstruct->Spectra = AllocArraySpectrum(newstruct->NumberOfSpectra);
     if(Spectra != 0)
          {
          oldSpectra = Spectra;
          newSpectra = newstruct->Spectra;
          LOOPi(newstruct->NumberOfSpectra)
               CopyFullSpectrum(newSpectra++, oldSpectra++);
          }



     return(newstruct);
}


extern void CopyFullSpectrumSet(SpectrumSet *newstruct, SpectrumSet *oldstruct)
{
Spectrum *oldSpectra,*newSpectra;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfSpectra = oldstruct->NumberOfSpectra;

     if(oldstruct->Data != 0)
          {
          newstruct->Data = AllocateSpectrumSetData;
          CopyFullSpectrumSetData(newstruct->Data, oldstruct->Data);
          }
     else
          newstruct->Data = 0;
     if(oldstruct->Standard != 0)
          {
          newstruct->Standard = AllocateSpectrumSetStandard;
          CopyFullSpectrumSetStandard(newstruct->Standard, oldstruct->Standard);
          }
     else
          newstruct->Standard = 0;
     if(oldstruct->Standards != 0)
          {
          newstruct->Standards = AllocateSpectrumStandardSet;
          CopyFullSpectrumStandardSet(newstruct->Standards, oldstruct->Standards);
          }
     else
          newstruct->Standards = 0;
     if(oldstruct->Order != 0)
          {
          newstruct->Order = AllocateSpectrumSetOrder;
          CopyFullSpectrumSetOrder(newstruct->Order, oldstruct->Order);
          }
     else
          newstruct->Order = 0;

     newstruct->Spectra = AllocArraySpectrum(newstruct->NumberOfSpectra);
     if(oldstruct->Spectra != 0)
          {
          oldSpectra = oldstruct->Spectra;
          newSpectra = newstruct->Spectra;
          LOOPi(newstruct->NumberOfSpectra)
               CopyFullSpectrum(newSpectra++, oldSpectra++);
          }


}
extern void PrintSpectrumSet(SpectrumSet *eleptr)
{
Spectrum *ptrSpectra;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("  Number Of Spectra :");
     printf("%d\n",eleptr->NumberOfSpectra);

     printf("Data about the set of spectra :\n");
     PrintSpectrumSetData(eleptr->Data);

     printf("Definitions of the Standard Spectrum:\n");
     PrintSpectrumSetStandard(eleptr->Standard);

     printf("Set of Standard Spectra:\n");
     PrintSpectrumStandardSet(eleptr->Standards);

     printf("   Ordering of Names:\n");
     PrintSpectrumSetOrder(eleptr->Order);

     printf("  The set of Spectra:\n");
     if(eleptr->Spectra != 0)
          {
          ptrSpectra = eleptr->Spectra;
          LOOPi(eleptr->NumberOfSpectra)
               PrintSpectrum(ptrSpectra++);
          }


}
extern void FreeSpectrumSet(SpectrumSet *eleptr)
{
Spectrum *ptrSpectra;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrSpectra = eleptr->Spectra;
     LOOPi(eleptr->NumberOfSpectra)
          FreeSpectrum(ptrSpectra++);
     Free(eleptr->Spectra);

     FreeSpectrumSetData(eleptr->Data);
     Free(eleptr->Data);

     FreeSpectrumSetStandard(eleptr->Standard);
     Free(eleptr->Standard);

     FreeSpectrumStandardSet(eleptr->Standards);
     Free(eleptr->Standards);

     FreeSpectrumSetOrder(eleptr->Order);
     Free(eleptr->Order);

}
extern void WriteBinSpectrumSet(SpectrumSet *eleptr, DbaseLinkedList *file)
{
Spectrum *ptrSpectra;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfSpectra),file);

     WriteBinSpectrumSetData(eleptr->Data,file);

     WriteBinSpectrumSetStandard(eleptr->Standard,file);

     WriteBinSpectrumStandardSet(eleptr->Standards,file);

     WriteBinSpectrumSetOrder(eleptr->Order,file);

     if(eleptr->Spectra != 0)
          {
          ptrSpectra = eleptr->Spectra;
          LOOPi(eleptr->NumberOfSpectra)
               WriteBinSpectrum(ptrSpectra++,file);
          }

}
extern INT ReadBinSpectrumSet(SpectrumSet *eleptr,DbaseLinkedList *file)
     {
Spectrum *ptrSpectra;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfSpectra),file);

     eleptr->Data = AllocateSpectrumSetData;
     if(ReadBinSpectrumSetData(eleptr->Data,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Data);
           eleptr->Data = 0;
           }

     eleptr->Standard = AllocateSpectrumSetStandard;
     if(ReadBinSpectrumSetStandard(eleptr->Standard,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Standard);
           eleptr->Standard = 0;
           }

     eleptr->Standards = AllocateSpectrumStandardSet;
     if(ReadBinSpectrumStandardSet(eleptr->Standards,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Standards);
           eleptr->Standards = 0;
           }

     eleptr->Order = AllocateSpectrumSetOrder;
     if(ReadBinSpectrumSetOrder(eleptr->Order,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Order);
           eleptr->Order = 0;
           }

          eleptr->Spectra = AllocArraySpectrum(eleptr->NumberOfSpectra);
          ptrSpectra = eleptr->Spectra;
          LOOPi(eleptr->NumberOfSpectra)
               ReadBinSpectrum(ptrSpectra++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SpectrumSet(XDR *stream, char **eleptrp)
{
     SpectrumSet *eleptr;
     eleptr = (SpectrumSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfSpectra));

     xdr_pointer(stream,
          (char **) &(eleptr->Data),
          SpectrumSetDataSize,
                 (xdrproc_t) xdr_SpectrumSetData);
     xdr_pointer(stream,
          (char **) &(eleptr->Standard),
          SpectrumSetStandardSize,
                 (xdrproc_t) xdr_SpectrumSetStandard);
     xdr_pointer(stream,
          (char **) &(eleptr->Standards),
          SpectrumStandardSetSize,
                 (xdrproc_t) xdr_SpectrumStandardSet);
     xdr_pointer(stream,
          (char **) &(eleptr->Order),
          SpectrumSetOrderSize,
                 (xdrproc_t) xdr_SpectrumSetOrder);
     xdr_array(stream,(char **) &(eleptr->Spectra),
             (uint *) &(eleptr->NumberOfSpectra),eleptr->NumberOfSpectra,
               SpectrumSize,(xdrproc_t) xdr_Spectrum);
}

extern void *AllocSpectrumSet()
{
     return((void *) AllocateSpectrumSet);
}
