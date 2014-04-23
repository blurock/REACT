/*------------------------------------------*/
/*   Property Structures   */
/* Structure:100:IntegerPropVector

         NumberOfIntegers --(INT) The Number of Integers Stored
                 Integers --(INT) The Vector of Integers
*/
typedef struct intpropvec IntegerPropVector;
struct intpropvec {
     INT ID;
     CHAR *Name;
     INT  NumberOfIntegers;
     INT *Integers;
     };
#define IntegerPropVectorSize sizeof(IntegerPropVector)
#define AllocateIntegerPropVector (IntegerPropVector *) Malloc(IntegerPropVectorSize)
#define AllocArrayIntegerPropVector(n) (IntegerPropVector *) Calloc(n,IntegerPropVectorSize)
#define IntegerPropVectorPntrSize sizeof(IntegerPropVector **)
#define AllocPntrArrayIntegerPropVector(n) (IntegerPropVector **) Calloc(n,IntegerPropVectorPntrSize)
#define SingCopyIntegerPropVector(out,in) memcpy(out,in,IntegerPropVectorSize)
extern IntegerPropVector *CreateIntegerPropVector(IntegerPropVector *newstruct,
                                           INT id,
                                           CHAR *name,
                                           INT  NumberOfIntegers,
                                           INT *Integers);

extern CHAR *GetNameIntegerPropVector(IntegerPropVector *str);
extern INT  GetIDIntegerPropVector(IntegerPropVector *str);
extern void PrintIntegerPropVector(IntegerPropVector *eleptr);
extern void FreeIntegerPropVector(IntegerPropVector *eleptr);
extern void *AllocIntegerPropVector();
extern void WriteBinIntegerPropVector(IntegerPropVector *eleptr, DbaseLinkedList *file);
extern INT ReadBinIntegerPropVector(IntegerPropVector *eleptr, DbaseLinkedList *file);
extern void xdr_IntegerPropVector(XDR *stream, char **eleptr);
extern void CopyFullIntegerPropVector(IntegerPropVector *newstruct, IntegerPropVector *oldstruct);
/*------------------------------------------*/
/*   Property Structures   */
/* Structure:100:FloatPropVector

           NumberOfFloats --(INT) The Number of Floats Stored
                   Floats --(INT) The Vector of Floats
*/
typedef struct fltpropvec FloatPropVector;
struct fltpropvec {
     INT ID;
     CHAR *Name;
     INT  NumberOfFloats;
     INT *Floats;
     };
#define FloatPropVectorSize sizeof(FloatPropVector)
#define AllocateFloatPropVector (FloatPropVector *) Malloc(FloatPropVectorSize)
#define AllocArrayFloatPropVector(n) (FloatPropVector *) Calloc(n,FloatPropVectorSize)
#define FloatPropVectorPntrSize sizeof(FloatPropVector **)
#define AllocPntrArrayFloatPropVector(n) (FloatPropVector **) Calloc(n,FloatPropVectorPntrSize)
#define SingCopyFloatPropVector(out,in) memcpy(out,in,FloatPropVectorSize)
extern FloatPropVector *CreateFloatPropVector(FloatPropVector *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NumberOfFloats,
                                       INT *Floats);

extern CHAR *GetNameFloatPropVector(FloatPropVector *str);
extern INT  GetIDFloatPropVector(FloatPropVector *str);
extern void PrintFloatPropVector(FloatPropVector *eleptr);
extern void FreeFloatPropVector(FloatPropVector *eleptr);
extern void *AllocFloatPropVector();
extern void WriteBinFloatPropVector(FloatPropVector *eleptr, DbaseLinkedList *file);
extern INT ReadBinFloatPropVector(FloatPropVector *eleptr, DbaseLinkedList *file);
extern void xdr_FloatPropVector(XDR *stream, char **eleptr);
extern void CopyFullFloatPropVector(FloatPropVector *newstruct, FloatPropVector *oldstruct);
/*------------------------------------------*/
/*   Property Structures   */
/* Structure:102:PropValue

                  Integer --(INT) A Single Integer
                    Float --(FLOAT) A Single Float
                   IntVec --(IntegerPropVector) A Vector of Integers
                   FltVec --(FloatPropVector) A Vector of Floats
*/
typedef struct propvalue PropValue;
struct propvalue {
     INT ID;
     CHAR *Name;
     INT  Integer;
     FLOAT  Float;
     IntegerPropVector *IntVec;
     FloatPropVector *FltVec;
     };
#define PropValueSize sizeof(PropValue)
#define AllocatePropValue (PropValue *) Malloc(PropValueSize)
#define AllocArrayPropValue(n) (PropValue *) Calloc(n,PropValueSize)
#define PropValuePntrSize sizeof(PropValue **)
#define AllocPntrArrayPropValue(n) (PropValue **) Calloc(n,PropValuePntrSize)
#define SingCopyPropValue(out,in) memcpy(out,in,PropValueSize)
extern PropValue *CreatePropValue(PropValue *newstruct,
                           INT id,
                           CHAR *name,
                           INT  Integer,
                           FLOAT  Float,
                           IntegerPropVector *IntVec,
                           FloatPropVector *FltVec);

extern CHAR *GetNamePropValue(PropValue *str);
extern INT  GetIDPropValue(PropValue *str);
extern void PrintPropValue(PropValue *eleptr);
extern void FreePropValue(PropValue *eleptr);
extern void *AllocPropValue();
extern void WriteBinPropValue(PropValue *eleptr, DbaseLinkedList *file);
extern INT ReadBinPropValue(PropValue *eleptr, DbaseLinkedList *file);
extern void xdr_PropValue(XDR *stream, char **eleptr);
extern void CopyFullPropValue(PropValue *newstruct, PropValue *oldstruct);
/*------------------------------------------*/
/*   Property Structures   */
/* Structure:104:CompareVector

          NumberOfObjects --(INT) The Number Objects
                 Compares --(INT) The Comparisons of reference object with rest
*/
typedef struct comparevector CompareVector;
struct comparevector {
     INT ID;
     CHAR *Name;
     INT  NumberOfObjects;
     INT *Compares;
     };
#define CompareVectorSize sizeof(CompareVector)
#define AllocateCompareVector (CompareVector *) Malloc(CompareVectorSize)
#define AllocArrayCompareVector(n) (CompareVector *) Calloc(n,CompareVectorSize)
#define CompareVectorPntrSize sizeof(CompareVector **)
#define AllocPntrArrayCompareVector(n) (CompareVector **) Calloc(n,CompareVectorPntrSize)
#define SingCopyCompareVector(out,in) memcpy(out,in,CompareVectorSize)
extern CompareVector *CreateCompareVector(CompareVector *newstruct,
                                   INT id,
                                   CHAR *name,
                                   INT  NumberOfObjects,
                                   INT *Compares);

extern CHAR *GetNameCompareVector(CompareVector *str);
extern INT  GetIDCompareVector(CompareVector *str);
extern void PrintCompareVector(CompareVector *eleptr);
extern void FreeCompareVector(CompareVector *eleptr);
extern void *AllocCompareVector();
extern void WriteBinCompareVector(CompareVector *eleptr, DbaseLinkedList *file);
extern INT ReadBinCompareVector(CompareVector *eleptr, DbaseLinkedList *file);
extern void xdr_CompareVector(XDR *stream, char **eleptr);
extern void CopyFullCompareVector(CompareVector *newstruct, CompareVector *oldstruct);
/*------------------------------------------*/
/*   Property Structures   */
/* Structure:105:CompareVectorSet

             NumberOfSets --(INT) The number of sets
                     Sets --(CompareVector) The set of Compare Vectors
*/
typedef struct comparevectorset CompareVectorSet;
struct comparevectorset {
     INT ID;
     CHAR *Name;
     INT  NumberOfSets;
     CompareVector *Sets;
     };
#define CompareVectorSetSize sizeof(CompareVectorSet)
#define AllocateCompareVectorSet (CompareVectorSet *) Malloc(CompareVectorSetSize)
#define AllocArrayCompareVectorSet(n) (CompareVectorSet *) Calloc(n,CompareVectorSetSize)
#define CompareVectorSetPntrSize sizeof(CompareVectorSet **)
#define AllocPntrArrayCompareVectorSet(n) (CompareVectorSet **) Calloc(n,CompareVectorSetPntrSize)
#define SingCopyCompareVectorSet(out,in) memcpy(out,in,CompareVectorSetSize)
extern CompareVectorSet *CreateCompareVectorSet(CompareVectorSet *newstruct,
                                         INT id,
                                         CHAR *name,
                                         INT  NumberOfSets,
                                         CompareVector *Sets);

extern CHAR *GetNameCompareVectorSet(CompareVectorSet *str);
extern INT  GetIDCompareVectorSet(CompareVectorSet *str);
extern void PrintCompareVectorSet(CompareVectorSet *eleptr);
extern void FreeCompareVectorSet(CompareVectorSet *eleptr);
extern void *AllocCompareVectorSet();
extern void WriteBinCompareVectorSet(CompareVectorSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinCompareVectorSet(CompareVectorSet *eleptr, DbaseLinkedList *file);
extern void xdr_CompareVectorSet(XDR *stream, char **eleptr);
extern void CopyFullCompareVectorSet(CompareVectorSet *newstruct, CompareVectorSet *oldstruct);
