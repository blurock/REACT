/*------------------------------------------*/
/*   The Master Data Structure for the Data Matrix Points   */
/* Structure:0:DatMatConstants

                ReadDebug --(INT) The Debug Flag
                 MaxNames --(INT) The Maximum number of variable names
        DescriptorMissing --(INT) Flag to eliminate Missing Descriptor points
              GoalMissing --(INT) Flag to eliminate missing Goal points
             SubSetRanges --(STRING) The set of Ranges to use (as a string)
          SubSetNumRanges --(INT) The maximum number of ranges allowed
             TrainPercent --(INT) The Percent of points to be used for training
            RandomPercent --(INT) The Percent of random points
            DataDirectory --(STRING) The Default Data Directory
             VarDirectory --(STRING) The Default Variable Directory
               LatexPrint --(INT) Print as latex document
              ControlFile --(STRING) The ControlFile Name
                DescrList --(STRING) The Name of the Descriptor List
                 GoalList --(STRING) The Name of the GoalList
*/
typedef struct syssamconstants DatMatConstants;
struct syssamconstants {
     INT ID;
     CHAR *Name;
     INT  ReadDebug;
     INT  MaxNames;
     INT  DescriptorMissing;
     INT  GoalMissing;
     STRING *SubSetRanges;
     INT  SubSetNumRanges;
     INT  TrainPercent;
     INT  RandomPercent;
     STRING *DataDirectory;
     STRING *VarDirectory;
     INT  LatexPrint;
     STRING *ControlFile;
     STRING *DescrList;
     STRING *GoalList;
     };
#define DatMatConstantsSize sizeof(DatMatConstants)
#define AllocateDatMatConstants (DatMatConstants *) Malloc(DatMatConstantsSize)
#define AllocArrayDatMatConstants(n) (DatMatConstants *) Calloc(n,DatMatConstantsSize)
#define DatMatConstantsPntrSize sizeof(DatMatConstants **)
#define AllocPntrArrayDatMatConstants(n) (DatMatConstants **) Calloc(n,DatMatConstantsPntrSize)
#define SingCopyDatMatConstants(out,in) memcpy(out,in,DatMatConstantsSize)
extern DatMatConstants *CreateDatMatConstants(DatMatConstants *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  ReadDebug,
                                       INT  MaxNames,
                                       INT  GoalMissing,
                                       STRING *SubSetRanges,
                                       INT  SubSetNumRanges,
                                       INT  TrainPercent,
                                       INT  RandomPercent,
                                       STRING *DataDirectory,
                                       STRING *VarDirectory,
                                       INT  LatexPrint,
                                       STRING *ControlFile,
                                       STRING *DescrList,
                                       STRING *GoalList);

extern CHAR *GetNameDatMatConstants(DatMatConstants *str);
extern INT  GetIDDatMatConstants(DatMatConstants *str);
extern void PrintDatMatConstants(DatMatConstants *eleptr);
extern void FreeDatMatConstants(DatMatConstants *eleptr);
extern void *AllocDatMatConstants();
extern void WriteBinDatMatConstants(DatMatConstants *eleptr, DbaseLinkedList *file);
extern INT ReadBinDatMatConstants(DatMatConstants *eleptr, DbaseLinkedList *file);
extern void xdr_DatMatConstants(XDR *stream, char **eleptr);
extern void CopyFullDatMatConstants(DatMatConstants *newstruct, DatMatConstants *oldstruct);
/*------------------------------------------*/
/*   The Master Data Structure for the Data Matrix Points   */
/* Structure:1:DatMatMaster

     SysSamVectorSetElement --(SysSamVectorSet) The Data Points
       DataSubSetStandard --(DataSubSet) The Raw Data Set
        DataSubSetElement --(DataSubSet) The Current DataSubSet
     SystemVariablePairElement --(SystemVariablePair) The Set of Variables to use
     DataTestBlockElement --(DataTestBlock) The Test and Training SubSets
                Constants --(DatMatConstants) The set of constants to be used
*/
typedef struct datmatmaster DatMatMaster;
struct datmatmaster {
     INT ID;
     CHAR *Name;
     SysSamVectorSet *SysSamVectorSetElement;
     DataSubSet *DataSubSetStandard;
     DataSubSet *DataSubSetElement;
     SystemVariablePair *SystemVariablePairElement;
     DataTestBlock *DataTestBlockElement;
     DatMatConstants *Constants;
     };
#define DatMatMasterSize sizeof(DatMatMaster)
#define AllocateDatMatMaster (DatMatMaster *) Malloc(DatMatMasterSize)
#define AllocArrayDatMatMaster(n) (DatMatMaster *) Calloc(n,DatMatMasterSize)
#define DatMatMasterPntrSize sizeof(DatMatMaster **)
#define AllocPntrArrayDatMatMaster(n) (DatMatMaster **) Calloc(n,DatMatMasterPntrSize)
#define SingCopyDatMatMaster(out,in) memcpy(out,in,DatMatMasterSize)
extern DatMatMaster *CreateDatMatMaster(DatMatMaster *newstruct,
                                 INT id,
                                 CHAR *name,
                                 SysSamVectorSet *SysSamVectorSetElement,
                                 DataSubSet *DataSubSetStandard,
                                 DataSubSet *DataSubSetElement,
                                 SystemVariablePair *SystemVariablePairElement,
                                 DataTestBlock *DataTestBlockElement,
                                 DatMatConstants *Constants);

extern CHAR *GetNameDatMatMaster(DatMatMaster *str);
extern INT  GetIDDatMatMaster(DatMatMaster *str);
extern void PrintDatMatMaster(DatMatMaster *eleptr);
extern void FreeDatMatMaster(DatMatMaster *eleptr);
extern void *AllocDatMatMaster();
extern void WriteBinDatMatMaster(DatMatMaster *eleptr, DbaseLinkedList *file);
extern INT ReadBinDatMatMaster(DatMatMaster *eleptr, DbaseLinkedList *file);
extern void xdr_DatMatMaster(XDR *stream, char **eleptr);
extern void CopyFullDatMatMaster(DatMatMaster *newstruct, DatMatMaster *oldstruct);
/*------------------------------------------*/
/*   The Master Data Structure for the Data Matrix Points   */
/* Structure:2:GoalValueElements

           NumberOfValues --(INT) The number of values
                   Values --(BaseType) The Set of Values (as base types .. for printing)
                  FValues --(FLOAT) The set of Values  (as floats .. for ordering)
*/
typedef struct goalvalueelements GoalValueElements;
struct goalvalueelements {
     INT ID;
     CHAR *Name;
     INT  NumberOfValues;
     BaseType *Values;
     FLOAT *FValues;
     };
#define GoalValueElementsSize sizeof(GoalValueElements)
#define AllocateGoalValueElements (GoalValueElements *) Malloc(GoalValueElementsSize)
#define AllocArrayGoalValueElements(n) (GoalValueElements *) Calloc(n,GoalValueElementsSize)
#define GoalValueElementsPntrSize sizeof(GoalValueElements **)
#define AllocPntrArrayGoalValueElements(n) (GoalValueElements **) Calloc(n,GoalValueElementsPntrSize)
#define SingCopyGoalValueElements(out,in) memcpy(out,in,GoalValueElementsSize)
extern GoalValueElements *CreateGoalValueElements(GoalValueElements *newstruct,
                                           INT id,
                                           CHAR *name,
                                           INT  NumberOfValues,
                                           BaseType *Values,
                                           FLOAT *FValues);

extern CHAR *GetNameGoalValueElements(GoalValueElements *str);
extern INT  GetIDGoalValueElements(GoalValueElements *str);
extern void PrintGoalValueElements(GoalValueElements *eleptr);
extern void FreeGoalValueElements(GoalValueElements *eleptr);
extern void *AllocGoalValueElements();
extern void WriteBinGoalValueElements(GoalValueElements *eleptr, DbaseLinkedList *file);
extern INT ReadBinGoalValueElements(GoalValueElements *eleptr, DbaseLinkedList *file);
extern void xdr_GoalValueElements(XDR *stream, char **eleptr);
extern void CopyFullGoalValueElements(GoalValueElements *newstruct, GoalValueElements *oldstruct);
/*------------------------------------------*/
/*   The Master Data Structure for the Data Matrix Points   */
/* Structure:3:DatMatGoalValues

         NumberOfElements --(INT) The number of elements
                 Elements --(GoalValueElements) The set of elements
*/
typedef struct datmatgoalvalues DatMatGoalValues;
struct datmatgoalvalues {
     INT ID;
     CHAR *Name;
     INT  NumberOfElements;
     GoalValueElements *Elements;
     };
#define DatMatGoalValuesSize sizeof(DatMatGoalValues)
#define AllocateDatMatGoalValues (DatMatGoalValues *) Malloc(DatMatGoalValuesSize)
#define AllocArrayDatMatGoalValues(n) (DatMatGoalValues *) Calloc(n,DatMatGoalValuesSize)
#define DatMatGoalValuesPntrSize sizeof(DatMatGoalValues **)
#define AllocPntrArrayDatMatGoalValues(n) (DatMatGoalValues **) Calloc(n,DatMatGoalValuesPntrSize)
#define SingCopyDatMatGoalValues(out,in) memcpy(out,in,DatMatGoalValuesSize)
extern DatMatGoalValues *CreateDatMatGoalValues(DatMatGoalValues *newstruct,
                                         INT id,
                                         CHAR *name,
                                         INT  NumberOfElements,
                                         GoalValueElements *Elements);

extern CHAR *GetNameDatMatGoalValues(DatMatGoalValues *str);
extern INT  GetIDDatMatGoalValues(DatMatGoalValues *str);
extern void PrintDatMatGoalValues(DatMatGoalValues *eleptr);
extern void FreeDatMatGoalValues(DatMatGoalValues *eleptr);
extern void *AllocDatMatGoalValues();
extern void WriteBinDatMatGoalValues(DatMatGoalValues *eleptr, DbaseLinkedList *file);
extern INT ReadBinDatMatGoalValues(DatMatGoalValues *eleptr, DbaseLinkedList *file);
extern void xdr_DatMatGoalValues(XDR *stream, char **eleptr);
extern void CopyFullDatMatGoalValues(DatMatGoalValues *newstruct, DatMatGoalValues *oldstruct);
