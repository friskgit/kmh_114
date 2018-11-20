/* ------------------------------------------------------------
author: "AmbisonicDecoderToolkit"
copyright: "(c) Aaron J. Heller 2013"
license: "BSD 3-Clause License"
name: "KMH114_AE_5h5p_normal_6"
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
	
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fHslider0;
	double fRec0[2];
	int fSamplingFreq;
	int iConst0;
	double fConst1;
	FAUSTFLOAT fHslider1;
	double fRec1[2];
	double fRec2[3];
	FAUSTFLOAT fHslider2;
	double fRec3[2];
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	double fConst7;
	double fConst8;
	double fConst9;
	double fConst10;
	double fRec19[3];
	double fRec20[3];
	double fRec21[3];
	double fRec22[3];
	double fRec23[3];
	double fRec24[3];
	double fRec25[3];
	double fRec26[3];
	double fRec27[3];
	double fRec28[3];
	double fRec29[3];
	double fConst11;
	double fConst12;
	double fRec18[2];
	double fRec16[2];
	double fRec15[2];
	double fRec13[2];
	double fRec12[2];
	double fRec10[2];
	double fRec9[2];
	double fRec7[2];
	double fRec6[2];
	double fRec4[2];
	double fConst13;
	double fConst14;
	double fConst15;
	double fConst16;
	double fConst17;
	double fRec42[3];
	double fRec43[3];
	double fRec44[3];
	double fRec45[3];
	double fRec46[3];
	double fRec47[3];
	double fRec48[3];
	double fRec49[3];
	double fRec50[3];
	double fConst18;
	double fConst19;
	double fRec41[2];
	double fRec39[2];
	double fRec38[2];
	double fRec36[2];
	double fRec35[2];
	double fRec33[2];
	double fRec32[2];
	double fRec30[2];
	double fConst20;
	double fConst21;
	double fConst22;
	double fConst23;
	double fRec60[3];
	double fRec61[3];
	double fRec62[3];
	double fRec63[3];
	double fRec64[3];
	double fRec65[3];
	double fRec66[3];
	double fConst24;
	double fConst25;
	double fRec59[2];
	double fRec57[2];
	double fRec56[2];
	double fRec54[2];
	double fRec53[2];
	double fRec51[2];
	double fConst26;
	double fConst27;
	double fRec70[3];
	double fRec71[3];
	double fRec72[3];
	double fConst28;
	double fRec69[2];
	double fRec67[2];
	double fConst29;
	double fConst30;
	double fRec79[3];
	double fRec80[3];
	double fRec81[3];
	double fRec82[3];
	double fRec83[3];
	double fConst31;
	double fConst32;
	double fRec78[2];
	double fRec76[2];
	double fRec75[2];
	double fRec73[2];
	int IOTA;
	double fVec0[128];
	int iConst33;
	double fConst34;
	double fConst35;
	double fConst36;
	double fConst37;
	double fConst38;
	double fConst39;
	double fConst40;
	double fConst41;
	double fConst42;
	double fRec98[2];
	double fRec96[2];
	double fRec95[2];
	double fRec93[2];
	double fRec92[2];
	double fRec90[2];
	double fRec89[2];
	double fRec87[2];
	double fRec86[2];
	double fRec84[2];
	double fConst43;
	double fConst44;
	double fConst45;
	double fConst46;
	double fRec104[2];
	double fRec102[2];
	double fRec101[2];
	double fRec99[2];
	double fConst47;
	double fConst48;
	double fConst49;
	double fRec107[2];
	double fRec105[2];
	double fConst50;
	double fConst51;
	double fConst52;
	double fConst53;
	double fConst54;
	double fConst55;
	double fRec116[2];
	double fRec114[2];
	double fRec113[2];
	double fRec111[2];
	double fRec110[2];
	double fRec108[2];
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
	double fVec1[64];
	int iConst63;
	double fConst64;
	double fConst65;
	double fConst66;
	double fConst67;
	double fConst68;
	double fConst69;
	double fConst70;
	double fConst71;
	double fConst72;
	double fRec143[2];
	double fRec141[2];
	double fRec140[2];
	double fRec138[2];
	double fRec137[2];
	double fRec135[2];
	double fRec134[2];
	double fRec132[2];
	double fRec131[2];
	double fRec129[2];
	double fConst73;
	double fConst74;
	double fConst75;
	double fConst76;
	double fConst77;
	double fConst78;
	double fConst79;
	double fRec155[2];
	double fRec153[2];
	double fRec152[2];
	double fRec150[2];
	double fRec149[2];
	double fRec147[2];
	double fRec146[2];
	double fRec144[2];
	double fConst80;
	double fConst81;
	double fConst82;
	double fConst83;
	double fConst84;
	double fConst85;
	double fRec164[2];
	double fRec162[2];
	double fRec161[2];
	double fRec159[2];
	double fRec158[2];
	double fRec156[2];
	double fConst86;
	double fConst87;
	double fConst88;
	double fRec167[2];
	double fRec165[2];
	double fConst89;
	double fConst90;
	double fConst91;
	double fConst92;
	double fRec173[2];
	double fRec171[2];
	double fRec170[2];
	double fRec168[2];
	double fVec2[16];
	int iConst93;
	double fConst94;
	double fConst95;
	double fConst96;
	double fConst97;
	double fConst98;
	double fConst99;
	double fRec188[2];
	double fRec186[2];
	double fRec185[2];
	double fRec183[2];
	double fConst100;
	double fConst101;
	double fRec182[2];
	double fRec180[2];
	double fRec179[2];
	double fRec177[2];
	double fConst102;
	double fRec176[2];
	double fRec174[2];
	double fConst103;
	double fConst104;
	double fConst105;
	double fConst106;
	double fConst107;
	double fConst108;
	double fConst109;
	double fRec200[2];
	double fRec198[2];
	double fRec197[2];
	double fRec195[2];
	double fRec194[2];
	double fRec192[2];
	double fRec191[2];
	double fRec189[2];
	double fConst110;
	double fConst111;
	double fConst112;
	double fConst113;
	double fConst114;
	double fConst115;
	double fRec209[2];
	double fRec207[2];
	double fRec206[2];
	double fRec204[2];
	double fRec203[2];
	double fRec201[2];
	double fConst116;
	double fConst117;
	double fConst118;
	double fRec212[2];
	double fRec210[2];
	double fConst119;
	double fConst120;
	double fConst121;
	double fConst122;
	double fRec218[2];
	double fRec216[2];
	double fRec215[2];
	double fRec213[2];
	double fVec3[64];
	int iConst123;
	double fConst124;
	double fConst125;
	double fConst126;
	double fConst127;
	double fConst128;
	double fConst129;
	double fConst130;
	double fConst131;
	double fConst132;
	double fRec233[2];
	double fRec231[2];
	double fRec230[2];
	double fRec228[2];
	double fRec227[2];
	double fRec225[2];
	double fRec224[2];
	double fRec222[2];
	double fRec221[2];
	double fRec219[2];
	double fConst133;
	double fConst134;
	double fConst135;
	double fConst136;
	double fConst137;
	double fConst138;
	double fConst139;
	double fRec245[2];
	double fRec243[2];
	double fRec242[2];
	double fRec240[2];
	double fRec239[2];
	double fRec237[2];
	double fRec236[2];
	double fRec234[2];
	double fConst140;
	double fConst141;
	double fConst142;
	double fConst143;
	double fConst144;
	double fConst145;
	double fRec254[2];
	double fRec252[2];
	double fRec251[2];
	double fRec249[2];
	double fRec248[2];
	double fRec246[2];
	double fConst146;
	double fConst147;
	double fConst148;
	double fRec257[2];
	double fRec255[2];
	double fConst149;
	double fConst150;
	double fConst151;
	double fConst152;
	double fRec263[2];
	double fRec261[2];
	double fRec260[2];
	double fRec258[2];
	double fVec4[8];
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
	double fConst163;
	double fConst164;
	double fConst165;
	double fConst166;
	double fConst167;
	double fConst168;
	double fConst169;
	double fRec290[2];
	double fRec288[2];
	double fRec287[2];
	double fRec285[2];
	double fRec284[2];
	double fRec282[2];
	double fRec281[2];
	double fRec279[2];
	double fConst170;
	double fConst171;
	double fConst172;
	double fConst173;
	double fConst174;
	double fConst175;
	double fRec299[2];
	double fRec297[2];
	double fRec296[2];
	double fRec294[2];
	double fRec293[2];
	double fRec291[2];
	double fConst176;
	double fConst177;
	double fConst178;
	double fRec302[2];
	double fRec300[2];
	double fConst179;
	double fConst180;
	double fConst181;
	double fConst182;
	double fRec308[2];
	double fRec306[2];
	double fRec305[2];
	double fRec303[2];
	double fConst183;
	double fConst184;
	double fConst185;
	double fConst186;
	double fConst187;
	double fConst188;
	double fConst189;
	double fConst190;
	double fConst191;
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
	double fConst192;
	double fConst193;
	double fConst194;
	double fConst195;
	double fConst196;
	double fConst197;
	double fConst198;
	double fRec335[2];
	double fRec333[2];
	double fRec332[2];
	double fRec330[2];
	double fRec329[2];
	double fRec327[2];
	double fRec326[2];
	double fRec324[2];
	double fConst199;
	double fConst200;
	double fConst201;
	double fConst202;
	double fConst203;
	double fConst204;
	double fRec344[2];
	double fRec342[2];
	double fRec341[2];
	double fRec339[2];
	double fRec338[2];
	double fRec336[2];
	double fConst205;
	double fConst206;
	double fConst207;
	double fRec347[2];
	double fRec345[2];
	double fConst208;
	double fConst209;
	double fConst210;
	double fConst211;
	double fRec353[2];
	double fRec351[2];
	double fRec350[2];
	double fRec348[2];
	double fVec5[128];
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
	double fRec368[2];
	double fRec366[2];
	double fRec365[2];
	double fRec363[2];
	double fRec362[2];
	double fRec360[2];
	double fRec359[2];
	double fRec357[2];
	double fRec356[2];
	double fRec354[2];
	double fConst222;
	double fConst223;
	double fConst224;
	double fConst225;
	double fConst226;
	double fConst227;
	double fConst228;
	double fRec380[2];
	double fRec378[2];
	double fRec377[2];
	double fRec375[2];
	double fRec374[2];
	double fRec372[2];
	double fRec371[2];
	double fRec369[2];
	double fConst229;
	double fConst230;
	double fConst231;
	double fConst232;
	double fConst233;
	double fConst234;
	double fRec389[2];
	double fRec387[2];
	double fRec386[2];
	double fRec384[2];
	double fRec383[2];
	double fRec381[2];
	double fConst235;
	double fConst236;
	double fConst237;
	double fRec392[2];
	double fRec390[2];
	double fConst238;
	double fConst239;
	double fConst240;
	double fConst241;
	double fRec398[2];
	double fRec396[2];
	double fRec395[2];
	double fRec393[2];
	double fVec6[64];
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
	double fConst252;
	double fConst253;
	double fConst254;
	double fConst255;
	double fConst256;
	double fConst257;
	double fConst258;
	double fRec425[2];
	double fRec423[2];
	double fRec422[2];
	double fRec420[2];
	double fRec419[2];
	double fRec417[2];
	double fRec416[2];
	double fRec414[2];
	double fConst259;
	double fConst260;
	double fConst261;
	double fConst262;
	double fConst263;
	double fConst264;
	double fRec434[2];
	double fRec432[2];
	double fRec431[2];
	double fRec429[2];
	double fRec428[2];
	double fRec426[2];
	double fConst265;
	double fConst266;
	double fConst267;
	double fRec437[2];
	double fRec435[2];
	double fConst268;
	double fConst269;
	double fConst270;
	double fConst271;
	double fRec443[2];
	double fRec441[2];
	double fRec440[2];
	double fRec438[2];
	double fVec7[256];
	int iConst272;
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
	double fRec470[2];
	double fRec468[2];
	double fRec467[2];
	double fRec465[2];
	double fRec464[2];
	double fRec462[2];
	double fRec461[2];
	double fRec459[2];
	double fRec479[2];
	double fRec477[2];
	double fRec476[2];
	double fRec474[2];
	double fRec473[2];
	double fRec471[2];
	double fRec482[2];
	double fRec480[2];
	double fRec488[2];
	double fRec486[2];
	double fRec485[2];
	double fRec483[2];
	double fVec8[256];
	double fConst273;
	double fConst274;
	double fConst275;
	double fConst276;
	double fConst277;
	double fConst278;
	double fRec497[2];
	double fRec495[2];
	double fRec494[2];
	double fRec492[2];
	double fRec491[2];
	double fRec489[2];
	double fConst279;
	double fConst280;
	double fConst281;
	double fRec500[2];
	double fRec498[2];
	double fConst282;
	double fConst283;
	double fConst284;
	double fConst285;
	double fRec506[2];
	double fRec504[2];
	double fRec503[2];
	double fRec501[2];
	double fConst286;
	double fConst287;
	double fConst288;
	double fConst289;
	double fConst290;
	double fConst291;
	double fConst292;
	double fRec518[2];
	double fRec516[2];
	double fRec515[2];
	double fRec513[2];
	double fRec512[2];
	double fRec510[2];
	double fRec509[2];
	double fRec507[2];
	double fConst293;
	double fConst294;
	double fConst295;
	double fConst296;
	double fConst297;
	double fConst298;
	double fConst299;
	double fConst300;
	double fConst301;
	double fRec533[2];
	double fRec531[2];
	double fRec530[2];
	double fRec528[2];
	double fRec527[2];
	double fRec525[2];
	double fRec524[2];
	double fRec522[2];
	double fRec521[2];
	double fRec519[2];
	double fVec9[256];
	int iConst302;
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
	double fRec560[2];
	double fRec558[2];
	double fRec557[2];
	double fRec555[2];
	double fRec554[2];
	double fRec552[2];
	double fRec551[2];
	double fRec549[2];
	double fRec563[2];
	double fRec561[2];
	double fRec569[2];
	double fRec567[2];
	double fRec566[2];
	double fRec564[2];
	double fRec578[2];
	double fRec576[2];
	double fRec575[2];
	double fRec573[2];
	double fRec572[2];
	double fRec570[2];
	double fVec10[256];
	double fConst303;
	double fConst304;
	double fConst305;
	double fConst306;
	double fConst307;
	double fConst308;
	double fConst309;
	double fConst310;
	double fConst311;
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
	double fConst312;
	double fConst313;
	double fConst314;
	double fConst315;
	double fConst316;
	double fConst317;
	double fConst318;
	double fRec605[2];
	double fRec603[2];
	double fRec602[2];
	double fRec600[2];
	double fRec599[2];
	double fRec597[2];
	double fRec596[2];
	double fRec594[2];
	double fConst319;
	double fConst320;
	double fConst321;
	double fConst322;
	double fConst323;
	double fConst324;
	double fRec614[2];
	double fRec612[2];
	double fRec611[2];
	double fRec609[2];
	double fRec608[2];
	double fRec606[2];
	double fConst325;
	double fConst326;
	double fConst327;
	double fRec617[2];
	double fRec615[2];
	double fConst328;
	double fConst329;
	double fConst330;
	double fConst331;
	double fRec623[2];
	double fRec621[2];
	double fRec620[2];
	double fRec618[2];
	double fVec11[1024];
	int iConst332;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "AmbisonicDecoderToolkit");
		m->declare("copyright", "(c) Aaron J. Heller 2013");
		m->declare("filename", "KMH114_AE_5h5p_normal_6");
		m->declare("license", "BSD 3-Clause License");
		m->declare("name", "KMH114_AE_5h5p_normal_6");
		m->declare("version", "1.2");
	}

	virtual int getNumInputs() {
		return 36;
		
	}
	virtual int getNumOutputs() {
		return 13;
		
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
		fConst1 = (3.1415926535897931 / double(iConst0));
		fConst2 = double(iConst0);
		fConst3 = ((191.96533911319742 / fConst2) + 1.0);
		fConst4 = (0.0 - (383.93067822639483 / (fConst2 * fConst3)));
		fConst5 = mydsp_faustpower2_f(fConst2);
		fConst6 = ((((39549.029677540268 / fConst2) + 352.89584379873679) / fConst2) + 1.0);
		fConst7 = (0.0 - (158196.11871016107 / (fConst5 * fConst6)));
		fConst8 = (0.0 - (((158196.11871016107 / fConst2) + 705.79168759747358) / (fConst2 * fConst6)));
		fConst9 = ((((50311.132146818818 / fConst2) + 244.74301037618173) / fConst2) + 1.0);
		fConst10 = (1.0 / ((fConst3 * fConst6) * fConst9));
		fConst11 = (0.0 - (201244.52858727527 / (fConst5 * fConst9)));
		fConst12 = (0.0 - (((201244.52858727527 / fConst2) + 489.48602075236346) / (fConst2 * fConst9)));
		fConst13 = ((((25327.293843552216 / fConst2) + 304.91467155099616) / fConst2) + 1.0);
		fConst14 = (0.0 - (101309.17537420886 / (fConst5 * fConst13)));
		fConst15 = (0.0 - (((101309.17537420886 / fConst2) + 609.82934310199232) / (fConst2 * fConst13)));
		fConst16 = ((((31832.683993978117 / fConst2) + 221.48812397441478) / fConst2) + 1.0);
		fConst17 = (1.0 / (fConst13 * fConst16));
		fConst18 = (0.0 - (127330.73597591247 / (fConst5 * fConst16)));
		fConst19 = (0.0 - (((127330.73597591247 / fConst2) + 442.97624794882955) / (fConst2 * fConst16)));
		fConst20 = ((122.24048624033396 / fConst2) + 1.0);
		fConst21 = (0.0 - (244.48097248066793 / (fConst2 * fConst20)));
		fConst22 = ((((17899.081736840039 / fConst2) + 193.60119107491266) / fConst2) + 1.0);
		fConst23 = (1.0 / (fConst20 * fConst22));
		fConst24 = (0.0 - (71596.326947360154 / (fConst5 * fConst22)));
		fConst25 = (0.0 - (((71596.326947360154 / fConst2) + 387.20238214982533) / (fConst2 * fConst22)));
		fConst26 = ((52.640279552541102 / fConst2) + 1.0);
		fConst27 = (1.0 / fConst26);
		fConst28 = (0.0 - (105.2805591050822 / (fConst2 * fConst26)));
		fConst29 = ((((8312.9970941090305 / fConst2) + 157.92083865762331) / fConst2) + 1.0);
		fConst30 = (1.0 / fConst29);
		fConst31 = (0.0 - (((33251.988376436122 / fConst2) + 315.84167731524661) / (fConst2 * fConst29)));
		fConst32 = (0.0 - (33251.988376436122 / (fConst5 * fConst29)));
		iConst33 = int(((0.00033798093768075285 * double(iConst0)) + 0.5));
		fConst34 = ((189.63848651788592 / fConst2) + 1.0);
		fConst35 = (0.0 - (379.27697303577185 / (fConst2 * fConst34)));
		fConst36 = ((((38596.076014786682 / fConst2) + 348.61831841935816) / fConst2) + 1.0);
		fConst37 = (0.0 - (154384.30405914673 / (fConst5 * fConst36)));
		fConst38 = (0.0 - (((154384.30405914673 / fConst2) + 697.23663683871632) / (fConst2 * fConst36)));
		fConst39 = ((((49098.860239075453 / fConst2) + 241.77642843222799) / fConst2) + 1.0);
		fConst40 = (1.0 / ((fConst34 * fConst36) * fConst39));
		fConst41 = (0.0 - (196395.44095630181 / (fConst5 * fConst39)));
		fConst42 = (0.0 - (((196395.44095630181 / fConst2) + 483.55285686445598) / (fConst2 * fConst39)));
		fConst43 = ((((8112.6912688111233 / fConst2) + 156.00664667389452) / fConst2) + 1.0);
		fConst44 = (1.0 / fConst43);
		fConst45 = (0.0 - (32450.765075244493 / (fConst5 * fConst43)));
		fConst46 = (0.0 - (((32450.765075244493 / fConst2) + 312.01329334778904) / (fConst2 * fConst43)));
		fConst47 = ((52.002215557964846 / fConst2) + 1.0);
		fConst48 = (1.0 / fConst47);
		fConst49 = (0.0 - (104.00443111592969 / (fConst2 * fConst47)));
		fConst50 = ((120.75878337681476 / fConst2) + 1.0);
		fConst51 = (0.0 - (241.51756675362952 / (fConst2 * fConst50)));
		fConst52 = ((((17467.794404631881 / fConst2) + 191.25450997097431) / fConst2) + 1.0);
		fConst53 = (1.0 / (fConst50 * fConst52));
		fConst54 = (0.0 - (69871.177618527523 / (fConst5 * fConst52)));
		fConst55 = (0.0 - (((69871.177618527523 / fConst2) + 382.50901994194862) / (fConst2 * fConst52)));
		fConst56 = ((((24717.020023116213 / fConst2) + 301.21873613825682) / fConst2) + 1.0);
		fConst57 = (0.0 - (98868.08009246485 / (fConst5 * fConst56)));
		fConst58 = (0.0 - (((98868.08009246485 / fConst2) + 602.43747227651363) / (fConst2 * fConst56)));
		fConst59 = ((((31065.659542185662 / fConst2) + 218.80341944139155) / fConst2) + 1.0);
		fConst60 = (1.0 / (fConst56 * fConst59));
		fConst61 = (0.0 - (124262.63816874265 / (fConst5 * fConst59)));
		fConst62 = (0.0 - (((124262.63816874265 / fConst2) + 437.60683888278311) / (fConst2 * fConst59)));
		iConst63 = int(((0.00022143578675635532 * double(iConst0)) + 0.5));
		fConst64 = ((186.80806134597717 / fConst2) + 1.0);
		fConst65 = (0.0 - (373.61612269195433 / (fConst2 * fConst64)));
		fConst66 = ((((37452.552265629485 / fConst2) + 343.41505993548714) / fConst2) + 1.0);
		fConst67 = (0.0 - (149810.20906251794 / (fConst5 * fConst66)));
		fConst68 = (0.0 - (((149810.20906251794 / fConst2) + 686.83011987097427) / (fConst2 * fConst66)));
		fConst69 = ((((47644.160214170784 / fConst2) + 238.16782502279173) / fConst2) + 1.0);
		fConst70 = (1.0 / ((fConst64 * fConst66) * fConst69));
		fConst71 = (0.0 - (190576.64085668314 / (fConst5 * fConst69)));
		fConst72 = (0.0 - (((190576.64085668314 / fConst2) + 476.33565004558346) / (fConst2 * fConst69)));
		fConst73 = ((((23984.704660435331 / fConst2) + 296.72293410634251) / fConst2) + 1.0);
		fConst74 = (0.0 - (95938.818641741324 / (fConst5 * fConst73)));
		fConst75 = (0.0 - (((95938.818641741324 / fConst2) + 593.44586821268501) / (fConst2 * fConst73)));
		fConst76 = ((((30145.246817946248 / fConst2) + 215.53769676316182) / fConst2) + 1.0);
		fConst77 = (1.0 / (fConst73 * fConst76));
		fConst78 = (0.0 - (120580.98727178499 / (fConst5 * fConst76)));
		fConst79 = (0.0 - (((120580.98727178499 / fConst2) + 431.07539352632364) / (fConst2 * fConst76)));
		fConst80 = ((118.95641347566826 / fConst2) + 1.0);
		fConst81 = (0.0 - (237.91282695133651 / (fConst2 * fConst80)));
		fConst82 = ((((16950.258950005893 / fConst2) + 188.39996504603437) / fConst2) + 1.0);
		fConst83 = (1.0 / (fConst80 * fConst82));
		fConst84 = (0.0 - (67801.035800023572 / (fConst5 * fConst82)));
		fConst85 = (0.0 - (((67801.035800023572 / fConst2) + 376.79993009206873) / (fConst2 * fConst82)));
		fConst86 = ((51.22606308695044 / fConst2) + 1.0);
		fConst87 = (1.0 / fConst86);
		fConst88 = (0.0 - (102.45212617390088 / (fConst2 * fConst86)));
		fConst89 = ((((7872.3286181646799 / fConst2) + 153.67818926085133) / fConst2) + 1.0);
		fConst90 = (1.0 / fConst89);
		fConst91 = (0.0 - (31489.31447265872 / (fConst5 * fConst89)));
		fConst92 = (0.0 - (((31489.31447265872 / fConst2) + 307.35637852170265) / (fConst2 * fConst89)));
		iConst93 = int(((7.5754348100857757e-05 * double(iConst0)) + 0.5));
		fConst94 = ((191.37828914649037 / fConst2) + 1.0);
		fConst95 = ((((39307.50945029196 / fConst2) + 351.81665161586596) / fConst2) + 1.0);
		fConst96 = ((((50003.889310059159 / fConst2) + 243.99456080316583) / fConst2) + 1.0);
		fConst97 = (1.0 / ((fConst94 * fConst95) * fConst96));
		fConst98 = (0.0 - (((200015.55724023664 / fConst2) + 487.98912160633165) / (fConst2 * fConst96)));
		fConst99 = (0.0 - (200015.55724023664 / (fConst5 * fConst96)));
		fConst100 = (0.0 - (((157230.03780116784 / fConst2) + 703.63330323173193) / (fConst2 * fConst95)));
		fConst101 = (0.0 - (157230.03780116784 / (fConst5 * fConst95)));
		fConst102 = (0.0 - (382.75657829298075 / (fConst2 * fConst94)));
		fConst103 = ((((25172.623708417312 / fConst2) + 303.98221078172702) / fConst2) + 1.0);
		fConst104 = (0.0 - (100690.49483366925 / (fConst5 * fConst103)));
		fConst105 = (0.0 - (((100690.49483366925 / fConst2) + 607.96442156345404) / (fConst2 * fConst103)));
		fConst106 = ((((31638.286378288562 / fConst2) + 220.81079026195476) / fConst2) + 1.0);
		fConst107 = (1.0 / (fConst103 * fConst106));
		fConst108 = (0.0 - (126553.14551315425 / (fConst5 * fConst106)));
		fConst109 = (0.0 - (((126553.14551315425 / fConst2) + 441.62158052390953) / (fConst2 * fConst106)));
		fConst110 = ((121.86666212339102 / fConst2) + 1.0);
		fConst111 = (0.0 - (243.73332424678205 / (fConst2 * fConst110)));
		fConst112 = ((((17789.774623015379 / fConst2) + 193.00913850281808) / fConst2) + 1.0);
		fConst113 = (1.0 / (fConst110 * fConst112));
		fConst114 = (0.0 - (71159.098492061516 / (fConst5 * fConst112)));
		fConst115 = (0.0 - (((71159.098492061516 / fConst2) + 386.01827700563615) / (fConst2 * fConst112)));
		fConst116 = ((52.479300104368185 / fConst2) + 1.0);
		fConst117 = (1.0 / fConst116);
		fConst118 = (0.0 - (104.95860020873637 / (fConst2 * fConst116)));
		fConst119 = ((((8262.2308183330169 / fConst2) + 157.43790031310456) / fConst2) + 1.0);
		fConst120 = (1.0 / fConst119);
		fConst121 = (0.0 - (33048.923273332068 / (fConst5 * fConst119)));
		fConst122 = (0.0 - (((33048.923273332068 / fConst2) + 314.87580062620913) / (fConst2 * fConst119)));
		iConst123 = int(((0.00030884464994965281 * double(iConst0)) + 0.5));
		fConst124 = ((186.03061994917465 / fConst2) + 1.0);
		fConst125 = (0.0 - (372.0612398983493 / (fConst2 * fConst124)));
		fConst126 = ((((37141.467447258146 / fConst2) + 341.98586527463789) / fConst2) + 1.0);
		fConst127 = (0.0 - (148565.86978903259 / (fConst5 * fConst126)));
		fConst128 = (0.0 - (((148565.86978903259 / fConst2) + 683.97173054927578) / (fConst2 * fConst126)));
		fConst129 = ((((47248.422833669691 / fConst2) + 237.17663906847574) / fConst2) + 1.0);
		fConst130 = (1.0 / ((fConst124 * fConst126) * fConst129));
		fConst131 = (0.0 - (188993.69133467876 / (fConst5 * fConst129)));
		fConst132 = (0.0 - (((188993.69133467876 / fConst2) + 474.35327813695147) / (fConst2 * fConst129)));
		fConst133 = ((((23785.485193626679 / fConst2) + 295.48805863741006) / fConst2) + 1.0);
		fConst134 = (0.0 - (95141.940774506715 / (fConst5 * fConst133)));
		fConst135 = (0.0 - (((95141.940774506715 / fConst2) + 590.97611727482013) / (fConst2 * fConst133)));
		fConst136 = ((((29894.857243302333 / fConst2) + 214.64069089078245) / fConst2) + 1.0);
		fConst137 = (1.0 / (fConst133 * fConst136));
		fConst138 = (0.0 - (119579.42897320933 / (fConst5 * fConst136)));
		fConst139 = (0.0 - (((119579.42897320933 / fConst2) + 429.2813817815649) / (fConst2 * fConst136)));
		fConst140 = ((118.46135111280877 / fConst2) + 1.0);
		fConst141 = (0.0 - (236.92270222561754 / (fConst2 * fConst140)));
		fConst142 = ((((16809.468325393405 / fConst2) + 187.61589860410677) / fConst2) + 1.0);
		fConst143 = (1.0 / (fConst140 * fConst142));
		fConst144 = (0.0 - (67237.873301573622 / (fConst5 * fConst142)));
		fConst145 = (0.0 - (((67237.873301573622 / fConst2) + 375.23179720821355) / (fConst2 * fConst142)));
		fConst146 = ((51.01287495281926 / fConst2) + 1.0);
		fConst147 = (1.0 / fConst146);
		fConst148 = (0.0 - (102.02574990563852 / (fConst2 * fConst146)));
		fConst149 = ((((7806.9402328559245 / fConst2) + 153.03862485845778) / fConst2) + 1.0);
		fConst150 = (1.0 / fConst149);
		fConst151 = (0.0 - (31227.760931423698 / (fConst5 * fConst149)));
		fConst152 = (0.0 - (((31227.760931423698 / fConst2) + 306.07724971691556) / (fConst2 * fConst149)));
		iConst153 = int(((3.4963545277319259e-05 * double(iConst0)) + 0.5));
		fConst154 = ((185.36937366973447 / fConst2) + 1.0);
		fConst155 = (0.0 - (370.73874733946894 / (fConst154 * fConst2)));
		fConst156 = ((((36877.897842540857 / fConst2) + 340.77027570612614) / fConst2) + 1.0);
		fConst157 = (0.0 - (147511.59137016343 / (fConst156 * fConst5)));
		fConst158 = (0.0 - (((147511.59137016343 / fConst2) + 681.54055141225228) / (fConst156 * fConst2)));
		fConst159 = ((((46913.130531407551 / fConst2) + 236.33359414287688) / fConst2) + 1.0);
		fConst160 = (1.0 / ((fConst154 * fConst156) * fConst159));
		fConst161 = (0.0 - (187652.5221256302 / (fConst159 * fConst5)));
		fConst162 = (0.0 - (((187652.5221256302 / fConst2) + 472.66718828575375) / (fConst159 * fConst2)));
		fConst163 = ((((23616.69458406352 / fConst2) + 294.43774563277469) / fConst2) + 1.0);
		fConst164 = (0.0 - (94466.778336254079 / (fConst5 * fConst163)));
		fConst165 = (0.0 - (((94466.778336254079 / fConst2) + 588.87549126554939) / (fConst2 * fConst163)));
		fConst166 = ((((29682.712267665982 / fConst2) + 213.87775004638394) / fConst2) + 1.0);
		fConst167 = (1.0 / (fConst163 * fConst166));
		fConst168 = (0.0 - (118730.84907066393 / (fConst5 * fConst166)));
		fConst169 = (0.0 - (((118730.84907066393 / fConst2) + 427.75550009276787) / (fConst2 * fConst166)));
		fConst170 = ((118.04027995956419 / fConst2) + 1.0);
		fConst171 = (0.0 - (236.08055991912838 / (fConst2 * fConst170)));
		fConst172 = ((((16690.182114413106 / fConst2) + 186.94901744793106) / fConst2) + 1.0);
		fConst173 = (1.0 / (fConst170 * fConst172));
		fConst174 = (0.0 - (66760.728457652425 / (fConst5 * fConst172)));
		fConst175 = (0.0 - (((66760.728457652425 / fConst2) + 373.89803489586211) / (fConst2 * fConst172)));
		fConst176 = ((50.831549567915872 / fConst2) + 1.0);
		fConst177 = (1.0 / fConst176);
		fConst178 = (0.0 - (101.66309913583174 / (fConst2 * fConst176)));
		fConst179 = ((((7751.5392944264649 / fConst2) + 152.4946487037476) / fConst2) + 1.0);
		fConst180 = (1.0 / fConst179);
		fConst181 = (0.0 - (31006.15717770586 / (fConst5 * fConst179)));
		fConst182 = (0.0 - (((31006.15717770586 / fConst2) + 304.9892974074952) / (fConst2 * fConst179)));
		fConst183 = ((191.84764117382693 / fConst2) + 1.0);
		fConst184 = (0.0 - (383.69528234765386 / (fConst2 * fConst183)));
		fConst185 = ((((39500.547880469159 / fConst2) + 352.67947602203611) / fConst2) + 1.0);
		fConst186 = (0.0 - (158002.19152187664 / (fConst5 * fConst185)));
		fConst187 = (0.0 - (((158002.19152187664 / fConst2) + 705.35895204407223) / (fConst2 * fConst185)));
		fConst188 = ((((50249.457457982011 / fConst2) + 244.59295334958685) / fConst2) + 1.0);
		fConst189 = (1.0 / ((fConst183 * fConst185) * fConst188));
		fConst190 = (0.0 - (200997.82983192804 / (fConst5 * fConst188)));
		fConst191 = (0.0 - (((200997.82983192804 / fConst2) + 489.1859066991737) / (fConst2 * fConst188)));
		fConst192 = ((((25296.245983958815 / fConst2) + 304.72772202827935) / fConst2) + 1.0);
		fConst193 = (0.0 - (101184.98393583526 / (fConst5 * fConst192)));
		fConst194 = (0.0 - (((101184.98393583526 / fConst2) + 609.45544405655869) / (fConst2 * fConst192)));
		fConst195 = ((((31793.661400043246 / fConst2) + 221.35232500202088) / fConst2) + 1.0);
		fConst196 = (1.0 / (fConst192 * fConst195));
		fConst197 = (0.0 - (127174.64560017298 / (fConst5 * fConst195)));
		fConst198 = (0.0 - (((127174.64560017298 / fConst2) + 442.70465000404175) / (fConst2 * fConst195)));
		fConst199 = ((122.1655380574766 / fConst2) + 1.0);
		fConst200 = (0.0 - (244.33107611495319 / (fConst2 * fConst199)));
		fConst201 = ((((17877.139867327685 / fConst2) + 193.48249016070361) / fConst2) + 1.0);
		fConst202 = (1.0 / (fConst199 * fConst201));
		fConst203 = (0.0 - (71508.559469310741 / (fConst5 * fConst201)));
		fConst204 = (0.0 - (((71508.559469310741 / fConst2) + 386.96498032140721) / (fConst2 * fConst201)));
		fConst205 = ((52.608004703030034 / fConst2) + 1.0);
		fConst206 = (1.0 / fConst205);
		fConst207 = (0.0 - (105.21600940606007 / (fConst2 * fConst205)));
		fConst208 = ((((8302.8064765020899 / fConst2) + 157.82401410909011) / fConst2) + 1.0);
		fConst209 = (1.0 / fConst208);
		fConst210 = (0.0 - (33211.22590600836 / (fConst5 * fConst208)));
		fConst211 = (0.0 - (((33211.22590600836 / fConst2) + 315.64802821818023) / (fConst2 * fConst208)));
		iConst212 = int(((0.00033215368013453231 * double(iConst0)) + 0.5));
		fConst213 = ((189.86863031220375 / fConst2) + 1.0);
		fConst214 = (0.0 - (379.7372606244075 / (fConst2 * fConst213)));
		fConst215 = ((((38689.81265547558 / fConst2) + 349.04139890287684) / fConst2) + 1.0);
		fConst216 = (0.0 - (154759.25062190232 / (fConst5 * fConst215)));
		fConst217 = (0.0 - (((154759.25062190232 / fConst2) + 698.08279780575367) / (fConst2 * fConst215)));
		fConst218 = ((((49218.104543048263 / fConst2) + 242.06984642789817) / fConst2) + 1.0);
		fConst219 = (1.0 / ((fConst213 * fConst215) * fConst218));
		fConst220 = (0.0 - (196872.41817219305 / (fConst5 * fConst218)));
		fConst221 = (0.0 - (((196872.41817219305 / fConst2) + 484.13969285579634) / (fConst2 * fConst218)));
		fConst222 = ((((24777.049193540675 / fConst2) + 301.58429285687117) / fConst2) + 1.0);
		fConst223 = (0.0 - (99108.196774162701 / (fConst5 * fConst222)));
		fConst224 = (0.0 - (((99108.196774162701 / fConst2) + 603.16858571374235) / (fConst2 * fConst222)));
		fConst225 = ((((31141.107382146231 / fConst2) + 219.06895757178162) / fConst2) + 1.0);
		fConst226 = (1.0 / (fConst222 * fConst225));
		fConst227 = (0.0 - (124564.42952858492 / (fConst5 * fConst225)));
		fConst228 = (0.0 - (((124564.42952858492 / fConst2) + 438.13791514356325) / (fConst2 * fConst225)));
		fConst229 = ((120.90533529838856 / fConst2) + 1.0);
		fConst230 = (0.0 - (241.81067059677713 / (fConst2 * fConst229)));
		fConst231 = ((((17510.217690540721 / fConst2) + 191.48661495880316) / fConst2) + 1.0);
		fConst232 = (1.0 / (fConst229 * fConst231));
		fConst233 = (0.0 - (70040.870762162886 / (fConst5 * fConst231)));
		fConst234 = (0.0 - (((70040.870762162886 / fConst2) + 382.97322991760632) / (fConst2 * fConst231)));
		fConst235 = ((52.06532504286529 / fConst2) + 1.0);
		fConst236 = (1.0 / fConst235);
		fConst237 = (0.0 - (104.13065008573058 / (fConst2 * fConst235)));
		fConst238 = ((((8132.3942154576471 / fConst2) + 156.19597512859588) / fConst2) + 1.0);
		fConst239 = (1.0 / fConst238);
		fConst240 = (0.0 - (32529.576861830588 / (fConst5 * fConst238)));
		fConst241 = (0.0 - (((32529.576861830588 / fConst2) + 312.39195025719175) / (fConst2 * fConst238)));
		iConst242 = int(((0.00023309030184879507 * double(iConst0)) + 0.5));
		fConst243 = ((207.22086275133231 / fConst2) + 1.0);
		fConst244 = (0.0 - (414.44172550266461 / (fConst2 * fConst243)));
		fConst245 = ((((46084.740559737176 / fConst2) + 380.94054661717945) / fConst2) + 1.0);
		fConst246 = (0.0 - (184338.9622389487 / (fConst5 * fConst245)));
		fConst247 = (0.0 - (((184338.9622389487 / fConst2) + 761.8810932343589) / (fConst2 * fConst245)));
		fConst248 = ((((58625.344064244076 / fConst2) + 264.19278603521599) / fConst2) + 1.0);
		fConst249 = (1.0 / ((fConst243 * fConst245) * fConst248));
		fConst250 = (0.0 - (234501.37625697631 / (fConst5 * fConst248)));
		fConst251 = (0.0 - (((234501.37625697631 / fConst2) + 528.38557207043198) / (fConst2 * fConst248)));
		fConst252 = ((((29512.778831162617 / fConst2) + 329.14630107822762) / fConst2) + 1.0);
		fConst253 = (0.0 - (118051.11532465047 / (fConst5 * fConst252)));
		fConst254 = (0.0 - (((118051.11532465047 / fConst2) + 658.29260215645525) / (fConst2 * fConst252)));
		fConst255 = ((((37093.223149686615 / fConst2) + 239.08982919092455) / fConst2) + 1.0);
		fConst256 = (1.0 / (fConst252 * fConst255));
		fConst257 = (0.0 - (148372.89259874646 / (fConst5 * fConst255)));
		fConst258 = (0.0 - (((148372.89259874646 / fConst2) + 478.17965838184909) / (fConst2 * fConst255)));
		fConst259 = ((131.95496196804262 / fConst2) + 1.0);
		fConst260 = (0.0 - (263.90992393608525 / (fConst2 * fConst259)));
		fConst261 = ((((20857.010774356517 / fConst2) + 208.98671619344873) / fConst2) + 1.0);
		fConst262 = (1.0 / (fConst259 * fConst261));
		fConst263 = (0.0 - (83428.043097426067 / (fConst5 * fConst261)));
		fConst264 = (0.0 - (((83428.043097426067 / fConst2) + 417.97343238689746) / (fConst2 * fConst261)));
		fConst265 = ((56.823613026915226 / fConst2) + 1.0);
		fConst266 = (1.0 / fConst265);
		fConst267 = (0.0 - (113.64722605383045 / (fConst2 * fConst265)));
		fConst268 = ((((9686.7689922978298 / fConst2) + 170.47083908074569) / fConst2) + 1.0);
		fConst269 = (1.0 / fConst268);
		fConst270 = (0.0 - (38747.075969191319 / (fConst5 * fConst268)));
		fConst271 = (0.0 - (((38747.075969191319 / fConst2) + 340.94167816149138) / (fConst2 * fConst268)));
		iConst272 = int(((0.0010372518432271369 * double(iConst0)) + 0.5));
		fConst273 = ((130.65704430934056 / fConst2) + 1.0);
		fConst274 = (0.0 - (261.31408861868113 / (fConst2 * fConst273)));
		fConst275 = ((((20448.726801014909 / fConst2) + 206.93110914892304) / fConst2) + 1.0);
		fConst276 = (1.0 / (fConst273 * fConst275));
		fConst277 = (0.0 - (81794.907204059637 / (fConst5 * fConst275)));
		fConst278 = (0.0 - (((81794.907204059637 / fConst2) + 413.86221829784608) / (fConst2 * fConst275)));
		fConst279 = ((56.264692243043932 / fConst2) + 1.0);
		fConst280 = (1.0 / fConst279);
		fConst281 = (0.0 - (112.52938448608786 / (fConst2 * fConst279)));
		fConst282 = ((((9497.1467796133438 / fConst2) + 168.7940767291318) / fConst2) + 1.0);
		fConst283 = (1.0 / fConst282);
		fConst284 = (0.0 - (37988.587118453375 / (fConst5 * fConst282)));
		fConst285 = (0.0 - (((37988.587118453375 / fConst2) + 337.5881534582636) / (fConst2 * fConst282)));
		fConst286 = ((((28935.054883282508 / fConst2) + 325.90879647745817) / fConst2) + 1.0);
		fConst287 = (0.0 - (115740.21953313003 / (fConst5 * fConst286)));
		fConst288 = (0.0 - (((115740.21953313003 / fConst2) + 651.81759295491634) / (fConst2 * fConst286)));
		fConst289 = ((((36367.10910125255 / fConst2) + 236.73812595298105) / fConst2) + 1.0);
		fConst290 = (1.0 / (fConst286 * fConst289));
		fConst291 = (0.0 - (145468.4364050102 / (fConst5 * fConst289)));
		fConst292 = (0.0 - (((145468.4364050102 / fConst2) + 473.4762519059621) / (fConst2 * fConst289)));
		fConst293 = ((205.18262475705691 / fConst2) + 1.0);
		fConst294 = (0.0 - (410.36524951411383 / (fConst2 * fConst293)));
		fConst295 = ((((45182.614114595752 / fConst2) + 377.19359042094487) / fConst2) + 1.0);
		fConst296 = (0.0 - (180730.45645838301 / (fConst5 * fConst295)));
		fConst297 = (0.0 - (((180730.45645838301 / fConst2) + 754.38718084188974) / (fConst2 * fConst295)));
		fConst298 = ((((57477.730502932725 / fConst2) + 261.59416846765652) / fConst2) + 1.0);
		fConst299 = (1.0 / ((fConst293 * fConst295) * fConst298));
		fConst300 = (0.0 - (229910.9220117309 / (fConst5 * fConst298)));
		fConst301 = (0.0 - (((229910.9220117309 / fConst2) + 523.18833693531303) / (fConst2 * fConst298)));
		iConst302 = int(((0.00094984298003383924 * double(iConst0)) + 0.5));
		fConst303 = ((391.12937844313967 / fConst2) + 1.0);
		fConst304 = (0.0 - (782.25875688627934 / (fConst2 * fConst303)));
		fConst305 = ((((164184.08898477611 / fConst2) + 719.02528173992607) / fConst2) + 1.0);
		fConst306 = (0.0 - (656736.35593910445 / (fConst5 * fConst305)));
		fConst307 = (0.0 - (((656736.35593910445 / fConst2) + 1438.0505634798521) / (fConst2 * fConst305)));
		fConst308 = ((((208861.94843887951 / fConst2) + 498.66388364147014) / fConst2) + 1.0);
		fConst309 = (1.0 / ((fConst303 * fConst305) * fConst308));
		fConst310 = (0.0 - (835447.79375551804 / (fConst5 * fConst308)));
		fConst311 = (0.0 - (((835447.79375551804 / fConst2) + 997.32776728294027) / (fConst2 * fConst308)));
		fConst312 = ((((105143.88595770916 / fConst2) + 621.26364328515456) / fConst2) + 1.0);
		fConst313 = (0.0 - (420575.54383083666 / (fConst5 * fConst312)));
		fConst314 = (0.0 - (((420575.54383083666 / fConst2) + 1242.5272865703091) / (fConst2 * fConst312)));
		fConst315 = ((((132150.40328687569 / fConst2) + 451.28205259787001) / fConst2) + 1.0);
		fConst316 = (1.0 / (fConst312 * fConst315));
		fConst317 = (0.0 - (528601.61314750277 / (fConst5 * fConst315)));
		fConst318 = (0.0 - (((528601.61314750277 / fConst2) + 902.56410519574001) / (fConst2 * fConst315)));
		fConst319 = ((249.06499071468039 / fConst2) + 1.0);
		fConst320 = (0.0 - (498.12998142936078 / (fConst2 * fConst319)));
		fConst321 = ((((74306.359791578565 / fConst2) + 394.46242681513445) / fConst2) + 1.0);
		fConst322 = (1.0 / (fConst319 * fConst321));
		fConst323 = (0.0 - (297225.43916631426 / (fConst5 * fConst321)));
		fConst324 = (0.0 - (((297225.43916631426 / fConst2) + 788.9248536302689) / (fConst2 * fConst321)));
		fConst325 = ((107.25456958830247 / fConst2) + 1.0);
		fConst326 = (1.0 / fConst325);
		fConst327 = (0.0 - (214.50913917660495 / (fConst325 * fConst2)));
		fConst328 = ((((34510.628092716055 / fConst2) + 321.76370876490739) / fConst2) + 1.0);
		fConst329 = (1.0 / fConst328);
		fConst330 = (0.0 - (138042.51237086422 / (fConst5 * fConst328)));
		fConst331 = (0.0 - (((138042.51237086422 / fConst2) + 643.52741752981478) / (fConst2 * fConst328)));
		iConst332 = int(((0.0051746047010432453 * double(iConst0)) + 0.5));
		
	}
	
	virtual void instanceResetUserInterface() {
		fCheckbox0 = FAUSTFLOAT(0.0);
		fHslider0 = FAUSTFLOAT(-10.0);
		fHslider1 = FAUSTFLOAT(400.0);
		fHslider2 = FAUSTFLOAT(0.0);
		
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0;
			
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0;
			
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec2[l2] = 0.0;
			
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0;
			
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
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec28[l13] = 0.0;
			
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec29[l14] = 0.0;
			
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec18[l15] = 0.0;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec16[l16] = 0.0;
			
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec15[l17] = 0.0;
			
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec13[l18] = 0.0;
			
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec12[l19] = 0.0;
			
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec10[l20] = 0.0;
			
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec9[l21] = 0.0;
			
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec7[l22] = 0.0;
			
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec6[l23] = 0.0;
			
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec4[l24] = 0.0;
			
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
		for (int l33 = 0; (l33 < 3); l33 = (l33 + 1)) {
			fRec50[l33] = 0.0;
			
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec41[l34] = 0.0;
			
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec39[l35] = 0.0;
			
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec38[l36] = 0.0;
			
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec36[l37] = 0.0;
			
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec35[l38] = 0.0;
			
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec33[l39] = 0.0;
			
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec32[l40] = 0.0;
			
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec30[l41] = 0.0;
			
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
		for (int l48 = 0; (l48 < 3); l48 = (l48 + 1)) {
			fRec66[l48] = 0.0;
			
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec59[l49] = 0.0;
			
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec57[l50] = 0.0;
			
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fRec56[l51] = 0.0;
			
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec54[l52] = 0.0;
			
		}
		for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
			fRec53[l53] = 0.0;
			
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fRec51[l54] = 0.0;
			
		}
		for (int l55 = 0; (l55 < 3); l55 = (l55 + 1)) {
			fRec70[l55] = 0.0;
			
		}
		for (int l56 = 0; (l56 < 3); l56 = (l56 + 1)) {
			fRec71[l56] = 0.0;
			
		}
		for (int l57 = 0; (l57 < 3); l57 = (l57 + 1)) {
			fRec72[l57] = 0.0;
			
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fRec69[l58] = 0.0;
			
		}
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			fRec67[l59] = 0.0;
			
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
		for (int l64 = 0; (l64 < 3); l64 = (l64 + 1)) {
			fRec83[l64] = 0.0;
			
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec78[l65] = 0.0;
			
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec76[l66] = 0.0;
			
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec75[l67] = 0.0;
			
		}
		for (int l68 = 0; (l68 < 2); l68 = (l68 + 1)) {
			fRec73[l68] = 0.0;
			
		}
		IOTA = 0;
		for (int l69 = 0; (l69 < 128); l69 = (l69 + 1)) {
			fVec0[l69] = 0.0;
			
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec98[l70] = 0.0;
			
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec96[l71] = 0.0;
			
		}
		for (int l72 = 0; (l72 < 2); l72 = (l72 + 1)) {
			fRec95[l72] = 0.0;
			
		}
		for (int l73 = 0; (l73 < 2); l73 = (l73 + 1)) {
			fRec93[l73] = 0.0;
			
		}
		for (int l74 = 0; (l74 < 2); l74 = (l74 + 1)) {
			fRec92[l74] = 0.0;
			
		}
		for (int l75 = 0; (l75 < 2); l75 = (l75 + 1)) {
			fRec90[l75] = 0.0;
			
		}
		for (int l76 = 0; (l76 < 2); l76 = (l76 + 1)) {
			fRec89[l76] = 0.0;
			
		}
		for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) {
			fRec87[l77] = 0.0;
			
		}
		for (int l78 = 0; (l78 < 2); l78 = (l78 + 1)) {
			fRec86[l78] = 0.0;
			
		}
		for (int l79 = 0; (l79 < 2); l79 = (l79 + 1)) {
			fRec84[l79] = 0.0;
			
		}
		for (int l80 = 0; (l80 < 2); l80 = (l80 + 1)) {
			fRec104[l80] = 0.0;
			
		}
		for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) {
			fRec102[l81] = 0.0;
			
		}
		for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) {
			fRec101[l82] = 0.0;
			
		}
		for (int l83 = 0; (l83 < 2); l83 = (l83 + 1)) {
			fRec99[l83] = 0.0;
			
		}
		for (int l84 = 0; (l84 < 2); l84 = (l84 + 1)) {
			fRec107[l84] = 0.0;
			
		}
		for (int l85 = 0; (l85 < 2); l85 = (l85 + 1)) {
			fRec105[l85] = 0.0;
			
		}
		for (int l86 = 0; (l86 < 2); l86 = (l86 + 1)) {
			fRec116[l86] = 0.0;
			
		}
		for (int l87 = 0; (l87 < 2); l87 = (l87 + 1)) {
			fRec114[l87] = 0.0;
			
		}
		for (int l88 = 0; (l88 < 2); l88 = (l88 + 1)) {
			fRec113[l88] = 0.0;
			
		}
		for (int l89 = 0; (l89 < 2); l89 = (l89 + 1)) {
			fRec111[l89] = 0.0;
			
		}
		for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) {
			fRec110[l90] = 0.0;
			
		}
		for (int l91 = 0; (l91 < 2); l91 = (l91 + 1)) {
			fRec108[l91] = 0.0;
			
		}
		for (int l92 = 0; (l92 < 2); l92 = (l92 + 1)) {
			fRec128[l92] = 0.0;
			
		}
		for (int l93 = 0; (l93 < 2); l93 = (l93 + 1)) {
			fRec126[l93] = 0.0;
			
		}
		for (int l94 = 0; (l94 < 2); l94 = (l94 + 1)) {
			fRec125[l94] = 0.0;
			
		}
		for (int l95 = 0; (l95 < 2); l95 = (l95 + 1)) {
			fRec123[l95] = 0.0;
			
		}
		for (int l96 = 0; (l96 < 2); l96 = (l96 + 1)) {
			fRec122[l96] = 0.0;
			
		}
		for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) {
			fRec120[l97] = 0.0;
			
		}
		for (int l98 = 0; (l98 < 2); l98 = (l98 + 1)) {
			fRec119[l98] = 0.0;
			
		}
		for (int l99 = 0; (l99 < 2); l99 = (l99 + 1)) {
			fRec117[l99] = 0.0;
			
		}
		for (int l100 = 0; (l100 < 64); l100 = (l100 + 1)) {
			fVec1[l100] = 0.0;
			
		}
		for (int l101 = 0; (l101 < 2); l101 = (l101 + 1)) {
			fRec143[l101] = 0.0;
			
		}
		for (int l102 = 0; (l102 < 2); l102 = (l102 + 1)) {
			fRec141[l102] = 0.0;
			
		}
		for (int l103 = 0; (l103 < 2); l103 = (l103 + 1)) {
			fRec140[l103] = 0.0;
			
		}
		for (int l104 = 0; (l104 < 2); l104 = (l104 + 1)) {
			fRec138[l104] = 0.0;
			
		}
		for (int l105 = 0; (l105 < 2); l105 = (l105 + 1)) {
			fRec137[l105] = 0.0;
			
		}
		for (int l106 = 0; (l106 < 2); l106 = (l106 + 1)) {
			fRec135[l106] = 0.0;
			
		}
		for (int l107 = 0; (l107 < 2); l107 = (l107 + 1)) {
			fRec134[l107] = 0.0;
			
		}
		for (int l108 = 0; (l108 < 2); l108 = (l108 + 1)) {
			fRec132[l108] = 0.0;
			
		}
		for (int l109 = 0; (l109 < 2); l109 = (l109 + 1)) {
			fRec131[l109] = 0.0;
			
		}
		for (int l110 = 0; (l110 < 2); l110 = (l110 + 1)) {
			fRec129[l110] = 0.0;
			
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec155[l111] = 0.0;
			
		}
		for (int l112 = 0; (l112 < 2); l112 = (l112 + 1)) {
			fRec153[l112] = 0.0;
			
		}
		for (int l113 = 0; (l113 < 2); l113 = (l113 + 1)) {
			fRec152[l113] = 0.0;
			
		}
		for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) {
			fRec150[l114] = 0.0;
			
		}
		for (int l115 = 0; (l115 < 2); l115 = (l115 + 1)) {
			fRec149[l115] = 0.0;
			
		}
		for (int l116 = 0; (l116 < 2); l116 = (l116 + 1)) {
			fRec147[l116] = 0.0;
			
		}
		for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) {
			fRec146[l117] = 0.0;
			
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			fRec144[l118] = 0.0;
			
		}
		for (int l119 = 0; (l119 < 2); l119 = (l119 + 1)) {
			fRec164[l119] = 0.0;
			
		}
		for (int l120 = 0; (l120 < 2); l120 = (l120 + 1)) {
			fRec162[l120] = 0.0;
			
		}
		for (int l121 = 0; (l121 < 2); l121 = (l121 + 1)) {
			fRec161[l121] = 0.0;
			
		}
		for (int l122 = 0; (l122 < 2); l122 = (l122 + 1)) {
			fRec159[l122] = 0.0;
			
		}
		for (int l123 = 0; (l123 < 2); l123 = (l123 + 1)) {
			fRec158[l123] = 0.0;
			
		}
		for (int l124 = 0; (l124 < 2); l124 = (l124 + 1)) {
			fRec156[l124] = 0.0;
			
		}
		for (int l125 = 0; (l125 < 2); l125 = (l125 + 1)) {
			fRec167[l125] = 0.0;
			
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fRec165[l126] = 0.0;
			
		}
		for (int l127 = 0; (l127 < 2); l127 = (l127 + 1)) {
			fRec173[l127] = 0.0;
			
		}
		for (int l128 = 0; (l128 < 2); l128 = (l128 + 1)) {
			fRec171[l128] = 0.0;
			
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec170[l129] = 0.0;
			
		}
		for (int l130 = 0; (l130 < 2); l130 = (l130 + 1)) {
			fRec168[l130] = 0.0;
			
		}
		for (int l131 = 0; (l131 < 16); l131 = (l131 + 1)) {
			fVec2[l131] = 0.0;
			
		}
		for (int l132 = 0; (l132 < 2); l132 = (l132 + 1)) {
			fRec188[l132] = 0.0;
			
		}
		for (int l133 = 0; (l133 < 2); l133 = (l133 + 1)) {
			fRec186[l133] = 0.0;
			
		}
		for (int l134 = 0; (l134 < 2); l134 = (l134 + 1)) {
			fRec185[l134] = 0.0;
			
		}
		for (int l135 = 0; (l135 < 2); l135 = (l135 + 1)) {
			fRec183[l135] = 0.0;
			
		}
		for (int l136 = 0; (l136 < 2); l136 = (l136 + 1)) {
			fRec182[l136] = 0.0;
			
		}
		for (int l137 = 0; (l137 < 2); l137 = (l137 + 1)) {
			fRec180[l137] = 0.0;
			
		}
		for (int l138 = 0; (l138 < 2); l138 = (l138 + 1)) {
			fRec179[l138] = 0.0;
			
		}
		for (int l139 = 0; (l139 < 2); l139 = (l139 + 1)) {
			fRec177[l139] = 0.0;
			
		}
		for (int l140 = 0; (l140 < 2); l140 = (l140 + 1)) {
			fRec176[l140] = 0.0;
			
		}
		for (int l141 = 0; (l141 < 2); l141 = (l141 + 1)) {
			fRec174[l141] = 0.0;
			
		}
		for (int l142 = 0; (l142 < 2); l142 = (l142 + 1)) {
			fRec200[l142] = 0.0;
			
		}
		for (int l143 = 0; (l143 < 2); l143 = (l143 + 1)) {
			fRec198[l143] = 0.0;
			
		}
		for (int l144 = 0; (l144 < 2); l144 = (l144 + 1)) {
			fRec197[l144] = 0.0;
			
		}
		for (int l145 = 0; (l145 < 2); l145 = (l145 + 1)) {
			fRec195[l145] = 0.0;
			
		}
		for (int l146 = 0; (l146 < 2); l146 = (l146 + 1)) {
			fRec194[l146] = 0.0;
			
		}
		for (int l147 = 0; (l147 < 2); l147 = (l147 + 1)) {
			fRec192[l147] = 0.0;
			
		}
		for (int l148 = 0; (l148 < 2); l148 = (l148 + 1)) {
			fRec191[l148] = 0.0;
			
		}
		for (int l149 = 0; (l149 < 2); l149 = (l149 + 1)) {
			fRec189[l149] = 0.0;
			
		}
		for (int l150 = 0; (l150 < 2); l150 = (l150 + 1)) {
			fRec209[l150] = 0.0;
			
		}
		for (int l151 = 0; (l151 < 2); l151 = (l151 + 1)) {
			fRec207[l151] = 0.0;
			
		}
		for (int l152 = 0; (l152 < 2); l152 = (l152 + 1)) {
			fRec206[l152] = 0.0;
			
		}
		for (int l153 = 0; (l153 < 2); l153 = (l153 + 1)) {
			fRec204[l153] = 0.0;
			
		}
		for (int l154 = 0; (l154 < 2); l154 = (l154 + 1)) {
			fRec203[l154] = 0.0;
			
		}
		for (int l155 = 0; (l155 < 2); l155 = (l155 + 1)) {
			fRec201[l155] = 0.0;
			
		}
		for (int l156 = 0; (l156 < 2); l156 = (l156 + 1)) {
			fRec212[l156] = 0.0;
			
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec210[l157] = 0.0;
			
		}
		for (int l158 = 0; (l158 < 2); l158 = (l158 + 1)) {
			fRec218[l158] = 0.0;
			
		}
		for (int l159 = 0; (l159 < 2); l159 = (l159 + 1)) {
			fRec216[l159] = 0.0;
			
		}
		for (int l160 = 0; (l160 < 2); l160 = (l160 + 1)) {
			fRec215[l160] = 0.0;
			
		}
		for (int l161 = 0; (l161 < 2); l161 = (l161 + 1)) {
			fRec213[l161] = 0.0;
			
		}
		for (int l162 = 0; (l162 < 64); l162 = (l162 + 1)) {
			fVec3[l162] = 0.0;
			
		}
		for (int l163 = 0; (l163 < 2); l163 = (l163 + 1)) {
			fRec233[l163] = 0.0;
			
		}
		for (int l164 = 0; (l164 < 2); l164 = (l164 + 1)) {
			fRec231[l164] = 0.0;
			
		}
		for (int l165 = 0; (l165 < 2); l165 = (l165 + 1)) {
			fRec230[l165] = 0.0;
			
		}
		for (int l166 = 0; (l166 < 2); l166 = (l166 + 1)) {
			fRec228[l166] = 0.0;
			
		}
		for (int l167 = 0; (l167 < 2); l167 = (l167 + 1)) {
			fRec227[l167] = 0.0;
			
		}
		for (int l168 = 0; (l168 < 2); l168 = (l168 + 1)) {
			fRec225[l168] = 0.0;
			
		}
		for (int l169 = 0; (l169 < 2); l169 = (l169 + 1)) {
			fRec224[l169] = 0.0;
			
		}
		for (int l170 = 0; (l170 < 2); l170 = (l170 + 1)) {
			fRec222[l170] = 0.0;
			
		}
		for (int l171 = 0; (l171 < 2); l171 = (l171 + 1)) {
			fRec221[l171] = 0.0;
			
		}
		for (int l172 = 0; (l172 < 2); l172 = (l172 + 1)) {
			fRec219[l172] = 0.0;
			
		}
		for (int l173 = 0; (l173 < 2); l173 = (l173 + 1)) {
			fRec245[l173] = 0.0;
			
		}
		for (int l174 = 0; (l174 < 2); l174 = (l174 + 1)) {
			fRec243[l174] = 0.0;
			
		}
		for (int l175 = 0; (l175 < 2); l175 = (l175 + 1)) {
			fRec242[l175] = 0.0;
			
		}
		for (int l176 = 0; (l176 < 2); l176 = (l176 + 1)) {
			fRec240[l176] = 0.0;
			
		}
		for (int l177 = 0; (l177 < 2); l177 = (l177 + 1)) {
			fRec239[l177] = 0.0;
			
		}
		for (int l178 = 0; (l178 < 2); l178 = (l178 + 1)) {
			fRec237[l178] = 0.0;
			
		}
		for (int l179 = 0; (l179 < 2); l179 = (l179 + 1)) {
			fRec236[l179] = 0.0;
			
		}
		for (int l180 = 0; (l180 < 2); l180 = (l180 + 1)) {
			fRec234[l180] = 0.0;
			
		}
		for (int l181 = 0; (l181 < 2); l181 = (l181 + 1)) {
			fRec254[l181] = 0.0;
			
		}
		for (int l182 = 0; (l182 < 2); l182 = (l182 + 1)) {
			fRec252[l182] = 0.0;
			
		}
		for (int l183 = 0; (l183 < 2); l183 = (l183 + 1)) {
			fRec251[l183] = 0.0;
			
		}
		for (int l184 = 0; (l184 < 2); l184 = (l184 + 1)) {
			fRec249[l184] = 0.0;
			
		}
		for (int l185 = 0; (l185 < 2); l185 = (l185 + 1)) {
			fRec248[l185] = 0.0;
			
		}
		for (int l186 = 0; (l186 < 2); l186 = (l186 + 1)) {
			fRec246[l186] = 0.0;
			
		}
		for (int l187 = 0; (l187 < 2); l187 = (l187 + 1)) {
			fRec257[l187] = 0.0;
			
		}
		for (int l188 = 0; (l188 < 2); l188 = (l188 + 1)) {
			fRec255[l188] = 0.0;
			
		}
		for (int l189 = 0; (l189 < 2); l189 = (l189 + 1)) {
			fRec263[l189] = 0.0;
			
		}
		for (int l190 = 0; (l190 < 2); l190 = (l190 + 1)) {
			fRec261[l190] = 0.0;
			
		}
		for (int l191 = 0; (l191 < 2); l191 = (l191 + 1)) {
			fRec260[l191] = 0.0;
			
		}
		for (int l192 = 0; (l192 < 2); l192 = (l192 + 1)) {
			fRec258[l192] = 0.0;
			
		}
		for (int l193 = 0; (l193 < 8); l193 = (l193 + 1)) {
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
			fRec290[l204] = 0.0;
			
		}
		for (int l205 = 0; (l205 < 2); l205 = (l205 + 1)) {
			fRec288[l205] = 0.0;
			
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
			fRec281[l210] = 0.0;
			
		}
		for (int l211 = 0; (l211 < 2); l211 = (l211 + 1)) {
			fRec279[l211] = 0.0;
			
		}
		for (int l212 = 0; (l212 < 2); l212 = (l212 + 1)) {
			fRec299[l212] = 0.0;
			
		}
		for (int l213 = 0; (l213 < 2); l213 = (l213 + 1)) {
			fRec297[l213] = 0.0;
			
		}
		for (int l214 = 0; (l214 < 2); l214 = (l214 + 1)) {
			fRec296[l214] = 0.0;
			
		}
		for (int l215 = 0; (l215 < 2); l215 = (l215 + 1)) {
			fRec294[l215] = 0.0;
			
		}
		for (int l216 = 0; (l216 < 2); l216 = (l216 + 1)) {
			fRec293[l216] = 0.0;
			
		}
		for (int l217 = 0; (l217 < 2); l217 = (l217 + 1)) {
			fRec291[l217] = 0.0;
			
		}
		for (int l218 = 0; (l218 < 2); l218 = (l218 + 1)) {
			fRec302[l218] = 0.0;
			
		}
		for (int l219 = 0; (l219 < 2); l219 = (l219 + 1)) {
			fRec300[l219] = 0.0;
			
		}
		for (int l220 = 0; (l220 < 2); l220 = (l220 + 1)) {
			fRec308[l220] = 0.0;
			
		}
		for (int l221 = 0; (l221 < 2); l221 = (l221 + 1)) {
			fRec306[l221] = 0.0;
			
		}
		for (int l222 = 0; (l222 < 2); l222 = (l222 + 1)) {
			fRec305[l222] = 0.0;
			
		}
		for (int l223 = 0; (l223 < 2); l223 = (l223 + 1)) {
			fRec303[l223] = 0.0;
			
		}
		for (int l224 = 0; (l224 < 2); l224 = (l224 + 1)) {
			fRec323[l224] = 0.0;
			
		}
		for (int l225 = 0; (l225 < 2); l225 = (l225 + 1)) {
			fRec321[l225] = 0.0;
			
		}
		for (int l226 = 0; (l226 < 2); l226 = (l226 + 1)) {
			fRec320[l226] = 0.0;
			
		}
		for (int l227 = 0; (l227 < 2); l227 = (l227 + 1)) {
			fRec318[l227] = 0.0;
			
		}
		for (int l228 = 0; (l228 < 2); l228 = (l228 + 1)) {
			fRec317[l228] = 0.0;
			
		}
		for (int l229 = 0; (l229 < 2); l229 = (l229 + 1)) {
			fRec315[l229] = 0.0;
			
		}
		for (int l230 = 0; (l230 < 2); l230 = (l230 + 1)) {
			fRec314[l230] = 0.0;
			
		}
		for (int l231 = 0; (l231 < 2); l231 = (l231 + 1)) {
			fRec312[l231] = 0.0;
			
		}
		for (int l232 = 0; (l232 < 2); l232 = (l232 + 1)) {
			fRec311[l232] = 0.0;
			
		}
		for (int l233 = 0; (l233 < 2); l233 = (l233 + 1)) {
			fRec309[l233] = 0.0;
			
		}
		for (int l234 = 0; (l234 < 2); l234 = (l234 + 1)) {
			fRec335[l234] = 0.0;
			
		}
		for (int l235 = 0; (l235 < 2); l235 = (l235 + 1)) {
			fRec333[l235] = 0.0;
			
		}
		for (int l236 = 0; (l236 < 2); l236 = (l236 + 1)) {
			fRec332[l236] = 0.0;
			
		}
		for (int l237 = 0; (l237 < 2); l237 = (l237 + 1)) {
			fRec330[l237] = 0.0;
			
		}
		for (int l238 = 0; (l238 < 2); l238 = (l238 + 1)) {
			fRec329[l238] = 0.0;
			
		}
		for (int l239 = 0; (l239 < 2); l239 = (l239 + 1)) {
			fRec327[l239] = 0.0;
			
		}
		for (int l240 = 0; (l240 < 2); l240 = (l240 + 1)) {
			fRec326[l240] = 0.0;
			
		}
		for (int l241 = 0; (l241 < 2); l241 = (l241 + 1)) {
			fRec324[l241] = 0.0;
			
		}
		for (int l242 = 0; (l242 < 2); l242 = (l242 + 1)) {
			fRec344[l242] = 0.0;
			
		}
		for (int l243 = 0; (l243 < 2); l243 = (l243 + 1)) {
			fRec342[l243] = 0.0;
			
		}
		for (int l244 = 0; (l244 < 2); l244 = (l244 + 1)) {
			fRec341[l244] = 0.0;
			
		}
		for (int l245 = 0; (l245 < 2); l245 = (l245 + 1)) {
			fRec339[l245] = 0.0;
			
		}
		for (int l246 = 0; (l246 < 2); l246 = (l246 + 1)) {
			fRec338[l246] = 0.0;
			
		}
		for (int l247 = 0; (l247 < 2); l247 = (l247 + 1)) {
			fRec336[l247] = 0.0;
			
		}
		for (int l248 = 0; (l248 < 2); l248 = (l248 + 1)) {
			fRec347[l248] = 0.0;
			
		}
		for (int l249 = 0; (l249 < 2); l249 = (l249 + 1)) {
			fRec345[l249] = 0.0;
			
		}
		for (int l250 = 0; (l250 < 2); l250 = (l250 + 1)) {
			fRec353[l250] = 0.0;
			
		}
		for (int l251 = 0; (l251 < 2); l251 = (l251 + 1)) {
			fRec351[l251] = 0.0;
			
		}
		for (int l252 = 0; (l252 < 2); l252 = (l252 + 1)) {
			fRec350[l252] = 0.0;
			
		}
		for (int l253 = 0; (l253 < 2); l253 = (l253 + 1)) {
			fRec348[l253] = 0.0;
			
		}
		for (int l254 = 0; (l254 < 128); l254 = (l254 + 1)) {
			fVec5[l254] = 0.0;
			
		}
		for (int l255 = 0; (l255 < 2); l255 = (l255 + 1)) {
			fRec368[l255] = 0.0;
			
		}
		for (int l256 = 0; (l256 < 2); l256 = (l256 + 1)) {
			fRec366[l256] = 0.0;
			
		}
		for (int l257 = 0; (l257 < 2); l257 = (l257 + 1)) {
			fRec365[l257] = 0.0;
			
		}
		for (int l258 = 0; (l258 < 2); l258 = (l258 + 1)) {
			fRec363[l258] = 0.0;
			
		}
		for (int l259 = 0; (l259 < 2); l259 = (l259 + 1)) {
			fRec362[l259] = 0.0;
			
		}
		for (int l260 = 0; (l260 < 2); l260 = (l260 + 1)) {
			fRec360[l260] = 0.0;
			
		}
		for (int l261 = 0; (l261 < 2); l261 = (l261 + 1)) {
			fRec359[l261] = 0.0;
			
		}
		for (int l262 = 0; (l262 < 2); l262 = (l262 + 1)) {
			fRec357[l262] = 0.0;
			
		}
		for (int l263 = 0; (l263 < 2); l263 = (l263 + 1)) {
			fRec356[l263] = 0.0;
			
		}
		for (int l264 = 0; (l264 < 2); l264 = (l264 + 1)) {
			fRec354[l264] = 0.0;
			
		}
		for (int l265 = 0; (l265 < 2); l265 = (l265 + 1)) {
			fRec380[l265] = 0.0;
			
		}
		for (int l266 = 0; (l266 < 2); l266 = (l266 + 1)) {
			fRec378[l266] = 0.0;
			
		}
		for (int l267 = 0; (l267 < 2); l267 = (l267 + 1)) {
			fRec377[l267] = 0.0;
			
		}
		for (int l268 = 0; (l268 < 2); l268 = (l268 + 1)) {
			fRec375[l268] = 0.0;
			
		}
		for (int l269 = 0; (l269 < 2); l269 = (l269 + 1)) {
			fRec374[l269] = 0.0;
			
		}
		for (int l270 = 0; (l270 < 2); l270 = (l270 + 1)) {
			fRec372[l270] = 0.0;
			
		}
		for (int l271 = 0; (l271 < 2); l271 = (l271 + 1)) {
			fRec371[l271] = 0.0;
			
		}
		for (int l272 = 0; (l272 < 2); l272 = (l272 + 1)) {
			fRec369[l272] = 0.0;
			
		}
		for (int l273 = 0; (l273 < 2); l273 = (l273 + 1)) {
			fRec389[l273] = 0.0;
			
		}
		for (int l274 = 0; (l274 < 2); l274 = (l274 + 1)) {
			fRec387[l274] = 0.0;
			
		}
		for (int l275 = 0; (l275 < 2); l275 = (l275 + 1)) {
			fRec386[l275] = 0.0;
			
		}
		for (int l276 = 0; (l276 < 2); l276 = (l276 + 1)) {
			fRec384[l276] = 0.0;
			
		}
		for (int l277 = 0; (l277 < 2); l277 = (l277 + 1)) {
			fRec383[l277] = 0.0;
			
		}
		for (int l278 = 0; (l278 < 2); l278 = (l278 + 1)) {
			fRec381[l278] = 0.0;
			
		}
		for (int l279 = 0; (l279 < 2); l279 = (l279 + 1)) {
			fRec392[l279] = 0.0;
			
		}
		for (int l280 = 0; (l280 < 2); l280 = (l280 + 1)) {
			fRec390[l280] = 0.0;
			
		}
		for (int l281 = 0; (l281 < 2); l281 = (l281 + 1)) {
			fRec398[l281] = 0.0;
			
		}
		for (int l282 = 0; (l282 < 2); l282 = (l282 + 1)) {
			fRec396[l282] = 0.0;
			
		}
		for (int l283 = 0; (l283 < 2); l283 = (l283 + 1)) {
			fRec395[l283] = 0.0;
			
		}
		for (int l284 = 0; (l284 < 2); l284 = (l284 + 1)) {
			fRec393[l284] = 0.0;
			
		}
		for (int l285 = 0; (l285 < 64); l285 = (l285 + 1)) {
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
		for (int l316 = 0; (l316 < 256); l316 = (l316 + 1)) {
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
			fRec497[l348] = 0.0;
			
		}
		for (int l349 = 0; (l349 < 2); l349 = (l349 + 1)) {
			fRec495[l349] = 0.0;
			
		}
		for (int l350 = 0; (l350 < 2); l350 = (l350 + 1)) {
			fRec494[l350] = 0.0;
			
		}
		for (int l351 = 0; (l351 < 2); l351 = (l351 + 1)) {
			fRec492[l351] = 0.0;
			
		}
		for (int l352 = 0; (l352 < 2); l352 = (l352 + 1)) {
			fRec491[l352] = 0.0;
			
		}
		for (int l353 = 0; (l353 < 2); l353 = (l353 + 1)) {
			fRec489[l353] = 0.0;
			
		}
		for (int l354 = 0; (l354 < 2); l354 = (l354 + 1)) {
			fRec500[l354] = 0.0;
			
		}
		for (int l355 = 0; (l355 < 2); l355 = (l355 + 1)) {
			fRec498[l355] = 0.0;
			
		}
		for (int l356 = 0; (l356 < 2); l356 = (l356 + 1)) {
			fRec506[l356] = 0.0;
			
		}
		for (int l357 = 0; (l357 < 2); l357 = (l357 + 1)) {
			fRec504[l357] = 0.0;
			
		}
		for (int l358 = 0; (l358 < 2); l358 = (l358 + 1)) {
			fRec503[l358] = 0.0;
			
		}
		for (int l359 = 0; (l359 < 2); l359 = (l359 + 1)) {
			fRec501[l359] = 0.0;
			
		}
		for (int l360 = 0; (l360 < 2); l360 = (l360 + 1)) {
			fRec518[l360] = 0.0;
			
		}
		for (int l361 = 0; (l361 < 2); l361 = (l361 + 1)) {
			fRec516[l361] = 0.0;
			
		}
		for (int l362 = 0; (l362 < 2); l362 = (l362 + 1)) {
			fRec515[l362] = 0.0;
			
		}
		for (int l363 = 0; (l363 < 2); l363 = (l363 + 1)) {
			fRec513[l363] = 0.0;
			
		}
		for (int l364 = 0; (l364 < 2); l364 = (l364 + 1)) {
			fRec512[l364] = 0.0;
			
		}
		for (int l365 = 0; (l365 < 2); l365 = (l365 + 1)) {
			fRec510[l365] = 0.0;
			
		}
		for (int l366 = 0; (l366 < 2); l366 = (l366 + 1)) {
			fRec509[l366] = 0.0;
			
		}
		for (int l367 = 0; (l367 < 2); l367 = (l367 + 1)) {
			fRec507[l367] = 0.0;
			
		}
		for (int l368 = 0; (l368 < 2); l368 = (l368 + 1)) {
			fRec533[l368] = 0.0;
			
		}
		for (int l369 = 0; (l369 < 2); l369 = (l369 + 1)) {
			fRec531[l369] = 0.0;
			
		}
		for (int l370 = 0; (l370 < 2); l370 = (l370 + 1)) {
			fRec530[l370] = 0.0;
			
		}
		for (int l371 = 0; (l371 < 2); l371 = (l371 + 1)) {
			fRec528[l371] = 0.0;
			
		}
		for (int l372 = 0; (l372 < 2); l372 = (l372 + 1)) {
			fRec527[l372] = 0.0;
			
		}
		for (int l373 = 0; (l373 < 2); l373 = (l373 + 1)) {
			fRec525[l373] = 0.0;
			
		}
		for (int l374 = 0; (l374 < 2); l374 = (l374 + 1)) {
			fRec524[l374] = 0.0;
			
		}
		for (int l375 = 0; (l375 < 2); l375 = (l375 + 1)) {
			fRec522[l375] = 0.0;
			
		}
		for (int l376 = 0; (l376 < 2); l376 = (l376 + 1)) {
			fRec521[l376] = 0.0;
			
		}
		for (int l377 = 0; (l377 < 2); l377 = (l377 + 1)) {
			fRec519[l377] = 0.0;
			
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
			fRec563[l397] = 0.0;
			
		}
		for (int l398 = 0; (l398 < 2); l398 = (l398 + 1)) {
			fRec561[l398] = 0.0;
			
		}
		for (int l399 = 0; (l399 < 2); l399 = (l399 + 1)) {
			fRec569[l399] = 0.0;
			
		}
		for (int l400 = 0; (l400 < 2); l400 = (l400 + 1)) {
			fRec567[l400] = 0.0;
			
		}
		for (int l401 = 0; (l401 < 2); l401 = (l401 + 1)) {
			fRec566[l401] = 0.0;
			
		}
		for (int l402 = 0; (l402 < 2); l402 = (l402 + 1)) {
			fRec564[l402] = 0.0;
			
		}
		for (int l403 = 0; (l403 < 2); l403 = (l403 + 1)) {
			fRec578[l403] = 0.0;
			
		}
		for (int l404 = 0; (l404 < 2); l404 = (l404 + 1)) {
			fRec576[l404] = 0.0;
			
		}
		for (int l405 = 0; (l405 < 2); l405 = (l405 + 1)) {
			fRec575[l405] = 0.0;
			
		}
		for (int l406 = 0; (l406 < 2); l406 = (l406 + 1)) {
			fRec573[l406] = 0.0;
			
		}
		for (int l407 = 0; (l407 < 2); l407 = (l407 + 1)) {
			fRec572[l407] = 0.0;
			
		}
		for (int l408 = 0; (l408 < 2); l408 = (l408 + 1)) {
			fRec570[l408] = 0.0;
			
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
			fRec617[l434] = 0.0;
			
		}
		for (int l435 = 0; (l435 < 2); l435 = (l435 + 1)) {
			fRec615[l435] = 0.0;
			
		}
		for (int l436 = 0; (l436 < 2); l436 = (l436 + 1)) {
			fRec623[l436] = 0.0;
			
		}
		for (int l437 = 0; (l437 < 2); l437 = (l437 + 1)) {
			fRec621[l437] = 0.0;
			
		}
		for (int l438 = 0; (l438 < 2); l438 = (l438 + 1)) {
			fRec620[l438] = 0.0;
			
		}
		for (int l439 = 0; (l439 < 2); l439 = (l439 + 1)) {
			fRec618[l439] = 0.0;
			
		}
		for (int l440 = 0; (l440 < 1024); l440 = (l440 + 1)) {
			fVec11[l440] = 0.0;
			
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
		ui_interface->openVerticalBox("KMH114_AE_5h5p_normal_6");
		ui_interface->declare(&fHslider0, "unit", "dB");
		ui_interface->addHorizontalSlider("gain", &fHslider0, -10.0, -30.0, 10.0, 1.0);
		ui_interface->declare(&fHslider2, "unit", "dB");
		ui_interface->addHorizontalSlider("lf/hf", &fHslider2, 0.0, -3.0, 3.0, 0.10000000000000001);
		ui_interface->addCheckButton("mute", &fCheckbox0);
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("xover", &fHslider1, 400.0, 200.0, 800.0, 20.0);
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
		double fSlow0 = (0.0010000000000000009 * (double((double(fCheckbox0) < 0.5)) * std::pow(10.0, (0.050000000000000003 * double(fHslider0)))));
		double fSlow1 = (0.0010000000000000009 * double(fHslider1));
		double fSlow2 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fHslider2))));
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec0[0] = (fSlow0 + (0.999 * fRec0[1]));
			fRec1[0] = (fSlow1 + (0.999 * fRec1[1]));
			double fTemp0 = std::tan((fConst1 * fRec1[0]));
			double fTemp1 = mydsp_faustpower2_f(fTemp0);
			double fTemp2 = ((fTemp0 * (fTemp0 + -2.0)) + 1.0);
			double fTemp3 = (fTemp1 + -1.0);
			double fTemp4 = ((fTemp0 * (fTemp0 + 2.0)) + 1.0);
			fRec2[0] = (double(input0[i]) - (((fRec2[2] * fTemp2) + (2.0 * (fRec2[1] * fTemp3))) / fTemp4));
			fRec3[0] = (fSlow2 + (0.999 * fRec3[1]));
			double fTemp5 = (fRec3[0] * fTemp4);
			double fTemp6 = (0.0 - (2.0 / fTemp4));
			double fTemp7 = (((fTemp1 * (fRec2[2] + (fRec2[0] + (2.0 * fRec2[1])))) / fTemp5) + (fRec3[0] * (0.0 - ((fRec2[1] * fTemp6) + ((fRec2[0] + fRec2[2]) / fTemp4)))));
			double fTemp8 = (fConst4 * fRec4[1]);
			double fTemp9 = (fConst7 * fRec7[1]);
			double fTemp10 = (fConst8 * fRec10[1]);
			fRec19[0] = (double(input25[i]) - (((fRec19[2] * fTemp2) + (2.0 * (fRec19[1] * fTemp3))) / fTemp4));
			double fTemp11 = ((((fRec19[2] + (fRec19[0] + (2.0 * fRec19[1]))) * fTemp1) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fRec19[1] * fTemp6) + ((fRec19[0] + fRec19[2]) / fTemp4))))));
			fRec20[0] = (double(input28[i]) - (((fRec20[2] * fTemp2) + (2.0 * (fRec20[1] * fTemp3))) / fTemp4));
			double fTemp12 = ((((fRec20[2] + (fRec20[0] + (2.0 * fRec20[1]))) * fTemp1) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fRec20[1] * fTemp6) + ((fRec20[0] + fRec20[2]) / fTemp4))))));
			fRec21[0] = (double(input29[i]) - (((fTemp2 * fRec21[2]) + (2.0 * (fRec21[1] * fTemp3))) / fTemp4));
			double fTemp13 = (((fTemp1 * (fRec21[2] + (fRec21[0] + (2.0 * fRec21[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fRec21[1] * fTemp6) + ((fRec21[0] + fRec21[2]) / fTemp4))))));
			fRec22[0] = (double(input30[i]) - (((fTemp2 * fRec22[2]) + (2.0 * (fTemp3 * fRec22[1]))) / fTemp4));
			double fTemp14 = (((fTemp1 * (fRec22[2] + (fRec22[0] + (2.0 * fRec22[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec22[1]) + ((fRec22[0] + fRec22[2]) / fTemp4))))));
			fRec23[0] = (double(input31[i]) - (((fTemp2 * fRec23[2]) + (2.0 * (fTemp3 * fRec23[1]))) / fTemp4));
			double fTemp15 = (((fTemp1 * (fRec23[2] + (fRec23[0] + (2.0 * fRec23[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec23[1]) + ((fRec23[0] + fRec23[2]) / fTemp4))))));
			fRec24[0] = (double(input26[i]) - (((fRec24[2] * fTemp2) + (2.0 * (fRec24[1] * fTemp3))) / fTemp4));
			double fTemp16 = ((((fRec24[2] + (fRec24[0] + (2.0 * fRec24[1]))) * fTemp1) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fRec24[1] * fTemp6) + ((fRec24[0] + fRec24[2]) / fTemp4))))));
			fRec25[0] = (double(input27[i]) - (((fRec25[2] * fTemp2) + (2.0 * (fRec25[1] * fTemp3))) / fTemp4));
			double fTemp17 = ((((fRec25[2] + (fRec25[0] + (2.0 * fRec25[1]))) * fTemp1) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fRec25[1] * fTemp6) + ((fRec25[0] + fRec25[2]) / fTemp4))))));
			fRec26[0] = (double(input32[i]) - (((fTemp2 * fRec26[2]) + (2.0 * (fTemp3 * fRec26[1]))) / fTemp4));
			double fTemp18 = (((fTemp1 * (fRec26[2] + (fRec26[0] + (2.0 * fRec26[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec26[1]) + ((fRec26[0] + fRec26[2]) / fTemp4))))));
			fRec27[0] = (double(input33[i]) - (((fTemp2 * fRec27[2]) + (2.0 * (fTemp3 * fRec27[1]))) / fTemp4));
			double fTemp19 = (((fTemp1 * (fRec27[2] + (fRec27[0] + (2.0 * fRec27[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec27[1]) + ((fRec27[0] + fRec27[2]) / fTemp4))))));
			fRec28[0] = (double(input34[i]) - (((fTemp2 * fRec28[2]) + (2.0 * (fTemp3 * fRec28[1]))) / fTemp4));
			double fTemp20 = (((fTemp1 * (fRec28[2] + (fRec28[0] + (2.0 * fRec28[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec28[1]) + ((fRec28[0] + fRec28[2]) / fTemp4))))));
			fRec29[0] = (double(input35[i]) - (((fTemp2 * fRec29[2]) + (2.0 * (fTemp3 * fRec29[1]))) / fTemp4));
			double fTemp21 = (((fTemp1 * (fRec29[2] + (fRec29[0] + (2.0 * fRec29[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec29[1]) + ((fRec29[0] + fRec29[2]) / fTemp4))))));
			double fTemp22 = (fConst10 * ((((((0.071427591900000004 * fTemp11) + (0.016950204100000001 * fTemp12)) + (0.016206051900000001 * fTemp13)) + (0.0035728342000000001 * fTemp14)) + (0.065868397100000003 * fTemp15)) - ((((((0.088662499500000005 * fTemp16) + (0.0032925643000000001 * fTemp17)) + (0.013921811500000001 * fTemp18)) + (0.019954593900000001 * fTemp19)) + (0.0015771972999999999 * fTemp20)) + (0.0062367956999999996 * fTemp21))));
			double fTemp23 = (fConst11 * fRec13[1]);
			double fTemp24 = (fConst12 * fRec16[1]);
			fRec18[0] = (fTemp22 + (fTemp23 + (fRec18[1] + fTemp24)));
			fRec16[0] = fRec18[0];
			double fRec17 = ((fTemp24 + fTemp23) + fTemp22);
			fRec15[0] = (fRec16[0] + fRec15[1]);
			fRec13[0] = fRec15[0];
			double fRec14 = fRec17;
			fRec12[0] = (fTemp9 + (fTemp10 + (fRec14 + fRec12[1])));
			fRec10[0] = fRec12[0];
			double fRec11 = (fTemp9 + (fRec14 + fTemp10));
			fRec9[0] = (fRec10[0] + fRec9[1]);
			fRec7[0] = fRec9[0];
			double fRec8 = fRec11;
			fRec6[0] = (fTemp8 + (fRec8 + fRec6[1]));
			fRec4[0] = fRec6[0];
			double fRec5 = (fRec8 + fTemp8);
			double fTemp25 = (fConst14 * fRec30[1]);
			double fTemp26 = (fConst15 * fRec33[1]);
			fRec42[0] = (double(input16[i]) - (((fRec42[2] * fTemp2) + (2.0 * (fRec42[1] * fTemp3))) / fTemp4));
			double fTemp27 = ((((fRec42[2] + (fRec42[0] + (2.0 * fRec42[1]))) * fTemp1) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fRec42[1] * fTemp6) + ((fRec42[0] + fRec42[2]) / fTemp4))))));
			fRec43[0] = (double(input19[i]) - (((fRec43[2] * fTemp2) + (2.0 * (fRec43[1] * fTemp3))) / fTemp4));
			double fTemp28 = ((((fRec43[2] + (fRec43[0] + (2.0 * fRec43[1]))) * fTemp1) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fRec43[1] * fTemp6) + ((fRec43[0] + fRec43[2]) / fTemp4))))));
			fRec44[0] = (double(input20[i]) - (((fRec44[2] * fTemp2) + (2.0 * (fRec44[1] * fTemp3))) / fTemp4));
			double fTemp29 = ((((fRec44[2] + (fRec44[0] + (2.0 * fRec44[1]))) * fTemp1) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fRec44[1] * fTemp6) + ((fRec44[0] + fRec44[2]) / fTemp4))))));
			fRec45[0] = (double(input21[i]) - (((fRec45[2] * fTemp2) + (2.0 * (fRec45[1] * fTemp3))) / fTemp4));
			double fTemp30 = ((((fRec45[2] + (fRec45[0] + (2.0 * fRec45[1]))) * fTemp1) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fRec45[1] * fTemp6) + ((fRec45[0] + fRec45[2]) / fTemp4))))));
			fRec46[0] = (double(input24[i]) - (((fRec46[2] * fTemp2) + (2.0 * (fRec46[1] * fTemp3))) / fTemp4));
			double fTemp31 = ((((fRec46[2] + (fRec46[0] + (2.0 * fRec46[1]))) * fTemp1) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fRec46[1] * fTemp6) + ((fRec46[0] + fRec46[2]) / fTemp4))))));
			fRec47[0] = (double(input17[i]) - (((fRec47[2] * fTemp2) + (2.0 * (fRec47[1] * fTemp3))) / fTemp4));
			double fTemp32 = ((((fRec47[2] + (fRec47[0] + (2.0 * fRec47[1]))) * fTemp1) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fRec47[1] * fTemp6) + ((fRec47[0] + fRec47[2]) / fTemp4))))));
			fRec48[0] = (double(input18[i]) - (((fRec48[2] * fTemp2) + (2.0 * (fRec48[1] * fTemp3))) / fTemp4));
			double fTemp33 = ((((fRec48[2] + (fRec48[0] + (2.0 * fRec48[1]))) * fTemp1) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fRec48[1] * fTemp6) + ((fRec48[0] + fRec48[2]) / fTemp4))))));
			fRec49[0] = (double(input22[i]) - (((fRec49[2] * fTemp2) + (2.0 * (fRec49[1] * fTemp3))) / fTemp4));
			double fTemp34 = ((((fRec49[2] + (fRec49[0] + (2.0 * fRec49[1]))) * fTemp1) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fRec49[1] * fTemp6) + ((fRec49[0] + fRec49[2]) / fTemp4))))));
			fRec50[0] = (double(input23[i]) - (((fRec50[2] * fTemp2) + (2.0 * (fRec50[1] * fTemp3))) / fTemp4));
			double fTemp35 = ((((fRec50[2] + (fRec50[0] + (2.0 * fRec50[1]))) * fTemp1) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fRec50[1] * fTemp6) + ((fRec50[0] + fRec50[2]) / fTemp4))))));
			double fTemp36 = (fConst17 * ((((((0.1268719639 * fTemp27) + (0.0201106008 * fTemp28)) + (0.048525109199999999 * fTemp29)) + (0.025039416599999999 * fTemp30)) + (0.0497517055 * fTemp31)) - ((((0.1042255995 * fTemp32) + (0.0144254356 * fTemp33)) + (0.043392140000000003 * fTemp34)) + (0.046083312699999997 * fTemp35))));
			double fTemp37 = (fConst18 * fRec36[1]);
			double fTemp38 = (fConst19 * fRec39[1]);
			fRec41[0] = (fTemp36 + (fTemp37 + (fRec41[1] + fTemp38)));
			fRec39[0] = fRec41[0];
			double fRec40 = ((fTemp38 + fTemp37) + fTemp36);
			fRec38[0] = (fRec39[0] + fRec38[1]);
			fRec36[0] = fRec38[0];
			double fRec37 = fRec40;
			fRec35[0] = (fTemp25 + (fTemp26 + (fRec37 + fRec35[1])));
			fRec33[0] = fRec35[0];
			double fRec34 = (fTemp25 + (fRec37 + fTemp26));
			fRec32[0] = (fRec33[0] + fRec32[1]);
			fRec30[0] = fRec32[0];
			double fRec31 = fRec34;
			double fTemp39 = (fConst21 * fRec51[1]);
			fRec60[0] = (double(input9[i]) - (((fRec60[2] * fTemp2) + (2.0 * (fRec60[1] * fTemp3))) / fTemp4));
			double fTemp40 = ((((fRec60[2] + (fRec60[0] + (2.0 * fRec60[1]))) * fTemp1) / fTemp5) + (0.62824992459999995 * (fRec3[0] * (0.0 - ((fRec60[1] * fTemp6) + ((fRec60[0] + fRec60[2]) / fTemp4))))));
			fRec61[0] = (double(input12[i]) - (((fRec61[2] * fTemp2) + (2.0 * (fRec61[1] * fTemp3))) / fTemp4));
			double fTemp41 = ((((fRec61[2] + (fRec61[0] + (2.0 * fRec61[1]))) * fTemp1) / fTemp5) + (0.62824992459999995 * (fRec3[0] * (0.0 - ((fRec61[1] * fTemp6) + ((fRec61[0] + fRec61[2]) / fTemp4))))));
			fRec62[0] = (double(input15[i]) - (((fRec62[2] * fTemp2) + (2.0 * (fRec62[1] * fTemp3))) / fTemp4));
			double fTemp42 = ((((fRec62[2] + (fRec62[0] + (2.0 * fRec62[1]))) * fTemp1) / fTemp5) + (0.62824992459999995 * (fRec3[0] * (0.0 - ((fRec62[1] * fTemp6) + ((fRec62[0] + fRec62[2]) / fTemp4))))));
			fRec63[0] = (double(input10[i]) - (((fRec63[2] * fTemp2) + (2.0 * (fRec63[1] * fTemp3))) / fTemp4));
			double fTemp43 = ((((fRec63[2] + (fRec63[0] + (2.0 * fRec63[1]))) * fTemp1) / fTemp5) + (0.62824992459999995 * (fRec3[0] * (0.0 - ((fRec63[1] * fTemp6) + ((fRec63[0] + fRec63[2]) / fTemp4))))));
			fRec64[0] = (double(input11[i]) - (((fRec64[2] * fTemp2) + (2.0 * (fRec64[1] * fTemp3))) / fTemp4));
			double fTemp44 = ((((fRec64[2] + (fRec64[0] + (2.0 * fRec64[1]))) * fTemp1) / fTemp5) + (0.62824992459999995 * (fRec3[0] * (0.0 - ((fRec64[1] * fTemp6) + ((fRec64[0] + fRec64[2]) / fTemp4))))));
			fRec65[0] = (double(input13[i]) - (((fRec65[2] * fTemp2) + (2.0 * (fRec65[1] * fTemp3))) / fTemp4));
			double fTemp45 = ((((fRec65[2] + (fRec65[0] + (2.0 * fRec65[1]))) * fTemp1) / fTemp5) + (0.62824992459999995 * (fRec3[0] * (0.0 - ((fRec65[1] * fTemp6) + ((fRec65[0] + fRec65[2]) / fTemp4))))));
			fRec66[0] = (double(input14[i]) - (((fRec66[2] * fTemp2) + (2.0 * (fRec66[1] * fTemp3))) / fTemp4));
			double fTemp46 = ((((fRec66[2] + (fRec66[0] + (2.0 * fRec66[1]))) * fTemp1) / fTemp5) + (0.62824992459999995 * (fRec3[0] * (0.0 - ((fRec66[1] * fTemp6) + ((fRec66[0] + fRec66[2]) / fTemp4))))));
			double fTemp47 = (fConst23 * ((((0.14649792880000001 * fTemp40) + (0.052929262599999999 * fTemp41)) + (0.126121281 * fTemp42)) - ((((0.086206815300000003 * fTemp43) + (0.017405833999999999 * fTemp44)) + (0.080487953500000001 * fTemp45)) + (0.091209163100000004 * fTemp46))));
			double fTemp48 = (fConst24 * fRec54[1]);
			double fTemp49 = (fConst25 * fRec57[1]);
			fRec59[0] = (fTemp47 + (fTemp48 + (fRec59[1] + fTemp49)));
			fRec57[0] = fRec59[0];
			double fRec58 = ((fTemp49 + fTemp48) + fTemp47);
			fRec56[0] = (fRec57[0] + fRec56[1]);
			fRec54[0] = fRec56[0];
			double fRec55 = fRec58;
			fRec53[0] = (fTemp39 + (fRec55 + fRec53[1]));
			fRec51[0] = fRec53[0];
			double fRec52 = (fRec55 + fTemp39);
			fRec70[0] = (double(input1[i]) - (((fTemp2 * fRec70[2]) + (2.0 * (fTemp3 * fRec70[1]))) / fTemp4));
			double fTemp50 = (((fTemp1 * (fRec70[2] + (fRec70[0] + (2.0 * fRec70[1])))) / fTemp5) + (0.93246951420000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec70[1]) + ((fRec70[0] + fRec70[2]) / fTemp4))))));
			fRec71[0] = (double(input3[i]) - (((fTemp2 * fRec71[2]) + (2.0 * (fTemp3 * fRec71[1]))) / fTemp4));
			double fTemp51 = (((fTemp1 * (fRec71[2] + (fRec71[0] + (2.0 * fRec71[1])))) / fTemp5) + (0.93246951420000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec71[1]) + ((fRec71[0] + fRec71[2]) / fTemp4))))));
			fRec72[0] = (double(input2[i]) - (((fTemp2 * fRec72[2]) + (2.0 * (fTemp3 * fRec72[1]))) / fTemp4));
			double fTemp52 = (((fTemp1 * (fRec72[2] + (fRec72[0] + (2.0 * fRec72[1])))) / fTemp5) + (0.93246951420000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec72[1]) + ((fRec72[0] + fRec72[2]) / fTemp4))))));
			double fTemp53 = (fConst27 * (((0.054423825699999998 * fTemp50) + (0.1889789999 * fTemp51)) - (0.058680118099999998 * fTemp52)));
			double fTemp54 = (fConst28 * fRec67[1]);
			fRec69[0] = (fTemp53 + (fRec69[1] + fTemp54));
			fRec67[0] = fRec69[0];
			double fRec68 = (fTemp54 + fTemp53);
			fRec79[0] = (double(input4[i]) - (((fRec79[2] * fTemp2) + (2.0 * (fRec79[1] * fTemp3))) / fTemp4));
			double fTemp55 = ((((fRec79[2] + (fRec79[0] + (2.0 * fRec79[1]))) * fTemp1) / fTemp5) + (0.80424909239999998 * (fRec3[0] * (0.0 - ((fRec79[1] * fTemp6) + ((fRec79[2] + fRec79[0]) / fTemp4))))));
			fRec80[0] = (double(input8[i]) - (((fRec80[2] * fTemp2) + (2.0 * (fRec80[1] * fTemp3))) / fTemp4));
			double fTemp56 = ((((fRec80[2] + (fRec80[0] + (2.0 * fRec80[1]))) * fTemp1) / fTemp5) + (0.80424909239999998 * (fRec3[0] * (0.0 - ((fRec80[1] * fTemp6) + ((fRec80[0] + fRec80[2]) / fTemp4))))));
			fRec81[0] = (double(input5[i]) - (((fRec81[2] * fTemp2) + (2.0 * (fRec81[1] * fTemp3))) / fTemp4));
			double fTemp57 = ((((fRec81[2] + (fRec81[0] + (2.0 * fRec81[1]))) * fTemp1) / fTemp5) + (0.80424909239999998 * (fRec3[0] * (0.0 - ((fRec81[1] * fTemp6) + ((fRec81[0] + fRec81[2]) / fTemp4))))));
			fRec82[0] = (double(input6[i]) - (((fRec82[2] * fTemp2) + (2.0 * (fRec82[1] * fTemp3))) / fTemp4));
			double fTemp58 = ((((fRec82[2] + (fRec82[0] + (2.0 * fRec82[1]))) * fTemp1) / fTemp5) + (0.80424909239999998 * (fRec3[0] * (0.0 - ((fRec82[1] * fTemp6) + ((fRec82[0] + fRec82[2]) / fTemp4))))));
			fRec83[0] = (double(input7[i]) - (((fRec83[2] * fTemp2) + (2.0 * (fRec83[1] * fTemp3))) / fTemp4));
			double fTemp59 = ((((fRec83[2] + (fRec83[0] + (2.0 * fRec83[1]))) * fTemp1) / fTemp5) + (0.80424909239999998 * (fRec3[0] * (0.0 - ((fRec83[1] * fTemp6) + ((fRec83[0] + fRec83[2]) / fTemp4))))));
			double fTemp60 = (fConst30 * (((0.11719796170000001 * fTemp55) + (0.1857775602 * fTemp56)) - (((0.042370694399999999 * fTemp57) + (0.0894925939 * fTemp58)) + (0.1095150193 * fTemp59))));
			double fTemp61 = (fConst31 * fRec76[1]);
			double fTemp62 = (fConst32 * fRec73[1]);
			fRec78[0] = (((fTemp60 + fRec78[1]) + fTemp61) + fTemp62);
			fRec76[0] = fRec78[0];
			double fRec77 = ((fTemp60 + fTemp61) + fTemp62);
			fRec75[0] = (fRec76[0] + fRec75[1]);
			fRec73[0] = fRec75[0];
			double fRec74 = fRec77;
			fVec0[(IOTA & 127)] = ((0.077602882900000003 * fTemp7) + (fRec5 + (fRec31 + (fRec52 + (fRec68 + fRec74)))));
			output0[i] = FAUSTFLOAT((0.96563981042654023 * (fRec0[0] * fVec0[((IOTA - iConst33) & 127)])));
			double fTemp63 = (fConst35 * fRec84[1]);
			double fTemp64 = (fConst37 * fRec87[1]);
			double fTemp65 = (fConst38 * fRec90[1]);
			double fTemp66 = (fConst40 * (((0.0080355609000000005 * fTemp19) + ((0.0299518584 * fTemp18) + (((0.091774503800000004 * fTemp16) + (0.0055589994000000004 * fTemp17)) + (0.038821720699999999 * fTemp15)))) - ((0.042155369200000001 * fTemp21) + (((((0.076424182500000007 * fTemp11) + (0.017751779700000001 * fTemp12)) + (0.017630479300000002 * fTemp13)) + (0.033223966000000001 * fTemp14)) + (0.019041295600000001 * fTemp20)))));
			double fTemp67 = (fConst41 * fRec93[1]);
			double fTemp68 = (fConst42 * fRec96[1]);
			fRec98[0] = (fTemp66 + (fTemp67 + (fRec98[1] + fTemp68)));
			fRec96[0] = fRec98[0];
			double fRec97 = ((fTemp68 + fTemp67) + fTemp66);
			fRec95[0] = (fRec96[0] + fRec95[1]);
			fRec93[0] = fRec95[0];
			double fRec94 = fRec97;
			fRec92[0] = (fTemp64 + (fTemp65 + (fRec94 + fRec92[1])));
			fRec90[0] = fRec92[0];
			double fRec91 = (fTemp64 + (fRec94 + fTemp65));
			fRec89[0] = (fRec90[0] + fRec89[1]);
			fRec87[0] = fRec89[0];
			double fRec88 = fRec91;
			fRec86[0] = (fTemp63 + (fRec88 + fRec86[1]));
			fRec84[0] = fRec86[0];
			double fRec85 = (fRec88 + fTemp63);
			double fTemp69 = (fConst44 * (((0.044094448199999997 * fTemp57) + (0.13603642960000001 * fTemp56)) - (((0.12239017520000001 * fTemp55) + (0.061705826800000002 * fTemp58)) + (0.1261106786 * fTemp59))));
			double fTemp70 = (fConst45 * fRec99[1]);
			double fTemp71 = (fConst46 * fRec102[1]);
			fRec104[0] = (fTemp69 + (fTemp70 + (fRec104[1] + fTemp71)));
			fRec102[0] = fRec104[0];
			double fRec103 = ((fTemp71 + fTemp70) + fTemp69);
			fRec101[0] = (fRec102[0] + fRec101[1]);
			fRec99[0] = fRec101[0];
			double fRec100 = fRec103;
			double fTemp72 = (fConst48 * ((0.15029179710000001 * fTemp51) - ((0.0568013531 * fTemp50) + (0.064740366399999999 * fTemp52))));
			double fTemp73 = (fConst49 * fRec105[1]);
			fRec107[0] = (fTemp72 + (fRec107[1] + fTemp73));
			fRec105[0] = fRec107[0];
			double fRec106 = (fTemp73 + fTemp72);
			double fTemp74 = (fConst51 * fRec108[1]);
			double fTemp75 = (fConst53 * (((((0.089646107899999994 * fTemp43) + (0.018565694800000001 * fTemp44)) + (0.074730813899999998 * fTemp41)) + (0.0735165859 * fTemp42)) - (((0.15319497560000001 * fTemp40) + (0.041231478600000003 * fTemp45)) + (0.1124954799 * fTemp46))));
			double fTemp76 = (fConst54 * fRec111[1]);
			double fTemp77 = (fConst55 * fRec114[1]);
			fRec116[0] = (fTemp75 + (fTemp76 + (fRec116[1] + fTemp77)));
			fRec114[0] = fRec116[0];
			double fRec115 = ((fTemp77 + fTemp76) + fTemp75);
			fRec113[0] = (fRec114[0] + fRec113[1]);
			fRec111[0] = fRec113[0];
			double fRec112 = fRec115;
			fRec110[0] = (fTemp74 + (fRec112 + fRec110[1]));
			fRec108[0] = fRec110[0];
			double fRec109 = (fRec112 + fTemp74);
			double fTemp78 = (fConst57 * fRec117[1]);
			double fTemp79 = (fConst58 * fRec120[1]);
			double fTemp80 = (fConst60 * ((((0.0654437613 * fTemp30) + (((0.108203073 * fTemp32) + (0.016187814299999999 * fTemp33)) + (0.0243013277 * fTemp29))) + (0.0023081058999999998 * fTemp31)) - ((0.067421390499999997 * fTemp35) + (((0.13325810060000001 * fTemp27) + (0.021000502800000001 * fTemp28)) + (0.0082908559999999992 * fTemp34)))));
			double fTemp81 = (fConst61 * fRec123[1]);
			double fTemp82 = (fConst62 * fRec126[1]);
			fRec128[0] = (fTemp80 + (fTemp81 + (fRec128[1] + fTemp82)));
			fRec126[0] = fRec128[0];
			double fRec127 = ((fTemp82 + fTemp81) + fTemp80);
			fRec125[0] = (fRec126[0] + fRec125[1]);
			fRec123[0] = fRec125[0];
			double fRec124 = fRec127;
			fRec122[0] = (fTemp78 + (fTemp79 + (fRec124 + fRec122[1])));
			fRec120[0] = fRec122[0];
			double fRec121 = (fTemp78 + (fRec124 + fTemp79));
			fRec119[0] = (fRec120[0] + fRec119[1]);
			fRec117[0] = fRec119[0];
			double fRec118 = fRec121;
			fVec1[(IOTA & 63)] = ((0.063906873599999997 * fTemp7) + (fRec85 + (fRec100 + (fRec106 + (fRec109 + fRec118)))));
			output1[i] = FAUSTFLOAT((0.97748815165876779 * (fRec0[0] * fVec1[((IOTA - iConst63) & 63)])));
			double fTemp83 = (fConst65 * fRec129[1]);
			double fTemp84 = (fConst67 * fRec132[1]);
			double fTemp85 = (fConst68 * fRec135[1]);
			double fTemp86 = (fConst70 * (((0.056779297300000003 * fTemp21) + ((0.022546072300000001 * fTemp20) + ((((0.078388411500000005 * fTemp11) + (0.0068986906000000001 * fTemp17)) + (0.019866383200000001 * fTemp15)) + (0.0023246925999999999 * fTemp19)))) - (((((0.094373202000000003 * fTemp16) + (0.024550059900000001 * fTemp12)) + (0.034953066999999997 * fTemp13)) + (0.032519356999999999 * fTemp14)) + (0.024024803399999999 * fTemp18))));
			double fTemp87 = (fConst71 * fRec138[1]);
			double fTemp88 = (fConst72 * fRec141[1]);
			fRec143[0] = (fTemp86 + (fTemp87 + (fRec143[1] + fTemp88)));
			fRec141[0] = fRec143[0];
			double fRec142 = ((fTemp88 + fTemp87) + fTemp86);
			fRec140[0] = (fRec141[0] + fRec140[1]);
			fRec138[0] = fRec140[0];
			double fRec139 = fRec142;
			fRec137[0] = (fTemp84 + (fTemp85 + (fRec139 + fRec137[1])));
			fRec135[0] = fRec137[0];
			double fRec136 = (fTemp84 + (fRec139 + fTemp85));
			fRec134[0] = (fRec135[0] + fRec134[1]);
			fRec132[0] = fRec134[0];
			double fRec133 = fRec136;
			fRec131[0] = (fTemp83 + (fRec133 + fRec131[1]));
			fRec129[0] = fRec131[0];
			double fRec130 = (fRec133 + fTemp83);
			double fTemp89 = (fConst74 * fRec144[1]);
			double fTemp90 = (fConst75 * fRec147[1]);
			double fTemp91 = (fConst77 * (((0.123789315 * fTemp35) + ((0.0057537808000000003 * fTemp34) + ((0.0277217269 * fTemp30) + (((0.1289556926 * fTemp27) + (0.0158544501 * fTemp33)) + (0.022828068399999998 * fTemp29))))) - (((0.028193329499999999 * fTemp32) + (0.060595397799999999 * fTemp28)) + (0.050251470899999998 * fTemp31))));
			double fTemp92 = (fConst78 * fRec150[1]);
			double fTemp93 = (fConst79 * fRec153[1]);
			fRec155[0] = (fTemp91 + (fTemp92 + (fRec155[1] + fTemp93)));
			fRec153[0] = fRec155[0];
			double fRec154 = ((fTemp93 + fTemp92) + fTemp91);
			fRec152[0] = (fRec153[0] + fRec152[1]);
			fRec150[0] = fRec152[0];
			double fRec151 = fRec154;
			fRec149[0] = (fTemp89 + (fTemp90 + (fRec151 + fRec149[1])));
			fRec147[0] = fRec149[0];
			double fRec148 = (fTemp89 + (fRec151 + fTemp90));
			fRec146[0] = (fRec147[0] + fRec146[1]);
			fRec144[0] = fRec146[0];
			double fRec145 = fRec148;
			double fTemp94 = (fConst81 * fRec156[1]);
			double fTemp95 = (fConst83 * ((((((0.0240859278 * fTemp40) + (0.1092067602 * fTemp43)) + (0.037356989799999997 * fTemp44)) + (0.071656250599999999 * fTemp41)) + (0.087380332000000005 * fTemp46)) - ((0.021033587999999999 * fTemp45) + (0.1672812393 * fTemp42))));
			double fTemp96 = (fConst84 * fRec159[1]);
			double fTemp97 = (fConst85 * fRec162[1]);
			fRec164[0] = (fTemp95 + (fTemp96 + (fRec164[1] + fTemp97)));
			fRec162[0] = fRec164[0];
			double fRec163 = ((fTemp97 + fTemp96) + fTemp95);
			fRec161[0] = (fRec162[0] + fRec161[1]);
			fRec159[0] = fRec161[0];
			double fRec160 = fRec163;
			fRec158[0] = (fTemp94 + (fRec160 + fRec158[1]));
			fRec156[0] = fRec158[0];
			double fRec157 = (fRec160 + fTemp94);
			double fTemp98 = (fConst87 * ((0.068978500200000001 * fTemp51) - ((0.137005127 * fTemp50) + (0.061796046299999997 * fTemp52))));
			double fTemp99 = (fConst88 * fRec165[1]);
			fRec167[0] = (fTemp98 + (fRec167[1] + fTemp99));
			fRec165[0] = fRec167[0];
			double fRec166 = (fTemp99 + fTemp98);
			double fTemp100 = (fConst90 * ((0.1154948672 * fTemp57) - ((((0.1431430266 * fTemp55) + (0.058504607600000001 * fTemp58)) + (0.055501522900000003 * fTemp59)) + (0.1045101599 * fTemp56))));
			double fTemp101 = (fConst91 * fRec168[1]);
			double fTemp102 = (fConst92 * fRec171[1]);
			fRec173[0] = (fTemp100 + (fTemp101 + (fRec173[1] + fTemp102)));
			fRec171[0] = fRec173[0];
			double fRec172 = ((fTemp102 + fTemp101) + fTemp100);
			fRec170[0] = (fRec171[0] + fRec170[1]);
			fRec168[0] = fRec170[0];
			double fRec169 = fRec172;
			fVec2[0] = ((0.060745746900000001 * fTemp7) + (fRec130 + (fRec145 + (fRec157 + (fRec166 + fRec169)))));
			output2[i] = FAUSTFLOAT((0.99229857819905221 * (fRec0[0] * fVec2[iConst93])));
			double fTemp103 = (fConst97 * (((((0.055185392700000002 * fTemp16) + (0.0052786574000000001 * fTemp12)) + (0.0088562095 * fTemp14)) + (0.010664019 * fTemp18)) - ((0.073279692100000002 * fTemp21) + ((0.070279184999999994 * fTemp20) + (((((0.080378668400000006 * fTemp11) + (0.019506394999999999 * fTemp17)) + (0.061513565399999998 * fTemp13)) + (0.0064170705000000001 * fTemp15)) + (0.0025326260000000001 * fTemp19))))));
			double fTemp104 = (fConst98 * fRec186[1]);
			double fTemp105 = (fConst99 * fRec183[1]);
			fRec188[0] = (((fTemp103 + fRec188[1]) + fTemp104) + fTemp105);
			fRec186[0] = fRec188[0];
			double fRec187 = ((fTemp103 + fTemp104) + fTemp105);
			fRec185[0] = (fRec186[0] + fRec185[1]);
			fRec183[0] = fRec185[0];
			double fRec184 = fRec187;
			double fTemp106 = (fConst100 * fRec180[1]);
			double fTemp107 = (fConst101 * fRec177[1]);
			fRec182[0] = (((fRec184 + fRec182[1]) + fTemp106) + fTemp107);
			fRec180[0] = fRec182[0];
			double fRec181 = ((fRec184 + fTemp106) + fTemp107);
			fRec179[0] = (fRec180[0] + fRec179[1]);
			fRec177[0] = fRec179[0];
			double fRec178 = fRec181;
			double fTemp108 = (fConst102 * fRec174[1]);
			fRec176[0] = ((fRec178 + fRec176[1]) + fTemp108);
			fRec174[0] = fRec176[0];
			double fRec175 = (fRec178 + fTemp108);
			double fTemp109 = (fConst104 * fRec189[1]);
			double fTemp110 = (fConst105 * fRec192[1]);
			double fTemp111 = (fConst107 * ((((0.044592959199999997 * fTemp29) + (0.044711451200000002 * fTemp34)) + (0.1374703954 * fTemp31)) - ((((((0.078764791400000006 * fTemp27) + (0.089724770800000006 * fTemp32)) + (0.0068631817000000001 * fTemp33)) + (0.017885314699999998 * fTemp28)) + (0.0062718790000000002 * fTemp30)) + (0.047419263699999999 * fTemp35))));
			double fTemp112 = (fConst108 * fRec195[1]);
			double fTemp113 = (fConst109 * fRec198[1]);
			fRec200[0] = (fTemp111 + (fTemp112 + (fRec200[1] + fTemp113)));
			fRec198[0] = fRec200[0];
			double fRec199 = ((fTemp113 + fTemp112) + fTemp111);
			fRec197[0] = (fRec198[0] + fRec197[1]);
			fRec195[0] = fRec197[0];
			double fRec196 = fRec199;
			fRec194[0] = (fTemp109 + (fTemp110 + (fRec196 + fRec194[1])));
			fRec192[0] = fRec194[0];
			double fRec193 = (fTemp109 + (fRec196 + fTemp110));
			fRec191[0] = (fRec192[0] + fRec191[1]);
			fRec189[0] = fRec191[0];
			double fRec190 = fRec193;
			double fTemp114 = (fConst111 * fRec201[1]);
			double fTemp115 = (fConst113 * (((0.068722808299999993 * fTemp42) + ((0.099718374799999995 * fTemp46) + ((((0.18093873059999999 * fTemp40) + (0.075647088900000006 * fTemp44)) + (0.040251609200000003 * fTemp41)) + (0.0068891880000000001 * fTemp45)))) - (0.032397425700000003 * fTemp43)));
			double fTemp116 = (fConst114 * fRec204[1]);
			double fTemp117 = (fConst115 * fRec207[1]);
			fRec209[0] = (fTemp115 + (fTemp116 + (fRec209[1] + fTemp117)));
			fRec207[0] = fRec209[0];
			double fRec208 = ((fTemp117 + fTemp116) + fTemp115);
			fRec206[0] = (fRec207[0] + fRec206[1]);
			fRec204[0] = fRec206[0];
			double fRec205 = fRec208;
			fRec203[0] = (fTemp114 + (fRec205 + fRec203[1]));
			fRec201[0] = fRec203[0];
			double fRec202 = (fRec205 + fTemp114);
			double fTemp118 = (fConst117 * (0.0 - (((0.1701255931 * fTemp50) + (0.0473590334 * fTemp52)) + (0.019553854799999999 * fTemp51))));
			double fTemp119 = (fConst118 * fRec210[1]);
			fRec212[0] = (fTemp118 + (fRec212[1] + fTemp119));
			fRec210[0] = fRec212[0];
			double fRec211 = (fTemp119 + fTemp118);
			double fTemp120 = (fConst120 * ((((0.046348462600000001 * fTemp55) + (0.094128958900000004 * fTemp57)) + (0.014375343 * fTemp59)) - ((0.078820296999999998 * fTemp58) + (0.19567594029999999 * fTemp56))));
			double fTemp121 = (fConst121 * fRec213[1]);
			double fTemp122 = (fConst122 * fRec216[1]);
			fRec218[0] = (fTemp120 + (fTemp121 + (fRec218[1] + fTemp122)));
			fRec216[0] = fRec218[0];
			double fRec217 = ((fTemp122 + fTemp121) + fTemp120);
			fRec215[0] = (fRec216[0] + fRec215[1]);
			fRec213[0] = fRec215[0];
			double fRec214 = fRec217;
			fVec3[(IOTA & 63)] = ((fRec175 + (fRec190 + (fRec202 + (fRec211 + fRec214)))) + (0.066334443100000001 * fTemp7));
			output3[i] = FAUSTFLOAT((0.96860189573459721 * (fRec0[0] * fVec3[((IOTA - iConst123) & 63)])));
			double fTemp123 = (fConst125 * fRec219[1]);
			double fTemp124 = (fConst127 * fRec222[1]);
			double fTemp125 = (fConst128 * fRec225[1]);
			double fTemp126 = (fConst130 * (((0.042673284899999997 * fTemp21) + ((0.0588579615 * fTemp20) + (((((0.061253788500000003 * fTemp11) + (0.0016627395000000001 * fTemp16)) + (0.0032562060999999998 * fTemp17)) + (0.016477930599999999 * fTemp12)) + (0.0122992148 * fTemp19)))) - ((0.029997316 * fTemp18) + ((0.081241189800000002 * fTemp15) + ((0.024967545300000001 * fTemp13) + (0.0024168865000000002 * fTemp14))))));
			double fTemp127 = (fConst131 * fRec228[1]);
			double fTemp128 = (fConst132 * fRec231[1]);
			fRec233[0] = (fTemp126 + (fTemp127 + (fRec233[1] + fTemp128)));
			fRec231[0] = fRec233[0];
			double fRec232 = ((fTemp128 + fTemp127) + fTemp126);
			fRec230[0] = (fRec231[0] + fRec230[1]);
			fRec228[0] = fRec230[0];
			double fRec229 = fRec232;
			fRec227[0] = (fTemp124 + (fTemp125 + (fRec229 + fRec227[1])));
			fRec225[0] = fRec227[0];
			double fRec226 = (fTemp124 + (fRec229 + fTemp125));
			fRec224[0] = (fRec225[0] + fRec224[1]);
			fRec222[0] = fRec224[0];
			double fRec223 = fRec226;
			fRec221[0] = (fTemp123 + (fRec223 + fRec221[1]));
			fRec219[0] = fRec221[0];
			double fRec220 = (fRec223 + fTemp123);
			double fTemp129 = (fConst134 * fRec234[1]);
			double fTemp130 = (fConst135 * fRec237[1]);
			double fTemp131 = (fConst137 * ((((0.021692717199999999 * fTemp27) + (0.080021927300000004 * fTemp32)) + (0.057866918900000001 * fTemp29)) - ((0.044902878299999997 * fTemp31) + ((0.0142117874 * fTemp35) + ((0.033516885500000003 * fTemp34) + (((0.015285743900000001 * fTemp33) + (0.031933873600000003 * fTemp28)) + (0.035626379999999999 * fTemp30)))))));
			double fTemp132 = (fConst138 * fRec240[1]);
			double fTemp133 = (fConst139 * fRec243[1]);
			fRec245[0] = (fTemp131 + (fTemp132 + (fRec245[1] + fTemp133)));
			fRec243[0] = fRec245[0];
			double fRec244 = ((fTemp133 + fTemp132) + fTemp131);
			fRec242[0] = (fRec243[0] + fRec242[1]);
			fRec240[0] = fRec242[0];
			double fRec241 = fRec244;
			fRec239[0] = (fTemp129 + (fTemp130 + (fRec241 + fRec239[1])));
			fRec237[0] = fRec239[0];
			double fRec238 = (fTemp129 + (fRec241 + fTemp130));
			fRec236[0] = (fRec237[0] + fRec236[1]);
			fRec234[0] = fRec236[0];
			double fRec235 = fRec238;
			double fTemp134 = (fConst141 * fRec246[1]);
			double fTemp135 = (fConst143 * ((((0.025110278699999999 * fTemp44) + (0.087931494900000004 * fTemp41)) + (0.087989912000000003 * fTemp45)) - ((0.045469950199999998 * fTemp42) + (((0.1250849174 * fTemp40) + (0.1156332819 * fTemp43)) + (0.089101956699999998 * fTemp46)))));
			double fTemp136 = (fConst144 * fRec249[1]);
			double fTemp137 = (fConst145 * fRec252[1]);
			fRec254[0] = (fTemp135 + (fTemp136 + (fRec254[1] + fTemp137)));
			fRec252[0] = fRec254[0];
			double fRec253 = ((fTemp137 + fTemp136) + fTemp135);
			fRec251[0] = (fRec252[0] + fRec251[1]);
			fRec249[0] = fRec251[0];
			double fRec250 = fRec253;
			fRec248[0] = (fTemp134 + (fRec250 + fRec248[1]));
			fRec246[0] = fRec248[0];
			double fRec247 = (fRec250 + fTemp134);
			double fTemp138 = (fConst147 * (0.0 - (((0.0897001506 * fTemp50) + (0.098515358299999994 * fTemp52)) + (0.25711536950000002 * fTemp51))));
			double fTemp139 = (fConst148 * fRec255[1]);
			fRec257[0] = (fTemp138 + (fRec257[1] + fTemp139));
			fRec255[0] = fRec257[0];
			double fRec256 = (fTemp139 + fTemp138);
			double fTemp140 = (fConst150 * (((((0.15740925159999999 * fTemp55) + (0.071790105399999998 * fTemp57)) + (0.16582771599999999 * fTemp59)) + (0.1851540236 * fTemp56)) - (0.11933776929999999 * fTemp58)));
			double fTemp141 = (fConst151 * fRec258[1]);
			double fTemp142 = (fConst152 * fRec261[1]);
			fRec263[0] = (fTemp140 + (fTemp141 + (fRec263[1] + fTemp142)));
			fRec261[0] = fRec263[0];
			double fRec262 = ((fTemp142 + fTemp141) + fTemp140);
			fRec260[0] = (fRec261[0] + fRec260[1]);
			fRec258[0] = fRec260[0];
			double fRec259 = fRec262;
			fVec4[0] = ((0.1160592082 * fTemp7) + (fRec220 + (fRec235 + (fRec247 + (fRec256 + fRec259)))));
			output4[i] = FAUSTFLOAT((0.99644549763033174 * (fRec0[0] * fVec4[iConst153])));
			double fTemp143 = (fConst155 * fRec264[1]);
			double fTemp144 = (fConst157 * fRec267[1]);
			double fTemp145 = (fConst158 * fRec270[1]);
			double fTemp146 = (fConst160 * (((0.047962184499999998 * fTemp21) + (((0.0271447909 * fTemp13) + (0.014758450399999999 * fTemp18)) + (0.041430444199999999 * fTemp20))) - (((0.058356045199999998 * fTemp15) + (((((0.057836635099999999 * fTemp11) + (0.0023113160999999999 * fTemp16)) + (0.0077126347999999997 * fTemp17)) + (0.015678597700000001 * fTemp12)) + (0.0432676569 * fTemp14))) + (0.0053702265000000002 * fTemp19))));
			double fTemp147 = (fConst161 * fRec273[1]);
			double fTemp148 = (fConst162 * fRec276[1]);
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
			double fTemp149 = (fConst164 * fRec279[1]);
			double fTemp150 = (fConst165 * fRec282[1]);
			double fTemp151 = (fConst167 * (((((0.018552197900000001 * fTemp33) + (0.031639782499999998 * fTemp28)) + (0.0345294399 * fTemp29)) + (0.0109543087 * fTemp35)) - (((0.0038074559999999999 * fTemp34) + (((0.025823548299999999 * fTemp27) + (0.079582109299999995 * fTemp32)) + (0.080901585499999998 * fTemp30))) + (0.064916298999999997 * fTemp31))));
			double fTemp152 = (fConst168 * fRec285[1]);
			double fTemp153 = (fConst169 * fRec288[1]);
			fRec290[0] = (fTemp151 + (fTemp152 + (fRec290[1] + fTemp153)));
			fRec288[0] = fRec290[0];
			double fRec289 = ((fTemp153 + fTemp152) + fTemp151);
			fRec287[0] = (fRec288[0] + fRec287[1]);
			fRec285[0] = fRec287[0];
			double fRec286 = fRec289;
			fRec284[0] = (fTemp149 + (fTemp150 + (fRec286 + fRec284[1])));
			fRec282[0] = fRec284[0];
			double fRec283 = (fTemp149 + (fRec286 + fTemp150));
			fRec281[0] = (fRec282[0] + fRec281[1]);
			fRec279[0] = fRec281[0];
			double fRec280 = fRec283;
			double fTemp154 = (fConst171 * fRec291[1]);
			double fTemp155 = (fConst173 * (((((0.1288453416 * fTemp40) + (0.1154320413 * fTemp43)) + (0.11373899580000001 * fTemp41)) + (0.050141783299999999 * fTemp45)) - ((0.011713232299999999 * fTemp42) + ((0.026655510699999999 * fTemp44) + (0.1159875168 * fTemp46)))));
			double fTemp156 = (fConst174 * fRec294[1]);
			double fTemp157 = (fConst175 * fRec297[1]);
			fRec299[0] = (fTemp155 + (fTemp156 + (fRec299[1] + fTemp157)));
			fRec297[0] = fRec299[0];
			double fRec298 = ((fTemp157 + fTemp156) + fTemp155);
			fRec296[0] = (fRec297[0] + fRec296[1]);
			fRec294[0] = fRec296[0];
			double fRec295 = fRec298;
			fRec293[0] = (fTemp154 + (fRec295 + fRec293[1]));
			fRec291[0] = fRec293[0];
			double fRec292 = (fRec295 + fTemp154);
			double fTemp158 = (fConst177 * ((0.090707389299999996 * fTemp50) - ((0.10680840010000001 * fTemp52) + (0.22142668779999999 * fTemp51))));
			double fTemp159 = (fConst178 * fRec300[1]);
			fRec302[0] = (fTemp158 + (fRec302[1] + fTemp159));
			fRec300[0] = fRec302[0];
			double fRec301 = (fTemp159 + fTemp158);
			double fTemp160 = (fConst180 * (((0.18751301819999999 * fTemp59) + (0.14474790009999999 * fTemp56)) - (((0.1599267093 * fTemp55) + (0.071747772700000004 * fTemp57)) + (0.0916836548 * fTemp58))));
			double fTemp161 = (fConst181 * fRec303[1]);
			double fTemp162 = (fConst182 * fRec306[1]);
			fRec308[0] = (fTemp160 + (fTemp161 + (fRec308[1] + fTemp162)));
			fRec306[0] = fRec308[0];
			double fRec307 = ((fTemp162 + fTemp161) + fTemp160);
			fRec305[0] = (fRec306[0] + fRec305[1]);
			fRec303[0] = fRec305[0];
			double fRec304 = fRec307;
			output5[i] = FAUSTFLOAT((fRec0[0] * ((0.1029711303 * fTemp7) + (fRec265 + (fRec280 + (fRec292 + (fRec301 + fRec304)))))));
			double fTemp163 = (fConst184 * fRec309[1]);
			double fTemp164 = (fConst186 * fRec312[1]);
			double fTemp165 = (fConst187 * fRec315[1]);
			double fTemp166 = (fConst189 * ((((0.0088832157000000005 * fTemp14) + (((0.080324536000000002 * fTemp11) + (0.0195276884 * fTemp17)) + (0.061528725499999999 * fTemp13))) + (0.0106525261 * fTemp18)) - ((0.073296437500000006 * fTemp21) + ((0.070327169999999994 * fTemp20) + ((((0.0551308311 * fTemp16) + (0.0051585262999999998 * fTemp12)) + (0.0064259868999999997 * fTemp15)) + (0.0025546904999999998 * fTemp19))))));
			double fTemp167 = (fConst190 * fRec318[1]);
			double fTemp168 = (fConst191 * fRec321[1]);
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
			double fTemp169 = (fConst193 * fRec324[1]);
			double fTemp170 = (fConst194 * fRec327[1]);
			double fTemp171 = (fConst196 * ((((((((0.078868528199999996 * fTemp27) + (0.089738116800000003 * fTemp32)) + (0.0068999819000000002 * fTemp33)) + (0.017884395000000001 * fTemp28)) + (0.044623408699999999 * fTemp29)) + (0.044751381700000002 * fTemp34)) + (0.1374320983 * fTemp31)) - ((0.0062210538000000001 * fTemp30) + (0.047357726400000001 * fTemp35))));
			double fTemp172 = (fConst197 * fRec330[1]);
			double fTemp173 = (fConst198 * fRec333[1]);
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
			double fTemp174 = (fConst200 * fRec336[1]);
			double fTemp175 = (fConst202 * (((0.0688619548 * fTemp42) + ((0.099706104000000004 * fTemp46) + (((0.032357517000000002 * fTemp43) + (0.040238775800000001 * fTemp41)) + (0.0069236523999999999 * fTemp45)))) - ((0.18092477300000001 * fTemp40) + (0.075698066600000002 * fTemp44))));
			double fTemp176 = (fConst203 * fRec339[1]);
			double fTemp177 = (fConst204 * fRec342[1]);
			fRec344[0] = (fTemp175 + (fTemp176 + (fRec344[1] + fTemp177)));
			fRec342[0] = fRec344[0];
			double fRec343 = ((fTemp177 + fTemp176) + fTemp175);
			fRec341[0] = (fRec342[0] + fRec341[1]);
			fRec339[0] = fRec341[0];
			double fRec340 = fRec343;
			fRec338[0] = (fTemp174 + (fRec340 + fRec338[1]));
			fRec336[0] = fRec338[0];
			double fRec337 = (fRec340 + fTemp174);
			double fTemp178 = (fConst206 * ((0.17013778360000001 * fTemp50) - ((0.047348098999999998 * fTemp52) + (0.019605341599999999 * fTemp51))));
			double fTemp179 = (fConst207 * fRec345[1]);
			fRec347[0] = (fTemp178 + (fRec347[1] + fTemp179));
			fRec345[0] = fRec347[0];
			double fRec346 = (fTemp179 + fTemp178);
			double fTemp180 = (fConst209 * ((0.014360447300000001 * fTemp59) - ((((0.046462565099999999 * fTemp55) + (0.094105577100000004 * fTemp57)) + (0.078846651599999998 * fTemp58)) + (0.19568197170000001 * fTemp56))));
			double fTemp181 = (fConst210 * fRec348[1]);
			double fTemp182 = (fConst211 * fRec351[1]);
			fRec353[0] = (fTemp180 + (fTemp181 + (fRec353[1] + fTemp182)));
			fRec351[0] = fRec353[0];
			double fRec352 = ((fTemp182 + fTemp181) + fTemp180);
			fRec350[0] = (fRec351[0] + fRec350[1]);
			fRec348[0] = fRec350[0];
			double fRec349 = fRec352;
			fVec5[(IOTA & 127)] = ((0.066339076900000002 * fTemp7) + (fRec310 + (fRec325 + (fRec337 + (fRec346 + fRec349)))));
			output6[i] = FAUSTFLOAT((0.96623222748815174 * (fRec0[0] * fVec5[((IOTA - iConst212) & 127)])));
			double fTemp183 = (fConst214 * fRec354[1]);
			double fTemp184 = (fConst216 * fRec357[1]);
			double fTemp185 = (fConst217 * fRec360[1]);
			double fTemp186 = (fConst219 * (((0.051021464400000001 * fTemp21) + ((0.025854454900000001 * fTemp20) + (((((0.091739611200000001 * fTemp16) + (0.025403881600000001 * fTemp12)) + (0.035503977399999997 * fTemp13)) + (0.0205616619 * fTemp15)) + (0.0023119929 * fTemp19)))) - ((((0.0782867852 * fTemp11) + (0.0067932315 * fTemp17)) + (0.033208484699999999 * fTemp14)) + (0.023629601199999999 * fTemp18))));
			double fTemp187 = (fConst220 * fRec363[1]);
			double fTemp188 = (fConst221 * fRec366[1]);
			fRec368[0] = (fTemp186 + (fTemp187 + (fRec368[1] + fTemp188)));
			fRec366[0] = fRec368[0];
			double fRec367 = ((fTemp188 + fTemp187) + fTemp186);
			fRec365[0] = (fRec366[0] + fRec365[1]);
			fRec363[0] = fRec365[0];
			double fRec364 = fRec367;
			fRec362[0] = (fTemp184 + (fTemp185 + (fRec364 + fRec362[1])));
			fRec360[0] = fRec362[0];
			double fRec361 = (fTemp184 + (fRec364 + fTemp185));
			fRec359[0] = (fRec360[0] + fRec359[1]);
			fRec357[0] = fRec359[0];
			double fRec358 = fRec361;
			fRec356[0] = (fTemp183 + (fRec358 + fRec356[1]));
			fRec354[0] = fRec356[0];
			double fRec355 = (fRec358 + fTemp183);
			double fTemp189 = (fConst223 * fRec369[1]);
			double fTemp190 = (fConst224 * fRec372[1]);
			double fTemp191 = (fConst226 * (((0.1249505309 * fTemp35) + ((0.0056518465 * fTemp34) + ((0.029010641 * fTemp30) + (((0.024312477700000001 * fTemp32) + (0.061462845199999998 * fTemp28)) + (0.0232632506 * fTemp29))))) - (((0.1256491914 * fTemp27) + (0.0161469165 * fTemp33)) + (0.054688413399999997 * fTemp31))));
			double fTemp192 = (fConst227 * fRec375[1]);
			double fTemp193 = (fConst228 * fRec378[1]);
			fRec380[0] = (fTemp191 + (fTemp192 + (fRec380[1] + fTemp193)));
			fRec378[0] = fRec380[0];
			double fRec379 = ((fTemp193 + fTemp192) + fTemp191);
			fRec377[0] = (fRec378[0] + fRec377[1]);
			fRec375[0] = fRec377[0];
			double fRec376 = fRec379;
			fRec374[0] = (fTemp189 + (fTemp190 + (fRec376 + fRec374[1])));
			fRec372[0] = fRec374[0];
			double fRec373 = (fTemp189 + (fRec376 + fTemp190));
			fRec371[0] = (fRec372[0] + fRec371[1]);
			fRec369[0] = fRec371[0];
			double fRec370 = fRec373;
			double fTemp194 = (fConst230 * fRec381[1]);
			double fTemp195 = (fConst232 * (((0.0732868468 * fTemp41) + (0.086214919299999998 * fTemp46)) - (((((0.0192019475 * fTemp40) + (0.1126769042 * fTemp43)) + (0.037870716399999997 * fTemp44)) + (0.021765649500000001 * fTemp45)) + (0.1688340958 * fTemp42))));
			double fTemp196 = (fConst233 * fRec384[1]);
			double fTemp197 = (fConst234 * fRec387[1]);
			fRec389[0] = (fTemp195 + (fTemp196 + (fRec389[1] + fTemp197)));
			fRec387[0] = fRec389[0];
			double fRec388 = ((fTemp197 + fTemp196) + fTemp195);
			fRec386[0] = (fRec387[0] + fRec386[1]);
			fRec384[0] = fRec386[0];
			double fRec385 = fRec388;
			fRec383[0] = (fTemp194 + (fRec385 + fRec383[1]));
			fRec381[0] = fRec383[0];
			double fRec382 = (fRec385 + fTemp194);
			double fTemp198 = (fConst236 * (((0.13906465509999999 * fTemp50) + (0.071811680500000002 * fTemp51)) - (0.063191711799999994 * fTemp52)));
			double fTemp199 = (fConst237 * fRec390[1]);
			fRec392[0] = (fTemp198 + (fRec392[1] + fTemp199));
			fRec390[0] = fRec392[0];
			double fRec391 = (fTemp199 + fTemp198);
			double fTemp200 = (fConst239 * ((0.1474027249 * fTemp55) - ((((0.1172591107 * fTemp57) + (0.059767500799999998 * fTemp58)) + (0.057936487699999997 * fTemp59)) + (0.10311647610000001 * fTemp56))));
			double fTemp201 = (fConst240 * fRec393[1]);
			double fTemp202 = (fConst241 * fRec396[1]);
			fRec398[0] = (fTemp200 + (fTemp201 + (fRec398[1] + fTemp202)));
			fRec396[0] = fRec398[0];
			double fRec397 = ((fTemp202 + fTemp201) + fTemp200);
			fRec395[0] = (fRec396[0] + fRec395[1]);
			fRec393[0] = fRec395[0];
			double fRec394 = fRec397;
			fVec6[(IOTA & 63)] = ((0.062088905799999997 * fTemp7) + (fRec355 + (fRec370 + (fRec382 + (fRec391 + fRec394)))));
			output7[i] = FAUSTFLOAT((0.976303317535545 * (fRec0[0] * fVec6[((IOTA - iConst242) & 63)])));
			double fTemp203 = (fConst244 * fRec399[1]);
			double fTemp204 = (fConst246 * fRec402[1]);
			double fTemp205 = (fConst247 * fRec405[1]);
			double fTemp206 = (fConst249 * (((0.0297825218 * fTemp20) + ((0.0233529432 * fTemp19) + ((((0.009611217 * fTemp11) + (0.00085924250000000003 * fTemp16)) + (0.0380175632 * fTemp14)) + (0.023108430900000001 * fTemp18)))) - (((((0.0050542857000000002 * fTemp17) + (0.033121045699999997 * fTemp12)) + (0.056201604500000002 * fTemp13)) + (0.069988886200000003 * fTemp15)) + (0.0056876729000000003 * fTemp21))));
			double fTemp207 = (fConst250 * fRec408[1]);
			double fTemp208 = (fConst251 * fRec411[1]);
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
			double fTemp209 = (fConst253 * fRec414[1]);
			double fTemp210 = (fConst254 * fRec417[1]);
			double fTemp211 = (fConst256 * (((((0.0038525757999999998 * fTemp32) + (0.063308772599999993 * fTemp33)) + (0.0189105421 * fTemp34)) + (0.0126698761 * fTemp31)) - (((((0.0016701845999999999 * fTemp27) + (0.085986149999999997 * fTemp28)) + (0.1128947417 * fTemp29)) + (0.064676209700000001 * fTemp30)) + (0.017979494200000001 * fTemp35))));
			double fTemp212 = (fConst257 * fRec420[1]);
			double fTemp213 = (fConst258 * fRec423[1]);
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
			double fTemp214 = (fConst260 * fRec426[1]);
			double fTemp215 = (fConst262 * (((((0.0058131051000000003 * fTemp40) + (0.1621856109 * fTemp43)) + (0.062665245199999997 * fTemp44)) + (0.082414582099999995 * fTemp45)) - ((0.0310230705 * fTemp42) + ((0.17173489480000001 * fTemp41) + (0.0133992312 * fTemp46)))));
			double fTemp216 = (fConst263 * fRec429[1]);
			double fTemp217 = (fConst264 * fRec432[1]);
			fRec434[0] = (fTemp215 + (fTemp216 + (fRec434[1] + fTemp217)));
			fRec432[0] = fRec434[0];
			double fRec433 = ((fTemp217 + fTemp216) + fTemp215);
			fRec431[0] = (fRec432[0] + fRec431[1]);
			fRec429[0] = fRec431[0];
			double fRec430 = fRec433;
			fRec428[0] = (fTemp214 + (fRec430 + fRec428[1]));
			fRec426[0] = fRec428[0];
			double fRec427 = (fRec430 + fTemp214);
			double fTemp218 = (fConst266 * (((0.1638181571 * fTemp50) + (0.1767763077 * fTemp52)) + (0.14591914650000001 * fTemp51)));
			double fTemp219 = (fConst267 * fRec435[1]);
			fRec437[0] = (fTemp218 + (fRec437[1] + fTemp219));
			fRec435[0] = fRec437[0];
			double fRec436 = (fTemp219 + fTemp218);
			double fTemp220 = (fConst269 * ((((0.13008314100000001 * fTemp55) + (0.21349855940000001 * fTemp57)) + (0.2034154748 * fTemp59)) - ((0.0066731170000000001 * fTemp58) + (0.0230121584 * fTemp56))));
			double fTemp221 = (fConst270 * fRec438[1]);
			double fTemp222 = (fConst271 * fRec441[1]);
			fRec443[0] = (fTemp220 + (fTemp221 + (fRec443[1] + fTemp222)));
			fRec441[0] = fRec443[0];
			double fRec442 = ((fTemp222 + fTemp221) + fTemp220);
			fRec440[0] = (fRec441[0] + fRec440[1]);
			fRec438[0] = fRec440[0];
			double fRec439 = fRec442;
			fVec7[(IOTA & 255)] = ((0.1130599913 * fTemp7) + (fRec400 + (fRec415 + (fRec427 + (fRec436 + fRec439)))));
			output8[i] = FAUSTFLOAT((0.89454976303317535 * (fRec0[0] * fVec7[((IOTA - iConst272) & 255)])));
			double fTemp223 = (fConst244 * fRec444[1]);
			double fTemp224 = (fConst246 * fRec447[1]);
			double fTemp225 = (fConst247 * fRec450[1]);
			double fTemp226 = (fConst249 * (((0.0131122724 * fTemp21) + ((0.045681315899999998 * fTemp20) + (((0.060224391500000002 * fTemp14) + ((((0.0024145782999999998 * fTemp16) + (0.0050302990999999998 * fTemp17)) + (0.030802380800000001 * fTemp12)) + (0.055927788700000002 * fTemp13))) + (0.0049479737999999999 * fTemp19)))) - ((0.0038845361000000001 * fTemp18) + ((0.0073934070999999999 * fTemp11) + (0.052516738100000002 * fTemp15)))));
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
			double fTemp231 = (fConst256 * ((((0.0040829443000000003 * fTemp27) + (0.084932226499999999 * fTemp28)) + (0.037277559500000002 * fTemp31)) - ((0.00079112400000000004 * fTemp35) + ((0.0032118984000000001 * fTemp34) + ((((0.0012750754 * fTemp32) + (0.063729281400000004 * fTemp33)) + (0.097646062699999994 * fTemp29)) + (0.089487759200000003 * fTemp30))))));
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
			double fTemp235 = (fConst262 * (((0.058483718800000001 * fTemp45) + (0.0022606286 * fTemp46)) - (((((0.0037079565999999999 * fTemp40) + (0.16065397610000001 * fTemp43)) + (0.063029153300000001 * fTemp44)) + (0.18542016319999999 * fTemp41)) + (0.0032303239000000001 * fTemp42))));
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
			double fTemp238 = (fConst266 * (((0.1811081038 * fTemp52) + (0.16726028000000001 * fTemp51)) - (0.16326933299999999 * fTemp50)));
			double fTemp239 = (fConst267 * fRec480[1]);
			fRec482[0] = (fTemp238 + (fRec482[1] + fTemp239));
			fRec480[0] = fRec482[0];
			double fRec481 = (fTemp239 + fTemp238);
			double fTemp240 = (fConst269 * (((0.2150620141 * fTemp59) + (0.00390741 * fTemp56)) - (((0.12868280739999999 * fTemp55) + (0.21294943999999999 * fTemp57)) + (0.023085793 * fTemp58))));
			double fTemp241 = (fConst270 * fRec483[1]);
			double fTemp242 = (fConst271 * fRec486[1]);
			fRec488[0] = (fTemp240 + (fTemp241 + (fRec488[1] + fTemp242)));
			fRec486[0] = fRec488[0];
			double fRec487 = ((fTemp242 + fTemp241) + fTemp240);
			fRec485[0] = (fRec486[0] + fRec485[1]);
			fRec483[0] = fRec485[0];
			double fRec484 = fRec487;
			fVec8[(IOTA & 255)] = ((0.1206169159 * fTemp7) + (fRec445 + (fRec460 + (fRec472 + (fRec481 + fRec484)))));
			output9[i] = FAUSTFLOAT((0.89454976303317535 * (fRec0[0] * fVec8[((IOTA - iConst272) & 255)])));
			double fTemp243 = (fConst274 * fRec489[1]);
			double fTemp244 = (fConst276 * (((0.1580468843 * fTemp43) + (0.042767804999999999 * fTemp42)) - (((((0.0087817833000000001 * fTemp40) + (0.083954024000000002 * fTemp44)) + (0.15229090349999999 * fTemp41)) + (0.097828076299999997 * fTemp45)) + (0.013926621199999999 * fTemp46))));
			double fTemp245 = (fConst277 * fRec492[1]);
			double fTemp246 = (fConst278 * fRec495[1]);
			fRec497[0] = (fTemp244 + (fTemp245 + (fRec497[1] + fTemp246)));
			fRec495[0] = fRec497[0];
			double fRec496 = ((fTemp246 + fTemp245) + fTemp244);
			fRec494[0] = (fRec495[0] + fRec494[1]);
			fRec492[0] = fRec494[0];
			double fRec493 = fRec496;
			fRec491[0] = (fTemp243 + (fRec493 + fRec491[1]));
			fRec489[0] = fRec491[0];
			double fRec490 = (fRec493 + fTemp243);
			double fTemp247 = (fConst280 * ((0.17058547609999999 * fTemp52) - ((0.1453717595 * fTemp50) + (0.1316162437 * fTemp51))));
			double fTemp248 = (fConst281 * fRec498[1]);
			fRec500[0] = (fTemp247 + (fRec500[1] + fTemp248));
			fRec498[0] = fRec500[0];
			double fRec499 = (fTemp248 + fTemp247);
			double fTemp249 = (fConst283 * (((0.1199590024 * fTemp55) + (0.015661929599999999 * fTemp58)) - (((0.20402777420000001 * fTemp57) + (0.19494619390000001 * fTemp59)) + (0.020568303900000001 * fTemp56))));
			double fTemp250 = (fConst284 * fRec501[1]);
			double fTemp251 = (fConst285 * fRec504[1]);
			fRec506[0] = (fTemp249 + (fTemp250 + (fRec506[1] + fTemp251)));
			fRec504[0] = fRec506[0];
			double fRec505 = ((fTemp251 + fTemp250) + fTemp249);
			fRec503[0] = (fRec504[0] + fRec503[1]);
			fRec501[0] = fRec503[0];
			double fRec502 = fRec505;
			double fTemp252 = (fConst287 * fRec507[1]);
			double fTemp253 = (fConst288 * fRec510[1]);
			double fTemp254 = (fConst290 * (((0.029204994500000001 * fTemp35) + ((0.014930674499999999 * fTemp34) + (((0.073546635099999993 * fTemp33) + (0.065547893600000004 * fTemp28)) + (0.046854595899999997 * fTemp30)))) - ((((0.019893196200000001 * fTemp27) + (0.0069740430999999997 * fTemp32)) + (0.13295343579999999 * fTemp29)) + (0.0068394559999999998 * fTemp31))));
			double fTemp255 = (fConst291 * fRec513[1]);
			double fTemp256 = (fConst292 * fRec516[1]);
			fRec518[0] = (fTemp254 + (fTemp255 + (fRec518[1] + fTemp256)));
			fRec516[0] = fRec518[0];
			double fRec517 = ((fTemp256 + fTemp255) + fTemp254);
			fRec515[0] = (fRec515[1] + fRec516[0]);
			fRec513[0] = fRec515[0];
			double fRec514 = fRec517;
			fRec512[0] = ((fTemp252 + (fRec512[1] + fTemp253)) + fRec514);
			fRec510[0] = fRec512[0];
			double fRec511 = ((fTemp253 + fTemp252) + fRec514);
			fRec509[0] = (fRec509[1] + fRec510[0]);
			fRec507[0] = fRec509[0];
			double fRec508 = fRec511;
			double fTemp257 = (fConst294 * fRec519[1]);
			double fTemp258 = (fConst296 * fRec522[1]);
			double fTemp259 = (fConst297 * fRec525[1]);
			double fTemp260 = (fConst299 * ((((0.0231489112 * fTemp18) + ((0.079771473999999995 * fTemp15) + ((0.0067885934999999996 * fTemp14) + (((0.0169697485 * fTemp11) + (0.0053612686 * fTemp17)) + (0.073109085500000004 * fTemp13))))) + (0.0134027451 * fTemp20)) - ((((0.011043593399999999 * fTemp16) + (0.025002611300000002 * fTemp12)) + (0.026884691499999998 * fTemp19)) + (0.0021474427000000001 * fTemp21))));
			double fTemp261 = (fConst300 * fRec528[1]);
			double fTemp262 = (fConst301 * fRec531[1]);
			fRec533[0] = (fTemp260 + (fTemp261 + (fRec533[1] + fTemp262)));
			fRec531[0] = fRec533[0];
			double fRec532 = ((fTemp262 + fTemp261) + fTemp260);
			fRec530[0] = (fRec530[1] + fRec531[0]);
			fRec528[0] = fRec530[0];
			double fRec529 = fRec532;
			fRec527[0] = ((fTemp258 + (fRec527[1] + fTemp259)) + fRec529);
			fRec525[0] = fRec527[0];
			double fRec526 = ((fTemp259 + fTemp258) + fRec529);
			fRec524[0] = (fRec524[1] + fRec525[0]);
			fRec522[0] = fRec524[0];
			double fRec523 = fRec526;
			fRec521[0] = ((fRec521[1] + fTemp257) + fRec523);
			fRec519[0] = fRec521[0];
			double fRec520 = (fTemp257 + fRec523);
			fVec9[(IOTA & 255)] = ((0.1026666754 * fTemp7) + (((fRec490 + (fRec499 + fRec502)) + fRec508) + fRec520));
			output10[i] = FAUSTFLOAT((0.90343601895734593 * (fRec0[0] * fVec9[((IOTA - iConst302) & 255)])));
			double fTemp263 = (fConst244 * fRec534[1]);
			double fTemp264 = (fConst246 * fRec537[1]);
			double fTemp265 = (fConst247 * fRec540[1]);
			double fTemp266 = (fConst249 * ((((0.050580007400000002 * fTemp15) + (((0.01517285 * fTemp16) + (0.021828078599999998 * fTemp12)) + (0.052661865400000001 * fTemp14))) + (0.0341549939 * fTemp20)) - (((0.0064851172000000004 * fTemp19) + ((((0.018952008900000001 * fTemp11) + (0.0061973150000000001 * fTemp17)) + (0.072281232299999998 * fTemp13)) + (0.027531791 * fTemp18))) + (0.0073202327999999997 * fTemp21))));
			double fTemp267 = (fConst250 * fRec543[1]);
			double fTemp268 = (fConst251 * fRec546[1]);
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
			double fTemp269 = (fConst253 * fRec549[1]);
			double fTemp270 = (fConst254 * fRec552[1]);
			double fTemp271 = (fConst256 * (((0.0156817967 * fTemp31) + ((((0.022392501400000001 * fTemp27) + (0.0034274994999999998 * fTemp32)) + (0.097554315200000005 * fTemp30)) + (0.00036036919999999999 * fTemp35))) - ((((0.0735171357 * fTemp33) + (0.063931763000000003 * fTemp28)) + (0.1044722835 * fTemp29)) + (0.020261881799999999 * fTemp34))));
			double fTemp272 = (fConst257 * fRec555[1]);
			double fTemp273 = (fConst258 * fRec558[1]);
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
			double fTemp274 = (fConst266 * (((0.1446583713 * fTemp50) + (0.1797626873 * fTemp52)) - (0.17287215340000001 * fTemp51)));
			double fTemp275 = (fConst267 * fRec561[1]);
			fRec563[0] = (fTemp274 + (fRec563[1] + fTemp275));
			fRec561[0] = fRec563[0];
			double fRec562 = (fTemp275 + fTemp274);
			double fTemp276 = (fConst269 * (((0.2031679069 * fTemp57) + (0.026076293699999999 * fTemp56)) - (((0.118283712 * fTemp55) + (0.016646586000000001 * fTemp58)) + (0.21906306079999999 * fTemp59))));
			double fTemp277 = (fConst270 * fRec564[1]);
			double fTemp278 = (fConst271 * fRec567[1]);
			fRec569[0] = (fTemp276 + (fTemp277 + (fRec569[1] + fTemp278)));
			fRec567[0] = fRec569[0];
			double fRec568 = ((fTemp278 + fTemp277) + fTemp276);
			fRec566[0] = (fRec566[1] + fRec567[0]);
			fRec564[0] = fRec566[0];
			double fRec565 = fRec568;
			double fTemp279 = (fConst262 * (((0.0040371770999999999 * fTemp42) + (((0.0064021082000000002 * fTemp40) + (0.084273836699999993 * fTemp44)) + (0.016298420000000001 * fTemp46))) - (((0.1557890331 * fTemp43) + (0.1810311443 * fTemp41)) + (0.053133621300000003 * fTemp45))));
			double fTemp280 = (fConst263 * fRec573[1]);
			double fTemp281 = (fConst264 * fRec576[1]);
			fRec578[0] = (fTemp279 + (fTemp280 + (fRec578[1] + fTemp281)));
			fRec576[0] = fRec578[0];
			double fRec577 = ((fTemp281 + fTemp280) + fTemp279);
			fRec575[0] = (fRec575[1] + fRec576[0]);
			fRec573[0] = fRec575[0];
			double fRec574 = fRec577;
			double fTemp282 = (fConst260 * fRec570[1]);
			fRec572[0] = (fRec574 + (fRec572[1] + fTemp282));
			fRec570[0] = fRec572[0];
			double fRec571 = (fTemp282 + fRec574);
			fVec10[(IOTA & 255)] = ((0.1177838765 * fTemp7) + (fRec535 + (fRec550 + ((fRec562 + fRec565) + fRec571))));
			output11[i] = FAUSTFLOAT((0.89454976303317535 * (fRec0[0] * fVec10[((IOTA - iConst272) & 255)])));
			double fTemp283 = (fConst304 * fRec579[1]);
			double fTemp284 = (fConst306 * fRec582[1]);
			double fTemp285 = (fConst307 * fRec585[1]);
			double fTemp286 = (fConst309 * ((((4.1103899999999998e-05 * fTemp16) + (5.8398000000000004e-06 * fTemp12)) + (1.37585e-05 * fTemp13)) - ((7.0557000000000001e-06 * fTemp21) + ((0.027577275200000001 * fTemp20) + ((1.2528000000000001e-06 * fTemp19) + ((7.6244999999999996e-06 * fTemp18) + ((1.12673e-05 * fTemp15) + (((1.4164900000000001e-05 * fTemp11) + (7.0095999999999998e-06 * fTemp17)) + (0.071487558100000001 * fTemp14)))))))));
			double fTemp287 = (fConst310 * fRec588[1]);
			double fTemp288 = (fConst311 * fRec591[1]);
			fRec593[0] = (fTemp286 + (fTemp287 + (fRec593[1] + fTemp288)));
			fRec591[0] = fRec593[0];
			double fRec592 = ((fTemp288 + fTemp287) + fTemp286);
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
			double fTemp289 = (fConst313 * fRec594[1]);
			double fTemp290 = (fConst314 * fRec597[1]);
			double fTemp291 = (fConst316 * (((6.0526000000000003e-06 * fTemp35) + ((((2.8717400000000001e-05 * fTemp27) + (1.3652800000000001e-05 * fTemp28)) + (0.027677506599999999 * fTemp29)) + (3.3879999999999999e-07 * fTemp34))) - ((((1.13386e-05 * fTemp32) + (3.4703999999999998e-06 * fTemp33)) + (1.1470100000000001e-05 * fTemp30)) + (0.014370546200000001 * fTemp31))));
			double fTemp292 = (fConst317 * fRec600[1]);
			double fTemp293 = (fConst318 * fRec603[1]);
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
			double fTemp294 = (fConst320 * fRec606[1]);
			double fTemp295 = (fConst322 * (((4.3178000000000004e-06 * fTemp42) + ((6.6695000000000003e-06 * fTemp46) + ((0.21350482379999999 * fTemp41) + (4.3414999999999999e-06 * fTemp45)))) - (((7.5517000000000001e-06 * fTemp40) + (9.9127000000000008e-06 * fTemp43)) + (5.5769999999999997e-07 * fTemp44))));
			double fTemp296 = (fConst323 * fRec609[1]);
			double fTemp297 = (fConst324 * fRec612[1]);
			fRec614[0] = (fTemp295 + (fTemp296 + (fRec614[1] + fTemp297)));
			fRec612[0] = fRec614[0];
			double fRec613 = ((fTemp297 + fTemp296) + fTemp295);
			fRec611[0] = (fRec612[0] + fRec611[1]);
			fRec609[0] = fRec611[0];
			double fRec610 = fRec613;
			fRec608[0] = (fTemp294 + (fRec610 + fRec608[1]));
			fRec606[0] = fRec608[0];
			double fRec607 = (fRec610 + fTemp294);
			double fTemp298 = (fConst326 * (((0.35535933549999998 * fTemp52) + (1.25946e-05 * fTemp51)) - (8.9069999999999996e-06 * fTemp50)));
			double fTemp299 = (fConst327 * fRec615[1]);
			fRec617[0] = (fTemp298 + (fRec617[1] + fTemp299));
			fRec615[0] = fRec617[0];
			double fRec616 = (fTemp299 + fTemp298);
			double fTemp300 = (fConst329 * ((((0.36672656650000002 * fTemp58) + (1.7067000000000001e-05 * fTemp59)) + (5.4956999999999997e-06 * fTemp56)) - ((7.3487999999999998e-06 * fTemp55) + (1.15651e-05 * fTemp57))));
			double fTemp301 = (fConst330 * fRec618[1]);
			double fTemp302 = (fConst331 * fRec621[1]);
			fRec623[0] = (fTemp300 + (fTemp301 + (fRec623[1] + fTemp302)));
			fRec621[0] = fRec623[0];
			double fRec622 = ((fTemp302 + fTemp301) + fTemp300);
			fRec620[0] = (fRec621[0] + fRec620[1]);
			fRec618[0] = fRec620[0];
			double fRec619 = fRec622;
			fVec11[(IOTA & 1023)] = ((0.1475660167 * fTemp7) + (fRec580 + (fRec595 + (fRec607 + (fRec616 + fRec619)))));
			output12[i] = FAUSTFLOAT((0.47393364928909959 * (fRec0[0] * fVec11[((IOTA - iConst332) & 1023)])));
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
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
			fRec28[2] = fRec28[1];
			fRec28[1] = fRec28[0];
			fRec29[2] = fRec29[1];
			fRec29[1] = fRec29[0];
			fRec18[1] = fRec18[0];
			fRec16[1] = fRec16[0];
			fRec15[1] = fRec15[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec10[1] = fRec10[0];
			fRec9[1] = fRec9[0];
			fRec7[1] = fRec7[0];
			fRec6[1] = fRec6[0];
			fRec4[1] = fRec4[0];
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
			fRec50[2] = fRec50[1];
			fRec50[1] = fRec50[0];
			fRec41[1] = fRec41[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			fRec36[1] = fRec36[0];
			fRec35[1] = fRec35[0];
			fRec33[1] = fRec33[0];
			fRec32[1] = fRec32[0];
			fRec30[1] = fRec30[0];
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
			fRec66[2] = fRec66[1];
			fRec66[1] = fRec66[0];
			fRec59[1] = fRec59[0];
			fRec57[1] = fRec57[0];
			fRec56[1] = fRec56[0];
			fRec54[1] = fRec54[0];
			fRec53[1] = fRec53[0];
			fRec51[1] = fRec51[0];
			fRec70[2] = fRec70[1];
			fRec70[1] = fRec70[0];
			fRec71[2] = fRec71[1];
			fRec71[1] = fRec71[0];
			fRec72[2] = fRec72[1];
			fRec72[1] = fRec72[0];
			fRec69[1] = fRec69[0];
			fRec67[1] = fRec67[0];
			fRec79[2] = fRec79[1];
			fRec79[1] = fRec79[0];
			fRec80[2] = fRec80[1];
			fRec80[1] = fRec80[0];
			fRec81[2] = fRec81[1];
			fRec81[1] = fRec81[0];
			fRec82[2] = fRec82[1];
			fRec82[1] = fRec82[0];
			fRec83[2] = fRec83[1];
			fRec83[1] = fRec83[0];
			fRec78[1] = fRec78[0];
			fRec76[1] = fRec76[0];
			fRec75[1] = fRec75[0];
			fRec73[1] = fRec73[0];
			IOTA = (IOTA + 1);
			fRec98[1] = fRec98[0];
			fRec96[1] = fRec96[0];
			fRec95[1] = fRec95[0];
			fRec93[1] = fRec93[0];
			fRec92[1] = fRec92[0];
			fRec90[1] = fRec90[0];
			fRec89[1] = fRec89[0];
			fRec87[1] = fRec87[0];
			fRec86[1] = fRec86[0];
			fRec84[1] = fRec84[0];
			fRec104[1] = fRec104[0];
			fRec102[1] = fRec102[0];
			fRec101[1] = fRec101[0];
			fRec99[1] = fRec99[0];
			fRec107[1] = fRec107[0];
			fRec105[1] = fRec105[0];
			fRec116[1] = fRec116[0];
			fRec114[1] = fRec114[0];
			fRec113[1] = fRec113[0];
			fRec111[1] = fRec111[0];
			fRec110[1] = fRec110[0];
			fRec108[1] = fRec108[0];
			fRec128[1] = fRec128[0];
			fRec126[1] = fRec126[0];
			fRec125[1] = fRec125[0];
			fRec123[1] = fRec123[0];
			fRec122[1] = fRec122[0];
			fRec120[1] = fRec120[0];
			fRec119[1] = fRec119[0];
			fRec117[1] = fRec117[0];
			fRec143[1] = fRec143[0];
			fRec141[1] = fRec141[0];
			fRec140[1] = fRec140[0];
			fRec138[1] = fRec138[0];
			fRec137[1] = fRec137[0];
			fRec135[1] = fRec135[0];
			fRec134[1] = fRec134[0];
			fRec132[1] = fRec132[0];
			fRec131[1] = fRec131[0];
			fRec129[1] = fRec129[0];
			fRec155[1] = fRec155[0];
			fRec153[1] = fRec153[0];
			fRec152[1] = fRec152[0];
			fRec150[1] = fRec150[0];
			fRec149[1] = fRec149[0];
			fRec147[1] = fRec147[0];
			fRec146[1] = fRec146[0];
			fRec144[1] = fRec144[0];
			fRec164[1] = fRec164[0];
			fRec162[1] = fRec162[0];
			fRec161[1] = fRec161[0];
			fRec159[1] = fRec159[0];
			fRec158[1] = fRec158[0];
			fRec156[1] = fRec156[0];
			fRec167[1] = fRec167[0];
			fRec165[1] = fRec165[0];
			fRec173[1] = fRec173[0];
			fRec171[1] = fRec171[0];
			fRec170[1] = fRec170[0];
			fRec168[1] = fRec168[0];
			for (int j0 = 15; (j0 > 0); j0 = (j0 - 1)) {
				fVec2[j0] = fVec2[(j0 - 1)];
				
			}
			fRec188[1] = fRec188[0];
			fRec186[1] = fRec186[0];
			fRec185[1] = fRec185[0];
			fRec183[1] = fRec183[0];
			fRec182[1] = fRec182[0];
			fRec180[1] = fRec180[0];
			fRec179[1] = fRec179[0];
			fRec177[1] = fRec177[0];
			fRec176[1] = fRec176[0];
			fRec174[1] = fRec174[0];
			fRec200[1] = fRec200[0];
			fRec198[1] = fRec198[0];
			fRec197[1] = fRec197[0];
			fRec195[1] = fRec195[0];
			fRec194[1] = fRec194[0];
			fRec192[1] = fRec192[0];
			fRec191[1] = fRec191[0];
			fRec189[1] = fRec189[0];
			fRec209[1] = fRec209[0];
			fRec207[1] = fRec207[0];
			fRec206[1] = fRec206[0];
			fRec204[1] = fRec204[0];
			fRec203[1] = fRec203[0];
			fRec201[1] = fRec201[0];
			fRec212[1] = fRec212[0];
			fRec210[1] = fRec210[0];
			fRec218[1] = fRec218[0];
			fRec216[1] = fRec216[0];
			fRec215[1] = fRec215[0];
			fRec213[1] = fRec213[0];
			fRec233[1] = fRec233[0];
			fRec231[1] = fRec231[0];
			fRec230[1] = fRec230[0];
			fRec228[1] = fRec228[0];
			fRec227[1] = fRec227[0];
			fRec225[1] = fRec225[0];
			fRec224[1] = fRec224[0];
			fRec222[1] = fRec222[0];
			fRec221[1] = fRec221[0];
			fRec219[1] = fRec219[0];
			fRec245[1] = fRec245[0];
			fRec243[1] = fRec243[0];
			fRec242[1] = fRec242[0];
			fRec240[1] = fRec240[0];
			fRec239[1] = fRec239[0];
			fRec237[1] = fRec237[0];
			fRec236[1] = fRec236[0];
			fRec234[1] = fRec234[0];
			fRec254[1] = fRec254[0];
			fRec252[1] = fRec252[0];
			fRec251[1] = fRec251[0];
			fRec249[1] = fRec249[0];
			fRec248[1] = fRec248[0];
			fRec246[1] = fRec246[0];
			fRec257[1] = fRec257[0];
			fRec255[1] = fRec255[0];
			fRec263[1] = fRec263[0];
			fRec261[1] = fRec261[0];
			fRec260[1] = fRec260[0];
			fRec258[1] = fRec258[0];
			for (int j1 = 7; (j1 > 0); j1 = (j1 - 1)) {
				fVec4[j1] = fVec4[(j1 - 1)];
				
			}
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
			fRec290[1] = fRec290[0];
			fRec288[1] = fRec288[0];
			fRec287[1] = fRec287[0];
			fRec285[1] = fRec285[0];
			fRec284[1] = fRec284[0];
			fRec282[1] = fRec282[0];
			fRec281[1] = fRec281[0];
			fRec279[1] = fRec279[0];
			fRec299[1] = fRec299[0];
			fRec297[1] = fRec297[0];
			fRec296[1] = fRec296[0];
			fRec294[1] = fRec294[0];
			fRec293[1] = fRec293[0];
			fRec291[1] = fRec291[0];
			fRec302[1] = fRec302[0];
			fRec300[1] = fRec300[0];
			fRec308[1] = fRec308[0];
			fRec306[1] = fRec306[0];
			fRec305[1] = fRec305[0];
			fRec303[1] = fRec303[0];
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
			fRec347[1] = fRec347[0];
			fRec345[1] = fRec345[0];
			fRec353[1] = fRec353[0];
			fRec351[1] = fRec351[0];
			fRec350[1] = fRec350[0];
			fRec348[1] = fRec348[0];
			fRec368[1] = fRec368[0];
			fRec366[1] = fRec366[0];
			fRec365[1] = fRec365[0];
			fRec363[1] = fRec363[0];
			fRec362[1] = fRec362[0];
			fRec360[1] = fRec360[0];
			fRec359[1] = fRec359[0];
			fRec357[1] = fRec357[0];
			fRec356[1] = fRec356[0];
			fRec354[1] = fRec354[0];
			fRec380[1] = fRec380[0];
			fRec378[1] = fRec378[0];
			fRec377[1] = fRec377[0];
			fRec375[1] = fRec375[0];
			fRec374[1] = fRec374[0];
			fRec372[1] = fRec372[0];
			fRec371[1] = fRec371[0];
			fRec369[1] = fRec369[0];
			fRec389[1] = fRec389[0];
			fRec387[1] = fRec387[0];
			fRec386[1] = fRec386[0];
			fRec384[1] = fRec384[0];
			fRec383[1] = fRec383[0];
			fRec381[1] = fRec381[0];
			fRec392[1] = fRec392[0];
			fRec390[1] = fRec390[0];
			fRec398[1] = fRec398[0];
			fRec396[1] = fRec396[0];
			fRec395[1] = fRec395[0];
			fRec393[1] = fRec393[0];
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
			fRec497[1] = fRec497[0];
			fRec495[1] = fRec495[0];
			fRec494[1] = fRec494[0];
			fRec492[1] = fRec492[0];
			fRec491[1] = fRec491[0];
			fRec489[1] = fRec489[0];
			fRec500[1] = fRec500[0];
			fRec498[1] = fRec498[0];
			fRec506[1] = fRec506[0];
			fRec504[1] = fRec504[0];
			fRec503[1] = fRec503[0];
			fRec501[1] = fRec501[0];
			fRec518[1] = fRec518[0];
			fRec516[1] = fRec516[0];
			fRec515[1] = fRec515[0];
			fRec513[1] = fRec513[0];
			fRec512[1] = fRec512[0];
			fRec510[1] = fRec510[0];
			fRec509[1] = fRec509[0];
			fRec507[1] = fRec507[0];
			fRec533[1] = fRec533[0];
			fRec531[1] = fRec531[0];
			fRec530[1] = fRec530[0];
			fRec528[1] = fRec528[0];
			fRec527[1] = fRec527[0];
			fRec525[1] = fRec525[0];
			fRec524[1] = fRec524[0];
			fRec522[1] = fRec522[0];
			fRec521[1] = fRec521[0];
			fRec519[1] = fRec519[0];
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
			fRec563[1] = fRec563[0];
			fRec561[1] = fRec561[0];
			fRec569[1] = fRec569[0];
			fRec567[1] = fRec567[0];
			fRec566[1] = fRec566[0];
			fRec564[1] = fRec564[0];
			fRec578[1] = fRec578[0];
			fRec576[1] = fRec576[0];
			fRec575[1] = fRec575[0];
			fRec573[1] = fRec573[0];
			fRec572[1] = fRec572[0];
			fRec570[1] = fRec570[0];
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
			fRec617[1] = fRec617[0];
			fRec615[1] = fRec615[0];
			fRec623[1] = fRec623[0];
			fRec621[1] = fRec621[0];
			fRec620[1] = fRec620[0];
			fRec618[1] = fRec618[0];
			
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
