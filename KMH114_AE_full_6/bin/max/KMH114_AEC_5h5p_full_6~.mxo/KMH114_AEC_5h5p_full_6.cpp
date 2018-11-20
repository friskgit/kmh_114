/* ------------------------------------------------------------
author: "AmbisonicDecoderToolkit"
copyright: "(c) Aaron J. Heller 2013"
license: "BSD 3-Clause License"
name: "KMH114_AEC_5h5p_full_6"
version: "1.2"
Code generated with Faust 2.6.3 (https://faust.grame.fr)
Compilation options: cpp, -double -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

/************************************************************************

    IMPORTANT NOTE : this file contains two clearly delimited sections :
    the ARCHITECTURE section (in two parts) and the USER section. Each section
    is governed by its own copyright and license. Please check individually
    each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2004-2028 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either version 3
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

    MAX MSP SDK : in order to compile a MaxMSP external with this
    architecture file you will need the official MaxMSP SDK from
    cycling'74. Please check the corresponding license.

 ************************************************************************
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>

#ifdef __APPLE__
#include <Carbon/Carbon.h>
#include <unistd.h>
#endif

#ifdef WIN32
#ifndef NAN
    static const unsigned long __nan[2] = {0xffffffff, 0x7fffffff};
    #define NAN (*(const float *) __nan)
#endif
#endif

#define FAUSTFLOAT double

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __UI_H__
#define __UI_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust DSP User Interface
 * User Interface as expected by the buildUserInterface() method of a DSP.
 * This abstract class contains only the method that the Faust compiler can
 * generate to describe a DSP user interface.
 ******************************************************************************/

struct Soundfile;

class UI
{

    public:

        UI() {}

        virtual ~UI() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
};

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef FAUST_JSONUI_H
#define FAUST_JSONUI_H

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <assert.h>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_PATHBUILDER_H
#define FAUST_PATHBUILDER_H

#include <vector>
#include <string>
#include <algorithm>

/*******************************************************************************
 * PathBuilder : Faust User Interface
 * Helper class to build complete hierarchical path for UI items.
 ******************************************************************************/

class PathBuilder
{

    protected:
    
        std::vector<std::string> fControlsLevel;
       
    public:
    
        PathBuilder() {}
        virtual ~PathBuilder() {}
    
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            std::replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
};

#endif  // FAUST_PATHBUILDER_H
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __meta__
#define __meta__

struct Meta
{
    virtual void declare(const char* key, const char* value) = 0;
    virtual ~Meta() {};
};

#endif

/*******************************************************************************
 * JSONUI : Faust User Interface
 * This class produce a complete JSON decription of the DSP instance.
 ******************************************************************************/

template <typename REAL>
class JSONUIAux : public PathBuilder, public Meta, public UI
{

    protected:
    
        std::stringstream fJSON;
        std::stringstream fUI;
        std::stringstream fMeta;
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        std::string fVersion;
        std::string fOptions;
        std::string fName;
        std::string fFileName;
        std::string fExpandedCode;
        std::string fSHAKey;
        std::string fDSPSize;
        std::map<std::string, int> fPathTable;
    
        char fCloseUIPar;
        char fCloseMetaPar;
        int fTab;
    
        int fInputs, fOutputs;
         
        void tab(int n, std::ostream& fout)
        {
            fout << '\n';
            while (n-- > 0) {
                fout << '\t';
            }
        }
    
        void addMeta(int tab_val, bool quote = true)
        {
            if (fMetaAux.size() > 0) {
                tab(tab_val, fUI); fUI << "\"meta\": [";
                std::string sep = "";
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    fUI << sep;
                    tab(tab_val + 1, fUI); fUI << "{ \"" << fMetaAux[i].first << "\": \"" << fMetaAux[i].second << "\" }";
                    sep = ",";
                }
                tab(tab_val, fUI); fUI << ((quote) ? "],": "]");
                fMetaAux.clear();
            }
        }
    
        // Add escape (that is  '\') for internal strings
        inline std::string flatten(const std::string& src)
        {
            bool in_string = false;
            std::stringstream dst;
            for (size_t i = 0; i < src.size(); i++) {
                switch (src[i]) {
                    case '\n':
                    case '\t':
                        break;
                    case ' ':
                        if (in_string) dst << src[i];
                        break;
                    case '"':
                        dst << "\\" << '"';
                        in_string = !in_string;
                        break;
                    case '\\':
                        dst << '\\' << '\\';
                        break;
                    default:
                        dst << src[i];
                        break;
                }
            }
            return dst.str();
        }
    
        inline std::string getAddressIndex(const std::string& path)
        {
            if (fPathTable.find(path) != fPathTable.end()) {
                std::stringstream num; num << fPathTable[path];
                return num.str();
            } else {
                return "-1";
            }
        }
      
     public:
     
        JSONUIAux(const std::string& name,
                  const std::string& filename,
                  int inputs,
                  int outputs,
                  const std::string& sha_key,
                  const std::string& dsp_code,
                  const std::string& version,
                  const std::string& options,
                  const std::string& size,
                  const std::map<std::string, int>& path_table)
        {
            init(name, filename, inputs, outputs, sha_key, dsp_code,  version, options, size, path_table);
        }

        JSONUIAux(const std::string& name, const std::string& filename, int inputs, int outputs)
        {
            init(name, filename, inputs, outputs, "", "", "", "", "", std::map<std::string, int>());
        }

        JSONUIAux(int inputs, int outputs)
        {
            init("", "", inputs, outputs, "", "","", "", "", std::map<std::string, int>());
        }
        
        JSONUIAux()
        {
            init("", "", -1, -1, "", "", "", "", "", std::map<std::string, int>());
        }
 
        virtual ~JSONUIAux() {}
        
        void setInputs(int inputs) { fInputs = inputs; }
        void setOutputs(int outputs) { fOutputs = outputs; }
    
        // Init may be called multiple times so fMeta and fUI are reinitialized
        void init(const std::string& name,
                  const std::string& filename,
                  int inputs,
                  int outputs,
                  const std::string& sha_key,
                  const std::string& dsp_code,
                  const std::string& version,
                  const std::string& options,
                  const std::string& size,
                  const std::map<std::string, int>& path_table)
        {
            fTab = 1;
            
            // Start Meta generation
            fMeta.str("");
            tab(fTab, fMeta); fMeta << "\"meta\": [";
            fCloseMetaPar = ' ';
            
            // Start UI generation
            fUI.str("");
            tab(fTab, fUI); fUI << "\"ui\": [";
            fCloseUIPar = ' ';
            fTab += 1;
            
            fName = name;
            fFileName = filename;
            fInputs = inputs;
            fOutputs = outputs;
            fExpandedCode = dsp_code;
            fSHAKey = sha_key;
            fDSPSize = size;
            fPathTable = path_table;
            fVersion = version;
            fOptions = options;
        }
   
        // -- widget's layouts
    
        virtual void openGenericGroup(const char* label, const char* name)
        {
            fControlsLevel.push_back(label);
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
            addMeta(fTab + 1);
            tab(fTab, fUI); fUI << "\"items\": [";
            fCloseUIPar = ' ';
            fTab += 1;
        }

        virtual void openTabBox(const char* label)
        {
            openGenericGroup(label, "tgroup");
        }
    
        virtual void openHorizontalBox(const char* label)
        {
            openGenericGroup(label, "hgroup");
        }
    
        virtual void openVerticalBox(const char* label)
        {
            openGenericGroup(label, "vgroup");
        }
    
        virtual void closeBox()
        {
            fControlsLevel.pop_back();
            fTab -= 1;
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        // -- active widgets
  
        virtual void addGenericButton(const char* label, const char* name)
        {
            std::string path = buildPath(label);
            std::string index = getAddressIndex(path);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\",";
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << index << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            } else {
                tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            }
            addMeta(fTab + 1, false);
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addButton(const char* label, REAL* zone)
        {
            addGenericButton(label, "button");
        }
    
        virtual void addCheckButton(const char* label, REAL* zone)
        {
            addGenericButton(label, "checkbox");
        }

        virtual void addGenericEntry(const char* label, const char* name, REAL init, REAL min, REAL max, REAL step)
        {
            std::string path = buildPath(label);
            std::string index = getAddressIndex(path);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << index << "\",";
            }
            addMeta(fTab + 1);
            tab(fTab + 1, fUI); fUI << "\"init\": \"" << init << "\",";
            tab(fTab + 1, fUI); fUI << "\"min\": \"" << min << "\",";
            tab(fTab + 1, fUI); fUI << "\"max\": \"" << max << "\",";
            tab(fTab + 1, fUI); fUI << "\"step\": \"" << step << "\"";
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        virtual void addVerticalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "vslider", init, min, max, step);
        }
    
        virtual void addHorizontalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "hslider", init, min, max, step);
        }
    
        virtual void addNumEntry(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "nentry", init, min, max, step);
        }

        // -- passive widgets
    
        virtual void addGenericBargraph(const char* label, const char* name, REAL min, REAL max) 
        {
            std::string path = buildPath(label);
            std::string index = getAddressIndex(path);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << index << "\",";
            }
            addMeta(fTab + 1);
            tab(fTab + 1, fUI); fUI << "\"min\": \"" << min << "\",";
            tab(fTab + 1, fUI); fUI << "\"max\": \"" << max << "\"";
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addHorizontalBargraph(const char* label, REAL* zone, REAL min, REAL max) 
        {
            addGenericBargraph(label, "hbargraph", min, max);
        }
    
        virtual void addVerticalBargraph(const char* label, REAL* zone, REAL min, REAL max)
        {
            addGenericBargraph(label, "vbargraph", min, max);
        }
    
        virtual void addSoundfile(const char* label, const char* url, Soundfile** zone)
        {
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << "soundfile" << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"url\": \"" << url << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << buildPath(label) << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            addMeta(fTab + 1, false);
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        // -- metadata declarations

        virtual void declare(REAL* zone, const char* key, const char* val)
        {
            fMetaAux.push_back(std::make_pair(key, val));
        }
    
        // Meta interface
        virtual void declare(const char* key, const char* value)
        {
            fMeta << fCloseMetaPar;
            // fName found in metadata
            if ((strcmp(key, "name") == 0) && (fName == "")) fName = value;
            // fFileName found in metadata
            if ((strcmp(key, "filename") == 0) && (fFileName == "")) fFileName = value;
            tab(fTab, fMeta); fMeta << "{ " << "\"" << key << "\"" << ": " << "\"" << value << "\" }";
            fCloseMetaPar = ',';
        }
    
        std::string JSON(bool flat = false)
        {
            fTab = 0;
            fJSON << "{";
            fTab += 1;
            tab(fTab, fJSON); fJSON << "\"name\": \"" << fName << "\",";
            tab(fTab, fJSON); fJSON << "\"filename\": \"" << fFileName << "\",";
            if (fVersion != "") { tab(fTab, fJSON); fJSON << "\"version\": \"" << fVersion << "\","; }
            if (fOptions != "") { tab(fTab, fJSON); fJSON << "\"options\": \"" << fOptions << "\","; }
            if (fDSPSize != "") { tab(fTab, fJSON); fJSON << "\"size\": \"" << fDSPSize << "\","; }
            if (fSHAKey != "") { tab(fTab, fJSON); fJSON << "\"sha_key\": \"" << fSHAKey << "\","; }
            if (fExpandedCode != "") { tab(fTab, fJSON); fJSON << "\"code\": \"" << fExpandedCode << "\","; }
            tab(fTab, fJSON); fJSON << "\"inputs\": \"" << fInputs << "\","; 
            tab(fTab, fJSON); fJSON << "\"outputs\": \"" << fOutputs << "\",";
            tab(fTab, fMeta); fMeta << "],";
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            if (fCloseMetaPar == ',') { // If "declare" has been called, fCloseMetaPar state is now ','
                fJSON << fMeta.str() << fUI.str();
            } else {
                fJSON << fUI.str();
            }
            tab(fTab, fJSON); fJSON << "}";
            return (flat) ? flatten(fJSON.str()) : fJSON.str();
        }
    
};

// Externally available class using FAUSTFLOAT

class JSONUI : public JSONUIAux<FAUSTFLOAT>
{
    public :
    
        JSONUI(const std::string& name,
               const std::string& filename,
               int inputs,
               int outputs,
               const std::string& sha_key,
               const std::string& dsp_code,
               const std::string& version,
               const std::string& options,
               const std::string& size,
               const std::map<std::string, int>& path_table):
        JSONUIAux<FAUSTFLOAT>(name, filename,
                              inputs, outputs,
                              sha_key, dsp_code,
                              version, options,
                              size, path_table)
        {}
        
        JSONUI(const std::string& name, const std::string& filename, int inputs, int outputs):
        JSONUIAux<FAUSTFLOAT>(name, filename, inputs, outputs)
        {}
        
        JSONUI(int inputs, int outputs):JSONUIAux<FAUSTFLOAT>(inputs, outputs)
        {}
        
        JSONUI():JSONUIAux<FAUSTFLOAT>()
        {}
    
        virtual ~JSONUI() {}
    
};

#endif // FAUST_JSONUI_H
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp__
#define __dsp__

#include <string>
#include <vector>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class UI;
struct Meta;

/**
 * DSP memory manager.
 */

struct dsp_memory_manager {
    
    virtual ~dsp_memory_manager() {}
    
    virtual void* allocate(size_t size) = 0;
    virtual void destroy(void* ptr) = 0;
    
};

/**
* Signal processor definition.
*/

class dsp {

    public:

        dsp() {}
        virtual ~dsp() {}

        /* Return instance number of audio inputs */
        virtual int getNumInputs() = 0;
    
        /* Return instance number of audio outputs */
        virtual int getNumOutputs() = 0;
    
        /**
         * Trigger the ui_interface parameter with instance specific calls
         * to 'addBtton', 'addVerticalSlider'... in order to build the UI.
         *
         * @param ui_interface - the user interface builder
         */
        virtual void buildUserInterface(UI* ui_interface) = 0;
    
        /* Returns the sample rate currently used by the instance */
        virtual int getSampleRate() = 0;
    
        /**
         * Global init, calls the following methods:
         * - static class 'classInit': static tables initialization
         * - 'instanceInit': constants and instance state initialization
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void init(int samplingRate) = 0;

        /**
         * Init instance state
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void instanceInit(int samplingRate) = 0;

        /**
         * Init instance constant state
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void instanceConstants(int samplingRate) = 0;
    
        /* Init default control parameters values */
        virtual void instanceResetUserInterface() = 0;
    
        /* Init instance state (delay lines...) */
        virtual void instanceClear() = 0;
 
        /**
         * Return a clone of the instance.
         *
         * @return a copy of the instance on success, otherwise a null pointer.
         */
        virtual dsp* clone() = 0;
    
        /**
         * Trigger the Meta* parameter with instance specific calls to 'declare' (key, value) metadata.
         *
         * @param m - the Meta* meta user
         */
        virtual void metadata(Meta* m) = 0;
    
        /**
         * DSP instance computation, to be called with successive in/out audio buffers.
         *
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
    
        /**
         * DSP instance computation: alternative method to be used by subclasses.
         *
         * @param date_usec - the timestamp in microsec given by audio driver.
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(double /*date_usec*/, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

/**
 * Generic DSP decorator.
 */

class decorator_dsp : public dsp {

    protected:

        dsp* fDSP;

    public:

        decorator_dsp(dsp* dsp = 0):fDSP(dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return fDSP->getSampleRate(); }
        virtual void init(int samplingRate) { fDSP->init(samplingRate); }
        virtual void instanceInit(int samplingRate) { fDSP->instanceInit(samplingRate); }
        virtual void instanceConstants(int samplingRate) { fDSP->instanceConstants(samplingRate); }
        virtual void instanceResetUserInterface() { fDSP->instanceResetUserInterface(); }
        virtual void instanceClear() { fDSP->instanceClear(); }
        virtual decorator_dsp* clone() { return new decorator_dsp(fDSP->clone()); }
        virtual void metadata(Meta* m) { fDSP->metadata(m); }
        // Beware: subclasses usually have to overload the two 'compute' methods
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
    
};

/**
 * DSP factory class.
 */

class dsp_factory {
    
    protected:
    
        // So that to force sub-classes to use deleteDSPFactory(dsp_factory* factory);
        virtual ~dsp_factory() {}
    
    public:
    
        virtual std::string getName() = 0;
        virtual std::string getSHAKey() = 0;
        virtual std::string getDSPCode() = 0;
    
        virtual std::vector<std::string> getDSPFactoryLibraryList() = 0;
        virtual std::vector<std::string> getDSPFactoryIncludePathnames() = 0;
    
        virtual dsp* createDSPInstance() = 0;
    
        virtual void setMemoryManager(dsp_memory_manager* manager) = 0;
        virtual dsp_memory_manager* getMemoryManager() = 0;
    
};

/**
 * On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
 * flags to avoid costly denormals.
 */

#ifdef __SSE__
    #include <xmmintrin.h>
    #ifdef __SSE2__
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8040)
    #else
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8000)
    #endif
#else
    #define AVOIDDENORMALS
#endif

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __misc__
#define __misc__

#include <algorithm>
#include <map>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>


using std::max;
using std::min;

struct XXXX_Meta : std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

struct MY_Meta : Meta, std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

inline int lsr(int x, int n)	{ return int(((unsigned int)x) >> n); }

inline int int2pow2(int x)		{ int r = 0; while ((1<<r) < x) r++; return r; }

inline long lopt(char* argv[], const char* name, long def)
{
	int	i;
    for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return std::atoi(argv[i+1]);
	return def;
}

inline bool isopt(char* argv[], const char* name)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
	return false;
}

inline const char* lopts(char* argv[], const char* name, const char* def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
	return def;
}

#endif


#ifdef POLY2
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp_combiner__
#define __dsp_combiner__

#include <string.h>
#include <assert.h>


// Combine two DSP in sequence

class dsp_sequencer : public dsp {
    
    private:
        
        dsp* fDSP1;
        dsp* fDSP2;
        FAUSTFLOAT** fSeqBuffer;
         
    public:
        
        dsp_sequencer(dsp* dsp1, dsp* dsp2, int buffer_size = 4096)
            :fDSP1(dsp1), fDSP2(dsp2)
        {
            assert(fDSP1->getNumOutputs() == fDSP2->getNumInputs());
            fSeqBuffer = new FAUSTFLOAT*[fDSP1->getNumOutputs()];
            for (int i = 0; i < fDSP1->getNumOutputs(); i++) {
                fSeqBuffer[i] = new FAUSTFLOAT[buffer_size];
            }
        }
        
        virtual ~dsp_sequencer()
        {
            for (int i = 0; i < fDSP1->getNumOutputs(); i++) {
               delete [] fSeqBuffer[i];
            }
            
            delete [] fSeqBuffer;
            delete fDSP1;
            delete fDSP2;
        }
               
        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP2->getNumOutputs(); }
    
        virtual void buildUserInterface(UI* ui_interface)
        {
            ui_interface->openTabBox("Sequencer");
            ui_interface->openVerticalBox("DSP1");
            fDSP1->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->openVerticalBox("DSP2");
            fDSP2->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->closeBox();
        }
        
        virtual int getSampleRate()
        {
            return fDSP1->getSampleRate();
        }
    
        virtual void init(int samplingRate)
        {
            fDSP1->init(samplingRate);
            fDSP2->init(samplingRate);
        }
    
        virtual void instanceInit(int samplingRate)
        {
            fDSP1->instanceInit(samplingRate);
            fDSP2->instanceInit(samplingRate);
        }
    
        virtual void instanceConstants(int samplingRate)
        {
            fDSP1->instanceConstants(samplingRate);
            fDSP2->instanceConstants(samplingRate);
        }
    
        virtual void instanceResetUserInterface()
        {
            fDSP1->instanceResetUserInterface();
            fDSP2->instanceResetUserInterface();
        }
    
        virtual void instanceClear()
        {
            fDSP1->instanceClear();
            fDSP2->instanceClear();
        }
        
        virtual dsp* clone()
        {
            return new dsp_sequencer(fDSP1->clone(), fDSP2->clone());
        }
    
        virtual void metadata(Meta* m)
        {
            fDSP1->metadata(m);
            fDSP2->metadata(m);
        }
 
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, fSeqBuffer);
            fDSP2->compute(count, fSeqBuffer, outputs);
        }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
};

// Combine two DSP in parallel

class dsp_parallelizer : public dsp {
    
    private:
        
        dsp* fDSP1;
        dsp* fDSP2;
    
        FAUSTFLOAT** fInputsDSP2;
        FAUSTFLOAT** fOutputsDSP2;
    
    public:
        
        dsp_parallelizer(dsp* dsp1, dsp* dsp2, int buffer_size = 4096)
            :fDSP1(dsp1), fDSP2(dsp2)
        {
            fInputsDSP2 = new FAUSTFLOAT*[fDSP2->getNumInputs()];
            fOutputsDSP2 = new FAUSTFLOAT*[fDSP2->getNumOutputs()];
        }
        
        virtual ~dsp_parallelizer()
        {
            delete fDSP1;
            delete fDSP2;
            delete [] fInputsDSP2;
            delete [] fOutputsDSP2;
        }
               
        virtual int getNumInputs() { return fDSP1->getNumInputs() + fDSP2->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP1->getNumOutputs() + fDSP2->getNumOutputs(); }
    
        virtual void buildUserInterface(UI* ui_interface)
        {
            ui_interface->openTabBox("Parallelizer");
            ui_interface->openVerticalBox("DSP1");
            fDSP1->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->openVerticalBox("DSP2");
            fDSP2->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->closeBox();
        }
        
        virtual int getSampleRate()
        {
            return fDSP1->getSampleRate();
        }
    
        virtual void init(int samplingRate)
        {
            fDSP1->init(samplingRate);
            fDSP2->init(samplingRate);
        }
    
        virtual void instanceInit(int samplingRate)
        {
            fDSP1->instanceInit(samplingRate);
            fDSP2->instanceInit(samplingRate);
        }
    
        virtual void instanceConstants(int samplingRate)
        {
            fDSP1->instanceConstants(samplingRate);
            fDSP2->instanceConstants(samplingRate);
        }
        
        virtual void instanceResetUserInterface()
        {
            fDSP1->instanceResetUserInterface();
            fDSP2->instanceResetUserInterface();
        }

        virtual void instanceClear()
        {
            fDSP1->instanceClear();
            fDSP2->instanceClear();
        }
        
        virtual dsp* clone()
        {
            return new dsp_parallelizer(fDSP1->clone(), fDSP2->clone());
        }

        virtual void metadata(Meta* m)
        {
            fDSP1->metadata(m);
            fDSP2->metadata(m);
        }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, outputs);
            
            // Shift inputs/outputs channels for fDSP2
            for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                fInputsDSP2[chan] = inputs[fDSP1->getNumInputs() + chan];
            }
            for (int chan = 0; chan < fDSP2->getNumOutputs(); chan++) {
                fOutputsDSP2[chan] = outputs[fDSP1->getNumOutputs() + chan];
            }
            
            fDSP2->compute(count, fInputsDSP2, fOutputsDSP2);
        }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
};

#endif
#include "effect.cpp"
#endif

#if SOUNDFILE
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __SoundUI_H__
#define __SoundUI_H__

#include <map>
#include <vector>
#include <string>

#ifdef __APPLE__
#include <CoreFoundation/CFBundle.h>
#endif

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef Decorator_UI_H
#define Decorator_UI_H


//----------------------------------------------------------------
//  Generic UI empty implementation
//----------------------------------------------------------------

class GenericUI : public UI
{
    
    public:
        
        GenericUI() {}
        virtual ~GenericUI() {}
        
        // -- widget's layouts
        virtual void openTabBox(const char* label) {}
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
    
        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* soundpath, Soundfile** sf_zone) {}
    
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) {}
    
};

//----------------------------------------------------------------
//  Generic UI decorator
//----------------------------------------------------------------

class DecoratorUI : public UI
{
    
    protected:
        
        UI* fUI;
        
    public:
        
        DecoratorUI(UI* ui = 0):fUI(ui) {}
        virtual ~DecoratorUI() { delete fUI; }
        
        // -- widget's layouts
        virtual void openTabBox(const char* label)          { fUI->openTabBox(label); }
        virtual void openHorizontalBox(const char* label)   { fUI->openHorizontalBox(label); }
        virtual void openVerticalBox(const char* label)     { fUI->openVerticalBox(label); }
        virtual void closeBox()                             { fUI->closeBox(); }
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)         { fUI->addButton(label, zone); }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)    { fUI->addCheckButton(label, zone); }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addVerticalSlider(label, zone, init, min, max, step); }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addHorizontalSlider(label, zone, init, min, max, step); }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addNumEntry(label, zone, init, min, max, step); }
        
        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        { fUI->addHorizontalBargraph(label, zone, min, max); }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        { fUI->addVerticalBargraph(label, zone, min, max); }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) { fUI->addSoundfile(label, filename, sf_zone); }
    
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) { fUI->declare(zone, key, val); }
    
};

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __soundfile__
#define __soundfile__

#include <sndfile.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#define BUFFER_SIZE     1024
#define SAMPLE_RATE     44100
#define MAX_CHAN        64

#define MIN_CHAN(a,b) ((a) < (b) ? (a) : (b))

#define PRE_PACKED_STRUCTURE
#define POST_PACKED_STRUCTURE __attribute__((__packed__))

PRE_PACKED_STRUCTURE
struct Soundfile {
    
    FAUSTFLOAT** fBuffers;
    int fLength;
    int fSampleRate;
    int fChannels;
    
    typedef sf_count_t (* sample_read)(SNDFILE* sndfile, FAUSTFLOAT* ptr, sf_count_t frames);
    
    static std::string CheckAux(const std::string& path_name_str, std::string& sha_key)
    {
        SF_INFO snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name_str.c_str(), SFM_READ, &snd_info);
        if (snd_file) {
            sf_close(snd_file);
            // Possibly read associated SHA_KEY file
            std::string sha_key_path_name_str = path_name_str + "_sha_key";
            std::ifstream reader(sha_key_path_name_str.c_str());
            if (reader.is_open()) {
                std::string sha_key_line;
                getline(reader, sha_key_line);
                std::stringstream line_reader(sha_key_line);
                line_reader >> sha_key;
            }
            return path_name_str;
        } else {
            std::cerr << "ERROR : cannot open '" << path_name_str << "' (" << sf_strerror(NULL) << ")" << std::endl;
            return "";
        }
    }
    
    // Check if soundfile exists and return the real path_name
    static std::string Check(const std::vector<std::string>& sound_directories, const std::string& file_name_str, std::string& sha_key)
    {
        std::string path_name_str = CheckAux(file_name_str, sha_key);
        if (path_name_str != "") {
            return path_name_str;
        } else {
            for (int i = 0; i < sound_directories.size(); i++) {
                std::string res = CheckAux(sound_directories[i] + "/" + file_name_str, sha_key);
                if (res != "") { return res; }
            }
            return "";
        }
    }
    
    Soundfile(const std::string& path_name_str, int max_chan)
    {
        fBuffers = new FAUSTFLOAT*[max_chan];
        if (!fBuffers) {
            throw std::bad_alloc();
        }
     
        // Open sndfile
        SF_INFO	snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name_str.c_str(), SFM_READ, &snd_info);
        
        if (snd_file) {
            
            fChannels = MIN_CHAN(max_chan, snd_info.channels);
            fLength = int(snd_info.frames);
            fSampleRate = snd_info.samplerate;
            
            for (int chan = 0; chan < fChannels; chan++) {
                fBuffers[chan] = new FAUSTFLOAT[snd_info.frames];
                if (!fBuffers[chan]) {
                    throw std::bad_alloc();
                }
            }
            
            // Read and fill snd_info.channels number of channels
            sf_count_t nbf, index = 0;
            FAUSTFLOAT buffer[BUFFER_SIZE * snd_info.channels];
            sample_read reader;
            if (sizeof(FAUSTFLOAT) == 4) {
                reader = reinterpret_cast<sample_read>(sf_readf_float);
            } else {
                reader = reinterpret_cast<sample_read>(sf_readf_double);
            }
            do {
                nbf = reader(snd_file, buffer, BUFFER_SIZE);
                for (int sample = 0; sample < nbf; sample++) {
                    for (int chan = 0; chan < fChannels; chan++) {
                        fBuffers[chan][index + sample] = buffer[sample * snd_info.channels + chan];
                    }
                }
                index += nbf;
            } while (nbf == BUFFER_SIZE);
            
            // Share the same buffers for all other channels so that we have max_chan channels available
            for (int chan = fChannels; chan < max_chan; chan++) {
                fBuffers[chan] = fBuffers[chan % snd_info.channels];
            }
       
            sf_close(snd_file);
            
        } else {
            
            if (path_name_str != "") {
                std::cerr << "Error opening the file : " << path_name_str << std::endl;
            }
            
            fChannels = 1;
            fLength = BUFFER_SIZE;
            fSampleRate = SAMPLE_RATE;
            
            // Allocate 1 channel
            fBuffers[0] = new FAUSTFLOAT[BUFFER_SIZE];
            if (!fBuffers[0]) {
                throw std::bad_alloc();
            }
            memset(fBuffers[0], 0, BUFFER_SIZE * sizeof(FAUSTFLOAT));
            
            // Share the same buffer for all other channels so that we have max_chan channels available
            for (int chan = fChannels; chan < max_chan; chan++) {
                fBuffers[chan] = fBuffers[0];
            }
        }
    }
    
    ~Soundfile()
    {
        // Free the real channels only
        for (int chan = 0; chan < fChannels; chan++) {
            delete fBuffers[chan];
        }
        delete [] fBuffers;
    }
    
} POST_PACKED_STRUCTURE;

#endif

// To be used by dsp code if no SoundUI is used or when soundfile is not found
extern "C" Soundfile* defaultsound = new Soundfile("", MAX_CHAN);

class SoundUI : public GenericUI
{
		
    private:
    
        std::vector<std::string> fSoundfileDir;        // The soundfile directories
        std::map<std::string, Soundfile*> fSFMap;      // Map to share loaded soundfiles
    
     public:
            
        SoundUI(const std::string& sound_directory = "")
        {
            fSoundfileDir.push_back(sound_directory);
        }
    
        SoundUI(const std::vector<std::string>& sound_directories):fSoundfileDir(sound_directories)
        {}
    
        virtual ~SoundUI()
        {   
            // delete all soundfiles
            std::map<std::string, Soundfile*>::iterator it;
            for (it = fSFMap.begin(); it != fSFMap.end(); it++) {
                delete (*it).second;
            }
        }

        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* file_name, Soundfile** sf_zone)
        {
            // If no filename was given, assume label is the filename
            std::string file_name_str;
            if (strlen(file_name) == 0) {
                file_name_str = label;
            } else {
                file_name_str = file_name;
            }
            
            std::string sha_key;
            std::string path_name_str = Soundfile::Check(fSoundfileDir, file_name_str, sha_key);
            if (path_name_str != "") {
                std::string file_key = (sha_key == "") ? path_name_str : sha_key;
                // Check if 'file_key' is already loaded
                if (fSFMap.find(file_key) == fSFMap.end()) {
                    fSFMap[file_key] = new Soundfile(path_name_str, 64);
                }
                // Get the soundfile
                *sf_zone = fSFMap[file_key];
            } else {
                // Take the defaultsound
                std::cout << "addSoundfile : defaultsound\n";
                *sf_zone = defaultsound;
            }
        }
    
    static std::string getBinaryPath(std::string folder = "")
    {
        std::string bundle_path_str;
    #ifdef __APPLE__
        CFURLRef bundle_ref = CFBundleCopyBundleURL(CFBundleGetMainBundle());
        if (bundle_ref) {
            UInt8 bundle_path[512];
            if (CFURLGetFileSystemRepresentation(bundle_ref, true, bundle_path, 512)) {
                bundle_path_str = std::string((char*)bundle_path) + folder;
            }
        }
    #endif
        return bundle_path_str;
    }
    
    static std::string getBinaryPathFrom(const std::string& path)
    {
        std::string bundle_path_str;
    #ifdef __APPLE__
        CFBundleRef bundle = CFBundleGetBundleWithIdentifier(CFStringCreateWithCString(kCFAllocatorDefault, path.c_str(), CFStringGetSystemEncoding()));
        CFURLRef bundle_ref = CFBundleCopyBundleURL(bundle);
        if (bundle_ref) {
            UInt8 bundle_path[512];
            if (CFURLGetFileSystemRepresentation(bundle_ref, true, bundle_path, 512)) {
                bundle_path_str = std::string((char*)bundle_path);
            }
        }
    #endif
        return bundle_path_str;
    }
};

#endif
#endif

using namespace std;

/******************************************************************************
*******************************************************************************

							       VECTOR INTRINSICS

*******************************************************************************
*******************************************************************************/


/********************END ARCHITECTURE SECTION (part 1/2)****************/

/**************************BEGIN USER SECTION **************************/

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <math.h>

double mydsp_faustpower2_f(double value) {
	return (value * value);
	
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif
#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {
	
 private:
	
	int fSamplingFreq;
	int iConst0;
	double fConst1;
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	FAUSTFLOAT fHslider0;
	double fRec16[2];
	double fRec15[3];
	FAUSTFLOAT fHslider1;
	double fRec17[2];
	double fRec18[3];
	double fRec19[3];
	double fRec20[3];
	double fRec21[3];
	double fRec22[3];
	double fRec23[3];
	double fRec24[3];
	double fRec25[3];
	double fRec26[3];
	double fRec27[3];
	double fConst7;
	double fConst8;
	double fConst9;
	double fRec14[2];
	double fRec12[2];
	double fRec11[2];
	double fRec9[2];
	double fConst10;
	double fConst11;
	double fRec8[2];
	double fRec6[2];
	double fRec5[2];
	double fRec3[2];
	double fConst12;
	double fRec2[2];
	double fRec0[2];
	double fRec28[3];
	double fConst13;
	double fConst14;
	double fConst15;
	double fConst16;
	double fConst17;
	double fRec41[3];
	double fRec42[3];
	double fRec43[3];
	double fRec44[3];
	double fRec45[3];
	double fRec46[3];
	double fRec47[3];
	double fRec48[3];
	double fRec49[3];
	double fConst18;
	double fConst19;
	double fRec40[2];
	double fRec38[2];
	double fRec37[2];
	double fRec35[2];
	double fRec34[2];
	double fRec32[2];
	double fRec31[2];
	double fRec29[2];
	double fConst20;
	double fConst21;
	double fConst22;
	double fConst23;
	double fRec59[3];
	double fRec60[3];
	double fRec61[3];
	double fRec62[3];
	double fRec63[3];
	double fRec64[3];
	double fRec65[3];
	double fConst24;
	double fConst25;
	double fRec58[2];
	double fRec56[2];
	double fRec55[2];
	double fRec53[2];
	double fRec52[2];
	double fRec50[2];
	double fConst26;
	double fConst27;
	double fRec69[3];
	double fRec70[3];
	double fRec71[3];
	double fConst28;
	double fRec68[2];
	double fRec66[2];
	double fConst29;
	double fConst30;
	double fRec78[3];
	double fRec79[3];
	double fRec80[3];
	double fRec81[3];
	double fRec82[3];
	double fConst31;
	double fConst32;
	double fRec77[2];
	double fRec75[2];
	double fRec74[2];
	double fRec72[2];
	int IOTA;
	double fVec0[128];
	int iConst33;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fCheckbox0;
	double fRec83[2];
	double fConst34;
	double fConst35;
	double fConst36;
	double fRec86[2];
	double fRec84[2];
	double fConst37;
	double fConst38;
	double fConst39;
	double fConst40;
	double fRec92[2];
	double fRec90[2];
	double fRec89[2];
	double fRec87[2];
	double fConst41;
	double fConst42;
	double fConst43;
	double fConst44;
	double fConst45;
	double fConst46;
	double fRec101[2];
	double fRec99[2];
	double fRec98[2];
	double fRec96[2];
	double fRec95[2];
	double fRec93[2];
	double fConst47;
	double fConst48;
	double fConst49;
	double fConst50;
	double fConst51;
	double fConst52;
	double fConst53;
	double fRec113[2];
	double fRec111[2];
	double fRec110[2];
	double fRec108[2];
	double fRec107[2];
	double fRec105[2];
	double fRec104[2];
	double fRec102[2];
	double fConst54;
	double fConst55;
	double fConst56;
	double fConst57;
	double fConst58;
	double fConst59;
	double fConst60;
	double fConst61;
	double fConst62;
	double fRec128[2];
	double fRec126[2];
	double fRec125[2];
	double fRec123[2];
	double fRec122[2];
	double fRec120[2];
	double fRec119[2];
	double fRec117[2];
	double fRec116[2];
	double fRec114[2];
	double fVec1[64];
	int iConst63;
	double fConst64;
	double fConst65;
	double fConst66;
	double fRec131[2];
	double fRec129[2];
	double fConst67;
	double fConst68;
	double fConst69;
	double fConst70;
	double fRec137[2];
	double fRec135[2];
	double fRec134[2];
	double fRec132[2];
	double fConst71;
	double fConst72;
	double fConst73;
	double fConst74;
	double fConst75;
	double fConst76;
	double fRec146[2];
	double fRec144[2];
	double fRec143[2];
	double fRec141[2];
	double fRec140[2];
	double fRec138[2];
	double fConst77;
	double fConst78;
	double fConst79;
	double fConst80;
	double fConst81;
	double fConst82;
	double fConst83;
	double fRec158[2];
	double fRec156[2];
	double fRec155[2];
	double fRec153[2];
	double fRec152[2];
	double fRec150[2];
	double fRec149[2];
	double fRec147[2];
	double fConst84;
	double fConst85;
	double fConst86;
	double fConst87;
	double fConst88;
	double fConst89;
	double fConst90;
	double fConst91;
	double fConst92;
	double fRec173[2];
	double fRec171[2];
	double fRec170[2];
	double fRec168[2];
	double fRec167[2];
	double fRec165[2];
	double fRec164[2];
	double fRec162[2];
	double fRec161[2];
	double fRec159[2];
	double fVec2[64];
	int iConst93;
	double fConst94;
	double fConst95;
	double fConst96;
	double fRec176[2];
	double fRec174[2];
	double fConst97;
	double fConst98;
	double fConst99;
	double fConst100;
	double fRec182[2];
	double fRec180[2];
	double fRec179[2];
	double fRec177[2];
	double fConst101;
	double fConst102;
	double fConst103;
	double fConst104;
	double fConst105;
	double fConst106;
	double fRec191[2];
	double fRec189[2];
	double fRec188[2];
	double fRec186[2];
	double fRec185[2];
	double fRec183[2];
	double fConst107;
	double fConst108;
	double fConst109;
	double fConst110;
	double fConst111;
	double fConst112;
	double fConst113;
	double fRec203[2];
	double fRec201[2];
	double fRec200[2];
	double fRec198[2];
	double fRec197[2];
	double fRec195[2];
	double fRec194[2];
	double fRec192[2];
	double fConst114;
	double fConst115;
	double fConst116;
	double fConst117;
	double fConst118;
	double fConst119;
	double fConst120;
	double fConst121;
	double fConst122;
	double fRec218[2];
	double fRec216[2];
	double fRec215[2];
	double fRec213[2];
	double fRec212[2];
	double fRec210[2];
	double fRec209[2];
	double fRec207[2];
	double fRec206[2];
	double fRec204[2];
	double fVec3[16];
	int iConst123;
	double fRec221[2];
	double fRec219[2];
	double fRec227[2];
	double fRec225[2];
	double fRec224[2];
	double fRec222[2];
	double fRec236[2];
	double fRec234[2];
	double fRec233[2];
	double fRec231[2];
	double fRec230[2];
	double fRec228[2];
	double fRec248[2];
	double fRec246[2];
	double fRec245[2];
	double fRec243[2];
	double fRec242[2];
	double fRec240[2];
	double fRec239[2];
	double fRec237[2];
	double fRec263[2];
	double fRec261[2];
	double fRec260[2];
	double fRec258[2];
	double fRec257[2];
	double fRec255[2];
	double fRec254[2];
	double fRec252[2];
	double fRec251[2];
	double fRec249[2];
	double fVec4[64];
	double fConst124;
	double fConst125;
	double fConst126;
	double fConst127;
	double fConst128;
	double fConst129;
	double fConst130;
	double fConst131;
	double fConst132;
	double fRec278[2];
	double fRec276[2];
	double fRec275[2];
	double fRec273[2];
	double fRec272[2];
	double fRec270[2];
	double fRec269[2];
	double fRec267[2];
	double fRec266[2];
	double fRec264[2];
	double fConst133;
	double fConst134;
	double fConst135;
	double fRec281[2];
	double fRec279[2];
	double fConst136;
	double fConst137;
	double fConst138;
	double fConst139;
	double fRec287[2];
	double fRec285[2];
	double fRec284[2];
	double fRec282[2];
	double fConst140;
	double fConst141;
	double fConst142;
	double fConst143;
	double fConst144;
	double fConst145;
	double fRec296[2];
	double fRec294[2];
	double fRec293[2];
	double fRec291[2];
	double fRec290[2];
	double fRec288[2];
	double fConst146;
	double fConst147;
	double fConst148;
	double fConst149;
	double fConst150;
	double fRec308[2];
	double fRec306[2];
	double fRec305[2];
	double fRec303[2];
	double fConst151;
	double fConst152;
	double fRec302[2];
	double fRec300[2];
	double fRec299[2];
	double fRec297[2];
	double fVec5[8];
	int iConst153;
	double fConst154;
	double fConst155;
	double fConst156;
	double fConst157;
	double fConst158;
	double fConst159;
	double fConst160;
	double fConst161;
	double fConst162;
	double fRec323[2];
	double fRec321[2];
	double fRec320[2];
	double fRec318[2];
	double fRec317[2];
	double fRec315[2];
	double fRec314[2];
	double fRec312[2];
	double fRec311[2];
	double fRec309[2];
	double fConst163;
	double fConst164;
	double fConst165;
	double fConst166;
	double fConst167;
	double fConst168;
	double fConst169;
	double fRec335[2];
	double fRec333[2];
	double fRec332[2];
	double fRec330[2];
	double fRec329[2];
	double fRec327[2];
	double fRec326[2];
	double fRec324[2];
	double fConst170;
	double fConst171;
	double fConst172;
	double fConst173;
	double fConst174;
	double fConst175;
	double fRec344[2];
	double fRec342[2];
	double fRec341[2];
	double fRec339[2];
	double fRec338[2];
	double fRec336[2];
	double fConst176;
	double fConst177;
	double fConst178;
	double fConst179;
	double fRec350[2];
	double fRec348[2];
	double fRec347[2];
	double fRec345[2];
	double fConst180;
	double fConst181;
	double fConst182;
	double fRec353[2];
	double fRec351[2];
	double fConst183;
	double fConst184;
	double fConst185;
	double fRec356[2];
	double fRec354[2];
	double fConst186;
	double fConst187;
	double fConst188;
	double fConst189;
	double fConst190;
	double fConst191;
	double fConst192;
	double fConst193;
	double fConst194;
	double fRec371[2];
	double fRec369[2];
	double fRec368[2];
	double fRec366[2];
	double fRec365[2];
	double fRec363[2];
	double fRec362[2];
	double fRec360[2];
	double fRec359[2];
	double fRec357[2];
	double fConst195;
	double fConst196;
	double fConst197;
	double fConst198;
	double fConst199;
	double fConst200;
	double fConst201;
	double fRec383[2];
	double fRec381[2];
	double fRec380[2];
	double fRec378[2];
	double fRec377[2];
	double fRec375[2];
	double fRec374[2];
	double fRec372[2];
	double fConst202;
	double fConst203;
	double fConst204;
	double fConst205;
	double fRec389[2];
	double fRec387[2];
	double fRec386[2];
	double fRec384[2];
	double fConst206;
	double fConst207;
	double fConst208;
	double fConst209;
	double fConst210;
	double fConst211;
	double fRec398[2];
	double fRec396[2];
	double fRec395[2];
	double fRec393[2];
	double fRec392[2];
	double fRec390[2];
	double fVec6[128];
	int iConst212;
	double fConst213;
	double fConst214;
	double fConst215;
	double fConst216;
	double fConst217;
	double fConst218;
	double fConst219;
	double fConst220;
	double fConst221;
	double fRec413[2];
	double fRec411[2];
	double fRec410[2];
	double fRec408[2];
	double fRec407[2];
	double fRec405[2];
	double fRec404[2];
	double fRec402[2];
	double fRec401[2];
	double fRec399[2];
	double fConst222;
	double fConst223;
	double fConst224;
	double fConst225;
	double fConst226;
	double fConst227;
	double fConst228;
	double fRec425[2];
	double fRec423[2];
	double fRec422[2];
	double fRec420[2];
	double fRec419[2];
	double fRec417[2];
	double fRec416[2];
	double fRec414[2];
	double fConst229;
	double fConst230;
	double fConst231;
	double fConst232;
	double fConst233;
	double fConst234;
	double fRec434[2];
	double fRec432[2];
	double fRec431[2];
	double fRec429[2];
	double fRec428[2];
	double fRec426[2];
	double fConst235;
	double fConst236;
	double fConst237;
	double fRec437[2];
	double fRec435[2];
	double fConst238;
	double fConst239;
	double fConst240;
	double fConst241;
	double fRec443[2];
	double fRec441[2];
	double fRec440[2];
	double fRec438[2];
	double fVec7[64];
	int iConst242;
	double fConst243;
	double fConst244;
	double fConst245;
	double fConst246;
	double fConst247;
	double fConst248;
	double fConst249;
	double fConst250;
	double fConst251;
	double fRec458[2];
	double fRec456[2];
	double fRec455[2];
	double fRec453[2];
	double fRec452[2];
	double fRec450[2];
	double fRec449[2];
	double fRec447[2];
	double fRec446[2];
	double fRec444[2];
	double fConst252;
	double fConst253;
	double fConst254;
	double fConst255;
	double fConst256;
	double fConst257;
	double fConst258;
	double fRec470[2];
	double fRec468[2];
	double fRec467[2];
	double fRec465[2];
	double fRec464[2];
	double fRec462[2];
	double fRec461[2];
	double fRec459[2];
	double fConst259;
	double fConst260;
	double fConst261;
	double fConst262;
	double fConst263;
	double fConst264;
	double fRec479[2];
	double fRec477[2];
	double fRec476[2];
	double fRec474[2];
	double fRec473[2];
	double fRec471[2];
	double fConst265;
	double fConst266;
	double fConst267;
	double fRec482[2];
	double fRec480[2];
	double fConst268;
	double fConst269;
	double fConst270;
	double fConst271;
	double fRec488[2];
	double fRec486[2];
	double fRec485[2];
	double fRec483[2];
	double fVec8[256];
	int iConst272;
	double fRec503[2];
	double fRec501[2];
	double fRec500[2];
	double fRec498[2];
	double fRec497[2];
	double fRec495[2];
	double fRec494[2];
	double fRec492[2];
	double fRec491[2];
	double fRec489[2];
	double fRec515[2];
	double fRec513[2];
	double fRec512[2];
	double fRec510[2];
	double fRec509[2];
	double fRec507[2];
	double fRec506[2];
	double fRec504[2];
	double fRec524[2];
	double fRec522[2];
	double fRec521[2];
	double fRec519[2];
	double fRec518[2];
	double fRec516[2];
	double fRec527[2];
	double fRec525[2];
	double fRec533[2];
	double fRec531[2];
	double fRec530[2];
	double fRec528[2];
	double fVec9[256];
	double fConst273;
	double fConst274;
	double fConst275;
	double fConst276;
	double fConst277;
	double fConst278;
	double fConst279;
	double fConst280;
	double fConst281;
	double fRec548[2];
	double fRec546[2];
	double fRec545[2];
	double fRec543[2];
	double fRec542[2];
	double fRec540[2];
	double fRec539[2];
	double fRec537[2];
	double fRec536[2];
	double fRec534[2];
	double fConst282;
	double fConst283;
	double fConst284;
	double fConst285;
	double fConst286;
	double fConst287;
	double fConst288;
	double fRec560[2];
	double fRec558[2];
	double fRec557[2];
	double fRec555[2];
	double fRec554[2];
	double fRec552[2];
	double fRec551[2];
	double fRec549[2];
	double fConst289;
	double fConst290;
	double fConst291;
	double fConst292;
	double fConst293;
	double fConst294;
	double fRec569[2];
	double fRec567[2];
	double fRec566[2];
	double fRec564[2];
	double fRec563[2];
	double fRec561[2];
	double fConst295;
	double fConst296;
	double fConst297;
	double fRec572[2];
	double fRec570[2];
	double fConst298;
	double fConst299;
	double fConst300;
	double fConst301;
	double fRec578[2];
	double fRec576[2];
	double fRec575[2];
	double fRec573[2];
	double fVec10[256];
	int iConst302;
	double fRec593[2];
	double fRec591[2];
	double fRec590[2];
	double fRec588[2];
	double fRec587[2];
	double fRec585[2];
	double fRec584[2];
	double fRec582[2];
	double fRec581[2];
	double fRec579[2];
	double fRec605[2];
	double fRec603[2];
	double fRec602[2];
	double fRec600[2];
	double fRec599[2];
	double fRec597[2];
	double fRec596[2];
	double fRec594[2];
	double fRec614[2];
	double fRec612[2];
	double fRec611[2];
	double fRec609[2];
	double fRec608[2];
	double fRec606[2];
	double fRec620[2];
	double fRec618[2];
	double fRec617[2];
	double fRec615[2];
	double fRec623[2];
	double fRec621[2];
	double fVec11[256];
	double fConst303;
	double fConst304;
	double fConst305;
	double fConst306;
	double fConst307;
	double fConst308;
	double fConst309;
	double fRec635[2];
	double fRec633[2];
	double fRec632[2];
	double fRec630[2];
	double fRec629[2];
	double fRec627[2];
	double fRec626[2];
	double fRec624[2];
	double fConst310;
	double fConst311;
	double fConst312;
	double fConst313;
	double fConst314;
	double fConst315;
	double fRec644[2];
	double fRec642[2];
	double fRec641[2];
	double fRec639[2];
	double fRec638[2];
	double fRec636[2];
	double fConst316;
	double fConst317;
	double fConst318;
	double fConst319;
	double fRec650[2];
	double fRec648[2];
	double fRec647[2];
	double fRec645[2];
	double fConst320;
	double fConst321;
	double fConst322;
	double fRec653[2];
	double fRec651[2];
	double fConst323;
	double fConst324;
	double fConst325;
	double fConst326;
	double fConst327;
	double fConst328;
	double fConst329;
	double fConst330;
	double fConst331;
	double fRec668[2];
	double fRec666[2];
	double fRec665[2];
	double fRec663[2];
	double fRec662[2];
	double fRec660[2];
	double fRec659[2];
	double fRec657[2];
	double fRec656[2];
	double fRec654[2];
	double fVec12[1024];
	int iConst332;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "AmbisonicDecoderToolkit");
		m->declare("copyright", "(c) Aaron J. Heller 2013");
		m->declare("filename", "KMH114_AEC_5h5p_full_6");
		m->declare("license", "BSD 3-Clause License");
		m->declare("name", "KMH114_AEC_5h5p_full_6");
		m->declare("version", "1.2");
	}

	virtual int getNumInputs() {
		return 36;
		
	}
	virtual int getNumOutputs() {
		return 14;
		
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			case 2: {
				rate = 1;
				break;
			}
			case 3: {
				rate = 1;
				break;
			}
			case 4: {
				rate = 1;
				break;
			}
			case 5: {
				rate = 1;
				break;
			}
			case 6: {
				rate = 1;
				break;
			}
			case 7: {
				rate = 1;
				break;
			}
			case 8: {
				rate = 1;
				break;
			}
			case 9: {
				rate = 1;
				break;
			}
			case 10: {
				rate = 1;
				break;
			}
			case 11: {
				rate = 1;
				break;
			}
			case 12: {
				rate = 1;
				break;
			}
			case 13: {
				rate = 1;
				break;
			}
			case 14: {
				rate = 1;
				break;
			}
			case 15: {
				rate = 1;
				break;
			}
			case 16: {
				rate = 1;
				break;
			}
			case 17: {
				rate = 1;
				break;
			}
			case 18: {
				rate = 1;
				break;
			}
			case 19: {
				rate = 1;
				break;
			}
			case 20: {
				rate = 1;
				break;
			}
			case 21: {
				rate = 1;
				break;
			}
			case 22: {
				rate = 1;
				break;
			}
			case 23: {
				rate = 1;
				break;
			}
			case 24: {
				rate = 1;
				break;
			}
			case 25: {
				rate = 1;
				break;
			}
			case 26: {
				rate = 1;
				break;
			}
			case 27: {
				rate = 1;
				break;
			}
			case 28: {
				rate = 1;
				break;
			}
			case 29: {
				rate = 1;
				break;
			}
			case 30: {
				rate = 1;
				break;
			}
			case 31: {
				rate = 1;
				break;
			}
			case 32: {
				rate = 1;
				break;
			}
			case 33: {
				rate = 1;
				break;
			}
			case 34: {
				rate = 1;
				break;
			}
			case 35: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			case 2: {
				rate = 1;
				break;
			}
			case 3: {
				rate = 1;
				break;
			}
			case 4: {
				rate = 1;
				break;
			}
			case 5: {
				rate = 1;
				break;
			}
			case 6: {
				rate = 1;
				break;
			}
			case 7: {
				rate = 1;
				break;
			}
			case 8: {
				rate = 1;
				break;
			}
			case 9: {
				rate = 1;
				break;
			}
			case 10: {
				rate = 1;
				break;
			}
			case 11: {
				rate = 1;
				break;
			}
			case 12: {
				rate = 1;
				break;
			}
			case 13: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	static void classInit(int samplingFreq) {
		
	}
	
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		iConst0 = std::min(192000, std::max(1, fSamplingFreq));
		fConst1 = double(iConst0);
		fConst2 = ((191.96533911319742 / fConst1) + 1.0);
		fConst3 = ((((39549.029677540268 / fConst1) + 352.89584379873679) / fConst1) + 1.0);
		fConst4 = ((((50311.132146818818 / fConst1) + 244.74301037618173) / fConst1) + 1.0);
		fConst5 = (1.0 / ((fConst2 * fConst3) * fConst4));
		fConst6 = (3.1415926535897931 / double(iConst0));
		fConst7 = (0.0 - (((201244.52858727527 / fConst1) + 489.48602075236346) / (fConst1 * fConst4)));
		fConst8 = mydsp_faustpower2_f(fConst1);
		fConst9 = (0.0 - (201244.52858727527 / (fConst8 * fConst4)));
		fConst10 = (0.0 - (((158196.11871016107 / fConst1) + 705.79168759747358) / (fConst1 * fConst3)));
		fConst11 = (0.0 - (158196.11871016107 / (fConst8 * fConst3)));
		fConst12 = (0.0 - (383.93067822639483 / (fConst1 * fConst2)));
		fConst13 = ((((25327.293843552216 / fConst1) + 304.91467155099616) / fConst1) + 1.0);
		fConst14 = (0.0 - (101309.17537420886 / (fConst8 * fConst13)));
		fConst15 = (0.0 - (((101309.17537420886 / fConst1) + 609.82934310199232) / (fConst1 * fConst13)));
		fConst16 = ((((31832.683993978117 / fConst1) + 221.48812397441478) / fConst1) + 1.0);
		fConst17 = (1.0 / (fConst13 * fConst16));
		fConst18 = (0.0 - (127330.73597591247 / (fConst8 * fConst16)));
		fConst19 = (0.0 - (((127330.73597591247 / fConst1) + 442.97624794882955) / (fConst1 * fConst16)));
		fConst20 = ((122.24048624033396 / fConst1) + 1.0);
		fConst21 = (0.0 - (244.48097248066793 / (fConst1 * fConst20)));
		fConst22 = ((((17899.081736840039 / fConst1) + 193.60119107491266) / fConst1) + 1.0);
		fConst23 = (1.0 / (fConst20 * fConst22));
		fConst24 = (0.0 - (71596.326947360154 / (fConst8 * fConst22)));
		fConst25 = (0.0 - (((71596.326947360154 / fConst1) + 387.20238214982533) / (fConst1 * fConst22)));
		fConst26 = ((52.640279552541102 / fConst1) + 1.0);
		fConst27 = (1.0 / fConst26);
		fConst28 = (0.0 - (105.2805591050822 / (fConst1 * fConst26)));
		fConst29 = ((((8312.9970941090305 / fConst1) + 157.92083865762331) / fConst1) + 1.0);
		fConst30 = (1.0 / fConst29);
		fConst31 = (0.0 - (33251.988376436122 / (fConst8 * fConst29)));
		fConst32 = (0.0 - (((33251.988376436122 / fConst1) + 315.84167731524661) / (fConst1 * fConst29)));
		iConst33 = int(((0.00033798093768075285 * double(iConst0)) + 0.5));
		fConst34 = ((52.479300104368185 / fConst1) + 1.0);
		fConst35 = (1.0 / fConst34);
		fConst36 = (0.0 - (104.95860020873637 / (fConst1 * fConst34)));
		fConst37 = ((((8262.2308183330169 / fConst1) + 157.43790031310456) / fConst1) + 1.0);
		fConst38 = (1.0 / fConst37);
		fConst39 = (0.0 - (33048.923273332068 / (fConst8 * fConst37)));
		fConst40 = (0.0 - (((33048.923273332068 / fConst1) + 314.87580062620913) / (fConst1 * fConst37)));
		fConst41 = ((121.86666212339102 / fConst1) + 1.0);
		fConst42 = (0.0 - (243.73332424678205 / (fConst1 * fConst41)));
		fConst43 = ((((17789.774623015379 / fConst1) + 193.00913850281808) / fConst1) + 1.0);
		fConst44 = (1.0 / (fConst41 * fConst43));
		fConst45 = (0.0 - (71159.098492061516 / (fConst8 * fConst43)));
		fConst46 = (0.0 - (((71159.098492061516 / fConst1) + 386.01827700563615) / (fConst1 * fConst43)));
		fConst47 = ((((25172.623708417312 / fConst1) + 303.98221078172702) / fConst1) + 1.0);
		fConst48 = (0.0 - (100690.49483366925 / (fConst8 * fConst47)));
		fConst49 = (0.0 - (((100690.49483366925 / fConst1) + 607.96442156345404) / (fConst1 * fConst47)));
		fConst50 = ((((31638.286378288562 / fConst1) + 220.81079026195476) / fConst1) + 1.0);
		fConst51 = (1.0 / (fConst47 * fConst50));
		fConst52 = (0.0 - (126553.14551315425 / (fConst8 * fConst50)));
		fConst53 = (0.0 - (((126553.14551315425 / fConst1) + 441.62158052390953) / (fConst1 * fConst50)));
		fConst54 = ((191.37828914649037 / fConst1) + 1.0);
		fConst55 = (0.0 - (382.75657829298075 / (fConst1 * fConst54)));
		fConst56 = ((((39307.50945029196 / fConst1) + 351.81665161586596) / fConst1) + 1.0);
		fConst57 = (0.0 - (157230.03780116784 / (fConst8 * fConst56)));
		fConst58 = (0.0 - (((157230.03780116784 / fConst1) + 703.63330323173193) / (fConst1 * fConst56)));
		fConst59 = ((((50003.889310059159 / fConst1) + 243.99456080316583) / fConst1) + 1.0);
		fConst60 = (1.0 / ((fConst54 * fConst56) * fConst59));
		fConst61 = (0.0 - (200015.55724023664 / (fConst8 * fConst59)));
		fConst62 = (0.0 - (((200015.55724023664 / fConst1) + 487.98912160633165) / (fConst1 * fConst59)));
		iConst63 = int(((0.00030884464994965281 * double(iConst0)) + 0.5));
		fConst64 = ((52.002215557964846 / fConst1) + 1.0);
		fConst65 = (1.0 / fConst64);
		fConst66 = (0.0 - (104.00443111592969 / (fConst1 * fConst64)));
		fConst67 = ((((8112.6912688111233 / fConst1) + 156.00664667389452) / fConst1) + 1.0);
		fConst68 = (1.0 / fConst67);
		fConst69 = (0.0 - (32450.765075244493 / (fConst8 * fConst67)));
		fConst70 = (0.0 - (((32450.765075244493 / fConst1) + 312.01329334778904) / (fConst1 * fConst67)));
		fConst71 = ((120.75878337681476 / fConst1) + 1.0);
		fConst72 = (0.0 - (241.51756675362952 / (fConst1 * fConst71)));
		fConst73 = ((((17467.794404631881 / fConst1) + 191.25450997097431) / fConst1) + 1.0);
		fConst74 = (1.0 / (fConst71 * fConst73));
		fConst75 = (0.0 - (69871.177618527523 / (fConst8 * fConst73)));
		fConst76 = (0.0 - (((69871.177618527523 / fConst1) + 382.50901994194862) / (fConst1 * fConst73)));
		fConst77 = ((((24717.020023116213 / fConst1) + 301.21873613825682) / fConst1) + 1.0);
		fConst78 = (0.0 - (98868.08009246485 / (fConst77 * fConst8)));
		fConst79 = (0.0 - (((98868.08009246485 / fConst1) + 602.43747227651363) / (fConst77 * fConst1)));
		fConst80 = ((((31065.659542185662 / fConst1) + 218.80341944139155) / fConst1) + 1.0);
		fConst81 = (1.0 / (fConst77 * fConst80));
		fConst82 = (0.0 - (124262.63816874265 / (fConst80 * fConst8)));
		fConst83 = (0.0 - (((124262.63816874265 / fConst1) + 437.60683888278311) / (fConst80 * fConst1)));
		fConst84 = ((189.63848651788592 / fConst1) + 1.0);
		fConst85 = (0.0 - (379.27697303577185 / (fConst1 * fConst84)));
		fConst86 = ((((38596.076014786682 / fConst1) + 348.61831841935816) / fConst1) + 1.0);
		fConst87 = (0.0 - (154384.30405914673 / (fConst8 * fConst86)));
		fConst88 = (0.0 - (((154384.30405914673 / fConst1) + 697.23663683871632) / (fConst1 * fConst86)));
		fConst89 = ((((49098.860239075453 / fConst1) + 241.77642843222799) / fConst1) + 1.0);
		fConst90 = (1.0 / ((fConst84 * fConst86) * fConst89));
		fConst91 = (0.0 - (196395.44095630181 / (fConst8 * fConst89)));
		fConst92 = (0.0 - (((196395.44095630181 / fConst1) + 483.55285686445598) / (fConst1 * fConst89)));
		iConst93 = int(((0.00022143578675635532 * double(iConst0)) + 0.5));
		fConst94 = ((51.22606308695044 / fConst1) + 1.0);
		fConst95 = (1.0 / fConst94);
		fConst96 = (0.0 - (102.45212617390088 / (fConst1 * fConst94)));
		fConst97 = ((((7872.3286181646799 / fConst1) + 153.67818926085133) / fConst1) + 1.0);
		fConst98 = (1.0 / fConst97);
		fConst99 = (0.0 - (31489.31447265872 / (fConst8 * fConst97)));
		fConst100 = (0.0 - (((31489.31447265872 / fConst1) + 307.35637852170265) / (fConst1 * fConst97)));
		fConst101 = ((118.95641347566826 / fConst1) + 1.0);
		fConst102 = (0.0 - (237.91282695133651 / (fConst1 * fConst101)));
		fConst103 = ((((16950.258950005893 / fConst1) + 188.39996504603437) / fConst1) + 1.0);
		fConst104 = (1.0 / (fConst101 * fConst103));
		fConst105 = (0.0 - (67801.035800023572 / (fConst8 * fConst103)));
		fConst106 = (0.0 - (((67801.035800023572 / fConst1) + 376.79993009206873) / (fConst1 * fConst103)));
		fConst107 = ((((23984.704660435331 / fConst1) + 296.72293410634251) / fConst1) + 1.0);
		fConst108 = (0.0 - (95938.818641741324 / (fConst8 * fConst107)));
		fConst109 = (0.0 - (((95938.818641741324 / fConst1) + 593.44586821268501) / (fConst1 * fConst107)));
		fConst110 = ((((30145.246817946248 / fConst1) + 215.53769676316182) / fConst1) + 1.0);
		fConst111 = (1.0 / (fConst107 * fConst110));
		fConst112 = (0.0 - (120580.98727178499 / (fConst8 * fConst110)));
		fConst113 = (0.0 - (((120580.98727178499 / fConst1) + 431.07539352632364) / (fConst1 * fConst110)));
		fConst114 = ((186.80806134597717 / fConst1) + 1.0);
		fConst115 = (0.0 - (373.61612269195433 / (fConst1 * fConst114)));
		fConst116 = ((((37452.552265629485 / fConst1) + 343.41505993548714) / fConst1) + 1.0);
		fConst117 = (0.0 - (149810.20906251794 / (fConst8 * fConst116)));
		fConst118 = (0.0 - (((149810.20906251794 / fConst1) + 686.83011987097427) / (fConst1 * fConst116)));
		fConst119 = ((((47644.160214170784 / fConst1) + 238.16782502279173) / fConst1) + 1.0);
		fConst120 = (1.0 / ((fConst114 * fConst116) * fConst119));
		fConst121 = (0.0 - (190576.64085668314 / (fConst8 * fConst119)));
		fConst122 = (0.0 - (((190576.64085668314 / fConst1) + 476.33565004558346) / (fConst1 * fConst119)));
		iConst123 = int(((7.5754348100857757e-05 * double(iConst0)) + 0.5));
		fConst124 = ((186.03061994917465 / fConst1) + 1.0);
		fConst125 = (0.0 - (372.0612398983493 / (fConst1 * fConst124)));
		fConst126 = ((((37141.467447258146 / fConst1) + 341.98586527463789) / fConst1) + 1.0);
		fConst127 = (0.0 - (148565.86978903259 / (fConst8 * fConst126)));
		fConst128 = (0.0 - (((148565.86978903259 / fConst1) + 683.97173054927578) / (fConst1 * fConst126)));
		fConst129 = ((((47248.422833669691 / fConst1) + 237.17663906847574) / fConst1) + 1.0);
		fConst130 = (1.0 / ((fConst124 * fConst126) * fConst129));
		fConst131 = (0.0 - (188993.69133467876 / (fConst8 * fConst129)));
		fConst132 = (0.0 - (((188993.69133467876 / fConst1) + 474.35327813695147) / (fConst1 * fConst129)));
		fConst133 = ((51.01287495281926 / fConst1) + 1.0);
		fConst134 = (1.0 / fConst133);
		fConst135 = (0.0 - (102.02574990563852 / (fConst1 * fConst133)));
		fConst136 = ((((7806.9402328559245 / fConst1) + 153.03862485845778) / fConst1) + 1.0);
		fConst137 = (1.0 / fConst136);
		fConst138 = (0.0 - (31227.760931423698 / (fConst8 * fConst136)));
		fConst139 = (0.0 - (((31227.760931423698 / fConst1) + 306.07724971691556) / (fConst1 * fConst136)));
		fConst140 = ((118.46135111280877 / fConst1) + 1.0);
		fConst141 = (0.0 - (236.92270222561754 / (fConst1 * fConst140)));
		fConst142 = ((((16809.468325393405 / fConst1) + 187.61589860410677) / fConst1) + 1.0);
		fConst143 = (1.0 / (fConst140 * fConst142));
		fConst144 = (0.0 - (67237.873301573622 / (fConst8 * fConst142)));
		fConst145 = (0.0 - (((67237.873301573622 / fConst1) + 375.23179720821355) / (fConst1 * fConst142)));
		fConst146 = ((((23785.485193626679 / fConst1) + 295.48805863741006) / fConst1) + 1.0);
		fConst147 = ((((29894.857243302333 / fConst1) + 214.64069089078245) / fConst1) + 1.0);
		fConst148 = (1.0 / (fConst146 * fConst147));
		fConst149 = (0.0 - (119579.42897320933 / (fConst8 * fConst147)));
		fConst150 = (0.0 - (((119579.42897320933 / fConst1) + 429.2813817815649) / (fConst1 * fConst147)));
		fConst151 = (0.0 - (95141.940774506715 / (fConst8 * fConst146)));
		fConst152 = (0.0 - (((95141.940774506715 / fConst1) + 590.97611727482013) / (fConst1 * fConst146)));
		iConst153 = int(((3.4963545277319259e-05 * double(iConst0)) + 0.5));
		fConst154 = ((185.36937366973447 / fConst1) + 1.0);
		fConst155 = (0.0 - (370.73874733946894 / (fConst1 * fConst154)));
		fConst156 = ((((36877.897842540857 / fConst1) + 340.77027570612614) / fConst1) + 1.0);
		fConst157 = (0.0 - (147511.59137016343 / (fConst8 * fConst156)));
		fConst158 = (0.0 - (((147511.59137016343 / fConst1) + 681.54055141225228) / (fConst1 * fConst156)));
		fConst159 = ((((46913.130531407551 / fConst1) + 236.33359414287688) / fConst1) + 1.0);
		fConst160 = (1.0 / ((fConst154 * fConst156) * fConst159));
		fConst161 = (0.0 - (187652.5221256302 / (fConst8 * fConst159)));
		fConst162 = (0.0 - (((187652.5221256302 / fConst1) + 472.66718828575375) / (fConst1 * fConst159)));
		fConst163 = ((((23616.69458406352 / fConst1) + 294.43774563277469) / fConst1) + 1.0);
		fConst164 = (0.0 - (94466.778336254079 / (fConst8 * fConst163)));
		fConst165 = (0.0 - (((94466.778336254079 / fConst1) + 588.87549126554939) / (fConst1 * fConst163)));
		fConst166 = ((((29682.712267665982 / fConst1) + 213.87775004638394) / fConst1) + 1.0);
		fConst167 = (1.0 / (fConst163 * fConst166));
		fConst168 = (0.0 - (118730.84907066393 / (fConst8 * fConst166)));
		fConst169 = (0.0 - (((118730.84907066393 / fConst1) + 427.75550009276787) / (fConst1 * fConst166)));
		fConst170 = ((118.04027995956419 / fConst1) + 1.0);
		fConst171 = (0.0 - (236.08055991912838 / (fConst1 * fConst170)));
		fConst172 = ((((16690.182114413106 / fConst1) + 186.94901744793106) / fConst1) + 1.0);
		fConst173 = (1.0 / (fConst170 * fConst172));
		fConst174 = (0.0 - (66760.728457652425 / (fConst8 * fConst172)));
		fConst175 = (0.0 - (((66760.728457652425 / fConst1) + 373.89803489586211) / (fConst1 * fConst172)));
		fConst176 = ((((7751.5392944264649 / fConst1) + 152.4946487037476) / fConst1) + 1.0);
		fConst177 = (1.0 / fConst176);
		fConst178 = (0.0 - (31006.15717770586 / (fConst8 * fConst176)));
		fConst179 = (0.0 - (((31006.15717770586 / fConst1) + 304.9892974074952) / (fConst1 * fConst176)));
		fConst180 = ((50.831549567915872 / fConst1) + 1.0);
		fConst181 = (1.0 / fConst180);
		fConst182 = (0.0 - (101.66309913583174 / (fConst1 * fConst180)));
		fConst183 = ((52.608004703030034 / fConst1) + 1.0);
		fConst184 = (1.0 / fConst183);
		fConst185 = (0.0 - (105.21600940606007 / (fConst1 * fConst183)));
		fConst186 = ((191.84764117382693 / fConst1) + 1.0);
		fConst187 = (0.0 - (383.69528234765386 / (fConst1 * fConst186)));
		fConst188 = ((((39500.547880469159 / fConst1) + 352.67947602203611) / fConst1) + 1.0);
		fConst189 = (0.0 - (158002.19152187664 / (fConst8 * fConst188)));
		fConst190 = (0.0 - (((158002.19152187664 / fConst1) + 705.35895204407223) / (fConst1 * fConst188)));
		fConst191 = ((((50249.457457982011 / fConst1) + 244.59295334958685) / fConst1) + 1.0);
		fConst192 = (1.0 / ((fConst186 * fConst188) * fConst191));
		fConst193 = (0.0 - (200997.82983192804 / (fConst8 * fConst191)));
		fConst194 = (0.0 - (((200997.82983192804 / fConst1) + 489.1859066991737) / (fConst1 * fConst191)));
		fConst195 = ((((25296.245983958815 / fConst1) + 304.72772202827935) / fConst1) + 1.0);
		fConst196 = (0.0 - (101184.98393583526 / (fConst8 * fConst195)));
		fConst197 = (0.0 - (((101184.98393583526 / fConst1) + 609.45544405655869) / (fConst1 * fConst195)));
		fConst198 = ((((31793.661400043246 / fConst1) + 221.35232500202088) / fConst1) + 1.0);
		fConst199 = (1.0 / (fConst195 * fConst198));
		fConst200 = (0.0 - (127174.64560017298 / (fConst8 * fConst198)));
		fConst201 = (0.0 - (((127174.64560017298 / fConst1) + 442.70465000404175) / (fConst1 * fConst198)));
		fConst202 = ((((8302.8064765020899 / fConst1) + 157.82401410909011) / fConst1) + 1.0);
		fConst203 = (1.0 / fConst202);
		fConst204 = (0.0 - (33211.22590600836 / (fConst8 * fConst202)));
		fConst205 = (0.0 - (((33211.22590600836 / fConst1) + 315.64802821818023) / (fConst1 * fConst202)));
		fConst206 = ((122.1655380574766 / fConst1) + 1.0);
		fConst207 = (0.0 - (244.33107611495319 / (fConst206 * fConst1)));
		fConst208 = ((((17877.139867327685 / fConst1) + 193.48249016070361) / fConst1) + 1.0);
		fConst209 = (1.0 / (fConst206 * fConst208));
		fConst210 = (0.0 - (71508.559469310741 / (fConst208 * fConst8)));
		fConst211 = (0.0 - (((71508.559469310741 / fConst1) + 386.96498032140721) / (fConst208 * fConst1)));
		iConst212 = int(((0.00033215368013453231 * double(iConst0)) + 0.5));
		fConst213 = ((189.86863031220375 / fConst1) + 1.0);
		fConst214 = (0.0 - (379.7372606244075 / (fConst1 * fConst213)));
		fConst215 = ((((38689.81265547558 / fConst1) + 349.04139890287684) / fConst1) + 1.0);
		fConst216 = (0.0 - (154759.25062190232 / (fConst8 * fConst215)));
		fConst217 = (0.0 - (((154759.25062190232 / fConst1) + 698.08279780575367) / (fConst1 * fConst215)));
		fConst218 = ((((49218.104543048263 / fConst1) + 242.06984642789817) / fConst1) + 1.0);
		fConst219 = (1.0 / ((fConst213 * fConst215) * fConst218));
		fConst220 = (0.0 - (196872.41817219305 / (fConst8 * fConst218)));
		fConst221 = (0.0 - (((196872.41817219305 / fConst1) + 484.13969285579634) / (fConst1 * fConst218)));
		fConst222 = ((((24777.049193540675 / fConst1) + 301.58429285687117) / fConst1) + 1.0);
		fConst223 = (0.0 - (99108.196774162701 / (fConst8 * fConst222)));
		fConst224 = (0.0 - (((99108.196774162701 / fConst1) + 603.16858571374235) / (fConst1 * fConst222)));
		fConst225 = ((((31141.107382146231 / fConst1) + 219.06895757178162) / fConst1) + 1.0);
		fConst226 = (1.0 / (fConst222 * fConst225));
		fConst227 = (0.0 - (124564.42952858492 / (fConst8 * fConst225)));
		fConst228 = (0.0 - (((124564.42952858492 / fConst1) + 438.13791514356325) / (fConst1 * fConst225)));
		fConst229 = ((120.90533529838856 / fConst1) + 1.0);
		fConst230 = (0.0 - (241.81067059677713 / (fConst1 * fConst229)));
		fConst231 = ((((17510.217690540721 / fConst1) + 191.48661495880316) / fConst1) + 1.0);
		fConst232 = (1.0 / (fConst229 * fConst231));
		fConst233 = (0.0 - (70040.870762162886 / (fConst8 * fConst231)));
		fConst234 = (0.0 - (((70040.870762162886 / fConst1) + 382.97322991760632) / (fConst1 * fConst231)));
		fConst235 = ((52.06532504286529 / fConst1) + 1.0);
		fConst236 = (1.0 / fConst235);
		fConst237 = (0.0 - (104.13065008573058 / (fConst1 * fConst235)));
		fConst238 = ((((8132.3942154576471 / fConst1) + 156.19597512859588) / fConst1) + 1.0);
		fConst239 = (1.0 / fConst238);
		fConst240 = (0.0 - (32529.576861830588 / (fConst8 * fConst238)));
		fConst241 = (0.0 - (((32529.576861830588 / fConst1) + 312.39195025719175) / (fConst1 * fConst238)));
		iConst242 = int(((0.00023309030184879507 * double(iConst0)) + 0.5));
		fConst243 = ((207.22086275133231 / fConst1) + 1.0);
		fConst244 = (0.0 - (414.44172550266461 / (fConst243 * fConst1)));
		fConst245 = ((((46084.740559737176 / fConst1) + 380.94054661717945) / fConst1) + 1.0);
		fConst246 = (0.0 - (184338.9622389487 / (fConst245 * fConst8)));
		fConst247 = (0.0 - (((184338.9622389487 / fConst1) + 761.8810932343589) / (fConst245 * fConst1)));
		fConst248 = ((((58625.344064244076 / fConst1) + 264.19278603521599) / fConst1) + 1.0);
		fConst249 = (1.0 / ((fConst243 * fConst245) * fConst248));
		fConst250 = (0.0 - (234501.37625697631 / (fConst248 * fConst8)));
		fConst251 = (0.0 - (((234501.37625697631 / fConst1) + 528.38557207043198) / (fConst248 * fConst1)));
		fConst252 = ((((29512.778831162617 / fConst1) + 329.14630107822762) / fConst1) + 1.0);
		fConst253 = (0.0 - (118051.11532465047 / (fConst8 * fConst252)));
		fConst254 = (0.0 - (((118051.11532465047 / fConst1) + 658.29260215645525) / (fConst1 * fConst252)));
		fConst255 = ((((37093.223149686615 / fConst1) + 239.08982919092455) / fConst1) + 1.0);
		fConst256 = (1.0 / (fConst252 * fConst255));
		fConst257 = (0.0 - (148372.89259874646 / (fConst8 * fConst255)));
		fConst258 = (0.0 - (((148372.89259874646 / fConst1) + 478.17965838184909) / (fConst1 * fConst255)));
		fConst259 = ((131.95496196804262 / fConst1) + 1.0);
		fConst260 = (0.0 - (263.90992393608525 / (fConst1 * fConst259)));
		fConst261 = ((((20857.010774356517 / fConst1) + 208.98671619344873) / fConst1) + 1.0);
		fConst262 = (1.0 / (fConst259 * fConst261));
		fConst263 = (0.0 - (83428.043097426067 / (fConst8 * fConst261)));
		fConst264 = (0.0 - (((83428.043097426067 / fConst1) + 417.97343238689746) / (fConst1 * fConst261)));
		fConst265 = ((56.823613026915226 / fConst1) + 1.0);
		fConst266 = (1.0 / fConst265);
		fConst267 = (0.0 - (113.64722605383045 / (fConst1 * fConst265)));
		fConst268 = ((((9686.7689922978298 / fConst1) + 170.47083908074569) / fConst1) + 1.0);
		fConst269 = (1.0 / fConst268);
		fConst270 = (0.0 - (38747.075969191319 / (fConst268 * fConst8)));
		fConst271 = (0.0 - (((38747.075969191319 / fConst1) + 340.94167816149138) / (fConst268 * fConst1)));
		iConst272 = int(((0.0010372518432271369 * double(iConst0)) + 0.5));
		fConst273 = ((205.18262475705691 / fConst1) + 1.0);
		fConst274 = (0.0 - (410.36524951411383 / (fConst1 * fConst273)));
		fConst275 = ((((45182.614114595752 / fConst1) + 377.19359042094487) / fConst1) + 1.0);
		fConst276 = (0.0 - (180730.45645838301 / (fConst8 * fConst275)));
		fConst277 = (0.0 - (((180730.45645838301 / fConst1) + 754.38718084188974) / (fConst1 * fConst275)));
		fConst278 = ((((57477.730502932725 / fConst1) + 261.59416846765652) / fConst1) + 1.0);
		fConst279 = (1.0 / ((fConst273 * fConst275) * fConst278));
		fConst280 = (0.0 - (229910.9220117309 / (fConst8 * fConst278)));
		fConst281 = (0.0 - (((229910.9220117309 / fConst1) + 523.18833693531303) / (fConst1 * fConst278)));
		fConst282 = ((((28935.054883282508 / fConst1) + 325.90879647745817) / fConst1) + 1.0);
		fConst283 = (0.0 - (115740.21953313003 / (fConst8 * fConst282)));
		fConst284 = (0.0 - (((115740.21953313003 / fConst1) + 651.81759295491634) / (fConst1 * fConst282)));
		fConst285 = ((((36367.10910125255 / fConst1) + 236.73812595298105) / fConst1) + 1.0);
		fConst286 = (1.0 / (fConst282 * fConst285));
		fConst287 = (0.0 - (145468.4364050102 / (fConst8 * fConst285)));
		fConst288 = (0.0 - (((145468.4364050102 / fConst1) + 473.4762519059621) / (fConst1 * fConst285)));
		fConst289 = ((130.65704430934056 / fConst1) + 1.0);
		fConst290 = (0.0 - (261.31408861868113 / (fConst1 * fConst289)));
		fConst291 = ((((20448.726801014909 / fConst1) + 206.93110914892304) / fConst1) + 1.0);
		fConst292 = (1.0 / (fConst289 * fConst291));
		fConst293 = (0.0 - (81794.907204059637 / (fConst8 * fConst291)));
		fConst294 = (0.0 - (((81794.907204059637 / fConst1) + 413.86221829784608) / (fConst1 * fConst291)));
		fConst295 = ((56.264692243043932 / fConst1) + 1.0);
		fConst296 = (1.0 / fConst295);
		fConst297 = (0.0 - (112.52938448608786 / (fConst1 * fConst295)));
		fConst298 = ((((9497.1467796133438 / fConst1) + 168.7940767291318) / fConst1) + 1.0);
		fConst299 = (1.0 / fConst298);
		fConst300 = (0.0 - (37988.587118453375 / (fConst8 * fConst298)));
		fConst301 = (0.0 - (((37988.587118453375 / fConst1) + 337.5881534582636) / (fConst1 * fConst298)));
		iConst302 = int(((0.00094984298003383924 * double(iConst0)) + 0.5));
		fConst303 = ((((105143.88595770916 / fConst1) + 621.26364328515456) / fConst1) + 1.0);
		fConst304 = (0.0 - (420575.54383083666 / (fConst8 * fConst303)));
		fConst305 = (0.0 - (((420575.54383083666 / fConst1) + 1242.5272865703091) / (fConst1 * fConst303)));
		fConst306 = ((((132150.40328687569 / fConst1) + 451.28205259787001) / fConst1) + 1.0);
		fConst307 = (1.0 / (fConst303 * fConst306));
		fConst308 = (0.0 - (528601.61314750277 / (fConst8 * fConst306)));
		fConst309 = (0.0 - (((528601.61314750277 / fConst1) + 902.56410519574001) / (fConst1 * fConst306)));
		fConst310 = ((249.06499071468039 / fConst1) + 1.0);
		fConst311 = (0.0 - (498.12998142936078 / (fConst1 * fConst310)));
		fConst312 = ((((74306.359791578565 / fConst1) + 394.46242681513445) / fConst1) + 1.0);
		fConst313 = (1.0 / (fConst310 * fConst312));
		fConst314 = (0.0 - (297225.43916631426 / (fConst8 * fConst312)));
		fConst315 = (0.0 - (((297225.43916631426 / fConst1) + 788.9248536302689) / (fConst1 * fConst312)));
		fConst316 = ((((34510.628092716055 / fConst1) + 321.76370876490739) / fConst1) + 1.0);
		fConst317 = (1.0 / fConst316);
		fConst318 = (0.0 - (138042.51237086422 / (fConst8 * fConst316)));
		fConst319 = (0.0 - (((138042.51237086422 / fConst1) + 643.52741752981478) / (fConst1 * fConst316)));
		fConst320 = ((107.25456958830247 / fConst1) + 1.0);
		fConst321 = (1.0 / fConst320);
		fConst322 = (0.0 - (214.50913917660495 / (fConst1 * fConst320)));
		fConst323 = ((391.12937844313967 / fConst1) + 1.0);
		fConst324 = (0.0 - (782.25875688627934 / (fConst1 * fConst323)));
		fConst325 = ((((164184.08898477611 / fConst1) + 719.02528173992607) / fConst1) + 1.0);
		fConst326 = (0.0 - (656736.35593910445 / (fConst8 * fConst325)));
		fConst327 = (0.0 - (((656736.35593910445 / fConst1) + 1438.0505634798521) / (fConst1 * fConst325)));
		fConst328 = ((((208861.94843887951 / fConst1) + 498.66388364147014) / fConst1) + 1.0);
		fConst329 = (1.0 / ((fConst323 * fConst325) * fConst328));
		fConst330 = (0.0 - (835447.79375551804 / (fConst8 * fConst328)));
		fConst331 = (0.0 - (((835447.79375551804 / fConst1) + 997.32776728294027) / (fConst1 * fConst328)));
		iConst332 = int(((0.0051746047010432453 * double(iConst0)) + 0.5));
		
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(400.0);
		fHslider1 = FAUSTFLOAT(0.0);
		fHslider2 = FAUSTFLOAT(-10.0);
		fCheckbox0 = FAUSTFLOAT(0.0);
		
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec16[l0] = 0.0;
			
		}
		for (int l1 = 0; (l1 < 3); l1 = (l1 + 1)) {
			fRec15[l1] = 0.0;
			
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec17[l2] = 0.0;
			
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec18[l3] = 0.0;
			
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec19[l4] = 0.0;
			
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec20[l5] = 0.0;
			
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec21[l6] = 0.0;
			
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec22[l7] = 0.0;
			
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec23[l8] = 0.0;
			
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec24[l9] = 0.0;
			
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec25[l10] = 0.0;
			
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec26[l11] = 0.0;
			
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec27[l12] = 0.0;
			
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec14[l13] = 0.0;
			
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec12[l14] = 0.0;
			
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec11[l15] = 0.0;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec9[l16] = 0.0;
			
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec8[l17] = 0.0;
			
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec6[l18] = 0.0;
			
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec5[l19] = 0.0;
			
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec3[l20] = 0.0;
			
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec2[l21] = 0.0;
			
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec0[l22] = 0.0;
			
		}
		for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) {
			fRec28[l23] = 0.0;
			
		}
		for (int l24 = 0; (l24 < 3); l24 = (l24 + 1)) {
			fRec41[l24] = 0.0;
			
		}
		for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) {
			fRec42[l25] = 0.0;
			
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec43[l26] = 0.0;
			
		}
		for (int l27 = 0; (l27 < 3); l27 = (l27 + 1)) {
			fRec44[l27] = 0.0;
			
		}
		for (int l28 = 0; (l28 < 3); l28 = (l28 + 1)) {
			fRec45[l28] = 0.0;
			
		}
		for (int l29 = 0; (l29 < 3); l29 = (l29 + 1)) {
			fRec46[l29] = 0.0;
			
		}
		for (int l30 = 0; (l30 < 3); l30 = (l30 + 1)) {
			fRec47[l30] = 0.0;
			
		}
		for (int l31 = 0; (l31 < 3); l31 = (l31 + 1)) {
			fRec48[l31] = 0.0;
			
		}
		for (int l32 = 0; (l32 < 3); l32 = (l32 + 1)) {
			fRec49[l32] = 0.0;
			
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec40[l33] = 0.0;
			
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec38[l34] = 0.0;
			
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec37[l35] = 0.0;
			
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec35[l36] = 0.0;
			
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec34[l37] = 0.0;
			
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec32[l38] = 0.0;
			
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec31[l39] = 0.0;
			
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec29[l40] = 0.0;
			
		}
		for (int l41 = 0; (l41 < 3); l41 = (l41 + 1)) {
			fRec59[l41] = 0.0;
			
		}
		for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) {
			fRec60[l42] = 0.0;
			
		}
		for (int l43 = 0; (l43 < 3); l43 = (l43 + 1)) {
			fRec61[l43] = 0.0;
			
		}
		for (int l44 = 0; (l44 < 3); l44 = (l44 + 1)) {
			fRec62[l44] = 0.0;
			
		}
		for (int l45 = 0; (l45 < 3); l45 = (l45 + 1)) {
			fRec63[l45] = 0.0;
			
		}
		for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) {
			fRec64[l46] = 0.0;
			
		}
		for (int l47 = 0; (l47 < 3); l47 = (l47 + 1)) {
			fRec65[l47] = 0.0;
			
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec58[l48] = 0.0;
			
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec56[l49] = 0.0;
			
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec55[l50] = 0.0;
			
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fRec53[l51] = 0.0;
			
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec52[l52] = 0.0;
			
		}
		for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
			fRec50[l53] = 0.0;
			
		}
		for (int l54 = 0; (l54 < 3); l54 = (l54 + 1)) {
			fRec69[l54] = 0.0;
			
		}
		for (int l55 = 0; (l55 < 3); l55 = (l55 + 1)) {
			fRec70[l55] = 0.0;
			
		}
		for (int l56 = 0; (l56 < 3); l56 = (l56 + 1)) {
			fRec71[l56] = 0.0;
			
		}
		for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
			fRec68[l57] = 0.0;
			
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fRec66[l58] = 0.0;
			
		}
		for (int l59 = 0; (l59 < 3); l59 = (l59 + 1)) {
			fRec78[l59] = 0.0;
			
		}
		for (int l60 = 0; (l60 < 3); l60 = (l60 + 1)) {
			fRec79[l60] = 0.0;
			
		}
		for (int l61 = 0; (l61 < 3); l61 = (l61 + 1)) {
			fRec80[l61] = 0.0;
			
		}
		for (int l62 = 0; (l62 < 3); l62 = (l62 + 1)) {
			fRec81[l62] = 0.0;
			
		}
		for (int l63 = 0; (l63 < 3); l63 = (l63 + 1)) {
			fRec82[l63] = 0.0;
			
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fRec77[l64] = 0.0;
			
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec75[l65] = 0.0;
			
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec74[l66] = 0.0;
			
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec72[l67] = 0.0;
			
		}
		IOTA = 0;
		for (int l68 = 0; (l68 < 128); l68 = (l68 + 1)) {
			fVec0[l68] = 0.0;
			
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fRec83[l69] = 0.0;
			
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec86[l70] = 0.0;
			
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec84[l71] = 0.0;
			
		}
		for (int l72 = 0; (l72 < 2); l72 = (l72 + 1)) {
			fRec92[l72] = 0.0;
			
		}
		for (int l73 = 0; (l73 < 2); l73 = (l73 + 1)) {
			fRec90[l73] = 0.0;
			
		}
		for (int l74 = 0; (l74 < 2); l74 = (l74 + 1)) {
			fRec89[l74] = 0.0;
			
		}
		for (int l75 = 0; (l75 < 2); l75 = (l75 + 1)) {
			fRec87[l75] = 0.0;
			
		}
		for (int l76 = 0; (l76 < 2); l76 = (l76 + 1)) {
			fRec101[l76] = 0.0;
			
		}
		for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) {
			fRec99[l77] = 0.0;
			
		}
		for (int l78 = 0; (l78 < 2); l78 = (l78 + 1)) {
			fRec98[l78] = 0.0;
			
		}
		for (int l79 = 0; (l79 < 2); l79 = (l79 + 1)) {
			fRec96[l79] = 0.0;
			
		}
		for (int l80 = 0; (l80 < 2); l80 = (l80 + 1)) {
			fRec95[l80] = 0.0;
			
		}
		for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) {
			fRec93[l81] = 0.0;
			
		}
		for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) {
			fRec113[l82] = 0.0;
			
		}
		for (int l83 = 0; (l83 < 2); l83 = (l83 + 1)) {
			fRec111[l83] = 0.0;
			
		}
		for (int l84 = 0; (l84 < 2); l84 = (l84 + 1)) {
			fRec110[l84] = 0.0;
			
		}
		for (int l85 = 0; (l85 < 2); l85 = (l85 + 1)) {
			fRec108[l85] = 0.0;
			
		}
		for (int l86 = 0; (l86 < 2); l86 = (l86 + 1)) {
			fRec107[l86] = 0.0;
			
		}
		for (int l87 = 0; (l87 < 2); l87 = (l87 + 1)) {
			fRec105[l87] = 0.0;
			
		}
		for (int l88 = 0; (l88 < 2); l88 = (l88 + 1)) {
			fRec104[l88] = 0.0;
			
		}
		for (int l89 = 0; (l89 < 2); l89 = (l89 + 1)) {
			fRec102[l89] = 0.0;
			
		}
		for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) {
			fRec128[l90] = 0.0;
			
		}
		for (int l91 = 0; (l91 < 2); l91 = (l91 + 1)) {
			fRec126[l91] = 0.0;
			
		}
		for (int l92 = 0; (l92 < 2); l92 = (l92 + 1)) {
			fRec125[l92] = 0.0;
			
		}
		for (int l93 = 0; (l93 < 2); l93 = (l93 + 1)) {
			fRec123[l93] = 0.0;
			
		}
		for (int l94 = 0; (l94 < 2); l94 = (l94 + 1)) {
			fRec122[l94] = 0.0;
			
		}
		for (int l95 = 0; (l95 < 2); l95 = (l95 + 1)) {
			fRec120[l95] = 0.0;
			
		}
		for (int l96 = 0; (l96 < 2); l96 = (l96 + 1)) {
			fRec119[l96] = 0.0;
			
		}
		for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) {
			fRec117[l97] = 0.0;
			
		}
		for (int l98 = 0; (l98 < 2); l98 = (l98 + 1)) {
			fRec116[l98] = 0.0;
			
		}
		for (int l99 = 0; (l99 < 2); l99 = (l99 + 1)) {
			fRec114[l99] = 0.0;
			
		}
		for (int l100 = 0; (l100 < 64); l100 = (l100 + 1)) {
			fVec1[l100] = 0.0;
			
		}
		for (int l101 = 0; (l101 < 2); l101 = (l101 + 1)) {
			fRec131[l101] = 0.0;
			
		}
		for (int l102 = 0; (l102 < 2); l102 = (l102 + 1)) {
			fRec129[l102] = 0.0;
			
		}
		for (int l103 = 0; (l103 < 2); l103 = (l103 + 1)) {
			fRec137[l103] = 0.0;
			
		}
		for (int l104 = 0; (l104 < 2); l104 = (l104 + 1)) {
			fRec135[l104] = 0.0;
			
		}
		for (int l105 = 0; (l105 < 2); l105 = (l105 + 1)) {
			fRec134[l105] = 0.0;
			
		}
		for (int l106 = 0; (l106 < 2); l106 = (l106 + 1)) {
			fRec132[l106] = 0.0;
			
		}
		for (int l107 = 0; (l107 < 2); l107 = (l107 + 1)) {
			fRec146[l107] = 0.0;
			
		}
		for (int l108 = 0; (l108 < 2); l108 = (l108 + 1)) {
			fRec144[l108] = 0.0;
			
		}
		for (int l109 = 0; (l109 < 2); l109 = (l109 + 1)) {
			fRec143[l109] = 0.0;
			
		}
		for (int l110 = 0; (l110 < 2); l110 = (l110 + 1)) {
			fRec141[l110] = 0.0;
			
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec140[l111] = 0.0;
			
		}
		for (int l112 = 0; (l112 < 2); l112 = (l112 + 1)) {
			fRec138[l112] = 0.0;
			
		}
		for (int l113 = 0; (l113 < 2); l113 = (l113 + 1)) {
			fRec158[l113] = 0.0;
			
		}
		for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) {
			fRec156[l114] = 0.0;
			
		}
		for (int l115 = 0; (l115 < 2); l115 = (l115 + 1)) {
			fRec155[l115] = 0.0;
			
		}
		for (int l116 = 0; (l116 < 2); l116 = (l116 + 1)) {
			fRec153[l116] = 0.0;
			
		}
		for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) {
			fRec152[l117] = 0.0;
			
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			fRec150[l118] = 0.0;
			
		}
		for (int l119 = 0; (l119 < 2); l119 = (l119 + 1)) {
			fRec149[l119] = 0.0;
			
		}
		for (int l120 = 0; (l120 < 2); l120 = (l120 + 1)) {
			fRec147[l120] = 0.0;
			
		}
		for (int l121 = 0; (l121 < 2); l121 = (l121 + 1)) {
			fRec173[l121] = 0.0;
			
		}
		for (int l122 = 0; (l122 < 2); l122 = (l122 + 1)) {
			fRec171[l122] = 0.0;
			
		}
		for (int l123 = 0; (l123 < 2); l123 = (l123 + 1)) {
			fRec170[l123] = 0.0;
			
		}
		for (int l124 = 0; (l124 < 2); l124 = (l124 + 1)) {
			fRec168[l124] = 0.0;
			
		}
		for (int l125 = 0; (l125 < 2); l125 = (l125 + 1)) {
			fRec167[l125] = 0.0;
			
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fRec165[l126] = 0.0;
			
		}
		for (int l127 = 0; (l127 < 2); l127 = (l127 + 1)) {
			fRec164[l127] = 0.0;
			
		}
		for (int l128 = 0; (l128 < 2); l128 = (l128 + 1)) {
			fRec162[l128] = 0.0;
			
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec161[l129] = 0.0;
			
		}
		for (int l130 = 0; (l130 < 2); l130 = (l130 + 1)) {
			fRec159[l130] = 0.0;
			
		}
		for (int l131 = 0; (l131 < 64); l131 = (l131 + 1)) {
			fVec2[l131] = 0.0;
			
		}
		for (int l132 = 0; (l132 < 2); l132 = (l132 + 1)) {
			fRec176[l132] = 0.0;
			
		}
		for (int l133 = 0; (l133 < 2); l133 = (l133 + 1)) {
			fRec174[l133] = 0.0;
			
		}
		for (int l134 = 0; (l134 < 2); l134 = (l134 + 1)) {
			fRec182[l134] = 0.0;
			
		}
		for (int l135 = 0; (l135 < 2); l135 = (l135 + 1)) {
			fRec180[l135] = 0.0;
			
		}
		for (int l136 = 0; (l136 < 2); l136 = (l136 + 1)) {
			fRec179[l136] = 0.0;
			
		}
		for (int l137 = 0; (l137 < 2); l137 = (l137 + 1)) {
			fRec177[l137] = 0.0;
			
		}
		for (int l138 = 0; (l138 < 2); l138 = (l138 + 1)) {
			fRec191[l138] = 0.0;
			
		}
		for (int l139 = 0; (l139 < 2); l139 = (l139 + 1)) {
			fRec189[l139] = 0.0;
			
		}
		for (int l140 = 0; (l140 < 2); l140 = (l140 + 1)) {
			fRec188[l140] = 0.0;
			
		}
		for (int l141 = 0; (l141 < 2); l141 = (l141 + 1)) {
			fRec186[l141] = 0.0;
			
		}
		for (int l142 = 0; (l142 < 2); l142 = (l142 + 1)) {
			fRec185[l142] = 0.0;
			
		}
		for (int l143 = 0; (l143 < 2); l143 = (l143 + 1)) {
			fRec183[l143] = 0.0;
			
		}
		for (int l144 = 0; (l144 < 2); l144 = (l144 + 1)) {
			fRec203[l144] = 0.0;
			
		}
		for (int l145 = 0; (l145 < 2); l145 = (l145 + 1)) {
			fRec201[l145] = 0.0;
			
		}
		for (int l146 = 0; (l146 < 2); l146 = (l146 + 1)) {
			fRec200[l146] = 0.0;
			
		}
		for (int l147 = 0; (l147 < 2); l147 = (l147 + 1)) {
			fRec198[l147] = 0.0;
			
		}
		for (int l148 = 0; (l148 < 2); l148 = (l148 + 1)) {
			fRec197[l148] = 0.0;
			
		}
		for (int l149 = 0; (l149 < 2); l149 = (l149 + 1)) {
			fRec195[l149] = 0.0;
			
		}
		for (int l150 = 0; (l150 < 2); l150 = (l150 + 1)) {
			fRec194[l150] = 0.0;
			
		}
		for (int l151 = 0; (l151 < 2); l151 = (l151 + 1)) {
			fRec192[l151] = 0.0;
			
		}
		for (int l152 = 0; (l152 < 2); l152 = (l152 + 1)) {
			fRec218[l152] = 0.0;
			
		}
		for (int l153 = 0; (l153 < 2); l153 = (l153 + 1)) {
			fRec216[l153] = 0.0;
			
		}
		for (int l154 = 0; (l154 < 2); l154 = (l154 + 1)) {
			fRec215[l154] = 0.0;
			
		}
		for (int l155 = 0; (l155 < 2); l155 = (l155 + 1)) {
			fRec213[l155] = 0.0;
			
		}
		for (int l156 = 0; (l156 < 2); l156 = (l156 + 1)) {
			fRec212[l156] = 0.0;
			
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec210[l157] = 0.0;
			
		}
		for (int l158 = 0; (l158 < 2); l158 = (l158 + 1)) {
			fRec209[l158] = 0.0;
			
		}
		for (int l159 = 0; (l159 < 2); l159 = (l159 + 1)) {
			fRec207[l159] = 0.0;
			
		}
		for (int l160 = 0; (l160 < 2); l160 = (l160 + 1)) {
			fRec206[l160] = 0.0;
			
		}
		for (int l161 = 0; (l161 < 2); l161 = (l161 + 1)) {
			fRec204[l161] = 0.0;
			
		}
		for (int l162 = 0; (l162 < 16); l162 = (l162 + 1)) {
			fVec3[l162] = 0.0;
			
		}
		for (int l163 = 0; (l163 < 2); l163 = (l163 + 1)) {
			fRec221[l163] = 0.0;
			
		}
		for (int l164 = 0; (l164 < 2); l164 = (l164 + 1)) {
			fRec219[l164] = 0.0;
			
		}
		for (int l165 = 0; (l165 < 2); l165 = (l165 + 1)) {
			fRec227[l165] = 0.0;
			
		}
		for (int l166 = 0; (l166 < 2); l166 = (l166 + 1)) {
			fRec225[l166] = 0.0;
			
		}
		for (int l167 = 0; (l167 < 2); l167 = (l167 + 1)) {
			fRec224[l167] = 0.0;
			
		}
		for (int l168 = 0; (l168 < 2); l168 = (l168 + 1)) {
			fRec222[l168] = 0.0;
			
		}
		for (int l169 = 0; (l169 < 2); l169 = (l169 + 1)) {
			fRec236[l169] = 0.0;
			
		}
		for (int l170 = 0; (l170 < 2); l170 = (l170 + 1)) {
			fRec234[l170] = 0.0;
			
		}
		for (int l171 = 0; (l171 < 2); l171 = (l171 + 1)) {
			fRec233[l171] = 0.0;
			
		}
		for (int l172 = 0; (l172 < 2); l172 = (l172 + 1)) {
			fRec231[l172] = 0.0;
			
		}
		for (int l173 = 0; (l173 < 2); l173 = (l173 + 1)) {
			fRec230[l173] = 0.0;
			
		}
		for (int l174 = 0; (l174 < 2); l174 = (l174 + 1)) {
			fRec228[l174] = 0.0;
			
		}
		for (int l175 = 0; (l175 < 2); l175 = (l175 + 1)) {
			fRec248[l175] = 0.0;
			
		}
		for (int l176 = 0; (l176 < 2); l176 = (l176 + 1)) {
			fRec246[l176] = 0.0;
			
		}
		for (int l177 = 0; (l177 < 2); l177 = (l177 + 1)) {
			fRec245[l177] = 0.0;
			
		}
		for (int l178 = 0; (l178 < 2); l178 = (l178 + 1)) {
			fRec243[l178] = 0.0;
			
		}
		for (int l179 = 0; (l179 < 2); l179 = (l179 + 1)) {
			fRec242[l179] = 0.0;
			
		}
		for (int l180 = 0; (l180 < 2); l180 = (l180 + 1)) {
			fRec240[l180] = 0.0;
			
		}
		for (int l181 = 0; (l181 < 2); l181 = (l181 + 1)) {
			fRec239[l181] = 0.0;
			
		}
		for (int l182 = 0; (l182 < 2); l182 = (l182 + 1)) {
			fRec237[l182] = 0.0;
			
		}
		for (int l183 = 0; (l183 < 2); l183 = (l183 + 1)) {
			fRec263[l183] = 0.0;
			
		}
		for (int l184 = 0; (l184 < 2); l184 = (l184 + 1)) {
			fRec261[l184] = 0.0;
			
		}
		for (int l185 = 0; (l185 < 2); l185 = (l185 + 1)) {
			fRec260[l185] = 0.0;
			
		}
		for (int l186 = 0; (l186 < 2); l186 = (l186 + 1)) {
			fRec258[l186] = 0.0;
			
		}
		for (int l187 = 0; (l187 < 2); l187 = (l187 + 1)) {
			fRec257[l187] = 0.0;
			
		}
		for (int l188 = 0; (l188 < 2); l188 = (l188 + 1)) {
			fRec255[l188] = 0.0;
			
		}
		for (int l189 = 0; (l189 < 2); l189 = (l189 + 1)) {
			fRec254[l189] = 0.0;
			
		}
		for (int l190 = 0; (l190 < 2); l190 = (l190 + 1)) {
			fRec252[l190] = 0.0;
			
		}
		for (int l191 = 0; (l191 < 2); l191 = (l191 + 1)) {
			fRec251[l191] = 0.0;
			
		}
		for (int l192 = 0; (l192 < 2); l192 = (l192 + 1)) {
			fRec249[l192] = 0.0;
			
		}
		for (int l193 = 0; (l193 < 64); l193 = (l193 + 1)) {
			fVec4[l193] = 0.0;
			
		}
		for (int l194 = 0; (l194 < 2); l194 = (l194 + 1)) {
			fRec278[l194] = 0.0;
			
		}
		for (int l195 = 0; (l195 < 2); l195 = (l195 + 1)) {
			fRec276[l195] = 0.0;
			
		}
		for (int l196 = 0; (l196 < 2); l196 = (l196 + 1)) {
			fRec275[l196] = 0.0;
			
		}
		for (int l197 = 0; (l197 < 2); l197 = (l197 + 1)) {
			fRec273[l197] = 0.0;
			
		}
		for (int l198 = 0; (l198 < 2); l198 = (l198 + 1)) {
			fRec272[l198] = 0.0;
			
		}
		for (int l199 = 0; (l199 < 2); l199 = (l199 + 1)) {
			fRec270[l199] = 0.0;
			
		}
		for (int l200 = 0; (l200 < 2); l200 = (l200 + 1)) {
			fRec269[l200] = 0.0;
			
		}
		for (int l201 = 0; (l201 < 2); l201 = (l201 + 1)) {
			fRec267[l201] = 0.0;
			
		}
		for (int l202 = 0; (l202 < 2); l202 = (l202 + 1)) {
			fRec266[l202] = 0.0;
			
		}
		for (int l203 = 0; (l203 < 2); l203 = (l203 + 1)) {
			fRec264[l203] = 0.0;
			
		}
		for (int l204 = 0; (l204 < 2); l204 = (l204 + 1)) {
			fRec281[l204] = 0.0;
			
		}
		for (int l205 = 0; (l205 < 2); l205 = (l205 + 1)) {
			fRec279[l205] = 0.0;
			
		}
		for (int l206 = 0; (l206 < 2); l206 = (l206 + 1)) {
			fRec287[l206] = 0.0;
			
		}
		for (int l207 = 0; (l207 < 2); l207 = (l207 + 1)) {
			fRec285[l207] = 0.0;
			
		}
		for (int l208 = 0; (l208 < 2); l208 = (l208 + 1)) {
			fRec284[l208] = 0.0;
			
		}
		for (int l209 = 0; (l209 < 2); l209 = (l209 + 1)) {
			fRec282[l209] = 0.0;
			
		}
		for (int l210 = 0; (l210 < 2); l210 = (l210 + 1)) {
			fRec296[l210] = 0.0;
			
		}
		for (int l211 = 0; (l211 < 2); l211 = (l211 + 1)) {
			fRec294[l211] = 0.0;
			
		}
		for (int l212 = 0; (l212 < 2); l212 = (l212 + 1)) {
			fRec293[l212] = 0.0;
			
		}
		for (int l213 = 0; (l213 < 2); l213 = (l213 + 1)) {
			fRec291[l213] = 0.0;
			
		}
		for (int l214 = 0; (l214 < 2); l214 = (l214 + 1)) {
			fRec290[l214] = 0.0;
			
		}
		for (int l215 = 0; (l215 < 2); l215 = (l215 + 1)) {
			fRec288[l215] = 0.0;
			
		}
		for (int l216 = 0; (l216 < 2); l216 = (l216 + 1)) {
			fRec308[l216] = 0.0;
			
		}
		for (int l217 = 0; (l217 < 2); l217 = (l217 + 1)) {
			fRec306[l217] = 0.0;
			
		}
		for (int l218 = 0; (l218 < 2); l218 = (l218 + 1)) {
			fRec305[l218] = 0.0;
			
		}
		for (int l219 = 0; (l219 < 2); l219 = (l219 + 1)) {
			fRec303[l219] = 0.0;
			
		}
		for (int l220 = 0; (l220 < 2); l220 = (l220 + 1)) {
			fRec302[l220] = 0.0;
			
		}
		for (int l221 = 0; (l221 < 2); l221 = (l221 + 1)) {
			fRec300[l221] = 0.0;
			
		}
		for (int l222 = 0; (l222 < 2); l222 = (l222 + 1)) {
			fRec299[l222] = 0.0;
			
		}
		for (int l223 = 0; (l223 < 2); l223 = (l223 + 1)) {
			fRec297[l223] = 0.0;
			
		}
		for (int l224 = 0; (l224 < 8); l224 = (l224 + 1)) {
			fVec5[l224] = 0.0;
			
		}
		for (int l225 = 0; (l225 < 2); l225 = (l225 + 1)) {
			fRec323[l225] = 0.0;
			
		}
		for (int l226 = 0; (l226 < 2); l226 = (l226 + 1)) {
			fRec321[l226] = 0.0;
			
		}
		for (int l227 = 0; (l227 < 2); l227 = (l227 + 1)) {
			fRec320[l227] = 0.0;
			
		}
		for (int l228 = 0; (l228 < 2); l228 = (l228 + 1)) {
			fRec318[l228] = 0.0;
			
		}
		for (int l229 = 0; (l229 < 2); l229 = (l229 + 1)) {
			fRec317[l229] = 0.0;
			
		}
		for (int l230 = 0; (l230 < 2); l230 = (l230 + 1)) {
			fRec315[l230] = 0.0;
			
		}
		for (int l231 = 0; (l231 < 2); l231 = (l231 + 1)) {
			fRec314[l231] = 0.0;
			
		}
		for (int l232 = 0; (l232 < 2); l232 = (l232 + 1)) {
			fRec312[l232] = 0.0;
			
		}
		for (int l233 = 0; (l233 < 2); l233 = (l233 + 1)) {
			fRec311[l233] = 0.0;
			
		}
		for (int l234 = 0; (l234 < 2); l234 = (l234 + 1)) {
			fRec309[l234] = 0.0;
			
		}
		for (int l235 = 0; (l235 < 2); l235 = (l235 + 1)) {
			fRec335[l235] = 0.0;
			
		}
		for (int l236 = 0; (l236 < 2); l236 = (l236 + 1)) {
			fRec333[l236] = 0.0;
			
		}
		for (int l237 = 0; (l237 < 2); l237 = (l237 + 1)) {
			fRec332[l237] = 0.0;
			
		}
		for (int l238 = 0; (l238 < 2); l238 = (l238 + 1)) {
			fRec330[l238] = 0.0;
			
		}
		for (int l239 = 0; (l239 < 2); l239 = (l239 + 1)) {
			fRec329[l239] = 0.0;
			
		}
		for (int l240 = 0; (l240 < 2); l240 = (l240 + 1)) {
			fRec327[l240] = 0.0;
			
		}
		for (int l241 = 0; (l241 < 2); l241 = (l241 + 1)) {
			fRec326[l241] = 0.0;
			
		}
		for (int l242 = 0; (l242 < 2); l242 = (l242 + 1)) {
			fRec324[l242] = 0.0;
			
		}
		for (int l243 = 0; (l243 < 2); l243 = (l243 + 1)) {
			fRec344[l243] = 0.0;
			
		}
		for (int l244 = 0; (l244 < 2); l244 = (l244 + 1)) {
			fRec342[l244] = 0.0;
			
		}
		for (int l245 = 0; (l245 < 2); l245 = (l245 + 1)) {
			fRec341[l245] = 0.0;
			
		}
		for (int l246 = 0; (l246 < 2); l246 = (l246 + 1)) {
			fRec339[l246] = 0.0;
			
		}
		for (int l247 = 0; (l247 < 2); l247 = (l247 + 1)) {
			fRec338[l247] = 0.0;
			
		}
		for (int l248 = 0; (l248 < 2); l248 = (l248 + 1)) {
			fRec336[l248] = 0.0;
			
		}
		for (int l249 = 0; (l249 < 2); l249 = (l249 + 1)) {
			fRec350[l249] = 0.0;
			
		}
		for (int l250 = 0; (l250 < 2); l250 = (l250 + 1)) {
			fRec348[l250] = 0.0;
			
		}
		for (int l251 = 0; (l251 < 2); l251 = (l251 + 1)) {
			fRec347[l251] = 0.0;
			
		}
		for (int l252 = 0; (l252 < 2); l252 = (l252 + 1)) {
			fRec345[l252] = 0.0;
			
		}
		for (int l253 = 0; (l253 < 2); l253 = (l253 + 1)) {
			fRec353[l253] = 0.0;
			
		}
		for (int l254 = 0; (l254 < 2); l254 = (l254 + 1)) {
			fRec351[l254] = 0.0;
			
		}
		for (int l255 = 0; (l255 < 2); l255 = (l255 + 1)) {
			fRec356[l255] = 0.0;
			
		}
		for (int l256 = 0; (l256 < 2); l256 = (l256 + 1)) {
			fRec354[l256] = 0.0;
			
		}
		for (int l257 = 0; (l257 < 2); l257 = (l257 + 1)) {
			fRec371[l257] = 0.0;
			
		}
		for (int l258 = 0; (l258 < 2); l258 = (l258 + 1)) {
			fRec369[l258] = 0.0;
			
		}
		for (int l259 = 0; (l259 < 2); l259 = (l259 + 1)) {
			fRec368[l259] = 0.0;
			
		}
		for (int l260 = 0; (l260 < 2); l260 = (l260 + 1)) {
			fRec366[l260] = 0.0;
			
		}
		for (int l261 = 0; (l261 < 2); l261 = (l261 + 1)) {
			fRec365[l261] = 0.0;
			
		}
		for (int l262 = 0; (l262 < 2); l262 = (l262 + 1)) {
			fRec363[l262] = 0.0;
			
		}
		for (int l263 = 0; (l263 < 2); l263 = (l263 + 1)) {
			fRec362[l263] = 0.0;
			
		}
		for (int l264 = 0; (l264 < 2); l264 = (l264 + 1)) {
			fRec360[l264] = 0.0;
			
		}
		for (int l265 = 0; (l265 < 2); l265 = (l265 + 1)) {
			fRec359[l265] = 0.0;
			
		}
		for (int l266 = 0; (l266 < 2); l266 = (l266 + 1)) {
			fRec357[l266] = 0.0;
			
		}
		for (int l267 = 0; (l267 < 2); l267 = (l267 + 1)) {
			fRec383[l267] = 0.0;
			
		}
		for (int l268 = 0; (l268 < 2); l268 = (l268 + 1)) {
			fRec381[l268] = 0.0;
			
		}
		for (int l269 = 0; (l269 < 2); l269 = (l269 + 1)) {
			fRec380[l269] = 0.0;
			
		}
		for (int l270 = 0; (l270 < 2); l270 = (l270 + 1)) {
			fRec378[l270] = 0.0;
			
		}
		for (int l271 = 0; (l271 < 2); l271 = (l271 + 1)) {
			fRec377[l271] = 0.0;
			
		}
		for (int l272 = 0; (l272 < 2); l272 = (l272 + 1)) {
			fRec375[l272] = 0.0;
			
		}
		for (int l273 = 0; (l273 < 2); l273 = (l273 + 1)) {
			fRec374[l273] = 0.0;
			
		}
		for (int l274 = 0; (l274 < 2); l274 = (l274 + 1)) {
			fRec372[l274] = 0.0;
			
		}
		for (int l275 = 0; (l275 < 2); l275 = (l275 + 1)) {
			fRec389[l275] = 0.0;
			
		}
		for (int l276 = 0; (l276 < 2); l276 = (l276 + 1)) {
			fRec387[l276] = 0.0;
			
		}
		for (int l277 = 0; (l277 < 2); l277 = (l277 + 1)) {
			fRec386[l277] = 0.0;
			
		}
		for (int l278 = 0; (l278 < 2); l278 = (l278 + 1)) {
			fRec384[l278] = 0.0;
			
		}
		for (int l279 = 0; (l279 < 2); l279 = (l279 + 1)) {
			fRec398[l279] = 0.0;
			
		}
		for (int l280 = 0; (l280 < 2); l280 = (l280 + 1)) {
			fRec396[l280] = 0.0;
			
		}
		for (int l281 = 0; (l281 < 2); l281 = (l281 + 1)) {
			fRec395[l281] = 0.0;
			
		}
		for (int l282 = 0; (l282 < 2); l282 = (l282 + 1)) {
			fRec393[l282] = 0.0;
			
		}
		for (int l283 = 0; (l283 < 2); l283 = (l283 + 1)) {
			fRec392[l283] = 0.0;
			
		}
		for (int l284 = 0; (l284 < 2); l284 = (l284 + 1)) {
			fRec390[l284] = 0.0;
			
		}
		for (int l285 = 0; (l285 < 128); l285 = (l285 + 1)) {
			fVec6[l285] = 0.0;
			
		}
		for (int l286 = 0; (l286 < 2); l286 = (l286 + 1)) {
			fRec413[l286] = 0.0;
			
		}
		for (int l287 = 0; (l287 < 2); l287 = (l287 + 1)) {
			fRec411[l287] = 0.0;
			
		}
		for (int l288 = 0; (l288 < 2); l288 = (l288 + 1)) {
			fRec410[l288] = 0.0;
			
		}
		for (int l289 = 0; (l289 < 2); l289 = (l289 + 1)) {
			fRec408[l289] = 0.0;
			
		}
		for (int l290 = 0; (l290 < 2); l290 = (l290 + 1)) {
			fRec407[l290] = 0.0;
			
		}
		for (int l291 = 0; (l291 < 2); l291 = (l291 + 1)) {
			fRec405[l291] = 0.0;
			
		}
		for (int l292 = 0; (l292 < 2); l292 = (l292 + 1)) {
			fRec404[l292] = 0.0;
			
		}
		for (int l293 = 0; (l293 < 2); l293 = (l293 + 1)) {
			fRec402[l293] = 0.0;
			
		}
		for (int l294 = 0; (l294 < 2); l294 = (l294 + 1)) {
			fRec401[l294] = 0.0;
			
		}
		for (int l295 = 0; (l295 < 2); l295 = (l295 + 1)) {
			fRec399[l295] = 0.0;
			
		}
		for (int l296 = 0; (l296 < 2); l296 = (l296 + 1)) {
			fRec425[l296] = 0.0;
			
		}
		for (int l297 = 0; (l297 < 2); l297 = (l297 + 1)) {
			fRec423[l297] = 0.0;
			
		}
		for (int l298 = 0; (l298 < 2); l298 = (l298 + 1)) {
			fRec422[l298] = 0.0;
			
		}
		for (int l299 = 0; (l299 < 2); l299 = (l299 + 1)) {
			fRec420[l299] = 0.0;
			
		}
		for (int l300 = 0; (l300 < 2); l300 = (l300 + 1)) {
			fRec419[l300] = 0.0;
			
		}
		for (int l301 = 0; (l301 < 2); l301 = (l301 + 1)) {
			fRec417[l301] = 0.0;
			
		}
		for (int l302 = 0; (l302 < 2); l302 = (l302 + 1)) {
			fRec416[l302] = 0.0;
			
		}
		for (int l303 = 0; (l303 < 2); l303 = (l303 + 1)) {
			fRec414[l303] = 0.0;
			
		}
		for (int l304 = 0; (l304 < 2); l304 = (l304 + 1)) {
			fRec434[l304] = 0.0;
			
		}
		for (int l305 = 0; (l305 < 2); l305 = (l305 + 1)) {
			fRec432[l305] = 0.0;
			
		}
		for (int l306 = 0; (l306 < 2); l306 = (l306 + 1)) {
			fRec431[l306] = 0.0;
			
		}
		for (int l307 = 0; (l307 < 2); l307 = (l307 + 1)) {
			fRec429[l307] = 0.0;
			
		}
		for (int l308 = 0; (l308 < 2); l308 = (l308 + 1)) {
			fRec428[l308] = 0.0;
			
		}
		for (int l309 = 0; (l309 < 2); l309 = (l309 + 1)) {
			fRec426[l309] = 0.0;
			
		}
		for (int l310 = 0; (l310 < 2); l310 = (l310 + 1)) {
			fRec437[l310] = 0.0;
			
		}
		for (int l311 = 0; (l311 < 2); l311 = (l311 + 1)) {
			fRec435[l311] = 0.0;
			
		}
		for (int l312 = 0; (l312 < 2); l312 = (l312 + 1)) {
			fRec443[l312] = 0.0;
			
		}
		for (int l313 = 0; (l313 < 2); l313 = (l313 + 1)) {
			fRec441[l313] = 0.0;
			
		}
		for (int l314 = 0; (l314 < 2); l314 = (l314 + 1)) {
			fRec440[l314] = 0.0;
			
		}
		for (int l315 = 0; (l315 < 2); l315 = (l315 + 1)) {
			fRec438[l315] = 0.0;
			
		}
		for (int l316 = 0; (l316 < 64); l316 = (l316 + 1)) {
			fVec7[l316] = 0.0;
			
		}
		for (int l317 = 0; (l317 < 2); l317 = (l317 + 1)) {
			fRec458[l317] = 0.0;
			
		}
		for (int l318 = 0; (l318 < 2); l318 = (l318 + 1)) {
			fRec456[l318] = 0.0;
			
		}
		for (int l319 = 0; (l319 < 2); l319 = (l319 + 1)) {
			fRec455[l319] = 0.0;
			
		}
		for (int l320 = 0; (l320 < 2); l320 = (l320 + 1)) {
			fRec453[l320] = 0.0;
			
		}
		for (int l321 = 0; (l321 < 2); l321 = (l321 + 1)) {
			fRec452[l321] = 0.0;
			
		}
		for (int l322 = 0; (l322 < 2); l322 = (l322 + 1)) {
			fRec450[l322] = 0.0;
			
		}
		for (int l323 = 0; (l323 < 2); l323 = (l323 + 1)) {
			fRec449[l323] = 0.0;
			
		}
		for (int l324 = 0; (l324 < 2); l324 = (l324 + 1)) {
			fRec447[l324] = 0.0;
			
		}
		for (int l325 = 0; (l325 < 2); l325 = (l325 + 1)) {
			fRec446[l325] = 0.0;
			
		}
		for (int l326 = 0; (l326 < 2); l326 = (l326 + 1)) {
			fRec444[l326] = 0.0;
			
		}
		for (int l327 = 0; (l327 < 2); l327 = (l327 + 1)) {
			fRec470[l327] = 0.0;
			
		}
		for (int l328 = 0; (l328 < 2); l328 = (l328 + 1)) {
			fRec468[l328] = 0.0;
			
		}
		for (int l329 = 0; (l329 < 2); l329 = (l329 + 1)) {
			fRec467[l329] = 0.0;
			
		}
		for (int l330 = 0; (l330 < 2); l330 = (l330 + 1)) {
			fRec465[l330] = 0.0;
			
		}
		for (int l331 = 0; (l331 < 2); l331 = (l331 + 1)) {
			fRec464[l331] = 0.0;
			
		}
		for (int l332 = 0; (l332 < 2); l332 = (l332 + 1)) {
			fRec462[l332] = 0.0;
			
		}
		for (int l333 = 0; (l333 < 2); l333 = (l333 + 1)) {
			fRec461[l333] = 0.0;
			
		}
		for (int l334 = 0; (l334 < 2); l334 = (l334 + 1)) {
			fRec459[l334] = 0.0;
			
		}
		for (int l335 = 0; (l335 < 2); l335 = (l335 + 1)) {
			fRec479[l335] = 0.0;
			
		}
		for (int l336 = 0; (l336 < 2); l336 = (l336 + 1)) {
			fRec477[l336] = 0.0;
			
		}
		for (int l337 = 0; (l337 < 2); l337 = (l337 + 1)) {
			fRec476[l337] = 0.0;
			
		}
		for (int l338 = 0; (l338 < 2); l338 = (l338 + 1)) {
			fRec474[l338] = 0.0;
			
		}
		for (int l339 = 0; (l339 < 2); l339 = (l339 + 1)) {
			fRec473[l339] = 0.0;
			
		}
		for (int l340 = 0; (l340 < 2); l340 = (l340 + 1)) {
			fRec471[l340] = 0.0;
			
		}
		for (int l341 = 0; (l341 < 2); l341 = (l341 + 1)) {
			fRec482[l341] = 0.0;
			
		}
		for (int l342 = 0; (l342 < 2); l342 = (l342 + 1)) {
			fRec480[l342] = 0.0;
			
		}
		for (int l343 = 0; (l343 < 2); l343 = (l343 + 1)) {
			fRec488[l343] = 0.0;
			
		}
		for (int l344 = 0; (l344 < 2); l344 = (l344 + 1)) {
			fRec486[l344] = 0.0;
			
		}
		for (int l345 = 0; (l345 < 2); l345 = (l345 + 1)) {
			fRec485[l345] = 0.0;
			
		}
		for (int l346 = 0; (l346 < 2); l346 = (l346 + 1)) {
			fRec483[l346] = 0.0;
			
		}
		for (int l347 = 0; (l347 < 256); l347 = (l347 + 1)) {
			fVec8[l347] = 0.0;
			
		}
		for (int l348 = 0; (l348 < 2); l348 = (l348 + 1)) {
			fRec503[l348] = 0.0;
			
		}
		for (int l349 = 0; (l349 < 2); l349 = (l349 + 1)) {
			fRec501[l349] = 0.0;
			
		}
		for (int l350 = 0; (l350 < 2); l350 = (l350 + 1)) {
			fRec500[l350] = 0.0;
			
		}
		for (int l351 = 0; (l351 < 2); l351 = (l351 + 1)) {
			fRec498[l351] = 0.0;
			
		}
		for (int l352 = 0; (l352 < 2); l352 = (l352 + 1)) {
			fRec497[l352] = 0.0;
			
		}
		for (int l353 = 0; (l353 < 2); l353 = (l353 + 1)) {
			fRec495[l353] = 0.0;
			
		}
		for (int l354 = 0; (l354 < 2); l354 = (l354 + 1)) {
			fRec494[l354] = 0.0;
			
		}
		for (int l355 = 0; (l355 < 2); l355 = (l355 + 1)) {
			fRec492[l355] = 0.0;
			
		}
		for (int l356 = 0; (l356 < 2); l356 = (l356 + 1)) {
			fRec491[l356] = 0.0;
			
		}
		for (int l357 = 0; (l357 < 2); l357 = (l357 + 1)) {
			fRec489[l357] = 0.0;
			
		}
		for (int l358 = 0; (l358 < 2); l358 = (l358 + 1)) {
			fRec515[l358] = 0.0;
			
		}
		for (int l359 = 0; (l359 < 2); l359 = (l359 + 1)) {
			fRec513[l359] = 0.0;
			
		}
		for (int l360 = 0; (l360 < 2); l360 = (l360 + 1)) {
			fRec512[l360] = 0.0;
			
		}
		for (int l361 = 0; (l361 < 2); l361 = (l361 + 1)) {
			fRec510[l361] = 0.0;
			
		}
		for (int l362 = 0; (l362 < 2); l362 = (l362 + 1)) {
			fRec509[l362] = 0.0;
			
		}
		for (int l363 = 0; (l363 < 2); l363 = (l363 + 1)) {
			fRec507[l363] = 0.0;
			
		}
		for (int l364 = 0; (l364 < 2); l364 = (l364 + 1)) {
			fRec506[l364] = 0.0;
			
		}
		for (int l365 = 0; (l365 < 2); l365 = (l365 + 1)) {
			fRec504[l365] = 0.0;
			
		}
		for (int l366 = 0; (l366 < 2); l366 = (l366 + 1)) {
			fRec524[l366] = 0.0;
			
		}
		for (int l367 = 0; (l367 < 2); l367 = (l367 + 1)) {
			fRec522[l367] = 0.0;
			
		}
		for (int l368 = 0; (l368 < 2); l368 = (l368 + 1)) {
			fRec521[l368] = 0.0;
			
		}
		for (int l369 = 0; (l369 < 2); l369 = (l369 + 1)) {
			fRec519[l369] = 0.0;
			
		}
		for (int l370 = 0; (l370 < 2); l370 = (l370 + 1)) {
			fRec518[l370] = 0.0;
			
		}
		for (int l371 = 0; (l371 < 2); l371 = (l371 + 1)) {
			fRec516[l371] = 0.0;
			
		}
		for (int l372 = 0; (l372 < 2); l372 = (l372 + 1)) {
			fRec527[l372] = 0.0;
			
		}
		for (int l373 = 0; (l373 < 2); l373 = (l373 + 1)) {
			fRec525[l373] = 0.0;
			
		}
		for (int l374 = 0; (l374 < 2); l374 = (l374 + 1)) {
			fRec533[l374] = 0.0;
			
		}
		for (int l375 = 0; (l375 < 2); l375 = (l375 + 1)) {
			fRec531[l375] = 0.0;
			
		}
		for (int l376 = 0; (l376 < 2); l376 = (l376 + 1)) {
			fRec530[l376] = 0.0;
			
		}
		for (int l377 = 0; (l377 < 2); l377 = (l377 + 1)) {
			fRec528[l377] = 0.0;
			
		}
		for (int l378 = 0; (l378 < 256); l378 = (l378 + 1)) {
			fVec9[l378] = 0.0;
			
		}
		for (int l379 = 0; (l379 < 2); l379 = (l379 + 1)) {
			fRec548[l379] = 0.0;
			
		}
		for (int l380 = 0; (l380 < 2); l380 = (l380 + 1)) {
			fRec546[l380] = 0.0;
			
		}
		for (int l381 = 0; (l381 < 2); l381 = (l381 + 1)) {
			fRec545[l381] = 0.0;
			
		}
		for (int l382 = 0; (l382 < 2); l382 = (l382 + 1)) {
			fRec543[l382] = 0.0;
			
		}
		for (int l383 = 0; (l383 < 2); l383 = (l383 + 1)) {
			fRec542[l383] = 0.0;
			
		}
		for (int l384 = 0; (l384 < 2); l384 = (l384 + 1)) {
			fRec540[l384] = 0.0;
			
		}
		for (int l385 = 0; (l385 < 2); l385 = (l385 + 1)) {
			fRec539[l385] = 0.0;
			
		}
		for (int l386 = 0; (l386 < 2); l386 = (l386 + 1)) {
			fRec537[l386] = 0.0;
			
		}
		for (int l387 = 0; (l387 < 2); l387 = (l387 + 1)) {
			fRec536[l387] = 0.0;
			
		}
		for (int l388 = 0; (l388 < 2); l388 = (l388 + 1)) {
			fRec534[l388] = 0.0;
			
		}
		for (int l389 = 0; (l389 < 2); l389 = (l389 + 1)) {
			fRec560[l389] = 0.0;
			
		}
		for (int l390 = 0; (l390 < 2); l390 = (l390 + 1)) {
			fRec558[l390] = 0.0;
			
		}
		for (int l391 = 0; (l391 < 2); l391 = (l391 + 1)) {
			fRec557[l391] = 0.0;
			
		}
		for (int l392 = 0; (l392 < 2); l392 = (l392 + 1)) {
			fRec555[l392] = 0.0;
			
		}
		for (int l393 = 0; (l393 < 2); l393 = (l393 + 1)) {
			fRec554[l393] = 0.0;
			
		}
		for (int l394 = 0; (l394 < 2); l394 = (l394 + 1)) {
			fRec552[l394] = 0.0;
			
		}
		for (int l395 = 0; (l395 < 2); l395 = (l395 + 1)) {
			fRec551[l395] = 0.0;
			
		}
		for (int l396 = 0; (l396 < 2); l396 = (l396 + 1)) {
			fRec549[l396] = 0.0;
			
		}
		for (int l397 = 0; (l397 < 2); l397 = (l397 + 1)) {
			fRec569[l397] = 0.0;
			
		}
		for (int l398 = 0; (l398 < 2); l398 = (l398 + 1)) {
			fRec567[l398] = 0.0;
			
		}
		for (int l399 = 0; (l399 < 2); l399 = (l399 + 1)) {
			fRec566[l399] = 0.0;
			
		}
		for (int l400 = 0; (l400 < 2); l400 = (l400 + 1)) {
			fRec564[l400] = 0.0;
			
		}
		for (int l401 = 0; (l401 < 2); l401 = (l401 + 1)) {
			fRec563[l401] = 0.0;
			
		}
		for (int l402 = 0; (l402 < 2); l402 = (l402 + 1)) {
			fRec561[l402] = 0.0;
			
		}
		for (int l403 = 0; (l403 < 2); l403 = (l403 + 1)) {
			fRec572[l403] = 0.0;
			
		}
		for (int l404 = 0; (l404 < 2); l404 = (l404 + 1)) {
			fRec570[l404] = 0.0;
			
		}
		for (int l405 = 0; (l405 < 2); l405 = (l405 + 1)) {
			fRec578[l405] = 0.0;
			
		}
		for (int l406 = 0; (l406 < 2); l406 = (l406 + 1)) {
			fRec576[l406] = 0.0;
			
		}
		for (int l407 = 0; (l407 < 2); l407 = (l407 + 1)) {
			fRec575[l407] = 0.0;
			
		}
		for (int l408 = 0; (l408 < 2); l408 = (l408 + 1)) {
			fRec573[l408] = 0.0;
			
		}
		for (int l409 = 0; (l409 < 256); l409 = (l409 + 1)) {
			fVec10[l409] = 0.0;
			
		}
		for (int l410 = 0; (l410 < 2); l410 = (l410 + 1)) {
			fRec593[l410] = 0.0;
			
		}
		for (int l411 = 0; (l411 < 2); l411 = (l411 + 1)) {
			fRec591[l411] = 0.0;
			
		}
		for (int l412 = 0; (l412 < 2); l412 = (l412 + 1)) {
			fRec590[l412] = 0.0;
			
		}
		for (int l413 = 0; (l413 < 2); l413 = (l413 + 1)) {
			fRec588[l413] = 0.0;
			
		}
		for (int l414 = 0; (l414 < 2); l414 = (l414 + 1)) {
			fRec587[l414] = 0.0;
			
		}
		for (int l415 = 0; (l415 < 2); l415 = (l415 + 1)) {
			fRec585[l415] = 0.0;
			
		}
		for (int l416 = 0; (l416 < 2); l416 = (l416 + 1)) {
			fRec584[l416] = 0.0;
			
		}
		for (int l417 = 0; (l417 < 2); l417 = (l417 + 1)) {
			fRec582[l417] = 0.0;
			
		}
		for (int l418 = 0; (l418 < 2); l418 = (l418 + 1)) {
			fRec581[l418] = 0.0;
			
		}
		for (int l419 = 0; (l419 < 2); l419 = (l419 + 1)) {
			fRec579[l419] = 0.0;
			
		}
		for (int l420 = 0; (l420 < 2); l420 = (l420 + 1)) {
			fRec605[l420] = 0.0;
			
		}
		for (int l421 = 0; (l421 < 2); l421 = (l421 + 1)) {
			fRec603[l421] = 0.0;
			
		}
		for (int l422 = 0; (l422 < 2); l422 = (l422 + 1)) {
			fRec602[l422] = 0.0;
			
		}
		for (int l423 = 0; (l423 < 2); l423 = (l423 + 1)) {
			fRec600[l423] = 0.0;
			
		}
		for (int l424 = 0; (l424 < 2); l424 = (l424 + 1)) {
			fRec599[l424] = 0.0;
			
		}
		for (int l425 = 0; (l425 < 2); l425 = (l425 + 1)) {
			fRec597[l425] = 0.0;
			
		}
		for (int l426 = 0; (l426 < 2); l426 = (l426 + 1)) {
			fRec596[l426] = 0.0;
			
		}
		for (int l427 = 0; (l427 < 2); l427 = (l427 + 1)) {
			fRec594[l427] = 0.0;
			
		}
		for (int l428 = 0; (l428 < 2); l428 = (l428 + 1)) {
			fRec614[l428] = 0.0;
			
		}
		for (int l429 = 0; (l429 < 2); l429 = (l429 + 1)) {
			fRec612[l429] = 0.0;
			
		}
		for (int l430 = 0; (l430 < 2); l430 = (l430 + 1)) {
			fRec611[l430] = 0.0;
			
		}
		for (int l431 = 0; (l431 < 2); l431 = (l431 + 1)) {
			fRec609[l431] = 0.0;
			
		}
		for (int l432 = 0; (l432 < 2); l432 = (l432 + 1)) {
			fRec608[l432] = 0.0;
			
		}
		for (int l433 = 0; (l433 < 2); l433 = (l433 + 1)) {
			fRec606[l433] = 0.0;
			
		}
		for (int l434 = 0; (l434 < 2); l434 = (l434 + 1)) {
			fRec620[l434] = 0.0;
			
		}
		for (int l435 = 0; (l435 < 2); l435 = (l435 + 1)) {
			fRec618[l435] = 0.0;
			
		}
		for (int l436 = 0; (l436 < 2); l436 = (l436 + 1)) {
			fRec617[l436] = 0.0;
			
		}
		for (int l437 = 0; (l437 < 2); l437 = (l437 + 1)) {
			fRec615[l437] = 0.0;
			
		}
		for (int l438 = 0; (l438 < 2); l438 = (l438 + 1)) {
			fRec623[l438] = 0.0;
			
		}
		for (int l439 = 0; (l439 < 2); l439 = (l439 + 1)) {
			fRec621[l439] = 0.0;
			
		}
		for (int l440 = 0; (l440 < 256); l440 = (l440 + 1)) {
			fVec11[l440] = 0.0;
			
		}
		for (int l441 = 0; (l441 < 2); l441 = (l441 + 1)) {
			fRec635[l441] = 0.0;
			
		}
		for (int l442 = 0; (l442 < 2); l442 = (l442 + 1)) {
			fRec633[l442] = 0.0;
			
		}
		for (int l443 = 0; (l443 < 2); l443 = (l443 + 1)) {
			fRec632[l443] = 0.0;
			
		}
		for (int l444 = 0; (l444 < 2); l444 = (l444 + 1)) {
			fRec630[l444] = 0.0;
			
		}
		for (int l445 = 0; (l445 < 2); l445 = (l445 + 1)) {
			fRec629[l445] = 0.0;
			
		}
		for (int l446 = 0; (l446 < 2); l446 = (l446 + 1)) {
			fRec627[l446] = 0.0;
			
		}
		for (int l447 = 0; (l447 < 2); l447 = (l447 + 1)) {
			fRec626[l447] = 0.0;
			
		}
		for (int l448 = 0; (l448 < 2); l448 = (l448 + 1)) {
			fRec624[l448] = 0.0;
			
		}
		for (int l449 = 0; (l449 < 2); l449 = (l449 + 1)) {
			fRec644[l449] = 0.0;
			
		}
		for (int l450 = 0; (l450 < 2); l450 = (l450 + 1)) {
			fRec642[l450] = 0.0;
			
		}
		for (int l451 = 0; (l451 < 2); l451 = (l451 + 1)) {
			fRec641[l451] = 0.0;
			
		}
		for (int l452 = 0; (l452 < 2); l452 = (l452 + 1)) {
			fRec639[l452] = 0.0;
			
		}
		for (int l453 = 0; (l453 < 2); l453 = (l453 + 1)) {
			fRec638[l453] = 0.0;
			
		}
		for (int l454 = 0; (l454 < 2); l454 = (l454 + 1)) {
			fRec636[l454] = 0.0;
			
		}
		for (int l455 = 0; (l455 < 2); l455 = (l455 + 1)) {
			fRec650[l455] = 0.0;
			
		}
		for (int l456 = 0; (l456 < 2); l456 = (l456 + 1)) {
			fRec648[l456] = 0.0;
			
		}
		for (int l457 = 0; (l457 < 2); l457 = (l457 + 1)) {
			fRec647[l457] = 0.0;
			
		}
		for (int l458 = 0; (l458 < 2); l458 = (l458 + 1)) {
			fRec645[l458] = 0.0;
			
		}
		for (int l459 = 0; (l459 < 2); l459 = (l459 + 1)) {
			fRec653[l459] = 0.0;
			
		}
		for (int l460 = 0; (l460 < 2); l460 = (l460 + 1)) {
			fRec651[l460] = 0.0;
			
		}
		for (int l461 = 0; (l461 < 2); l461 = (l461 + 1)) {
			fRec668[l461] = 0.0;
			
		}
		for (int l462 = 0; (l462 < 2); l462 = (l462 + 1)) {
			fRec666[l462] = 0.0;
			
		}
		for (int l463 = 0; (l463 < 2); l463 = (l463 + 1)) {
			fRec665[l463] = 0.0;
			
		}
		for (int l464 = 0; (l464 < 2); l464 = (l464 + 1)) {
			fRec663[l464] = 0.0;
			
		}
		for (int l465 = 0; (l465 < 2); l465 = (l465 + 1)) {
			fRec662[l465] = 0.0;
			
		}
		for (int l466 = 0; (l466 < 2); l466 = (l466 + 1)) {
			fRec660[l466] = 0.0;
			
		}
		for (int l467 = 0; (l467 < 2); l467 = (l467 + 1)) {
			fRec659[l467] = 0.0;
			
		}
		for (int l468 = 0; (l468 < 2); l468 = (l468 + 1)) {
			fRec657[l468] = 0.0;
			
		}
		for (int l469 = 0; (l469 < 2); l469 = (l469 + 1)) {
			fRec656[l469] = 0.0;
			
		}
		for (int l470 = 0; (l470 < 2); l470 = (l470 + 1)) {
			fRec654[l470] = 0.0;
			
		}
		for (int l471 = 0; (l471 < 1024); l471 = (l471 + 1)) {
			fVec12[l471] = 0.0;
			
		}
		
	}
	
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	virtual int getSampleRate() {
		return fSamplingFreq;
		
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("KMH114_AEC_5h5p_full_6");
		ui_interface->declare(&fHslider2, "unit", "dB");
		ui_interface->addHorizontalSlider("gain", &fHslider2, -10.0, -30.0, 10.0, 1.0);
		ui_interface->declare(&fHslider1, "unit", "dB");
		ui_interface->addHorizontalSlider("lf/hf", &fHslider1, 0.0, -3.0, 3.0, 0.10000000000000001);
		ui_interface->addCheckButton("mute", &fCheckbox0);
		ui_interface->declare(&fHslider0, "unit", "Hz");
		ui_interface->addHorizontalSlider("xover", &fHslider0, 400.0, 200.0, 800.0, 20.0);
		ui_interface->closeBox();
		
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* input2 = inputs[2];
		FAUSTFLOAT* input3 = inputs[3];
		FAUSTFLOAT* input4 = inputs[4];
		FAUSTFLOAT* input5 = inputs[5];
		FAUSTFLOAT* input6 = inputs[6];
		FAUSTFLOAT* input7 = inputs[7];
		FAUSTFLOAT* input8 = inputs[8];
		FAUSTFLOAT* input9 = inputs[9];
		FAUSTFLOAT* input10 = inputs[10];
		FAUSTFLOAT* input11 = inputs[11];
		FAUSTFLOAT* input12 = inputs[12];
		FAUSTFLOAT* input13 = inputs[13];
		FAUSTFLOAT* input14 = inputs[14];
		FAUSTFLOAT* input15 = inputs[15];
		FAUSTFLOAT* input16 = inputs[16];
		FAUSTFLOAT* input17 = inputs[17];
		FAUSTFLOAT* input18 = inputs[18];
		FAUSTFLOAT* input19 = inputs[19];
		FAUSTFLOAT* input20 = inputs[20];
		FAUSTFLOAT* input21 = inputs[21];
		FAUSTFLOAT* input22 = inputs[22];
		FAUSTFLOAT* input23 = inputs[23];
		FAUSTFLOAT* input24 = inputs[24];
		FAUSTFLOAT* input25 = inputs[25];
		FAUSTFLOAT* input26 = inputs[26];
		FAUSTFLOAT* input27 = inputs[27];
		FAUSTFLOAT* input28 = inputs[28];
		FAUSTFLOAT* input29 = inputs[29];
		FAUSTFLOAT* input30 = inputs[30];
		FAUSTFLOAT* input31 = inputs[31];
		FAUSTFLOAT* input32 = inputs[32];
		FAUSTFLOAT* input33 = inputs[33];
		FAUSTFLOAT* input34 = inputs[34];
		FAUSTFLOAT* input35 = inputs[35];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		FAUSTFLOAT* output2 = outputs[2];
		FAUSTFLOAT* output3 = outputs[3];
		FAUSTFLOAT* output4 = outputs[4];
		FAUSTFLOAT* output5 = outputs[5];
		FAUSTFLOAT* output6 = outputs[6];
		FAUSTFLOAT* output7 = outputs[7];
		FAUSTFLOAT* output8 = outputs[8];
		FAUSTFLOAT* output9 = outputs[9];
		FAUSTFLOAT* output10 = outputs[10];
		FAUSTFLOAT* output11 = outputs[11];
		FAUSTFLOAT* output12 = outputs[12];
		FAUSTFLOAT* output13 = outputs[13];
		double fSlow0 = (0.0010000000000000009 * double(fHslider0));
		double fSlow1 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fHslider1))));
		double fSlow2 = (0.0010000000000000009 * (std::pow(10.0, (0.050000000000000003 * double(fHslider2))) * double((double(fCheckbox0) < 0.5))));
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec16[0] = (fSlow0 + (0.999 * fRec16[1]));
			double fTemp0 = std::tan((fConst6 * fRec16[0]));
			double fTemp1 = ((fTemp0 * (fTemp0 + -2.0)) + 1.0);
			double fTemp2 = mydsp_faustpower2_f(fTemp0);
			double fTemp3 = (fTemp2 + -1.0);
			double fTemp4 = ((fTemp0 * (fTemp0 + 2.0)) + 1.0);
			fRec15[0] = (double(input31[i]) - (((fTemp1 * fRec15[2]) + (2.0 * (fTemp3 * fRec15[1]))) / fTemp4));
			double fTemp5 = (0.0 - (2.0 / fTemp4));
			fRec17[0] = (fSlow1 + (0.999 * fRec17[1]));
			double fTemp6 = (fTemp4 * fRec17[0]);
			double fTemp7 = ((0.20571231109999999 * ((0.0 - (((fRec15[0] + fRec15[2]) / fTemp4) + (fTemp5 * fRec15[1]))) * fRec17[0])) + ((fTemp2 * (fRec15[2] + (fRec15[0] + (2.0 * fRec15[1])))) / fTemp6));
			fRec18[0] = (double(input32[i]) - (((fTemp1 * fRec18[2]) + (2.0 * (fTemp3 * fRec18[1]))) / fTemp4));
			double fTemp8 = (((fTemp2 * (fRec18[2] + ((2.0 * fRec18[1]) + fRec18[0]))) / fTemp6) + (0.20571231109999999 * ((0.0 - ((fRec18[1] * fTemp5) + ((fRec18[2] + fRec18[0]) / fTemp4))) * fRec17[0])));
			fRec19[0] = (double(input33[i]) - (((fTemp1 * fRec19[2]) + (2.0 * (fTemp3 * fRec19[1]))) / fTemp4));
			double fTemp9 = (((fTemp2 * (fRec19[2] + ((2.0 * fRec19[1]) + fRec19[0]))) / fTemp6) + (0.20571231109999999 * ((0.0 - ((fRec19[1] * fTemp5) + ((fRec19[2] + fRec19[0]) / fTemp4))) * fRec17[0])));
			fRec20[0] = (double(input34[i]) - (((fTemp1 * fRec20[2]) + (2.0 * (fTemp3 * fRec20[1]))) / fTemp4));
			double fTemp10 = (((fTemp2 * (fRec20[2] + ((2.0 * fRec20[1]) + fRec20[0]))) / fTemp6) + (0.20571231109999999 * ((0.0 - ((fRec20[1] * fTemp5) + ((fRec20[2] + fRec20[0]) / fTemp4))) * fRec17[0])));
			fRec21[0] = (double(input25[i]) - (((fTemp1 * fRec21[2]) + (2.0 * (fTemp3 * fRec21[1]))) / fTemp4));
			double fTemp11 = (((fTemp2 * (fRec21[2] + (fRec21[0] + (2.0 * fRec21[1])))) / fTemp6) + (0.20571231109999999 * (fRec17[0] * (0.0 - ((fTemp5 * fRec21[1]) + ((fRec21[0] + fRec21[2]) / fTemp4))))));
			fRec22[0] = (double(input28[i]) - (((fTemp1 * fRec22[2]) + (2.0 * (fTemp3 * fRec22[1]))) / fTemp4));
			double fTemp12 = (((fTemp2 * (fRec22[2] + (fRec22[0] + (2.0 * fRec22[1])))) / fTemp6) + (0.20571231109999999 * (fRec17[0] * (0.0 - ((fTemp5 * fRec22[1]) + ((fRec22[0] + fRec22[2]) / fTemp4))))));
			fRec23[0] = (double(input29[i]) - (((fTemp1 * fRec23[2]) + (2.0 * (fTemp3 * fRec23[1]))) / fTemp4));
			double fTemp13 = (((fTemp2 * (fRec23[2] + (fRec23[0] + (2.0 * fRec23[1])))) / fTemp6) + (0.20571231109999999 * (fRec17[0] * (0.0 - ((fTemp5 * fRec23[1]) + ((fRec23[0] + fRec23[2]) / fTemp4))))));
			fRec24[0] = (double(input35[i]) - (((fTemp1 * fRec24[2]) + (2.0 * (fTemp3 * fRec24[1]))) / fTemp4));
			double fTemp14 = (((fTemp2 * (fRec24[2] + ((2.0 * fRec24[1]) + fRec24[0]))) / fTemp6) + (0.20571231109999999 * ((0.0 - ((fRec24[1] * fTemp5) + ((fRec24[2] + fRec24[0]) / fTemp4))) * fRec17[0])));
			fRec25[0] = (double(input26[i]) - (((fTemp1 * fRec25[2]) + (2.0 * (fTemp3 * fRec25[1]))) / fTemp4));
			double fTemp15 = (((fTemp2 * (fRec25[2] + (fRec25[0] + (2.0 * fRec25[1])))) / fTemp6) + (0.20571231109999999 * (fRec17[0] * (0.0 - ((fTemp5 * fRec25[1]) + ((fRec25[0] + fRec25[2]) / fTemp4))))));
			fRec26[0] = (double(input27[i]) - (((fTemp1 * fRec26[2]) + (2.0 * (fTemp3 * fRec26[1]))) / fTemp4));
			double fTemp16 = (((fTemp2 * (fRec26[2] + (fRec26[0] + (2.0 * fRec26[1])))) / fTemp6) + (0.20571231109999999 * (fRec17[0] * (0.0 - ((fTemp5 * fRec26[1]) + ((fRec26[0] + fRec26[2]) / fTemp4))))));
			fRec27[0] = (double(input30[i]) - (((fTemp1 * fRec27[2]) + (2.0 * (fTemp3 * fRec27[1]))) / fTemp4));
			double fTemp17 = (((fTemp2 * (fRec27[2] + (fRec27[0] + (2.0 * fRec27[1])))) / fTemp6) + (0.20571231109999999 * (fRec17[0] * (0.0 - ((fTemp5 * fRec27[1]) + ((fRec27[0] + fRec27[2]) / fTemp4))))));
			double fTemp18 = (fConst5 * ((((((((0.025299101000000001 * fTemp7) + (0.018487806799999999 * fTemp8)) + (0.0059125539 * fTemp9)) + (0.033143314700000003 * fTemp10)) + (0.073034932299999994 * fTemp11)) + (0.022229469599999999 * fTemp12)) + (0.0154096184 * fTemp13)) - ((((0.10026194300000001 * fTemp14) + (0.099929311399999998 * fTemp15)) + (6.8381799999999996e-05 * fTemp16)) + (0.024408139999999998 * fTemp17))));
			double fTemp19 = (fConst7 * fRec12[1]);
			double fTemp20 = (fConst9 * fRec9[1]);
			fRec14[0] = (((fTemp18 + fRec14[1]) + fTemp19) + fTemp20);
			fRec12[0] = fRec14[0];
			double fRec13 = ((fTemp18 + fTemp19) + fTemp20);
			fRec11[0] = (fRec12[0] + fRec11[1]);
			fRec9[0] = fRec11[0];
			double fRec10 = fRec13;
			double fTemp21 = (fConst10 * fRec6[1]);
			double fTemp22 = (fConst11 * fRec3[1]);
			fRec8[0] = (((fRec10 + fRec8[1]) + fTemp21) + fTemp22);
			fRec6[0] = fRec8[0];
			double fRec7 = ((fRec10 + fTemp21) + fTemp22);
			fRec5[0] = (fRec6[0] + fRec5[1]);
			fRec3[0] = fRec5[0];
			double fRec4 = fRec7;
			double fTemp23 = (fConst12 * fRec0[1]);
			fRec2[0] = ((fRec4 + fRec2[1]) + fTemp23);
			fRec0[0] = fRec2[0];
			double fRec1 = (fRec4 + fTemp23);
			fRec28[0] = (double(input0[i]) - (((fRec28[2] * fTemp1) + (2.0 * (fRec28[1] * fTemp3))) / fTemp4));
			double fTemp24 = (((fTemp2 * (fRec28[2] + ((2.0 * fRec28[1]) + fRec28[0]))) / fTemp6) + (fRec17[0] * (0.0 - ((fRec28[1] * fTemp5) + ((fRec28[2] + fRec28[0]) / fTemp4)))));
			double fTemp25 = (fConst14 * fRec29[1]);
			double fTemp26 = (fConst15 * fRec32[1]);
			fRec41[0] = (double(input16[i]) - (((fTemp1 * fRec41[2]) + (2.0 * (fTemp3 * fRec41[1]))) / fTemp4));
			double fTemp27 = (((fTemp2 * (fRec41[2] + (fRec41[0] + (2.0 * fRec41[1])))) / fTemp6) + (0.42200500930000001 * (fRec17[0] * (0.0 - ((fTemp5 * fRec41[1]) + ((fRec41[0] + fRec41[2]) / fTemp4))))));
			fRec42[0] = (double(input19[i]) - (((fTemp1 * fRec42[2]) + (2.0 * (fTemp3 * fRec42[1]))) / fTemp4));
			double fTemp28 = (((fTemp2 * (fRec42[2] + (fRec42[0] + (2.0 * fRec42[1])))) / fTemp6) + (0.42200500930000001 * (fRec17[0] * (0.0 - ((fTemp5 * fRec42[1]) + ((fRec42[0] + fRec42[2]) / fTemp4))))));
			fRec43[0] = (double(input20[i]) - (((fTemp1 * fRec43[2]) + (2.0 * (fTemp3 * fRec43[1]))) / fTemp4));
			double fTemp29 = (((fTemp2 * (fRec43[2] + (fRec43[0] + (2.0 * fRec43[1])))) / fTemp6) + (0.42200500930000001 * (fRec17[0] * (0.0 - ((fTemp5 * fRec43[1]) + ((fRec43[0] + fRec43[2]) / fTemp4))))));
			fRec44[0] = (double(input21[i]) - (((fTemp1 * fRec44[2]) + (2.0 * (fTemp3 * fRec44[1]))) / fTemp4));
			double fTemp30 = (((fTemp2 * (fRec44[2] + (fRec44[0] + (2.0 * fRec44[1])))) / fTemp6) + (0.42200500930000001 * (fRec17[0] * (0.0 - ((fTemp5 * fRec44[1]) + ((fRec44[0] + fRec44[2]) / fTemp4))))));
			fRec45[0] = (double(input17[i]) - (((fTemp1 * fRec45[2]) + (2.0 * (fTemp3 * fRec45[1]))) / fTemp4));
			double fTemp31 = (((fTemp2 * (fRec45[2] + (fRec45[0] + (2.0 * fRec45[1])))) / fTemp6) + (0.42200500930000001 * (fRec17[0] * (0.0 - ((fTemp5 * fRec45[1]) + ((fRec45[0] + fRec45[2]) / fTemp4))))));
			fRec46[0] = (double(input18[i]) - (((fTemp1 * fRec46[2]) + (2.0 * (fTemp3 * fRec46[1]))) / fTemp4));
			double fTemp32 = (((fTemp2 * (fRec46[2] + (fRec46[0] + (2.0 * fRec46[1])))) / fTemp6) + (0.42200500930000001 * (fRec17[0] * (0.0 - ((fTemp5 * fRec46[1]) + ((fRec46[0] + fRec46[2]) / fTemp4))))));
			fRec47[0] = (double(input22[i]) - (((fTemp1 * fRec47[2]) + (2.0 * (fTemp3 * fRec47[1]))) / fTemp4));
			double fTemp33 = (((fTemp2 * (fRec47[2] + (fRec47[0] + (2.0 * fRec47[1])))) / fTemp6) + (0.42200500930000001 * (fRec17[0] * (0.0 - ((fTemp5 * fRec47[1]) + ((fRec47[0] + fRec47[2]) / fTemp4))))));
			fRec48[0] = (double(input23[i]) - (((fTemp1 * fRec48[2]) + (2.0 * (fTemp3 * fRec48[1]))) / fTemp4));
			double fTemp34 = (((fTemp2 * (fRec48[2] + (fRec48[0] + (2.0 * fRec48[1])))) / fTemp6) + (0.42200500930000001 * (fRec17[0] * (0.0 - ((fTemp5 * fRec48[1]) + ((fRec48[0] + fRec48[2]) / fTemp4))))));
			fRec49[0] = (double(input24[i]) - (((fTemp1 * fRec49[2]) + (2.0 * (fTemp3 * fRec49[1]))) / fTemp4));
			double fTemp35 = (((fTemp2 * (fRec49[2] + (fRec49[0] + (2.0 * fRec49[1])))) / fTemp6) + (0.42200500930000001 * (fRec17[0] * (0.0 - ((fTemp5 * fRec49[1]) + ((fRec49[0] + fRec49[2]) / fTemp4))))));
			double fTemp36 = (fConst17 * (((((0.12789909250000001 * fTemp27) + (0.022717052799999998 * fTemp28)) + (0.016728998700000001 * fTemp29)) + (0.045275054699999998 * fTemp30)) - (((((0.1125766629 * fTemp31) + (0.012406558999999999 * fTemp32)) + (0.0038043851 * fTemp33)) + (0.015862543600000001 * fTemp34)) + (0.059600389599999998 * fTemp35))));
			double fTemp37 = (fConst18 * fRec35[1]);
			double fTemp38 = (fConst19 * fRec38[1]);
			fRec40[0] = (fTemp36 + (fTemp37 + (fRec40[1] + fTemp38)));
			fRec38[0] = fRec40[0];
			double fRec39 = ((fTemp38 + fTemp37) + fTemp36);
			fRec37[0] = (fRec38[0] + fRec37[1]);
			fRec35[0] = fRec37[0];
			double fRec36 = fRec39;
			fRec34[0] = (fTemp25 + (fTemp26 + (fRec36 + fRec34[1])));
			fRec32[0] = fRec34[0];
			double fRec33 = (fTemp25 + (fRec36 + fTemp26));
			fRec31[0] = (fRec32[0] + fRec31[1]);
			fRec29[0] = fRec31[0];
			double fRec30 = fRec33;
			double fTemp39 = (fConst21 * fRec50[1]);
			fRec59[0] = (double(input9[i]) - (((fTemp1 * fRec59[2]) + (2.0 * (fTemp3 * fRec59[1]))) / fTemp4));
			double fTemp40 = (((fTemp2 * (fRec59[2] + (fRec59[0] + (2.0 * fRec59[1])))) / fTemp6) + (0.62824992459999995 * (fRec17[0] * (0.0 - ((fTemp5 * fRec59[1]) + ((fRec59[0] + fRec59[2]) / fTemp4))))));
			fRec60[0] = (double(input12[i]) - (((fTemp1 * fRec60[2]) + (2.0 * (fTemp3 * fRec60[1]))) / fTemp4));
			double fTemp41 = (((fTemp2 * (fRec60[2] + (fRec60[0] + (2.0 * fRec60[1])))) / fTemp6) + (0.62824992459999995 * (fRec17[0] * (0.0 - ((fTemp5 * fRec60[1]) + ((fRec60[0] + fRec60[2]) / fTemp4))))));
			fRec61[0] = (double(input15[i]) - (((fTemp1 * fRec61[2]) + (2.0 * (fTemp3 * fRec61[1]))) / fTemp4));
			double fTemp42 = (((fTemp2 * (fRec61[2] + (fRec61[0] + (2.0 * fRec61[1])))) / fTemp6) + (0.62824992459999995 * (fRec17[0] * (0.0 - ((fTemp5 * fRec61[1]) + ((fRec61[0] + fRec61[2]) / fTemp4))))));
			fRec62[0] = (double(input10[i]) - (((fTemp1 * fRec62[2]) + (2.0 * (fTemp3 * fRec62[1]))) / fTemp4));
			double fTemp43 = (((fTemp2 * (fRec62[2] + (fRec62[0] + (2.0 * fRec62[1])))) / fTemp6) + (0.62824992459999995 * (fRec17[0] * (0.0 - ((fTemp5 * fRec62[1]) + ((fRec62[0] + fRec62[2]) / fTemp4))))));
			fRec63[0] = (double(input11[i]) - (((fTemp1 * fRec63[2]) + (2.0 * (fTemp3 * fRec63[1]))) / fTemp4));
			double fTemp44 = (((fTemp2 * (fRec63[2] + (fRec63[0] + (2.0 * fRec63[1])))) / fTemp6) + (0.62824992459999995 * (fRec17[0] * (0.0 - ((fTemp5 * fRec63[1]) + ((fRec63[0] + fRec63[2]) / fTemp4))))));
			fRec64[0] = (double(input13[i]) - (((fTemp1 * fRec64[2]) + (2.0 * (fTemp3 * fRec64[1]))) / fTemp4));
			double fTemp45 = (((fTemp2 * (fRec64[2] + (fRec64[0] + (2.0 * fRec64[1])))) / fTemp6) + (0.62824992459999995 * (fRec17[0] * (0.0 - ((fTemp5 * fRec64[1]) + ((fRec64[0] + fRec64[2]) / fTemp4))))));
			fRec65[0] = (double(input14[i]) - (((fTemp1 * fRec65[2]) + (2.0 * (fTemp3 * fRec65[1]))) / fTemp4));
			double fTemp46 = (((fTemp2 * (fRec65[2] + (fRec65[0] + (2.0 * fRec65[1])))) / fTemp6) + (0.62824992459999995 * (fRec17[0] * (0.0 - ((fTemp5 * fRec65[1]) + ((fRec65[0] + fRec65[2]) / fTemp4))))));
			double fTemp47 = (fConst23 * ((((0.14711612539999999 * fTemp40) + (0.052724825400000001 * fTemp41)) + (0.0099831204999999996 * fTemp42)) - ((((0.091151080600000003 * fTemp43) + (0.016607731300000001 * fTemp44)) + (0.0275389742 * fTemp45)) + (0.063857430000000007 * fTemp46))));
			double fTemp48 = (fConst24 * fRec53[1]);
			double fTemp49 = (fConst25 * fRec56[1]);
			fRec58[0] = (fTemp47 + (fTemp48 + (fRec58[1] + fTemp49)));
			fRec56[0] = fRec58[0];
			double fRec57 = ((fTemp49 + fTemp48) + fTemp47);
			fRec55[0] = (fRec56[0] + fRec55[1]);
			fRec53[0] = fRec55[0];
			double fRec54 = fRec57;
			fRec52[0] = (fTemp39 + (fRec54 + fRec52[1]));
			fRec50[0] = fRec52[0];
			double fRec51 = (fRec54 + fTemp39);
			fRec69[0] = (double(input1[i]) - (((fTemp1 * fRec69[2]) + (2.0 * (fTemp3 * fRec69[1]))) / fTemp4));
			double fTemp50 = (((fTemp2 * (fRec69[2] + (fRec69[0] + (2.0 * fRec69[1])))) / fTemp6) + (0.93246951420000002 * (fRec17[0] * (0.0 - ((fTemp5 * fRec69[1]) + ((fRec69[0] + fRec69[2]) / fTemp4))))));
			fRec70[0] = (double(input3[i]) - (((fTemp1 * fRec70[2]) + (2.0 * (fTemp3 * fRec70[1]))) / fTemp4));
			double fTemp51 = (((fTemp2 * (fRec70[2] + (fRec70[0] + (2.0 * fRec70[1])))) / fTemp6) + (0.93246951420000002 * (fRec17[0] * (0.0 - ((fTemp5 * fRec70[1]) + ((fRec70[0] + fRec70[2]) / fTemp4))))));
			fRec71[0] = (double(input2[i]) - (((fTemp1 * fRec71[2]) + (2.0 * (fTemp3 * fRec71[1]))) / fTemp4));
			double fTemp52 = (((fTemp2 * (fRec71[2] + (fRec71[0] + (2.0 * fRec71[1])))) / fTemp6) + (0.93246951420000002 * (fRec17[0] * (0.0 - ((fTemp5 * fRec71[1]) + ((fRec71[0] + fRec71[2]) / fTemp4))))));
			double fTemp53 = (fConst27 * (((0.054611664599999998 * fTemp50) + (0.1001530682 * fTemp51)) - (0.045051330399999999 * fTemp52)));
			double fTemp54 = (fConst28 * fRec66[1]);
			fRec68[0] = (fTemp53 + (fRec68[1] + fTemp54));
			fRec66[0] = fRec68[0];
			double fRec67 = (fTemp54 + fTemp53);
			fRec78[0] = (double(input4[i]) - (((fTemp1 * fRec78[2]) + (2.0 * (fTemp3 * fRec78[1]))) / fTemp4));
			double fTemp55 = (((fTemp2 * (fRec78[2] + (fRec78[0] + (2.0 * fRec78[1])))) / fTemp6) + (0.80424909239999998 * (fRec17[0] * (0.0 - ((fTemp5 * fRec78[1]) + ((fRec78[0] + fRec78[2]) / fTemp4))))));
			fRec79[0] = (double(input8[i]) - (((fTemp1 * fRec79[2]) + (2.0 * (fTemp3 * fRec79[1]))) / fTemp4));
			double fTemp56 = (((fTemp2 * (fRec79[2] + (fRec79[0] + (2.0 * fRec79[1])))) / fTemp6) + (0.80424909239999998 * (fRec17[0] * (0.0 - ((fTemp5 * fRec79[1]) + ((fRec79[0] + fRec79[2]) / fTemp4))))));
			fRec80[0] = (double(input5[i]) - (((fTemp1 * fRec80[2]) + (2.0 * (fTemp3 * fRec80[1]))) / fTemp4));
			double fTemp57 = (((fTemp2 * (fRec80[2] + (fRec80[0] + (2.0 * fRec80[1])))) / fTemp6) + (0.80424909239999998 * (fRec17[0] * (0.0 - ((fTemp5 * fRec80[1]) + ((fRec80[0] + fRec80[2]) / fTemp4))))));
			fRec81[0] = (double(input6[i]) - (((fTemp1 * fRec81[2]) + (2.0 * (fTemp3 * fRec81[1]))) / fTemp4));
			double fTemp58 = (((fTemp2 * (fRec81[2] + (fRec81[0] + (2.0 * fRec81[1])))) / fTemp6) + (0.80424909239999998 * (fRec17[0] * (0.0 - ((fTemp5 * fRec81[1]) + ((fRec81[0] + fRec81[2]) / fTemp4))))));
			fRec82[0] = (double(input7[i]) - (((fTemp1 * fRec82[2]) + (2.0 * (fTemp3 * fRec82[1]))) / fTemp4));
			double fTemp59 = (((fTemp2 * (fRec82[2] + (fRec82[0] + (2.0 * fRec82[1])))) / fTemp6) + (0.80424909239999998 * (fRec17[0] * (0.0 - ((fTemp5 * fRec82[1]) + ((fRec82[0] + fRec82[2]) / fTemp4))))));
			double fTemp60 = (fConst30 * (((0.1175711931 * fTemp55) + (0.075422010400000003 * fTemp56)) - (((0.044265196499999999 * fTemp57) + (0.042932384400000002 * fTemp58)) + (0.0846327474 * fTemp59))));
			double fTemp61 = (fConst31 * fRec72[1]);
			double fTemp62 = (fConst32 * fRec75[1]);
			fRec77[0] = (fTemp60 + (fTemp61 + (fRec77[1] + fTemp62)));
			fRec75[0] = fRec77[0];
			double fRec76 = ((fTemp62 + fTemp61) + fTemp60);
			fRec74[0] = (fRec75[0] + fRec74[1]);
			fRec72[0] = fRec74[0];
			double fRec73 = fRec76;
			fVec0[(IOTA & 127)] = (fRec1 + ((0.044306982199999997 * fTemp24) + (fRec30 + (fRec51 + (fRec67 + fRec73)))));
			fRec83[0] = (fSlow2 + (0.999 * fRec83[1]));
			output0[i] = FAUSTFLOAT((0.96563981042654023 * (fVec0[((IOTA - iConst33) & 127)] * fRec83[0])));
			double fTemp63 = (fConst35 * (((0.035087305999999999 * fTemp52) + (0.2210033783 * fTemp51)) - (0.001126527 * fTemp50)));
			double fTemp64 = (fConst36 * fRec84[1]);
			fRec86[0] = (fTemp63 + (fRec86[1] + fTemp64));
			fRec84[0] = fRec86[0];
			double fRec85 = (fTemp64 + fTemp63);
			double fTemp65 = (fConst38 * ((((0.00083796649999999995 * fTemp57) + (0.068617371600000004 * fTemp59)) + (0.25217342040000001 * fTemp56)) - ((0.0027633324 * fTemp55) + (0.056263776799999998 * fTemp58))));
			double fTemp66 = (fConst39 * fRec87[1]);
			double fTemp67 = (fConst40 * fRec90[1]);
			fRec92[0] = (fTemp65 + (fTemp66 + (fRec92[1] + fTemp67)));
			fRec90[0] = fRec92[0];
			double fRec91 = ((fTemp67 + fTemp66) + fTemp65);
			fRec89[0] = (fRec89[1] + fRec90[0]);
			fRec87[0] = fRec89[0];
			double fRec88 = fRec91;
			double fTemp68 = (fConst42 * fRec93[1]);
			double fTemp69 = (fConst44 * (((0.24261249039999999 * fTemp42) + ((0.061111228400000002 * fTemp46) + (((0.0019786825 * fTemp43) + (0.00041639360000000002 * fTemp44)) + (0.0019556309000000002 * fTemp45)))) - ((0.0043438985999999999 * fTemp40) + (0.039893204199999997 * fTemp41))));
			double fTemp70 = (fConst45 * fRec96[1]);
			double fTemp71 = (fConst46 * fRec99[1]);
			fRec101[0] = (fTemp69 + (fTemp70 + (fRec101[1] + fTemp71)));
			fRec99[0] = fRec101[0];
			double fRec100 = ((fTemp71 + fTemp70) + fTemp69);
			fRec98[0] = (fRec98[1] + fRec99[0]);
			fRec96[0] = fRec98[0];
			double fRec97 = fRec100;
			fRec95[0] = ((fRec95[1] + fTemp68) + fRec97);
			fRec93[0] = fRec95[0];
			double fRec94 = (fTemp68 + fRec97);
			double fTemp72 = (fConst48 * fRec102[1]);
			double fTemp73 = (fConst49 * fRec105[1]);
			double fTemp74 = (fConst51 * (((0.2071684546 * fTemp35) + ((0.031875251600000001 * fTemp34) + (((0.0031301293999999999 * fTemp31) + (0.00043761270000000001 * fTemp32)) + (0.048364605300000002 * fTemp33)))) - ((((0.0054476469999999999 * fTemp27) + (0.00039274299999999998 * fTemp28)) + (0.021649410000000001 * fTemp29)) + (0.034170276800000003 * fTemp30))));
			double fTemp75 = (fConst52 * fRec108[1]);
			double fTemp76 = (fConst53 * fRec111[1]);
			fRec113[0] = (fTemp74 + (fTemp75 + (fRec113[1] + fTemp76)));
			fRec111[0] = fRec113[0];
			double fRec112 = ((fTemp76 + fTemp75) + fTemp74);
			fRec110[0] = (fRec110[1] + fRec111[0]);
			fRec108[0] = fRec110[0];
			double fRec109 = fRec112;
			fRec107[0] = ((fTemp72 + (fRec107[1] + fTemp73)) + fRec109);
			fRec105[0] = fRec107[0];
			double fRec106 = ((fTemp73 + fTemp72) + fRec109);
			fRec104[0] = (fRec104[1] + fRec105[0]);
			fRec102[0] = fRec104[0];
			double fRec103 = fRec106;
			double fTemp77 = (fConst55 * fRec114[1]);
			double fTemp78 = (fConst57 * fRec117[1]);
			double fTemp79 = (fConst58 * fRec120[1]);
			double fTemp80 = (fConst60 * (((0.0165718121 * fTemp17) + ((0.00017641719999999999 * fTemp16) + ((0.0040795247999999996 * fTemp15) + ((0.063755184399999998 * fTemp9) + (0.1592932376 * fTemp14))))) - ((0.000372001 * fTemp13) + ((0.00040016850000000002 * fTemp12) + ((0.0058125779999999997 * fTemp11) + (((0.016077186699999999 * fTemp7) + (0.0145779012 * fTemp8)) + (0.0082835362999999999 * fTemp10)))))));
			double fTemp81 = (fConst61 * fRec123[1]);
			double fTemp82 = (fConst62 * fRec126[1]);
			fRec128[0] = (fTemp80 + (fTemp81 + (fRec128[1] + fTemp82)));
			fRec126[0] = fRec128[0];
			double fRec127 = ((fTemp82 + fTemp81) + fTemp80);
			fRec125[0] = (fRec125[1] + fRec126[0]);
			fRec123[0] = fRec125[0];
			double fRec124 = fRec127;
			fRec122[0] = ((fTemp78 + (fRec122[1] + fTemp79)) + fRec124);
			fRec120[0] = fRec122[0];
			double fRec121 = ((fTemp79 + fTemp78) + fRec124);
			fRec119[0] = (fRec119[1] + fRec120[0]);
			fRec117[0] = fRec119[0];
			double fRec118 = fRec121;
			fRec116[0] = ((fRec116[1] + fTemp77) + fRec118);
			fRec114[0] = fRec116[0];
			double fRec115 = (fTemp77 + fRec118);
			fVec1[(IOTA & 63)] = ((((((0.090002385300000001 * fTemp24) + fRec85) + fRec88) + fRec94) + fRec103) + fRec115);
			output1[i] = FAUSTFLOAT((0.96860189573459721 * (fVec1[((IOTA - iConst63) & 63)] * fRec83[0])));
			double fTemp83 = (fConst65 * ((0.099655899800000003 * fTemp51) - ((0.055476548299999998 * fTemp50) + (0.045039828300000001 * fTemp52))));
			double fTemp84 = (fConst66 * fRec129[1]);
			fRec131[0] = (fTemp83 + (fRec131[1] + fTemp84));
			fRec129[0] = fRec131[0];
			double fRec130 = (fTemp84 + fTemp83);
			double fTemp85 = (fConst68 * (((0.045066650999999999 * fTemp57) + (0.073332930800000001 * fTemp56)) - (((0.1189039804 * fTemp55) + (0.042942440300000002 * fTemp58)) + (0.084217625700000007 * fTemp59))));
			double fTemp86 = (fConst69 * fRec132[1]);
			double fTemp87 = (fConst70 * fRec135[1]);
			fRec137[0] = (fTemp85 + (fTemp86 + (fRec137[1] + fTemp87)));
			fRec135[0] = fRec137[0];
			double fRec136 = ((fTemp87 + fTemp86) + fTemp85);
			fRec134[0] = (fRec134[1] + fRec135[0]);
			fRec132[0] = fRec134[0];
			double fRec133 = fRec136;
			double fTemp88 = (fConst72 * fRec138[1]);
			double fTemp89 = (fConst74 * (((((0.092401297499999993 * fTemp43) + (0.016794990400000001 * fTemp44)) + (0.052763034799999997 * fTemp41)) + (0.0059521139999999997 * fTemp42)) - (((0.14742560539999999 * fTemp40) + (0.0274284074 * fTemp45)) + (0.0620936235 * fTemp46))));
			double fTemp90 = (fConst75 * fRec141[1]);
			double fTemp91 = (fConst76 * fRec144[1]);
			fRec146[0] = (fTemp89 + (fTemp90 + (fRec146[1] + fTemp91)));
			fRec144[0] = fRec146[0];
			double fRec145 = ((fTemp91 + fTemp90) + fTemp89);
			fRec143[0] = (fRec143[1] + fRec144[0]);
			fRec141[0] = fRec143[0];
			double fRec142 = fRec145;
			fRec140[0] = ((fRec140[1] + fTemp88) + fRec142);
			fRec138[0] = fRec140[0];
			double fRec139 = (fTemp88 + fRec142);
			double fTemp92 = (fConst78 * fRec147[1]);
			double fTemp93 = (fConst79 * fRec150[1]);
			double fTemp94 = (fConst81 * (((0.045076755500000003 * fTemp30) + (((0.1130707118 * fTemp31) + (0.0124021714 * fTemp32)) + (0.016707711900000002 * fTemp29))) - ((0.064549537899999995 * fTemp35) + ((0.012431972100000001 * fTemp34) + (((0.12570869909999999 * fTemp27) + (0.0231748492 * fTemp28)) + (0.0037321070000000001 * fTemp33))))));
			double fTemp95 = (fConst82 * fRec153[1]);
			double fTemp96 = (fConst83 * fRec156[1]);
			fRec158[0] = (fTemp94 + (fTemp95 + (fRec158[1] + fTemp96)));
			fRec156[0] = fRec158[0];
			double fRec157 = ((fTemp96 + fTemp95) + fTemp94);
			fRec155[0] = (fRec155[1] + fRec156[0]);
			fRec153[0] = fRec155[0];
			double fRec154 = fRec157;
			fRec152[0] = ((fTemp92 + (fRec152[1] + fTemp93)) + fRec154);
			fRec150[0] = fRec152[0];
			double fRec151 = ((fTemp93 + fTemp92) + fRec154);
			fRec149[0] = (fRec149[1] + fRec150[0]);
			fRec147[0] = fRec149[0];
			double fRec148 = fRec151;
			double fTemp97 = (fConst85 * fRec159[1]);
			double fTemp98 = (fConst87 * fRec162[1]);
			double fTemp99 = (fConst88 * fRec165[1]);
			double fTemp100 = (fConst90 * (((0.098467620699999994 * fTemp15) + ((0.0374858068 * fTemp10) + ((0.0056323941999999998 * fTemp9) + ((0.0252212437 * fTemp7) + (0.018028466100000001 * fTemp8))))) - ((0.024387334100000001 * fTemp17) + ((0.0155970919 * fTemp13) + ((0.022633359799999999 * fTemp12) + ((7.7664300000000001e-05 * fTemp16) + ((0.067994928400000001 * fTemp11) + (0.104180301 * fTemp14))))))));
			double fTemp101 = (fConst91 * fRec168[1]);
			double fTemp102 = (fConst92 * fRec171[1]);
			fRec173[0] = (fTemp100 + (fTemp101 + (fRec173[1] + fTemp102)));
			fRec171[0] = fRec173[0];
			double fRec172 = ((fTemp102 + fTemp101) + fTemp100);
			fRec170[0] = (fRec170[1] + fRec171[0]);
			fRec168[0] = fRec170[0];
			double fRec169 = fRec172;
			fRec167[0] = ((fTemp98 + (fRec167[1] + fTemp99)) + fRec169);
			fRec165[0] = fRec167[0];
			double fRec166 = ((fTemp99 + fTemp98) + fRec169);
			fRec164[0] = (fRec164[1] + fRec165[0]);
			fRec162[0] = fRec164[0];
			double fRec163 = fRec166;
			fRec161[0] = ((fRec161[1] + fTemp97) + fRec163);
			fRec159[0] = fRec161[0];
			double fRec160 = (fTemp97 + fRec163);
			fVec2[(IOTA & 63)] = ((((((0.044292682299999997 * fTemp24) + fRec130) + fRec133) + fRec139) + fRec148) + fRec160);
			output2[i] = FAUSTFLOAT((0.97748815165876779 * (fVec2[((IOTA - iConst93) & 63)] * fRec83[0])));
			double fTemp103 = (fConst95 * ((0.068978500200000001 * fTemp51) - ((0.137005127 * fTemp50) + (0.061796046299999997 * fTemp52))));
			double fTemp104 = (fConst96 * fRec174[1]);
			fRec176[0] = (fTemp103 + (fRec176[1] + fTemp104));
			fRec174[0] = fRec176[0];
			double fRec175 = (fTemp104 + fTemp103);
			double fTemp105 = (fConst98 * ((0.1154948672 * fTemp57) - ((((0.1431430266 * fTemp55) + (0.058504607600000001 * fTemp58)) + (0.055501522900000003 * fTemp59)) + (0.1045101599 * fTemp56))));
			double fTemp106 = (fConst99 * fRec177[1]);
			double fTemp107 = (fConst100 * fRec180[1]);
			fRec182[0] = (fTemp105 + (fTemp106 + (fRec182[1] + fTemp107)));
			fRec180[0] = fRec182[0];
			double fRec181 = ((fTemp107 + fTemp106) + fTemp105);
			fRec179[0] = (fRec179[1] + fRec180[0]);
			fRec177[0] = fRec179[0];
			double fRec178 = fRec181;
			double fTemp108 = (fConst102 * fRec183[1]);
			double fTemp109 = (fConst104 * ((((((0.0240859278 * fTemp40) + (0.1092067602 * fTemp43)) + (0.037356989799999997 * fTemp44)) + (0.071656250599999999 * fTemp41)) + (0.087380332000000005 * fTemp46)) - ((0.021033587999999999 * fTemp45) + (0.1672812393 * fTemp42))));
			double fTemp110 = (fConst105 * fRec186[1]);
			double fTemp111 = (fConst106 * fRec189[1]);
			fRec191[0] = (fTemp109 + (fTemp110 + (fRec191[1] + fTemp111)));
			fRec189[0] = fRec191[0];
			double fRec190 = ((fTemp111 + fTemp110) + fTemp109);
			fRec188[0] = (fRec188[1] + fRec189[0]);
			fRec186[0] = fRec188[0];
			double fRec187 = fRec190;
			fRec185[0] = ((fRec185[1] + fTemp108) + fRec187);
			fRec183[0] = fRec185[0];
			double fRec184 = (fTemp108 + fRec187);
			double fTemp112 = (fConst108 * fRec192[1]);
			double fTemp113 = (fConst109 * fRec195[1]);
			double fTemp114 = (fConst111 * (((0.123789315 * fTemp34) + ((0.0057537808000000003 * fTemp33) + ((0.0277217269 * fTemp30) + (((0.1289556926 * fTemp27) + (0.0158544501 * fTemp32)) + (0.022828068399999998 * fTemp29))))) - (((0.028193329499999999 * fTemp31) + (0.060595397799999999 * fTemp28)) + (0.050251470899999998 * fTemp35))));
			double fTemp115 = (fConst112 * fRec198[1]);
			double fTemp116 = (fConst113 * fRec201[1]);
			fRec203[0] = (fTemp114 + (fTemp115 + (fRec203[1] + fTemp116)));
			fRec201[0] = fRec203[0];
			double fRec202 = ((fTemp116 + fTemp115) + fTemp114);
			fRec200[0] = (fRec200[1] + fRec201[0]);
			fRec198[0] = fRec200[0];
			double fRec199 = fRec202;
			fRec197[0] = ((fTemp112 + (fRec197[1] + fTemp113)) + fRec199);
			fRec195[0] = fRec197[0];
			double fRec196 = ((fTemp113 + fTemp112) + fRec199);
			fRec194[0] = (fRec194[1] + fRec195[0]);
			fRec192[0] = fRec194[0];
			double fRec193 = fRec196;
			double fTemp117 = (fConst115 * fRec204[1]);
			double fTemp118 = (fConst117 * fRec207[1]);
			double fTemp119 = (fConst118 * fRec210[1]);
			double fTemp120 = (fConst120 * (((0.0068986906000000001 * fTemp16) + ((0.078388411500000005 * fTemp11) + ((0.056779297300000003 * fTemp14) + ((0.022546072300000001 * fTemp10) + ((0.019866383200000001 * fTemp7) + (0.0023246925999999999 * fTemp9)))))) - ((0.032519356999999999 * fTemp17) + ((0.034953066999999997 * fTemp13) + ((0.024550059900000001 * fTemp12) + ((0.094373202000000003 * fTemp15) + (0.024024803399999999 * fTemp8)))))));
			double fTemp121 = (fConst121 * fRec213[1]);
			double fTemp122 = (fConst122 * fRec216[1]);
			fRec218[0] = (fTemp120 + (fTemp121 + (fRec218[1] + fTemp122)));
			fRec216[0] = fRec218[0];
			double fRec217 = ((fTemp122 + fTemp121) + fTemp120);
			fRec215[0] = (fRec215[1] + fRec216[0]);
			fRec213[0] = fRec215[0];
			double fRec214 = fRec217;
			fRec212[0] = ((fTemp118 + (fRec212[1] + fTemp119)) + fRec214);
			fRec210[0] = fRec212[0];
			double fRec211 = ((fTemp119 + fTemp118) + fRec214);
			fRec209[0] = (fRec209[1] + fRec210[0]);
			fRec207[0] = fRec209[0];
			double fRec208 = fRec211;
			fRec206[0] = ((fRec206[1] + fTemp117) + fRec208);
			fRec204[0] = fRec206[0];
			double fRec205 = (fTemp117 + fRec208);
			fVec3[0] = ((((((0.060745746900000001 * fTemp24) + fRec175) + fRec178) + fRec184) + fRec193) + fRec205);
			output3[i] = FAUSTFLOAT((0.99229857819905221 * (fVec3[iConst123] * fRec83[0])));
			double fTemp123 = (fConst35 * (0.0 - (((0.1701255931 * fTemp50) + (0.0473590334 * fTemp52)) + (0.019553854799999999 * fTemp51))));
			double fTemp124 = (fConst36 * fRec219[1]);
			fRec221[0] = (fTemp123 + (fRec221[1] + fTemp124));
			fRec219[0] = fRec221[0];
			double fRec220 = (fTemp124 + fTemp123);
			double fTemp125 = (fConst38 * ((((0.046348462600000001 * fTemp55) + (0.094128958900000004 * fTemp57)) + (0.014375343 * fTemp59)) - ((0.078820296999999998 * fTemp58) + (0.19567594029999999 * fTemp56))));
			double fTemp126 = (fConst39 * fRec222[1]);
			double fTemp127 = (fConst40 * fRec225[1]);
			fRec227[0] = (fTemp125 + (fTemp126 + (fRec227[1] + fTemp127)));
			fRec225[0] = fRec227[0];
			double fRec226 = ((fTemp127 + fTemp126) + fTemp125);
			fRec224[0] = (fRec224[1] + fRec225[0]);
			fRec222[0] = fRec224[0];
			double fRec223 = fRec226;
			double fTemp128 = (fConst42 * fRec228[1]);
			double fTemp129 = (fConst44 * (((0.068722808299999993 * fTemp42) + ((0.099718374799999995 * fTemp46) + ((((0.18093873059999999 * fTemp40) + (0.075647088900000006 * fTemp44)) + (0.040251609200000003 * fTemp41)) + (0.0068891880000000001 * fTemp45)))) - (0.032397425700000003 * fTemp43)));
			double fTemp130 = (fConst45 * fRec231[1]);
			double fTemp131 = (fConst46 * fRec234[1]);
			fRec236[0] = (fTemp129 + (fTemp130 + (fRec236[1] + fTemp131)));
			fRec234[0] = fRec236[0];
			double fRec235 = ((fTemp131 + fTemp130) + fTemp129);
			fRec233[0] = (fRec233[1] + fRec234[0]);
			fRec231[0] = fRec233[0];
			double fRec232 = fRec235;
			fRec230[0] = ((fRec230[1] + fTemp128) + fRec232);
			fRec228[0] = fRec230[0];
			double fRec229 = (fTemp128 + fRec232);
			double fTemp132 = (fConst48 * fRec237[1]);
			double fTemp133 = (fConst49 * fRec240[1]);
			double fTemp134 = (fConst51 * ((((0.044592959199999997 * fTemp29) + (0.044711451200000002 * fTemp33)) + (0.1374703954 * fTemp35)) - ((((((0.078764791400000006 * fTemp27) + (0.089724770800000006 * fTemp31)) + (0.0068631817000000001 * fTemp32)) + (0.017885314699999998 * fTemp28)) + (0.0062718790000000002 * fTemp30)) + (0.047419263699999999 * fTemp34))));
			double fTemp135 = (fConst52 * fRec243[1]);
			double fTemp136 = (fConst53 * fRec246[1]);
			fRec248[0] = (fTemp134 + (fTemp135 + (fRec248[1] + fTemp136)));
			fRec246[0] = fRec248[0];
			double fRec247 = ((fTemp136 + fTemp135) + fTemp134);
			fRec245[0] = (fRec245[1] + fRec246[0]);
			fRec243[0] = fRec245[0];
			double fRec244 = fRec247;
			fRec242[0] = ((fTemp132 + (fRec242[1] + fTemp133)) + fRec244);
			fRec240[0] = fRec242[0];
			double fRec241 = ((fTemp133 + fTemp132) + fRec244);
			fRec239[0] = (fRec239[1] + fRec240[0]);
			fRec237[0] = fRec239[0];
			double fRec238 = fRec241;
			double fTemp137 = (fConst55 * fRec249[1]);
			double fTemp138 = (fConst57 * fRec252[1]);
			double fTemp139 = (fConst58 * fRec255[1]);
			double fTemp140 = (fConst60 * (((0.0088562095 * fTemp17) + ((0.0052786574000000001 * fTemp12) + ((0.055185392700000002 * fTemp15) + (0.010664019 * fTemp8)))) - ((0.061513565399999998 * fTemp13) + ((0.019506394999999999 * fTemp16) + ((0.080378668400000006 * fTemp11) + ((0.073279692100000002 * fTemp14) + ((0.070279184999999994 * fTemp10) + ((0.0064170705000000001 * fTemp7) + (0.0025326260000000001 * fTemp9)))))))));
			double fTemp141 = (fConst61 * fRec258[1]);
			double fTemp142 = (fConst62 * fRec261[1]);
			fRec263[0] = (fTemp140 + (fTemp141 + (fRec263[1] + fTemp142)));
			fRec261[0] = fRec263[0];
			double fRec262 = ((fTemp142 + fTemp141) + fTemp140);
			fRec260[0] = (fRec260[1] + fRec261[0]);
			fRec258[0] = fRec260[0];
			double fRec259 = fRec262;
			fRec257[0] = ((fTemp138 + (fRec257[1] + fTemp139)) + fRec259);
			fRec255[0] = fRec257[0];
			double fRec256 = ((fTemp139 + fTemp138) + fRec259);
			fRec254[0] = (fRec254[1] + fRec255[0]);
			fRec252[0] = fRec254[0];
			double fRec253 = fRec256;
			fRec251[0] = ((fRec251[1] + fTemp137) + fRec253);
			fRec249[0] = fRec251[0];
			double fRec250 = (fTemp137 + fRec253);
			fVec4[(IOTA & 63)] = ((((((0.066334443100000001 * fTemp24) + fRec220) + fRec223) + fRec229) + fRec238) + fRec250);
			output4[i] = FAUSTFLOAT((0.96860189573459721 * (fVec4[((IOTA - iConst63) & 63)] * fRec83[0])));
			double fTemp143 = (fConst125 * fRec264[1]);
			double fTemp144 = (fConst127 * fRec267[1]);
			double fTemp145 = (fConst128 * fRec270[1]);
			double fTemp146 = (fConst130 * (((0.016477930599999999 * fTemp12) + ((0.0032562060999999998 * fTemp16) + ((0.0016627395000000001 * fTemp15) + ((0.061253788500000003 * fTemp11) + ((0.042673284899999997 * fTemp14) + ((0.0122992148 * fTemp9) + (0.0588579615 * fTemp10))))))) - ((0.0024168865000000002 * fTemp17) + ((0.024967545300000001 * fTemp13) + ((0.081241189800000002 * fTemp7) + (0.029997316 * fTemp8))))));
			double fTemp147 = (fConst131 * fRec273[1]);
			double fTemp148 = (fConst132 * fRec276[1]);
			fRec278[0] = (fTemp146 + (fTemp147 + (fRec278[1] + fTemp148)));
			fRec276[0] = fRec278[0];
			double fRec277 = ((fTemp148 + fTemp147) + fTemp146);
			fRec275[0] = (fRec276[0] + fRec275[1]);
			fRec273[0] = fRec275[0];
			double fRec274 = fRec277;
			fRec272[0] = (fTemp144 + (fTemp145 + (fRec274 + fRec272[1])));
			fRec270[0] = fRec272[0];
			double fRec271 = (fTemp144 + (fRec274 + fTemp145));
			fRec269[0] = (fRec270[0] + fRec269[1]);
			fRec267[0] = fRec269[0];
			double fRec268 = fRec271;
			fRec266[0] = (fTemp143 + (fRec268 + fRec266[1]));
			fRec264[0] = fRec266[0];
			double fRec265 = (fRec268 + fTemp143);
			double fTemp149 = (fConst134 * (0.0 - (((0.0897001506 * fTemp50) + (0.098515358299999994 * fTemp52)) + (0.25711536950000002 * fTemp51))));
			double fTemp150 = (fConst135 * fRec279[1]);
			fRec281[0] = (fTemp149 + (fRec281[1] + fTemp150));
			fRec279[0] = fRec281[0];
			double fRec280 = (fTemp150 + fTemp149);
			double fTemp151 = (fConst137 * (((((0.15740925159999999 * fTemp55) + (0.071790105399999998 * fTemp57)) + (0.16582771599999999 * fTemp59)) + (0.1851540236 * fTemp56)) - (0.11933776929999999 * fTemp58)));
			double fTemp152 = (fConst138 * fRec282[1]);
			double fTemp153 = (fConst139 * fRec285[1]);
			fRec287[0] = (fTemp151 + (fTemp152 + (fRec287[1] + fTemp153)));
			fRec285[0] = fRec287[0];
			double fRec286 = ((fTemp153 + fTemp152) + fTemp151);
			fRec284[0] = (fRec284[1] + fRec285[0]);
			fRec282[0] = fRec284[0];
			double fRec283 = fRec286;
			double fTemp154 = (fConst141 * fRec288[1]);
			double fTemp155 = (fConst143 * ((((0.025110278699999999 * fTemp44) + (0.087931494900000004 * fTemp41)) + (0.087989912000000003 * fTemp45)) - ((0.045469950199999998 * fTemp42) + (((0.1250849174 * fTemp40) + (0.1156332819 * fTemp43)) + (0.089101956699999998 * fTemp46)))));
			double fTemp156 = (fConst144 * fRec291[1]);
			double fTemp157 = (fConst145 * fRec294[1]);
			fRec296[0] = (fTemp155 + (fTemp156 + (fRec296[1] + fTemp157)));
			fRec294[0] = fRec296[0];
			double fRec295 = ((fTemp157 + fTemp156) + fTemp155);
			fRec293[0] = (fRec293[1] + fRec294[0]);
			fRec291[0] = fRec293[0];
			double fRec292 = fRec295;
			fRec290[0] = ((fRec290[1] + fTemp154) + fRec292);
			fRec288[0] = fRec290[0];
			double fRec289 = (fTemp154 + fRec292);
			double fTemp158 = (fConst148 * ((((0.021692717199999999 * fTemp27) + (0.080021927300000004 * fTemp31)) + (0.057866918900000001 * fTemp29)) - ((0.044902878299999997 * fTemp35) + ((0.0142117874 * fTemp34) + ((0.033516885500000003 * fTemp33) + (((0.015285743900000001 * fTemp32) + (0.031933873600000003 * fTemp28)) + (0.035626379999999999 * fTemp30)))))));
			double fTemp159 = (fConst149 * fRec303[1]);
			double fTemp160 = (fConst150 * fRec306[1]);
			fRec308[0] = (fTemp158 + (fTemp159 + (fRec308[1] + fTemp160)));
			fRec306[0] = fRec308[0];
			double fRec307 = ((fTemp160 + fTemp159) + fTemp158);
			fRec305[0] = (fRec305[1] + fRec306[0]);
			fRec303[0] = fRec305[0];
			double fRec304 = fRec307;
			double fTemp161 = (fConst151 * fRec297[1]);
			double fTemp162 = (fConst152 * fRec300[1]);
			fRec302[0] = (fRec304 + (fTemp161 + (fRec302[1] + fTemp162)));
			fRec300[0] = fRec302[0];
			double fRec301 = ((fTemp162 + fTemp161) + fRec304);
			fRec299[0] = (fRec299[1] + fRec300[0]);
			fRec297[0] = fRec299[0];
			double fRec298 = fRec301;
			fVec5[0] = (fRec265 + (((((0.1160592082 * fTemp24) + fRec280) + fRec283) + fRec289) + fRec298));
			output5[i] = FAUSTFLOAT((0.99644549763033174 * (fRec83[0] * fVec5[iConst153])));
			double fTemp163 = (fConst155 * fRec309[1]);
			double fTemp164 = (fConst157 * fRec312[1]);
			double fTemp165 = (fConst158 * fRec315[1]);
			double fTemp166 = (fConst160 * (((0.0271447909 * fTemp13) + ((0.047962184499999998 * fTemp14) + ((0.014758450399999999 * fTemp8) + (0.041430444199999999 * fTemp10)))) - ((0.0432676569 * fTemp17) + ((0.015678597700000001 * fTemp12) + ((0.0077126347999999997 * fTemp16) + ((0.0023113160999999999 * fTemp15) + ((0.057836635099999999 * fTemp11) + ((0.058356045199999998 * fTemp7) + (0.0053702265000000002 * fTemp9)))))))));
			double fTemp167 = (fConst161 * fRec318[1]);
			double fTemp168 = (fConst162 * fRec321[1]);
			fRec323[0] = (fTemp166 + (fTemp167 + (fRec323[1] + fTemp168)));
			fRec321[0] = fRec323[0];
			double fRec322 = ((fTemp168 + fTemp167) + fTemp166);
			fRec320[0] = (fRec321[0] + fRec320[1]);
			fRec318[0] = fRec320[0];
			double fRec319 = fRec322;
			fRec317[0] = (fTemp164 + (fTemp165 + (fRec319 + fRec317[1])));
			fRec315[0] = fRec317[0];
			double fRec316 = (fTemp164 + (fRec319 + fTemp165));
			fRec314[0] = (fRec315[0] + fRec314[1]);
			fRec312[0] = fRec314[0];
			double fRec313 = fRec316;
			fRec311[0] = (fTemp163 + (fRec313 + fRec311[1]));
			fRec309[0] = fRec311[0];
			double fRec310 = (fRec313 + fTemp163);
			double fTemp169 = (fConst164 * fRec324[1]);
			double fTemp170 = (fConst165 * fRec327[1]);
			double fTemp171 = (fConst167 * (((((0.018552197900000001 * fTemp32) + (0.031639782499999998 * fTemp28)) + (0.0345294399 * fTemp29)) + (0.0109543087 * fTemp34)) - (((0.0038074559999999999 * fTemp33) + (((0.025823548299999999 * fTemp27) + (0.079582109299999995 * fTemp31)) + (0.080901585499999998 * fTemp30))) + (0.064916298999999997 * fTemp35))));
			double fTemp172 = (fConst168 * fRec330[1]);
			double fTemp173 = (fConst169 * fRec333[1]);
			fRec335[0] = (fTemp171 + (fTemp172 + (fRec335[1] + fTemp173)));
			fRec333[0] = fRec335[0];
			double fRec334 = ((fTemp173 + fTemp172) + fTemp171);
			fRec332[0] = (fRec333[0] + fRec332[1]);
			fRec330[0] = fRec332[0];
			double fRec331 = fRec334;
			fRec329[0] = (fTemp169 + (fTemp170 + (fRec331 + fRec329[1])));
			fRec327[0] = fRec329[0];
			double fRec328 = (fTemp169 + (fRec331 + fTemp170));
			fRec326[0] = (fRec327[0] + fRec326[1]);
			fRec324[0] = fRec326[0];
			double fRec325 = fRec328;
			double fTemp174 = (fConst171 * fRec336[1]);
			double fTemp175 = (fConst173 * (((((0.1288453416 * fTemp40) + (0.1154320413 * fTemp43)) + (0.11373899580000001 * fTemp41)) + (0.050141783299999999 * fTemp45)) - ((0.011713232299999999 * fTemp42) + ((0.026655510699999999 * fTemp44) + (0.1159875168 * fTemp46)))));
			double fTemp176 = (fConst174 * fRec339[1]);
			double fTemp177 = (fConst175 * fRec342[1]);
			fRec344[0] = (fTemp175 + (fTemp176 + (fRec344[1] + fTemp177)));
			fRec342[0] = fRec344[0];
			double fRec343 = ((fTemp177 + fTemp176) + fTemp175);
			fRec341[0] = (fRec342[0] + fRec341[1]);
			fRec339[0] = fRec341[0];
			double fRec340 = fRec343;
			fRec338[0] = (fTemp174 + (fRec340 + fRec338[1]));
			fRec336[0] = fRec338[0];
			double fRec337 = (fRec340 + fTemp174);
			double fTemp178 = (fConst177 * (((0.18751301819999999 * fTemp59) + (0.14474790009999999 * fTemp56)) - (((0.1599267093 * fTemp55) + (0.071747772700000004 * fTemp57)) + (0.0916836548 * fTemp58))));
			double fTemp179 = (fConst178 * fRec345[1]);
			double fTemp180 = (fConst179 * fRec348[1]);
			fRec350[0] = (fTemp178 + (fTemp179 + (fRec350[1] + fTemp180)));
			fRec348[0] = fRec350[0];
			double fRec349 = ((fTemp180 + fTemp179) + fTemp178);
			fRec347[0] = (fRec348[0] + fRec347[1]);
			fRec345[0] = fRec347[0];
			double fRec346 = fRec349;
			double fTemp181 = (fConst181 * ((0.090707389299999996 * fTemp50) - ((0.10680840010000001 * fTemp52) + (0.22142668779999999 * fTemp51))));
			double fTemp182 = (fConst182 * fRec351[1]);
			fRec353[0] = (fTemp181 + (fRec353[1] + fTemp182));
			fRec351[0] = fRec353[0];
			double fRec352 = (fTemp182 + fTemp181);
			output6[i] = FAUSTFLOAT((fRec83[0] * (fRec310 + (fRec325 + (fRec337 + (fRec346 + (fRec352 + (0.1029711303 * fTemp24))))))));
			double fTemp183 = (fConst184 * ((0.17013778360000001 * fTemp50) - ((0.047348098999999998 * fTemp52) + (0.019605341599999999 * fTemp51))));
			double fTemp184 = (fConst185 * fRec354[1]);
			fRec356[0] = (fTemp183 + (fRec356[1] + fTemp184));
			fRec354[0] = fRec356[0];
			double fRec355 = (fTemp184 + fTemp183);
			double fTemp185 = (fConst187 * fRec357[1]);
			double fTemp186 = (fConst189 * fRec360[1]);
			double fTemp187 = (fConst190 * fRec363[1]);
			double fTemp188 = (fConst192 * (((0.0088832157000000005 * fTemp17) + ((0.061528725499999999 * fTemp13) + ((0.0195276884 * fTemp16) + ((0.080324536000000002 * fTemp11) + (0.0106525261 * fTemp8))))) - ((0.0051585262999999998 * fTemp12) + ((0.0551308311 * fTemp15) + ((0.073296437500000006 * fTemp14) + ((0.070327169999999994 * fTemp10) + ((0.0064259868999999997 * fTemp7) + (0.0025546904999999998 * fTemp9))))))));
			double fTemp189 = (fConst193 * fRec366[1]);
			double fTemp190 = (fConst194 * fRec369[1]);
			fRec371[0] = (fTemp188 + (fTemp189 + (fRec371[1] + fTemp190)));
			fRec369[0] = fRec371[0];
			double fRec370 = ((fTemp190 + fTemp189) + fTemp188);
			fRec368[0] = (fRec369[0] + fRec368[1]);
			fRec366[0] = fRec368[0];
			double fRec367 = fRec370;
			fRec365[0] = (fTemp186 + (fTemp187 + (fRec367 + fRec365[1])));
			fRec363[0] = fRec365[0];
			double fRec364 = (fTemp186 + (fRec367 + fTemp187));
			fRec362[0] = (fRec363[0] + fRec362[1]);
			fRec360[0] = fRec362[0];
			double fRec361 = fRec364;
			fRec359[0] = (fTemp185 + (fRec361 + fRec359[1]));
			fRec357[0] = fRec359[0];
			double fRec358 = (fRec361 + fTemp185);
			double fTemp191 = (fConst196 * fRec372[1]);
			double fTemp192 = (fConst197 * fRec375[1]);
			double fTemp193 = (fConst199 * ((((((((0.078868528199999996 * fTemp27) + (0.089738116800000003 * fTemp31)) + (0.0068999819000000002 * fTemp32)) + (0.017884395000000001 * fTemp28)) + (0.044623408699999999 * fTemp29)) + (0.044751381700000002 * fTemp33)) + (0.1374320983 * fTemp35)) - ((0.0062210538000000001 * fTemp30) + (0.047357726400000001 * fTemp34))));
			double fTemp194 = (fConst200 * fRec378[1]);
			double fTemp195 = (fConst201 * fRec381[1]);
			fRec383[0] = (fTemp193 + (fTemp194 + (fRec383[1] + fTemp195)));
			fRec381[0] = fRec383[0];
			double fRec382 = ((fTemp195 + fTemp194) + fTemp193);
			fRec380[0] = (fRec381[0] + fRec380[1]);
			fRec378[0] = fRec380[0];
			double fRec379 = fRec382;
			fRec377[0] = (fTemp191 + (fTemp192 + (fRec379 + fRec377[1])));
			fRec375[0] = fRec377[0];
			double fRec376 = (fTemp191 + (fRec379 + fTemp192));
			fRec374[0] = (fRec375[0] + fRec374[1]);
			fRec372[0] = fRec374[0];
			double fRec373 = fRec376;
			double fTemp196 = (fConst203 * ((0.014360447300000001 * fTemp59) - ((((0.046462565099999999 * fTemp55) + (0.094105577100000004 * fTemp57)) + (0.078846651599999998 * fTemp58)) + (0.19568197170000001 * fTemp56))));
			double fTemp197 = (fConst204 * fRec384[1]);
			double fTemp198 = (fConst205 * fRec387[1]);
			fRec389[0] = (fTemp196 + (fTemp197 + (fRec389[1] + fTemp198)));
			fRec387[0] = fRec389[0];
			double fRec388 = ((fTemp198 + fTemp197) + fTemp196);
			fRec386[0] = (fRec387[0] + fRec386[1]);
			fRec384[0] = fRec386[0];
			double fRec385 = fRec388;
			double fTemp199 = (fConst207 * fRec390[1]);
			double fTemp200 = (fConst209 * (((0.0688619548 * fTemp42) + ((0.099706104000000004 * fTemp46) + (((0.032357517000000002 * fTemp43) + (0.040238775800000001 * fTemp41)) + (0.0069236523999999999 * fTemp45)))) - ((0.18092477300000001 * fTemp40) + (0.075698066600000002 * fTemp44))));
			double fTemp201 = (fConst210 * fRec393[1]);
			double fTemp202 = (fConst211 * fRec396[1]);
			fRec398[0] = (fTemp200 + (fTemp201 + (fRec398[1] + fTemp202)));
			fRec396[0] = fRec398[0];
			double fRec397 = ((fTemp202 + fTemp201) + fTemp200);
			fRec395[0] = (fRec396[0] + fRec395[1]);
			fRec393[0] = fRec395[0];
			double fRec394 = fRec397;
			fRec392[0] = (fTemp199 + (fRec394 + fRec392[1]));
			fRec390[0] = fRec392[0];
			double fRec391 = (fRec394 + fTemp199);
			fVec6[(IOTA & 127)] = (fRec355 + ((0.066339076900000002 * fTemp24) + (fRec358 + (fRec373 + (fRec385 + fRec391)))));
			output7[i] = FAUSTFLOAT((0.96623222748815174 * (fRec83[0] * fVec6[((IOTA - iConst212) & 127)])));
			double fTemp203 = (fConst214 * fRec399[1]);
			double fTemp204 = (fConst216 * fRec402[1]);
			double fTemp205 = (fConst217 * fRec405[1]);
			double fTemp206 = (fConst219 * (((0.035503977399999997 * fTemp13) + ((0.025403881600000001 * fTemp12) + ((0.091739611200000001 * fTemp15) + ((0.051021464400000001 * fTemp14) + ((0.025854454900000001 * fTemp10) + ((0.0205616619 * fTemp7) + (0.0023119929 * fTemp9))))))) - ((0.033208484699999999 * fTemp17) + ((0.0067932315 * fTemp16) + ((0.0782867852 * fTemp11) + (0.023629601199999999 * fTemp8))))));
			double fTemp207 = (fConst220 * fRec408[1]);
			double fTemp208 = (fConst221 * fRec411[1]);
			fRec413[0] = (fTemp206 + (fTemp207 + (fRec413[1] + fTemp208)));
			fRec411[0] = fRec413[0];
			double fRec412 = ((fTemp208 + fTemp207) + fTemp206);
			fRec410[0] = (fRec411[0] + fRec410[1]);
			fRec408[0] = fRec410[0];
			double fRec409 = fRec412;
			fRec407[0] = (fTemp204 + (fTemp205 + (fRec409 + fRec407[1])));
			fRec405[0] = fRec407[0];
			double fRec406 = (fTemp204 + (fRec409 + fTemp205));
			fRec404[0] = (fRec405[0] + fRec404[1]);
			fRec402[0] = fRec404[0];
			double fRec403 = fRec406;
			fRec401[0] = (fTemp203 + (fRec403 + fRec401[1]));
			fRec399[0] = fRec401[0];
			double fRec400 = (fRec403 + fTemp203);
			double fTemp209 = (fConst223 * fRec414[1]);
			double fTemp210 = (fConst224 * fRec417[1]);
			double fTemp211 = (fConst226 * (((0.1249505309 * fTemp34) + ((0.0056518465 * fTemp33) + ((0.029010641 * fTemp30) + (((0.024312477700000001 * fTemp31) + (0.061462845199999998 * fTemp28)) + (0.0232632506 * fTemp29))))) - (((0.1256491914 * fTemp27) + (0.0161469165 * fTemp32)) + (0.054688413399999997 * fTemp35))));
			double fTemp212 = (fConst227 * fRec420[1]);
			double fTemp213 = (fConst228 * fRec423[1]);
			fRec425[0] = (fTemp211 + (fTemp212 + (fRec425[1] + fTemp213)));
			fRec423[0] = fRec425[0];
			double fRec424 = ((fTemp213 + fTemp212) + fTemp211);
			fRec422[0] = (fRec423[0] + fRec422[1]);
			fRec420[0] = fRec422[0];
			double fRec421 = fRec424;
			fRec419[0] = (fTemp209 + (fTemp210 + (fRec421 + fRec419[1])));
			fRec417[0] = fRec419[0];
			double fRec418 = (fTemp209 + (fRec421 + fTemp210));
			fRec416[0] = (fRec417[0] + fRec416[1]);
			fRec414[0] = fRec416[0];
			double fRec415 = fRec418;
			double fTemp214 = (fConst230 * fRec426[1]);
			double fTemp215 = (fConst232 * (((0.0732868468 * fTemp41) + (0.086214919299999998 * fTemp46)) - (((((0.0192019475 * fTemp40) + (0.1126769042 * fTemp43)) + (0.037870716399999997 * fTemp44)) + (0.021765649500000001 * fTemp45)) + (0.1688340958 * fTemp42))));
			double fTemp216 = (fConst233 * fRec429[1]);
			double fTemp217 = (fConst234 * fRec432[1]);
			fRec434[0] = (fTemp215 + (fTemp216 + (fRec434[1] + fTemp217)));
			fRec432[0] = fRec434[0];
			double fRec433 = ((fTemp217 + fTemp216) + fTemp215);
			fRec431[0] = (fRec432[0] + fRec431[1]);
			fRec429[0] = fRec431[0];
			double fRec430 = fRec433;
			fRec428[0] = (fTemp214 + (fRec430 + fRec428[1]));
			fRec426[0] = fRec428[0];
			double fRec427 = (fRec430 + fTemp214);
			double fTemp218 = (fConst236 * (((0.13906465509999999 * fTemp50) + (0.071811680500000002 * fTemp51)) - (0.063191711799999994 * fTemp52)));
			double fTemp219 = (fConst237 * fRec435[1]);
			fRec437[0] = (fTemp218 + (fRec437[1] + fTemp219));
			fRec435[0] = fRec437[0];
			double fRec436 = (fTemp219 + fTemp218);
			double fTemp220 = (fConst239 * ((0.1474027249 * fTemp55) - ((((0.1172591107 * fTemp57) + (0.059767500799999998 * fTemp58)) + (0.057936487699999997 * fTemp59)) + (0.10311647610000001 * fTemp56))));
			double fTemp221 = (fConst240 * fRec438[1]);
			double fTemp222 = (fConst241 * fRec441[1]);
			fRec443[0] = (fTemp220 + (fTemp221 + (fRec443[1] + fTemp222)));
			fRec441[0] = fRec443[0];
			double fRec442 = ((fTemp222 + fTemp221) + fTemp220);
			fRec440[0] = (fRec441[0] + fRec440[1]);
			fRec438[0] = fRec440[0];
			double fRec439 = fRec442;
			fVec7[(IOTA & 63)] = ((0.062088905799999997 * fTemp24) + (fRec400 + (fRec415 + (fRec427 + (fRec436 + fRec439)))));
			output8[i] = FAUSTFLOAT((0.976303317535545 * (fRec83[0] * fVec7[((IOTA - iConst242) & 63)])));
			double fTemp223 = (fConst244 * fRec444[1]);
			double fTemp224 = (fConst246 * fRec447[1]);
			double fTemp225 = (fConst247 * fRec450[1]);
			double fTemp226 = (fConst249 * (((0.050042484900000003 * fTemp17) + ((0.0099379075000000008 * fTemp15) + ((0.0187708605 * fTemp11) + (0.0041243275000000003 * fTemp8)))) - ((0.057571459800000002 * fTemp13) + ((0.037779891000000003 * fTemp12) + ((0.0045311796 * fTemp16) + ((0.028640035500000001 * fTemp14) + ((0.028811781799999998 * fTemp10) + ((0.024945784700000001 * fTemp7) + (0.049170006099999997 * fTemp9)))))))));
			double fTemp227 = (fConst250 * fRec453[1]);
			double fTemp228 = (fConst251 * fRec456[1]);
			fRec458[0] = (fTemp226 + (fTemp227 + (fRec458[1] + fTemp228)));
			fRec456[0] = fRec458[0];
			double fRec457 = ((fTemp228 + fTemp227) + fTemp226);
			fRec455[0] = (fRec456[0] + fRec455[1]);
			fRec453[0] = fRec455[0];
			double fRec454 = fRec457;
			fRec452[0] = (fTemp224 + (fTemp225 + (fRec454 + fRec452[1])));
			fRec450[0] = fRec452[0];
			double fRec451 = (fTemp224 + (fRec454 + fTemp225));
			fRec449[0] = (fRec450[0] + fRec449[1]);
			fRec447[0] = fRec449[0];
			double fRec448 = fRec451;
			fRec446[0] = (fTemp223 + (fRec448 + fRec446[1]));
			fRec444[0] = fRec446[0];
			double fRec445 = (fRec448 + fTemp223);
			double fTemp229 = (fConst253 * fRec459[1]);
			double fTemp230 = (fConst254 * fRec462[1]);
			double fTemp231 = (fConst256 * ((((0.0084924435000000003 * fTemp27) + (0.0127175338 * fTemp31)) + (0.062936954000000003 * fTemp32)) - ((0.020033959300000001 * fTemp35) + ((0.095813404800000002 * fTemp34) + ((0.057987137699999997 * fTemp33) + (((0.089113862700000004 * fTemp28) + (0.067298309099999995 * fTemp29)) + (0.057727214800000003 * fTemp30)))))));
			double fTemp232 = (fConst257 * fRec465[1]);
			double fTemp233 = (fConst258 * fRec468[1]);
			fRec470[0] = (fTemp231 + (fTemp232 + (fRec470[1] + fTemp233)));
			fRec468[0] = fRec470[0];
			double fRec469 = ((fTemp233 + fTemp232) + fTemp231);
			fRec467[0] = (fRec468[0] + fRec467[1]);
			fRec465[0] = fRec467[0];
			double fRec466 = fRec469;
			fRec464[0] = (fTemp229 + (fTemp230 + (fRec466 + fRec464[1])));
			fRec462[0] = fRec464[0];
			double fRec463 = (fTemp229 + (fRec466 + fTemp230));
			fRec461[0] = (fRec462[0] + fRec461[1]);
			fRec459[0] = fRec461[0];
			double fRec460 = fRec463;
			double fTemp234 = (fConst260 * fRec471[1]);
			double fTemp235 = (fConst262 * (((((0.0150232113 * fTemp40) + (0.1684605954 * fTemp43)) + (0.061687161999999997 * fTemp44)) + (0.020588946899999998 * fTemp45)) - ((0.074565956399999994 * fTemp42) + ((0.1386495076 * fTemp41) + (0.10387041750000001 * fTemp46)))));
			double fTemp236 = (fConst263 * fRec474[1]);
			double fTemp237 = (fConst264 * fRec477[1]);
			fRec479[0] = (fTemp235 + (fTemp236 + (fRec479[1] + fTemp237)));
			fRec477[0] = fRec479[0];
			double fRec478 = ((fTemp237 + fTemp236) + fTemp235);
			fRec476[0] = (fRec477[0] + fRec476[1]);
			fRec474[0] = fRec476[0];
			double fRec475 = fRec478;
			fRec473[0] = (fTemp234 + (fRec475 + fRec473[1]));
			fRec471[0] = fRec473[0];
			double fRec472 = (fRec475 + fTemp234);
			double fTemp238 = (fConst266 * (((0.1665574608 * fTemp50) + (0.13067427819999999 * fTemp52)) + (0.0935620759 * fTemp51)));
			double fTemp239 = (fConst267 * fRec480[1]);
			fRec482[0] = (fTemp238 + (fRec482[1] + fTemp239));
			fRec480[0] = fRec482[0];
			double fRec481 = (fTemp239 + fTemp238);
			double fTemp240 = (fConst269 * ((((0.1364947024 * fTemp55) + (0.2161483619 * fTemp57)) + (0.11459543260000001 * fTemp59)) - ((0.0222443105 * fTemp58) + (0.074978250199999999 * fTemp56))));
			double fTemp241 = (fConst270 * fRec483[1]);
			double fTemp242 = (fConst271 * fRec486[1]);
			fRec488[0] = (fTemp240 + (fTemp241 + (fRec488[1] + fTemp242)));
			fRec486[0] = fRec488[0];
			double fRec487 = ((fTemp242 + fTemp241) + fTemp240);
			fRec485[0] = (fRec486[0] + fRec485[1]);
			fRec483[0] = fRec485[0];
			double fRec484 = fRec487;
			fVec8[(IOTA & 255)] = ((0.088519252100000001 * fTemp24) + (fRec445 + (fRec460 + (fRec472 + (fRec481 + fRec484)))));
			output9[i] = FAUSTFLOAT((0.89454976303317535 * (fRec83[0] * fVec8[((IOTA - iConst272) & 255)])));
			double fTemp243 = (fConst244 * fRec489[1]);
			double fTemp244 = (fConst246 * fRec492[1]);
			double fTemp245 = (fConst247 * fRec495[1]);
			double fTemp246 = (fConst249 * (((0.050079503999999997 * fTemp17) + ((0.057556836899999998 * fTemp13) + ((0.037778500299999997 * fTemp12) + ((0.0045570623000000003 * fTemp16) + (0.0041745345000000003 * fTemp8))))) - ((0.0099222065000000009 * fTemp15) + ((0.0186942924 * fTemp11) + ((0.028620200500000002 * fTemp14) + ((0.028834764999999998 * fTemp10) + ((0.024951984900000002 * fTemp7) + (0.049150509699999997 * fTemp9))))))));
			double fTemp247 = (fConst250 * fRec498[1]);
			double fTemp248 = (fConst251 * fRec501[1]);
			fRec503[0] = (fTemp246 + (fTemp247 + (fRec503[1] + fTemp248)));
			fRec501[0] = fRec503[0];
			double fRec502 = ((fTemp248 + fTemp247) + fTemp246);
			fRec500[0] = (fRec501[0] + fRec500[1]);
			fRec498[0] = fRec500[0];
			double fRec499 = fRec502;
			fRec497[0] = (fTemp244 + (fTemp245 + (fRec499 + fRec497[1])));
			fRec495[0] = fRec497[0];
			double fRec496 = (fTemp244 + (fRec499 + fTemp245));
			fRec494[0] = (fRec495[0] + fRec494[1]);
			fRec492[0] = fRec494[0];
			double fRec493 = fRec496;
			fRec491[0] = (fTemp243 + (fRec493 + fRec491[1]));
			fRec489[0] = fRec491[0];
			double fRec490 = (fRec493 + fTemp243);
			double fTemp249 = (fConst253 * fRec504[1]);
			double fTemp250 = (fConst254 * fRec507[1]);
			double fTemp251 = (fConst256 * ((0.089165655199999999 * fTemp28) - ((0.020095910000000002 * fTemp35) + ((0.095829692199999997 * fTemp34) + ((0.057971763000000003 * fTemp33) + (((((0.0084682017000000005 * fTemp27) + (0.0126992371 * fTemp31)) + (0.062927876399999999 * fTemp32)) + (0.067285445999999999 * fTemp29)) + (0.057723311100000001 * fTemp30)))))));
			double fTemp252 = (fConst257 * fRec510[1]);
			double fTemp253 = (fConst258 * fRec513[1]);
			fRec515[0] = (fTemp251 + (fTemp252 + (fRec515[1] + fTemp253)));
			fRec513[0] = fRec515[0];
			double fRec514 = ((fTemp253 + fTemp252) + fTemp251);
			fRec512[0] = (fRec513[0] + fRec512[1]);
			fRec510[0] = fRec512[0];
			double fRec511 = fRec514;
			fRec509[0] = (fTemp249 + (fTemp250 + (fRec511 + fRec509[1])));
			fRec507[0] = fRec509[0];
			double fRec508 = (fTemp249 + (fRec511 + fTemp250));
			fRec506[0] = (fRec507[0] + fRec506[1]);
			fRec504[0] = fRec506[0];
			double fRec505 = fRec508;
			double fTemp254 = (fConst260 * fRec516[1]);
			double fTemp255 = (fConst262 * ((0.020590229500000001 * fTemp45) - ((0.074600429300000007 * fTemp42) + (((((0.015033603899999999 * fTemp40) + (0.16846785619999999 * fTemp43)) + (0.061652947299999997 * fTemp44)) + (0.1386807373 * fTemp41)) + (0.1039026634 * fTemp46)))));
			double fTemp256 = (fConst263 * fRec519[1]);
			double fTemp257 = (fConst264 * fRec522[1]);
			fRec524[0] = (fTemp255 + (fTemp256 + (fRec524[1] + fTemp257)));
			fRec522[0] = fRec524[0];
			double fRec523 = ((fTemp257 + fTemp256) + fTemp255);
			fRec521[0] = (fRec522[0] + fRec521[1]);
			fRec519[0] = fRec521[0];
			double fRec520 = fRec523;
			fRec518[0] = (fTemp254 + (fRec520 + fRec518[1]));
			fRec516[0] = fRec518[0];
			double fRec517 = (fRec520 + fTemp254);
			double fTemp258 = (fConst266 * (((0.13068048069999999 * fTemp52) + (0.093565142500000004 * fTemp51)) - (0.166590408 * fTemp50)));
			double fTemp259 = (fConst267 * fRec525[1]);
			fRec527[0] = (fTemp258 + (fRec527[1] + fTemp259));
			fRec525[0] = fRec527[0];
			double fRec526 = (fTemp259 + fTemp258);
			double fTemp260 = (fConst269 * ((0.1145968222 * fTemp59) - ((((0.136514002 * fTemp55) + (0.21617194910000001 * fTemp57)) + (0.022271674200000001 * fTemp58)) + (0.075009252900000004 * fTemp56))));
			double fTemp261 = (fConst270 * fRec528[1]);
			double fTemp262 = (fConst271 * fRec531[1]);
			fRec533[0] = (fTemp260 + (fTemp261 + (fRec533[1] + fTemp262)));
			fRec531[0] = fRec533[0];
			double fRec532 = ((fTemp262 + fTemp261) + fTemp260);
			fRec530[0] = (fRec531[0] + fRec530[1]);
			fRec528[0] = fRec530[0];
			double fRec529 = fRec532;
			fVec9[(IOTA & 255)] = ((0.088530002999999996 * fTemp24) + (fRec490 + (fRec505 + (fRec517 + (fRec526 + fRec529)))));
			output10[i] = FAUSTFLOAT((0.89454976303317535 * (fRec83[0] * fVec9[((IOTA - iConst272) & 255)])));
			double fTemp263 = (fConst274 * fRec534[1]);
			double fTemp264 = (fConst276 * fRec537[1]);
			double fTemp265 = (fConst277 * fRec540[1]);
			double fTemp266 = (fConst279 * (((0.0067885934999999996 * fTemp17) + ((0.073109085500000004 * fTemp13) + ((0.0053612686 * fTemp16) + ((0.0169697485 * fTemp11) + (((0.079771473999999995 * fTemp7) + (0.0231489112 * fTemp8)) + (0.0134027451 * fTemp10)))))) - ((0.025002611300000002 * fTemp12) + ((0.011043593399999999 * fTemp15) + ((0.026884691499999998 * fTemp9) + (0.0021474427000000001 * fTemp14))))));
			double fTemp267 = (fConst280 * fRec543[1]);
			double fTemp268 = (fConst281 * fRec546[1]);
			fRec548[0] = (fTemp266 + (fTemp267 + (fRec548[1] + fTemp268)));
			fRec546[0] = fRec548[0];
			double fRec547 = ((fTemp268 + fTemp267) + fTemp266);
			fRec545[0] = (fRec546[0] + fRec545[1]);
			fRec543[0] = fRec545[0];
			double fRec544 = fRec547;
			fRec542[0] = (fTemp264 + (fTemp265 + (fRec544 + fRec542[1])));
			fRec540[0] = fRec542[0];
			double fRec541 = (fTemp264 + (fRec544 + fTemp265));
			fRec539[0] = (fRec540[0] + fRec539[1]);
			fRec537[0] = fRec539[0];
			double fRec538 = fRec541;
			fRec536[0] = (fTemp263 + (fRec538 + fRec536[1]));
			fRec534[0] = fRec536[0];
			double fRec535 = (fRec538 + fTemp263);
			double fTemp269 = (fConst283 * fRec549[1]);
			double fTemp270 = (fConst284 * fRec552[1]);
			double fTemp271 = (fConst286 * (((0.029204994500000001 * fTemp34) + ((0.014930674499999999 * fTemp33) + (((0.073546635099999993 * fTemp32) + (0.065547893600000004 * fTemp28)) + (0.046854595899999997 * fTemp30)))) - ((((0.019893196200000001 * fTemp27) + (0.0069740430999999997 * fTemp31)) + (0.13295343579999999 * fTemp29)) + (0.0068394559999999998 * fTemp35))));
			double fTemp272 = (fConst287 * fRec555[1]);
			double fTemp273 = (fConst288 * fRec558[1]);
			fRec560[0] = (fTemp271 + (fTemp272 + (fRec560[1] + fTemp273)));
			fRec558[0] = fRec560[0];
			double fRec559 = ((fTemp273 + fTemp272) + fTemp271);
			fRec557[0] = (fRec558[0] + fRec557[1]);
			fRec555[0] = fRec557[0];
			double fRec556 = fRec559;
			fRec554[0] = (fTemp269 + (fTemp270 + (fRec556 + fRec554[1])));
			fRec552[0] = fRec554[0];
			double fRec553 = (fTemp269 + (fRec556 + fTemp270));
			fRec551[0] = (fRec552[0] + fRec551[1]);
			fRec549[0] = fRec551[0];
			double fRec550 = fRec553;
			double fTemp274 = (fConst290 * fRec561[1]);
			double fTemp275 = (fConst292 * (((0.1580468843 * fTemp43) + (0.042767804999999999 * fTemp42)) - (((((0.0087817833000000001 * fTemp40) + (0.083954024000000002 * fTemp44)) + (0.15229090349999999 * fTemp41)) + (0.097828076299999997 * fTemp45)) + (0.013926621199999999 * fTemp46))));
			double fTemp276 = (fConst293 * fRec564[1]);
			double fTemp277 = (fConst294 * fRec567[1]);
			fRec569[0] = (fTemp275 + (fTemp276 + (fRec569[1] + fTemp277)));
			fRec567[0] = fRec569[0];
			double fRec568 = ((fTemp277 + fTemp276) + fTemp275);
			fRec566[0] = (fRec567[0] + fRec566[1]);
			fRec564[0] = fRec566[0];
			double fRec565 = fRec568;
			fRec563[0] = (fTemp274 + (fRec565 + fRec563[1]));
			fRec561[0] = fRec563[0];
			double fRec562 = (fRec565 + fTemp274);
			double fTemp278 = (fConst296 * ((0.17058547609999999 * fTemp52) - ((0.1453717595 * fTemp50) + (0.1316162437 * fTemp51))));
			double fTemp279 = (fConst297 * fRec570[1]);
			fRec572[0] = (fTemp278 + (fRec572[1] + fTemp279));
			fRec570[0] = fRec572[0];
			double fRec571 = (fTemp279 + fTemp278);
			double fTemp280 = (fConst299 * (((0.1199590024 * fTemp55) + (0.015661929599999999 * fTemp58)) - (((0.20402777420000001 * fTemp57) + (0.19494619390000001 * fTemp59)) + (0.020568303900000001 * fTemp56))));
			double fTemp281 = (fConst300 * fRec573[1]);
			double fTemp282 = (fConst301 * fRec576[1]);
			fRec578[0] = (fTemp280 + (fTemp281 + (fRec578[1] + fTemp282)));
			fRec576[0] = fRec578[0];
			double fRec577 = ((fTemp282 + fTemp281) + fTemp280);
			fRec575[0] = (fRec576[0] + fRec575[1]);
			fRec573[0] = fRec575[0];
			double fRec574 = fRec577;
			fVec10[(IOTA & 255)] = (fRec535 + ((0.1026666754 * fTemp24) + (fRec550 + (fRec562 + (fRec571 + fRec574)))));
			output11[i] = FAUSTFLOAT((0.90343601895734593 * (fRec83[0] * fVec10[((IOTA - iConst302) & 255)])));
			double fTemp283 = (fConst244 * fRec579[1]);
			double fTemp284 = (fConst246 * fRec582[1]);
			double fTemp285 = (fConst247 * fRec585[1]);
			double fTemp286 = (fConst251 * fRec591[1]);
			double fTemp287 = (fConst250 * fRec588[1]);
			double fTemp288 = (fConst249 * (((0.052661865400000001 * fTemp17) + ((0.021828078599999998 * fTemp12) + ((0.01517285 * fTemp15) + ((0.050580007400000002 * fTemp7) + (0.0341549939 * fTemp10))))) - ((0.072281232299999998 * fTemp13) + ((0.0061973150000000001 * fTemp16) + ((0.018952008900000001 * fTemp11) + (((0.027531791 * fTemp8) + (0.0064851172000000004 * fTemp9)) + (0.0073202327999999997 * fTemp14)))))));
			fRec593[0] = (((fRec593[1] + fTemp286) + fTemp287) + fTemp288);
			fRec591[0] = fRec593[0];
			double fRec592 = ((fTemp286 + fTemp287) + fTemp288);
			fRec590[0] = (fRec591[0] + fRec590[1]);
			fRec588[0] = fRec590[0];
			double fRec589 = fRec592;
			fRec587[0] = (fTemp284 + (fTemp285 + (fRec589 + fRec587[1])));
			fRec585[0] = fRec587[0];
			double fRec586 = (fTemp284 + (fRec589 + fTemp285));
			fRec584[0] = (fRec585[0] + fRec584[1]);
			fRec582[0] = fRec584[0];
			double fRec583 = fRec586;
			fRec581[0] = (fTemp283 + (fRec583 + fRec581[1]));
			fRec579[0] = fRec581[0];
			double fRec580 = (fRec583 + fTemp283);
			double fTemp289 = (fConst253 * fRec594[1]);
			double fTemp290 = (fConst254 * fRec597[1]);
			double fTemp291 = (fConst256 * (((0.0156817967 * fTemp35) + ((((0.022392501400000001 * fTemp27) + (0.0034274994999999998 * fTemp31)) + (0.097554315200000005 * fTemp30)) + (0.00036036919999999999 * fTemp34))) - ((((0.0735171357 * fTemp32) + (0.063931763000000003 * fTemp28)) + (0.1044722835 * fTemp29)) + (0.020261881799999999 * fTemp33))));
			double fTemp292 = (fConst257 * fRec600[1]);
			double fTemp293 = (fConst258 * fRec603[1]);
			fRec605[0] = (fTemp291 + (fTemp292 + (fRec605[1] + fTemp293)));
			fRec603[0] = fRec605[0];
			double fRec604 = ((fTemp293 + fTemp292) + fTemp291);
			fRec602[0] = (fRec603[0] + fRec602[1]);
			fRec600[0] = fRec602[0];
			double fRec601 = fRec604;
			fRec599[0] = (fTemp289 + (fTemp290 + (fRec601 + fRec599[1])));
			fRec597[0] = fRec599[0];
			double fRec598 = (fTemp289 + (fRec601 + fTemp290));
			fRec596[0] = (fRec597[0] + fRec596[1]);
			fRec594[0] = fRec596[0];
			double fRec595 = fRec598;
			double fTemp294 = (fConst260 * fRec606[1]);
			double fTemp295 = (fConst262 * (((0.0040371770999999999 * fTemp42) + (((0.0064021082000000002 * fTemp40) + (0.084273836699999993 * fTemp44)) + (0.016298420000000001 * fTemp46))) - (((0.1557890331 * fTemp43) + (0.1810311443 * fTemp41)) + (0.053133621300000003 * fTemp45))));
			double fTemp296 = (fConst263 * fRec609[1]);
			double fTemp297 = (fConst264 * fRec612[1]);
			fRec614[0] = (fTemp295 + (fTemp296 + (fRec614[1] + fTemp297)));
			fRec612[0] = fRec614[0];
			double fRec613 = ((fTemp297 + fTemp296) + fTemp295);
			fRec611[0] = (fRec612[0] + fRec611[1]);
			fRec609[0] = fRec611[0];
			double fRec610 = fRec613;
			fRec608[0] = (fTemp294 + (fRec610 + fRec608[1]));
			fRec606[0] = fRec608[0];
			double fRec607 = (fRec610 + fTemp294);
			double fTemp298 = (fConst269 * (((0.2031679069 * fTemp57) + (0.026076293699999999 * fTemp56)) - (((0.118283712 * fTemp55) + (0.016646586000000001 * fTemp58)) + (0.21906306079999999 * fTemp59))));
			double fTemp299 = (fConst270 * fRec615[1]);
			double fTemp300 = (fConst271 * fRec618[1]);
			fRec620[0] = (fTemp298 + (fTemp299 + (fRec620[1] + fTemp300)));
			fRec618[0] = fRec620[0];
			double fRec619 = ((fTemp300 + fTemp299) + fTemp298);
			fRec617[0] = (fRec618[0] + fRec617[1]);
			fRec615[0] = fRec617[0];
			double fRec616 = fRec619;
			double fTemp301 = (fConst266 * (((0.1446583713 * fTemp50) + (0.1797626873 * fTemp52)) - (0.17287215340000001 * fTemp51)));
			double fTemp302 = (fConst267 * fRec621[1]);
			fRec623[0] = (fTemp301 + (fRec623[1] + fTemp302));
			fRec621[0] = fRec623[0];
			double fRec622 = (fTemp302 + fTemp301);
			fVec11[(IOTA & 255)] = (fRec580 + (fRec595 + (fRec607 + (fRec616 + (fRec622 + (0.1177838765 * fTemp24))))));
			output12[i] = FAUSTFLOAT((0.89454976303317535 * (fRec83[0] * fVec11[((IOTA - iConst272) & 255)])));
			double fTemp303 = (fConst304 * fRec624[1]);
			double fTemp304 = (fConst305 * fRec627[1]);
			double fTemp305 = (fConst307 * (((0.0082696268000000007 * fTemp35) + ((0.050319459900000002 * fTemp34) + ((((2.7742700000000001e-05 * fTemp27) + (6.1817999999999998e-06 * fTemp32)) + (1.1138700000000001e-05 * fTemp28)) + (0.036878174100000001 * fTemp33)))) - (((9.5310000000000003e-07 * fTemp31) + (0.003197999 * fTemp29)) + (0.027137660500000001 * fTemp30))));
			double fTemp306 = (fConst308 * fRec630[1]);
			double fTemp307 = (fConst309 * fRec633[1]);
			fRec635[0] = (fTemp305 + (fTemp306 + (fRec635[1] + fTemp307)));
			fRec633[0] = fRec635[0];
			double fRec634 = ((fTemp307 + fTemp306) + fTemp305);
			fRec632[0] = (fRec633[0] + fRec632[1]);
			fRec630[0] = fRec632[0];
			double fRec631 = fRec634;
			fRec629[0] = (fTemp303 + (fTemp304 + (fRec631 + fRec629[1])));
			fRec627[0] = fRec629[0];
			double fRec628 = (fTemp303 + (fRec631 + fTemp304));
			fRec626[0] = (fRec627[0] + fRec626[1]);
			fRec624[0] = fRec626[0];
			double fRec625 = fRec628;
			double fTemp308 = (fConst311 * fRec636[1]);
			double fTemp309 = (fConst313 * (((0.0338496265 * fTemp42) + ((0.0615261644 * fTemp46) + ((((4.714e-07 * fTemp43) + (3.0709999999999999e-06 * fTemp44)) + (0.1787424624 * fTemp41)) + (0.024744043800000001 * fTemp45)))) - (3.9832000000000003e-06 * fTemp40)));
			double fTemp310 = (fConst314 * fRec639[1]);
			double fTemp311 = (fConst315 * fRec642[1]);
			fRec644[0] = (fTemp309 + (fTemp310 + (fRec644[1] + fTemp311)));
			fRec642[0] = fRec644[0];
			double fRec643 = ((fTemp311 + fTemp310) + fTemp309);
			fRec641[0] = (fRec642[0] + fRec641[1]);
			fRec639[0] = fRec641[0];
			double fRec640 = fRec643;
			fRec638[0] = (fTemp308 + (fRec640 + fRec638[1]));
			fRec636[0] = fRec638[0];
			double fRec637 = (fRec640 + fTemp308);
			double fTemp312 = (fConst317 * ((((0.36514337340000003 * fTemp58) + (0.059594921600000003 * fTemp59)) + (0.041716031000000001 * fTemp56)) - ((2.4679000000000001e-06 * fTemp55) + (6.1646999999999996e-06 * fTemp57))));
			double fTemp313 = (fConst318 * fRec645[1]);
			double fTemp314 = (fConst319 * fRec648[1]);
			fRec650[0] = (fTemp312 + (fTemp313 + (fRec650[1] + fTemp314)));
			fRec648[0] = fRec650[0];
			double fRec649 = ((fTemp314 + fTemp313) + fTemp312);
			fRec647[0] = (fRec648[0] + fRec647[1]);
			fRec645[0] = fRec647[0];
			double fRec646 = fRec649;
			double fTemp315 = (fConst321 * (((0.38405163489999999 * fTemp52) + (0.041088315100000002 * fTemp51)) - (5.9954000000000002e-06 * fTemp50)));
			double fTemp316 = (fConst322 * fRec651[1]);
			fRec653[0] = (fTemp315 + (fRec653[1] + fTemp316));
			fRec651[0] = fRec653[0];
			double fRec652 = (fTemp316 + fTemp315);
			double fTemp317 = (fConst324 * fRec654[1]);
			double fTemp318 = (fConst326 * fRec657[1]);
			double fTemp319 = (fConst327 * fRec660[1]);
			double fTemp320 = (fConst329 * (((6.3995000000000003e-06 * fTemp13) + ((5.9410000000000004e-06 * fTemp12) + ((4.4478e-06 * fTemp16) + ((4.6119799999999998e-05 * fTemp15) + ((0.012039283 * fTemp14) + ((0.034177886900000003 * fTemp9) + (0.0049527130999999997 * fTemp10))))))) - ((0.0705372051 * fTemp17) + ((2.1674800000000001e-05 * fTemp11) + ((0.039893782599999997 * fTemp7) + (0.0079828107000000006 * fTemp8))))));
			double fTemp321 = (fConst330 * fRec663[1]);
			double fTemp322 = (fConst331 * fRec666[1]);
			fRec668[0] = (fTemp320 + (fTemp321 + (fRec668[1] + fTemp322)));
			fRec666[0] = fRec668[0];
			double fRec667 = ((fTemp322 + fTemp321) + fTemp320);
			fRec665[0] = (fRec666[0] + fRec665[1]);
			fRec663[0] = fRec665[0];
			double fRec664 = fRec667;
			fRec662[0] = (fTemp318 + (fTemp319 + (fRec664 + fRec662[1])));
			fRec660[0] = fRec662[0];
			double fRec661 = (fTemp318 + (fRec664 + fTemp319));
			fRec659[0] = (fRec660[0] + fRec659[1]);
			fRec657[0] = fRec659[0];
			double fRec658 = fRec661;
			fRec656[0] = (fTemp317 + (fRec658 + fRec656[1]));
			fRec654[0] = fRec656[0];
			double fRec655 = (fRec658 + fTemp317);
			fVec12[(IOTA & 1023)] = (fRec625 + (fRec637 + (fRec646 + (fRec652 + (fRec655 + (0.1654347686 * fTemp24))))));
			output13[i] = FAUSTFLOAT((0.47393364928909959 * (fRec83[0] * fVec12[((IOTA - iConst332) & 1023)])));
			fRec16[1] = fRec16[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec17[1] = fRec17[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fRec21[2] = fRec21[1];
			fRec21[1] = fRec21[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
			fRec23[2] = fRec23[1];
			fRec23[1] = fRec23[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec27[2] = fRec27[1];
			fRec27[1] = fRec27[0];
			fRec14[1] = fRec14[0];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			fRec9[1] = fRec9[0];
			fRec8[1] = fRec8[0];
			fRec6[1] = fRec6[0];
			fRec5[1] = fRec5[0];
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			fRec0[1] = fRec0[0];
			fRec28[2] = fRec28[1];
			fRec28[1] = fRec28[0];
			fRec41[2] = fRec41[1];
			fRec41[1] = fRec41[0];
			fRec42[2] = fRec42[1];
			fRec42[1] = fRec42[0];
			fRec43[2] = fRec43[1];
			fRec43[1] = fRec43[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec46[2] = fRec46[1];
			fRec46[1] = fRec46[0];
			fRec47[2] = fRec47[1];
			fRec47[1] = fRec47[0];
			fRec48[2] = fRec48[1];
			fRec48[1] = fRec48[0];
			fRec49[2] = fRec49[1];
			fRec49[1] = fRec49[0];
			fRec40[1] = fRec40[0];
			fRec38[1] = fRec38[0];
			fRec37[1] = fRec37[0];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			fRec32[1] = fRec32[0];
			fRec31[1] = fRec31[0];
			fRec29[1] = fRec29[0];
			fRec59[2] = fRec59[1];
			fRec59[1] = fRec59[0];
			fRec60[2] = fRec60[1];
			fRec60[1] = fRec60[0];
			fRec61[2] = fRec61[1];
			fRec61[1] = fRec61[0];
			fRec62[2] = fRec62[1];
			fRec62[1] = fRec62[0];
			fRec63[2] = fRec63[1];
			fRec63[1] = fRec63[0];
			fRec64[2] = fRec64[1];
			fRec64[1] = fRec64[0];
			fRec65[2] = fRec65[1];
			fRec65[1] = fRec65[0];
			fRec58[1] = fRec58[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec53[1] = fRec53[0];
			fRec52[1] = fRec52[0];
			fRec50[1] = fRec50[0];
			fRec69[2] = fRec69[1];
			fRec69[1] = fRec69[0];
			fRec70[2] = fRec70[1];
			fRec70[1] = fRec70[0];
			fRec71[2] = fRec71[1];
			fRec71[1] = fRec71[0];
			fRec68[1] = fRec68[0];
			fRec66[1] = fRec66[0];
			fRec78[2] = fRec78[1];
			fRec78[1] = fRec78[0];
			fRec79[2] = fRec79[1];
			fRec79[1] = fRec79[0];
			fRec80[2] = fRec80[1];
			fRec80[1] = fRec80[0];
			fRec81[2] = fRec81[1];
			fRec81[1] = fRec81[0];
			fRec82[2] = fRec82[1];
			fRec82[1] = fRec82[0];
			fRec77[1] = fRec77[0];
			fRec75[1] = fRec75[0];
			fRec74[1] = fRec74[0];
			fRec72[1] = fRec72[0];
			IOTA = (IOTA + 1);
			fRec83[1] = fRec83[0];
			fRec86[1] = fRec86[0];
			fRec84[1] = fRec84[0];
			fRec92[1] = fRec92[0];
			fRec90[1] = fRec90[0];
			fRec89[1] = fRec89[0];
			fRec87[1] = fRec87[0];
			fRec101[1] = fRec101[0];
			fRec99[1] = fRec99[0];
			fRec98[1] = fRec98[0];
			fRec96[1] = fRec96[0];
			fRec95[1] = fRec95[0];
			fRec93[1] = fRec93[0];
			fRec113[1] = fRec113[0];
			fRec111[1] = fRec111[0];
			fRec110[1] = fRec110[0];
			fRec108[1] = fRec108[0];
			fRec107[1] = fRec107[0];
			fRec105[1] = fRec105[0];
			fRec104[1] = fRec104[0];
			fRec102[1] = fRec102[0];
			fRec128[1] = fRec128[0];
			fRec126[1] = fRec126[0];
			fRec125[1] = fRec125[0];
			fRec123[1] = fRec123[0];
			fRec122[1] = fRec122[0];
			fRec120[1] = fRec120[0];
			fRec119[1] = fRec119[0];
			fRec117[1] = fRec117[0];
			fRec116[1] = fRec116[0];
			fRec114[1] = fRec114[0];
			fRec131[1] = fRec131[0];
			fRec129[1] = fRec129[0];
			fRec137[1] = fRec137[0];
			fRec135[1] = fRec135[0];
			fRec134[1] = fRec134[0];
			fRec132[1] = fRec132[0];
			fRec146[1] = fRec146[0];
			fRec144[1] = fRec144[0];
			fRec143[1] = fRec143[0];
			fRec141[1] = fRec141[0];
			fRec140[1] = fRec140[0];
			fRec138[1] = fRec138[0];
			fRec158[1] = fRec158[0];
			fRec156[1] = fRec156[0];
			fRec155[1] = fRec155[0];
			fRec153[1] = fRec153[0];
			fRec152[1] = fRec152[0];
			fRec150[1] = fRec150[0];
			fRec149[1] = fRec149[0];
			fRec147[1] = fRec147[0];
			fRec173[1] = fRec173[0];
			fRec171[1] = fRec171[0];
			fRec170[1] = fRec170[0];
			fRec168[1] = fRec168[0];
			fRec167[1] = fRec167[0];
			fRec165[1] = fRec165[0];
			fRec164[1] = fRec164[0];
			fRec162[1] = fRec162[0];
			fRec161[1] = fRec161[0];
			fRec159[1] = fRec159[0];
			fRec176[1] = fRec176[0];
			fRec174[1] = fRec174[0];
			fRec182[1] = fRec182[0];
			fRec180[1] = fRec180[0];
			fRec179[1] = fRec179[0];
			fRec177[1] = fRec177[0];
			fRec191[1] = fRec191[0];
			fRec189[1] = fRec189[0];
			fRec188[1] = fRec188[0];
			fRec186[1] = fRec186[0];
			fRec185[1] = fRec185[0];
			fRec183[1] = fRec183[0];
			fRec203[1] = fRec203[0];
			fRec201[1] = fRec201[0];
			fRec200[1] = fRec200[0];
			fRec198[1] = fRec198[0];
			fRec197[1] = fRec197[0];
			fRec195[1] = fRec195[0];
			fRec194[1] = fRec194[0];
			fRec192[1] = fRec192[0];
			fRec218[1] = fRec218[0];
			fRec216[1] = fRec216[0];
			fRec215[1] = fRec215[0];
			fRec213[1] = fRec213[0];
			fRec212[1] = fRec212[0];
			fRec210[1] = fRec210[0];
			fRec209[1] = fRec209[0];
			fRec207[1] = fRec207[0];
			fRec206[1] = fRec206[0];
			fRec204[1] = fRec204[0];
			for (int j0 = 15; (j0 > 0); j0 = (j0 - 1)) {
				fVec3[j0] = fVec3[(j0 - 1)];
				
			}
			fRec221[1] = fRec221[0];
			fRec219[1] = fRec219[0];
			fRec227[1] = fRec227[0];
			fRec225[1] = fRec225[0];
			fRec224[1] = fRec224[0];
			fRec222[1] = fRec222[0];
			fRec236[1] = fRec236[0];
			fRec234[1] = fRec234[0];
			fRec233[1] = fRec233[0];
			fRec231[1] = fRec231[0];
			fRec230[1] = fRec230[0];
			fRec228[1] = fRec228[0];
			fRec248[1] = fRec248[0];
			fRec246[1] = fRec246[0];
			fRec245[1] = fRec245[0];
			fRec243[1] = fRec243[0];
			fRec242[1] = fRec242[0];
			fRec240[1] = fRec240[0];
			fRec239[1] = fRec239[0];
			fRec237[1] = fRec237[0];
			fRec263[1] = fRec263[0];
			fRec261[1] = fRec261[0];
			fRec260[1] = fRec260[0];
			fRec258[1] = fRec258[0];
			fRec257[1] = fRec257[0];
			fRec255[1] = fRec255[0];
			fRec254[1] = fRec254[0];
			fRec252[1] = fRec252[0];
			fRec251[1] = fRec251[0];
			fRec249[1] = fRec249[0];
			fRec278[1] = fRec278[0];
			fRec276[1] = fRec276[0];
			fRec275[1] = fRec275[0];
			fRec273[1] = fRec273[0];
			fRec272[1] = fRec272[0];
			fRec270[1] = fRec270[0];
			fRec269[1] = fRec269[0];
			fRec267[1] = fRec267[0];
			fRec266[1] = fRec266[0];
			fRec264[1] = fRec264[0];
			fRec281[1] = fRec281[0];
			fRec279[1] = fRec279[0];
			fRec287[1] = fRec287[0];
			fRec285[1] = fRec285[0];
			fRec284[1] = fRec284[0];
			fRec282[1] = fRec282[0];
			fRec296[1] = fRec296[0];
			fRec294[1] = fRec294[0];
			fRec293[1] = fRec293[0];
			fRec291[1] = fRec291[0];
			fRec290[1] = fRec290[0];
			fRec288[1] = fRec288[0];
			fRec308[1] = fRec308[0];
			fRec306[1] = fRec306[0];
			fRec305[1] = fRec305[0];
			fRec303[1] = fRec303[0];
			fRec302[1] = fRec302[0];
			fRec300[1] = fRec300[0];
			fRec299[1] = fRec299[0];
			fRec297[1] = fRec297[0];
			for (int j1 = 7; (j1 > 0); j1 = (j1 - 1)) {
				fVec5[j1] = fVec5[(j1 - 1)];
				
			}
			fRec323[1] = fRec323[0];
			fRec321[1] = fRec321[0];
			fRec320[1] = fRec320[0];
			fRec318[1] = fRec318[0];
			fRec317[1] = fRec317[0];
			fRec315[1] = fRec315[0];
			fRec314[1] = fRec314[0];
			fRec312[1] = fRec312[0];
			fRec311[1] = fRec311[0];
			fRec309[1] = fRec309[0];
			fRec335[1] = fRec335[0];
			fRec333[1] = fRec333[0];
			fRec332[1] = fRec332[0];
			fRec330[1] = fRec330[0];
			fRec329[1] = fRec329[0];
			fRec327[1] = fRec327[0];
			fRec326[1] = fRec326[0];
			fRec324[1] = fRec324[0];
			fRec344[1] = fRec344[0];
			fRec342[1] = fRec342[0];
			fRec341[1] = fRec341[0];
			fRec339[1] = fRec339[0];
			fRec338[1] = fRec338[0];
			fRec336[1] = fRec336[0];
			fRec350[1] = fRec350[0];
			fRec348[1] = fRec348[0];
			fRec347[1] = fRec347[0];
			fRec345[1] = fRec345[0];
			fRec353[1] = fRec353[0];
			fRec351[1] = fRec351[0];
			fRec356[1] = fRec356[0];
			fRec354[1] = fRec354[0];
			fRec371[1] = fRec371[0];
			fRec369[1] = fRec369[0];
			fRec368[1] = fRec368[0];
			fRec366[1] = fRec366[0];
			fRec365[1] = fRec365[0];
			fRec363[1] = fRec363[0];
			fRec362[1] = fRec362[0];
			fRec360[1] = fRec360[0];
			fRec359[1] = fRec359[0];
			fRec357[1] = fRec357[0];
			fRec383[1] = fRec383[0];
			fRec381[1] = fRec381[0];
			fRec380[1] = fRec380[0];
			fRec378[1] = fRec378[0];
			fRec377[1] = fRec377[0];
			fRec375[1] = fRec375[0];
			fRec374[1] = fRec374[0];
			fRec372[1] = fRec372[0];
			fRec389[1] = fRec389[0];
			fRec387[1] = fRec387[0];
			fRec386[1] = fRec386[0];
			fRec384[1] = fRec384[0];
			fRec398[1] = fRec398[0];
			fRec396[1] = fRec396[0];
			fRec395[1] = fRec395[0];
			fRec393[1] = fRec393[0];
			fRec392[1] = fRec392[0];
			fRec390[1] = fRec390[0];
			fRec413[1] = fRec413[0];
			fRec411[1] = fRec411[0];
			fRec410[1] = fRec410[0];
			fRec408[1] = fRec408[0];
			fRec407[1] = fRec407[0];
			fRec405[1] = fRec405[0];
			fRec404[1] = fRec404[0];
			fRec402[1] = fRec402[0];
			fRec401[1] = fRec401[0];
			fRec399[1] = fRec399[0];
			fRec425[1] = fRec425[0];
			fRec423[1] = fRec423[0];
			fRec422[1] = fRec422[0];
			fRec420[1] = fRec420[0];
			fRec419[1] = fRec419[0];
			fRec417[1] = fRec417[0];
			fRec416[1] = fRec416[0];
			fRec414[1] = fRec414[0];
			fRec434[1] = fRec434[0];
			fRec432[1] = fRec432[0];
			fRec431[1] = fRec431[0];
			fRec429[1] = fRec429[0];
			fRec428[1] = fRec428[0];
			fRec426[1] = fRec426[0];
			fRec437[1] = fRec437[0];
			fRec435[1] = fRec435[0];
			fRec443[1] = fRec443[0];
			fRec441[1] = fRec441[0];
			fRec440[1] = fRec440[0];
			fRec438[1] = fRec438[0];
			fRec458[1] = fRec458[0];
			fRec456[1] = fRec456[0];
			fRec455[1] = fRec455[0];
			fRec453[1] = fRec453[0];
			fRec452[1] = fRec452[0];
			fRec450[1] = fRec450[0];
			fRec449[1] = fRec449[0];
			fRec447[1] = fRec447[0];
			fRec446[1] = fRec446[0];
			fRec444[1] = fRec444[0];
			fRec470[1] = fRec470[0];
			fRec468[1] = fRec468[0];
			fRec467[1] = fRec467[0];
			fRec465[1] = fRec465[0];
			fRec464[1] = fRec464[0];
			fRec462[1] = fRec462[0];
			fRec461[1] = fRec461[0];
			fRec459[1] = fRec459[0];
			fRec479[1] = fRec479[0];
			fRec477[1] = fRec477[0];
			fRec476[1] = fRec476[0];
			fRec474[1] = fRec474[0];
			fRec473[1] = fRec473[0];
			fRec471[1] = fRec471[0];
			fRec482[1] = fRec482[0];
			fRec480[1] = fRec480[0];
			fRec488[1] = fRec488[0];
			fRec486[1] = fRec486[0];
			fRec485[1] = fRec485[0];
			fRec483[1] = fRec483[0];
			fRec503[1] = fRec503[0];
			fRec501[1] = fRec501[0];
			fRec500[1] = fRec500[0];
			fRec498[1] = fRec498[0];
			fRec497[1] = fRec497[0];
			fRec495[1] = fRec495[0];
			fRec494[1] = fRec494[0];
			fRec492[1] = fRec492[0];
			fRec491[1] = fRec491[0];
			fRec489[1] = fRec489[0];
			fRec515[1] = fRec515[0];
			fRec513[1] = fRec513[0];
			fRec512[1] = fRec512[0];
			fRec510[1] = fRec510[0];
			fRec509[1] = fRec509[0];
			fRec507[1] = fRec507[0];
			fRec506[1] = fRec506[0];
			fRec504[1] = fRec504[0];
			fRec524[1] = fRec524[0];
			fRec522[1] = fRec522[0];
			fRec521[1] = fRec521[0];
			fRec519[1] = fRec519[0];
			fRec518[1] = fRec518[0];
			fRec516[1] = fRec516[0];
			fRec527[1] = fRec527[0];
			fRec525[1] = fRec525[0];
			fRec533[1] = fRec533[0];
			fRec531[1] = fRec531[0];
			fRec530[1] = fRec530[0];
			fRec528[1] = fRec528[0];
			fRec548[1] = fRec548[0];
			fRec546[1] = fRec546[0];
			fRec545[1] = fRec545[0];
			fRec543[1] = fRec543[0];
			fRec542[1] = fRec542[0];
			fRec540[1] = fRec540[0];
			fRec539[1] = fRec539[0];
			fRec537[1] = fRec537[0];
			fRec536[1] = fRec536[0];
			fRec534[1] = fRec534[0];
			fRec560[1] = fRec560[0];
			fRec558[1] = fRec558[0];
			fRec557[1] = fRec557[0];
			fRec555[1] = fRec555[0];
			fRec554[1] = fRec554[0];
			fRec552[1] = fRec552[0];
			fRec551[1] = fRec551[0];
			fRec549[1] = fRec549[0];
			fRec569[1] = fRec569[0];
			fRec567[1] = fRec567[0];
			fRec566[1] = fRec566[0];
			fRec564[1] = fRec564[0];
			fRec563[1] = fRec563[0];
			fRec561[1] = fRec561[0];
			fRec572[1] = fRec572[0];
			fRec570[1] = fRec570[0];
			fRec578[1] = fRec578[0];
			fRec576[1] = fRec576[0];
			fRec575[1] = fRec575[0];
			fRec573[1] = fRec573[0];
			fRec593[1] = fRec593[0];
			fRec591[1] = fRec591[0];
			fRec590[1] = fRec590[0];
			fRec588[1] = fRec588[0];
			fRec587[1] = fRec587[0];
			fRec585[1] = fRec585[0];
			fRec584[1] = fRec584[0];
			fRec582[1] = fRec582[0];
			fRec581[1] = fRec581[0];
			fRec579[1] = fRec579[0];
			fRec605[1] = fRec605[0];
			fRec603[1] = fRec603[0];
			fRec602[1] = fRec602[0];
			fRec600[1] = fRec600[0];
			fRec599[1] = fRec599[0];
			fRec597[1] = fRec597[0];
			fRec596[1] = fRec596[0];
			fRec594[1] = fRec594[0];
			fRec614[1] = fRec614[0];
			fRec612[1] = fRec612[0];
			fRec611[1] = fRec611[0];
			fRec609[1] = fRec609[0];
			fRec608[1] = fRec608[0];
			fRec606[1] = fRec606[0];
			fRec620[1] = fRec620[0];
			fRec618[1] = fRec618[0];
			fRec617[1] = fRec617[0];
			fRec615[1] = fRec615[0];
			fRec623[1] = fRec623[0];
			fRec621[1] = fRec621[0];
			fRec635[1] = fRec635[0];
			fRec633[1] = fRec633[0];
			fRec632[1] = fRec632[0];
			fRec630[1] = fRec630[0];
			fRec629[1] = fRec629[0];
			fRec627[1] = fRec627[0];
			fRec626[1] = fRec626[0];
			fRec624[1] = fRec624[0];
			fRec644[1] = fRec644[0];
			fRec642[1] = fRec642[0];
			fRec641[1] = fRec641[0];
			fRec639[1] = fRec639[0];
			fRec638[1] = fRec638[0];
			fRec636[1] = fRec636[0];
			fRec650[1] = fRec650[0];
			fRec648[1] = fRec648[0];
			fRec647[1] = fRec647[0];
			fRec645[1] = fRec645[0];
			fRec653[1] = fRec653[0];
			fRec651[1] = fRec651[0];
			fRec668[1] = fRec668[0];
			fRec666[1] = fRec666[0];
			fRec665[1] = fRec665[0];
			fRec663[1] = fRec663[0];
			fRec662[1] = fRec662[0];
			fRec660[1] = fRec660[0];
			fRec659[1] = fRec659[0];
			fRec657[1] = fRec657[0];
			fRec656[1] = fRec656[0];
			fRec654[1] = fRec654[0];
			
		}
		
	}

	
};

/***************************END USER SECTION ***************************/

/*******************BEGIN ARCHITECTURE SECTION (part 2/2)***************/

/* Faust code wrapper ------- */

#include "ext.h"
#include "ext_obex.h"
#include "z_dsp.h"
#include "jpatcher_api.h"
#include <string.h>

#define ASSIST_INLET 	1  	/* should be defined somewhere ?? */
#define ASSIST_OUTLET 	2	/* should be defined somewhere ?? */

#define EXTERNAL_VERSION    "0.64"
#define STR_SIZE            512

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __GUI_H__
#define __GUI_H__

#include <list>
#include <map>
#include <vector>
#include <iostream>

#ifdef _WIN32
# pragma warning (disable: 4100)
#else
# pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

/*
  Copyright (C) 2000 Paul Davis
  Copyright (C) 2003 Rohan Drape
  Copyright (C) 2016 GRAME (renaming for internal use)

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

  ISO/POSIX C version of Paul Davis's lock free ringbuffer C++ code.
  This is safe for the case of one read thread and one write thread.
*/

#ifndef __ring_buffer__
#define __ring_buffer__

#include <stdlib.h>
#include <string.h>

#ifdef WIN32
#pragma warning (disable: 4334)
#endif

typedef struct {
    char *buf;
    size_t len;
}
ringbuffer_data_t;

typedef struct {
    char *buf;
    volatile size_t write_ptr;
    volatile size_t read_ptr;
    size_t	size;
    size_t	size_mask;
    int	mlocked;
}
ringbuffer_t;

ringbuffer_t *ringbuffer_create(size_t sz);
void ringbuffer_free(ringbuffer_t *rb);
void ringbuffer_get_read_vector(const ringbuffer_t *rb,
                                         ringbuffer_data_t *vec);
void ringbuffer_get_write_vector(const ringbuffer_t *rb,
                                          ringbuffer_data_t *vec);
size_t ringbuffer_read(ringbuffer_t *rb, char *dest, size_t cnt);
size_t ringbuffer_peek(ringbuffer_t *rb, char *dest, size_t cnt);
void ringbuffer_read_advance(ringbuffer_t *rb, size_t cnt);
size_t ringbuffer_read_space(const ringbuffer_t *rb);
int ringbuffer_mlock(ringbuffer_t *rb);
void ringbuffer_reset(ringbuffer_t *rb);
void ringbuffer_reset_size (ringbuffer_t * rb, size_t sz);
size_t ringbuffer_write(ringbuffer_t *rb, const char *src,
                                 size_t cnt);
void ringbuffer_write_advance(ringbuffer_t *rb, size_t cnt);
size_t ringbuffer_write_space(const ringbuffer_t *rb);

/* Create a new ringbuffer to hold at least `sz' bytes of data. The
   actual buffer size is rounded up to the next power of two. */

inline ringbuffer_t *
ringbuffer_create (size_t sz)
{
	size_t power_of_two;
	ringbuffer_t *rb;

	if ((rb = (ringbuffer_t *) malloc (sizeof (ringbuffer_t))) == NULL) {
		return NULL;
	}

	for (power_of_two = 1u; 1u << power_of_two < sz; power_of_two++);

	rb->size = 1u << power_of_two;
	rb->size_mask = rb->size;
	rb->size_mask -= 1;
	rb->write_ptr = 0;
	rb->read_ptr = 0;
	if ((rb->buf = (char *) malloc (rb->size)) == NULL) {
		free (rb);
		return NULL;
	}
	rb->mlocked = 0;

	return rb;
}

/* Free all data associated with the ringbuffer `rb'. */

inline void
ringbuffer_free (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (rb->mlocked) {
		munlock (rb->buf, rb->size);
	}
#endif /* USE_MLOCK */
	free (rb->buf);
	free (rb);
}

/* Lock the data block of `rb' using the system call 'mlock'.  */

inline int
ringbuffer_mlock (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (mlock (rb->buf, rb->size)) {
		return -1;
	}
#endif /* USE_MLOCK */
	rb->mlocked = 1;
	return 0;
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

inline void
ringbuffer_reset (ringbuffer_t * rb)
{
	rb->read_ptr = 0;
	rb->write_ptr = 0;
    memset(rb->buf, 0, rb->size);
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

inline void
ringbuffer_reset_size (ringbuffer_t * rb, size_t sz)
{
    rb->size = sz;
    rb->size_mask = rb->size;
    rb->size_mask -= 1;
    rb->read_ptr = 0;
    rb->write_ptr = 0;
}

/* Return the number of bytes available for reading. This is the
   number of bytes in front of the read pointer and behind the write
   pointer.  */

inline size_t
ringbuffer_read_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return w - r;
	} else {
		return (w - r + rb->size) & rb->size_mask;
	}
}

/* Return the number of bytes available for writing. This is the
   number of bytes in front of the write pointer and behind the read
   pointer.  */

inline size_t
ringbuffer_write_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		return (r - w) - 1;
	} else {
		return rb->size - 1;
	}
}

/* The copying data reader. Copy at most `cnt' bytes from `rb' to
   `dest'.  Returns the actual number of bytes copied. */

inline size_t
ringbuffer_read (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[rb->read_ptr]), n1);
	rb->read_ptr = (rb->read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[rb->read_ptr]), n2);
		rb->read_ptr = (rb->read_ptr + n2) & rb->size_mask;
	}

	return to_read;
}

/* The copying data reader w/o read pointer advance. Copy at most
   `cnt' bytes from `rb' to `dest'.  Returns the actual number of bytes
   copied. */

inline size_t
ringbuffer_peek (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;
	size_t tmp_read_ptr;

	tmp_read_ptr = rb->read_ptr;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = tmp_read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - tmp_read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[tmp_read_ptr]), n1);
	tmp_read_ptr = (tmp_read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[tmp_read_ptr]), n2);
	}

	return to_read;
}

/* The copying data writer. Copy at most `cnt' bytes to `rb' from
   `src'.  Returns the actual number of bytes copied. */

inline size_t
ringbuffer_write (ringbuffer_t * rb, const char *src, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_write;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_write_space (rb)) == 0) {
		return 0;
	}

	to_write = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->write_ptr + to_write;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->write_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_write;
		n2 = 0;
	}

	memcpy (&(rb->buf[rb->write_ptr]), src, n1);
	rb->write_ptr = (rb->write_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (&(rb->buf[rb->write_ptr]), src + n1, n2);
		rb->write_ptr = (rb->write_ptr + n2) & rb->size_mask;
	}

	return to_write;
}

/* Advance the read pointer `cnt' places. */

inline void
ringbuffer_read_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->read_ptr + cnt) & rb->size_mask;
	rb->read_ptr = tmp;
}

/* Advance the write pointer `cnt' places. */

inline void
ringbuffer_write_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->write_ptr + cnt) & rb->size_mask;
	rb->write_ptr = tmp;
}

/* The non-copying data reader. `vec' is an array of two places. Set
   the values at `vec' to hold the current readable data at `rb'. If
   the readable data is in one segment the second segment has zero
   length. */

inline void
ringbuffer_get_read_vector (const ringbuffer_t * rb,
				 ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = w - r;
	} else {
		free_cnt = (w - r + rb->size) & rb->size_mask;
	}

	cnt2 = r + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = rb->size - r;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;

	} else {

		/* Single part vector: just the rest of the buffer */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

/* The non-copying data writer. `vec' is an array of two places. Set
   the values at `vec' to hold the current writeable data at `rb'. If
   the writeable data is in one segment the second segment has zero
   length. */

inline void
ringbuffer_get_write_vector (const ringbuffer_t * rb,
				  ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		free_cnt = (r - w) - 1;
	} else {
		free_cnt = rb->size - 1;
	}

	cnt2 = w + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[w]);
		vec[0].len = rb->size - w;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;
	} else {
		vec[0].buf = &(rb->buf[w]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

#endif // __ring_buffer__

/*******************************************************************************
 * GUI : Abstract Graphic User Interface
 * Provides additional mechanisms to synchronize widgets and zones. Widgets
 * should both reflect the value of a zone and allow to change this value.
 ******************************************************************************/

class uiItem;
typedef void (*uiCallback)(FAUSTFLOAT val, void* data);

class clist : public std::list<uiItem*>
{
    
    public:
    
        virtual ~clist();
        
};

typedef std::map<FAUSTFLOAT*, clist*> zmap;

typedef std::map<FAUSTFLOAT*, ringbuffer_t*> ztimedmap;

class GUI : public UI
{
		
    private:
     
        static std::list<GUI*> fGuiList;
        zmap fZoneMap;
        bool fStopped;
        
     public:
            
        GUI():fStopped(false)
        {	
            fGuiList.push_back(this);
        }
        
        virtual ~GUI() 
        {   
            // delete all items
            zmap::iterator it;
            for (it = fZoneMap.begin(); it != fZoneMap.end(); it++) {
                delete (*it).second;
            }
            // suppress 'this' in static fGuiList
            fGuiList.remove(this);
        }

        // -- registerZone(z,c) : zone management
        
        void registerZone(FAUSTFLOAT* z, uiItem* c)
        {
            if (fZoneMap.find(z) == fZoneMap.end()) fZoneMap[z] = new clist();
            fZoneMap[z]->push_back(c);
        }

        void updateAllZones();
        
        void updateZone(FAUSTFLOAT* z);
        
        static void updateAllGuis()
        {
            std::list<GUI*>::iterator g;
            for (g = fGuiList.begin(); g != fGuiList.end(); g++) {
                (*g)->updateAllZones();
            }
        }
        void addCallback(FAUSTFLOAT* zone, uiCallback foo, void* data);
        virtual void show() {};	
        virtual bool run() { return false; };
    
        virtual void stop() { fStopped = true; }
        bool stopped() { return fStopped; }
    
        // -- widget's layouts
        
        virtual void openTabBox(const char* label) {};
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
    
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
    
        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
    
        // Static global for timed zones, shared between all UI that will set timed values
        static ztimedmap gTimedZoneMap;

};

/**
 * User Interface Item: abstract definition
 */

class uiItem
{
    protected:
          
        GUI* fGUI;
        FAUSTFLOAT* fZone;
        FAUSTFLOAT fCache;

        uiItem(GUI* ui, FAUSTFLOAT* zone):fGUI(ui), fZone(zone), fCache(FAUSTFLOAT(-123456.654321))
        { 
            ui->registerZone(zone, this); 
        }

    public:

        virtual ~uiItem() 
        {}

        void modifyZone(FAUSTFLOAT v) 	
        { 
            fCache = v;
            if (*fZone != v) {
                *fZone = v;
                fGUI->updateZone(fZone);
            }
        }
                
        FAUSTFLOAT cache() { return fCache; }
        virtual void reflectZone() = 0;
};

/**
 * User Interface item owned (and so deleted) by external code
 */

class uiOwnedItem : public uiItem {
    
    protected:
    
        uiOwnedItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
    
     public:
    
        virtual ~uiOwnedItem()
        {}
    
        virtual void reflectZone() {}
};

/**
 * Callback Item
 */

struct uiCallbackItem : public uiItem {
    
	uiCallback fCallback;
	void* fData;
	
	uiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data) 
			: uiItem(ui, zone), fCallback(foo), fData(data) {}
	
	virtual void reflectZone() 
    {		
		FAUSTFLOAT v = *fZone;
		fCache = v; 
		fCallback(v, fData);	
	}
};

/**
 * Base class for timed items
 */

// For precise timestamped control
struct DatedControl {
    
    double fDate;
    FAUSTFLOAT fValue;
    
    DatedControl(double d = 0., FAUSTFLOAT v = FAUSTFLOAT(0)):fDate(d), fValue(v) {}
    
};

class uiTimedItem : public uiItem
{
    
    protected:
        
        bool fDelete;
        
    public:
        
        uiTimedItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {
            if (GUI::gTimedZoneMap.find(fZone) == GUI::gTimedZoneMap.end()) {
                GUI::gTimedZoneMap[fZone] = ringbuffer_create(8192);
                fDelete = true;
            } else {
                fDelete = false;
            }
        }
        
        virtual ~uiTimedItem()
        {
            ztimedmap::iterator it;
            if (fDelete && ((it = GUI::gTimedZoneMap.find(fZone)) != GUI::gTimedZoneMap.end())) {
                ringbuffer_free((*it).second);
                GUI::gTimedZoneMap.erase(it);
            }
        }
        
        virtual void modifyZone(double date, FAUSTFLOAT v)
        {
            size_t res;
            DatedControl dated_val(date, v);
            if ((res = ringbuffer_write(GUI::gTimedZoneMap[fZone], (const char*)&dated_val, sizeof(DatedControl))) != sizeof(DatedControl)) {
                std::cerr << "ringbuffer_write error DatedControl" << std::endl;
            }
        }
    
};

/**
 * Allows to group a set of zones
 */

class uiGroupItem : public uiItem
{
    protected:
    
        std::vector<FAUSTFLOAT*> fZoneMap;

    public:
    
        uiGroupItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
        virtual ~uiGroupItem() 
        {}
        
        virtual void reflectZone() 
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            
            // Update all zones of the same group
            std::vector<FAUSTFLOAT*>::iterator it;
            for (it = fZoneMap.begin(); it != fZoneMap.end(); it++) {
                (*(*it)) = v;
            }
        }
        
        void addZone(FAUSTFLOAT* zone) { fZoneMap.push_back(zone); }

};

/**
 * Update all user items reflecting zone z
 */

inline void GUI::updateZone(FAUSTFLOAT* z)
{
	FAUSTFLOAT v = *z;
	clist* l = fZoneMap[z];
	for (clist::iterator c = l->begin(); c != l->end(); c++) {
		if ((*c)->cache() != v) (*c)->reflectZone();
	}
}

/**
 * Update all user items not up to date
 */

inline void GUI::updateAllZones()
{
	for (zmap::iterator m = fZoneMap.begin(); m != fZoneMap.end(); m++) {
		FAUSTFLOAT* z = m->first;
		clist*	l = m->second;
        if (z) {
            FAUSTFLOAT v = *z;
            for (clist::iterator c = l->begin(); c != l->end(); c++) {
                if ((*c)->cache() != v) (*c)->reflectZone();
            }
        }
	}
}

inline void GUI::addCallback(FAUSTFLOAT* zone, uiCallback foo, void* data) 
{ 
	new uiCallbackItem(this, zone, foo, data); 
};

inline clist::~clist() 
{
    std::list<uiItem*>::iterator it;
    for (it = begin(); it != end(); it++) {
        uiOwnedItem* owned = dynamic_cast<uiOwnedItem*>(*it);
        // owned items are deleted by external code
        if (!owned) {
            delete (*it);
        }
    }
}

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_MIDIUI_H
#define FAUST_MIDIUI_H

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <cstdlib>
#include <cmath>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __midi__
#define __midi__

#include <vector>
#include <string>
#include <algorithm>

class MapUI;

//----------------------------------------------------------------
//  MIDI processor definition
//----------------------------------------------------------------

class midi {

    public:

        midi() {}
        virtual ~midi() {}

        // Additional time-stamped API for MIDI input
        virtual MapUI* keyOn(double, int channel, int pitch, int velocity)
        {
            return keyOn(channel, pitch, velocity);
        }
        
        virtual void keyOff(double, int channel, int pitch, int velocity = 127)
        {
            keyOff(channel, pitch, velocity);
        }
        
        virtual void pitchWheel(double, int channel, int wheel)
        {
            pitchWheel(channel, wheel);
        }
           
        virtual void ctrlChange(double, int channel, int ctrl, int value)
        {
            ctrlChange(channel, ctrl, value);
        }
       
        virtual void progChange(double, int channel, int pgm)
        {
            progChange(channel, pgm);
        }
        
        virtual void keyPress(double, int channel, int pitch, int press)
        {
            keyPress(channel, pitch, press);
        }
        
        virtual void chanPress(double date, int channel, int press)
        {
            chanPress(channel, press);
        }
       
        virtual void ctrlChange14bits(double, int channel, int ctrl, int value)
        {
            ctrlChange14bits(channel, ctrl, value);
        }

        // MIDI sync
        virtual void start_sync(double date)  {}
        virtual void stop_sync(double date)   {}
        virtual void clock(double date)  {}

        // Standard MIDI API
        virtual MapUI* keyOn(int channel, int pitch, int velocity)      { return 0; }
        virtual void keyOff(int channel, int pitch, int velocity)       {}
        virtual void keyPress(int channel, int pitch, int press)        {}
        virtual void chanPress(int channel, int press)                  {}
        virtual void ctrlChange(int channel, int ctrl, int value)       {}
        virtual void ctrlChange14bits(int channel, int ctrl, int value) {}
        virtual void pitchWheel(int channel, int wheel)                 {}
        virtual void progChange(int channel, int pgm)                   {}

        enum MidiStatus {

            // channel voice messages
            MIDI_NOTE_OFF = 0x80,
            MIDI_NOTE_ON = 0x90,
            MIDI_CONTROL_CHANGE = 0xB0,
            MIDI_PROGRAM_CHANGE = 0xC0,
            MIDI_PITCH_BEND = 0xE0,
            MIDI_AFTERTOUCH = 0xD0,         // aka channel pressure
            MIDI_POLY_AFTERTOUCH = 0xA0,    // aka key pressure
            MIDI_CLOCK = 0xF8,
            MIDI_START = 0xFA,
            MIDI_STOP = 0xFC

        };

        enum MidiCtrl {

            ALL_NOTES_OFF = 123,
            ALL_SOUND_OFF = 120

        };
};

//----------------------------------------------------------------
//  Base class for MIDI API handling
//----------------------------------------------------------------

class midi_handler : public midi {

    protected:

        std::vector<midi*> fMidiInputs;
        std::string fName;

    public:

        midi_handler(const std::string& name = "MIDIHandler"):fName(name) {}
        virtual ~midi_handler() {}

        void addMidiIn(midi* midi_dsp) { if (midi_dsp) fMidiInputs.push_back(midi_dsp); }
        void removeMidiIn(midi* midi_dsp)
        {
            std::vector<midi*>::iterator it = std::find(fMidiInputs.begin(), fMidiInputs.end(), midi_dsp);
            if (it != fMidiInputs.end()) {
                fMidiInputs.erase(it);
            }
        }

        virtual bool start_midi() { return true; }
        virtual void stop_midi() {}
    
        void setName(const std::string& name) { fName = name; }
        std::string getName() { return fName; }
        
        void handleSync(double time, int type)
        {
            if (type == MIDI_CLOCK) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->clock(time);
                }
            } else if (type == MIDI_START) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->start_sync(time);
                }
            } else if (type == MIDI_STOP) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->stop_sync(time);
                }
            }
        }

        void handleData1(double time, int type, int channel, int data1)
        {
            if (type == MIDI_PROGRAM_CHANGE) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->progChange(time, channel, data1);
                }
            } else if (type == MIDI_AFTERTOUCH) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->chanPress(time, channel, data1);
                }
            }
        }

        void handleData2(double time, int type, int channel, int data1, int data2)
        {
            if (type == MIDI_NOTE_OFF || ((type == MIDI_NOTE_ON) && (data2 == 0))) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyOff(time, channel, data1, data2);
                }
            } else if (type == MIDI_NOTE_ON) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyOn(time, channel, data1, data2);
                }
            } else if (type == MIDI_CONTROL_CHANGE) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->ctrlChange(time, channel, data1, data2);
                }
            } else if (type == MIDI_PITCH_BEND) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->pitchWheel(time, channel, (data2 * 128.0) + data1);
                }
            } else if (type == MIDI_POLY_AFTERTOUCH) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyPress(time, channel, data1, data2);
                }
            }
        }

};

#endif // __midi__
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __ValueConverter__
#define __ValueConverter__

/***************************************************************************************
								ValueConverter.h
							    (GRAME, © 2015)

Set of conversion objects used to map user interface values (for example a gui slider
delivering values between 0 and 1) to faust values (for example a vslider between
20 and 20000) using a log scale.

-- Utilities

Range(lo,hi) : clip a value x between lo and hi
Interpolator(lo,hi,v1,v2) : Maps a value x between lo and hi to a value y between v1 and v2
Interpolator3pt(lo,mi,hi,v1,vm,v2) : Map values between lo mid hi to values between v1 vm v2

-- Value Converters

ValueConverter::ui2faust(x)
ValueConverter::faust2ui(x)

-- ValueConverters used for sliders depending of the scale

LinearValueConverter(umin, umax, fmin, fmax)
LogValueConverter(umin, umax, fmin, fmax)
ExpValueConverter(umin, umax, fmin, fmax)

-- ValueConverters used for accelerometers based on 3 points

AccUpConverter(amin, amid, amax, fmin, fmid, fmax)		-- curve 0
AccDownConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 1
AccUpDownConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 2
AccDownUpConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 3

-- lists of ZoneControl are used to implement accelerometers metadata for each axes

ZoneControl(zone, valueConverter) : a zone with an accelerometer data converter

-- ZoneReader are used to implement screencolor metadata

ZoneReader(zone, valueConverter) : a zone with a data converter

****************************************************************************************/

#include <float.h>
#include <algorithm>    // std::max
#include <cmath>
#include <vector>
#include <assert.h>

//--------------------------------------------------------------------------------------
// Interpolator(lo,hi,v1,v2)
// Maps a value x between lo and hi to a value y between v1 and v2
// y = v1 + (x-lo)/(hi-lo)*(v2-v1)
// y = v1 + (x-lo) * coef   		with coef = (v2-v1)/(hi-lo)
// y = v1 + x*coef - lo*coef
// y = v1 - lo*coef + x*coef
// y = offset + x*coef				with offset = v1 - lo*coef
//--------------------------------------------------------------------------------------
class Interpolator
{
    private:

        //--------------------------------------------------------------------------------------
        // Range(lo,hi) clip a value between lo and hi
        //--------------------------------------------------------------------------------------
        struct Range
        {
            double fLo;
            double fHi;

            Range(double x, double y) : fLo(std::min<double>(x,y)), fHi(std::max<double>(x,y)) {}
            double operator()(double x) { return (x<fLo) ? fLo : (x>fHi) ? fHi : x; }
        };


        Range fRange;
        double fCoef;
        double fOffset;

    public:

        Interpolator(double lo, double hi, double v1, double v2) : fRange(lo,hi)
        {
            if (hi != lo) {
                // regular case
                fCoef = (v2-v1)/(hi-lo);
                fOffset = v1 - lo*fCoef;
            } else {
                // degenerate case, avoids division by zero
                fCoef = 0;
                fOffset = (v1+v2)/2;
            }
        }
        double operator()(double v)
        {
            double x = fRange(v);
            return  fOffset + x*fCoef;
        }

        void getLowHigh(double& amin, double& amax)
        {
            amin = fRange.fLo;
            amax = fRange.fHi;
        }
};

//--------------------------------------------------------------------------------------
// Interpolator3pt(lo,mi,hi,v1,vm,v2)
// Map values between lo mid hi to values between v1 vm v2
//--------------------------------------------------------------------------------------
class Interpolator3pt
{

    private:

        Interpolator fSegment1;
        Interpolator fSegment2;
        double fMid;

    public:

        Interpolator3pt(double lo, double mi, double hi, double v1, double vm, double v2) :
            fSegment1(lo, mi, v1, vm),
            fSegment2(mi, hi, vm, v2),
            fMid(mi) {}
        double operator()(double x) { return  (x < fMid) ? fSegment1(x) : fSegment2(x); }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fSegment1.getLowHigh(amin, amid);
            fSegment2.getLowHigh(amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Abstract ValueConverter class. Converts values between UI and Faust representations
//--------------------------------------------------------------------------------------
class ValueConverter
{

    public:

        virtual ~ValueConverter() {}
        virtual double ui2faust(double x) = 0;
        virtual double faust2ui(double x) = 0;
};

//--------------------------------------------------------------------------------------
// Linear conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class LinearValueConverter : public ValueConverter
{

    private:

        Interpolator fUI2F;
        Interpolator fF2UI;

    public:

        LinearValueConverter(double umin, double umax, double fmin, double fmax) :
            fUI2F(umin,umax,fmin,fmax), fF2UI(fmin,fmax,umin,umax)
        {}

        LinearValueConverter() :
            fUI2F(0.,0.,0.,0.), fF2UI(0.,0.,0.,0.)
        {}
        virtual double ui2faust(double x) {	return fUI2F(x); }
        virtual double faust2ui(double x) {	return fF2UI(x); }

};

//--------------------------------------------------------------------------------------
// Logarithmic conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class LogValueConverter : public LinearValueConverter
{

    public:

        LogValueConverter(double umin, double umax, double fmin, double fmax) :
        LinearValueConverter(umin, umax, log(std::max<double>(DBL_MIN, fmin)), std::log(std::max<double>(DBL_MIN, fmax)))
        {}

        virtual double ui2faust(double x) 	{ return std::exp(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x)	{ return LinearValueConverter::faust2ui(std::log(std::max<double>(x, DBL_MIN))); }

};

//--------------------------------------------------------------------------------------
// Exponential conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class ExpValueConverter : public LinearValueConverter
{

    public:

        ExpValueConverter(double umin, double umax, double fmin, double fmax) :
            LinearValueConverter(umin, umax, exp(fmin), exp(fmax))
        {}

        virtual double ui2faust(double x) { return std::log(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x) { return LinearValueConverter::faust2ui(std::exp(x)); }

};

//--------------------------------------------------------------------------------------
// A converter than can be updated
//--------------------------------------------------------------------------------------

class UpdatableValueConverter : public ValueConverter {

    protected:

        bool fActive;

    public:

        UpdatableValueConverter():fActive(true)
        {}
        virtual ~UpdatableValueConverter()
        {}

        virtual void setMappingValues(double amin, double amid, double amax, double min, double init, double max) = 0;
        virtual void getMappingValues(double& amin, double& amid, double& amax) = 0;

        void setActive(bool on_off) { fActive = on_off; }
        bool getActive() { return fActive; }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up curve (curve 0)
//--------------------------------------------------------------------------------------
class AccUpConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt fA2F;
        Interpolator3pt fF2A;

    public:

        AccUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmid,fmax),
            fF2A(fmin,fmid,fmax,amin,amid,amax)
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmin,fmid,fmax);
            fF2A = Interpolator3pt(fmin,fmid,fmax,amin,amid,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down curve (curve 1)
//--------------------------------------------------------------------------------------
class AccDownConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator3pt	fF2A;

    public:

        AccDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmid,fmin),
            fF2A(fmin,fmid,fmax,amax,amid,amin)
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
             //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmax,fmid,fmin);
            fF2A = Interpolator3pt(fmin,fmid,fmax,amax,amid,amin);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up-Down curve (curve 2)
//--------------------------------------------------------------------------------------
class AccUpDownConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccUpDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmax,fmin),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotone function
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
             //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmin,fmax,fmin);
            fF2A = Interpolator(fmin,fmax,amin,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down-Up curve (curve 3)
//--------------------------------------------------------------------------------------
class AccDownUpConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccDownUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmin,fmax),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotone function
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmax,fmin,fmax);
            fF2A = Interpolator(fmin,fmax,amin,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Base class for ZoneControl
//--------------------------------------------------------------------------------------
class ZoneControl
{

    protected:

        FAUSTFLOAT*	fZone;

    public:

        ZoneControl(FAUSTFLOAT* zone) : fZone(zone) {}
        virtual ~ZoneControl() {}

        virtual void update(double v) {}

        virtual void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max) {}
        virtual void getMappingValues(double& amin, double& amid, double& amax) {}

        FAUSTFLOAT* getZone() { return fZone; }

        virtual void setActive(bool on_off) {}
        virtual bool getActive() { return false; }

        virtual int getCurve() { return -1; }

};

//--------------------------------------------------------------------------------------
//  Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class ConverterZoneControl : public ZoneControl
{

    private:

        ValueConverter* fValueConverter;

    public:

        ConverterZoneControl(FAUSTFLOAT* zone, ValueConverter* valueConverter) : ZoneControl(zone), fValueConverter(valueConverter) {}
        virtual ~ConverterZoneControl() { delete fValueConverter; } // Assuming fValueConverter is not kept elsewhere...

        void update(double v) { *fZone = fValueConverter->ui2faust(v); }

        ValueConverter* getConverter() { return fValueConverter; }

};

//--------------------------------------------------------------------------------------
// Association of a zone and a four value converter, each one for each possible curve.
// Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class CurveZoneControl : public ZoneControl
{

    private:

        std::vector<UpdatableValueConverter*> fValueConverters;
        int fCurve;

    public:

        CurveZoneControl(FAUSTFLOAT* zone, int curve, double amin, double amid, double amax, double min, double init, double max) : ZoneControl(zone), fCurve(0)
        {
            assert(curve >= 0 && curve <= 3);
            fValueConverters.push_back(new AccUpConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccUpDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownUpConverter(amin, amid, amax, min, init, max));
            fCurve = curve;
        }
        virtual ~CurveZoneControl()
        {
            std::vector<UpdatableValueConverter*>::iterator it;
            for (it = fValueConverters.begin(); it != fValueConverters.end(); it++) {
                delete(*it);
            }
        }
        void update(double v) { if (fValueConverters[fCurve]->getActive()) *fZone = fValueConverters[fCurve]->ui2faust(v); }

        void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max)
        {
            fValueConverters[curve]->setMappingValues(amin, amid, amax, min, init, max);
            fCurve = curve;
        }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fValueConverters[fCurve]->getMappingValues(amin, amid, amax);
        }

        void setActive(bool on_off)
        {
            std::vector<UpdatableValueConverter*>::iterator it;
            for (it = fValueConverters.begin(); it != fValueConverters.end(); it++) {
                (*it)->setActive(on_off);
            }
        }

        int getCurve() { return fCurve; }
};

class ZoneReader
{

    private:

        FAUSTFLOAT* fZone;
        Interpolator fInterpolator;

    public:

        ZoneReader(FAUSTFLOAT* zone, double lo, double hi) : fZone(zone), fInterpolator(lo, hi, 0, 255) {}

        virtual ~ZoneReader() {}

        int getValue()
        {
            if (fZone != 0) {
                return (int)fInterpolator(*fZone);
            } else {
                return 127;
            }
        }

};

#endif

#ifdef _MSC_VER
#define gsscanf sscanf_s
#else
#define gsscanf sscanf
#endif

/*****************************************************************************
* Helper code for MIDI meta and polyphonic 'nvoices' parsing
******************************************************************************/

struct MidiMeta : public Meta, public std::map<std::string, std::string>
{
    void declare(const char* key, const char* value)
    {
        (*this)[key] = value;
    }
    
    const std::string get(const char* key, const char* def)
    {
        if (this->find(key) != this->end()) {
            return (*this)[key];
        } else {
            return def;
        }
    }
    
    static void analyse(dsp* tmp_dsp, bool& midi_sync, int& nvoices)
    {
        JSONUI jsonui;
        tmp_dsp->buildUserInterface(&jsonui);
        std::string json = jsonui.JSON();
        midi_sync = ((json.find("midi") != std::string::npos) &&
                     ((json.find("start") != std::string::npos) ||
                      (json.find("stop") != std::string::npos) ||
                      (json.find("clock") != std::string::npos)));
    
    #if defined(NVOICES) && NVOICES!=NUM_VOICES
        nvoices = NVOICES;
    #else
        MidiMeta meta;
        tmp_dsp->metadata(&meta);
        std::string numVoices = meta.get("nvoices", "0");
        nvoices = std::atoi(numVoices.c_str());
        if (nvoices < 0) nvoices = 0;
    #endif
    }
};

/*******************************************************************************
 * MidiUI : Faust User Interface
 * This class decodes MIDI meta data and maps incoming MIDI messages to them.
 * Currently ctrl, keyon/keyoff, keypress, pgm, chanpress, pitchwheel/pitchbend
 * start/stop/clock meta data is handled.
 ******************************************************************************/

class uiMidi {
    
    protected:
        
        midi* fMidiOut;
        bool fInputCtrl;
        
    public:
        
        uiMidi(midi* midi_out, bool input):fMidiOut(midi_out), fInputCtrl(input)
        {}
        virtual ~uiMidi()
        {}
    
};

class uiMidiItem : public uiMidi, public uiItem {
    
    public:
        
        uiMidiItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidi(midi_out, input), uiItem(ui, zone)
        {}
        virtual ~uiMidiItem()
        {}
    
        virtual void reflectZone() {}
    
};

class uiMidiTimedItem : public uiMidi, public uiTimedItem {
    
    public:
        
        uiMidiTimedItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidi(midi_out, input), uiTimedItem(ui, zone)
        {}
        virtual ~uiMidiTimedItem()
        {}
    
        virtual void reflectZone() {}
    
};

// MIDI sync

class uiMidiStart : public uiMidiTimedItem
{
  
    public:
    
        uiMidiStart(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiStart()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->start_sync(0);
            }
        }
        
};

class uiMidiStop : public uiMidiTimedItem
{
  
    public:
    
        uiMidiStop(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiStop()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(1)) {
                fMidiOut->stop_sync(0);
            }
        }
};

class uiMidiClock : public uiMidiTimedItem
{

    private:
        
        bool fState;
  
    public:
    
        uiMidiClock(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input), fState(false)
        {}
        virtual ~uiMidiClock()
        {}
    
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->clock(0);
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                fState = !fState;
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fState));
            }
        }

};

class uiMidiProgChange : public uiMidiItem
{
    
    private:
        
        int fPgm;
  
    public:
    
        uiMidiProgChange(midi* midi_out, int pgm, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fPgm(pgm)
        {}
        virtual ~uiMidiProgChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->progChange(0, fPgm);
            }
        }
        
};

class uiMidiChanPress : public uiMidiItem
{
    private:
        
        int fPress;
  
    public:
    
        uiMidiChanPress(midi* midi_out, int press, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fPress(press)
        {}
        virtual ~uiMidiChanPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->chanPress(0, fPress);
            }
        }
        
};

class uiMidiCtrlChange : public uiMidiItem
{
    private:
    
        int fCtrl;
        LinearValueConverter fConverter;
 
    public:
    
        uiMidiCtrlChange(midi* midi_out, int ctrl, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fCtrl(ctrl), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiCtrlChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->ctrlChange(0, fCtrl, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
 
};

class uiMidiPitchWheel : public uiMidiItem
{

    private:
    	
		// currently, the range is of pitchwheel if fixed (-2/2 semitones)
        FAUSTFLOAT wheel2bend(float v)
        {
            return std::pow(2.0,(v/16383.0*4-2)/12);
        }

        int bend2wheel(float v)
        {
            return (int)((12*std::log(v)/std::log(2.0)+2)/4*16383);
        }
 
    public:
    
        uiMidiPitchWheel(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiPitchWheel()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->pitchWheel(0, bend2wheel(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(wheel2bend(v));
            }
        }
 
};

class uiMidiKeyOn : public uiMidiItem
{

    private:
        
        int fKeyOn;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyOn(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKeyOn(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyOn()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyOn(0, fKeyOn, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};

class uiMidiKeyOff : public uiMidiItem
{

    private:
        
        int fKeyOff;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyOff(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKeyOff(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyOff()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyOff(0, fKeyOff, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};


class uiMidiKeyPress : public uiMidiItem
{

    private:
    
        int fKey;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyPress(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKey(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyPress(0, fKey, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};

class MapUI;

class MidiUI : public GUI, public midi
{

    protected:
    
        std::map <int, std::vector<uiMidiCtrlChange*> > fCtrlChangeTable;
        std::map <int, std::vector<uiMidiProgChange*> > fProgChangeTable;
        std::map <int, std::vector<uiMidiChanPress*> >  fChanPressTable;
        std::map <int, std::vector<uiMidiKeyOn*> >      fKeyOnTable;
        std::map <int, std::vector<uiMidiKeyOff*> >     fKeyOffTable;
        std::map <int, std::vector<uiMidiKeyOn*> >      fKeyTable;
        std::map <int, std::vector<uiMidiKeyPress*> >   fKeyPressTable;
        std::vector<uiMidiPitchWheel*>                  fPitchWheelTable;
        
        std::vector<uiMidiStart*>   fStartTable;
        std::vector<uiMidiStop*>    fStopTable;
        std::vector<uiMidiClock*>   fClockTable;
        
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        
        midi_handler* fMidiHandler;
        bool fDelete;
    
        void addGenericZone(FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
        {
            if (fMetaAux.size() > 0) {
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    unsigned num;
                    if (fMetaAux[i].first == "midi") {
                        if (gsscanf(fMetaAux[i].second.c_str(), "ctrl %u", &num) == 1) {
                            fCtrlChangeTable[num].push_back(new uiMidiCtrlChange(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyon %u", &num) == 1) {
                            fKeyOnTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyoff %u", &num) == 1) {
                            fKeyOffTable[num].push_back(new uiMidiKeyOff(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "key %u", &num) == 1) {
                            fKeyTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keypress %u", &num) == 1) {
                            fKeyPressTable[num].push_back(new uiMidiKeyPress(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "pgm %u", &num) == 1) {
                            fProgChangeTable[num].push_back(new uiMidiProgChange(fMidiHandler, num, this, zone, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "chanpress %u", &num) == 1) {
                            fChanPressTable[num].push_back(new uiMidiChanPress(fMidiHandler, num, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "pitchwheel") == 0 
                            || strcmp(fMetaAux[i].second.c_str(), "pitchbend") == 0) {
                            fPitchWheelTable.push_back(new uiMidiPitchWheel(fMidiHandler, this, zone, input));
                        // MIDI sync
                        } else if (strcmp(fMetaAux[i].second.c_str(), "start") == 0) {
                            fStartTable.push_back(new uiMidiStart(fMidiHandler, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "stop") == 0) {
                            fStopTable.push_back(new uiMidiStop(fMidiHandler, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "clock") == 0) {
                            fClockTable.push_back(new uiMidiClock(fMidiHandler, this, zone, input));
                        }
                    }
                }
            }
            fMetaAux.clear();
        }

    public:
    
        MidiUI():fMidiHandler(NULL), fDelete(false)
        {}

        MidiUI(midi_handler* midi_handler, bool delete_handler = false)
        {
            fMidiHandler = midi_handler;
            fMidiHandler->addMidiIn(this);
            fDelete = delete_handler;
        }
 
        virtual ~MidiUI() 
        { 
            fMidiHandler->removeMidiIn(this);
            if (fDelete) delete fMidiHandler;
        }
        
        bool run() { return fMidiHandler->start_midi(); }
        void stop() { fMidiHandler->stop_midi(); }
        
        void addMidiIn(midi* midi_dsp) { fMidiHandler->addMidiIn(midi_dsp); }
        void removeMidiIn(midi* midi_dsp) { fMidiHandler->removeMidiIn(midi_dsp); }
      
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericZone(zone, FAUSTFLOAT(0), FAUSTFLOAT(1));
        }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericZone(zone, FAUSTFLOAT(0), FAUSTFLOAT(1));
        }
        
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            addGenericZone(zone, min, max, false);
        }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addGenericZone(zone, min, max, false);
        }

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            fMetaAux.push_back(std::make_pair(key, val));
        }
        
        // -- MIDI API 
        
        MapUI* keyOn(double date, int channel, int note, int velocity)
        {
            if (fKeyOnTable.find(note) != fKeyOnTable.end()) {
                for (unsigned int i = 0; i < fKeyOnTable[note].size(); i++) {
                    fKeyOnTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                }
            }
            // If note is in fKeyTable, handle it as a keyOn
            if (fKeyTable.find(note) != fKeyTable.end()) {
                for (unsigned int i = 0; i < fKeyTable[note].size(); i++) {
                    fKeyTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                }
            }
            return 0;
        }
        
        void keyOff(double date, int channel, int note, int velocity)
        {
            if (fKeyOffTable.find(note) != fKeyOffTable.end()) {
                for (unsigned int i = 0; i < fKeyOffTable[note].size(); i++) {
                    fKeyOffTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                }
            }
            // If note is in fKeyTable, handle it as a keyOff with a 0 velocity
            if (fKeyTable.find(note) != fKeyTable.end()) {
                for (unsigned int i = 0; i < fKeyTable[note].size(); i++) {
                    fKeyTable[note][i]->modifyZone(0);
                }
            }
        }
           
        void ctrlChange(double date, int channel, int ctrl, int value)
        {
            if (fCtrlChangeTable.find(ctrl) != fCtrlChangeTable.end()) {
                for (unsigned int i = 0; i < fCtrlChangeTable[ctrl].size(); i++) {
                    fCtrlChangeTable[ctrl][i]->modifyZone(FAUSTFLOAT(value));
                }
            } 
        }
        
        void progChange(double date, int channel, int pgm)
        {
            if (fProgChangeTable.find(pgm) != fProgChangeTable.end()) {
                for (unsigned int i = 0; i < fProgChangeTable[pgm].size(); i++) {
                    fProgChangeTable[pgm][i]->modifyZone(FAUSTFLOAT(1));
                }
            } 
        }
        
        void pitchWheel(double date, int channel, int wheel) 
        {
            for (unsigned int i = 0; i < fPitchWheelTable.size(); i++) {
                fPitchWheelTable[i]->modifyZone(FAUSTFLOAT(wheel));
            }
        }
        
        void keyPress(double date, int channel, int pitch, int press) 
        {
            if (fKeyPressTable.find(pitch) != fKeyPressTable.end()) {
                for (unsigned int i = 0; i < fKeyPressTable[pitch].size(); i++) {
                    fKeyPressTable[pitch][i]->modifyZone(FAUSTFLOAT(press));
                }
            } 
        }
        
        void chanPress(double date, int channel, int press)
        {
            if (fChanPressTable.find(press) != fChanPressTable.end()) {
                for (unsigned int i = 0; i < fChanPressTable[press].size(); i++) {
                    fChanPressTable[press][i]->modifyZone(FAUSTFLOAT(1));
                }
            } 
        }
        
        void ctrlChange14bits(double date, int channel, int ctrl, int value) {}
        
        // MIDI sync
        
        void start_sync(double date)
        {
            for (unsigned int i = 0; i < fStartTable.size(); i++) {
                fStartTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
        
        void stop_sync(double date)
        {
            for (unsigned int i = 0; i < fStopTable.size(); i++) {
                fStopTable[i]->modifyZone(date, FAUSTFLOAT(0));
            }
        }
        
        void clock(double date)
        {
            for (unsigned int i = 0; i < fClockTable.size(); i++) {
                fClockTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
};

#endif // FAUST_MIDIUI_H
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __poly_dsp__
#define __poly_dsp__

#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <ostream>
#include <sstream>
#include <vector>
#include <limits.h>
#include <float.h>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_MAPUI_H
#define FAUST_MAPUI_H

#include <vector>
#include <map>
#include <string>


/*******************************************************************************
 * MapUI : Faust User Interface
 * This class creates a map of complete hierarchical path and zones for each UI items.
 ******************************************************************************/

class MapUI : public UI, public PathBuilder
{
    
    protected:
    
        // Complete path map
        std::map<std::string, FAUSTFLOAT*> fPathZoneMap;
    
        // Label zone map
        std::map<std::string, FAUSTFLOAT*> fLabelZoneMap;
    
    public:
        
        MapUI() {};
        virtual ~MapUI() {};
        
        // -- widget's layouts
        void openTabBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openHorizontalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openVerticalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void closeBox()
        {
            fControlsLevel.pop_back();
        }
        
        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        
        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
        
        // -- metadata declarations
        void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {}
        
        // set/get
        void setParamValue(const std::string& path, FAUSTFLOAT value)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                *fPathZoneMap[path] = value;
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                *fLabelZoneMap[path] = value;
            }
        }
        
        FAUSTFLOAT getParamValue(const std::string& path)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                return *fPathZoneMap[path];
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                return *fLabelZoneMap[path];
            } else {
                return FAUSTFLOAT(0);
            }
        }
    
        // map access 
        std::map<std::string, FAUSTFLOAT*>& getMap() { return fPathZoneMap; }
        
        int getParamsCount() { return int(fPathZoneMap.size()); }
        
        std::string getParamAddress(int index)
        { 
            std::map<std::string, FAUSTFLOAT*>::iterator it = fPathZoneMap.begin();
            while (index-- > 0 && it++ != fPathZoneMap.end()) {}
            return (*it).first;
        }
    
        std::string getParamAddress(FAUSTFLOAT* zone)
        {
            std::map<std::string, FAUSTFLOAT*>::iterator it = fPathZoneMap.begin();
            do {
                if ((*it).second == zone) return (*it).first;
            }
            while (it++ != fPathZoneMap.end());
            return "";
        }
};

#endif // FAUST_MAPUI_H
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __proxy_dsp__
#define __proxy_dsp__

#include <vector>
#include <map>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __JSONUIDecoder__
#define __JSONUIDecoder__

#include <vector>
#include <map>
#include <utility>
#include <assert.h>
#include <cstdlib>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef SIMPLEPARSER_H
#define SIMPLEPARSER_H

// ---------------------------------------------------------------------
//                          Simple Parser
// A parser returns true if it was able to parse what it is
// supposed to parse and advance the pointer. Otherwise it returns false
// and the pointer is not advanced so that another parser can be tried.
// ---------------------------------------------------------------------

#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <ctype.h>

#ifndef _WIN32
# pragma GCC diagnostic ignored "-Wunused-function"
#endif

using namespace std;

struct itemInfo {
    std::string type;
    std::string label;
    std::string address;
    std::string index;
    std::string init;
    std::string min;
    std::string max;
    std::string step;
    std::vector<std::pair<std::string, std::string> > meta;
};

bool parseMenuList(const char*& p, vector<string>& names, vector<double>& values);
bool parseMenuItem(const char*& p, string& name, double& value);

void skipBlank(const char*& p);
bool parseChar(const char*& p, char x);
bool parseWord(const char*& p, const char* w);
bool parseString(const char*& p, char quote, string& s);
bool parseSQString(const char*& p, string& s);
bool parseDQString(const char*& p, string& s);
bool parseDouble(const char*& p, double& x);

// ---------------------------------------------------------------------
//
//                          IMPLEMENTATION
// 
// ---------------------------------------------------------------------

/**
 * @brief parseMenuList, parse a menu list {'low' : 440.0; 'mid' : 880.0; 'hi' : 1760.0}...
 * @param p the string to parse, then the remaining string
 * @param names the vector of names found
 * @param values the vector of values found
 * @return true if a menu list was found
 */
inline bool parseMenuList(const char*& p, vector<string>& names, vector<double>& values)
{
    vector<string> tmpnames;
    vector<double> tmpvalues;

    const char* saved = p;

    if (parseChar(p, '{')) {
        do {
            string n;
            double v;
            if (parseMenuItem(p, n, v)) {
                tmpnames.push_back(n);
                tmpvalues.push_back(v);
            } else {
                p = saved;
                return false;
            }
        } while (parseChar(p, ';'));
        if (parseChar(p, '}')) {
            // we suceeded
            names = tmpnames;
            values = tmpvalues;
            return true;
        }
    }
    p = saved;
    return false;
}

/**
 * @brief parseMenuItem, parse a menu item ...'low':440.0...
 * @param p the string to parse, then the remaining string
 * @param name the name found
 * @param value the value found
 * @return true if a nemu item was found
 */
inline bool parseMenuItem(const char*& p, string& name, double& value)
{
    const char* saved = p;
    if (parseSQString(p, name) && parseChar(p, ':') && parseDouble(p, value)) {
        return true;
    } else {
        p = saved;
        return false;
    }
}

// ---------------------------------------------------------------------
//                          Elementary parsers
// ---------------------------------------------------------------------

// Report a parsing error
static bool parseError(const char*& p, const char* errmsg)
{
    std::cerr << "Parse error : " << errmsg << " here : " << p << std::endl;
    return true;
}

// Parse character x, but don't report error if fails
static bool tryChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief skipBlank : advance pointer p to the first non blank character
 * @param p the string to parse, then the remaining string
 */
inline void skipBlank(const char*& p)
{
    while (isspace(*p)) { p++; }
}

/**
 * @brief parseChar : parse a specific character x
 * @param p the string to parse, then the remaining string
 * @param x the character to recognize
 * @return true if x was found at the begin of p
 */
inline bool parseChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief parseWord : parse a specific string w
 * @param p the string to parse, then the remaining string
 * @param w the string to recognize
 * @return true if string w was found at the begin of p
 */
inline bool parseWord(const char*& p, const char* w)
{
    skipBlank(p);
    const char* saved = p;
    while ((*w == *p) && (*w)) {++w; ++p;}
    if (*w) {
        p = saved;
        return false;
    } else {
        return true;
    }
}

/**
 * @brief parseDouble : parse number [s]dddd[.dddd] and store the result in x
 * @param p the string to parse, then the remaining string
 * @param x the float number found if any
 * @return true if a float number was found at the begin of p
 */
inline bool parseDouble(const char*& p, double& x)
{
    double sign = +1.0;    // sign of the number
    double ipart = 0;      // integral part of the number
    double dpart = 0;      // decimal part of the number before division
    double dcoef = 1.0;    // division factor for the decimal part

    bool valid = false;   // true if the number contains at least one digit
    skipBlank(p);
    const char* saved = p;  // to restore position if we fail

    if (parseChar(p, '+')) {
        sign = 1.0;
    } else if (parseChar(p, '-')) {
        sign = -1.0;
    }
    while (isdigit(*p)) {
        valid = true;
        ipart = ipart*10 + (*p - '0');
        p++;
    }
    if (parseChar(p, '.')) {
        while (isdigit(*p)) {
            valid = true;
            dpart = dpart*10 + (*p - '0');
            dcoef *= 10.0;
            p++;
        }
    }
    if (valid)  {
        x = sign*(ipart + dpart/dcoef);
    } else {
        p = saved;
    }
    return valid;
}

/**
 * @brief parseString, parse an arbitrary quoted string q...q and store the result in s
 * @param p the string to parse, then the remaining string
 * @param quote the character used to quote the string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
inline bool parseString(const char*& p, char quote, string& s)
{
    string str;
    skipBlank(p);
 
    const char* saved = p;
    if (*p++ == quote) {
        while ((*p != 0) && (*p != quote)) {
            str += *p++;
        }
        if (*p++ == quote) {
            s = str;
            return true;
        }
    }
    p = saved;
    return false;
}

/**
 * @brief parseSQString, parse a single quoted string '...' and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
inline bool parseSQString(const char*& p, string& s)
{
    return parseString(p, '\'', s);
}

/**
 * @brief parseDQString, parse a double quoted string "..." and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
inline bool parseDQString(const char*& p, string& s)
{
    return parseString(p, '"', s);
}

static bool parseMetaData(const char*& p, std::map<std::string, std::string>& metadatas)
{
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas[metaKey] = metaValue;
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        return false;
    }
}

static bool parseItemMetaData(const char*& p, std::vector<std::pair<std::string, std::string> >& metadatas)
{
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas.push_back(std::make_pair(metaKey, metaValue));
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse metadatas of the interface:
// "name" : "...", "inputs" : "...", "outputs" : "...", ...
// and store the result as key/value
//
static bool parseGlobalMetaData(const char*& p, std::string& key, std::string& value, std::map<std::string, std::string>& metadatas)
{
    if (parseDQString(p, key)) {
        if (key == "meta") {
            return parseMetaData(p, metadatas);
        } else {
            return parseChar(p, ':') && parseDQString(p, value);
        }
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse gui:
// "type" : "...", "label" : "...", "address" : "...", ...
// and store the result in uiItems Vector
//
static bool parseUI(const char*& p, std::vector<itemInfo*>& uiItems, int& numItems)
{
    if (parseChar(p, '{')) {
        
        std::string label;
        std::string value;
        
        do {
            if (parseDQString(p, label)) {
                if (label == "type") {
                    if (uiItems.size() != 0) {
                        numItems++;
                    }
                    if (parseChar(p, ':') && parseDQString(p, value)) {   
                        itemInfo* item = new itemInfo;
                        item->type = value;
                        uiItems.push_back(item);
                    }
                }
                
                else if (label == "label") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->label = value;
                    }
                }
                
                else if (label == "address") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->address = value;
                    }
                }
                
                else if (label == "index") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->index = value;
                    }
                }
                
                else if (label == "meta") {
                    itemInfo* item = uiItems[numItems];
                    if (!parseItemMetaData(p, item->meta)) {
                        return false;
                    }
                }
                
                else if (label == "init") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->init = value;
                    }
                }
                
                else if (label == "min") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->min = value;
                    }
                }
                
                else if (label == "max") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->max = value;
                    }
                }
                
                else if (label == "step"){
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->step = value;
                    }
                }
                
                else if (label == "items") {
                    if (parseChar(p, ':') && parseChar(p, '[')) {
                        do { 
                            if (!parseUI(p, uiItems, numItems)) {
                                return false;
                            }
                        } while (tryChar(p, ','));
                        if (parseChar(p, ']')) {
                            itemInfo* item = new itemInfo;
                            item->type = "close";
                            uiItems.push_back(item);
                            numItems++;
                        }
                    }
                }
            } else {
                return false;
            }
            
        } while (tryChar(p, ','));
        
        return parseChar(p, '}');
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse full JSON record describing a JSON/Faust interface :
// {"metadatas": "...", "ui": [{ "type": "...", "label": "...", "items": [...], "address": "...","init": "...", "min": "...", "max": "...","step": "..."}]}
//
// and store the result in map Metadatas and vector containing the items of the interface. Returns true if parsing was successfull.
//

inline bool parseJson(const char*& p, std::map<std::string, std::string>& metadatas, std::vector<itemInfo*>& uiItems)
{
    parseChar(p, '{');
    
    do {
        std::string key;
        std::string value;
        if (parseGlobalMetaData(p, key, value, metadatas)) {
            if (key != "meta") {
                // keep "name", "inputs", "outputs" key/value pairs
                metadatas[key] = value;
            }
        } else if (key == "ui") {
            int numItems = 0;
            parseChar(p, '[') && parseUI(p, uiItems, numItems);
        }
    } while (tryChar(p, ','));
    
    return parseChar(p, '}');
}

#endif // SIMPLEPARSER_H

#ifdef _WIN32
#include <windows.h>
#define snprintf _snprintf
#endif

inline FAUSTFLOAT STR2REAL(const std::string& s) { return (std::strtod(s.c_str(), NULL)); }

//-------------------------------------------------------------------
//  Decode a dsp JSON description and implement 'buildUserInterface'
//-------------------------------------------------------------------

typedef std::map<std::string, pair <int, FAUSTFLOAT*> > controlMap;

struct JSONUIDecoder {

    std::string fName;
    std::string fFileName;
    
    std::map<std::string, std::string> fMetadatas; 
    std::vector<itemInfo*> fUiItems;     
    
    FAUSTFLOAT* fInControl;
    FAUSTFLOAT* fOutControl;
    
    std::string fJSON;
    
    int fNumInputs, fNumOutputs; 
    int fInputItems, fOutputItems;
    
    std::string fVersion;
    std::string fOptions;
    
    int fDSPSize;
    
    controlMap fPathInputTable;     // [path, <index, zone>]
    controlMap fPathOutputTable;    // [path, <index, zone>]
    
    bool isInput(const string& type) { return (type == "vslider" || type == "hslider" || type == "nentry" || type == "button" || type == "checkbox"); }
    bool isOutput(const string& type) { return (type == "hbargraph" || type == "vbargraph"); }

    JSONUIDecoder(const std::string& json) 
    {
        fJSON = json;
        const char* p = fJSON.c_str();
        parseJson(p, fMetadatas, fUiItems);
        
        // fMetadatas will contain the "meta" section as well as <name : val>, <inputs : val>, <ouputs : val> pairs
        if (fMetadatas.find("name") != fMetadatas.end()) {
            fName = fMetadatas["name"];
            fMetadatas.erase("name");
        } else {
            fName = "";
        }
        
        if (fMetadatas.find("filename") != fMetadatas.end()) {
            fFileName = fMetadatas["filename"];
            fMetadatas.erase("filename");
        } else {
            fName = "";
        }
     
        if (fMetadatas.find("version") != fMetadatas.end()) {
            fVersion = fMetadatas["version"];
            fMetadatas.erase("version");
        } else {
            fVersion = "";
        }
        
        if (fMetadatas.find("options") != fMetadatas.end()) {
            fOptions = fMetadatas["options"];
            fMetadatas.erase("options");
        } else {
            fOptions = "";
        }
        
        if (fMetadatas.find("size") != fMetadatas.end()) {
            fDSPSize = std::atoi(fMetadatas["size"].c_str());
            fMetadatas.erase("size");
        } else {
            fDSPSize = -1;
        }
         
        if (fMetadatas.find("inputs") != fMetadatas.end()) {
            fNumInputs = std::atoi(fMetadatas["inputs"].c_str());
            fMetadatas.erase("inputs");
        } else {
            fNumInputs = -1;
        }
        
        if (fMetadatas.find("outputs") != fMetadatas.end()) {
            fNumOutputs = std::atoi(fMetadatas["outputs"].c_str());
            fMetadatas.erase("outputs");
        } else {
            fNumOutputs = -1;
        }
       
        fInputItems = 0;
        fOutputItems = 0;
        
        vector<itemInfo*>::iterator it;
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            string type = (*it)->type;
            if (isInput(type)) {
                fInputItems++;
            } else if (isOutput(type)) {
                fOutputItems++;          
            }
        }
        
        fInControl = new FAUSTFLOAT[fInputItems];
        fOutControl = new FAUSTFLOAT[fOutputItems];
        
        int counterIn = 0;
        int counterOut = 0;
        
        // Prepare the fPathTable and init zone
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            string type = (*it)->type;
            // Meta data declaration for input items
            if (isInput(type)) {
                if ((*it)->address != "") {
                    fPathInputTable[(*it)->address] = make_pair(std::atoi((*it)->index.c_str()), &fInControl[counterIn]);
                }
                fInControl[counterIn] = STR2REAL((*it)->init);
                counterIn++;
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                if ((*it)->address != "") {
                    fPathOutputTable[(*it)->address] = make_pair(std::atoi((*it)->index.c_str()), &fOutControl[counterOut]);
                }
                fOutControl[counterOut] = FAUSTFLOAT(0);
                counterOut++;
            }
        }
    }
    
    virtual ~JSONUIDecoder() 
    {
        vector<itemInfo*>::iterator it;
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            delete(*it);
        }
        delete [] fInControl;
        delete [] fOutControl;
    }
    
    void metadata(Meta* m)
    {
        std::map<std::string, std::string>::iterator it;
        for (it = fMetadatas.begin(); it != fMetadatas.end(); it++) {
            m->declare((*it).first.c_str(), (*it).second.c_str());
        }
    }
    
    void resetUserInterface()
    {
        vector<itemInfo*>::iterator it;
        int item = 0;
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            if (isInput((*it)->type)) {
                fInControl[item++] = STR2REAL((*it)->init);
            }
        }
    }
   
    void buildUserInterface(UI* ui)
    {
        // To be sure the floats are correctly encoded
        char* tmp_local = setlocale(LC_ALL, NULL);
        setlocale(LC_ALL, "C");

        int counterIn = 0;
        int counterOut = 0;
        vector<itemInfo*>::iterator it;
        
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            
            bool isInItem = false;
            bool isOutItem = false;
            string type = (*it)->type;
            
            FAUSTFLOAT init = STR2REAL((*it)->init);
            FAUSTFLOAT min = STR2REAL((*it)->min);
            FAUSTFLOAT max = STR2REAL((*it)->max);
            FAUSTFLOAT step = STR2REAL((*it)->step);
            
            if (isInput(type)) {
                isInItem = true;
            } else if (isOutput(type)) {
                isOutItem = true;
            }
            
            // Meta data declaration for input items
            if (isInput(type)) {
                fInControl[counterIn] = init;
                for (size_t i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(&fInControl[counterIn], (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                fOutControl[counterOut] = init;
                for (size_t i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(&fOutControl[counterOut], (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            // Meta data declaration for group opening or closing
            else {
                for (size_t i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(0, (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            
            if (type == "hgroup") {
                ui->openHorizontalBox((*it)->label.c_str());
            } else if (type == "vgroup") { 
                ui->openVerticalBox((*it)->label.c_str());
            } else if (type == "tgroup") {
                ui->openTabBox((*it)->label.c_str());
            } else if (type == "vslider") {
                ui->addVerticalSlider((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);
            } else if (type == "hslider") {
                ui->addHorizontalSlider((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);            
            } else if (type == "checkbox") {
                ui->addCheckButton((*it)->label.c_str(), &fInControl[counterIn]);
            } else if (type == "hbargraph") {
                ui->addHorizontalBargraph((*it)->label.c_str(), &fOutControl[counterOut], min, max);
            } else if (type == "vbargraph") {
                ui->addVerticalBargraph((*it)->label.c_str(), &fOutControl[counterOut], min, max);
            } else if (type == "nentry") {
                ui->addNumEntry((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);
            } else if (type == "button") {
                ui->addButton((*it)->label.c_str(), &fInControl[counterIn]);
            } else if (type == "close") {
                ui->closeBox();
            }
                
            if (isInItem) {
                counterIn++;
            }
                
            if (isOutItem) {
                counterOut++;
            }
        }
        
        setlocale(LC_ALL, tmp_local);
    }
    
};


#endif

//----------------------------------------------------------------
//  Proxy dsp definition created from the DSP JSON description
//  This class allows a 'proxy' dsp to control a real dsp 
//  possibly running somewhere else.
//----------------------------------------------------------------

class proxy_dsp : public dsp {

    private:
    
        int fSamplingFreq;
        JSONUIDecoder* fDecoder;
        
    public:
    
        proxy_dsp(const string& json)
        {
            fDecoder = new JSONUIDecoder(json);
            fSamplingFreq = -1;
        }
          
        proxy_dsp(dsp* dsp)
        {
            JSONUI builder(dsp->getNumInputs(), dsp->getNumOutputs());
            dsp->metadata(&builder);
            dsp->buildUserInterface(&builder);
            fSamplingFreq = dsp->getSampleRate();
            fDecoder = new JSONUIDecoder(builder.JSON());
        }
      
        virtual ~proxy_dsp()
        {
            delete fDecoder;
        }
       
        virtual int getNumInputs() 	{ return fDecoder->fNumInputs; }
        virtual int getNumOutputs() { return fDecoder->fNumOutputs; }
        
        virtual void buildUserInterface(UI* ui) { fDecoder->buildUserInterface(ui); }
        
        // To possibly implement in a concrete proxy dsp 
        virtual void init(int samplingFreq)
        {
            instanceInit(samplingFreq);
        }
        virtual void instanceInit(int samplingFreq)
        {
            instanceConstants(samplingFreq);
            instanceResetUserInterface();
            instanceClear();
        }
        virtual void instanceConstants(int samplingRate) { fSamplingFreq = samplingRate; }
        virtual void instanceResetUserInterface() { fDecoder->resetUserInterface(); }
        virtual void instanceClear() {}
    
        virtual int getSampleRate() { return fSamplingFreq; }
    
        virtual proxy_dsp* clone() { return new proxy_dsp(fDecoder->fJSON); }
        virtual void metadata(Meta* m) { fDecoder->metadata(m); }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {}
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {} 
        
};

#endif

#define kActiveVoice      0
#define kFreeVoice        -1
#define kReleaseVoice     -2
#define kNoVoice          -3

#define VOICE_STOP_LEVEL  0.001
#define MIX_BUFFER_SIZE   16384

#define FLOAT_MAX(a, b) (((a) < (b)) ? (b) : (a))

// endsWith(<str>,<end>) : returns true if <str> ends with <end>

static inline bool endsWith(std::string const& str, std::string const& end)
{
    size_t l1 = str.length();
    size_t l2 = end.length();
    return (l1 >= l2) && (0 == str.compare(l1 - l2, l2, end));
}

static inline double midiToFreq(double note)
{
    return 440.0 * std::pow(2.0, (note-69.0)/12.0);
}

/**
 * Allows to control zones in a grouped manner.
 */

class GroupUI : public GUI, public PathBuilder
{

    private:

        std::map<std::string, uiGroupItem*> fLabelZoneMap;

        void insertMap(std::string label, FAUSTFLOAT* zone)
        {
            if (!endsWith(label, "/gate")
                && !endsWith(label, "/freq")
                && !endsWith(label, "/gain")) {

                // Groups all controller except 'freq', 'gate', and 'gain'
                if (fLabelZoneMap.find(label) != fLabelZoneMap.end()) {
                    fLabelZoneMap[label]->addZone(zone);
                } else {
                    fLabelZoneMap[label] = new uiGroupItem(this, zone);
                }
            }
        }

        uiCallbackItem* fPanic;

    public:

        GroupUI(FAUSTFLOAT* zone, uiCallback cb, void* arg)
        {
            fPanic = new uiCallbackItem(this, zone, cb, arg);
        }
    
        virtual ~GroupUI()
        {
            // 'fPanic' is kept and deleted in GUI, so do not delete here
        }

        // -- widget's layouts
        void openTabBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openHorizontalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openVerticalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void closeBox()
        {
            fControlsLevel.pop_back();
        }

        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            insertMap(buildPath(label), zone);
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            insertMap(buildPath(label), zone);
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }

        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            insertMap(buildPath(label), zone);
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            insertMap(buildPath(label), zone);
        }

};

/**
 * One voice of polyphony.
 */

struct dsp_voice : public MapUI, public decorator_dsp {

    int fNote;              // Playing note actual pitch
    int fDate;              // KeyOn date
    bool fTrigger;          // True if stolen note and need for envelop trigger
    FAUSTFLOAT fLevel;      // Last audio block level
    std::string fGatePath;  // Path of 'gate' control
    std::string fGainPath;  // Path of 'gain' control
    std::string fFreqPath;  // Path of 'freq' control
    FAUSTFLOAT** fInputsSlice;
    FAUSTFLOAT** fOutputsSlice;
 
    dsp_voice(dsp* dsp):decorator_dsp(dsp)
    {
        dsp->buildUserInterface(this);
        fNote = kFreeVoice;
        fLevel = FAUSTFLOAT(0);
        fDate = 0;
        fTrigger = false;
        extractPaths(fGatePath, fFreqPath, fGainPath);
        fInputsSlice = new FAUSTFLOAT*[dsp->getNumInputs()];
        fOutputsSlice = new FAUSTFLOAT*[dsp->getNumOutputs()];
    }
    virtual ~dsp_voice()
    {
        delete [] fInputsSlice;
        delete [] fOutputsSlice;
    }

    void extractPaths(std::string& gate, std::string& freq, std::string& gain)
    {
        // Keep gain, freq and gate labels
        std::map<std::string, FAUSTFLOAT*>::iterator it;
        for (it = getMap().begin(); it != getMap().end(); it++) {
            std::string path = (*it).first;
            if (endsWith(path, "/gate")) {
                gate = path;
            } else if (endsWith(path, "/freq")) {
                freq = path;
            } else if (endsWith(path, "/gain")) {
                gain = path;
            }
        }
    }

    // MIDI velocity [0..127]
    void keyOn(int pitch, int velocity)
    {
        setParamValue(fFreqPath, midiToFreq(pitch));
        setParamValue(fGainPath, float(velocity)/127.f);
        fNote = pitch;
    }

    // Normalized MIDI velocity [0..1]
    void keyOn(int pitch, float velocity)
    {
        setParamValue(fFreqPath, midiToFreq(pitch));
        setParamValue(fGainPath, velocity);
        fNote = pitch;
    }

    void keyOff(bool hard = false)
    {
        // No use of velocity for now...
        setParamValue(fGatePath, FAUSTFLOAT(0));
        
        if (hard) {
            // Stop immediately
            fNote = kFreeVoice;
            fTrigger = false;
        } else {
            // Release voice
            fNote = kReleaseVoice;
        }
    }

    void play(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        if (fTrigger) {
            // New note, so trigger it
            trigger(count, inputs, outputs);
        } else {
            // Compute the voice
            compute(count, inputs, outputs);
        }
    }

    void trigger(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        setParamValue(fGatePath, FAUSTFLOAT(0));
        computeSlice(0, 1, inputs, outputs);
        setParamValue(fGatePath, FAUSTFLOAT(1));
        computeSlice(1, count - 1, inputs, outputs);
        fTrigger = false;
    }

    void computeSlice(int offset, int slice, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        if (slice > 0) {
            for (int chan = 0; chan < getNumInputs(); chan++) {
                fInputsSlice[chan] = &(inputs[chan][offset]);
            }
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                fOutputsSlice[chan] = &(outputs[chan][offset]);
            }
            compute(slice, fInputsSlice, fOutputsSlice);
        }
    }

};

/**
 * A group of voices.
 */

struct dsp_voice_group {

    GroupUI fGroups;

    std::vector<dsp_voice*> fVoiceTable; // Individual voices
    dsp* fVoiceGroup;                    // Voices group to be used for GUI grouped control

    FAUSTFLOAT fPanic;

    bool fVoiceControl;
    bool fGroupControl;

    dsp_voice_group(uiCallback cb, void* arg, bool control, bool group)
        :fGroups(&fPanic, cb, arg),
        fVoiceGroup(0), fPanic(FAUSTFLOAT(0)),
        fVoiceControl(control), fGroupControl(group)
    {}

    virtual ~dsp_voice_group()
    {
        for (size_t i = 0; i < fVoiceTable.size(); i++) {
            delete fVoiceTable[i];
        }
        delete fVoiceGroup;
    }

    void addVoice(dsp_voice* voice)
    {
        fVoiceTable.push_back(voice);
    }

    void clearVoices()
    {
        fVoiceTable.clear();
    }

    void init()
    {
        // Groups all uiItem for a given path
        fVoiceGroup = new proxy_dsp(fVoiceTable[0]);
        fVoiceGroup->buildUserInterface(&fGroups);
        for (size_t i = 0; i < fVoiceTable.size(); i++) {
            fVoiceTable[i]->buildUserInterface(&fGroups);
        }
    }

    void buildUserInterface(UI* ui_interface)
    {
        if (fVoiceTable.size() > 1) {
            ui_interface->openTabBox("Polyphonic");

            // Grouped voices UI
            ui_interface->openVerticalBox("Voices");
            ui_interface->addButton("Panic", &fPanic);
            fVoiceGroup->buildUserInterface(ui_interface);
            ui_interface->closeBox();

            // If not grouped, also add individual voices UI
            if (!fGroupControl) {
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    char buffer[32];
                    snprintf(buffer, 32, ((fVoiceTable.size() < 8) ? "Voice%ld" : "V%ld"), i+1);
                    ui_interface->openHorizontalBox(buffer);
                    fVoiceTable[i]->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                }
            }

            ui_interface->closeBox();
        } else {
            fVoiceTable[0]->buildUserInterface(ui_interface);
        }
    }

};

/**
 * Base class for Polyphonic DSP.
 */
class dsp_poly : public decorator_dsp, public midi {

    public:
    
        dsp_poly(dsp* dsp):decorator_dsp(dsp)
        {}
    
        virtual ~dsp_poly() {}
};

/**
 * Polyphonic DSP : group a set of DSP to be played together or triggered by MIDI.
 */

class mydsp_poly : public dsp_voice_group, public dsp_poly {

    private:

        FAUSTFLOAT** fMixBuffer;
        int fDate;

        inline FAUSTFLOAT mixVoice(int count, FAUSTFLOAT** outputBuffer, FAUSTFLOAT** mixBuffer)
        {
            FAUSTFLOAT level = 0;
            for (int i = 0; i < getNumOutputs(); i++) {
                FAUSTFLOAT* mixChannel = mixBuffer[i];
                FAUSTFLOAT* outChannel = outputBuffer[i];
                for (int j = 0; j < count; j++) {
                    level = FLOAT_MAX(level, (FAUSTFLOAT)fabs(outChannel[j]));
                    mixChannel[j] += outChannel[j];
                }
            }
            return level;
        }

        inline void clearOutput(int count, FAUSTFLOAT** mixBuffer)
        {
            for (int i = 0; i < getNumOutputs(); i++) {
                memset(mixBuffer[i], 0, count * sizeof(FAUSTFLOAT));
            }
        }
    
        inline int getPlayingVoice(int pitch)
        {
            int voice_playing = kNoVoice;
            int oldest_date_playing = INT_MAX;
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fNote == pitch) {
                    // Keeps oldest playing voice
                    if (fVoiceTable[i]->fDate < oldest_date_playing) {
                        oldest_date_playing = fVoiceTable[i]->fDate;
                        voice_playing = i;
                    }
                }
            }
            
            return voice_playing;
        }
    
        // Always returns a voice
        inline int getFreeVoice()
        {
            int voice = kNoVoice;
            
            // Looks for the first available voice
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fNote == kFreeVoice) {
                    voice = i;
                    goto result;
                }
            }

            {
                // Otherwise steal one
                int voice_release = kNoVoice;
                int voice_playing = kNoVoice;
                
                int oldest_date_release = INT_MAX;
                int oldest_date_playing = INT_MAX;

                // Scan all voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    if (fVoiceTable[i]->fNote == kReleaseVoice) {
                        // Keeps oldest release voice
                        if (fVoiceTable[i]->fDate < oldest_date_release) {
                            oldest_date_release = fVoiceTable[i]->fDate;
                            voice_release = i;
                        }
                    } else {
                        // Otherwise keeps oldest playing voice
                        if (fVoiceTable[i]->fDate < oldest_date_playing) {
                            oldest_date_playing = fVoiceTable[i]->fDate;
                            voice_playing = i;
                        }
                    }
                }
            
                // Then decide which one to steal
                if (oldest_date_release != INT_MAX) {
                    std::cout << "Steal release voice : voice_date " << fVoiceTable[voice_release]->fDate << " cur_date = " << fDate << " voice = " << voice_release << std::endl;
                    voice = voice_release;
                    goto result;
                } else if (oldest_date_playing != INT_MAX) {
                    std::cout << "Steal playing voice : voice_date " << fVoiceTable[voice_playing]->fDate << " cur_date = " << fDate << " voice = " << voice_playing << std::endl;
                    voice = voice_playing;
                    goto result;
                } else {
                    assert(false);
                    return kNoVoice;
                }
            }
            
        result:
            fVoiceTable[voice]->fDate = fDate++;
            fVoiceTable[voice]->fTrigger = true;    // So that envelop is always re-initialized
            fVoiceTable[voice]->fNote = kActiveVoice;
            return voice;
        }

        static void panic(FAUSTFLOAT val, void* arg)
        {
            if (val == FAUSTFLOAT(1)) {
                static_cast<mydsp_poly*>(arg)->allNotesOff(true);
            }
        }

        inline bool checkPolyphony()
        {
            if (fVoiceTable.size() > 0) {
                return true;
            } else {
                std::cout << "DSP is not polyphonic...\n";
                return false;
            }
        }

    public:
    
        /**
         * Constructor.
         *
         * @param dsp - the dsp to be used for one voice. Beware: mydsp_poly will use and finally delete the pointer.
         * @param nvoices - number of polyphony voices
         * @param control - whether voices will be dynamically allocated and controlled (typically by a MIDI controler).
         *                If false all voices are always running.
         * @param group - if true, voices are not individually accessible, a global "Voices" tab will automatically dispatch
         *                a given control on all voices, assuming GUI::updateAllGuis() is called.
         *                If false, all voices can be individually controlled.
         *
         */
        mydsp_poly(dsp* dsp,
                   int nvoices,
                   bool control = false,
                   bool group = true)
        : dsp_voice_group(panic, this, control, group), dsp_poly(dsp)
        {
            fDate = 0;

            // Create voices
            for (int i = 0; i < nvoices; i++) {
                addVoice(new dsp_voice(dsp->clone()));
            }

            // Init audio output buffers
            fMixBuffer = new FAUSTFLOAT*[getNumOutputs()];
            for (int i = 0; i < getNumOutputs(); i++) {
                fMixBuffer[i] = new FAUSTFLOAT[MIX_BUFFER_SIZE];
            }

            dsp_voice_group::init();
        }

        virtual ~mydsp_poly()
        {
            for (int i = 0; i < getNumOutputs(); i++) {
                delete[] fMixBuffer[i];
            }
            delete[] fMixBuffer;
        }

        // DSP API
    
        void buildUserInterface(UI* ui_interface)
        {
            dsp_voice_group::buildUserInterface(ui_interface);
        }

        void init(int samplingRate)
        {
            decorator_dsp::init(samplingRate);
            fVoiceGroup->init(samplingRate);
            fPanic = FAUSTFLOAT(0);
            
            // Init voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->init(samplingRate);
            }
        }
    
        void instanceInit(int samplingFreq)
        {
            instanceConstants(samplingFreq);
            instanceResetUserInterface();
            instanceClear();
        }

        void instanceConstants(int samplingRate)
        {
            decorator_dsp::instanceConstants(samplingRate);
            fVoiceGroup->instanceConstants(samplingRate);
            
            // Init voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceConstants(samplingRate);
            }
        }

        void instanceResetUserInterface()
        {
            decorator_dsp::instanceResetUserInterface();
            fVoiceGroup->instanceResetUserInterface();
            fPanic = FAUSTFLOAT(0);
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceResetUserInterface();
            }
        }

        void instanceClear()
        {
            decorator_dsp::instanceClear();
            fVoiceGroup->instanceClear();
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceClear();
            }
        }

        virtual mydsp_poly* clone()
        {
            return new mydsp_poly(fDSP->clone(), int(fVoiceTable.size()), fVoiceControl, fGroupControl);
        }

        void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            assert(count < MIX_BUFFER_SIZE);

            // First clear the outputs
            clearOutput(count, outputs);

            if (fVoiceControl) {
                // Mix all playing voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    dsp_voice* voice = fVoiceTable[i];
                    if (voice->fNote != kFreeVoice) {
                        voice->play(count, inputs, fMixBuffer);
                        // Mix it in result
                        voice->fLevel = mixVoice(count, fMixBuffer, outputs);
                        // Check the level to possibly set the voice in kFreeVoice again
                        if ((voice->fLevel < VOICE_STOP_LEVEL) && (voice->fNote == kReleaseVoice)) {
                            voice->fNote = kFreeVoice;
                        }
                    }
                }
            } else {
                // Mix all voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    fVoiceTable[i]->compute(count, inputs, fMixBuffer);
                    mixVoice(count, fMixBuffer, outputs);
                }
            }
        }

        void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            compute(count, inputs, outputs);
        }

        // Additional polyphonic API
        MapUI* newVoice()
        {
            return fVoiceTable[getFreeVoice()];
        }

        void deleteVoice(MapUI* voice)
        {
            std::vector<dsp_voice*>::iterator it = find(fVoiceTable.begin(), fVoiceTable.end(), reinterpret_cast<dsp_voice*>(voice));
            if (it != fVoiceTable.end()) {
                (*it)->keyOff();
            } else {
                std::cout << "Voice not found\n";
            }
        }

        // MIDI API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            if (checkPolyphony()) {
                int voice = getFreeVoice();
                fVoiceTable[voice]->keyOn(pitch, velocity);
                return fVoiceTable[voice];
            } else {
                return 0;
            }
        }

        void keyOff(int channel, int pitch, int velocity = 127)
        {
            if (checkPolyphony()) {
                int voice = getPlayingVoice(pitch);
                if (voice != kNoVoice) {
                    fVoiceTable[voice]->keyOff();
                } else {
                    std::cout << "Playing pitch = " << pitch << " not found\n";
                }
            }
        }

        void pitchWheel(int channel, int wheel)
        {}

        void ctrlChange(int channel, int ctrl, int value)
        {
            if (ctrl == ALL_NOTES_OFF || ctrl == ALL_SOUND_OFF) {
                allNotesOff();
            }
        }

        void progChange(int channel, int pgm)
        {}

        void keyPress(int channel, int pitch, int press)
        {}

        void chanPress(int channel, int press)
        {}

        void ctrlChange14bits(int channel, int ctrl, int value)
        {}

        // Terminate all active voices, gently or immediately (depending of 'hard' value)
        void allNotesOff(bool hard = false)
        {
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->keyOff(hard);
            }
        }

};

#endif // __poly_dsp__

std::list<GUI*> GUI::fGuiList;
ztimedmap GUI::gTimedZoneMap;

static const char* getCodeSize()
{
    int tmp;
    return (sizeof(&tmp) == 8) ? "64 bits" : "32 bits";
}

class mspUI;

struct Max_Meta1 : Meta
{
    int fCount;
    
    Max_Meta1():fCount(0)
    {}
     
    void declare(const char* key, const char* value)
    {
        if ((strcmp("name", key) == 0) || (strcmp("author", key) == 0)) {
            fCount++;
        }
    }
};

struct Max_Meta2 : Meta
{
    void declare(const char* key, const char* value)
    {
        if ((strcmp("name", key) == 0) || (strcmp("author", key) == 0)) {
            post("%s : %s", key, value);
        }
    }
};

struct Max_Meta3 : Meta
{
    string fName;
    void declare(const char* key, const char* value)
    {
        if ((strcmp("filename", key) == 0)) {
            fName = "com.grame." + string(value) + "~";
        }
    }
};

/*--------------------------------------------------------------------------*/
typedef struct faust
{
    t_pxobject m_ob;
    t_atom *m_seen, *m_want;
    map<string, vector <t_object*> > m_output_table;
    short m_where;
    bool m_mute;
    void** m_args;
    mspUI* m_dspUI;
    dsp* m_dsp;
    char* m_json;
    t_systhread_mutex m_mutex;    
    int m_Inputs;
    int m_Outputs;
#ifdef MIDICTRL
    MidiUI* m_midiUI;
    midi_handler* m_midiHandler;
#endif
#ifdef SOUNDFILE
    SoundUI* m_soundInterface;
#endif
} t_faust;

void* faust_class;

void faust_create_jsui(t_faust* x);
void faust_make_json(t_faust* x);

/*--------------------------------------------------------------------------*/
class mspUIObject {

	protected:

		string fLabel;
		FAUSTFLOAT* fZone;

		FAUSTFLOAT range(FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT val) {return (val < min) ? min : (val > max) ? max : val;}

	public:

		mspUIObject(const string& label, FAUSTFLOAT* zone):fLabel(label),fZone(zone) {}
		virtual ~mspUIObject() {}

		virtual void setValue(FAUSTFLOAT f) {*fZone = range(0.0,1.0,f);}
        virtual FAUSTFLOAT getValue() { return *fZone; }
		virtual void toString(char* buffer) {}
		virtual string getName() {return fLabel;}
};

/*--------------------------------------------------------------------------*/
class mspCheckButton : public mspUIObject {

	public:

		mspCheckButton(const string& label, FAUSTFLOAT* zone):mspUIObject(label,zone) {}
		virtual ~mspCheckButton() {}

		void toString(char* buffer)
		{
            snprintf(buffer, STR_SIZE, "CheckButton(double): %s", fLabel.c_str());
		}
};

/*--------------------------------------------------------------------------*/
class mspButton : public mspUIObject {

	public:

		mspButton(const string& label, FAUSTFLOAT* zone):mspUIObject(label,zone) {}
		virtual ~mspButton() {}

		void toString(char* buffer)
		{
            snprintf(buffer, STR_SIZE, "Button(double): %s", fLabel.c_str());
		}
};

/*--------------------------------------------------------------------------*/
class mspSlider : public mspUIObject {

	private:

		FAUSTFLOAT fInit;
		FAUSTFLOAT fMin;
		FAUSTFLOAT fMax;
		FAUSTFLOAT fStep;

	public:

		mspSlider(const string& label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
			:mspUIObject(label,zone),fInit(init),fMin(min),fMax(max),fStep(step) {}
		virtual ~mspSlider() {}

        void toString(char* buffer)
        {
            stringstream str;
            str << "Slider(float): " << fLabel << " [init=" << fInit << ":min=" << fMin << ":max=" << fMax << ":step=" << fStep << ":cur=" << *fZone << "]";
            string res = str.str();
            snprintf(buffer, STR_SIZE, "%s", res.c_str());
        }

		void setValue(FAUSTFLOAT f) {*fZone = range(fMin,fMax,f);}
};

/*--------------------------------------------------------------------------*/
class mspBargraph : public mspUIObject {
    
    private:
        
        FAUSTFLOAT fMin;
        FAUSTFLOAT fMax;
        FAUSTFLOAT fCurrent;
        
    public:
        
        mspBargraph(const string& label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        :mspUIObject(label,zone),fMin(min),fMax(max),fCurrent(*zone) {}
        virtual ~mspBargraph() {}
        
        void toString(char* buffer)
        {
            stringstream str;
            str << "Bargraph(float): " << fLabel << " [min=" << fMin << ":max=" << fMax << ":cur=" << *fZone << "]";
            string res = str.str();
            snprintf(buffer, STR_SIZE, "%s", res.c_str());
        }
    
        virtual FAUSTFLOAT getValue() 
        { 
            if (*fZone != fCurrent) {
                fCurrent = *fZone;
                return fCurrent;
            } else {
                return NAN; 
            }
        }
};

/*--------------------------------------------------------------------------*/

#define MULTI_SIZE  256

class mspUI : public UI
{
	private:

        map<string, mspUIObject*> fUITable1;       // Table using labels
        map<string, mspUIObject*> fUITable2;       // Table using complete path
        map<string, mspUIObject*> fUITable3;       // Table containing bargraph
       
        map<const char*, const char*> fDeclareTable;
        std::vector<std::string> fControlsLevel;
        
        FAUSTFLOAT* fMultiTable[MULTI_SIZE];
        int fMultiIndex;
        int fMultiControl;
        
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
        string createLabel(const char* label)
        {
            map<const char*, const char*>::reverse_iterator it;
            if (fDeclareTable.size() > 0) {
                unsigned int i = 0;
                string res = string(label);
                char sep = '[';
                for (it = fDeclareTable.rbegin(); it != fDeclareTable.rend(); it++, i++) {
                    res = res + sep + (*it).first + ":" + (*it).second;
                    sep = ',';
                }
                res += ']';
                fDeclareTable.clear();
                return res;
            } else {
                return string(label);
            }
        }

	public:
    
		typedef map<string, mspUIObject*>::iterator iterator;

		mspUI() 
        {
     		for (int i = 0; i < MULTI_SIZE; i++) {
                fMultiTable[i] = 0;
            }
            fMultiIndex = fMultiControl = 0;
        }
		virtual ~mspUI()
		{
            clear();
   		}
      
		void addButton(const char* label, FAUSTFLOAT* zone) 
        {
            mspUIObject* obj = new mspButton(createLabel(label), zone);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj;
        }
        
        void addCheckButton(const char* label, FAUSTFLOAT* zone) 
        {
            mspUIObject* obj = new mspCheckButton(createLabel(label), zone);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj; 
        }
        
        void addSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            mspUIObject* obj = new mspSlider(createLabel(label), zone, init, min, max, step);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj; 
        }
        
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addSlider(label, zone, init, min, max, step);
        }
        
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addSlider(label, zone, init, min, max, step);
        }
        
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            mspUIObject* obj = new mspSlider(createLabel(label), zone, init, min, max, step);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj;
        }
        
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {   
            fUITable3[buildPath(label)] = new mspBargraph(createLabel(label), zone, min, max);
            fDeclareTable.clear();
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            fUITable3[buildPath(label)] = new mspBargraph(createLabel(label), zone, min, max);
            fDeclareTable.clear();
        }
    
        void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
    
        void openTabBox(const char* label) {fControlsLevel.push_back(label); fDeclareTable.clear();}
        void openHorizontalBox(const char* label) {fControlsLevel.push_back(label); fDeclareTable.clear();}
        void openVerticalBox(const char* label) {fControlsLevel.push_back(label); fDeclareTable.clear();}
        void closeBox() {fControlsLevel.pop_back(); fDeclareTable.clear();}

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            if (strcmp(key,"multi") == 0) {
                int index = atoi(val);
                if (index >= 0 && index < MULTI_SIZE) {
                    fMultiTable[index] = zone;
                    fMultiControl++;
                } else {
                    post("Invalid multi index = %d", index);
                }
            }
            
            fDeclareTable[key] = val;
        }
        
        void setMultiValues(FAUSTFLOAT* multi, int buffer_size)
		{
            for (int read = 0; read < buffer_size; read++) {
                int write = (fMultiIndex + read) & (MULTI_SIZE - 1);
                if (fMultiTable[write]) {
                    *fMultiTable[write] = multi[read];
                }
            }
            fMultiIndex += buffer_size;
		}
        
        bool isMulti() { return fMultiControl > 0; }
    
        bool isValue(string name) 
        {
            return (fUITable1.count(name) || fUITable2.count(name));
        }
        bool isOutputValue(string name) 
        {
            return fUITable3.count(name);
        }
        bool isInputValue(string name) 
        {
            return fUITable2.count(name);
        }
        bool setValue(string name, FAUSTFLOAT f)
        {
            if (fUITable1.count(name)) {
                fUITable1[name]->setValue(f);
                return true;
            } else if (fUITable2.count(name)) {
                fUITable2[name]->setValue(f);
                return true;
            } else {
                return false;
            }
        }
		FAUSTFLOAT getOutputValue(string name) { return fUITable3[name]->getValue(); }
          
        iterator begin1()	{ return fUITable1.begin(); }
        iterator end1()		{ return fUITable1.end(); }
        
        iterator begin2()	{ return fUITable2.begin(); }
        iterator end2()		{ return fUITable2.end(); }

        int itemsCount() { return fUITable1.size(); }
        void clear() 
        { 
            iterator it;
            for (it = begin1(); it != end1(); it++) {
                delete (*it).second;
            }
            fUITable1.clear(); 
            fUITable2.clear(); 
        }
    
        void displayControls()
        {
            iterator it;
            post((char*)"------- labels and ranges ----------");
            for (it = fUITable1.begin(); it != fUITable1.end(); it++) {
                char param[STR_SIZE];
                it->second->toString(param);
                post(param);
            }
            post((char*)"------- complete paths ----------");
            for (it = fUITable2.begin(); it != fUITable2.end(); it++) {
                post(it->first.c_str());
            }
            post((char*)"---------------------------------");
        }
    
};

//--------------------------------------------------------------------------
static bool check_digit(const string& name)
{
    for (int i = name.size() - 1; i >= 0; i--) {
        if (isdigit(name[i])) { return true; }
    }
    return false;
}

static int count_digit(const string& name)
{
    int count = 0;
    for (int i = name.size() - 1; i >= 0; i--) {
        if (isdigit(name[i])) { count++; }
    }
    return count;
}

/*--------------------------------------------------------------------------*/
void faust_anything(t_faust* obj, t_symbol* s, short ac, t_atom* av)
{
    if (ac < 0) return;
    
    bool res = false;
    string name = string((s)->s_name);
    
    // Check if no argument is there, consider it is a toggle message for a button
    if (ac == 0 && obj->m_dspUI->isValue(name)) {
        
        float off = 0.0f;
        float on = 1.0f;
        obj->m_dspUI->setValue(name, off);
        obj->m_dspUI->setValue(name, on);
        
        av[0].a_type = A_FLOAT;
        av[0].a_w.w_float = off;
        faust_anything(obj, s, 1, av);
        
        return;
    }
    
    // List of values
    if (check_digit(name)) {
        
        int ndigit = 0;
        int pos;
        
        for (pos = name.size() - 1; pos >= 0; pos--) {
            if (isdigit(name[pos]) || name[pos] == ' ') {
                ndigit++;
            } else {
                break;
            }
        }
        pos++;
        
        string prefix = name.substr(0, pos);
        string num_base = name.substr(pos);
        int num = atoi(num_base.c_str());
        
        int i;
        t_atom* ap;
       
        // Increment ap each time to get to the next atom
        for (i = 0, ap = av; i < ac; i++, ap++) {
            float value;
            switch (atom_gettype(ap)) {
                case A_LONG: 
                    value = (float)ap[0].a_w.w_long;
                    break;
                
                case A_FLOAT:
                    value = ap[0].a_w.w_float;
                    break;
                    
                default:
                    post("Invalid argument in parameter setting"); 
                    return;         
            }
            
            stringstream num_val;
            num_val << num + i;
            string str = num_val.str();
            char param_name[256];
            
            switch (ndigit - count_digit(str)) {
                case 0:
                    sprintf(param_name, "%s%s", prefix.c_str(), str.c_str());
                    break;
                case 1:
                    sprintf(param_name, "%s %s", prefix.c_str(), str.c_str());
                    break;
                case 2:
                    sprintf(param_name, "%s  %s", prefix.c_str(), str.c_str());
                    break;
            }
            
            // Try special naming scheme for list of parameters
            res = obj->m_dspUI->setValue(param_name, value); 
            
            // Otherwise try standard name
            if (!res) {
                res = obj->m_dspUI->setValue(name, value);
            }
            
            if (!res) {
                post("Unknown parameter : %s", (s)->s_name);
            }
        }
    } else {
        // Standard parameter name
        float value = (av[0].a_type == A_LONG) ? (float)av[0].a_w.w_long : av[0].a_w.w_float;
        res = obj->m_dspUI->setValue(name, value);
    }
    
    if (!res) {
        post("Unknown parameter : %s", (s)->s_name);
    }
}

/*--------------------------------------------------------------------------*/
void faust_polyphony(t_faust* obj, t_symbol* s, short ac, t_atom* av)
{
    if (systhread_mutex_lock(obj->m_mutex) == MAX_ERR_NONE) {
    #ifdef MIDICTRL
        mydsp_poly* poly = dynamic_cast<mydsp_poly*>(obj->m_dsp);
        if (poly) {
            obj->m_midiHandler->removeMidiIn(poly);
        }
    #endif
        // Delete old
        delete obj->m_dsp;
        obj->m_dspUI->clear();
        mydsp_poly* dsp_poly = NULL;
        // Allocate new one
        if (av[0].a_w.w_long > 0) {
            post("polyphonic DSP voices = %d", av[0].a_w.w_long);
            dsp_poly = new mydsp_poly(new mydsp(), av[0].a_w.w_long, true, true);
        #ifdef POLY2
            obj->m_dsp = new dsp_sequencer(dsp_poly, new effect());
        #else
            obj->m_dsp = dsp_poly;
        #endif
        } else {
            obj->m_dsp = new mydsp();
            post("monophonic DSP");
        }
        // Initialize User Interface (here connnection with controls)
        obj->m_dsp->buildUserInterface(obj->m_dspUI);
    #ifdef MIDICTRL
        obj->m_midiHandler->addMidiIn(dsp_poly);
        obj->m_dsp->buildUserInterface(obj->m_midiUI);
    #endif
        // Initialize at the system's sampling rate
        obj->m_dsp->init(long(sys_getsr()));
        
        // Prepare JSON
        faust_make_json(obj);
        
        // Send JSON to JS script
        faust_create_jsui(obj);
        
        systhread_mutex_unlock(obj->m_mutex);
    } else {
        post("Mutex lock cannot be taken...");
    }
}

/*--------------------------------------------------------------------------*/
#ifdef MIDICTRL
void faust_midievent(t_faust* obj, t_symbol* s, short ac, t_atom* av) 
{
    if (ac > 0) {
        int type = (int)av[0].a_w.w_long & 0xf0;
        int channel = (int)av[0].a_w.w_long & 0x0f;
                
        if (ac == 1) {
            obj->m_midiHandler->handleSync(0.0, av[0].a_w.w_long);
        } else if (ac == 2) {
            obj->m_midiHandler->handleData1(0.0, type, channel, av[1].a_w.w_long);
        } else if (ac == 3) {
            obj->m_midiHandler->handleData2(0.0, type, channel, av[1].a_w.w_long, av[2].a_w.w_long);
        }
    }
}
#endif

/*--------------------------------------------------------------------------*/
void faust_create_jsui(t_faust* x)
{
    t_object *patcher, *box, *obj;
    object_obex_lookup((t_object*)x, gensym("#P"), &patcher);
    
    for (box = jpatcher_get_firstobject(patcher); box; box = jbox_get_nextobject(box)) {
        obj = jbox_get_object(box);
        // Notify JSON
        if (obj && strcmp(object_classname(obj)->s_name, "js") == 0) {
            t_atom json;
            atom_setsym(&json, gensym(x->m_json));
            object_method_typed(obj, gensym("anything"), 1, &json, 0);
        }
    }
        
    // Keep all outputs
    x->m_output_table.clear();
    for (box = jpatcher_get_firstobject(patcher); box; box = jbox_get_nextobject(box)) {
        obj = jbox_get_object(box);
        t_symbol* scriptingname = jbox_get_varname(obj); // scripting name
        // Keep control outputs
        if (scriptingname && x->m_dspUI->isOutputValue(scriptingname->s_name)) {
            x->m_output_table[scriptingname->s_name].push_back(obj);
        }
    }
}

void faust_update_outputs(t_faust* x)
{
    map<string, vector<t_object*> >::iterator it1;
    vector<t_object*>::iterator it2;
    for (it1 = x->m_output_table.begin(); it1 != x->m_output_table.end(); it1++) {
        FAUSTFLOAT value = x->m_dspUI->getOutputValue((*it1).first);
        if (value != NAN) {
            t_atom at_value;
            atom_setfloat(&at_value, value);
            for (it2 = (*it1).second.begin(); it2 != (*it1).second.end(); it2++) {
                object_method_typed((*it2), gensym("float"), 1, &at_value, 0);
            }
        }
    }
}

/*--------------------------------------------------------------------------*/
void faust_make_json(t_faust* x)
{
    // Prepare JSON
    if (x->m_json) free(x->m_json);
    JSONUI builder(x->m_dsp->getNumInputs(), x->m_dsp->getNumOutputs());
    x->m_dsp->metadata(&builder);
    x->m_dsp->buildUserInterface(&builder);
    x->m_json = strdup(builder.JSON().c_str());
}

/*--------------------------------------------------------------------------*/
void* faust_new(t_symbol* s, short ac, t_atom* av)
{
    bool midi_sync = false;
    int nvoices = 0;
    mydsp_poly* dsp_poly = NULL;
    
    mydsp* tmp_dsp = new mydsp();
    MidiMeta::analyse(tmp_dsp, midi_sync, nvoices);
    delete tmp_dsp;
    
    t_faust* x = (t_faust*)newobject(faust_class);

    x->m_json = 0;
    x->m_mute = false;
    
#ifdef MIDICTRL
    x->m_midiHandler = new midi_handler();
    x->m_midiUI = new MidiUI(x->m_midiHandler);
#endif
    
    if (nvoices > 0) {
        post("polyphonic DSP voices = %d", nvoices);
        dsp_poly = new mydsp_poly(new mydsp(), nvoices, true, true);
    #ifdef POLY2
        x->m_dsp = new dsp_sequencer(dsp_poly, new effect());
    #else
        x->m_dsp = dsp_poly;
    #endif
        
    #ifdef MIDICTRL
        x->m_midiHandler->addMidiIn(dsp_poly);
        x->m_dsp->buildUserInterface(x->m_midiUI);
    #endif
    } else {
        post("monophonic DSP");
        x->m_dsp = new mydsp();
    }
    
    x->m_Inputs = x->m_dsp->getNumInputs();
    x->m_Outputs = x->m_dsp->getNumOutputs();
   
    x->m_dspUI = new mspUI();

    x->m_dsp->init(long(sys_getsr()));
    x->m_dsp->buildUserInterface(x->m_dspUI);
    
    t_max_err err = systhread_mutex_new(&x->m_mutex, SYSTHREAD_MUTEX_NORMAL);
    if (err != MAX_ERR_NONE) {
        post("Cannot allocate mutex...");
    }
    
    // Prepare JSON
    faust_make_json(x);
    
    int num_input;
    
    if (x->m_dspUI->isMulti()) {
        num_input = x->m_dsp->getNumInputs() + 1;
    } else {
        num_input = x->m_dsp->getNumInputs();
    }
    
    x->m_args = (void**)calloc((num_input + x->m_dsp->getNumOutputs()) + 2, sizeof(void*));
    /* Multi in */
    dsp_setup((t_pxobject*)x, num_input);

    /* Multi out */
    for (int i = 0; i< x->m_dsp->getNumOutputs(); i++) {
        outlet_new((t_pxobject*)x, (char*)"signal");
    }

    ((t_pxobject*)x)->z_misc = Z_NO_INPLACE; // To assure input and output buffers are actually different

#ifdef SOUNDFILE
    Max_Meta3 meta3;
    x->m_dsp->metadata(&meta3);
    string bundle_path_str = SoundUI::getBinaryPathFrom(meta3.fName);
    if (bundle_path_str == "") {
        post("Bundle_path cannot be found!");
    }
    x->m_soundInterface = new SoundUI(bundle_path_str);
    x->m_dsp->buildUserInterface(x->m_soundInterface);
#endif
    
    // Send JSON to JS script
    faust_create_jsui(x);
    return x;
}

/*--------------------------------------------------------------------------*/
void faust_dblclick(t_faust* x, long inlet)
{
    x->m_dspUI->displayControls();
}

/*--------------------------------------------------------------------------*/
//11/13/2015 : faust_assist is actually called at each click in the patcher, so we now use 'faust_dblclick' to display the parameters...
void faust_assist(t_faust* x, void* b, long msg, long a, char* dst)
{
    if (msg == ASSIST_INLET) {
        if (a == 0) {
            if (x->m_dsp->getNumInputs() == 0) {
                sprintf(dst, "(signal) : Unused Input");
            } else {
                sprintf(dst, "(signal) : Audio Input %ld", (a+1));
			}
        } else if (a < x->m_dsp->getNumInputs()) {
            sprintf(dst, "(signal) : Audio Input %ld", (a+1));
        }
    } else if (msg == ASSIST_OUTLET) {
        sprintf(dst, "(signal) : Audio Output %ld", (a+1));
    }
}

/*--------------------------------------------------------------------------*/
void faust_mute(t_faust* obj, t_symbol* s, short ac, t_atom* at)
{
    if (atom_gettype(at) == A_LONG) {
        obj->m_mute = atom_getlong(at);
    }
}

/*--------------------------------------------------------------------------*/
void faust_free(t_faust* x)
{
	dsp_free((t_pxobject*)x);
	delete x->m_dsp;
	delete x->m_dspUI;
	if (x->m_args) free(x->m_args);
    if (x->m_json) free(x->m_json);
    systhread_mutex_free(x->m_mutex);
#ifdef MIDICTRL
    // m_midiUI *must* be deleted before m_midiHandler
    delete x->m_midiUI;
    delete x->m_midiHandler;
#endif
#ifdef SOUNDFILE
    delete x->m_soundInterface;
#endif
}

/*--------------------------------------------------------------------------*/
void faust_perform64(t_faust* x, t_object* dsp64, double** ins, long numins, double** outs, long numouts, long sampleframes, long flags, void* userparam)
{
    AVOIDDENORMALS;
    if (!x->m_mute && systhread_mutex_trylock(x->m_mutex) == MAX_ERR_NONE) {
        if (x->m_dsp) {
            if (x->m_dspUI->isMulti()) {
                x->m_dspUI->setMultiValues(ins[0], sampleframes);
                x->m_dsp->compute(sampleframes, ++ins, outs);
            } else {
                x->m_dsp->compute(sampleframes, ins, outs);
            }
            faust_update_outputs(x);
        }
    #ifdef MIDICTRL
        GUI::updateAllGuis();
    #endif
        systhread_mutex_unlock(x->m_mutex);
    } else {
        // Write null buffers to outs
        for (int i = 0; i < numouts; i++) {
             memset(outs[i], 0, sizeof(double) * sampleframes);
        }
    }
}

/*--------------------------------------------------------------------------*/
void faust_dsp64(t_faust* x, t_object* dsp64, short* count, double samplerate, long maxvectorsize, long flags)
{
    object_method(dsp64, gensym("dsp_add64"), x, faust_perform64, 0, NULL);
}

/*--------------------------------------------------------------------------*/
extern "C" int main(void)
{
	setup((t_messlist**)&faust_class, (method)faust_new, (method)faust_free,
		(short)sizeof(t_faust), 0L, A_DEFFLOAT, 0);

    dsp* tmp_dsp = new mydsp();
    mspUI m_dspUI;
    tmp_dsp->buildUserInterface(&m_dspUI);

    // 03/11/14 : use 'anything' to handle all parameter changes
    addmess((method)faust_anything, (char*)"anything", A_GIMME, 0);
    addmess((method)faust_polyphony, (char*)"polyphony", A_GIMME, 0);
#ifdef MIDICTRL
    addmess((method)faust_midievent, (char*)"midievent", A_GIMME, 0);
#endif
    addmess((method)faust_dsp64, (char*)"dsp64", A_CANT, 0);
    addmess((method)faust_dblclick, (char*)"dblclick", A_CANT, 0);
    addmess((method)faust_assist, (char*)"assist", A_CANT, 0);
    addmess((method)faust_mute, (char*)"mute", A_GIMME, 0);
    dsp_initclass();

    post((char*)"Faust DSP object v%s (sample = 64 bits code = %s)", EXTERNAL_VERSION, getCodeSize());
    post((char*)"Copyright (c) 2012-2018 Grame");
    Max_Meta1 meta1;
    tmp_dsp->metadata(&meta1);
    if (meta1.fCount > 0) {
        Max_Meta2 meta2;
        post("------------------------------");
        tmp_dsp->metadata(&meta2);
        post("------------------------------");
    }
    
    delete(tmp_dsp);
    return 0;
}

/********************END ARCHITECTURE SECTION (part 2/2)****************/





#endif
