/*------------------------------------------*/
/*   Structures for Spectrum   */
/* Structure:0:SpectrumPair

                Frequency --(FLOAT) Frequency of Point
               PeakHeight --(FLOAT) Peak Height
*/
typedef struct spectrumpair SpectrumPair;
struct spectrumpair {
     INT ID;
     CHAR *Name;
     FLOAT  Frequency;
     FLOAT  PeakHeight;
     };
#define SpectrumPairSize sizeof(SpectrumPair)
#define AllocateSpectrumPair (SpectrumPair *) Malloc(SpectrumPairSize)
#define AllocArraySpectrumPair(n) (SpectrumPair *) Calloc(n,SpectrumPairSize)
#define SpectrumPairPntrSize sizeof(SpectrumPair **)
#define AllocPntrArraySpectrumPair(n) (SpectrumPair **) Calloc(n,SpectrumPairPntrSize)
#define SingCopySpectrumPair(out,in) memcpy(out,in,SpectrumPairSize)
extern SpectrumPair *CreateSpectrumPair(SpectrumPair *newstruct,
                                 INT id,
                                 CHAR *name,
                                 FLOAT  Frequency,
                                 FLOAT  PeakHeight);

extern CHAR *GetNameSpectrumPair(SpectrumPair *str);
extern INT  GetIDSpectrumPair(SpectrumPair *str);
extern void PrintSpectrumPair(SpectrumPair *eleptr);
extern void FreeSpectrumPair(SpectrumPair *eleptr);
extern void *AllocSpectrumPair();
extern void WriteBinSpectrumPair(SpectrumPair *eleptr, DbaseLinkedList *file);
extern INT ReadBinSpectrumPair(SpectrumPair *eleptr, DbaseLinkedList *file);
extern void xdr_SpectrumPair(XDR *stream, char **eleptr);
extern void CopyFullSpectrumPair(SpectrumPair *newstruct, SpectrumPair *oldstruct);
/*------------------------------------------*/
/*   Structures for Spectrum   */
/* Structure:1:Spectrum

           NumberOfPoints --(INT) Number of Points in Spectrum
                   Points --(SpectrumPair) Set of Points
*/
typedef struct spectrum Spectrum;
struct spectrum {
     INT ID;
     CHAR *Name;
     INT  NumberOfPoints;
     SpectrumPair *Points;
     };
#define SpectrumSize sizeof(Spectrum)
#define AllocateSpectrum (Spectrum *) Malloc(SpectrumSize)
#define AllocArraySpectrum(n) (Spectrum *) Calloc(n,SpectrumSize)
#define SpectrumPntrSize sizeof(Spectrum **)
#define AllocPntrArraySpectrum(n) (Spectrum **) Calloc(n,SpectrumPntrSize)
#define SingCopySpectrum(out,in) memcpy(out,in,SpectrumSize)
extern Spectrum *CreateSpectrum(Spectrum *newstruct,
                         INT id,
                         CHAR *name,
                         INT  NumberOfPoints,
                         SpectrumPair *Points);

extern CHAR *GetNameSpectrum(Spectrum *str);
extern INT  GetIDSpectrum(Spectrum *str);
extern void PrintSpectrum(Spectrum *eleptr);
extern void FreeSpectrum(Spectrum *eleptr);
extern void *AllocSpectrum();
extern void WriteBinSpectrum(Spectrum *eleptr, DbaseLinkedList *file);
extern INT ReadBinSpectrum(Spectrum *eleptr, DbaseLinkedList *file);
extern void xdr_Spectrum(XDR *stream, char **eleptr);
extern void CopyFullSpectrum(Spectrum *newstruct, Spectrum *oldstruct);
/*------------------------------------------*/
/*   Structures for Spectrum   */
/* Structure:2:SpectrumSetData

      LargestSetFrequency --(FLOAT) Largest Frequency
     SmallestSetFrequency --(FLOAT) Smallest Frequency
         LargestSetHeight --(FLOAT) Largest Height
        SmallestSetHeight --(FLOAT) Smallest Height
                 Interval --(FLOAT) Minimum Allowed Interval
*/
typedef struct spectrumsetdata SpectrumSetData;
struct spectrumsetdata {
     INT ID;
     CHAR *Name;
     FLOAT  LargestSetFrequency;
     FLOAT  SmallestSetFrequency;
     FLOAT  LargestSetHeight;
     FLOAT  SmallestSetHeight;
     FLOAT  Interval;
     };
#define SpectrumSetDataSize sizeof(SpectrumSetData)
#define AllocateSpectrumSetData (SpectrumSetData *) Malloc(SpectrumSetDataSize)
#define AllocArraySpectrumSetData(n) (SpectrumSetData *) Calloc(n,SpectrumSetDataSize)
#define SpectrumSetDataPntrSize sizeof(SpectrumSetData **)
#define AllocPntrArraySpectrumSetData(n) (SpectrumSetData **) Calloc(n,SpectrumSetDataPntrSize)
#define SingCopySpectrumSetData(out,in) memcpy(out,in,SpectrumSetDataSize)
extern SpectrumSetData *CreateSpectrumSetData(SpectrumSetData *newstruct,
                                       INT id,
                                       CHAR *name,
                                       FLOAT  LargestSetFrequency,
                                       FLOAT  SmallestSetFrequency,
                                       FLOAT  LargestSetHeight,
                                       FLOAT  SmallestSetHeight,
                                       FLOAT  Interval);

extern CHAR *GetNameSpectrumSetData(SpectrumSetData *str);
extern INT  GetIDSpectrumSetData(SpectrumSetData *str);
extern void PrintSpectrumSetData(SpectrumSetData *eleptr);
extern void FreeSpectrumSetData(SpectrumSetData *eleptr);
extern void *AllocSpectrumSetData();
extern void WriteBinSpectrumSetData(SpectrumSetData *eleptr, DbaseLinkedList *file);
extern INT ReadBinSpectrumSetData(SpectrumSetData *eleptr, DbaseLinkedList *file);
extern void xdr_SpectrumSetData(XDR *stream, char **eleptr);
extern void CopyFullSpectrumSetData(SpectrumSetData *newstruct, SpectrumSetData *oldstruct);
/*------------------------------------------*/
/*   Structures for Spectrum   */
/* Structure:3:SpectrumSetStandard

           BeginFrequency --(FLOAT) Begin Frequency
             EndFrequency --(FLOAT) End Frequency
        NumberOfIntervals --(INT) Number of Intervals
                 Interval --(FLOAT) Interval Size
*/
typedef struct spectrumsetstandard SpectrumSetStandard;
struct spectrumsetstandard {
     INT ID;
     CHAR *Name;
     FLOAT  BeginFrequency;
     FLOAT  EndFrequency;
     INT  NumberOfIntervals;
     FLOAT  Interval;
     };
#define SpectrumSetStandardSize sizeof(SpectrumSetStandard)
#define AllocateSpectrumSetStandard (SpectrumSetStandard *) Malloc(SpectrumSetStandardSize)
#define AllocArraySpectrumSetStandard(n) (SpectrumSetStandard *) Calloc(n,SpectrumSetStandardSize)
#define SpectrumSetStandardPntrSize sizeof(SpectrumSetStandard **)
#define AllocPntrArraySpectrumSetStandard(n) (SpectrumSetStandard **) Calloc(n,SpectrumSetStandardPntrSize)
#define SingCopySpectrumSetStandard(out,in) memcpy(out,in,SpectrumSetStandardSize)
extern SpectrumSetStandard *CreateSpectrumSetStandard(SpectrumSetStandard *newstruct,
                                               INT id,
                                               CHAR *name,
                                               FLOAT  BeginFrequency,
                                               FLOAT  EndFrequency,
                                               INT  NumberOfIntervals,
                                               FLOAT  Interval);

extern CHAR *GetNameSpectrumSetStandard(SpectrumSetStandard *str);
extern INT  GetIDSpectrumSetStandard(SpectrumSetStandard *str);
extern void PrintSpectrumSetStandard(SpectrumSetStandard *eleptr);
extern void FreeSpectrumSetStandard(SpectrumSetStandard *eleptr);
extern void *AllocSpectrumSetStandard();
extern void WriteBinSpectrumSetStandard(SpectrumSetStandard *eleptr, DbaseLinkedList *file);
extern INT ReadBinSpectrumSetStandard(SpectrumSetStandard *eleptr, DbaseLinkedList *file);
extern void xdr_SpectrumSetStandard(XDR *stream, char **eleptr);
extern void CopyFullSpectrumSetStandard(SpectrumSetStandard *newstruct, SpectrumSetStandard *oldstruct);
/*------------------------------------------*/
/*   Structures for Spectrum   */
/* Structure:5:SpectrumStandard

      NumberOfFrequencies --(INT) Number of Frequencies
                  Heights --(FLOAT) Set of Heights
*/
typedef struct spectrumstandard SpectrumStandard;
struct spectrumstandard {
     INT ID;
     CHAR *Name;
     INT  NumberOfFrequencies;
     FLOAT *Heights;
     };
#define SpectrumStandardSize sizeof(SpectrumStandard)
#define AllocateSpectrumStandard (SpectrumStandard *) Malloc(SpectrumStandardSize)
#define AllocArraySpectrumStandard(n) (SpectrumStandard *) Calloc(n,SpectrumStandardSize)
#define SpectrumStandardPntrSize sizeof(SpectrumStandard **)
#define AllocPntrArraySpectrumStandard(n) (SpectrumStandard **) Calloc(n,SpectrumStandardPntrSize)
#define SingCopySpectrumStandard(out,in) memcpy(out,in,SpectrumStandardSize)
extern SpectrumStandard *CreateSpectrumStandard(SpectrumStandard *newstruct,
                                         INT id,
                                         CHAR *name,
                                         INT  NumberOfFrequencies,
                                         FLOAT *Heights);

extern CHAR *GetNameSpectrumStandard(SpectrumStandard *str);
extern INT  GetIDSpectrumStandard(SpectrumStandard *str);
extern void PrintSpectrumStandard(SpectrumStandard *eleptr);
extern void FreeSpectrumStandard(SpectrumStandard *eleptr);
extern void *AllocSpectrumStandard();
extern void WriteBinSpectrumStandard(SpectrumStandard *eleptr, DbaseLinkedList *file);
extern INT ReadBinSpectrumStandard(SpectrumStandard *eleptr, DbaseLinkedList *file);
extern void xdr_SpectrumStandard(XDR *stream, char **eleptr);
extern void CopyFullSpectrumStandard(SpectrumStandard *newstruct, SpectrumStandard *oldstruct);
/*------------------------------------------*/
/*   Structures for Spectrum   */
/* Structure:4:SpectrumName

*/
typedef struct spectrumname SpectrumName;
struct spectrumname {
     INT ID;
     CHAR *Name;
     };
#define SpectrumNameSize sizeof(SpectrumName)
#define AllocateSpectrumName (SpectrumName *) Malloc(SpectrumNameSize)
#define AllocArraySpectrumName(n) (SpectrumName *) Calloc(n,SpectrumNameSize)
#define SpectrumNamePntrSize sizeof(SpectrumName **)
#define AllocPntrArraySpectrumName(n) (SpectrumName **) Calloc(n,SpectrumNamePntrSize)
#define SingCopySpectrumName(out,in) memcpy(out,in,SpectrumNameSize)
extern SpectrumName *CreateSpectrumName(SpectrumName *newstruct,
                                 INT id,
                                 CHAR *name);

extern CHAR *GetNameSpectrumName(SpectrumName *str);
extern INT  GetIDSpectrumName(SpectrumName *str);
extern void PrintSpectrumName(SpectrumName *eleptr);
extern void FreeSpectrumName(SpectrumName *eleptr);
extern void *AllocSpectrumName();
extern void WriteBinSpectrumName(SpectrumName *eleptr, DbaseLinkedList *file);
extern INT ReadBinSpectrumName(SpectrumName *eleptr, DbaseLinkedList *file);
extern void xdr_SpectrumName(XDR *stream, char **eleptr);
extern void CopyFullSpectrumName(SpectrumName *newstruct, SpectrumName *oldstruct);
/*------------------------------------------*/
/*   Structures for Spectrum   */
/* Structure:4:SpectrumSetOrder

          NumberOfSpectra --(INT) NumberOfSpectrum
                    Names --(SpectrumName) Ordered List of Names
*/
typedef struct spectrumsetorder SpectrumSetOrder;
struct spectrumsetorder {
     INT ID;
     CHAR *Name;
     INT  NumberOfSpectra;
     SpectrumName *Names;
     };
#define SpectrumSetOrderSize sizeof(SpectrumSetOrder)
#define AllocateSpectrumSetOrder (SpectrumSetOrder *) Malloc(SpectrumSetOrderSize)
#define AllocArraySpectrumSetOrder(n) (SpectrumSetOrder *) Calloc(n,SpectrumSetOrderSize)
#define SpectrumSetOrderPntrSize sizeof(SpectrumSetOrder **)
#define AllocPntrArraySpectrumSetOrder(n) (SpectrumSetOrder **) Calloc(n,SpectrumSetOrderPntrSize)
#define SingCopySpectrumSetOrder(out,in) memcpy(out,in,SpectrumSetOrderSize)
extern SpectrumSetOrder *CreateSpectrumSetOrder(SpectrumSetOrder *newstruct,
                                         INT id,
                                         CHAR *name,
                                         INT  NumberOfSpectra,
                                         SpectrumName *Names);

extern CHAR *GetNameSpectrumSetOrder(SpectrumSetOrder *str);
extern INT  GetIDSpectrumSetOrder(SpectrumSetOrder *str);
extern void PrintSpectrumSetOrder(SpectrumSetOrder *eleptr);
extern void FreeSpectrumSetOrder(SpectrumSetOrder *eleptr);
extern void *AllocSpectrumSetOrder();
extern void WriteBinSpectrumSetOrder(SpectrumSetOrder *eleptr, DbaseLinkedList *file);
extern INT ReadBinSpectrumSetOrder(SpectrumSetOrder *eleptr, DbaseLinkedList *file);
extern void xdr_SpectrumSetOrder(XDR *stream, char **eleptr);
extern void CopyFullSpectrumSetOrder(SpectrumSetOrder *newstruct, SpectrumSetOrder *oldstruct);
/*------------------------------------------*/
/*   Structures for Spectrum   */
/* Structure:6:SpectrumStandardSet

          NumberOfSpectra --(INT) NumberOfSpectra
                 Standard --(SpectrumStandard) Standard Spectrum
               Difference --(SpectrumStandard) The Difference Spectra
*/
typedef struct spectrumstandardset SpectrumStandardSet;
struct spectrumstandardset {
     INT ID;
     CHAR *Name;
     INT  NumberOfSpectra;
     SpectrumStandard *Standard;
     SpectrumStandard *Difference;
     };
#define SpectrumStandardSetSize sizeof(SpectrumStandardSet)
#define AllocateSpectrumStandardSet (SpectrumStandardSet *) Malloc(SpectrumStandardSetSize)
#define AllocArraySpectrumStandardSet(n) (SpectrumStandardSet *) Calloc(n,SpectrumStandardSetSize)
#define SpectrumStandardSetPntrSize sizeof(SpectrumStandardSet **)
#define AllocPntrArraySpectrumStandardSet(n) (SpectrumStandardSet **) Calloc(n,SpectrumStandardSetPntrSize)
#define SingCopySpectrumStandardSet(out,in) memcpy(out,in,SpectrumStandardSetSize)
extern SpectrumStandardSet *CreateSpectrumStandardSet(SpectrumStandardSet *newstruct,
                                               INT id,
                                               CHAR *name,
                                               INT  NumberOfSpectra,
                                               SpectrumStandard *Standard,
                                               SpectrumStandard *Difference);

extern CHAR *GetNameSpectrumStandardSet(SpectrumStandardSet *str);
extern INT  GetIDSpectrumStandardSet(SpectrumStandardSet *str);
extern void PrintSpectrumStandardSet(SpectrumStandardSet *eleptr);
extern void FreeSpectrumStandardSet(SpectrumStandardSet *eleptr);
extern void *AllocSpectrumStandardSet();
extern void WriteBinSpectrumStandardSet(SpectrumStandardSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinSpectrumStandardSet(SpectrumStandardSet *eleptr, DbaseLinkedList *file);
extern void xdr_SpectrumStandardSet(XDR *stream, char **eleptr);
extern void CopyFullSpectrumStandardSet(SpectrumStandardSet *newstruct, SpectrumStandardSet *oldstruct);
/*------------------------------------------*/
/*   Structures for Spectrum   */
/* Structure:5:SpectrumSet

          NumberOfSpectra --(INT) Number Of Spectra 
                  Spectra --(Spectrum) The set of Spectra
                     Data --(SpectrumSetData) Data about the set of spectra 
                 Standard --(SpectrumSetStandard) Definitions of the Standard Spectrum
                Standards --(SpectrumStandardSet) Set of Standard Spectra
                    Order --(SpectrumSetOrder) Ordering of Names
*/
typedef struct spectrumset SpectrumSet;
struct spectrumset {
     INT ID;
     CHAR *Name;
     INT  NumberOfSpectra;
     Spectrum *Spectra;
     SpectrumSetData *Data;
     SpectrumSetStandard *Standard;
     SpectrumStandardSet *Standards;
     SpectrumSetOrder *Order;
     };
#define SpectrumSetSize sizeof(SpectrumSet)
#define AllocateSpectrumSet (SpectrumSet *) Malloc(SpectrumSetSize)
#define AllocArraySpectrumSet(n) (SpectrumSet *) Calloc(n,SpectrumSetSize)
#define SpectrumSetPntrSize sizeof(SpectrumSet **)
#define AllocPntrArraySpectrumSet(n) (SpectrumSet **) Calloc(n,SpectrumSetPntrSize)
#define SingCopySpectrumSet(out,in) memcpy(out,in,SpectrumSetSize)
extern SpectrumSet *CreateSpectrumSet(SpectrumSet *newstruct,
                               INT id,
                               CHAR *name,
                               INT  NumberOfSpectra,
                               Spectrum *Spectra,
                               SpectrumSetData *Data,
                               SpectrumSetStandard *Standard,
                               SpectrumStandardSet *Standards,
                               SpectrumSetOrder *Order);

extern CHAR *GetNameSpectrumSet(SpectrumSet *str);
extern INT  GetIDSpectrumSet(SpectrumSet *str);
extern void PrintSpectrumSet(SpectrumSet *eleptr);
extern void FreeSpectrumSet(SpectrumSet *eleptr);
extern void *AllocSpectrumSet();
extern void WriteBinSpectrumSet(SpectrumSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinSpectrumSet(SpectrumSet *eleptr, DbaseLinkedList *file);
extern void xdr_SpectrumSet(XDR *stream, char **eleptr);
extern void CopyFullSpectrumSet(SpectrumSet *newstruct, SpectrumSet *oldstruct);
