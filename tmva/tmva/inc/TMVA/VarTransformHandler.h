/**********************************************************************************
 * Project: TMVA - a Root-integrated toolkit for multivariate data analysis       *
 * Package: TMVA                                                                  *
 * Class  : Interval                                                              *
 * Web    : http://tmva.sourceforge.net                                           *
 *                                                                                *
 * Description:                                                                   *
 *          Extension of the Interval to "logarithmic" intervals                  *
 *                                                                                *
 *                                                                                *
 *                                                                                *
 * Authors (alphabetical):                                                        *
 *      Abhinav Moudgil                                                           *
 *                                                                                *
 * Copyright (c) 2005:                                                            *
 *      CERN, Switzerland                                                         *
 *                                                                                *
 * Redistribution and use in source and binary forms, with or without             *
 * modification, are permitted according to the terms listed in LICENSE           *
 * (http://tmva.sourceforge.net/LICENSE)                                          *
 **********************************************************************************/

#ifndef ROOT_TMVA_VarTransformHandler
#define ROOT_TMVA_VarTransformHandler

#include "TList.h"
#include "TString.h"
#include "TMVA/Types.h"
#include "TMVA/DataSetInfo.h"

class TTree;
class TFile;
class TDirectory;

namespace TMVA {

   class DataLoader;
   class MethodBase;
   class DataSetInfo;
   class Event;
   class DataSet;
   class MsgLogger;
   class DataInputHandler;
   class VarTransformHandler {
   public:

      VarTransformHandler(DataLoader*);
      ~VarTransformHandler();

      TMVA::DataLoader* VarianceThreshold(Double_t threshold);
      mutable MsgLogger* fLogger;             //! message logger
      MsgLogger& Log() const { return *fLogger; }

   private:

      DataSetInfo&                  fDataSetInfo;
      DataLoader*                   fDataLoader;
      const std::vector<Event*>&    fEvents;
      void                          UpdateNorm (Int_t ivar, Double_t x);
      void                          CalcNorm();
      void                          CopyDataLoader(TMVA::DataLoader* des, TMVA::DataLoader* src);
   };
}

#endif
