/* ------------------------------------------------------------
author: "AmbisonicDecoderToolkit"
copyright: "(c) Aaron J. Heller 2013"
license: "BSD 3-Clause License"
name: "KMH114_AE_7h7v_normal_4"
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
	double fRec4[3];
	double fRec5[3];
	double fRec6[3];
	double fRec7[3];
	double fRec8[3];
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	double fConst7;
	double fConst8;
	double fConst9;
	double fConst10;
	double fConst11;
	double fRec27[3];
	double fRec28[3];
	double fRec29[3];
	double fRec30[3];
	double fRec31[3];
	double fRec32[3];
	double fRec33[3];
	double fRec34[3];
	double fRec35[3];
	double fRec36[3];
	double fRec37[3];
	double fRec38[3];
	double fRec39[3];
	double fConst12;
	double fConst13;
	double fRec26[2];
	double fRec24[2];
	double fRec23[2];
	double fRec21[2];
	double fRec20[2];
	double fRec18[2];
	double fRec17[2];
	double fRec15[2];
	double fRec14[2];
	double fRec12[2];
	double fRec11[2];
	double fRec9[2];
	double fConst14;
	double fConst15;
	double fConst16;
	double fConst17;
	double fConst18;
	double fConst19;
	double fConst20;
	double fRec55[3];
	double fRec56[3];
	double fRec57[3];
	double fRec58[3];
	double fRec59[3];
	double fRec60[3];
	double fRec61[3];
	double fRec62[3];
	double fRec63[3];
	double fConst21;
	double fConst22;
	double fRec54[2];
	double fRec52[2];
	double fRec51[2];
	double fRec49[2];
	double fRec48[2];
	double fRec46[2];
	double fRec45[2];
	double fRec43[2];
	double fRec42[2];
	double fRec40[2];
	double fConst23;
	double fConst24;
	double fConst25;
	double fConst26;
	double fConst27;
	double fRec76[3];
	double fRec77[3];
	double fRec78[3];
	double fRec79[3];
	double fRec80[3];
	double fRec81[3];
	double fRec82[3];
	double fRec83[3];
	double fRec84[3];
	double fConst28;
	double fConst29;
	double fRec75[2];
	double fRec73[2];
	double fRec72[2];
	double fRec70[2];
	double fRec69[2];
	double fRec67[2];
	double fRec66[2];
	double fRec64[2];
	double fConst30;
	double fConst31;
	double fConst32;
	double fConst33;
	double fRec94[3];
	double fRec95[3];
	double fRec96[3];
	double fRec97[3];
	double fRec98[3];
	double fRec99[3];
	double fConst34;
	double fConst35;
	double fRec93[2];
	double fRec91[2];
	double fRec90[2];
	double fRec88[2];
	double fRec87[2];
	double fRec85[2];
	double fConst36;
	double fConst37;
	double fRec103[3];
	double fRec104[3];
	double fRec105[3];
	double fConst38;
	double fRec102[2];
	double fRec100[2];
	double fConst39;
	double fConst40;
	double fRec112[3];
	double fRec113[3];
	double fRec114[3];
	double fRec115[3];
	double fRec116[3];
	double fConst41;
	double fConst42;
	double fRec111[2];
	double fRec109[2];
	double fRec108[2];
	double fRec106[2];
	double fRec117[3];
	double fRec118[3];
	double fRec119[3];
	double fRec120[3];
	double fRec121[3];
	double fRec122[3];
	double fRec123[3];
	int IOTA;
	double fVec0[128];
	int iConst43;
	double fConst44;
	double fConst45;
	double fConst46;
	double fConst47;
	double fConst48;
	double fConst49;
	double fConst50;
	double fConst51;
	double fConst52;
	double fConst53;
	double fRec141[2];
	double fRec139[2];
	double fRec138[2];
	double fRec136[2];
	double fRec135[2];
	double fRec133[2];
	double fRec132[2];
	double fRec130[2];
	double fRec129[2];
	double fRec127[2];
	double fRec126[2];
	double fRec124[2];
	double fConst54;
	double fConst55;
	double fConst56;
	double fConst57;
	double fConst58;
	double fConst59;
	double fConst60;
	double fConst61;
	double fConst62;
	double fRec156[2];
	double fRec154[2];
	double fRec153[2];
	double fRec151[2];
	double fRec150[2];
	double fRec148[2];
	double fRec147[2];
	double fRec145[2];
	double fRec144[2];
	double fRec142[2];
	double fConst63;
	double fConst64;
	double fConst65;
	double fConst66;
	double fConst67;
	double fConst68;
	double fConst69;
	double fRec168[2];
	double fRec166[2];
	double fRec165[2];
	double fRec163[2];
	double fRec162[2];
	double fRec160[2];
	double fRec159[2];
	double fRec157[2];
	double fConst70;
	double fConst71;
	double fConst72;
	double fConst73;
	double fConst74;
	double fConst75;
	double fRec177[2];
	double fRec175[2];
	double fRec174[2];
	double fRec172[2];
	double fRec171[2];
	double fRec169[2];
	double fConst76;
	double fConst77;
	double fConst78;
	double fRec180[2];
	double fRec178[2];
	double fConst79;
	double fConst80;
	double fConst81;
	double fConst82;
	double fRec186[2];
	double fRec184[2];
	double fRec183[2];
	double fRec181[2];
	double fVec1[64];
	int iConst83;
	double fConst84;
	double fConst85;
	double fConst86;
	double fConst87;
	double fConst88;
	double fConst89;
	double fConst90;
	double fConst91;
	double fConst92;
	double fConst93;
	double fRec204[2];
	double fRec202[2];
	double fRec201[2];
	double fRec199[2];
	double fRec198[2];
	double fRec196[2];
	double fRec195[2];
	double fRec193[2];
	double fRec192[2];
	double fRec190[2];
	double fRec189[2];
	double fRec187[2];
	double fConst94;
	double fConst95;
	double fConst96;
	double fConst97;
	double fConst98;
	double fConst99;
	double fConst100;
	double fConst101;
	double fConst102;
	double fRec219[2];
	double fRec217[2];
	double fRec216[2];
	double fRec214[2];
	double fRec213[2];
	double fRec211[2];
	double fRec210[2];
	double fRec208[2];
	double fRec207[2];
	double fRec205[2];
	double fConst103;
	double fConst104;
	double fConst105;
	double fConst106;
	double fConst107;
	double fConst108;
	double fConst109;
	double fRec231[2];
	double fRec229[2];
	double fRec228[2];
	double fRec226[2];
	double fRec225[2];
	double fRec223[2];
	double fRec222[2];
	double fRec220[2];
	double fConst110;
	double fConst111;
	double fConst112;
	double fConst113;
	double fConst114;
	double fConst115;
	double fRec240[2];
	double fRec238[2];
	double fRec237[2];
	double fRec235[2];
	double fRec234[2];
	double fRec232[2];
	double fConst116;
	double fConst117;
	double fConst118;
	double fRec243[2];
	double fRec241[2];
	double fConst119;
	double fConst120;
	double fConst121;
	double fConst122;
	double fRec249[2];
	double fRec247[2];
	double fRec246[2];
	double fRec244[2];
	double fVec2[16];
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
	double fConst133;
	double fRec267[2];
	double fRec265[2];
	double fRec264[2];
	double fRec262[2];
	double fRec261[2];
	double fRec259[2];
	double fRec258[2];
	double fRec256[2];
	double fRec255[2];
	double fRec253[2];
	double fRec252[2];
	double fRec250[2];
	double fConst134;
	double fConst135;
	double fConst136;
	double fConst137;
	double fConst138;
	double fConst139;
	double fConst140;
	double fConst141;
	double fConst142;
	double fRec282[2];
	double fRec280[2];
	double fRec279[2];
	double fRec277[2];
	double fRec276[2];
	double fRec274[2];
	double fRec273[2];
	double fRec271[2];
	double fRec270[2];
	double fRec268[2];
	double fConst143;
	double fConst144;
	double fConst145;
	double fConst146;
	double fConst147;
	double fConst148;
	double fConst149;
	double fRec294[2];
	double fRec292[2];
	double fRec291[2];
	double fRec289[2];
	double fRec288[2];
	double fRec286[2];
	double fRec285[2];
	double fRec283[2];
	double fConst150;
	double fConst151;
	double fConst152;
	double fConst153;
	double fConst154;
	double fConst155;
	double fRec303[2];
	double fRec301[2];
	double fRec300[2];
	double fRec298[2];
	double fRec297[2];
	double fRec295[2];
	double fConst156;
	double fConst157;
	double fConst158;
	double fRec306[2];
	double fRec304[2];
	double fConst159;
	double fConst160;
	double fConst161;
	double fConst162;
	double fRec312[2];
	double fRec310[2];
	double fRec309[2];
	double fRec307[2];
	double fVec3[64];
	int iConst163;
	double fConst164;
	double fConst165;
	double fConst166;
	double fConst167;
	double fConst168;
	double fConst169;
	double fConst170;
	double fConst171;
	double fConst172;
	double fConst173;
	double fRec330[2];
	double fRec328[2];
	double fRec327[2];
	double fRec325[2];
	double fRec324[2];
	double fRec322[2];
	double fRec321[2];
	double fRec319[2];
	double fRec318[2];
	double fRec316[2];
	double fRec315[2];
	double fRec313[2];
	double fConst174;
	double fConst175;
	double fConst176;
	double fConst177;
	double fConst178;
	double fConst179;
	double fConst180;
	double fConst181;
	double fConst182;
	double fRec345[2];
	double fRec343[2];
	double fRec342[2];
	double fRec340[2];
	double fRec339[2];
	double fRec337[2];
	double fRec336[2];
	double fRec334[2];
	double fRec333[2];
	double fRec331[2];
	double fConst183;
	double fConst184;
	double fConst185;
	double fConst186;
	double fConst187;
	double fConst188;
	double fConst189;
	double fRec357[2];
	double fRec355[2];
	double fRec354[2];
	double fRec352[2];
	double fRec351[2];
	double fRec349[2];
	double fRec348[2];
	double fRec346[2];
	double fConst190;
	double fConst191;
	double fConst192;
	double fConst193;
	double fConst194;
	double fConst195;
	double fRec366[2];
	double fRec364[2];
	double fRec363[2];
	double fRec361[2];
	double fRec360[2];
	double fRec358[2];
	double fConst196;
	double fConst197;
	double fConst198;
	double fRec369[2];
	double fRec367[2];
	double fConst199;
	double fConst200;
	double fConst201;
	double fConst202;
	double fRec375[2];
	double fRec373[2];
	double fRec372[2];
	double fRec370[2];
	double fVec4[8];
	int iConst203;
	double fConst204;
	double fConst205;
	double fConst206;
	double fConst207;
	double fConst208;
	double fConst209;
	double fConst210;
	double fConst211;
	double fConst212;
	double fConst213;
	double fRec393[2];
	double fRec391[2];
	double fRec390[2];
	double fRec388[2];
	double fRec387[2];
	double fRec385[2];
	double fRec384[2];
	double fRec382[2];
	double fRec381[2];
	double fRec379[2];
	double fRec378[2];
	double fRec376[2];
	double fConst214;
	double fConst215;
	double fConst216;
	double fConst217;
	double fConst218;
	double fConst219;
	double fConst220;
	double fConst221;
	double fConst222;
	double fRec408[2];
	double fRec406[2];
	double fRec405[2];
	double fRec403[2];
	double fRec402[2];
	double fRec400[2];
	double fRec399[2];
	double fRec397[2];
	double fRec396[2];
	double fRec394[2];
	double fConst223;
	double fConst224;
	double fConst225;
	double fConst226;
	double fConst227;
	double fConst228;
	double fConst229;
	double fRec420[2];
	double fRec418[2];
	double fRec417[2];
	double fRec415[2];
	double fRec414[2];
	double fRec412[2];
	double fRec411[2];
	double fRec409[2];
	double fConst230;
	double fConst231;
	double fConst232;
	double fConst233;
	double fConst234;
	double fConst235;
	double fRec429[2];
	double fRec427[2];
	double fRec426[2];
	double fRec424[2];
	double fRec423[2];
	double fRec421[2];
	double fConst236;
	double fConst237;
	double fConst238;
	double fRec432[2];
	double fRec430[2];
	double fConst239;
	double fConst240;
	double fConst241;
	double fConst242;
	double fRec438[2];
	double fRec436[2];
	double fRec435[2];
	double fRec433[2];
	double fConst243;
	double fConst244;
	double fConst245;
	double fConst246;
	double fConst247;
	double fConst248;
	double fConst249;
	double fConst250;
	double fConst251;
	double fConst252;
	double fRec456[2];
	double fRec454[2];
	double fRec453[2];
	double fRec451[2];
	double fRec450[2];
	double fRec448[2];
	double fRec447[2];
	double fRec445[2];
	double fRec444[2];
	double fRec442[2];
	double fRec441[2];
	double fRec439[2];
	double fConst253;
	double fConst254;
	double fConst255;
	double fConst256;
	double fConst257;
	double fConst258;
	double fConst259;
	double fConst260;
	double fConst261;
	double fRec471[2];
	double fRec469[2];
	double fRec468[2];
	double fRec466[2];
	double fRec465[2];
	double fRec463[2];
	double fRec462[2];
	double fRec460[2];
	double fRec459[2];
	double fRec457[2];
	double fConst262;
	double fConst263;
	double fConst264;
	double fConst265;
	double fConst266;
	double fConst267;
	double fConst268;
	double fRec483[2];
	double fRec481[2];
	double fRec480[2];
	double fRec478[2];
	double fRec477[2];
	double fRec475[2];
	double fRec474[2];
	double fRec472[2];
	double fConst269;
	double fConst270;
	double fConst271;
	double fConst272;
	double fConst273;
	double fConst274;
	double fRec492[2];
	double fRec490[2];
	double fRec489[2];
	double fRec487[2];
	double fRec486[2];
	double fRec484[2];
	double fConst275;
	double fConst276;
	double fConst277;
	double fRec495[2];
	double fRec493[2];
	double fConst278;
	double fConst279;
	double fConst280;
	double fConst281;
	double fRec501[2];
	double fRec499[2];
	double fRec498[2];
	double fRec496[2];
	double fVec5[128];
	int iConst282;
	double fConst283;
	double fConst284;
	double fConst285;
	double fConst286;
	double fConst287;
	double fConst288;
	double fConst289;
	double fConst290;
	double fConst291;
	double fConst292;
	double fRec519[2];
	double fRec517[2];
	double fRec516[2];
	double fRec514[2];
	double fRec513[2];
	double fRec511[2];
	double fRec510[2];
	double fRec508[2];
	double fRec507[2];
	double fRec505[2];
	double fRec504[2];
	double fRec502[2];
	double fConst293;
	double fConst294;
	double fConst295;
	double fConst296;
	double fConst297;
	double fConst298;
	double fConst299;
	double fConst300;
	double fConst301;
	double fRec534[2];
	double fRec532[2];
	double fRec531[2];
	double fRec529[2];
	double fRec528[2];
	double fRec526[2];
	double fRec525[2];
	double fRec523[2];
	double fRec522[2];
	double fRec520[2];
	double fConst302;
	double fConst303;
	double fConst304;
	double fConst305;
	double fConst306;
	double fConst307;
	double fConst308;
	double fRec546[2];
	double fRec544[2];
	double fRec543[2];
	double fRec541[2];
	double fRec540[2];
	double fRec538[2];
	double fRec537[2];
	double fRec535[2];
	double fConst309;
	double fConst310;
	double fConst311;
	double fConst312;
	double fConst313;
	double fConst314;
	double fRec555[2];
	double fRec553[2];
	double fRec552[2];
	double fRec550[2];
	double fRec549[2];
	double fRec547[2];
	double fConst315;
	double fConst316;
	double fConst317;
	double fRec558[2];
	double fRec556[2];
	double fConst318;
	double fConst319;
	double fConst320;
	double fConst321;
	double fRec564[2];
	double fRec562[2];
	double fRec561[2];
	double fRec559[2];
	double fVec6[64];
	int iConst322;
	double fConst323;
	double fConst324;
	double fConst325;
	double fConst326;
	double fConst327;
	double fConst328;
	double fConst329;
	double fConst330;
	double fConst331;
	double fConst332;
	double fRec582[2];
	double fRec580[2];
	double fRec579[2];
	double fRec577[2];
	double fRec576[2];
	double fRec574[2];
	double fRec573[2];
	double fRec571[2];
	double fRec570[2];
	double fRec568[2];
	double fRec567[2];
	double fRec565[2];
	double fConst333;
	double fConst334;
	double fConst335;
	double fConst336;
	double fConst337;
	double fConst338;
	double fConst339;
	double fConst340;
	double fConst341;
	double fRec597[2];
	double fRec595[2];
	double fRec594[2];
	double fRec592[2];
	double fRec591[2];
	double fRec589[2];
	double fRec588[2];
	double fRec586[2];
	double fRec585[2];
	double fRec583[2];
	double fConst342;
	double fConst343;
	double fConst344;
	double fConst345;
	double fConst346;
	double fConst347;
	double fConst348;
	double fRec609[2];
	double fRec607[2];
	double fRec606[2];
	double fRec604[2];
	double fRec603[2];
	double fRec601[2];
	double fRec600[2];
	double fRec598[2];
	double fConst349;
	double fConst350;
	double fConst351;
	double fConst352;
	double fConst353;
	double fConst354;
	double fRec618[2];
	double fRec616[2];
	double fRec615[2];
	double fRec613[2];
	double fRec612[2];
	double fRec610[2];
	double fConst355;
	double fConst356;
	double fConst357;
	double fRec621[2];
	double fRec619[2];
	double fConst358;
	double fConst359;
	double fConst360;
	double fConst361;
	double fRec627[2];
	double fRec625[2];
	double fRec624[2];
	double fRec622[2];
	double fVec7[256];
	int iConst362;
	double fRec645[2];
	double fRec643[2];
	double fRec642[2];
	double fRec640[2];
	double fRec639[2];
	double fRec637[2];
	double fRec636[2];
	double fRec634[2];
	double fRec633[2];
	double fRec631[2];
	double fRec630[2];
	double fRec628[2];
	double fRec660[2];
	double fRec658[2];
	double fRec657[2];
	double fRec655[2];
	double fRec654[2];
	double fRec652[2];
	double fRec651[2];
	double fRec649[2];
	double fRec648[2];
	double fRec646[2];
	double fRec672[2];
	double fRec670[2];
	double fRec669[2];
	double fRec667[2];
	double fRec666[2];
	double fRec664[2];
	double fRec663[2];
	double fRec661[2];
	double fRec681[2];
	double fRec679[2];
	double fRec678[2];
	double fRec676[2];
	double fRec675[2];
	double fRec673[2];
	double fRec684[2];
	double fRec682[2];
	double fRec690[2];
	double fRec688[2];
	double fRec687[2];
	double fRec685[2];
	double fVec8[256];
	double fConst363;
	double fConst364;
	double fConst365;
	double fConst366;
	double fConst367;
	double fRec702[2];
	double fRec700[2];
	double fRec699[2];
	double fRec697[2];
	double fConst368;
	double fConst369;
	double fRec696[2];
	double fRec694[2];
	double fRec693[2];
	double fRec691[2];
	double fConst370;
	double fConst371;
	double fConst372;
	double fConst373;
	double fConst374;
	double fConst375;
	double fRec711[2];
	double fRec709[2];
	double fRec708[2];
	double fRec706[2];
	double fRec705[2];
	double fRec703[2];
	double fConst376;
	double fConst377;
	double fConst378;
	double fRec714[2];
	double fRec712[2];
	double fConst379;
	double fConst380;
	double fConst381;
	double fConst382;
	double fRec720[2];
	double fRec718[2];
	double fRec717[2];
	double fRec715[2];
	double fConst383;
	double fConst384;
	double fConst385;
	double fConst386;
	double fConst387;
	double fConst388;
	double fConst389;
	double fConst390;
	double fConst391;
	double fRec735[2];
	double fRec733[2];
	double fRec732[2];
	double fRec730[2];
	double fRec729[2];
	double fRec727[2];
	double fRec726[2];
	double fRec724[2];
	double fRec723[2];
	double fRec721[2];
	double fConst392;
	double fConst393;
	double fConst394;
	double fConst395;
	double fConst396;
	double fConst397;
	double fConst398;
	double fConst399;
	double fConst400;
	double fConst401;
	double fRec753[2];
	double fRec751[2];
	double fRec750[2];
	double fRec748[2];
	double fRec747[2];
	double fRec745[2];
	double fRec744[2];
	double fRec742[2];
	double fRec741[2];
	double fRec739[2];
	double fRec738[2];
	double fRec736[2];
	double fVec9[256];
	int iConst402;
	double fRec756[2];
	double fRec754[2];
	double fRec762[2];
	double fRec760[2];
	double fRec759[2];
	double fRec757[2];
	double fRec771[2];
	double fRec769[2];
	double fRec768[2];
	double fRec766[2];
	double fRec765[2];
	double fRec763[2];
	double fRec783[2];
	double fRec781[2];
	double fRec780[2];
	double fRec778[2];
	double fRec777[2];
	double fRec775[2];
	double fRec774[2];
	double fRec772[2];
	double fRec798[2];
	double fRec796[2];
	double fRec795[2];
	double fRec793[2];
	double fRec792[2];
	double fRec790[2];
	double fRec789[2];
	double fRec787[2];
	double fRec786[2];
	double fRec784[2];
	double fRec816[2];
	double fRec814[2];
	double fRec813[2];
	double fRec811[2];
	double fRec810[2];
	double fRec808[2];
	double fRec807[2];
	double fRec805[2];
	double fRec804[2];
	double fRec802[2];
	double fRec801[2];
	double fRec799[2];
	double fVec10[256];
	double fConst403;
	double fConst404;
	double fConst405;
	double fRec819[2];
	double fRec817[2];
	double fConst406;
	double fConst407;
	double fConst408;
	double fConst409;
	double fRec825[2];
	double fRec823[2];
	double fRec822[2];
	double fRec820[2];
	double fConst410;
	double fConst411;
	double fConst412;
	double fConst413;
	double fConst414;
	double fConst415;
	double fRec834[2];
	double fRec832[2];
	double fRec831[2];
	double fRec829[2];
	double fRec828[2];
	double fRec826[2];
	double fConst416;
	double fConst417;
	double fConst418;
	double fConst419;
	double fConst420;
	double fConst421;
	double fConst422;
	double fRec846[2];
	double fRec844[2];
	double fRec843[2];
	double fRec841[2];
	double fRec840[2];
	double fRec838[2];
	double fRec837[2];
	double fRec835[2];
	double fConst423;
	double fConst424;
	double fConst425;
	double fConst426;
	double fConst427;
	double fConst428;
	double fConst429;
	double fConst430;
	double fConst431;
	double fRec861[2];
	double fRec859[2];
	double fRec858[2];
	double fRec856[2];
	double fRec855[2];
	double fRec853[2];
	double fRec852[2];
	double fRec850[2];
	double fRec849[2];
	double fRec847[2];
	double fConst432;
	double fConst433;
	double fConst434;
	double fConst435;
	double fConst436;
	double fConst437;
	double fConst438;
	double fConst439;
	double fConst440;
	double fConst441;
	double fRec879[2];
	double fRec877[2];
	double fRec876[2];
	double fRec874[2];
	double fRec873[2];
	double fRec871[2];
	double fRec870[2];
	double fRec868[2];
	double fRec867[2];
	double fRec865[2];
	double fRec864[2];
	double fRec862[2];
	double fVec11[1024];
	int iConst442;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "AmbisonicDecoderToolkit");
		m->declare("copyright", "(c) Aaron J. Heller 2013");
		m->declare("filename", "KMH114_AE_7h7v_normal_4");
		m->declare("license", "BSD 3-Clause License");
		m->declare("name", "KMH114_AE_7h7v_normal_4");
		m->declare("version", "1.2");
	}

	virtual int getNumInputs() {
		return 64;
		
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
				rate = 0;
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
				rate = 0;
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
				rate = 0;
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
			case 36: {
				rate = 1;
				break;
			}
			case 37: {
				rate = 1;
				break;
			}
			case 38: {
				rate = 1;
				break;
			}
			case 39: {
				rate = 1;
				break;
			}
			case 40: {
				rate = 1;
				break;
			}
			case 41: {
				rate = 1;
				break;
			}
			case 42: {
				rate = 1;
				break;
			}
			case 43: {
				rate = 1;
				break;
			}
			case 44: {
				rate = 1;
				break;
			}
			case 45: {
				rate = 1;
				break;
			}
			case 46: {
				rate = 1;
				break;
			}
			case 47: {
				rate = 1;
				break;
			}
			case 48: {
				rate = 1;
				break;
			}
			case 49: {
				rate = 1;
				break;
			}
			case 50: {
				rate = 1;
				break;
			}
			case 51: {
				rate = 1;
				break;
			}
			case 52: {
				rate = 0;
				break;
			}
			case 53: {
				rate = 1;
				break;
			}
			case 54: {
				rate = 1;
				break;
			}
			case 55: {
				rate = 1;
				break;
			}
			case 56: {
				rate = 1;
				break;
			}
			case 57: {
				rate = 1;
				break;
			}
			case 58: {
				rate = 0;
				break;
			}
			case 59: {
				rate = 1;
				break;
			}
			case 60: {
				rate = 1;
				break;
			}
			case 61: {
				rate = 1;
				break;
			}
			case 62: {
				rate = 0;
				break;
			}
			case 63: {
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
		fConst3 = mydsp_faustpower2_f(fConst2);
		fConst4 = ((((52097.914652354157 / fConst2) + 447.26965247582257) / fConst2) + 1.0);
		fConst5 = (0.0 - (208391.65860941663 / (fConst3 * fConst4)));
		fConst6 = (0.0 - (((208391.65860941663 / fConst2) + 894.53930495164514) / (fConst2 * fConst4)));
		fConst7 = ((((57783.152825889571 / fConst2) + 393.29746440751228) / fConst2) + 1.0);
		fConst8 = (0.0 - (231132.61130355828 / (fConst3 * fConst7)));
		fConst9 = (0.0 - (((231132.61130355828 / fConst2) + 786.59492881502456) / (fConst2 * fConst7)));
		fConst10 = ((((73470.338546123472 / fConst2) + 264.87875372002947) / fConst2) + 1.0);
		fConst11 = (1.0 / ((fConst4 * fConst7) * fConst10));
		fConst12 = (0.0 - (293881.35418449389 / (fConst3 * fConst10)));
		fConst13 = (0.0 - (((293881.35418449389 / fConst2) + 529.75750744005893) / (fConst2 * fConst10)));
		fConst14 = ((191.96533911319742 / fConst2) + 1.0);
		fConst15 = (0.0 - (383.93067822639483 / (fConst2 * fConst14)));
		fConst16 = ((((39549.029677540268 / fConst2) + 352.89584379873679) / fConst2) + 1.0);
		fConst17 = (0.0 - (158196.11871016107 / (fConst3 * fConst16)));
		fConst18 = (0.0 - (((158196.11871016107 / fConst2) + 705.79168759747358) / (fConst2 * fConst16)));
		fConst19 = ((((50311.132146818818 / fConst2) + 244.74301037618173) / fConst2) + 1.0);
		fConst20 = (1.0 / ((fConst14 * fConst16) * fConst19));
		fConst21 = (0.0 - (201244.52858727527 / (fConst3 * fConst19)));
		fConst22 = (0.0 - (((201244.52858727527 / fConst2) + 489.48602075236346) / (fConst2 * fConst19)));
		fConst23 = ((((25327.293843552216 / fConst2) + 304.91467155099616) / fConst2) + 1.0);
		fConst24 = (0.0 - (101309.17537420886 / (fConst3 * fConst23)));
		fConst25 = (0.0 - (((101309.17537420886 / fConst2) + 609.82934310199232) / (fConst2 * fConst23)));
		fConst26 = ((((31832.683993978117 / fConst2) + 221.48812397441478) / fConst2) + 1.0);
		fConst27 = (1.0 / (fConst23 * fConst26));
		fConst28 = (0.0 - (127330.73597591247 / (fConst3 * fConst26)));
		fConst29 = (0.0 - (((127330.73597591247 / fConst2) + 442.97624794882955) / (fConst2 * fConst26)));
		fConst30 = ((122.24048624033396 / fConst2) + 1.0);
		fConst31 = (0.0 - (244.48097248066793 / (fConst2 * fConst30)));
		fConst32 = ((((17899.081736840039 / fConst2) + 193.60119107491266) / fConst2) + 1.0);
		fConst33 = (1.0 / (fConst30 * fConst32));
		fConst34 = (0.0 - (71596.326947360154 / (fConst3 * fConst32)));
		fConst35 = (0.0 - (((71596.326947360154 / fConst2) + 387.20238214982533) / (fConst2 * fConst32)));
		fConst36 = ((52.640279552541102 / fConst2) + 1.0);
		fConst37 = (1.0 / fConst36);
		fConst38 = (0.0 - (105.2805591050822 / (fConst2 * fConst36)));
		fConst39 = ((((8312.9970941090305 / fConst2) + 157.92083865762331) / fConst2) + 1.0);
		fConst40 = (1.0 / fConst39);
		fConst41 = (0.0 - (33251.988376436122 / (fConst3 * fConst39)));
		fConst42 = (0.0 - (((33251.988376436122 / fConst2) + 315.84167731524661) / (fConst2 * fConst39)));
		iConst43 = int(((0.00033798093768075285 * double(iConst0)) + 0.5));
		fConst44 = ((((50842.589325928289 / fConst2) + 441.84820214278227) / fConst2) + 1.0);
		fConst45 = (0.0 - (203370.35730371316 / (fConst3 * fConst44)));
		fConst46 = (0.0 - (((203370.35730371316 / fConst2) + 883.69640428556454) / (fConst2 * fConst44)));
		fConst47 = ((((56390.838840442979 / fConst2) + 388.53022241469392) / fConst2) + 1.0);
		fConst48 = (0.0 - (225563.35536177192 / (fConst3 * fConst47)));
		fConst49 = (0.0 - (((225563.35536177192 / fConst2) + 777.06044482938785) / (fConst2 * fConst47)));
		fConst50 = ((((71700.033969952419 / fConst2) + 261.66810215978671) / fConst2) + 1.0);
		fConst51 = (1.0 / ((fConst44 * fConst47) * fConst50));
		fConst52 = (0.0 - (286800.13587980968 / (fConst3 * fConst50)));
		fConst53 = (0.0 - (((286800.13587980968 / fConst2) + 523.33620431957343) / (fConst2 * fConst50)));
		fConst54 = ((189.63848651788592 / fConst2) + 1.0);
		fConst55 = (0.0 - (379.27697303577185 / (fConst2 * fConst54)));
		fConst56 = ((((38596.076014786682 / fConst2) + 348.61831841935816) / fConst2) + 1.0);
		fConst57 = (0.0 - (154384.30405914673 / (fConst3 * fConst56)));
		fConst58 = (0.0 - (((154384.30405914673 / fConst2) + 697.23663683871632) / (fConst2 * fConst56)));
		fConst59 = ((((49098.860239075453 / fConst2) + 241.77642843222799) / fConst2) + 1.0);
		fConst60 = (1.0 / ((fConst54 * fConst56) * fConst59));
		fConst61 = (0.0 - (196395.44095630181 / (fConst3 * fConst59)));
		fConst62 = (0.0 - (((196395.44095630181 / fConst2) + 483.55285686445598) / (fConst2 * fConst59)));
		fConst63 = ((((24717.020023116213 / fConst2) + 301.21873613825682) / fConst2) + 1.0);
		fConst64 = (0.0 - (98868.08009246485 / (fConst3 * fConst63)));
		fConst65 = (0.0 - (((98868.08009246485 / fConst2) + 602.43747227651363) / (fConst2 * fConst63)));
		fConst66 = ((((31065.659542185662 / fConst2) + 218.80341944139155) / fConst2) + 1.0);
		fConst67 = (1.0 / (fConst63 * fConst66));
		fConst68 = (0.0 - (124262.63816874265 / (fConst3 * fConst66)));
		fConst69 = (0.0 - (((124262.63816874265 / fConst2) + 437.60683888278311) / (fConst2 * fConst66)));
		fConst70 = ((120.75878337681476 / fConst2) + 1.0);
		fConst71 = (0.0 - (241.51756675362952 / (fConst2 * fConst70)));
		fConst72 = ((((17467.794404631881 / fConst2) + 191.25450997097431) / fConst2) + 1.0);
		fConst73 = (1.0 / (fConst70 * fConst72));
		fConst74 = (0.0 - (69871.177618527523 / (fConst3 * fConst72)));
		fConst75 = (0.0 - (((69871.177618527523 / fConst2) + 382.50901994194862) / (fConst2 * fConst72)));
		fConst76 = ((52.002215557964846 / fConst2) + 1.0);
		fConst77 = (1.0 / fConst76);
		fConst78 = (0.0 - (104.00443111592969 / (fConst2 * fConst76)));
		fConst79 = ((((8112.6912688111233 / fConst2) + 156.00664667389452) / fConst2) + 1.0);
		fConst80 = (1.0 / fConst79);
		fConst81 = (0.0 - (32450.765075244493 / (fConst3 * fConst79)));
		fConst82 = (0.0 - (((32450.765075244493 / fConst2) + 312.01329334778904) / (fConst2 * fConst79)));
		iConst83 = int(((0.00022143578675635532 * double(iConst0)) + 0.5));
		fConst84 = ((((49336.226131375268 / fConst2) + 435.25345285706908) / fConst2) + 1.0);
		fConst85 = (0.0 - (197344.90452550107 / (fConst3 * fConst84)));
		fConst86 = (0.0 - (((197344.90452550107 / fConst2) + 870.50690571413816) / (fConst2 * fConst84)));
		fConst87 = ((((54720.092222982748 / fConst2) + 382.731263871191) / fConst2) + 1.0);
		fConst88 = (0.0 - (218880.36889193099 / (fConst3 * fConst87)));
		fConst89 = (0.0 - (((218880.36889193099 / fConst2) + 765.46252774238201) / (fConst2 * fConst87)));
		fConst90 = ((((69575.706832950033 / fConst2) + 257.76260809770031) / fConst2) + 1.0);
		fConst91 = (1.0 / ((fConst84 * fConst87) * fConst90));
		fConst92 = (0.0 - (278302.82733180013 / (fConst3 * fConst90)));
		fConst93 = (0.0 - (((278302.82733180013 / fConst2) + 515.52521619540062) / (fConst2 * fConst90)));
		fConst94 = ((186.80806134597717 / fConst2) + 1.0);
		fConst95 = (0.0 - (373.61612269195433 / (fConst2 * fConst94)));
		fConst96 = ((((37452.552265629485 / fConst2) + 343.41505993548714) / fConst2) + 1.0);
		fConst97 = (0.0 - (149810.20906251794 / (fConst3 * fConst96)));
		fConst98 = (0.0 - (((149810.20906251794 / fConst2) + 686.83011987097427) / (fConst2 * fConst96)));
		fConst99 = ((((47644.160214170784 / fConst2) + 238.16782502279173) / fConst2) + 1.0);
		fConst100 = (1.0 / ((fConst94 * fConst96) * fConst99));
		fConst101 = (0.0 - (190576.64085668314 / (fConst3 * fConst99)));
		fConst102 = (0.0 - (((190576.64085668314 / fConst2) + 476.33565004558346) / (fConst2 * fConst99)));
		fConst103 = ((((23984.704660435331 / fConst2) + 296.72293410634251) / fConst2) + 1.0);
		fConst104 = (0.0 - (95938.818641741324 / (fConst3 * fConst103)));
		fConst105 = (0.0 - (((95938.818641741324 / fConst2) + 593.44586821268501) / (fConst2 * fConst103)));
		fConst106 = ((((30145.246817946248 / fConst2) + 215.53769676316182) / fConst2) + 1.0);
		fConst107 = (1.0 / (fConst103 * fConst106));
		fConst108 = (0.0 - (120580.98727178499 / (fConst3 * fConst106)));
		fConst109 = (0.0 - (((120580.98727178499 / fConst2) + 431.07539352632364) / (fConst2 * fConst106)));
		fConst110 = ((118.95641347566826 / fConst2) + 1.0);
		fConst111 = (0.0 - (237.91282695133651 / (fConst2 * fConst110)));
		fConst112 = ((((16950.258950005893 / fConst2) + 188.39996504603437) / fConst2) + 1.0);
		fConst113 = (1.0 / (fConst110 * fConst112));
		fConst114 = (0.0 - (67801.035800023572 / (fConst3 * fConst112)));
		fConst115 = (0.0 - (((67801.035800023572 / fConst2) + 376.79993009206873) / (fConst2 * fConst112)));
		fConst116 = ((51.22606308695044 / fConst2) + 1.0);
		fConst117 = (1.0 / fConst116);
		fConst118 = (0.0 - (102.45212617390088 / (fConst2 * fConst116)));
		fConst119 = ((((7872.3286181646799 / fConst2) + 153.67818926085133) / fConst2) + 1.0);
		fConst120 = (1.0 / fConst119);
		fConst121 = (0.0 - (31489.31447265872 / (fConst3 * fConst119)));
		fConst122 = (0.0 - (((31489.31447265872 / fConst2) + 307.35637852170265) / (fConst2 * fConst119)));
		iConst123 = int(((7.5754348100857757e-05 * double(iConst0)) + 0.5));
		fConst124 = ((((51779.76019221716 / fConst2) + 445.90185537344991) / fConst2) + 1.0);
		fConst125 = (0.0 - (207119.04076886864 / (fConst3 * fConst124)));
		fConst126 = (0.0 - (((207119.04076886864 / fConst2) + 891.80371074689981) / (fConst2 * fConst124)));
		fConst127 = ((((57430.27943517884 / fConst2) + 392.0947198680397) / fConst2) + 1.0);
		fConst128 = (0.0 - (229721.11774071536 / (fConst3 * fConst127)));
		fConst129 = (0.0 - (((229721.11774071536 / fConst2) + 784.18943973607941) / (fConst2 * fConst127)));
		fConst130 = ((((73021.665771940417 / fConst2) + 264.06872695024339) / fConst2) + 1.0);
		fConst131 = (1.0 / ((fConst124 * fConst127) * fConst130));
		fConst132 = (0.0 - (292086.66308776167 / (fConst3 * fConst130)));
		fConst133 = (0.0 - (((292086.66308776167 / fConst2) + 528.13745390048678) / (fConst2 * fConst130)));
		fConst134 = ((191.37828914649037 / fConst2) + 1.0);
		fConst135 = (0.0 - (382.75657829298075 / (fConst2 * fConst134)));
		fConst136 = ((((39307.50945029196 / fConst2) + 351.81665161586596) / fConst2) + 1.0);
		fConst137 = (0.0 - (157230.03780116784 / (fConst3 * fConst136)));
		fConst138 = (0.0 - (((157230.03780116784 / fConst2) + 703.63330323173193) / (fConst2 * fConst136)));
		fConst139 = ((((50003.889310059159 / fConst2) + 243.99456080316583) / fConst2) + 1.0);
		fConst140 = (1.0 / ((fConst134 * fConst136) * fConst139));
		fConst141 = (0.0 - (200015.55724023664 / (fConst3 * fConst139)));
		fConst142 = (0.0 - (((200015.55724023664 / fConst2) + 487.98912160633165) / (fConst2 * fConst139)));
		fConst143 = ((((25172.623708417312 / fConst2) + 303.98221078172702) / fConst2) + 1.0);
		fConst144 = (0.0 - (100690.49483366925 / (fConst3 * fConst143)));
		fConst145 = (0.0 - (((100690.49483366925 / fConst2) + 607.96442156345404) / (fConst2 * fConst143)));
		fConst146 = ((((31638.286378288562 / fConst2) + 220.81079026195476) / fConst2) + 1.0);
		fConst147 = (1.0 / (fConst143 * fConst146));
		fConst148 = (0.0 - (126553.14551315425 / (fConst3 * fConst146)));
		fConst149 = (0.0 - (((126553.14551315425 / fConst2) + 441.62158052390953) / (fConst2 * fConst146)));
		fConst150 = ((121.86666212339102 / fConst2) + 1.0);
		fConst151 = (0.0 - (243.73332424678205 / (fConst2 * fConst150)));
		fConst152 = ((((17789.774623015379 / fConst2) + 193.00913850281808) / fConst2) + 1.0);
		fConst153 = (1.0 / (fConst150 * fConst152));
		fConst154 = (0.0 - (71159.098492061516 / (fConst3 * fConst152)));
		fConst155 = (0.0 - (((71159.098492061516 / fConst2) + 386.01827700563615) / (fConst2 * fConst152)));
		fConst156 = ((52.479300104368185 / fConst2) + 1.0);
		fConst157 = (1.0 / fConst156);
		fConst158 = (0.0 - (104.95860020873637 / (fConst2 * fConst156)));
		fConst159 = ((((8262.2308183330169 / fConst2) + 157.43790031310456) / fConst2) + 1.0);
		fConst160 = (1.0 / fConst159);
		fConst161 = (0.0 - (33048.923273332068 / (fConst3 * fConst159)));
		fConst162 = (0.0 - (((33048.923273332068 / fConst2) + 314.87580062620913) / (fConst2 * fConst159)));
		iConst163 = int(((0.00030884464994965281 * double(iConst0)) + 0.5));
		fConst164 = ((((48926.434274298248 / fConst2) + 433.4420532316235) / fConst2) + 1.0);
		fConst165 = (0.0 - (195705.73709719299 / (fConst3 * fConst164)));
		fConst166 = (0.0 - (((195705.73709719299 / fConst2) + 866.88410646324701) / (fConst2 * fConst164)));
		fConst167 = ((((54265.581410749757 / fConst2) + 381.13844648290427) / fConst2) + 1.0);
		fConst168 = (0.0 - (217062.32564299903 / (fConst3 * fConst167)));
		fConst169 = (0.0 - (((217062.32564299903 / fConst2) + 762.27689296580854) / (fConst2 * fConst167)));
		fConst170 = ((((68997.803731188687 / fConst2) + 256.68987429467779) / fConst2) + 1.0);
		fConst171 = (1.0 / ((fConst164 * fConst167) * fConst170));
		fConst172 = (0.0 - (275991.21492475475 / (fConst3 * fConst170)));
		fConst173 = (0.0 - (((275991.21492475475 / fConst2) + 513.37974858935559) / (fConst2 * fConst170)));
		fConst174 = ((186.03061994917465 / fConst2) + 1.0);
		fConst175 = (0.0 - (372.0612398983493 / (fConst2 * fConst174)));
		fConst176 = ((((37141.467447258146 / fConst2) + 341.98586527463789) / fConst2) + 1.0);
		fConst177 = (0.0 - (148565.86978903259 / (fConst3 * fConst176)));
		fConst178 = (0.0 - (((148565.86978903259 / fConst2) + 683.97173054927578) / (fConst2 * fConst176)));
		fConst179 = ((((47248.422833669691 / fConst2) + 237.17663906847574) / fConst2) + 1.0);
		fConst180 = (1.0 / ((fConst174 * fConst176) * fConst179));
		fConst181 = (0.0 - (188993.69133467876 / (fConst3 * fConst179)));
		fConst182 = (0.0 - (((188993.69133467876 / fConst2) + 474.35327813695147) / (fConst2 * fConst179)));
		fConst183 = ((((23785.485193626679 / fConst2) + 295.48805863741006) / fConst2) + 1.0);
		fConst184 = (0.0 - (95141.940774506715 / (fConst3 * fConst183)));
		fConst185 = (0.0 - (((95141.940774506715 / fConst2) + 590.97611727482013) / (fConst2 * fConst183)));
		fConst186 = ((((29894.857243302333 / fConst2) + 214.64069089078245) / fConst2) + 1.0);
		fConst187 = (1.0 / (fConst183 * fConst186));
		fConst188 = (0.0 - (119579.42897320933 / (fConst3 * fConst186)));
		fConst189 = (0.0 - (((119579.42897320933 / fConst2) + 429.2813817815649) / (fConst2 * fConst186)));
		fConst190 = ((118.46135111280877 / fConst2) + 1.0);
		fConst191 = (0.0 - (236.92270222561754 / (fConst2 * fConst190)));
		fConst192 = ((((16809.468325393405 / fConst2) + 187.61589860410677) / fConst2) + 1.0);
		fConst193 = (1.0 / (fConst190 * fConst192));
		fConst194 = (0.0 - (67237.873301573622 / (fConst3 * fConst192)));
		fConst195 = (0.0 - (((67237.873301573622 / fConst2) + 375.23179720821355) / (fConst2 * fConst192)));
		fConst196 = ((51.01287495281926 / fConst2) + 1.0);
		fConst197 = (1.0 / fConst196);
		fConst198 = (0.0 - (102.02574990563852 / (fConst2 * fConst196)));
		fConst199 = ((((7806.9402328559245 / fConst2) + 153.03862485845778) / fConst2) + 1.0);
		fConst200 = (1.0 / fConst199);
		fConst201 = (0.0 - (31227.760931423698 / (fConst3 * fConst199)));
		fConst202 = (0.0 - (((31227.760931423698 / fConst2) + 306.07724971691556) / (fConst2 * fConst199)));
		iConst203 = int(((3.4963545277319259e-05 * double(iConst0)) + 0.5));
		fConst204 = ((((48579.234181565917 / fConst2) + 431.9013824262978) / fConst2) + 1.0);
		fConst205 = (0.0 - (194316.93672626367 / (fConst3 * fConst204)));
		fConst206 = (0.0 - (((194316.93672626367 / fConst2) + 863.8027648525956) / (fConst2 * fConst204)));
		fConst207 = ((((53880.492753105973 / fConst2) + 379.78368897170907) / fConst2) + 1.0);
		fConst208 = (0.0 - (215521.97101242389 / (fConst3 * fConst207)));
		fConst209 = (0.0 - (((215521.97101242389 / fConst2) + 759.56737794341814) / (fConst2 * fConst207)));
		fConst210 = ((((68508.169769320753 / fConst2) + 255.7774695282275) / fConst2) + 1.0);
		fConst211 = (1.0 / ((fConst204 * fConst207) * fConst210));
		fConst212 = (0.0 - (274032.67907728301 / (fConst3 * fConst210)));
		fConst213 = (0.0 - (((274032.67907728301 / fConst2) + 511.554939056455) / (fConst2 * fConst210)));
		fConst214 = ((185.36937366973447 / fConst2) + 1.0);
		fConst215 = (0.0 - (370.73874733946894 / (fConst2 * fConst214)));
		fConst216 = ((((36877.897842540857 / fConst2) + 340.77027570612614) / fConst2) + 1.0);
		fConst217 = (0.0 - (147511.59137016343 / (fConst3 * fConst216)));
		fConst218 = (0.0 - (((147511.59137016343 / fConst2) + 681.54055141225228) / (fConst2 * fConst216)));
		fConst219 = ((((46913.130531407551 / fConst2) + 236.33359414287688) / fConst2) + 1.0);
		fConst220 = (1.0 / ((fConst214 * fConst216) * fConst219));
		fConst221 = (0.0 - (187652.5221256302 / (fConst3 * fConst219)));
		fConst222 = (0.0 - (((187652.5221256302 / fConst2) + 472.66718828575375) / (fConst2 * fConst219)));
		fConst223 = ((((23616.69458406352 / fConst2) + 294.43774563277469) / fConst2) + 1.0);
		fConst224 = (0.0 - (94466.778336254079 / (fConst3 * fConst223)));
		fConst225 = (0.0 - (((94466.778336254079 / fConst2) + 588.87549126554939) / (fConst2 * fConst223)));
		fConst226 = ((((29682.712267665982 / fConst2) + 213.87775004638394) / fConst2) + 1.0);
		fConst227 = (1.0 / (fConst223 * fConst226));
		fConst228 = (0.0 - (118730.84907066393 / (fConst3 * fConst226)));
		fConst229 = (0.0 - (((118730.84907066393 / fConst2) + 427.75550009276787) / (fConst2 * fConst226)));
		fConst230 = ((118.04027995956419 / fConst2) + 1.0);
		fConst231 = (0.0 - (236.08055991912838 / (fConst2 * fConst230)));
		fConst232 = ((((16690.182114413106 / fConst2) + 186.94901744793106) / fConst2) + 1.0);
		fConst233 = (1.0 / (fConst230 * fConst232));
		fConst234 = (0.0 - (66760.728457652425 / (fConst3 * fConst232)));
		fConst235 = (0.0 - (((66760.728457652425 / fConst2) + 373.89803489586211) / (fConst2 * fConst232)));
		fConst236 = ((50.831549567915872 / fConst2) + 1.0);
		fConst237 = (1.0 / fConst236);
		fConst238 = (0.0 - (101.66309913583174 / (fConst2 * fConst236)));
		fConst239 = ((((7751.5392944264649 / fConst2) + 152.4946487037476) / fConst2) + 1.0);
		fConst240 = (1.0 / fConst239);
		fConst241 = (0.0 - (31006.15717770586 / (fConst3 * fConst239)));
		fConst242 = (0.0 - (((31006.15717770586 / fConst2) + 304.9892974074952) / (fConst2 * fConst239)));
		fConst243 = ((((52034.04960821534 / fConst2) + 446.99542215548172) / fConst2) + 1.0);
		fConst244 = (0.0 - (208136.19843286136 / (fConst3 * fConst243)));
		fConst245 = (0.0 - (((208136.19843286136 / fConst2) + 893.99084431096344) / (fConst2 * fConst243)));
		fConst246 = ((((57712.31844354757 / fConst2) + 393.05632555747695) / fConst2) + 1.0);
		fConst247 = (0.0 - (230849.27377419028 / (fConst3 * fConst246)));
		fConst248 = (0.0 - (((230849.27377419028 / fConst2) + 786.11265111495391) / (fConst2 * fConst246)));
		fConst249 = ((((73380.273781622775 / fConst2) + 264.71635105067321) / fConst2) + 1.0);
		fConst250 = (1.0 / ((fConst243 * fConst246) * fConst249));
		fConst251 = (0.0 - (293521.0951264911 / (fConst3 * fConst249)));
		fConst252 = (0.0 - (((293521.0951264911 / fConst2) + 529.43270210134642) / (fConst2 * fConst249)));
		fConst253 = ((191.84764117382693 / fConst2) + 1.0);
		fConst254 = (0.0 - (383.69528234765386 / (fConst2 * fConst253)));
		fConst255 = ((((39500.547880469159 / fConst2) + 352.67947602203611) / fConst2) + 1.0);
		fConst256 = (0.0 - (158002.19152187664 / (fConst3 * fConst255)));
		fConst257 = (0.0 - (((158002.19152187664 / fConst2) + 705.35895204407223) / (fConst2 * fConst255)));
		fConst258 = ((((50249.457457982011 / fConst2) + 244.59295334958685) / fConst2) + 1.0);
		fConst259 = (1.0 / ((fConst253 * fConst255) * fConst258));
		fConst260 = (0.0 - (200997.82983192804 / (fConst3 * fConst258)));
		fConst261 = (0.0 - (((200997.82983192804 / fConst2) + 489.1859066991737) / (fConst2 * fConst258)));
		fConst262 = ((((25296.245983958815 / fConst2) + 304.72772202827935) / fConst2) + 1.0);
		fConst263 = (0.0 - (101184.98393583526 / (fConst3 * fConst262)));
		fConst264 = (0.0 - (((101184.98393583526 / fConst2) + 609.45544405655869) / (fConst2 * fConst262)));
		fConst265 = ((((31793.661400043246 / fConst2) + 221.35232500202088) / fConst2) + 1.0);
		fConst266 = (1.0 / (fConst262 * fConst265));
		fConst267 = (0.0 - (127174.64560017298 / (fConst3 * fConst265)));
		fConst268 = (0.0 - (((127174.64560017298 / fConst2) + 442.70465000404175) / (fConst2 * fConst265)));
		fConst269 = ((122.1655380574766 / fConst2) + 1.0);
		fConst270 = (0.0 - (244.33107611495319 / (fConst2 * fConst269)));
		fConst271 = ((((17877.139867327685 / fConst2) + 193.48249016070361) / fConst2) + 1.0);
		fConst272 = (1.0 / (fConst269 * fConst271));
		fConst273 = (0.0 - (71508.559469310741 / (fConst3 * fConst271)));
		fConst274 = (0.0 - (((71508.559469310741 / fConst2) + 386.96498032140721) / (fConst2 * fConst271)));
		fConst275 = ((52.608004703030034 / fConst2) + 1.0);
		fConst276 = (1.0 / fConst275);
		fConst277 = (0.0 - (105.21600940606007 / (fConst2 * fConst275)));
		fConst278 = ((((8302.8064765020899 / fConst2) + 157.82401410909011) / fConst2) + 1.0);
		fConst279 = (1.0 / fConst278);
		fConst280 = (0.0 - (33211.22590600836 / (fConst3 * fConst278)));
		fConst281 = (0.0 - (((33211.22590600836 / fConst2) + 315.64802821818023) / (fConst2 * fConst278)));
		iConst282 = int(((0.00033215368013453231 * double(iConst0)) + 0.5));
		fConst283 = ((((50966.068550228498 / fConst2) + 442.38442568907209) / fConst2) + 1.0);
		fConst284 = (0.0 - (203864.27420091399 / (fConst3 * fConst283)));
		fConst285 = (0.0 - (((203864.27420091399 / fConst2) + 884.76885137814418) / (fConst2 * fConst283)));
		fConst286 = ((((56527.792861274189 / fConst2) + 389.00173967490593) / fConst2) + 1.0);
		fConst287 = (0.0 - (226111.17144509676 / (fConst3 * fConst286)));
		fConst288 = (0.0 - (((226111.17144509676 / fConst2) + 778.00347934981187) / (fConst2 * fConst286)));
		fConst289 = ((((71874.168778865336 / fConst2) + 261.98566053619419) / fConst2) + 1.0);
		fConst290 = (1.0 / ((fConst283 * fConst286) * fConst289));
		fConst291 = (0.0 - (287496.67511546134 / (fConst3 * fConst289)));
		fConst292 = (0.0 - (((287496.67511546134 / fConst2) + 523.97132107238838) / (fConst2 * fConst289)));
		fConst293 = ((189.86863031220375 / fConst2) + 1.0);
		fConst294 = (0.0 - (379.7372606244075 / (fConst2 * fConst293)));
		fConst295 = ((((38689.81265547558 / fConst2) + 349.04139890287684) / fConst2) + 1.0);
		fConst296 = (0.0 - (154759.25062190232 / (fConst3 * fConst295)));
		fConst297 = (0.0 - (((154759.25062190232 / fConst2) + 698.08279780575367) / (fConst2 * fConst295)));
		fConst298 = ((((49218.104543048263 / fConst2) + 242.06984642789817) / fConst2) + 1.0);
		fConst299 = (1.0 / ((fConst293 * fConst295) * fConst298));
		fConst300 = (0.0 - (196872.41817219305 / (fConst3 * fConst298)));
		fConst301 = (0.0 - (((196872.41817219305 / fConst2) + 484.13969285579634) / (fConst2 * fConst298)));
		fConst302 = ((((24777.049193540675 / fConst2) + 301.58429285687117) / fConst2) + 1.0);
		fConst303 = (0.0 - (99108.196774162701 / (fConst3 * fConst302)));
		fConst304 = (0.0 - (((99108.196774162701 / fConst2) + 603.16858571374235) / (fConst2 * fConst302)));
		fConst305 = ((((31141.107382146231 / fConst2) + 219.06895757178162) / fConst2) + 1.0);
		fConst306 = (1.0 / (fConst302 * fConst305));
		fConst307 = (0.0 - (124564.42952858492 / (fConst3 * fConst305)));
		fConst308 = (0.0 - (((124564.42952858492 / fConst2) + 438.13791514356325) / (fConst2 * fConst305)));
		fConst309 = ((120.90533529838856 / fConst2) + 1.0);
		fConst310 = (0.0 - (241.81067059677713 / (fConst2 * fConst309)));
		fConst311 = ((((17510.217690540721 / fConst2) + 191.48661495880316) / fConst2) + 1.0);
		fConst312 = (1.0 / (fConst309 * fConst311));
		fConst313 = (0.0 - (70040.870762162886 / (fConst3 * fConst311)));
		fConst314 = (0.0 - (((70040.870762162886 / fConst2) + 382.97322991760632) / (fConst2 * fConst311)));
		fConst315 = ((52.06532504286529 / fConst2) + 1.0);
		fConst316 = (1.0 / fConst315);
		fConst317 = (0.0 - (104.13065008573058 / (fConst2 * fConst315)));
		fConst318 = ((((8132.3942154576471 / fConst2) + 156.19597512859588) / fConst2) + 1.0);
		fConst319 = (1.0 / fConst318);
		fConst320 = (0.0 - (32529.576861830588 / (fConst3 * fConst318)));
		fConst321 = (0.0 - (((32529.576861830588 / fConst2) + 312.39195025719175) / (fConst2 * fConst318)));
		iConst322 = int(((0.00023309030184879507 * double(iConst0)) + 0.5));
		fConst323 = ((((60707.402938397332 / fConst2) + 482.8142606195965) / fConst2) + 1.0);
		fConst324 = (0.0 - (242829.61175358933 / (fConst3 * fConst323)));
		fConst325 = (0.0 - (((242829.61175358933 / fConst2) + 965.62852123919299) / (fConst2 * fConst323)));
		fConst326 = ((((67332.160318892158 / fConst2) + 424.55289204254632) / fConst2) + 1.0);
		fConst327 = (0.0 - (269328.64127556863 / (fConst3 * fConst326)));
		fConst328 = (0.0 - (((269328.64127556863 / fConst2) + 849.10578408509264) / (fConst2 * fConst326)));
		fConst329 = ((((85611.746187972225 / fConst2) + 285.92872090307816) / fConst2) + 1.0);
		fConst330 = (1.0 / ((fConst323 * fConst326) * fConst329));
		fConst331 = (0.0 - (342446.9847518889 / (fConst3 * fConst329)));
		fConst332 = (0.0 - (((342446.9847518889 / fConst2) + 571.85744180615632) / (fConst2 * fConst329)));
		fConst333 = ((207.22086275133231 / fConst2) + 1.0);
		fConst334 = (0.0 - (414.44172550266461 / (fConst333 * fConst2)));
		fConst335 = ((((46084.740559737176 / fConst2) + 380.94054661717945) / fConst2) + 1.0);
		fConst336 = (0.0 - (184338.9622389487 / (fConst335 * fConst3)));
		fConst337 = (0.0 - (((184338.9622389487 / fConst2) + 761.8810932343589) / (fConst335 * fConst2)));
		fConst338 = ((((58625.344064244076 / fConst2) + 264.19278603521599) / fConst2) + 1.0);
		fConst339 = (1.0 / ((fConst333 * fConst335) * fConst338));
		fConst340 = (0.0 - (234501.37625697631 / (fConst338 * fConst3)));
		fConst341 = (0.0 - (((234501.37625697631 / fConst2) + 528.38557207043198) / (fConst338 * fConst2)));
		fConst342 = ((((29512.778831162617 / fConst2) + 329.14630107822762) / fConst2) + 1.0);
		fConst343 = (0.0 - (118051.11532465047 / (fConst3 * fConst342)));
		fConst344 = (0.0 - (((118051.11532465047 / fConst2) + 658.29260215645525) / (fConst2 * fConst342)));
		fConst345 = ((((37093.223149686615 / fConst2) + 239.08982919092455) / fConst2) + 1.0);
		fConst346 = (1.0 / (fConst342 * fConst345));
		fConst347 = (0.0 - (148372.89259874646 / (fConst3 * fConst345)));
		fConst348 = (0.0 - (((148372.89259874646 / fConst2) + 478.17965838184909) / (fConst2 * fConst345)));
		fConst349 = ((131.95496196804262 / fConst2) + 1.0);
		fConst350 = (0.0 - (263.90992393608525 / (fConst2 * fConst349)));
		fConst351 = ((((20857.010774356517 / fConst2) + 208.98671619344873) / fConst2) + 1.0);
		fConst352 = (1.0 / (fConst349 * fConst351));
		fConst353 = (0.0 - (83428.043097426067 / (fConst3 * fConst351)));
		fConst354 = (0.0 - (((83428.043097426067 / fConst2) + 417.97343238689746) / (fConst2 * fConst351)));
		fConst355 = ((56.823613026915226 / fConst2) + 1.0);
		fConst356 = (1.0 / fConst355);
		fConst357 = (0.0 - (113.64722605383045 / (fConst2 * fConst355)));
		fConst358 = ((((9686.7689922978298 / fConst2) + 170.47083908074569) / fConst2) + 1.0);
		fConst359 = (1.0 / fConst358);
		fConst360 = (0.0 - (38747.075969191319 / (fConst3 * fConst358)));
		fConst361 = (0.0 - (((38747.075969191319 / fConst2) + 340.94167816149138) / (fConst2 * fConst358)));
		iConst362 = int(((0.0010372518432271369 * double(iConst0)) + 0.5));
		fConst363 = ((((28935.054883282508 / fConst2) + 325.90879647745817) / fConst2) + 1.0);
		fConst364 = ((((36367.10910125255 / fConst2) + 236.73812595298105) / fConst2) + 1.0);
		fConst365 = (1.0 / (fConst363 * fConst364));
		fConst366 = (0.0 - (((145468.4364050102 / fConst2) + 473.4762519059621) / (fConst2 * fConst364)));
		fConst367 = (0.0 - (145468.4364050102 / (fConst3 * fConst364)));
		fConst368 = (0.0 - (((115740.21953313003 / fConst2) + 651.81759295491634) / (fConst2 * fConst363)));
		fConst369 = (0.0 - (115740.21953313003 / (fConst3 * fConst363)));
		fConst370 = ((130.65704430934056 / fConst2) + 1.0);
		fConst371 = (0.0 - (261.31408861868113 / (fConst2 * fConst370)));
		fConst372 = ((((20448.726801014909 / fConst2) + 206.93110914892304) / fConst2) + 1.0);
		fConst373 = (1.0 / (fConst370 * fConst372));
		fConst374 = (0.0 - (81794.907204059637 / (fConst3 * fConst372)));
		fConst375 = (0.0 - (((81794.907204059637 / fConst2) + 413.86221829784608) / (fConst2 * fConst372)));
		fConst376 = ((56.264692243043932 / fConst2) + 1.0);
		fConst377 = (1.0 / fConst376);
		fConst378 = (0.0 - (112.52938448608786 / (fConst2 * fConst376)));
		fConst379 = ((((9497.1467796133438 / fConst2) + 168.7940767291318) / fConst2) + 1.0);
		fConst380 = (1.0 / fConst379);
		fConst381 = (0.0 - (37988.587118453375 / (fConst3 * fConst379)));
		fConst382 = (0.0 - (((37988.587118453375 / fConst2) + 337.5881534582636) / (fConst2 * fConst379)));
		fConst383 = ((205.18262475705691 / fConst2) + 1.0);
		fConst384 = (0.0 - (410.36524951411383 / (fConst2 * fConst383)));
		fConst385 = ((((45182.614114595752 / fConst2) + 377.19359042094487) / fConst2) + 1.0);
		fConst386 = (0.0 - (180730.45645838301 / (fConst3 * fConst385)));
		fConst387 = (0.0 - (((180730.45645838301 / fConst2) + 754.38718084188974) / (fConst2 * fConst385)));
		fConst388 = ((((57477.730502932725 / fConst2) + 261.59416846765652) / fConst2) + 1.0);
		fConst389 = (1.0 / ((fConst383 * fConst385) * fConst388));
		fConst390 = (0.0 - (229910.9220117309 / (fConst3 * fConst388)));
		fConst391 = (0.0 - (((229910.9220117309 / fConst2) + 523.18833693531303) / (fConst2 * fConst388)));
		fConst392 = ((((59519.032277275895 / fConst2) + 478.06526789219066) / fConst2) + 1.0);
		fConst393 = (0.0 - (238076.12910910358 / (fConst3 * fConst392)));
		fConst394 = (0.0 - (((238076.12910910358 / fConst2) + 956.13053578438132) / (fConst2 * fConst392)));
		fConst395 = ((((66014.107495020042 / fConst2) + 420.37696195688193) / fConst2) + 1.0);
		fConst396 = (0.0 - (264056.42998008017 / (fConst3 * fConst395)));
		fConst397 = (0.0 - (((264056.42998008017 / fConst2) + 840.75392391376386) / (fConst2 * fConst395)));
		fConst398 = ((((83935.863470333978 / fConst2) + 283.11630725485116) / fConst2) + 1.0);
		fConst399 = (1.0 / ((fConst392 * fConst395) * fConst398));
		fConst400 = (0.0 - (335743.45388133591 / (fConst3 * fConst398)));
		fConst401 = (0.0 - (((335743.45388133591 / fConst2) + 566.23261450970233) / (fConst2 * fConst398)));
		iConst402 = int(((0.00094984298003383924 * double(iConst0)) + 0.5));
		fConst403 = ((107.25456958830247 / fConst2) + 1.0);
		fConst404 = (1.0 / fConst403);
		fConst405 = (0.0 - (214.50913917660495 / (fConst2 * fConst403)));
		fConst406 = ((((34510.628092716055 / fConst2) + 321.76370876490739) / fConst2) + 1.0);
		fConst407 = (1.0 / fConst406);
		fConst408 = (0.0 - (138042.51237086422 / (fConst3 * fConst406)));
		fConst409 = (0.0 - (((138042.51237086422 / fConst2) + 643.52741752981478) / (fConst2 * fConst406)));
		fConst410 = ((249.06499071468039 / fConst2) + 1.0);
		fConst411 = (0.0 - (498.12998142936078 / (fConst2 * fConst410)));
		fConst412 = ((((74306.359791578565 / fConst2) + 394.46242681513445) / fConst2) + 1.0);
		fConst413 = (1.0 / (fConst410 * fConst412));
		fConst414 = (0.0 - (297225.43916631426 / (fConst3 * fConst412)));
		fConst415 = (0.0 - (((297225.43916631426 / fConst2) + 788.9248536302689) / (fConst2 * fConst412)));
		fConst416 = ((((105143.88595770916 / fConst2) + 621.26364328515456) / fConst2) + 1.0);
		fConst417 = (0.0 - (420575.54383083666 / (fConst3 * fConst416)));
		fConst418 = (0.0 - (((420575.54383083666 / fConst2) + 1242.5272865703091) / (fConst2 * fConst416)));
		fConst419 = ((((132150.40328687569 / fConst2) + 451.28205259787001) / fConst2) + 1.0);
		fConst420 = (1.0 / (fConst416 * fConst419));
		fConst421 = (0.0 - (528601.61314750277 / (fConst3 * fConst419)));
		fConst422 = (0.0 - (((528601.61314750277 / fConst2) + 902.56410519574001) / (fConst2 * fConst419)));
		fConst423 = ((391.12937844313967 / fConst2) + 1.0);
		fConst424 = (0.0 - (782.25875688627934 / (fConst2 * fConst423)));
		fConst425 = ((((164184.08898477611 / fConst2) + 719.02528173992607) / fConst2) + 1.0);
		fConst426 = (0.0 - (656736.35593910445 / (fConst3 * fConst425)));
		fConst427 = (0.0 - (((656736.35593910445 / fConst2) + 1438.0505634798521) / (fConst2 * fConst425)));
		fConst428 = ((((208861.94843887951 / fConst2) + 498.66388364147014) / fConst2) + 1.0);
		fConst429 = (1.0 / ((fConst423 * fConst425) * fConst428));
		fConst430 = (0.0 - (835447.79375551804 / (fConst3 * fConst428)));
		fConst431 = (0.0 - (((835447.79375551804 / fConst2) + 997.32776728294027) / (fConst2 * fConst428)));
		fConst432 = ((((216279.60849974956 / fConst2) + 911.31191691948823) / fConst2) + 1.0);
		fConst433 = (0.0 - (865118.43399899825 / (fConst3 * fConst432)));
		fConst434 = (0.0 - (((865118.43399899825 / fConst2) + 1822.6238338389765) / (fConst2 * fConst432)));
		fConst435 = ((((239881.34178610303 / fConst2) + 801.34358373030602) / fConst2) + 1.0);
		fConst436 = (0.0 - (959525.36714441213 / (fConst3 * fConst435)));
		fConst437 = (0.0 - (((959525.36714441213 / fConst2) + 1602.687167460612) / (fConst2 * fConst435)));
		fConst438 = ((((305005.22262999282 / fConst2) + 539.69046070455988) / fConst2) + 1.0);
		fConst439 = (1.0 / ((fConst432 * fConst435) * fConst438));
		fConst440 = (0.0 - (1220020.8905199713 / (fConst3 * fConst438)));
		fConst441 = (0.0 - (((1220020.8905199713 / fConst2) + 1079.3809214091198) / (fConst2 * fConst438)));
		iConst442 = int(((0.0051746047010432453 * double(iConst0)) + 0.5));
		
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
			fRec4[l4] = 0.0;
			
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec5[l5] = 0.0;
			
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec6[l6] = 0.0;
			
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec7[l7] = 0.0;
			
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec8[l8] = 0.0;
			
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec27[l9] = 0.0;
			
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec28[l10] = 0.0;
			
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec29[l11] = 0.0;
			
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec30[l12] = 0.0;
			
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec31[l13] = 0.0;
			
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec32[l14] = 0.0;
			
		}
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fRec33[l15] = 0.0;
			
		}
		for (int l16 = 0; (l16 < 3); l16 = (l16 + 1)) {
			fRec34[l16] = 0.0;
			
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec35[l17] = 0.0;
			
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec36[l18] = 0.0;
			
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec37[l19] = 0.0;
			
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fRec38[l20] = 0.0;
			
		}
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec39[l21] = 0.0;
			
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec26[l22] = 0.0;
			
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec24[l23] = 0.0;
			
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec23[l24] = 0.0;
			
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec21[l25] = 0.0;
			
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec20[l26] = 0.0;
			
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec18[l27] = 0.0;
			
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec17[l28] = 0.0;
			
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec15[l29] = 0.0;
			
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec14[l30] = 0.0;
			
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec12[l31] = 0.0;
			
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec11[l32] = 0.0;
			
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec9[l33] = 0.0;
			
		}
		for (int l34 = 0; (l34 < 3); l34 = (l34 + 1)) {
			fRec55[l34] = 0.0;
			
		}
		for (int l35 = 0; (l35 < 3); l35 = (l35 + 1)) {
			fRec56[l35] = 0.0;
			
		}
		for (int l36 = 0; (l36 < 3); l36 = (l36 + 1)) {
			fRec57[l36] = 0.0;
			
		}
		for (int l37 = 0; (l37 < 3); l37 = (l37 + 1)) {
			fRec58[l37] = 0.0;
			
		}
		for (int l38 = 0; (l38 < 3); l38 = (l38 + 1)) {
			fRec59[l38] = 0.0;
			
		}
		for (int l39 = 0; (l39 < 3); l39 = (l39 + 1)) {
			fRec60[l39] = 0.0;
			
		}
		for (int l40 = 0; (l40 < 3); l40 = (l40 + 1)) {
			fRec61[l40] = 0.0;
			
		}
		for (int l41 = 0; (l41 < 3); l41 = (l41 + 1)) {
			fRec62[l41] = 0.0;
			
		}
		for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) {
			fRec63[l42] = 0.0;
			
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec54[l43] = 0.0;
			
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec52[l44] = 0.0;
			
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fRec51[l45] = 0.0;
			
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec49[l46] = 0.0;
			
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec48[l47] = 0.0;
			
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec46[l48] = 0.0;
			
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec45[l49] = 0.0;
			
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec43[l50] = 0.0;
			
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fRec42[l51] = 0.0;
			
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec40[l52] = 0.0;
			
		}
		for (int l53 = 0; (l53 < 3); l53 = (l53 + 1)) {
			fRec76[l53] = 0.0;
			
		}
		for (int l54 = 0; (l54 < 3); l54 = (l54 + 1)) {
			fRec77[l54] = 0.0;
			
		}
		for (int l55 = 0; (l55 < 3); l55 = (l55 + 1)) {
			fRec78[l55] = 0.0;
			
		}
		for (int l56 = 0; (l56 < 3); l56 = (l56 + 1)) {
			fRec79[l56] = 0.0;
			
		}
		for (int l57 = 0; (l57 < 3); l57 = (l57 + 1)) {
			fRec80[l57] = 0.0;
			
		}
		for (int l58 = 0; (l58 < 3); l58 = (l58 + 1)) {
			fRec81[l58] = 0.0;
			
		}
		for (int l59 = 0; (l59 < 3); l59 = (l59 + 1)) {
			fRec82[l59] = 0.0;
			
		}
		for (int l60 = 0; (l60 < 3); l60 = (l60 + 1)) {
			fRec83[l60] = 0.0;
			
		}
		for (int l61 = 0; (l61 < 3); l61 = (l61 + 1)) {
			fRec84[l61] = 0.0;
			
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec75[l62] = 0.0;
			
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fRec73[l63] = 0.0;
			
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fRec72[l64] = 0.0;
			
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec70[l65] = 0.0;
			
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec69[l66] = 0.0;
			
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec67[l67] = 0.0;
			
		}
		for (int l68 = 0; (l68 < 2); l68 = (l68 + 1)) {
			fRec66[l68] = 0.0;
			
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fRec64[l69] = 0.0;
			
		}
		for (int l70 = 0; (l70 < 3); l70 = (l70 + 1)) {
			fRec94[l70] = 0.0;
			
		}
		for (int l71 = 0; (l71 < 3); l71 = (l71 + 1)) {
			fRec95[l71] = 0.0;
			
		}
		for (int l72 = 0; (l72 < 3); l72 = (l72 + 1)) {
			fRec96[l72] = 0.0;
			
		}
		for (int l73 = 0; (l73 < 3); l73 = (l73 + 1)) {
			fRec97[l73] = 0.0;
			
		}
		for (int l74 = 0; (l74 < 3); l74 = (l74 + 1)) {
			fRec98[l74] = 0.0;
			
		}
		for (int l75 = 0; (l75 < 3); l75 = (l75 + 1)) {
			fRec99[l75] = 0.0;
			
		}
		for (int l76 = 0; (l76 < 2); l76 = (l76 + 1)) {
			fRec93[l76] = 0.0;
			
		}
		for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) {
			fRec91[l77] = 0.0;
			
		}
		for (int l78 = 0; (l78 < 2); l78 = (l78 + 1)) {
			fRec90[l78] = 0.0;
			
		}
		for (int l79 = 0; (l79 < 2); l79 = (l79 + 1)) {
			fRec88[l79] = 0.0;
			
		}
		for (int l80 = 0; (l80 < 2); l80 = (l80 + 1)) {
			fRec87[l80] = 0.0;
			
		}
		for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) {
			fRec85[l81] = 0.0;
			
		}
		for (int l82 = 0; (l82 < 3); l82 = (l82 + 1)) {
			fRec103[l82] = 0.0;
			
		}
		for (int l83 = 0; (l83 < 3); l83 = (l83 + 1)) {
			fRec104[l83] = 0.0;
			
		}
		for (int l84 = 0; (l84 < 3); l84 = (l84 + 1)) {
			fRec105[l84] = 0.0;
			
		}
		for (int l85 = 0; (l85 < 2); l85 = (l85 + 1)) {
			fRec102[l85] = 0.0;
			
		}
		for (int l86 = 0; (l86 < 2); l86 = (l86 + 1)) {
			fRec100[l86] = 0.0;
			
		}
		for (int l87 = 0; (l87 < 3); l87 = (l87 + 1)) {
			fRec112[l87] = 0.0;
			
		}
		for (int l88 = 0; (l88 < 3); l88 = (l88 + 1)) {
			fRec113[l88] = 0.0;
			
		}
		for (int l89 = 0; (l89 < 3); l89 = (l89 + 1)) {
			fRec114[l89] = 0.0;
			
		}
		for (int l90 = 0; (l90 < 3); l90 = (l90 + 1)) {
			fRec115[l90] = 0.0;
			
		}
		for (int l91 = 0; (l91 < 3); l91 = (l91 + 1)) {
			fRec116[l91] = 0.0;
			
		}
		for (int l92 = 0; (l92 < 2); l92 = (l92 + 1)) {
			fRec111[l92] = 0.0;
			
		}
		for (int l93 = 0; (l93 < 2); l93 = (l93 + 1)) {
			fRec109[l93] = 0.0;
			
		}
		for (int l94 = 0; (l94 < 2); l94 = (l94 + 1)) {
			fRec108[l94] = 0.0;
			
		}
		for (int l95 = 0; (l95 < 2); l95 = (l95 + 1)) {
			fRec106[l95] = 0.0;
			
		}
		for (int l96 = 0; (l96 < 3); l96 = (l96 + 1)) {
			fRec117[l96] = 0.0;
			
		}
		for (int l97 = 0; (l97 < 3); l97 = (l97 + 1)) {
			fRec118[l97] = 0.0;
			
		}
		for (int l98 = 0; (l98 < 3); l98 = (l98 + 1)) {
			fRec119[l98] = 0.0;
			
		}
		for (int l99 = 0; (l99 < 3); l99 = (l99 + 1)) {
			fRec120[l99] = 0.0;
			
		}
		for (int l100 = 0; (l100 < 3); l100 = (l100 + 1)) {
			fRec121[l100] = 0.0;
			
		}
		for (int l101 = 0; (l101 < 3); l101 = (l101 + 1)) {
			fRec122[l101] = 0.0;
			
		}
		for (int l102 = 0; (l102 < 3); l102 = (l102 + 1)) {
			fRec123[l102] = 0.0;
			
		}
		IOTA = 0;
		for (int l103 = 0; (l103 < 128); l103 = (l103 + 1)) {
			fVec0[l103] = 0.0;
			
		}
		for (int l104 = 0; (l104 < 2); l104 = (l104 + 1)) {
			fRec141[l104] = 0.0;
			
		}
		for (int l105 = 0; (l105 < 2); l105 = (l105 + 1)) {
			fRec139[l105] = 0.0;
			
		}
		for (int l106 = 0; (l106 < 2); l106 = (l106 + 1)) {
			fRec138[l106] = 0.0;
			
		}
		for (int l107 = 0; (l107 < 2); l107 = (l107 + 1)) {
			fRec136[l107] = 0.0;
			
		}
		for (int l108 = 0; (l108 < 2); l108 = (l108 + 1)) {
			fRec135[l108] = 0.0;
			
		}
		for (int l109 = 0; (l109 < 2); l109 = (l109 + 1)) {
			fRec133[l109] = 0.0;
			
		}
		for (int l110 = 0; (l110 < 2); l110 = (l110 + 1)) {
			fRec132[l110] = 0.0;
			
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec130[l111] = 0.0;
			
		}
		for (int l112 = 0; (l112 < 2); l112 = (l112 + 1)) {
			fRec129[l112] = 0.0;
			
		}
		for (int l113 = 0; (l113 < 2); l113 = (l113 + 1)) {
			fRec127[l113] = 0.0;
			
		}
		for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) {
			fRec126[l114] = 0.0;
			
		}
		for (int l115 = 0; (l115 < 2); l115 = (l115 + 1)) {
			fRec124[l115] = 0.0;
			
		}
		for (int l116 = 0; (l116 < 2); l116 = (l116 + 1)) {
			fRec156[l116] = 0.0;
			
		}
		for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) {
			fRec154[l117] = 0.0;
			
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			fRec153[l118] = 0.0;
			
		}
		for (int l119 = 0; (l119 < 2); l119 = (l119 + 1)) {
			fRec151[l119] = 0.0;
			
		}
		for (int l120 = 0; (l120 < 2); l120 = (l120 + 1)) {
			fRec150[l120] = 0.0;
			
		}
		for (int l121 = 0; (l121 < 2); l121 = (l121 + 1)) {
			fRec148[l121] = 0.0;
			
		}
		for (int l122 = 0; (l122 < 2); l122 = (l122 + 1)) {
			fRec147[l122] = 0.0;
			
		}
		for (int l123 = 0; (l123 < 2); l123 = (l123 + 1)) {
			fRec145[l123] = 0.0;
			
		}
		for (int l124 = 0; (l124 < 2); l124 = (l124 + 1)) {
			fRec144[l124] = 0.0;
			
		}
		for (int l125 = 0; (l125 < 2); l125 = (l125 + 1)) {
			fRec142[l125] = 0.0;
			
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fRec168[l126] = 0.0;
			
		}
		for (int l127 = 0; (l127 < 2); l127 = (l127 + 1)) {
			fRec166[l127] = 0.0;
			
		}
		for (int l128 = 0; (l128 < 2); l128 = (l128 + 1)) {
			fRec165[l128] = 0.0;
			
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec163[l129] = 0.0;
			
		}
		for (int l130 = 0; (l130 < 2); l130 = (l130 + 1)) {
			fRec162[l130] = 0.0;
			
		}
		for (int l131 = 0; (l131 < 2); l131 = (l131 + 1)) {
			fRec160[l131] = 0.0;
			
		}
		for (int l132 = 0; (l132 < 2); l132 = (l132 + 1)) {
			fRec159[l132] = 0.0;
			
		}
		for (int l133 = 0; (l133 < 2); l133 = (l133 + 1)) {
			fRec157[l133] = 0.0;
			
		}
		for (int l134 = 0; (l134 < 2); l134 = (l134 + 1)) {
			fRec177[l134] = 0.0;
			
		}
		for (int l135 = 0; (l135 < 2); l135 = (l135 + 1)) {
			fRec175[l135] = 0.0;
			
		}
		for (int l136 = 0; (l136 < 2); l136 = (l136 + 1)) {
			fRec174[l136] = 0.0;
			
		}
		for (int l137 = 0; (l137 < 2); l137 = (l137 + 1)) {
			fRec172[l137] = 0.0;
			
		}
		for (int l138 = 0; (l138 < 2); l138 = (l138 + 1)) {
			fRec171[l138] = 0.0;
			
		}
		for (int l139 = 0; (l139 < 2); l139 = (l139 + 1)) {
			fRec169[l139] = 0.0;
			
		}
		for (int l140 = 0; (l140 < 2); l140 = (l140 + 1)) {
			fRec180[l140] = 0.0;
			
		}
		for (int l141 = 0; (l141 < 2); l141 = (l141 + 1)) {
			fRec178[l141] = 0.0;
			
		}
		for (int l142 = 0; (l142 < 2); l142 = (l142 + 1)) {
			fRec186[l142] = 0.0;
			
		}
		for (int l143 = 0; (l143 < 2); l143 = (l143 + 1)) {
			fRec184[l143] = 0.0;
			
		}
		for (int l144 = 0; (l144 < 2); l144 = (l144 + 1)) {
			fRec183[l144] = 0.0;
			
		}
		for (int l145 = 0; (l145 < 2); l145 = (l145 + 1)) {
			fRec181[l145] = 0.0;
			
		}
		for (int l146 = 0; (l146 < 64); l146 = (l146 + 1)) {
			fVec1[l146] = 0.0;
			
		}
		for (int l147 = 0; (l147 < 2); l147 = (l147 + 1)) {
			fRec204[l147] = 0.0;
			
		}
		for (int l148 = 0; (l148 < 2); l148 = (l148 + 1)) {
			fRec202[l148] = 0.0;
			
		}
		for (int l149 = 0; (l149 < 2); l149 = (l149 + 1)) {
			fRec201[l149] = 0.0;
			
		}
		for (int l150 = 0; (l150 < 2); l150 = (l150 + 1)) {
			fRec199[l150] = 0.0;
			
		}
		for (int l151 = 0; (l151 < 2); l151 = (l151 + 1)) {
			fRec198[l151] = 0.0;
			
		}
		for (int l152 = 0; (l152 < 2); l152 = (l152 + 1)) {
			fRec196[l152] = 0.0;
			
		}
		for (int l153 = 0; (l153 < 2); l153 = (l153 + 1)) {
			fRec195[l153] = 0.0;
			
		}
		for (int l154 = 0; (l154 < 2); l154 = (l154 + 1)) {
			fRec193[l154] = 0.0;
			
		}
		for (int l155 = 0; (l155 < 2); l155 = (l155 + 1)) {
			fRec192[l155] = 0.0;
			
		}
		for (int l156 = 0; (l156 < 2); l156 = (l156 + 1)) {
			fRec190[l156] = 0.0;
			
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec189[l157] = 0.0;
			
		}
		for (int l158 = 0; (l158 < 2); l158 = (l158 + 1)) {
			fRec187[l158] = 0.0;
			
		}
		for (int l159 = 0; (l159 < 2); l159 = (l159 + 1)) {
			fRec219[l159] = 0.0;
			
		}
		for (int l160 = 0; (l160 < 2); l160 = (l160 + 1)) {
			fRec217[l160] = 0.0;
			
		}
		for (int l161 = 0; (l161 < 2); l161 = (l161 + 1)) {
			fRec216[l161] = 0.0;
			
		}
		for (int l162 = 0; (l162 < 2); l162 = (l162 + 1)) {
			fRec214[l162] = 0.0;
			
		}
		for (int l163 = 0; (l163 < 2); l163 = (l163 + 1)) {
			fRec213[l163] = 0.0;
			
		}
		for (int l164 = 0; (l164 < 2); l164 = (l164 + 1)) {
			fRec211[l164] = 0.0;
			
		}
		for (int l165 = 0; (l165 < 2); l165 = (l165 + 1)) {
			fRec210[l165] = 0.0;
			
		}
		for (int l166 = 0; (l166 < 2); l166 = (l166 + 1)) {
			fRec208[l166] = 0.0;
			
		}
		for (int l167 = 0; (l167 < 2); l167 = (l167 + 1)) {
			fRec207[l167] = 0.0;
			
		}
		for (int l168 = 0; (l168 < 2); l168 = (l168 + 1)) {
			fRec205[l168] = 0.0;
			
		}
		for (int l169 = 0; (l169 < 2); l169 = (l169 + 1)) {
			fRec231[l169] = 0.0;
			
		}
		for (int l170 = 0; (l170 < 2); l170 = (l170 + 1)) {
			fRec229[l170] = 0.0;
			
		}
		for (int l171 = 0; (l171 < 2); l171 = (l171 + 1)) {
			fRec228[l171] = 0.0;
			
		}
		for (int l172 = 0; (l172 < 2); l172 = (l172 + 1)) {
			fRec226[l172] = 0.0;
			
		}
		for (int l173 = 0; (l173 < 2); l173 = (l173 + 1)) {
			fRec225[l173] = 0.0;
			
		}
		for (int l174 = 0; (l174 < 2); l174 = (l174 + 1)) {
			fRec223[l174] = 0.0;
			
		}
		for (int l175 = 0; (l175 < 2); l175 = (l175 + 1)) {
			fRec222[l175] = 0.0;
			
		}
		for (int l176 = 0; (l176 < 2); l176 = (l176 + 1)) {
			fRec220[l176] = 0.0;
			
		}
		for (int l177 = 0; (l177 < 2); l177 = (l177 + 1)) {
			fRec240[l177] = 0.0;
			
		}
		for (int l178 = 0; (l178 < 2); l178 = (l178 + 1)) {
			fRec238[l178] = 0.0;
			
		}
		for (int l179 = 0; (l179 < 2); l179 = (l179 + 1)) {
			fRec237[l179] = 0.0;
			
		}
		for (int l180 = 0; (l180 < 2); l180 = (l180 + 1)) {
			fRec235[l180] = 0.0;
			
		}
		for (int l181 = 0; (l181 < 2); l181 = (l181 + 1)) {
			fRec234[l181] = 0.0;
			
		}
		for (int l182 = 0; (l182 < 2); l182 = (l182 + 1)) {
			fRec232[l182] = 0.0;
			
		}
		for (int l183 = 0; (l183 < 2); l183 = (l183 + 1)) {
			fRec243[l183] = 0.0;
			
		}
		for (int l184 = 0; (l184 < 2); l184 = (l184 + 1)) {
			fRec241[l184] = 0.0;
			
		}
		for (int l185 = 0; (l185 < 2); l185 = (l185 + 1)) {
			fRec249[l185] = 0.0;
			
		}
		for (int l186 = 0; (l186 < 2); l186 = (l186 + 1)) {
			fRec247[l186] = 0.0;
			
		}
		for (int l187 = 0; (l187 < 2); l187 = (l187 + 1)) {
			fRec246[l187] = 0.0;
			
		}
		for (int l188 = 0; (l188 < 2); l188 = (l188 + 1)) {
			fRec244[l188] = 0.0;
			
		}
		for (int l189 = 0; (l189 < 16); l189 = (l189 + 1)) {
			fVec2[l189] = 0.0;
			
		}
		for (int l190 = 0; (l190 < 2); l190 = (l190 + 1)) {
			fRec267[l190] = 0.0;
			
		}
		for (int l191 = 0; (l191 < 2); l191 = (l191 + 1)) {
			fRec265[l191] = 0.0;
			
		}
		for (int l192 = 0; (l192 < 2); l192 = (l192 + 1)) {
			fRec264[l192] = 0.0;
			
		}
		for (int l193 = 0; (l193 < 2); l193 = (l193 + 1)) {
			fRec262[l193] = 0.0;
			
		}
		for (int l194 = 0; (l194 < 2); l194 = (l194 + 1)) {
			fRec261[l194] = 0.0;
			
		}
		for (int l195 = 0; (l195 < 2); l195 = (l195 + 1)) {
			fRec259[l195] = 0.0;
			
		}
		for (int l196 = 0; (l196 < 2); l196 = (l196 + 1)) {
			fRec258[l196] = 0.0;
			
		}
		for (int l197 = 0; (l197 < 2); l197 = (l197 + 1)) {
			fRec256[l197] = 0.0;
			
		}
		for (int l198 = 0; (l198 < 2); l198 = (l198 + 1)) {
			fRec255[l198] = 0.0;
			
		}
		for (int l199 = 0; (l199 < 2); l199 = (l199 + 1)) {
			fRec253[l199] = 0.0;
			
		}
		for (int l200 = 0; (l200 < 2); l200 = (l200 + 1)) {
			fRec252[l200] = 0.0;
			
		}
		for (int l201 = 0; (l201 < 2); l201 = (l201 + 1)) {
			fRec250[l201] = 0.0;
			
		}
		for (int l202 = 0; (l202 < 2); l202 = (l202 + 1)) {
			fRec282[l202] = 0.0;
			
		}
		for (int l203 = 0; (l203 < 2); l203 = (l203 + 1)) {
			fRec280[l203] = 0.0;
			
		}
		for (int l204 = 0; (l204 < 2); l204 = (l204 + 1)) {
			fRec279[l204] = 0.0;
			
		}
		for (int l205 = 0; (l205 < 2); l205 = (l205 + 1)) {
			fRec277[l205] = 0.0;
			
		}
		for (int l206 = 0; (l206 < 2); l206 = (l206 + 1)) {
			fRec276[l206] = 0.0;
			
		}
		for (int l207 = 0; (l207 < 2); l207 = (l207 + 1)) {
			fRec274[l207] = 0.0;
			
		}
		for (int l208 = 0; (l208 < 2); l208 = (l208 + 1)) {
			fRec273[l208] = 0.0;
			
		}
		for (int l209 = 0; (l209 < 2); l209 = (l209 + 1)) {
			fRec271[l209] = 0.0;
			
		}
		for (int l210 = 0; (l210 < 2); l210 = (l210 + 1)) {
			fRec270[l210] = 0.0;
			
		}
		for (int l211 = 0; (l211 < 2); l211 = (l211 + 1)) {
			fRec268[l211] = 0.0;
			
		}
		for (int l212 = 0; (l212 < 2); l212 = (l212 + 1)) {
			fRec294[l212] = 0.0;
			
		}
		for (int l213 = 0; (l213 < 2); l213 = (l213 + 1)) {
			fRec292[l213] = 0.0;
			
		}
		for (int l214 = 0; (l214 < 2); l214 = (l214 + 1)) {
			fRec291[l214] = 0.0;
			
		}
		for (int l215 = 0; (l215 < 2); l215 = (l215 + 1)) {
			fRec289[l215] = 0.0;
			
		}
		for (int l216 = 0; (l216 < 2); l216 = (l216 + 1)) {
			fRec288[l216] = 0.0;
			
		}
		for (int l217 = 0; (l217 < 2); l217 = (l217 + 1)) {
			fRec286[l217] = 0.0;
			
		}
		for (int l218 = 0; (l218 < 2); l218 = (l218 + 1)) {
			fRec285[l218] = 0.0;
			
		}
		for (int l219 = 0; (l219 < 2); l219 = (l219 + 1)) {
			fRec283[l219] = 0.0;
			
		}
		for (int l220 = 0; (l220 < 2); l220 = (l220 + 1)) {
			fRec303[l220] = 0.0;
			
		}
		for (int l221 = 0; (l221 < 2); l221 = (l221 + 1)) {
			fRec301[l221] = 0.0;
			
		}
		for (int l222 = 0; (l222 < 2); l222 = (l222 + 1)) {
			fRec300[l222] = 0.0;
			
		}
		for (int l223 = 0; (l223 < 2); l223 = (l223 + 1)) {
			fRec298[l223] = 0.0;
			
		}
		for (int l224 = 0; (l224 < 2); l224 = (l224 + 1)) {
			fRec297[l224] = 0.0;
			
		}
		for (int l225 = 0; (l225 < 2); l225 = (l225 + 1)) {
			fRec295[l225] = 0.0;
			
		}
		for (int l226 = 0; (l226 < 2); l226 = (l226 + 1)) {
			fRec306[l226] = 0.0;
			
		}
		for (int l227 = 0; (l227 < 2); l227 = (l227 + 1)) {
			fRec304[l227] = 0.0;
			
		}
		for (int l228 = 0; (l228 < 2); l228 = (l228 + 1)) {
			fRec312[l228] = 0.0;
			
		}
		for (int l229 = 0; (l229 < 2); l229 = (l229 + 1)) {
			fRec310[l229] = 0.0;
			
		}
		for (int l230 = 0; (l230 < 2); l230 = (l230 + 1)) {
			fRec309[l230] = 0.0;
			
		}
		for (int l231 = 0; (l231 < 2); l231 = (l231 + 1)) {
			fRec307[l231] = 0.0;
			
		}
		for (int l232 = 0; (l232 < 64); l232 = (l232 + 1)) {
			fVec3[l232] = 0.0;
			
		}
		for (int l233 = 0; (l233 < 2); l233 = (l233 + 1)) {
			fRec330[l233] = 0.0;
			
		}
		for (int l234 = 0; (l234 < 2); l234 = (l234 + 1)) {
			fRec328[l234] = 0.0;
			
		}
		for (int l235 = 0; (l235 < 2); l235 = (l235 + 1)) {
			fRec327[l235] = 0.0;
			
		}
		for (int l236 = 0; (l236 < 2); l236 = (l236 + 1)) {
			fRec325[l236] = 0.0;
			
		}
		for (int l237 = 0; (l237 < 2); l237 = (l237 + 1)) {
			fRec324[l237] = 0.0;
			
		}
		for (int l238 = 0; (l238 < 2); l238 = (l238 + 1)) {
			fRec322[l238] = 0.0;
			
		}
		for (int l239 = 0; (l239 < 2); l239 = (l239 + 1)) {
			fRec321[l239] = 0.0;
			
		}
		for (int l240 = 0; (l240 < 2); l240 = (l240 + 1)) {
			fRec319[l240] = 0.0;
			
		}
		for (int l241 = 0; (l241 < 2); l241 = (l241 + 1)) {
			fRec318[l241] = 0.0;
			
		}
		for (int l242 = 0; (l242 < 2); l242 = (l242 + 1)) {
			fRec316[l242] = 0.0;
			
		}
		for (int l243 = 0; (l243 < 2); l243 = (l243 + 1)) {
			fRec315[l243] = 0.0;
			
		}
		for (int l244 = 0; (l244 < 2); l244 = (l244 + 1)) {
			fRec313[l244] = 0.0;
			
		}
		for (int l245 = 0; (l245 < 2); l245 = (l245 + 1)) {
			fRec345[l245] = 0.0;
			
		}
		for (int l246 = 0; (l246 < 2); l246 = (l246 + 1)) {
			fRec343[l246] = 0.0;
			
		}
		for (int l247 = 0; (l247 < 2); l247 = (l247 + 1)) {
			fRec342[l247] = 0.0;
			
		}
		for (int l248 = 0; (l248 < 2); l248 = (l248 + 1)) {
			fRec340[l248] = 0.0;
			
		}
		for (int l249 = 0; (l249 < 2); l249 = (l249 + 1)) {
			fRec339[l249] = 0.0;
			
		}
		for (int l250 = 0; (l250 < 2); l250 = (l250 + 1)) {
			fRec337[l250] = 0.0;
			
		}
		for (int l251 = 0; (l251 < 2); l251 = (l251 + 1)) {
			fRec336[l251] = 0.0;
			
		}
		for (int l252 = 0; (l252 < 2); l252 = (l252 + 1)) {
			fRec334[l252] = 0.0;
			
		}
		for (int l253 = 0; (l253 < 2); l253 = (l253 + 1)) {
			fRec333[l253] = 0.0;
			
		}
		for (int l254 = 0; (l254 < 2); l254 = (l254 + 1)) {
			fRec331[l254] = 0.0;
			
		}
		for (int l255 = 0; (l255 < 2); l255 = (l255 + 1)) {
			fRec357[l255] = 0.0;
			
		}
		for (int l256 = 0; (l256 < 2); l256 = (l256 + 1)) {
			fRec355[l256] = 0.0;
			
		}
		for (int l257 = 0; (l257 < 2); l257 = (l257 + 1)) {
			fRec354[l257] = 0.0;
			
		}
		for (int l258 = 0; (l258 < 2); l258 = (l258 + 1)) {
			fRec352[l258] = 0.0;
			
		}
		for (int l259 = 0; (l259 < 2); l259 = (l259 + 1)) {
			fRec351[l259] = 0.0;
			
		}
		for (int l260 = 0; (l260 < 2); l260 = (l260 + 1)) {
			fRec349[l260] = 0.0;
			
		}
		for (int l261 = 0; (l261 < 2); l261 = (l261 + 1)) {
			fRec348[l261] = 0.0;
			
		}
		for (int l262 = 0; (l262 < 2); l262 = (l262 + 1)) {
			fRec346[l262] = 0.0;
			
		}
		for (int l263 = 0; (l263 < 2); l263 = (l263 + 1)) {
			fRec366[l263] = 0.0;
			
		}
		for (int l264 = 0; (l264 < 2); l264 = (l264 + 1)) {
			fRec364[l264] = 0.0;
			
		}
		for (int l265 = 0; (l265 < 2); l265 = (l265 + 1)) {
			fRec363[l265] = 0.0;
			
		}
		for (int l266 = 0; (l266 < 2); l266 = (l266 + 1)) {
			fRec361[l266] = 0.0;
			
		}
		for (int l267 = 0; (l267 < 2); l267 = (l267 + 1)) {
			fRec360[l267] = 0.0;
			
		}
		for (int l268 = 0; (l268 < 2); l268 = (l268 + 1)) {
			fRec358[l268] = 0.0;
			
		}
		for (int l269 = 0; (l269 < 2); l269 = (l269 + 1)) {
			fRec369[l269] = 0.0;
			
		}
		for (int l270 = 0; (l270 < 2); l270 = (l270 + 1)) {
			fRec367[l270] = 0.0;
			
		}
		for (int l271 = 0; (l271 < 2); l271 = (l271 + 1)) {
			fRec375[l271] = 0.0;
			
		}
		for (int l272 = 0; (l272 < 2); l272 = (l272 + 1)) {
			fRec373[l272] = 0.0;
			
		}
		for (int l273 = 0; (l273 < 2); l273 = (l273 + 1)) {
			fRec372[l273] = 0.0;
			
		}
		for (int l274 = 0; (l274 < 2); l274 = (l274 + 1)) {
			fRec370[l274] = 0.0;
			
		}
		for (int l275 = 0; (l275 < 8); l275 = (l275 + 1)) {
			fVec4[l275] = 0.0;
			
		}
		for (int l276 = 0; (l276 < 2); l276 = (l276 + 1)) {
			fRec393[l276] = 0.0;
			
		}
		for (int l277 = 0; (l277 < 2); l277 = (l277 + 1)) {
			fRec391[l277] = 0.0;
			
		}
		for (int l278 = 0; (l278 < 2); l278 = (l278 + 1)) {
			fRec390[l278] = 0.0;
			
		}
		for (int l279 = 0; (l279 < 2); l279 = (l279 + 1)) {
			fRec388[l279] = 0.0;
			
		}
		for (int l280 = 0; (l280 < 2); l280 = (l280 + 1)) {
			fRec387[l280] = 0.0;
			
		}
		for (int l281 = 0; (l281 < 2); l281 = (l281 + 1)) {
			fRec385[l281] = 0.0;
			
		}
		for (int l282 = 0; (l282 < 2); l282 = (l282 + 1)) {
			fRec384[l282] = 0.0;
			
		}
		for (int l283 = 0; (l283 < 2); l283 = (l283 + 1)) {
			fRec382[l283] = 0.0;
			
		}
		for (int l284 = 0; (l284 < 2); l284 = (l284 + 1)) {
			fRec381[l284] = 0.0;
			
		}
		for (int l285 = 0; (l285 < 2); l285 = (l285 + 1)) {
			fRec379[l285] = 0.0;
			
		}
		for (int l286 = 0; (l286 < 2); l286 = (l286 + 1)) {
			fRec378[l286] = 0.0;
			
		}
		for (int l287 = 0; (l287 < 2); l287 = (l287 + 1)) {
			fRec376[l287] = 0.0;
			
		}
		for (int l288 = 0; (l288 < 2); l288 = (l288 + 1)) {
			fRec408[l288] = 0.0;
			
		}
		for (int l289 = 0; (l289 < 2); l289 = (l289 + 1)) {
			fRec406[l289] = 0.0;
			
		}
		for (int l290 = 0; (l290 < 2); l290 = (l290 + 1)) {
			fRec405[l290] = 0.0;
			
		}
		for (int l291 = 0; (l291 < 2); l291 = (l291 + 1)) {
			fRec403[l291] = 0.0;
			
		}
		for (int l292 = 0; (l292 < 2); l292 = (l292 + 1)) {
			fRec402[l292] = 0.0;
			
		}
		for (int l293 = 0; (l293 < 2); l293 = (l293 + 1)) {
			fRec400[l293] = 0.0;
			
		}
		for (int l294 = 0; (l294 < 2); l294 = (l294 + 1)) {
			fRec399[l294] = 0.0;
			
		}
		for (int l295 = 0; (l295 < 2); l295 = (l295 + 1)) {
			fRec397[l295] = 0.0;
			
		}
		for (int l296 = 0; (l296 < 2); l296 = (l296 + 1)) {
			fRec396[l296] = 0.0;
			
		}
		for (int l297 = 0; (l297 < 2); l297 = (l297 + 1)) {
			fRec394[l297] = 0.0;
			
		}
		for (int l298 = 0; (l298 < 2); l298 = (l298 + 1)) {
			fRec420[l298] = 0.0;
			
		}
		for (int l299 = 0; (l299 < 2); l299 = (l299 + 1)) {
			fRec418[l299] = 0.0;
			
		}
		for (int l300 = 0; (l300 < 2); l300 = (l300 + 1)) {
			fRec417[l300] = 0.0;
			
		}
		for (int l301 = 0; (l301 < 2); l301 = (l301 + 1)) {
			fRec415[l301] = 0.0;
			
		}
		for (int l302 = 0; (l302 < 2); l302 = (l302 + 1)) {
			fRec414[l302] = 0.0;
			
		}
		for (int l303 = 0; (l303 < 2); l303 = (l303 + 1)) {
			fRec412[l303] = 0.0;
			
		}
		for (int l304 = 0; (l304 < 2); l304 = (l304 + 1)) {
			fRec411[l304] = 0.0;
			
		}
		for (int l305 = 0; (l305 < 2); l305 = (l305 + 1)) {
			fRec409[l305] = 0.0;
			
		}
		for (int l306 = 0; (l306 < 2); l306 = (l306 + 1)) {
			fRec429[l306] = 0.0;
			
		}
		for (int l307 = 0; (l307 < 2); l307 = (l307 + 1)) {
			fRec427[l307] = 0.0;
			
		}
		for (int l308 = 0; (l308 < 2); l308 = (l308 + 1)) {
			fRec426[l308] = 0.0;
			
		}
		for (int l309 = 0; (l309 < 2); l309 = (l309 + 1)) {
			fRec424[l309] = 0.0;
			
		}
		for (int l310 = 0; (l310 < 2); l310 = (l310 + 1)) {
			fRec423[l310] = 0.0;
			
		}
		for (int l311 = 0; (l311 < 2); l311 = (l311 + 1)) {
			fRec421[l311] = 0.0;
			
		}
		for (int l312 = 0; (l312 < 2); l312 = (l312 + 1)) {
			fRec432[l312] = 0.0;
			
		}
		for (int l313 = 0; (l313 < 2); l313 = (l313 + 1)) {
			fRec430[l313] = 0.0;
			
		}
		for (int l314 = 0; (l314 < 2); l314 = (l314 + 1)) {
			fRec438[l314] = 0.0;
			
		}
		for (int l315 = 0; (l315 < 2); l315 = (l315 + 1)) {
			fRec436[l315] = 0.0;
			
		}
		for (int l316 = 0; (l316 < 2); l316 = (l316 + 1)) {
			fRec435[l316] = 0.0;
			
		}
		for (int l317 = 0; (l317 < 2); l317 = (l317 + 1)) {
			fRec433[l317] = 0.0;
			
		}
		for (int l318 = 0; (l318 < 2); l318 = (l318 + 1)) {
			fRec456[l318] = 0.0;
			
		}
		for (int l319 = 0; (l319 < 2); l319 = (l319 + 1)) {
			fRec454[l319] = 0.0;
			
		}
		for (int l320 = 0; (l320 < 2); l320 = (l320 + 1)) {
			fRec453[l320] = 0.0;
			
		}
		for (int l321 = 0; (l321 < 2); l321 = (l321 + 1)) {
			fRec451[l321] = 0.0;
			
		}
		for (int l322 = 0; (l322 < 2); l322 = (l322 + 1)) {
			fRec450[l322] = 0.0;
			
		}
		for (int l323 = 0; (l323 < 2); l323 = (l323 + 1)) {
			fRec448[l323] = 0.0;
			
		}
		for (int l324 = 0; (l324 < 2); l324 = (l324 + 1)) {
			fRec447[l324] = 0.0;
			
		}
		for (int l325 = 0; (l325 < 2); l325 = (l325 + 1)) {
			fRec445[l325] = 0.0;
			
		}
		for (int l326 = 0; (l326 < 2); l326 = (l326 + 1)) {
			fRec444[l326] = 0.0;
			
		}
		for (int l327 = 0; (l327 < 2); l327 = (l327 + 1)) {
			fRec442[l327] = 0.0;
			
		}
		for (int l328 = 0; (l328 < 2); l328 = (l328 + 1)) {
			fRec441[l328] = 0.0;
			
		}
		for (int l329 = 0; (l329 < 2); l329 = (l329 + 1)) {
			fRec439[l329] = 0.0;
			
		}
		for (int l330 = 0; (l330 < 2); l330 = (l330 + 1)) {
			fRec471[l330] = 0.0;
			
		}
		for (int l331 = 0; (l331 < 2); l331 = (l331 + 1)) {
			fRec469[l331] = 0.0;
			
		}
		for (int l332 = 0; (l332 < 2); l332 = (l332 + 1)) {
			fRec468[l332] = 0.0;
			
		}
		for (int l333 = 0; (l333 < 2); l333 = (l333 + 1)) {
			fRec466[l333] = 0.0;
			
		}
		for (int l334 = 0; (l334 < 2); l334 = (l334 + 1)) {
			fRec465[l334] = 0.0;
			
		}
		for (int l335 = 0; (l335 < 2); l335 = (l335 + 1)) {
			fRec463[l335] = 0.0;
			
		}
		for (int l336 = 0; (l336 < 2); l336 = (l336 + 1)) {
			fRec462[l336] = 0.0;
			
		}
		for (int l337 = 0; (l337 < 2); l337 = (l337 + 1)) {
			fRec460[l337] = 0.0;
			
		}
		for (int l338 = 0; (l338 < 2); l338 = (l338 + 1)) {
			fRec459[l338] = 0.0;
			
		}
		for (int l339 = 0; (l339 < 2); l339 = (l339 + 1)) {
			fRec457[l339] = 0.0;
			
		}
		for (int l340 = 0; (l340 < 2); l340 = (l340 + 1)) {
			fRec483[l340] = 0.0;
			
		}
		for (int l341 = 0; (l341 < 2); l341 = (l341 + 1)) {
			fRec481[l341] = 0.0;
			
		}
		for (int l342 = 0; (l342 < 2); l342 = (l342 + 1)) {
			fRec480[l342] = 0.0;
			
		}
		for (int l343 = 0; (l343 < 2); l343 = (l343 + 1)) {
			fRec478[l343] = 0.0;
			
		}
		for (int l344 = 0; (l344 < 2); l344 = (l344 + 1)) {
			fRec477[l344] = 0.0;
			
		}
		for (int l345 = 0; (l345 < 2); l345 = (l345 + 1)) {
			fRec475[l345] = 0.0;
			
		}
		for (int l346 = 0; (l346 < 2); l346 = (l346 + 1)) {
			fRec474[l346] = 0.0;
			
		}
		for (int l347 = 0; (l347 < 2); l347 = (l347 + 1)) {
			fRec472[l347] = 0.0;
			
		}
		for (int l348 = 0; (l348 < 2); l348 = (l348 + 1)) {
			fRec492[l348] = 0.0;
			
		}
		for (int l349 = 0; (l349 < 2); l349 = (l349 + 1)) {
			fRec490[l349] = 0.0;
			
		}
		for (int l350 = 0; (l350 < 2); l350 = (l350 + 1)) {
			fRec489[l350] = 0.0;
			
		}
		for (int l351 = 0; (l351 < 2); l351 = (l351 + 1)) {
			fRec487[l351] = 0.0;
			
		}
		for (int l352 = 0; (l352 < 2); l352 = (l352 + 1)) {
			fRec486[l352] = 0.0;
			
		}
		for (int l353 = 0; (l353 < 2); l353 = (l353 + 1)) {
			fRec484[l353] = 0.0;
			
		}
		for (int l354 = 0; (l354 < 2); l354 = (l354 + 1)) {
			fRec495[l354] = 0.0;
			
		}
		for (int l355 = 0; (l355 < 2); l355 = (l355 + 1)) {
			fRec493[l355] = 0.0;
			
		}
		for (int l356 = 0; (l356 < 2); l356 = (l356 + 1)) {
			fRec501[l356] = 0.0;
			
		}
		for (int l357 = 0; (l357 < 2); l357 = (l357 + 1)) {
			fRec499[l357] = 0.0;
			
		}
		for (int l358 = 0; (l358 < 2); l358 = (l358 + 1)) {
			fRec498[l358] = 0.0;
			
		}
		for (int l359 = 0; (l359 < 2); l359 = (l359 + 1)) {
			fRec496[l359] = 0.0;
			
		}
		for (int l360 = 0; (l360 < 128); l360 = (l360 + 1)) {
			fVec5[l360] = 0.0;
			
		}
		for (int l361 = 0; (l361 < 2); l361 = (l361 + 1)) {
			fRec519[l361] = 0.0;
			
		}
		for (int l362 = 0; (l362 < 2); l362 = (l362 + 1)) {
			fRec517[l362] = 0.0;
			
		}
		for (int l363 = 0; (l363 < 2); l363 = (l363 + 1)) {
			fRec516[l363] = 0.0;
			
		}
		for (int l364 = 0; (l364 < 2); l364 = (l364 + 1)) {
			fRec514[l364] = 0.0;
			
		}
		for (int l365 = 0; (l365 < 2); l365 = (l365 + 1)) {
			fRec513[l365] = 0.0;
			
		}
		for (int l366 = 0; (l366 < 2); l366 = (l366 + 1)) {
			fRec511[l366] = 0.0;
			
		}
		for (int l367 = 0; (l367 < 2); l367 = (l367 + 1)) {
			fRec510[l367] = 0.0;
			
		}
		for (int l368 = 0; (l368 < 2); l368 = (l368 + 1)) {
			fRec508[l368] = 0.0;
			
		}
		for (int l369 = 0; (l369 < 2); l369 = (l369 + 1)) {
			fRec507[l369] = 0.0;
			
		}
		for (int l370 = 0; (l370 < 2); l370 = (l370 + 1)) {
			fRec505[l370] = 0.0;
			
		}
		for (int l371 = 0; (l371 < 2); l371 = (l371 + 1)) {
			fRec504[l371] = 0.0;
			
		}
		for (int l372 = 0; (l372 < 2); l372 = (l372 + 1)) {
			fRec502[l372] = 0.0;
			
		}
		for (int l373 = 0; (l373 < 2); l373 = (l373 + 1)) {
			fRec534[l373] = 0.0;
			
		}
		for (int l374 = 0; (l374 < 2); l374 = (l374 + 1)) {
			fRec532[l374] = 0.0;
			
		}
		for (int l375 = 0; (l375 < 2); l375 = (l375 + 1)) {
			fRec531[l375] = 0.0;
			
		}
		for (int l376 = 0; (l376 < 2); l376 = (l376 + 1)) {
			fRec529[l376] = 0.0;
			
		}
		for (int l377 = 0; (l377 < 2); l377 = (l377 + 1)) {
			fRec528[l377] = 0.0;
			
		}
		for (int l378 = 0; (l378 < 2); l378 = (l378 + 1)) {
			fRec526[l378] = 0.0;
			
		}
		for (int l379 = 0; (l379 < 2); l379 = (l379 + 1)) {
			fRec525[l379] = 0.0;
			
		}
		for (int l380 = 0; (l380 < 2); l380 = (l380 + 1)) {
			fRec523[l380] = 0.0;
			
		}
		for (int l381 = 0; (l381 < 2); l381 = (l381 + 1)) {
			fRec522[l381] = 0.0;
			
		}
		for (int l382 = 0; (l382 < 2); l382 = (l382 + 1)) {
			fRec520[l382] = 0.0;
			
		}
		for (int l383 = 0; (l383 < 2); l383 = (l383 + 1)) {
			fRec546[l383] = 0.0;
			
		}
		for (int l384 = 0; (l384 < 2); l384 = (l384 + 1)) {
			fRec544[l384] = 0.0;
			
		}
		for (int l385 = 0; (l385 < 2); l385 = (l385 + 1)) {
			fRec543[l385] = 0.0;
			
		}
		for (int l386 = 0; (l386 < 2); l386 = (l386 + 1)) {
			fRec541[l386] = 0.0;
			
		}
		for (int l387 = 0; (l387 < 2); l387 = (l387 + 1)) {
			fRec540[l387] = 0.0;
			
		}
		for (int l388 = 0; (l388 < 2); l388 = (l388 + 1)) {
			fRec538[l388] = 0.0;
			
		}
		for (int l389 = 0; (l389 < 2); l389 = (l389 + 1)) {
			fRec537[l389] = 0.0;
			
		}
		for (int l390 = 0; (l390 < 2); l390 = (l390 + 1)) {
			fRec535[l390] = 0.0;
			
		}
		for (int l391 = 0; (l391 < 2); l391 = (l391 + 1)) {
			fRec555[l391] = 0.0;
			
		}
		for (int l392 = 0; (l392 < 2); l392 = (l392 + 1)) {
			fRec553[l392] = 0.0;
			
		}
		for (int l393 = 0; (l393 < 2); l393 = (l393 + 1)) {
			fRec552[l393] = 0.0;
			
		}
		for (int l394 = 0; (l394 < 2); l394 = (l394 + 1)) {
			fRec550[l394] = 0.0;
			
		}
		for (int l395 = 0; (l395 < 2); l395 = (l395 + 1)) {
			fRec549[l395] = 0.0;
			
		}
		for (int l396 = 0; (l396 < 2); l396 = (l396 + 1)) {
			fRec547[l396] = 0.0;
			
		}
		for (int l397 = 0; (l397 < 2); l397 = (l397 + 1)) {
			fRec558[l397] = 0.0;
			
		}
		for (int l398 = 0; (l398 < 2); l398 = (l398 + 1)) {
			fRec556[l398] = 0.0;
			
		}
		for (int l399 = 0; (l399 < 2); l399 = (l399 + 1)) {
			fRec564[l399] = 0.0;
			
		}
		for (int l400 = 0; (l400 < 2); l400 = (l400 + 1)) {
			fRec562[l400] = 0.0;
			
		}
		for (int l401 = 0; (l401 < 2); l401 = (l401 + 1)) {
			fRec561[l401] = 0.0;
			
		}
		for (int l402 = 0; (l402 < 2); l402 = (l402 + 1)) {
			fRec559[l402] = 0.0;
			
		}
		for (int l403 = 0; (l403 < 64); l403 = (l403 + 1)) {
			fVec6[l403] = 0.0;
			
		}
		for (int l404 = 0; (l404 < 2); l404 = (l404 + 1)) {
			fRec582[l404] = 0.0;
			
		}
		for (int l405 = 0; (l405 < 2); l405 = (l405 + 1)) {
			fRec580[l405] = 0.0;
			
		}
		for (int l406 = 0; (l406 < 2); l406 = (l406 + 1)) {
			fRec579[l406] = 0.0;
			
		}
		for (int l407 = 0; (l407 < 2); l407 = (l407 + 1)) {
			fRec577[l407] = 0.0;
			
		}
		for (int l408 = 0; (l408 < 2); l408 = (l408 + 1)) {
			fRec576[l408] = 0.0;
			
		}
		for (int l409 = 0; (l409 < 2); l409 = (l409 + 1)) {
			fRec574[l409] = 0.0;
			
		}
		for (int l410 = 0; (l410 < 2); l410 = (l410 + 1)) {
			fRec573[l410] = 0.0;
			
		}
		for (int l411 = 0; (l411 < 2); l411 = (l411 + 1)) {
			fRec571[l411] = 0.0;
			
		}
		for (int l412 = 0; (l412 < 2); l412 = (l412 + 1)) {
			fRec570[l412] = 0.0;
			
		}
		for (int l413 = 0; (l413 < 2); l413 = (l413 + 1)) {
			fRec568[l413] = 0.0;
			
		}
		for (int l414 = 0; (l414 < 2); l414 = (l414 + 1)) {
			fRec567[l414] = 0.0;
			
		}
		for (int l415 = 0; (l415 < 2); l415 = (l415 + 1)) {
			fRec565[l415] = 0.0;
			
		}
		for (int l416 = 0; (l416 < 2); l416 = (l416 + 1)) {
			fRec597[l416] = 0.0;
			
		}
		for (int l417 = 0; (l417 < 2); l417 = (l417 + 1)) {
			fRec595[l417] = 0.0;
			
		}
		for (int l418 = 0; (l418 < 2); l418 = (l418 + 1)) {
			fRec594[l418] = 0.0;
			
		}
		for (int l419 = 0; (l419 < 2); l419 = (l419 + 1)) {
			fRec592[l419] = 0.0;
			
		}
		for (int l420 = 0; (l420 < 2); l420 = (l420 + 1)) {
			fRec591[l420] = 0.0;
			
		}
		for (int l421 = 0; (l421 < 2); l421 = (l421 + 1)) {
			fRec589[l421] = 0.0;
			
		}
		for (int l422 = 0; (l422 < 2); l422 = (l422 + 1)) {
			fRec588[l422] = 0.0;
			
		}
		for (int l423 = 0; (l423 < 2); l423 = (l423 + 1)) {
			fRec586[l423] = 0.0;
			
		}
		for (int l424 = 0; (l424 < 2); l424 = (l424 + 1)) {
			fRec585[l424] = 0.0;
			
		}
		for (int l425 = 0; (l425 < 2); l425 = (l425 + 1)) {
			fRec583[l425] = 0.0;
			
		}
		for (int l426 = 0; (l426 < 2); l426 = (l426 + 1)) {
			fRec609[l426] = 0.0;
			
		}
		for (int l427 = 0; (l427 < 2); l427 = (l427 + 1)) {
			fRec607[l427] = 0.0;
			
		}
		for (int l428 = 0; (l428 < 2); l428 = (l428 + 1)) {
			fRec606[l428] = 0.0;
			
		}
		for (int l429 = 0; (l429 < 2); l429 = (l429 + 1)) {
			fRec604[l429] = 0.0;
			
		}
		for (int l430 = 0; (l430 < 2); l430 = (l430 + 1)) {
			fRec603[l430] = 0.0;
			
		}
		for (int l431 = 0; (l431 < 2); l431 = (l431 + 1)) {
			fRec601[l431] = 0.0;
			
		}
		for (int l432 = 0; (l432 < 2); l432 = (l432 + 1)) {
			fRec600[l432] = 0.0;
			
		}
		for (int l433 = 0; (l433 < 2); l433 = (l433 + 1)) {
			fRec598[l433] = 0.0;
			
		}
		for (int l434 = 0; (l434 < 2); l434 = (l434 + 1)) {
			fRec618[l434] = 0.0;
			
		}
		for (int l435 = 0; (l435 < 2); l435 = (l435 + 1)) {
			fRec616[l435] = 0.0;
			
		}
		for (int l436 = 0; (l436 < 2); l436 = (l436 + 1)) {
			fRec615[l436] = 0.0;
			
		}
		for (int l437 = 0; (l437 < 2); l437 = (l437 + 1)) {
			fRec613[l437] = 0.0;
			
		}
		for (int l438 = 0; (l438 < 2); l438 = (l438 + 1)) {
			fRec612[l438] = 0.0;
			
		}
		for (int l439 = 0; (l439 < 2); l439 = (l439 + 1)) {
			fRec610[l439] = 0.0;
			
		}
		for (int l440 = 0; (l440 < 2); l440 = (l440 + 1)) {
			fRec621[l440] = 0.0;
			
		}
		for (int l441 = 0; (l441 < 2); l441 = (l441 + 1)) {
			fRec619[l441] = 0.0;
			
		}
		for (int l442 = 0; (l442 < 2); l442 = (l442 + 1)) {
			fRec627[l442] = 0.0;
			
		}
		for (int l443 = 0; (l443 < 2); l443 = (l443 + 1)) {
			fRec625[l443] = 0.0;
			
		}
		for (int l444 = 0; (l444 < 2); l444 = (l444 + 1)) {
			fRec624[l444] = 0.0;
			
		}
		for (int l445 = 0; (l445 < 2); l445 = (l445 + 1)) {
			fRec622[l445] = 0.0;
			
		}
		for (int l446 = 0; (l446 < 256); l446 = (l446 + 1)) {
			fVec7[l446] = 0.0;
			
		}
		for (int l447 = 0; (l447 < 2); l447 = (l447 + 1)) {
			fRec645[l447] = 0.0;
			
		}
		for (int l448 = 0; (l448 < 2); l448 = (l448 + 1)) {
			fRec643[l448] = 0.0;
			
		}
		for (int l449 = 0; (l449 < 2); l449 = (l449 + 1)) {
			fRec642[l449] = 0.0;
			
		}
		for (int l450 = 0; (l450 < 2); l450 = (l450 + 1)) {
			fRec640[l450] = 0.0;
			
		}
		for (int l451 = 0; (l451 < 2); l451 = (l451 + 1)) {
			fRec639[l451] = 0.0;
			
		}
		for (int l452 = 0; (l452 < 2); l452 = (l452 + 1)) {
			fRec637[l452] = 0.0;
			
		}
		for (int l453 = 0; (l453 < 2); l453 = (l453 + 1)) {
			fRec636[l453] = 0.0;
			
		}
		for (int l454 = 0; (l454 < 2); l454 = (l454 + 1)) {
			fRec634[l454] = 0.0;
			
		}
		for (int l455 = 0; (l455 < 2); l455 = (l455 + 1)) {
			fRec633[l455] = 0.0;
			
		}
		for (int l456 = 0; (l456 < 2); l456 = (l456 + 1)) {
			fRec631[l456] = 0.0;
			
		}
		for (int l457 = 0; (l457 < 2); l457 = (l457 + 1)) {
			fRec630[l457] = 0.0;
			
		}
		for (int l458 = 0; (l458 < 2); l458 = (l458 + 1)) {
			fRec628[l458] = 0.0;
			
		}
		for (int l459 = 0; (l459 < 2); l459 = (l459 + 1)) {
			fRec660[l459] = 0.0;
			
		}
		for (int l460 = 0; (l460 < 2); l460 = (l460 + 1)) {
			fRec658[l460] = 0.0;
			
		}
		for (int l461 = 0; (l461 < 2); l461 = (l461 + 1)) {
			fRec657[l461] = 0.0;
			
		}
		for (int l462 = 0; (l462 < 2); l462 = (l462 + 1)) {
			fRec655[l462] = 0.0;
			
		}
		for (int l463 = 0; (l463 < 2); l463 = (l463 + 1)) {
			fRec654[l463] = 0.0;
			
		}
		for (int l464 = 0; (l464 < 2); l464 = (l464 + 1)) {
			fRec652[l464] = 0.0;
			
		}
		for (int l465 = 0; (l465 < 2); l465 = (l465 + 1)) {
			fRec651[l465] = 0.0;
			
		}
		for (int l466 = 0; (l466 < 2); l466 = (l466 + 1)) {
			fRec649[l466] = 0.0;
			
		}
		for (int l467 = 0; (l467 < 2); l467 = (l467 + 1)) {
			fRec648[l467] = 0.0;
			
		}
		for (int l468 = 0; (l468 < 2); l468 = (l468 + 1)) {
			fRec646[l468] = 0.0;
			
		}
		for (int l469 = 0; (l469 < 2); l469 = (l469 + 1)) {
			fRec672[l469] = 0.0;
			
		}
		for (int l470 = 0; (l470 < 2); l470 = (l470 + 1)) {
			fRec670[l470] = 0.0;
			
		}
		for (int l471 = 0; (l471 < 2); l471 = (l471 + 1)) {
			fRec669[l471] = 0.0;
			
		}
		for (int l472 = 0; (l472 < 2); l472 = (l472 + 1)) {
			fRec667[l472] = 0.0;
			
		}
		for (int l473 = 0; (l473 < 2); l473 = (l473 + 1)) {
			fRec666[l473] = 0.0;
			
		}
		for (int l474 = 0; (l474 < 2); l474 = (l474 + 1)) {
			fRec664[l474] = 0.0;
			
		}
		for (int l475 = 0; (l475 < 2); l475 = (l475 + 1)) {
			fRec663[l475] = 0.0;
			
		}
		for (int l476 = 0; (l476 < 2); l476 = (l476 + 1)) {
			fRec661[l476] = 0.0;
			
		}
		for (int l477 = 0; (l477 < 2); l477 = (l477 + 1)) {
			fRec681[l477] = 0.0;
			
		}
		for (int l478 = 0; (l478 < 2); l478 = (l478 + 1)) {
			fRec679[l478] = 0.0;
			
		}
		for (int l479 = 0; (l479 < 2); l479 = (l479 + 1)) {
			fRec678[l479] = 0.0;
			
		}
		for (int l480 = 0; (l480 < 2); l480 = (l480 + 1)) {
			fRec676[l480] = 0.0;
			
		}
		for (int l481 = 0; (l481 < 2); l481 = (l481 + 1)) {
			fRec675[l481] = 0.0;
			
		}
		for (int l482 = 0; (l482 < 2); l482 = (l482 + 1)) {
			fRec673[l482] = 0.0;
			
		}
		for (int l483 = 0; (l483 < 2); l483 = (l483 + 1)) {
			fRec684[l483] = 0.0;
			
		}
		for (int l484 = 0; (l484 < 2); l484 = (l484 + 1)) {
			fRec682[l484] = 0.0;
			
		}
		for (int l485 = 0; (l485 < 2); l485 = (l485 + 1)) {
			fRec690[l485] = 0.0;
			
		}
		for (int l486 = 0; (l486 < 2); l486 = (l486 + 1)) {
			fRec688[l486] = 0.0;
			
		}
		for (int l487 = 0; (l487 < 2); l487 = (l487 + 1)) {
			fRec687[l487] = 0.0;
			
		}
		for (int l488 = 0; (l488 < 2); l488 = (l488 + 1)) {
			fRec685[l488] = 0.0;
			
		}
		for (int l489 = 0; (l489 < 256); l489 = (l489 + 1)) {
			fVec8[l489] = 0.0;
			
		}
		for (int l490 = 0; (l490 < 2); l490 = (l490 + 1)) {
			fRec702[l490] = 0.0;
			
		}
		for (int l491 = 0; (l491 < 2); l491 = (l491 + 1)) {
			fRec700[l491] = 0.0;
			
		}
		for (int l492 = 0; (l492 < 2); l492 = (l492 + 1)) {
			fRec699[l492] = 0.0;
			
		}
		for (int l493 = 0; (l493 < 2); l493 = (l493 + 1)) {
			fRec697[l493] = 0.0;
			
		}
		for (int l494 = 0; (l494 < 2); l494 = (l494 + 1)) {
			fRec696[l494] = 0.0;
			
		}
		for (int l495 = 0; (l495 < 2); l495 = (l495 + 1)) {
			fRec694[l495] = 0.0;
			
		}
		for (int l496 = 0; (l496 < 2); l496 = (l496 + 1)) {
			fRec693[l496] = 0.0;
			
		}
		for (int l497 = 0; (l497 < 2); l497 = (l497 + 1)) {
			fRec691[l497] = 0.0;
			
		}
		for (int l498 = 0; (l498 < 2); l498 = (l498 + 1)) {
			fRec711[l498] = 0.0;
			
		}
		for (int l499 = 0; (l499 < 2); l499 = (l499 + 1)) {
			fRec709[l499] = 0.0;
			
		}
		for (int l500 = 0; (l500 < 2); l500 = (l500 + 1)) {
			fRec708[l500] = 0.0;
			
		}
		for (int l501 = 0; (l501 < 2); l501 = (l501 + 1)) {
			fRec706[l501] = 0.0;
			
		}
		for (int l502 = 0; (l502 < 2); l502 = (l502 + 1)) {
			fRec705[l502] = 0.0;
			
		}
		for (int l503 = 0; (l503 < 2); l503 = (l503 + 1)) {
			fRec703[l503] = 0.0;
			
		}
		for (int l504 = 0; (l504 < 2); l504 = (l504 + 1)) {
			fRec714[l504] = 0.0;
			
		}
		for (int l505 = 0; (l505 < 2); l505 = (l505 + 1)) {
			fRec712[l505] = 0.0;
			
		}
		for (int l506 = 0; (l506 < 2); l506 = (l506 + 1)) {
			fRec720[l506] = 0.0;
			
		}
		for (int l507 = 0; (l507 < 2); l507 = (l507 + 1)) {
			fRec718[l507] = 0.0;
			
		}
		for (int l508 = 0; (l508 < 2); l508 = (l508 + 1)) {
			fRec717[l508] = 0.0;
			
		}
		for (int l509 = 0; (l509 < 2); l509 = (l509 + 1)) {
			fRec715[l509] = 0.0;
			
		}
		for (int l510 = 0; (l510 < 2); l510 = (l510 + 1)) {
			fRec735[l510] = 0.0;
			
		}
		for (int l511 = 0; (l511 < 2); l511 = (l511 + 1)) {
			fRec733[l511] = 0.0;
			
		}
		for (int l512 = 0; (l512 < 2); l512 = (l512 + 1)) {
			fRec732[l512] = 0.0;
			
		}
		for (int l513 = 0; (l513 < 2); l513 = (l513 + 1)) {
			fRec730[l513] = 0.0;
			
		}
		for (int l514 = 0; (l514 < 2); l514 = (l514 + 1)) {
			fRec729[l514] = 0.0;
			
		}
		for (int l515 = 0; (l515 < 2); l515 = (l515 + 1)) {
			fRec727[l515] = 0.0;
			
		}
		for (int l516 = 0; (l516 < 2); l516 = (l516 + 1)) {
			fRec726[l516] = 0.0;
			
		}
		for (int l517 = 0; (l517 < 2); l517 = (l517 + 1)) {
			fRec724[l517] = 0.0;
			
		}
		for (int l518 = 0; (l518 < 2); l518 = (l518 + 1)) {
			fRec723[l518] = 0.0;
			
		}
		for (int l519 = 0; (l519 < 2); l519 = (l519 + 1)) {
			fRec721[l519] = 0.0;
			
		}
		for (int l520 = 0; (l520 < 2); l520 = (l520 + 1)) {
			fRec753[l520] = 0.0;
			
		}
		for (int l521 = 0; (l521 < 2); l521 = (l521 + 1)) {
			fRec751[l521] = 0.0;
			
		}
		for (int l522 = 0; (l522 < 2); l522 = (l522 + 1)) {
			fRec750[l522] = 0.0;
			
		}
		for (int l523 = 0; (l523 < 2); l523 = (l523 + 1)) {
			fRec748[l523] = 0.0;
			
		}
		for (int l524 = 0; (l524 < 2); l524 = (l524 + 1)) {
			fRec747[l524] = 0.0;
			
		}
		for (int l525 = 0; (l525 < 2); l525 = (l525 + 1)) {
			fRec745[l525] = 0.0;
			
		}
		for (int l526 = 0; (l526 < 2); l526 = (l526 + 1)) {
			fRec744[l526] = 0.0;
			
		}
		for (int l527 = 0; (l527 < 2); l527 = (l527 + 1)) {
			fRec742[l527] = 0.0;
			
		}
		for (int l528 = 0; (l528 < 2); l528 = (l528 + 1)) {
			fRec741[l528] = 0.0;
			
		}
		for (int l529 = 0; (l529 < 2); l529 = (l529 + 1)) {
			fRec739[l529] = 0.0;
			
		}
		for (int l530 = 0; (l530 < 2); l530 = (l530 + 1)) {
			fRec738[l530] = 0.0;
			
		}
		for (int l531 = 0; (l531 < 2); l531 = (l531 + 1)) {
			fRec736[l531] = 0.0;
			
		}
		for (int l532 = 0; (l532 < 256); l532 = (l532 + 1)) {
			fVec9[l532] = 0.0;
			
		}
		for (int l533 = 0; (l533 < 2); l533 = (l533 + 1)) {
			fRec756[l533] = 0.0;
			
		}
		for (int l534 = 0; (l534 < 2); l534 = (l534 + 1)) {
			fRec754[l534] = 0.0;
			
		}
		for (int l535 = 0; (l535 < 2); l535 = (l535 + 1)) {
			fRec762[l535] = 0.0;
			
		}
		for (int l536 = 0; (l536 < 2); l536 = (l536 + 1)) {
			fRec760[l536] = 0.0;
			
		}
		for (int l537 = 0; (l537 < 2); l537 = (l537 + 1)) {
			fRec759[l537] = 0.0;
			
		}
		for (int l538 = 0; (l538 < 2); l538 = (l538 + 1)) {
			fRec757[l538] = 0.0;
			
		}
		for (int l539 = 0; (l539 < 2); l539 = (l539 + 1)) {
			fRec771[l539] = 0.0;
			
		}
		for (int l540 = 0; (l540 < 2); l540 = (l540 + 1)) {
			fRec769[l540] = 0.0;
			
		}
		for (int l541 = 0; (l541 < 2); l541 = (l541 + 1)) {
			fRec768[l541] = 0.0;
			
		}
		for (int l542 = 0; (l542 < 2); l542 = (l542 + 1)) {
			fRec766[l542] = 0.0;
			
		}
		for (int l543 = 0; (l543 < 2); l543 = (l543 + 1)) {
			fRec765[l543] = 0.0;
			
		}
		for (int l544 = 0; (l544 < 2); l544 = (l544 + 1)) {
			fRec763[l544] = 0.0;
			
		}
		for (int l545 = 0; (l545 < 2); l545 = (l545 + 1)) {
			fRec783[l545] = 0.0;
			
		}
		for (int l546 = 0; (l546 < 2); l546 = (l546 + 1)) {
			fRec781[l546] = 0.0;
			
		}
		for (int l547 = 0; (l547 < 2); l547 = (l547 + 1)) {
			fRec780[l547] = 0.0;
			
		}
		for (int l548 = 0; (l548 < 2); l548 = (l548 + 1)) {
			fRec778[l548] = 0.0;
			
		}
		for (int l549 = 0; (l549 < 2); l549 = (l549 + 1)) {
			fRec777[l549] = 0.0;
			
		}
		for (int l550 = 0; (l550 < 2); l550 = (l550 + 1)) {
			fRec775[l550] = 0.0;
			
		}
		for (int l551 = 0; (l551 < 2); l551 = (l551 + 1)) {
			fRec774[l551] = 0.0;
			
		}
		for (int l552 = 0; (l552 < 2); l552 = (l552 + 1)) {
			fRec772[l552] = 0.0;
			
		}
		for (int l553 = 0; (l553 < 2); l553 = (l553 + 1)) {
			fRec798[l553] = 0.0;
			
		}
		for (int l554 = 0; (l554 < 2); l554 = (l554 + 1)) {
			fRec796[l554] = 0.0;
			
		}
		for (int l555 = 0; (l555 < 2); l555 = (l555 + 1)) {
			fRec795[l555] = 0.0;
			
		}
		for (int l556 = 0; (l556 < 2); l556 = (l556 + 1)) {
			fRec793[l556] = 0.0;
			
		}
		for (int l557 = 0; (l557 < 2); l557 = (l557 + 1)) {
			fRec792[l557] = 0.0;
			
		}
		for (int l558 = 0; (l558 < 2); l558 = (l558 + 1)) {
			fRec790[l558] = 0.0;
			
		}
		for (int l559 = 0; (l559 < 2); l559 = (l559 + 1)) {
			fRec789[l559] = 0.0;
			
		}
		for (int l560 = 0; (l560 < 2); l560 = (l560 + 1)) {
			fRec787[l560] = 0.0;
			
		}
		for (int l561 = 0; (l561 < 2); l561 = (l561 + 1)) {
			fRec786[l561] = 0.0;
			
		}
		for (int l562 = 0; (l562 < 2); l562 = (l562 + 1)) {
			fRec784[l562] = 0.0;
			
		}
		for (int l563 = 0; (l563 < 2); l563 = (l563 + 1)) {
			fRec816[l563] = 0.0;
			
		}
		for (int l564 = 0; (l564 < 2); l564 = (l564 + 1)) {
			fRec814[l564] = 0.0;
			
		}
		for (int l565 = 0; (l565 < 2); l565 = (l565 + 1)) {
			fRec813[l565] = 0.0;
			
		}
		for (int l566 = 0; (l566 < 2); l566 = (l566 + 1)) {
			fRec811[l566] = 0.0;
			
		}
		for (int l567 = 0; (l567 < 2); l567 = (l567 + 1)) {
			fRec810[l567] = 0.0;
			
		}
		for (int l568 = 0; (l568 < 2); l568 = (l568 + 1)) {
			fRec808[l568] = 0.0;
			
		}
		for (int l569 = 0; (l569 < 2); l569 = (l569 + 1)) {
			fRec807[l569] = 0.0;
			
		}
		for (int l570 = 0; (l570 < 2); l570 = (l570 + 1)) {
			fRec805[l570] = 0.0;
			
		}
		for (int l571 = 0; (l571 < 2); l571 = (l571 + 1)) {
			fRec804[l571] = 0.0;
			
		}
		for (int l572 = 0; (l572 < 2); l572 = (l572 + 1)) {
			fRec802[l572] = 0.0;
			
		}
		for (int l573 = 0; (l573 < 2); l573 = (l573 + 1)) {
			fRec801[l573] = 0.0;
			
		}
		for (int l574 = 0; (l574 < 2); l574 = (l574 + 1)) {
			fRec799[l574] = 0.0;
			
		}
		for (int l575 = 0; (l575 < 256); l575 = (l575 + 1)) {
			fVec10[l575] = 0.0;
			
		}
		for (int l576 = 0; (l576 < 2); l576 = (l576 + 1)) {
			fRec819[l576] = 0.0;
			
		}
		for (int l577 = 0; (l577 < 2); l577 = (l577 + 1)) {
			fRec817[l577] = 0.0;
			
		}
		for (int l578 = 0; (l578 < 2); l578 = (l578 + 1)) {
			fRec825[l578] = 0.0;
			
		}
		for (int l579 = 0; (l579 < 2); l579 = (l579 + 1)) {
			fRec823[l579] = 0.0;
			
		}
		for (int l580 = 0; (l580 < 2); l580 = (l580 + 1)) {
			fRec822[l580] = 0.0;
			
		}
		for (int l581 = 0; (l581 < 2); l581 = (l581 + 1)) {
			fRec820[l581] = 0.0;
			
		}
		for (int l582 = 0; (l582 < 2); l582 = (l582 + 1)) {
			fRec834[l582] = 0.0;
			
		}
		for (int l583 = 0; (l583 < 2); l583 = (l583 + 1)) {
			fRec832[l583] = 0.0;
			
		}
		for (int l584 = 0; (l584 < 2); l584 = (l584 + 1)) {
			fRec831[l584] = 0.0;
			
		}
		for (int l585 = 0; (l585 < 2); l585 = (l585 + 1)) {
			fRec829[l585] = 0.0;
			
		}
		for (int l586 = 0; (l586 < 2); l586 = (l586 + 1)) {
			fRec828[l586] = 0.0;
			
		}
		for (int l587 = 0; (l587 < 2); l587 = (l587 + 1)) {
			fRec826[l587] = 0.0;
			
		}
		for (int l588 = 0; (l588 < 2); l588 = (l588 + 1)) {
			fRec846[l588] = 0.0;
			
		}
		for (int l589 = 0; (l589 < 2); l589 = (l589 + 1)) {
			fRec844[l589] = 0.0;
			
		}
		for (int l590 = 0; (l590 < 2); l590 = (l590 + 1)) {
			fRec843[l590] = 0.0;
			
		}
		for (int l591 = 0; (l591 < 2); l591 = (l591 + 1)) {
			fRec841[l591] = 0.0;
			
		}
		for (int l592 = 0; (l592 < 2); l592 = (l592 + 1)) {
			fRec840[l592] = 0.0;
			
		}
		for (int l593 = 0; (l593 < 2); l593 = (l593 + 1)) {
			fRec838[l593] = 0.0;
			
		}
		for (int l594 = 0; (l594 < 2); l594 = (l594 + 1)) {
			fRec837[l594] = 0.0;
			
		}
		for (int l595 = 0; (l595 < 2); l595 = (l595 + 1)) {
			fRec835[l595] = 0.0;
			
		}
		for (int l596 = 0; (l596 < 2); l596 = (l596 + 1)) {
			fRec861[l596] = 0.0;
			
		}
		for (int l597 = 0; (l597 < 2); l597 = (l597 + 1)) {
			fRec859[l597] = 0.0;
			
		}
		for (int l598 = 0; (l598 < 2); l598 = (l598 + 1)) {
			fRec858[l598] = 0.0;
			
		}
		for (int l599 = 0; (l599 < 2); l599 = (l599 + 1)) {
			fRec856[l599] = 0.0;
			
		}
		for (int l600 = 0; (l600 < 2); l600 = (l600 + 1)) {
			fRec855[l600] = 0.0;
			
		}
		for (int l601 = 0; (l601 < 2); l601 = (l601 + 1)) {
			fRec853[l601] = 0.0;
			
		}
		for (int l602 = 0; (l602 < 2); l602 = (l602 + 1)) {
			fRec852[l602] = 0.0;
			
		}
		for (int l603 = 0; (l603 < 2); l603 = (l603 + 1)) {
			fRec850[l603] = 0.0;
			
		}
		for (int l604 = 0; (l604 < 2); l604 = (l604 + 1)) {
			fRec849[l604] = 0.0;
			
		}
		for (int l605 = 0; (l605 < 2); l605 = (l605 + 1)) {
			fRec847[l605] = 0.0;
			
		}
		for (int l606 = 0; (l606 < 2); l606 = (l606 + 1)) {
			fRec879[l606] = 0.0;
			
		}
		for (int l607 = 0; (l607 < 2); l607 = (l607 + 1)) {
			fRec877[l607] = 0.0;
			
		}
		for (int l608 = 0; (l608 < 2); l608 = (l608 + 1)) {
			fRec876[l608] = 0.0;
			
		}
		for (int l609 = 0; (l609 < 2); l609 = (l609 + 1)) {
			fRec874[l609] = 0.0;
			
		}
		for (int l610 = 0; (l610 < 2); l610 = (l610 + 1)) {
			fRec873[l610] = 0.0;
			
		}
		for (int l611 = 0; (l611 < 2); l611 = (l611 + 1)) {
			fRec871[l611] = 0.0;
			
		}
		for (int l612 = 0; (l612 < 2); l612 = (l612 + 1)) {
			fRec870[l612] = 0.0;
			
		}
		for (int l613 = 0; (l613 < 2); l613 = (l613 + 1)) {
			fRec868[l613] = 0.0;
			
		}
		for (int l614 = 0; (l614 < 2); l614 = (l614 + 1)) {
			fRec867[l614] = 0.0;
			
		}
		for (int l615 = 0; (l615 < 2); l615 = (l615 + 1)) {
			fRec865[l615] = 0.0;
			
		}
		for (int l616 = 0; (l616 < 2); l616 = (l616 + 1)) {
			fRec864[l616] = 0.0;
			
		}
		for (int l617 = 0; (l617 < 2); l617 = (l617 + 1)) {
			fRec862[l617] = 0.0;
			
		}
		for (int l618 = 0; (l618 < 1024); l618 = (l618 + 1)) {
			fVec11[l618] = 0.0;
			
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
		ui_interface->openVerticalBox("KMH114_AE_7h7v_normal_4");
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
		FAUSTFLOAT* input36 = inputs[36];
		FAUSTFLOAT* input37 = inputs[37];
		FAUSTFLOAT* input38 = inputs[38];
		FAUSTFLOAT* input39 = inputs[39];
		FAUSTFLOAT* input40 = inputs[40];
		FAUSTFLOAT* input41 = inputs[41];
		FAUSTFLOAT* input42 = inputs[42];
		FAUSTFLOAT* input43 = inputs[43];
		FAUSTFLOAT* input44 = inputs[44];
		FAUSTFLOAT* input45 = inputs[45];
		FAUSTFLOAT* input46 = inputs[46];
		FAUSTFLOAT* input47 = inputs[47];
		FAUSTFLOAT* input48 = inputs[48];
		FAUSTFLOAT* input49 = inputs[49];
		FAUSTFLOAT* input50 = inputs[50];
		FAUSTFLOAT* input51 = inputs[51];
		FAUSTFLOAT* input52 = inputs[52];
		FAUSTFLOAT* input53 = inputs[53];
		FAUSTFLOAT* input54 = inputs[54];
		FAUSTFLOAT* input55 = inputs[55];
		FAUSTFLOAT* input56 = inputs[56];
		FAUSTFLOAT* input57 = inputs[57];
		FAUSTFLOAT* input58 = inputs[58];
		FAUSTFLOAT* input59 = inputs[59];
		FAUSTFLOAT* input60 = inputs[60];
		FAUSTFLOAT* input61 = inputs[61];
		FAUSTFLOAT* input62 = inputs[62];
		FAUSTFLOAT* input63 = inputs[63];
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
			fRec2[0] = (double(input61[i]) - (((fTemp2 * fRec2[2]) + (2.0 * (fTemp3 * fRec2[1]))) / fTemp4));
			fRec3[0] = (fSlow2 + (0.999 * fRec3[1]));
			double fTemp5 = (fRec3[0] * fTemp4);
			double fTemp6 = (0.0 - (2.0 / fTemp4));
			double fTemp7 = (((fTemp1 * (fRec2[2] + (fRec2[0] + (2.0 * fRec2[1])))) / fTemp5) + (0.12574553229999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec2[1]) + ((fRec2[0] + fRec2[2]) / fTemp4))))));
			fRec4[0] = (double(input59[i]) - (((fTemp2 * fRec4[2]) + (2.0 * (fTemp3 * fRec4[1]))) / fTemp4));
			double fTemp8 = (((fTemp1 * (fRec4[2] + (fRec4[0] + (2.0 * fRec4[1])))) / fTemp5) + (0.12574553229999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec4[1]) + ((fRec4[0] + fRec4[2]) / fTemp4))))));
			fRec5[0] = (double(input56[i]) - (((fTemp2 * fRec5[2]) + (2.0 * (fTemp3 * fRec5[1]))) / fTemp4));
			double fTemp9 = (((fTemp1 * (fRec5[2] + (fRec5[0] + (2.0 * fRec5[1])))) / fTemp5) + (0.12574553229999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec5[1]) + ((fRec5[0] + fRec5[2]) / fTemp4))))));
			fRec6[0] = (double(input53[i]) - (((fTemp2 * fRec6[2]) + (2.0 * (fTemp3 * fRec6[1]))) / fTemp4));
			double fTemp10 = (((fTemp1 * (fRec6[2] + (fRec6[0] + (2.0 * fRec6[1])))) / fTemp5) + (0.12574553229999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec6[1]) + ((fRec6[0] + fRec6[2]) / fTemp4))))));
			fRec7[0] = (double(input50[i]) - (((fTemp2 * fRec7[2]) + (2.0 * (fTemp3 * fRec7[1]))) / fTemp4));
			double fTemp11 = (((fTemp1 * (fRec7[2] + (fRec7[0] + (2.0 * fRec7[1])))) / fTemp5) + (0.12574553229999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec7[1]) + ((fRec7[0] + fRec7[2]) / fTemp4))))));
			fRec8[0] = (double(input0[i]) - (((fRec8[2] * fTemp2) + (2.0 * (fRec8[1] * fTemp3))) / fTemp4));
			double fTemp12 = (((fTemp1 * (fRec8[2] + (fRec8[0] + (2.0 * fRec8[1])))) / fTemp5) + (0.81116304520000004 * (fRec3[0] * (0.0 - ((fRec8[1] * fTemp6) + ((fRec8[0] + fRec8[2]) / fTemp4))))));
			double fTemp13 = (fConst5 * fRec9[1]);
			double fTemp14 = (fConst6 * fRec12[1]);
			double fTemp15 = (fConst8 * fRec15[1]);
			double fTemp16 = (fConst9 * fRec18[1]);
			fRec27[0] = (double(input36[i]) - (((fTemp2 * fRec27[2]) + (2.0 * (fTemp3 * fRec27[1]))) / fTemp4));
			double fTemp17 = (((fTemp1 * (fRec27[2] + (fRec27[0] + (2.0 * fRec27[1])))) / fTemp5) + (0.2587546268 * (fRec3[0] * (0.0 - ((fTemp6 * fRec27[1]) + ((fRec27[0] + fRec27[2]) / fTemp4))))));
			fRec28[0] = (double(input37[i]) - (((fTemp2 * fRec28[2]) + (2.0 * (fTemp3 * fRec28[1]))) / fTemp4));
			double fTemp18 = (((fTemp1 * (fRec28[2] + (fRec28[0] + (2.0 * fRec28[1])))) / fTemp5) + (0.2587546268 * (fRec3[0] * (0.0 - ((fTemp6 * fRec28[1]) + ((fRec28[0] + fRec28[2]) / fTemp4))))));
			fRec29[0] = (double(input39[i]) - (((fTemp2 * fRec29[2]) + (2.0 * (fTemp3 * fRec29[1]))) / fTemp4));
			double fTemp19 = (((fTemp1 * (fRec29[2] + (fRec29[0] + (2.0 * fRec29[1])))) / fTemp5) + (0.2587546268 * (fRec3[0] * (0.0 - ((fTemp6 * fRec29[1]) + ((fRec29[0] + fRec29[2]) / fTemp4))))));
			fRec30[0] = (double(input40[i]) - (((fTemp2 * fRec30[2]) + (2.0 * (fTemp3 * fRec30[1]))) / fTemp4));
			double fTemp20 = (((fTemp1 * (fRec30[2] + (fRec30[0] + (2.0 * fRec30[1])))) / fTemp5) + (0.2587546268 * (fRec3[0] * (0.0 - ((fTemp6 * fRec30[1]) + ((fRec30[0] + fRec30[2]) / fTemp4))))));
			fRec31[0] = (double(input44[i]) - (((fTemp2 * fRec31[2]) + (2.0 * (fTemp3 * fRec31[1]))) / fTemp4));
			double fTemp21 = (((fTemp1 * (fRec31[2] + (fRec31[0] + (2.0 * fRec31[1])))) / fTemp5) + (0.2587546268 * (fRec3[0] * (0.0 - ((fTemp6 * fRec31[1]) + ((fRec31[0] + fRec31[2]) / fTemp4))))));
			fRec32[0] = (double(input46[i]) - (((fTemp2 * fRec32[2]) + (2.0 * (fTemp3 * fRec32[1]))) / fTemp4));
			double fTemp22 = (((fTemp1 * (fRec32[2] + (fRec32[0] + (2.0 * fRec32[1])))) / fTemp5) + (0.2587546268 * (fRec3[0] * (0.0 - ((fTemp6 * fRec32[1]) + ((fRec32[0] + fRec32[2]) / fTemp4))))));
			fRec33[0] = (double(input47[i]) - (((fTemp2 * fRec33[2]) + (2.0 * (fTemp3 * fRec33[1]))) / fTemp4));
			double fTemp23 = (((fTemp1 * (fRec33[2] + (fRec33[0] + (2.0 * fRec33[1])))) / fTemp5) + (0.2587546268 * (fRec3[0] * (0.0 - ((fTemp6 * fRec33[1]) + ((fRec33[0] + fRec33[2]) / fTemp4))))));
			fRec34[0] = (double(input38[i]) - (((fTemp2 * fRec34[2]) + (2.0 * (fTemp3 * fRec34[1]))) / fTemp4));
			double fTemp24 = (((fTemp1 * (fRec34[2] + (fRec34[0] + (2.0 * fRec34[1])))) / fTemp5) + (0.2587546268 * (fRec3[0] * (0.0 - ((fTemp6 * fRec34[1]) + ((fRec34[0] + fRec34[2]) / fTemp4))))));
			fRec35[0] = (double(input41[i]) - (((fTemp2 * fRec35[2]) + (2.0 * (fTemp3 * fRec35[1]))) / fTemp4));
			double fTemp25 = (((fTemp1 * (fRec35[2] + (fRec35[0] + (2.0 * fRec35[1])))) / fTemp5) + (0.2587546268 * (fRec3[0] * (0.0 - ((fTemp6 * fRec35[1]) + ((fRec35[0] + fRec35[2]) / fTemp4))))));
			fRec36[0] = (double(input42[i]) - (((fTemp2 * fRec36[2]) + (2.0 * (fTemp3 * fRec36[1]))) / fTemp4));
			double fTemp26 = (((fTemp1 * (fRec36[2] + (fRec36[0] + (2.0 * fRec36[1])))) / fTemp5) + (0.2587546268 * (fRec3[0] * (0.0 - ((fTemp6 * fRec36[1]) + ((fRec36[0] + fRec36[2]) / fTemp4))))));
			fRec37[0] = (double(input43[i]) - (((fTemp2 * fRec37[2]) + (2.0 * (fTemp3 * fRec37[1]))) / fTemp4));
			double fTemp27 = (((fTemp1 * (fRec37[2] + (fRec37[0] + (2.0 * fRec37[1])))) / fTemp5) + (0.2587546268 * (fRec3[0] * (0.0 - ((fTemp6 * fRec37[1]) + ((fRec37[0] + fRec37[2]) / fTemp4))))));
			fRec38[0] = (double(input45[i]) - (((fTemp2 * fRec38[2]) + (2.0 * (fTemp3 * fRec38[1]))) / fTemp4));
			double fTemp28 = (((fTemp1 * (fRec38[2] + (fRec38[0] + (2.0 * fRec38[1])))) / fTemp5) + (0.2587546268 * (fRec3[0] * (0.0 - ((fTemp6 * fRec38[1]) + ((fRec38[0] + fRec38[2]) / fTemp4))))));
			fRec39[0] = (double(input48[i]) - (((fTemp2 * fRec39[2]) + (2.0 * (fTemp3 * fRec39[1]))) / fTemp4));
			double fTemp29 = (((fTemp1 * (fRec39[2] + (fRec39[0] + (2.0 * fRec39[1])))) / fTemp5) + (0.2587546268 * (fRec3[0] * (0.0 - ((fTemp6 * fRec39[1]) + ((fRec39[0] + fRec39[2]) / fTemp4))))));
			double fTemp30 = (fConst11 * ((((((((0.0654561902 * fTemp17) + (0.0087869217999999999 * fTemp18)) + (0.0073721845999999997 * fTemp19)) + (0.054579408199999999 * fTemp20)) + (0.040839996000000003 * fTemp21)) + (0.0043934641000000002 * fTemp22)) + (0.0115667971 * fTemp23)) - ((((((0.076575496800000004 * fTemp24) + (0.0064413515999999999 * fTemp25)) + (0.047681842100000003 * fTemp26)) + (0.0084791703999999996 * fTemp27)) + (0.0097044864999999998 * fTemp28)) + (0.081680659799999999 * fTemp29))));
			double fTemp31 = (fConst12 * fRec21[1]);
			double fTemp32 = (fConst13 * fRec24[1]);
			fRec26[0] = (fTemp30 + (fTemp31 + (fRec26[1] + fTemp32)));
			fRec24[0] = fRec26[0];
			double fRec25 = ((fTemp32 + fTemp31) + fTemp30);
			fRec23[0] = (fRec24[0] + fRec23[1]);
			fRec21[0] = fRec23[0];
			double fRec22 = fRec25;
			fRec20[0] = (fTemp15 + (fTemp16 + (fRec22 + fRec20[1])));
			fRec18[0] = fRec20[0];
			double fRec19 = (fTemp15 + (fRec22 + fTemp16));
			fRec17[0] = (fRec18[0] + fRec17[1]);
			fRec15[0] = fRec17[0];
			double fRec16 = fRec19;
			fRec14[0] = (fTemp13 + (fTemp14 + (fRec16 + fRec14[1])));
			fRec12[0] = fRec14[0];
			double fRec13 = (fTemp13 + (fRec16 + fTemp14));
			fRec11[0] = (fRec12[0] + fRec11[1]);
			fRec9[0] = fRec11[0];
			double fRec10 = fRec13;
			double fTemp33 = (fConst15 * fRec40[1]);
			double fTemp34 = (fConst17 * fRec43[1]);
			double fTemp35 = (fConst18 * fRec46[1]);
			fRec55[0] = (double(input25[i]) - (((fTemp2 * fRec55[2]) + (2.0 * (fTemp3 * fRec55[1]))) / fTemp4));
			double fTemp36 = (((fTemp1 * (fRec55[2] + (fRec55[0] + (2.0 * fRec55[1])))) / fTemp5) + (0.39166900650000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec55[1]) + ((fRec55[0] + fRec55[2]) / fTemp4))))));
			fRec56[0] = (double(input28[i]) - (((fTemp2 * fRec56[2]) + (2.0 * (fTemp3 * fRec56[1]))) / fTemp4));
			double fTemp37 = (((fTemp1 * (fRec56[2] + (fRec56[0] + (2.0 * fRec56[1])))) / fTemp5) + (0.39166900650000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec56[1]) + ((fRec56[0] + fRec56[2]) / fTemp4))))));
			fRec57[0] = (double(input29[i]) - (((fTemp2 * fRec57[2]) + (2.0 * (fTemp3 * fRec57[1]))) / fTemp4));
			double fTemp38 = (((fTemp1 * (fRec57[2] + (fRec57[0] + (2.0 * fRec57[1])))) / fTemp5) + (0.39166900650000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec57[1]) + ((fRec57[0] + fRec57[2]) / fTemp4))))));
			fRec58[0] = (double(input31[i]) - (((fTemp2 * fRec58[2]) + (2.0 * (fTemp3 * fRec58[1]))) / fTemp4));
			double fTemp39 = (((fTemp1 * (fRec58[2] + (fRec58[0] + (2.0 * fRec58[1])))) / fTemp5) + (0.39166900650000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec58[1]) + ((fRec58[0] + fRec58[2]) / fTemp4))))));
			fRec59[0] = (double(input34[i]) - (((fTemp2 * fRec59[2]) + (2.0 * (fTemp3 * fRec59[1]))) / fTemp4));
			double fTemp40 = (((fTemp1 * (fRec59[2] + (fRec59[0] + (2.0 * fRec59[1])))) / fTemp5) + (0.39166900650000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec59[1]) + ((fRec59[0] + fRec59[2]) / fTemp4))))));
			fRec60[0] = (double(input27[i]) - (((fTemp2 * fRec60[2]) + (2.0 * (fTemp3 * fRec60[1]))) / fTemp4));
			double fTemp41 = (((fTemp1 * (fRec60[2] + (fRec60[0] + (2.0 * fRec60[1])))) / fTemp5) + (0.39166900650000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec60[1]) + ((fRec60[0] + fRec60[2]) / fTemp4))))));
			fRec61[0] = (double(input30[i]) - (((fTemp2 * fRec61[2]) + (2.0 * (fTemp3 * fRec61[1]))) / fTemp4));
			double fTemp42 = (((fTemp1 * (fRec61[2] + (fRec61[0] + (2.0 * fRec61[1])))) / fTemp5) + (0.39166900650000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec61[1]) + ((fRec61[0] + fRec61[2]) / fTemp4))))));
			fRec62[0] = (double(input33[i]) - (((fTemp2 * fRec62[2]) + (2.0 * (fTemp3 * fRec62[1]))) / fTemp4));
			double fTemp43 = (((fTemp1 * (fRec62[2] + (fRec62[0] + (2.0 * fRec62[1])))) / fTemp5) + (0.39166900650000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec62[1]) + ((fRec62[0] + fRec62[2]) / fTemp4))))));
			fRec63[0] = (double(input35[i]) - (((fTemp2 * fRec63[2]) + (2.0 * (fTemp3 * fRec63[1]))) / fTemp4));
			double fTemp44 = (((fTemp1 * (fRec63[2] + (fRec63[0] + (2.0 * fRec63[1])))) / fTemp5) + (0.39166900650000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec63[1]) + ((fRec63[0] + fRec63[2]) / fTemp4))))));
			double fTemp45 = (fConst20 * ((((((0.1012623025 * fTemp36) + (0.010369307100000001 * fTemp37)) + (0.029509125300000001 * fTemp38)) + (0.0632018892 * fTemp39)) + (0.0252063618 * fTemp40)) - ((((0.076314064400000006 * fTemp41) + (0.017364648699999999 * fTemp42)) + (0.019133917600000001 * fTemp43)) + (0.044083739400000002 * fTemp44))));
			double fTemp46 = (fConst21 * fRec49[1]);
			double fTemp47 = (fConst22 * fRec52[1]);
			fRec54[0] = (fTemp45 + (fTemp46 + (fRec54[1] + fTemp47)));
			fRec52[0] = fRec54[0];
			double fRec53 = ((fTemp47 + fTemp46) + fTemp45);
			fRec51[0] = (fRec52[0] + fRec51[1]);
			fRec49[0] = fRec51[0];
			double fRec50 = fRec53;
			fRec48[0] = (fTemp34 + (fTemp35 + (fRec50 + fRec48[1])));
			fRec46[0] = fRec48[0];
			double fRec47 = (fTemp34 + (fRec50 + fTemp35));
			fRec45[0] = (fRec46[0] + fRec45[1]);
			fRec43[0] = fRec45[0];
			double fRec44 = fRec47;
			fRec42[0] = (fTemp33 + (fRec44 + fRec42[1]));
			fRec40[0] = fRec42[0];
			double fRec41 = (fRec44 + fTemp33);
			double fTemp48 = (fConst24 * fRec64[1]);
			double fTemp49 = (fConst25 * fRec67[1]);
			fRec76[0] = (double(input16[i]) - (((fTemp2 * fRec76[2]) + (2.0 * (fTemp3 * fRec76[1]))) / fTemp4));
			double fTemp50 = (((fTemp1 * (fRec76[2] + (fRec76[0] + (2.0 * fRec76[1])))) / fTemp5) + (0.51694915070000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec76[1]) + ((fRec76[0] + fRec76[2]) / fTemp4))))));
			fRec77[0] = (double(input19[i]) - (((fTemp2 * fRec77[2]) + (2.0 * (fTemp3 * fRec77[1]))) / fTemp4));
			double fTemp51 = (((fTemp1 * (fRec77[2] + (fRec77[0] + (2.0 * fRec77[1])))) / fTemp5) + (0.51694915070000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec77[1]) + ((fRec77[0] + fRec77[2]) / fTemp4))))));
			fRec78[0] = (double(input20[i]) - (((fTemp2 * fRec78[2]) + (2.0 * (fTemp3 * fRec78[1]))) / fTemp4));
			double fTemp52 = (((fTemp1 * (fRec78[2] + (fRec78[0] + (2.0 * fRec78[1])))) / fTemp5) + (0.51694915070000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec78[1]) + ((fRec78[0] + fRec78[2]) / fTemp4))))));
			fRec79[0] = (double(input21[i]) - (((fTemp2 * fRec79[2]) + (2.0 * (fTemp3 * fRec79[1]))) / fTemp4));
			double fTemp53 = (((fTemp1 * (fRec79[2] + (fRec79[0] + (2.0 * fRec79[1])))) / fTemp5) + (0.51694915070000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec79[1]) + ((fRec79[0] + fRec79[2]) / fTemp4))))));
			fRec80[0] = (double(input23[i]) - (((fTemp2 * fRec80[2]) + (2.0 * (fTemp3 * fRec80[1]))) / fTemp4));
			double fTemp54 = (((fTemp1 * (fRec80[2] + (fRec80[0] + (2.0 * fRec80[1])))) / fTemp5) + (0.51694915070000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec80[1]) + ((fRec80[0] + fRec80[2]) / fTemp4))))));
			fRec81[0] = (double(input24[i]) - (((fTemp2 * fRec81[2]) + (2.0 * (fTemp3 * fRec81[1]))) / fTemp4));
			double fTemp55 = (((fTemp1 * (fRec81[2] + (fRec81[0] + (2.0 * fRec81[1])))) / fTemp5) + (0.51694915070000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec81[1]) + ((fRec81[0] + fRec81[2]) / fTemp4))))));
			fRec82[0] = (double(input17[i]) - (((fTemp2 * fRec82[2]) + (2.0 * (fTemp3 * fRec82[1]))) / fTemp4));
			double fTemp56 = (((fTemp1 * (fRec82[2] + (fRec82[0] + (2.0 * fRec82[1])))) / fTemp5) + (0.51694915070000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec82[1]) + ((fRec82[0] + fRec82[2]) / fTemp4))))));
			fRec83[0] = (double(input18[i]) - (((fTemp2 * fRec83[2]) + (2.0 * (fTemp3 * fRec83[1]))) / fTemp4));
			double fTemp57 = (((fTemp1 * (fRec83[2] + (fRec83[0] + (2.0 * fRec83[1])))) / fTemp5) + (0.51694915070000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec83[1]) + ((fRec83[0] + fRec83[2]) / fTemp4))))));
			fRec84[0] = (double(input22[i]) - (((fTemp2 * fRec84[2]) + (2.0 * (fTemp3 * fRec84[1]))) / fTemp4));
			double fTemp58 = (((fTemp1 * (fRec84[2] + (fRec84[0] + (2.0 * fRec84[1])))) / fTemp5) + (0.51694915070000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec84[1]) + ((fRec84[0] + fRec84[2]) / fTemp4))))));
			double fTemp59 = (fConst27 * (((((((0.1141520109 * fTemp50) + (0.0085081733999999992 * fTemp51)) + (0.042475806300000002 * fTemp52)) + (0.011199862499999999 * fTemp53)) + (0.011495499899999999 * fTemp54)) + (0.022010989000000002 * fTemp55)) - (((0.0087327596000000007 * fTemp56) + (0.0596827116 * fTemp57)) + (0.050413985500000001 * fTemp58))));
			double fTemp60 = (fConst28 * fRec70[1]);
			double fTemp61 = (fConst29 * fRec73[1]);
			fRec75[0] = (fTemp59 + (fTemp60 + (fRec75[1] + fTemp61)));
			fRec73[0] = fRec75[0];
			double fRec74 = ((fTemp61 + fTemp60) + fTemp59);
			fRec72[0] = (fRec73[0] + fRec72[1]);
			fRec70[0] = fRec72[0];
			double fRec71 = fRec74;
			fRec69[0] = (fTemp48 + (fTemp49 + (fRec71 + fRec69[1])));
			fRec67[0] = fRec69[0];
			double fRec68 = (fTemp48 + (fRec71 + fTemp49));
			fRec66[0] = (fRec67[0] + fRec66[1]);
			fRec64[0] = fRec66[0];
			double fRec65 = fRec68;
			double fTemp62 = (fConst31 * fRec85[1]);
			fRec94[0] = (double(input9[i]) - (((fTemp2 * fRec94[2]) + (2.0 * (fTemp3 * fRec94[1]))) / fTemp4));
			double fTemp63 = (((fTemp1 * (fRec94[2] + (fRec94[0] + (2.0 * fRec94[1])))) / fTemp5) + (0.62736104969999995 * (fRec3[0] * (0.0 - ((fTemp6 * fRec94[1]) + ((fRec94[0] + fRec94[2]) / fTemp4))))));
			fRec95[0] = (double(input12[i]) - (((fTemp2 * fRec95[2]) + (2.0 * (fTemp3 * fRec95[1]))) / fTemp4));
			double fTemp64 = (((fTemp1 * (fRec95[2] + (fRec95[0] + (2.0 * fRec95[1])))) / fTemp5) + (0.62736104969999995 * (fRec3[0] * (0.0 - ((fTemp6 * fRec95[1]) + ((fRec95[0] + fRec95[2]) / fTemp4))))));
			fRec96[0] = (double(input15[i]) - (((fTemp2 * fRec96[2]) + (2.0 * (fTemp3 * fRec96[1]))) / fTemp4));
			double fTemp65 = (((fTemp1 * (fRec96[2] + (fRec96[0] + (2.0 * fRec96[1])))) / fTemp5) + (0.62736104969999995 * (fRec3[0] * (0.0 - ((fTemp6 * fRec96[1]) + ((fRec96[0] + fRec96[2]) / fTemp4))))));
			fRec97[0] = (double(input10[i]) - (((fTemp2 * fRec97[2]) + (2.0 * (fTemp3 * fRec97[1]))) / fTemp4));
			double fTemp66 = (((fTemp1 * (fRec97[2] + (fRec97[0] + (2.0 * fRec97[1])))) / fTemp5) + (0.62736104969999995 * (fRec3[0] * (0.0 - ((fTemp6 * fRec97[1]) + ((fRec97[0] + fRec97[2]) / fTemp4))))));
			fRec98[0] = (double(input11[i]) - (((fTemp2 * fRec98[2]) + (2.0 * (fTemp3 * fRec98[1]))) / fTemp4));
			double fTemp67 = (((fTemp1 * (fRec98[2] + (fRec98[0] + (2.0 * fRec98[1])))) / fTemp5) + (0.62736104969999995 * (fRec3[0] * (0.0 - ((fTemp6 * fRec98[1]) + ((fRec98[0] + fRec98[2]) / fTemp4))))));
			fRec99[0] = (double(input13[i]) - (((fTemp2 * fRec99[2]) + (2.0 * (fTemp3 * fRec99[1]))) / fTemp4));
			double fTemp68 = (((fTemp1 * (fRec99[2] + (fRec99[0] + (2.0 * fRec99[1])))) / fTemp5) + (0.62736104969999995 * (fRec3[0] * (0.0 - ((fTemp6 * fRec99[1]) + ((fRec99[0] + fRec99[2]) / fTemp4))))));
			double fTemp69 = (fConst33 * ((((0.1061963444 * fTemp63) + (0.0155835173 * fTemp64)) + (0.041011569599999999 * fTemp65)) - (((0.0109855352 * fTemp66) + (0.031216779699999999 * fTemp67)) + (0.071902252900000005 * fTemp68))));
			double fTemp70 = (fConst34 * fRec88[1]);
			double fTemp71 = (fConst35 * fRec91[1]);
			fRec93[0] = (fTemp69 + (fTemp70 + (fRec93[1] + fTemp71)));
			fRec91[0] = fRec93[0];
			double fRec92 = ((fTemp71 + fTemp70) + fTemp69);
			fRec90[0] = (fRec91[0] + fRec90[1]);
			fRec88[0] = fRec90[0];
			double fRec89 = fRec92;
			fRec87[0] = (fTemp62 + (fRec89 + fRec87[1]));
			fRec85[0] = fRec87[0];
			double fRec86 = (fRec89 + fTemp62);
			fRec103[0] = (double(input1[i]) - (((fTemp2 * fRec103[2]) + (2.0 * (fTemp3 * fRec103[1]))) / fTemp4));
			double fTemp72 = (((fTemp1 * (fRec103[2] + (fRec103[0] + (2.0 * fRec103[1])))) / fTemp5) + (0.77895164429999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec103[1]) + ((fRec103[0] + fRec103[2]) / fTemp4))))));
			fRec104[0] = (double(input3[i]) - (((fTemp2 * fRec104[2]) + (2.0 * (fTemp3 * fRec104[1]))) / fTemp4));
			double fTemp73 = (((fTemp1 * (fRec104[2] + (fRec104[0] + (2.0 * fRec104[1])))) / fTemp5) + (0.77895164429999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec104[1]) + ((fRec104[0] + fRec104[2]) / fTemp4))))));
			fRec105[0] = (double(input2[i]) - (((fTemp2 * fRec105[2]) + (2.0 * (fTemp3 * fRec105[1]))) / fTemp4));
			double fTemp74 = (((fTemp1 * (fRec105[2] + (fRec105[0] + (2.0 * fRec105[1])))) / fTemp5) + (0.77895164429999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec105[1]) + ((fRec105[0] + fRec105[2]) / fTemp4))))));
			double fTemp75 = (fConst37 * (((0.043844938 * fTemp72) + (0.1080277691 * fTemp73)) - (0.0158195618 * fTemp74)));
			double fTemp76 = (fConst38 * fRec100[1]);
			fRec102[0] = (fTemp75 + (fRec102[1] + fTemp76));
			fRec100[0] = fRec102[0];
			double fRec101 = (fTemp76 + fTemp75);
			fRec112[0] = (double(input4[i]) - (((fTemp2 * fRec112[2]) + (2.0 * (fTemp3 * fRec112[1]))) / fTemp4));
			double fTemp77 = (((fTemp1 * (fRec112[2] + (fRec112[0] + (2.0 * fRec112[1])))) / fTemp5) + (0.71644752140000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec112[1]) + ((fRec112[0] + fRec112[2]) / fTemp4))))));
			fRec113[0] = (double(input8[i]) - (((fTemp2 * fRec113[2]) + (2.0 * (fTemp3 * fRec113[1]))) / fTemp4));
			double fTemp78 = (((fTemp1 * (fRec113[2] + (fRec113[0] + (2.0 * fRec113[1])))) / fTemp5) + (0.71644752140000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec113[1]) + ((fRec113[0] + fRec113[2]) / fTemp4))))));
			fRec114[0] = (double(input5[i]) - (((fTemp2 * fRec114[2]) + (2.0 * (fTemp3 * fRec114[1]))) / fTemp4));
			double fTemp79 = (((fTemp1 * (fRec114[2] + (fRec114[0] + (2.0 * fRec114[1])))) / fTemp5) + (0.71644752140000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec114[1]) + ((fRec114[0] + fRec114[2]) / fTemp4))))));
			fRec115[0] = (double(input6[i]) - (((fTemp2 * fRec115[2]) + (2.0 * (fTemp3 * fRec115[1]))) / fTemp4));
			double fTemp80 = (((fTemp1 * (fRec115[2] + (fRec115[0] + (2.0 * fRec115[1])))) / fTemp5) + (0.71644752140000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec115[1]) + ((fRec115[0] + fRec115[2]) / fTemp4))))));
			fRec116[0] = (double(input7[i]) - (((fTemp2 * fRec116[2]) + (2.0 * (fTemp3 * fRec116[1]))) / fTemp4));
			double fTemp81 = (((fTemp1 * (fRec116[2] + (fRec116[0] + (2.0 * fRec116[1])))) / fTemp5) + (0.71644752140000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec116[1]) + ((fRec116[0] + fRec116[2]) / fTemp4))))));
			double fTemp82 = (fConst40 * (((0.081832913899999998 * fTemp77) + (0.078101010600000007 * fTemp78)) - (((0.0079948524000000003 * fTemp79) + (0.048513357399999998 * fTemp80)) + (0.0105241447 * fTemp81))));
			double fTemp83 = (fConst41 * fRec106[1]);
			double fTemp84 = (fConst42 * fRec109[1]);
			fRec111[0] = (fTemp82 + (fTemp83 + (fRec111[1] + fTemp84)));
			fRec109[0] = fRec111[0];
			double fRec110 = ((fTemp84 + fTemp83) + fTemp82);
			fRec108[0] = (fRec109[0] + fRec108[1]);
			fRec106[0] = fRec108[0];
			double fRec107 = fRec110;
			fRec117[0] = (double(input49[i]) - (((fTemp2 * fRec117[2]) + (2.0 * (fTemp3 * fRec117[1]))) / fTemp4));
			double fTemp85 = (((fTemp1 * (fRec117[2] + (fRec117[0] + (2.0 * fRec117[1])))) / fTemp5) + (0.12574553229999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec117[1]) + ((fRec117[0] + fRec117[2]) / fTemp4))))));
			fRec118[0] = (double(input51[i]) - (((fTemp2 * fRec118[2]) + (2.0 * (fTemp3 * fRec118[1]))) / fTemp4));
			double fTemp86 = (((fTemp1 * (fRec118[2] + (fRec118[0] + (2.0 * fRec118[1])))) / fTemp5) + (0.12574553229999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec118[1]) + ((fRec118[0] + fRec118[2]) / fTemp4))))));
			fRec119[0] = (double(input54[i]) - (((fTemp2 * fRec119[2]) + (2.0 * (fTemp3 * fRec119[1]))) / fTemp4));
			double fTemp87 = (((fTemp1 * (fRec119[2] + (fRec119[0] + (2.0 * fRec119[1])))) / fTemp5) + (0.12574553229999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec119[1]) + ((fRec119[0] + fRec119[2]) / fTemp4))))));
			fRec120[0] = (double(input55[i]) - (((fTemp2 * fRec120[2]) + (2.0 * (fTemp3 * fRec120[1]))) / fTemp4));
			double fTemp88 = (((fTemp1 * (fRec120[2] + (fRec120[0] + (2.0 * fRec120[1])))) / fTemp5) + (0.12574553229999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec120[1]) + ((fRec120[0] + fRec120[2]) / fTemp4))))));
			fRec121[0] = (double(input57[i]) - (((fTemp2 * fRec121[2]) + (2.0 * (fTemp3 * fRec121[1]))) / fTemp4));
			double fTemp89 = (((fTemp1 * (fRec121[2] + (fRec121[0] + (2.0 * fRec121[1])))) / fTemp5) + (0.12574553229999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec121[1]) + ((fRec121[0] + fRec121[2]) / fTemp4))))));
			fRec122[0] = (double(input60[i]) - (((fTemp2 * fRec122[2]) + (2.0 * (fTemp3 * fRec122[1]))) / fTemp4));
			double fTemp90 = (((fTemp1 * (fRec122[2] + (fRec122[0] + (2.0 * fRec122[1])))) / fTemp5) + (0.12574553229999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec122[1]) + ((fRec122[0] + fRec122[2]) / fTemp4))))));
			fRec123[0] = (double(input63[i]) - (((fTemp2 * fRec123[2]) + (2.0 * (fTemp3 * fRec123[1]))) / fTemp4));
			double fTemp91 = (((fTemp1 * (fRec123[2] + (fRec123[0] + (2.0 * fRec123[1])))) / fTemp5) + (0.12574553229999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec123[1]) + ((fRec123[0] + fRec123[2]) / fTemp4))))));
			fVec0[(IOTA & 127)] = (((0.039329742600000002 * fTemp7) + ((0.0095560373000000004 * fTemp8) + ((0.0074989000000000002 * fTemp9) + ((0.067381054199999998 * fTemp10) + ((0.011240188 * fTemp11) + (((0.078355810799999995 * fTemp12) + (fRec10 + (fRec41 + (fRec65 + (fRec86 + (fRec101 + fRec107)))))) + (0.016708262000000002 * fTemp85))))))) - ((((((0.061349523400000001 * fTemp86) + (0.0066634729 * fTemp87)) + (0.0289331398 * fTemp88)) + (0.058885414599999998 * fTemp89)) + (0.018980189099999999 * fTemp90)) + (0.089536032599999996 * fTemp91)));
			output0[i] = FAUSTFLOAT((0.96563981042654023 * (fRec0[0] * fVec0[((IOTA - iConst43) & 127)])));
			double fTemp92 = (fConst45 * fRec124[1]);
			double fTemp93 = (fConst46 * fRec127[1]);
			double fTemp94 = (fConst48 * fRec130[1]);
			double fTemp95 = (fConst49 * fRec133[1]);
			double fTemp96 = (fConst51 * (((0.0125794735 * fTemp23) + ((((0.076600182399999994 * fTemp24) + (0.0079368175999999999 * fTemp25)) + (0.038575167 * fTemp21)) + (0.0137509663 * fTemp22))) - ((((0.0092215241999999992 * fTemp27) + (((((0.053691241600000002 * fTemp17) + (0.010826950599999999 * fTemp18)) + (0.0090837587999999993 * fTemp19)) + (0.057712042599999999 * fTemp20)) + (0.048218794600000003 * fTemp26))) + (0.010554117 * fTemp28)) + (0.092468878399999996 * fTemp29))));
			double fTemp97 = (fConst52 * fRec136[1]);
			double fTemp98 = (fConst53 * fRec139[1]);
			fRec141[0] = (fTemp96 + (fTemp97 + (fRec141[1] + fTemp98)));
			fRec139[0] = fRec141[0];
			double fRec140 = ((fTemp98 + fTemp97) + fTemp96);
			fRec138[0] = (fRec139[0] + fRec138[1]);
			fRec136[0] = fRec138[0];
			double fRec137 = fRec140;
			fRec135[0] = (fTemp94 + (fTemp95 + (fRec137 + fRec135[1])));
			fRec133[0] = fRec135[0];
			double fRec134 = (fTemp94 + (fRec137 + fTemp95));
			fRec132[0] = (fRec133[0] + fRec132[1]);
			fRec130[0] = fRec132[0];
			double fRec131 = fRec134;
			fRec129[0] = (fTemp92 + (fTemp93 + (fRec131 + fRec129[1])));
			fRec127[0] = fRec129[0];
			double fRec128 = (fTemp92 + (fRec131 + fTemp93));
			fRec126[0] = (fRec127[0] + fRec126[1]);
			fRec124[0] = fRec126[0];
			double fRec125 = fRec128;
			double fTemp99 = (fConst55 * fRec142[1]);
			double fTemp100 = (fConst57 * fRec145[1]);
			double fTemp101 = (fConst58 * fRec148[1]);
			double fTemp102 = (fConst60 * ((((0.0787787712 * fTemp41) + (0.062669559700000002 * fTemp39)) + (0.027026319900000002 * fTemp40)) - ((((((0.096485940000000006 * fTemp36) + (0.012489731400000001 * fTemp37)) + (0.031433918499999998 * fTemp38)) + (0.018215192200000001 * fTemp42)) + (0.0135281089 * fTemp43)) + (0.057198337600000003 * fTemp44))));
			double fTemp103 = (fConst61 * fRec151[1]);
			double fTemp104 = (fConst62 * fRec154[1]);
			fRec156[0] = (fTemp102 + (fTemp103 + (fRec156[1] + fTemp104)));
			fRec154[0] = fRec156[0];
			double fRec155 = ((fTemp104 + fTemp103) + fTemp102);
			fRec153[0] = (fRec154[0] + fRec153[1]);
			fRec151[0] = fRec153[0];
			double fRec152 = fRec155;
			fRec150[0] = (fTemp100 + (fTemp101 + (fRec152 + fRec150[1])));
			fRec148[0] = fRec150[0];
			double fRec149 = (fTemp100 + (fRec152 + fTemp101));
			fRec147[0] = (fRec148[0] + fRec147[1]);
			fRec145[0] = fRec147[0];
			double fRec146 = fRec149;
			fRec144[0] = (fTemp99 + (fRec146 + fRec144[1]));
			fRec142[0] = fRec144[0];
			double fRec143 = (fRec146 + fTemp99);
			double fTemp105 = (fConst64 * fRec157[1]);
			double fTemp106 = (fConst65 * fRec160[1]);
			double fTemp107 = (fConst67 * (((0.010123774300000001 * fTemp55) + (((0.0121804136 * fTemp53) + (((0.0107602138 * fTemp56) + (0.061976866399999997 * fTemp57)) + (0.042942807499999999 * fTemp52))) + (0.0125019342 * fTemp54))) - (((0.11418880989999999 * fTemp50) + (0.010483486199999999 * fTemp51)) + (0.047618220000000003 * fTemp58))));
			double fTemp108 = (fConst68 * fRec163[1]);
			double fTemp109 = (fConst69 * fRec166[1]);
			fRec168[0] = (fTemp107 + (fTemp108 + (fRec168[1] + fTemp109)));
			fRec166[0] = fRec168[0];
			double fRec167 = ((fTemp109 + fTemp108) + fTemp107);
			fRec165[0] = (fRec166[0] + fRec165[1]);
			fRec163[0] = fRec165[0];
			double fRec164 = fRec167;
			fRec162[0] = (fTemp105 + (fTemp106 + (fRec164 + fRec162[1])));
			fRec160[0] = fRec162[0];
			double fRec161 = (fTemp105 + (fRec164 + fTemp106));
			fRec159[0] = (fRec160[0] + fRec159[1]);
			fRec157[0] = fRec159[0];
			double fRec158 = fRec161;
			double fTemp110 = (fConst71 * fRec169[1]);
			double fTemp111 = (fConst73 * (((((0.013231972200000001 * fTemp66) + (0.032233018299999999 * fTemp67)) + (0.017111908200000001 * fTemp64)) + (0.033594324000000002 * fTemp65)) - ((0.1077914177 * fTemp63) + (0.070524778900000001 * fTemp68))));
			double fTemp112 = (fConst74 * fRec172[1]);
			double fTemp113 = (fConst75 * fRec175[1]);
			fRec177[0] = (fTemp111 + (fTemp112 + (fRec177[1] + fTemp113)));
			fRec175[0] = fRec177[0];
			double fRec176 = ((fTemp113 + fTemp112) + fTemp111);
			fRec174[0] = (fRec175[0] + fRec174[1]);
			fRec172[0] = fRec174[0];
			double fRec173 = fRec176;
			fRec171[0] = (fTemp110 + (fRec173 + fRec171[1]));
			fRec169[0] = fRec171[0];
			double fRec170 = (fRec173 + fTemp110);
			double fTemp114 = (fConst77 * ((0.1049564311 * fTemp73) - ((0.043848671999999998 * fTemp72) + (0.016558546399999999 * fTemp74))));
			double fTemp115 = (fConst78 * fRec178[1]);
			fRec180[0] = (fTemp114 + (fRec180[1] + fTemp115));
			fRec178[0] = fRec180[0];
			double fRec179 = (fTemp115 + fTemp114);
			double fTemp116 = (fConst80 * (((0.0098509892999999998 * fTemp79) + (0.073769829199999998 * fTemp78)) - (((0.083213853500000004 * fTemp77) + (0.047608809500000002 * fTemp80)) + (0.011445536500000001 * fTemp81))));
			double fTemp117 = (fConst81 * fRec181[1]);
			double fTemp118 = (fConst82 * fRec184[1]);
			fRec186[0] = (fTemp116 + (fTemp117 + (fRec186[1] + fTemp118)));
			fRec184[0] = fRec186[0];
			double fRec185 = ((fTemp118 + fTemp117) + fTemp116);
			fRec183[0] = (fRec184[0] + fRec183[1]);
			fRec181[0] = fRec183[0];
			double fRec182 = fRec185;
			fVec1[(IOTA & 63)] = (((0.049038774200000003 * fTemp7) + ((0.0044107284999999998 * fTemp8) + ((0.0084435627000000006 * fTemp9) + ((0.031443869700000002 * fTemp88) + ((0.0080260894999999999 * fTemp87) + ((0.056443063100000003 * fTemp86) + ((0.0011714249 * fTemp85) + ((0.076408305900000001 * fTemp12) + (fRec125 + (fRec143 + (fRec158 + (fRec170 + (fRec179 + fRec182))))))))))))) - (((((0.013538699100000001 * fTemp11) + (0.070493172500000006 * fTemp10)) + (0.058861295199999997 * fTemp89)) + (0.020350602999999998 * fTemp90)) + (0.093843559100000001 * fTemp91)));
			output1[i] = FAUSTFLOAT((0.97748815165876779 * (fRec0[0] * fVec1[((IOTA - iConst83) & 63)])));
			double fTemp119 = (fConst85 * fRec187[1]);
			double fTemp120 = (fConst86 * fRec190[1]);
			double fTemp121 = (fConst88 * fRec193[1]);
			double fTemp122 = (fConst89 * fRec196[1]);
			double fTemp123 = (fConst91 * (((0.10483031080000001 * fTemp29) + ((0.017889480999999999 * fTemp23) + (((0.00034365790000000002 * fTemp17) + (0.0098973676 * fTemp25)) + (0.0461258617 * fTemp22)))) - ((0.0150091875 * fTemp28) + ((0.030809358500000002 * fTemp21) + ((0.0131140848 * fTemp27) + (((((0.013501420199999999 * fTemp18) + (0.070438805399999999 * fTemp24)) + (0.011327625799999999 * fTemp19)) + (0.076910112899999994 * fTemp20)) + (0.055427856499999997 * fTemp26)))))));
			double fTemp124 = (fConst92 * fRec199[1]);
			double fTemp125 = (fConst93 * fRec202[1]);
			fRec204[0] = (fTemp123 + (fTemp124 + (fRec204[1] + fTemp125)));
			fRec202[0] = fRec204[0];
			double fRec203 = ((fTemp125 + fTemp124) + fTemp123);
			fRec201[0] = (fRec202[0] + fRec201[1]);
			fRec199[0] = fRec201[0];
			double fRec200 = fRec203;
			fRec198[0] = (fTemp121 + (fTemp122 + (fRec200 + fRec198[1])));
			fRec196[0] = fRec198[0];
			double fRec197 = (fTemp121 + (fRec200 + fTemp122));
			fRec195[0] = (fRec196[0] + fRec195[1]);
			fRec193[0] = fRec195[0];
			double fRec194 = fRec197;
			fRec192[0] = (fTemp119 + (fTemp120 + (fRec194 + fRec192[1])));
			fRec190[0] = fRec192[0];
			double fRec191 = (fTemp119 + (fRec194 + fTemp120));
			fRec189[0] = (fRec190[0] + fRec189[1]);
			fRec187[0] = fRec189[0];
			double fRec188 = fRec191;
			double fTemp126 = (fConst95 * fRec205[1]);
			double fTemp127 = (fConst97 * fRec208[1]);
			double fTemp128 = (fConst98 * fRec211[1]);
			double fTemp129 = (fConst100 * (((0.067067021399999996 * fTemp44) + ((0.036873576800000002 * fTemp40) + (((0.079883576900000003 * fTemp36) + (0.040025516999999997 * fTemp39)) + (0.081417821099999996 * fTemp43)))) - ((((0.0029850595000000001 * fTemp41) + (0.0249748781 * fTemp37)) + (0.058138387899999998 * fTemp38)) + (0.0235179586 * fTemp42))));
			double fTemp130 = (fConst101 * fRec214[1]);
			double fTemp131 = (fConst102 * fRec217[1]);
			fRec219[0] = (fTemp129 + (fTemp130 + (fRec219[1] + fTemp131)));
			fRec217[0] = fRec219[0];
			double fRec218 = ((fTemp131 + fTemp130) + fTemp129);
			fRec216[0] = (fRec217[0] + fRec216[1]);
			fRec214[0] = fRec216[0];
			double fRec215 = fRec218;
			fRec213[0] = (fTemp127 + (fTemp128 + (fRec215 + fRec213[1])));
			fRec211[0] = fRec213[0];
			double fRec212 = (fTemp127 + (fRec215 + fTemp128));
			fRec210[0] = (fRec211[0] + fRec210[1]);
			fRec208[0] = fRec210[0];
			double fRec209 = fRec212;
			fRec207[0] = (fTemp126 + (fRec209 + fRec207[1]));
			fRec205[0] = fRec207[0];
			double fRec206 = (fRec209 + fTemp126);
			double fTemp132 = (fConst104 * fRec220[1]);
			double fTemp133 = (fConst105 * fRec223[1]);
			double fTemp134 = (fConst107 * (((0.017779211100000001 * fTemp54) + ((0.038031897799999999 * fTemp58) + ((0.017321971299999999 * fTemp53) + ((((0.10500397140000001 * fTemp50) + (0.013418198100000001 * fTemp56)) + (0.076414453899999998 * fTemp57)) + (0.049092540300000001 * fTemp52))))) - ((0.0130731133 * fTemp51) + (0.026980314700000001 * fTemp55))));
			double fTemp135 = (fConst108 * fRec226[1]);
			double fTemp136 = (fConst109 * fRec229[1]);
			fRec231[0] = (fTemp134 + (fTemp135 + (fRec231[1] + fTemp136)));
			fRec229[0] = fRec231[0];
			double fRec230 = ((fTemp136 + fTemp135) + fTemp134);
			fRec228[0] = (fRec229[0] + fRec228[1]);
			fRec226[0] = fRec228[0];
			double fRec227 = fRec230;
			fRec225[0] = (fTemp132 + (fTemp133 + (fRec227 + fRec225[1])));
			fRec223[0] = fRec225[0];
			double fRec224 = (fTemp132 + (fRec227 + fTemp133));
			fRec222[0] = (fRec223[0] + fRec222[1]);
			fRec220[0] = fRec222[0];
			double fRec221 = fRec224;
			double fTemp137 = (fConst111 * fRec232[1]);
			double fTemp138 = (fConst113 * (((((0.018617887100000001 * fTemp63) + (0.0264590873 * fTemp66)) + (0.064152210299999998 * fTemp67)) + (0.0246808549 * fTemp64)) - ((0.038189974500000001 * fTemp68) + (0.1044030774 * fTemp65))));
			double fTemp139 = (fConst114 * fRec235[1]);
			double fTemp140 = (fConst115 * fRec238[1]);
			fRec240[0] = (fTemp138 + (fTemp139 + (fRec240[1] + fTemp140)));
			fRec238[0] = fRec240[0];
			double fRec239 = ((fTemp140 + fTemp139) + fTemp138);
			fRec237[0] = (fRec238[0] + fRec237[1]);
			fRec235[0] = fRec237[0];
			double fRec236 = fRec239;
			fRec234[0] = (fTemp137 + (fRec236 + fRec234[1]));
			fRec232[0] = fRec234[0];
			double fRec233 = (fRec236 + fTemp137);
			double fTemp141 = (fConst117 * ((0.047844082199999999 * fTemp73) - ((0.093801777899999994 * fTemp72) + (0.021257700500000001 * fTemp74))));
			double fTemp142 = (fConst118 * fRec241[1]);
			fRec243[0] = (fTemp141 + (fRec243[1] + fTemp142));
			fRec241[0] = fRec243[0];
			double fRec242 = (fTemp142 + fTemp141);
			double fTemp143 = (fConst120 * ((0.0122843773 * fTemp79) - ((((0.092784871399999996 * fTemp77) + (0.049180163499999999 * fTemp80)) + (0.016276890200000001 * fTemp81)) + (0.058918762700000002 * fTemp78))));
			double fTemp144 = (fConst121 * fRec244[1]);
			double fTemp145 = (fConst122 * fRec247[1]);
			fRec249[0] = (fTemp143 + (fTemp144 + (fRec249[1] + fTemp145)));
			fRec247[0] = fRec249[0];
			double fRec248 = ((fTemp145 + fTemp144) + fTemp143);
			fRec246[0] = (fRec247[0] + fRec246[1]);
			fRec244[0] = fRec246[0];
			double fRec245 = fRec248;
			fVec2[0] = (((0.047443671899999998 * fTemp91) + ((0.012854127999999999 * fTemp9) + ((0.0553839489 * fTemp88) + (((0.076699945699999994 * fTemp12) + (fRec188 + (fRec206 + (fRec221 + (fRec233 + (fRec242 + fRec245)))))) + (0.0160492328 * fTemp87))))) - ((0.030735002800000001 * fTemp7) + ((0.027765508899999999 * fTemp90) + ((0.076425077499999994 * fTemp8) + (((((0.090624329300000001 * fTemp85) + (0.027072428400000001 * fTemp11)) + (0.065152760899999995 * fTemp86)) + (0.0047425866000000002 * fTemp10)) + (0.041782308999999997 * fTemp89))))));
			output2[i] = FAUSTFLOAT((0.99229857819905221 * (fRec0[0] * fVec2[iConst123])));
			double fTemp146 = (fConst125 * fRec250[1]);
			double fTemp147 = (fConst126 * fRec253[1]);
			double fTemp148 = (fConst128 * fRec256[1]);
			double fTemp149 = (fConst129 * fRec259[1]);
			double fTemp150 = (fConst131 * (((((((0.1272541137 * fTemp17) + (0.0019413442999999999 * fTemp18)) + (0.061071029800000003 * fTemp24)) + (0.0016287783999999999 * fTemp19)) + (0.0109627062 * fTemp20)) + (0.0085900409999999996 * fTemp23)) - (((0.054763724100000001 * fTemp22) + ((0.0072070025999999999 * fTemp28) + ((0.050185718999999997 * fTemp21) + ((0.0062970259000000002 * fTemp27) + ((0.0014231242000000001 * fTemp25) + (0.035080338099999997 * fTemp26)))))) + (0.0127677173 * fTemp29))));
			double fTemp151 = (fConst132 * fRec262[1]);
			double fTemp152 = (fConst133 * fRec265[1]);
			fRec267[0] = (fTemp150 + (fTemp151 + (fRec267[1] + fTemp152)));
			fRec265[0] = fRec267[0];
			double fRec266 = ((fTemp152 + fTemp151) + fTemp150);
			fRec264[0] = (fRec265[0] + fRec264[1]);
			fRec262[0] = fRec264[0];
			double fRec263 = fRec266;
			fRec261[0] = (fTemp148 + (fTemp149 + (fRec263 + fRec261[1])));
			fRec259[0] = fRec261[0];
			double fRec260 = (fTemp148 + (fRec263 + fTemp149));
			fRec258[0] = (fRec259[0] + fRec258[1]);
			fRec256[0] = fRec258[0];
			double fRec257 = fRec260;
			fRec255[0] = (fTemp146 + (fTemp147 + (fRec257 + fRec255[1])));
			fRec253[0] = fRec255[0];
			double fRec254 = (fTemp146 + (fRec257 + fTemp147));
			fRec252[0] = (fRec253[0] + fRec252[1]);
			fRec250[0] = fRec252[0];
			double fRec251 = fRec254;
			double fTemp153 = (fConst135 * fRec268[1]);
			double fTemp154 = (fConst137 * fRec271[1]);
			double fTemp155 = (fConst138 * fRec274[1]);
			double fTemp156 = (fConst140 * ((0.0076556059999999997 * fTemp40) - ((((((((0.0550031775 * fTemp36) + (0.070475293300000005 * fTemp41)) + (0.011965181199999999 * fTemp37)) + (0.053131397300000001 * fTemp38)) + (0.0079663845999999993 * fTemp42)) + (0.0048024811000000004 * fTemp39)) + (0.039884619599999997 * fTemp43)) + (0.1050186261 * fTemp44))));
			double fTemp157 = (fConst141 * fRec277[1]);
			double fTemp158 = (fConst142 * fRec280[1]);
			fRec282[0] = (fTemp156 + (fTemp157 + (fRec282[1] + fTemp158)));
			fRec280[0] = fRec282[0];
			double fRec281 = ((fTemp158 + fTemp157) + fTemp156);
			fRec279[0] = (fRec280[0] + fRec279[1]);
			fRec277[0] = fRec279[0];
			double fRec278 = fRec281;
			fRec276[0] = (fTemp154 + (fTemp155 + (fRec278 + fRec276[1])));
			fRec274[0] = fRec276[0];
			double fRec275 = (fTemp154 + (fRec278 + fTemp155));
			fRec273[0] = (fRec274[0] + fRec273[1]);
			fRec271[0] = fRec273[0];
			double fRec272 = fRec275;
			fRec270[0] = (fTemp153 + (fRec272 + fRec270[1]));
			fRec268[0] = fRec270[0];
			double fRec269 = (fRec272 + fTemp153);
			double fTemp159 = (fConst144 * fRec283[1]);
			double fTemp160 = (fConst145 * fRec286[1]);
			double fTemp161 = (fConst147 * (((0.090311218499999998 * fTemp55) + ((0.0085370923999999997 * fTemp54) + ((0.061950596500000003 * fTemp58) + ((0.0083175382999999999 * fTemp53) + ((0.0018797588000000001 * fTemp51) + (0.031695511599999997 * fTemp52)))))) - (((0.091039316100000003 * fTemp50) + (0.0019293779 * fTemp56)) + (0.022407991799999999 * fTemp57))));
			double fTemp162 = (fConst148 * fRec289[1]);
			double fTemp163 = (fConst149 * fRec292[1]);
			fRec294[0] = (fTemp161 + (fTemp162 + (fRec294[1] + fTemp163)));
			fRec292[0] = fRec294[0];
			double fRec293 = ((fTemp163 + fTemp162) + fTemp161);
			fRec291[0] = (fRec292[0] + fRec291[1]);
			fRec289[0] = fRec291[0];
			double fRec290 = fRec293;
			fRec288[0] = (fTemp159 + (fTemp160 + (fRec290 + fRec288[1])));
			fRec286[0] = fRec288[0];
			double fRec287 = (fTemp159 + (fRec290 + fTemp160));
			fRec285[0] = (fRec286[0] + fRec285[1]);
			fRec283[0] = fRec285[0];
			double fRec284 = fRec287;
			double fTemp164 = (fConst151 * fRec295[1]);
			double fTemp165 = (fConst153 * ((((((0.1045205107 * fTemp63) + (0.012676249000000001 * fTemp66)) + (0.068556329400000005 * fTemp67)) + (0.0020405406000000002 * fTemp64)) + (0.012047457500000001 * fTemp68)) + (0.069273872099999995 * fTemp65)));
			double fTemp166 = (fConst154 * fRec298[1]);
			double fTemp167 = (fConst155 * fRec301[1]);
			fRec303[0] = (fTemp165 + (fTemp166 + (fRec303[1] + fTemp167)));
			fRec301[0] = fRec303[0];
			double fRec302 = ((fTemp167 + fTemp166) + fTemp165);
			fRec300[0] = (fRec301[0] + fRec300[1]);
			fRec298[0] = fRec300[0];
			double fRec299 = fRec302;
			fRec297[0] = (fTemp164 + (fRec299 + fRec297[1]));
			fRec295[0] = fRec297[0];
			double fRec296 = (fRec299 + fTemp164);
			double fTemp168 = (fConst157 * (0.0 - (((0.11352769710000001 * fTemp72) + (0.0074971151 * fTemp74)) + (0.0266454686 * fTemp73))));
			double fTemp169 = (fConst158 * fRec304[1]);
			fRec306[0] = (fTemp168 + (fRec306[1] + fTemp169));
			fRec304[0] = fRec306[0];
			double fRec305 = (fTemp169 + fTemp168);
			double fTemp170 = (fConst160 * ((0.046977013300000002 * fTemp77) - ((((0.0017663479 * fTemp79) + (0.046076543599999999 * fTemp80)) + (0.0078157187999999995 * fTemp81)) + (0.095973451400000007 * fTemp78))));
			double fTemp171 = (fConst161 * fRec307[1]);
			double fTemp172 = (fConst162 * fRec310[1]);
			fRec312[0] = (fTemp170 + (fTemp171 + (fRec312[1] + fTemp172)));
			fRec310[0] = fRec312[0];
			double fRec311 = ((fTemp172 + fTemp171) + fTemp170);
			fRec309[0] = (fRec310[0] + fRec309[1]);
			fRec307[0] = fRec309[0];
			double fRec308 = fRec311;
			fVec3[(IOTA & 63)] = (((0.107287673 * fTemp91) + ((0.078141880799999994 * fTemp7) + ((0.028190826400000001 * fTemp8) + ((0.0004496573 * fTemp89) + ((0.044544389199999999 * fTemp88) + ((0.0076890055999999998 * fTemp87) + ((0.058935926700000002 * fTemp10) + (((0.078405086499999999 * fTemp12) + (fRec251 + (fRec269 + (fRec284 + (fRec296 + (fRec305 + fRec308)))))) + (0.0388292524 * fTemp86))))))))) - ((((0.040055152099999998 * fTemp85) + (0.012970093699999999 * fTemp11)) + (0.00041489689999999997 * fTemp9)) + (0.0057646101999999999 * fTemp90)));
			output3[i] = FAUSTFLOAT((0.96860189573459721 * (fRec0[0] * fVec3[((IOTA - iConst163) & 63)])));
			double fTemp173 = (fConst165 * fRec313[1]);
			double fTemp174 = (fConst166 * fRec316[1]);
			double fTemp175 = (fConst168 * fRec319[1]);
			double fTemp176 = (fConst169 * fRec322[1]);
			double fTemp177 = (fConst171 * ((((0.096044872700000006 * fTemp22) + ((((0.019972569799999999 * fTemp25) + ((0.021165191199999999 * fTemp24) + (0.098845160700000004 * fTemp20))) + (0.024107520699999999 * fTemp27)) + (0.027591273400000001 * fTemp28))) + (0.071909042199999995 * fTemp29)) - ((((((0.1087504437 * fTemp17) + (0.027245432199999999 * fTemp18)) + (0.022858785100000001 * fTemp19)) + (0.050672008099999999 * fTemp26)) + (0.0011340317 * fTemp21)) + (0.032886094599999999 * fTemp23))));
			double fTemp178 = (fConst172 * fRec325[1]);
			double fTemp179 = (fConst173 * fRec328[1]);
			fRec330[0] = (fTemp177 + (fTemp178 + (fRec330[1] + fTemp179)));
			fRec328[0] = fRec330[0];
			double fRec329 = ((fTemp179 + fTemp178) + fTemp177);
			fRec327[0] = (fRec328[0] + fRec327[1]);
			fRec325[0] = fRec327[0];
			double fRec326 = fRec329;
			fRec324[0] = (fTemp175 + (fTemp176 + (fRec326 + fRec324[1])));
			fRec322[0] = fRec324[0];
			double fRec323 = (fTemp175 + (fRec326 + fTemp176));
			fRec321[0] = (fRec322[0] + fRec321[1]);
			fRec319[0] = fRec321[0];
			double fRec320 = fRec323;
			fRec318[0] = (fTemp173 + (fTemp174 + (fRec320 + fRec318[1])));
			fRec316[0] = fRec318[0];
			double fRec317 = (fTemp173 + (fRec320 + fTemp174));
			fRec315[0] = (fRec316[0] + fRec315[1]);
			fRec313[0] = fRec315[0];
			double fRec314 = fRec317;
			double fTemp180 = (fConst175 * fRec331[1]);
			double fTemp181 = (fConst177 * fRec334[1]);
			double fTemp182 = (fConst178 * fRec337[1]);
			double fTemp183 = (fConst180 * (((0.041932340499999998 * fTemp44) + ((((0.10537215580000001 * fTemp36) + (0.065916432100000005 * fTemp41)) + (0.045115341900000001 * fTemp37)) + (0.042683117899999998 * fTemp40))) - ((((0.046612575900000001 * fTemp38) + (0.025108172000000002 * fTemp42)) + (0.059034964600000003 * fTemp39)) + (0.062955055999999995 * fTemp43))));
			double fTemp184 = (fConst181 * fRec340[1]);
			double fTemp185 = (fConst182 * fRec343[1]);
			fRec345[0] = (fTemp183 + (fTemp184 + (fRec345[1] + fTemp185)));
			fRec343[0] = fRec345[0];
			double fRec344 = ((fTemp185 + fTemp184) + fTemp183);
			fRec342[0] = (fRec343[0] + fRec342[1]);
			fRec340[0] = fRec342[0];
			double fRec341 = fRec344;
			fRec339[0] = (fTemp181 + (fTemp182 + (fRec341 + fRec339[1])));
			fRec337[0] = fRec339[0];
			double fRec338 = (fTemp181 + (fRec341 + fTemp182));
			fRec336[0] = (fRec337[0] + fRec336[1]);
			fRec334[0] = fRec336[0];
			double fRec335 = fRec338;
			fRec333[0] = (fTemp180 + (fRec335 + fRec333[1]));
			fRec331[0] = fRec333[0];
			double fRec332 = (fRec335 + fTemp180);
			double fTemp186 = (fConst184 * fRec346[1]);
			double fTemp187 = (fConst185 * fRec349[1]);
			double fTemp188 = (fConst187 * ((((0.027077492700000001 * fTemp56) + (0.045294052899999999 * fTemp52)) + (0.0013998791 * fTemp58)) - ((0.094812610500000005 * fTemp55) + (((((0.031551204200000002 * fTemp50) + (0.0885522059 * fTemp57)) + (0.0263811228 * fTemp51)) + (0.0318428459 * fTemp53)) + (0.032683386299999999 * fTemp54)))));
			double fTemp189 = (fConst188 * fRec352[1]);
			double fTemp190 = (fConst189 * fRec355[1]);
			fRec357[0] = (fTemp188 + (fTemp189 + (fRec357[1] + fTemp190)));
			fRec355[0] = fRec357[0];
			double fRec356 = ((fTemp190 + fTemp189) + fTemp188);
			fRec354[0] = (fRec355[0] + fRec354[1]);
			fRec352[0] = fRec354[0];
			double fRec353 = fRec356;
			fRec351[0] = (fTemp186 + (fTemp187 + (fRec353 + fRec351[1])));
			fRec349[0] = fRec351[0];
			double fRec350 = (fTemp186 + (fRec353 + fTemp187));
			fRec348[0] = (fRec349[0] + fRec348[1]);
			fRec346[0] = fRec348[0];
			double fRec347 = fRec350;
			double fTemp191 = (fConst191 * fRec358[1]);
			double fTemp192 = (fConst193 * (((((0.040016726599999997 * fTemp67) + (0.030684507100000001 * fTemp64)) + (0.051807931500000001 * fTemp68)) + (0.060823074099999999 * fTemp65)) - ((0.071193040299999996 * fTemp63) + (0.047796460300000003 * fTemp66))));
			double fTemp193 = (fConst194 * fRec361[1]);
			double fTemp194 = (fConst195 * fRec364[1]);
			fRec366[0] = (fTemp192 + (fTemp193 + (fRec366[1] + fTemp194)));
			fRec364[0] = fRec366[0];
			double fRec365 = ((fTemp194 + fTemp193) + fTemp192);
			fRec363[0] = (fRec364[0] + fRec363[1]);
			fRec361[0] = fRec363[0];
			double fRec362 = fRec365;
			fRec360[0] = (fTemp191 + (fRec362 + fRec360[1]));
			fRec358[0] = fRec360[0];
			double fRec359 = (fRec362 + fTemp191);
			double fTemp195 = (fConst197 * (0.0 - (((0.043233456900000002 * fTemp72) + (0.022491803599999999 * fTemp74)) + (0.0579102056 * fTemp73))));
			double fTemp196 = (fConst198 * fRec367[1]);
			fRec369[0] = (fTemp195 + (fRec369[1] + fTemp196));
			fRec367[0] = fRec369[0];
			double fRec368 = (fTemp196 + fTemp195);
			double fTemp197 = (fConst200 * ((((0.090947328999999993 * fTemp77) + (0.024789478699999999 * fTemp79)) + (0.0299216814 * fTemp81)) - ((0.0366158361 * fTemp80) + (0.0021686832999999999 * fTemp78))));
			double fTemp198 = (fConst201 * fRec370[1]);
			double fTemp199 = (fConst202 * fRec373[1]);
			fRec375[0] = (fTemp197 + (fTemp198 + (fRec375[1] + fTemp199)));
			fRec373[0] = fRec375[0];
			double fRec374 = ((fTemp199 + fTemp198) + fTemp197);
			fRec372[0] = (fRec373[0] + fRec372[1]);
			fRec370[0] = fRec372[0];
			double fRec371 = fRec374;
			fVec4[0] = (((0.069248237300000001 * fTemp8) + ((0.064389103899999994 * fTemp89) + ((0.016994444500000001 * fTemp9) + ((0.051383877100000003 * fTemp88) + ((0.048904417300000003 * fTemp11) + ((0.0116109686 * fTemp85) + ((0.0545039654 * fTemp12) + (fRec314 + (fRec332 + (fRec347 + (fRec359 + (fRec368 + fRec371)))))))))))) - ((0.11544958549999999 * fTemp91) + ((0.055355314000000003 * fTemp7) + ((((0.093678862299999999 * fTemp86) + (0.068675281599999999 * fTemp10)) + (0.028991798100000001 * fTemp87)) + (0.032140046899999997 * fTemp90)))));
			output4[i] = FAUSTFLOAT((0.99644549763033174 * (fRec0[0] * fVec4[iConst203])));
			double fTemp200 = (fConst205 * fRec376[1]);
			double fTemp201 = (fConst206 * fRec379[1]);
			double fTemp202 = (fConst208 * fRec382[1]);
			double fTemp203 = (fConst209 * fRec385[1]);
			double fTemp204 = (fConst211 * ((((0.096027887699999995 * fTemp22) + (((((0.1075554269 * fTemp17) + (0.027337536900000001 * fTemp18)) + (0.022936060500000001 * fTemp19)) + (0.024130148399999999 * fTemp27)) + (0.027617170999999999 * fTemp28))) + (0.072078085299999997 * fTemp29)) - ((((0.050576409599999997 * fTemp26) + (((0.020680620199999999 * fTemp24) + (0.098990057899999997 * fTemp20)) + (0.0200400882 * fTemp25))) + (0.0012085943 * fTemp21)) + (0.032916962000000001 * fTemp23))));
			double fTemp205 = (fConst212 * fRec388[1]);
			double fTemp206 = (fConst213 * fRec391[1]);
			fRec393[0] = (fTemp204 + (fTemp205 + (fRec393[1] + fTemp206)));
			fRec391[0] = fRec393[0];
			double fRec392 = ((fTemp206 + fTemp205) + fTemp204);
			fRec390[0] = (fRec391[0] + fRec390[1]);
			fRec388[0] = fRec390[0];
			double fRec389 = fRec392;
			fRec387[0] = (fTemp202 + (fTemp203 + (fRec389 + fRec387[1])));
			fRec385[0] = fRec387[0];
			double fRec386 = (fTemp202 + (fRec389 + fTemp203));
			fRec384[0] = (fRec385[0] + fRec384[1]);
			fRec382[0] = fRec384[0];
			double fRec383 = fRec386;
			fRec381[0] = (fTemp200 + (fTemp201 + (fRec383 + fRec381[1])));
			fRec379[0] = fRec381[0];
			double fRec380 = (fTemp200 + (fRec383 + fTemp201));
			fRec378[0] = (fRec379[0] + fRec378[1]);
			fRec376[0] = fRec378[0];
			double fRec377 = fRec380;
			double fTemp207 = (fConst215 * fRec394[1]);
			double fTemp208 = (fConst217 * fRec397[1]);
			double fTemp209 = (fConst218 * fRec400[1]);
			double fTemp210 = (fConst220 * (((0.042026538400000001 * fTemp44) + ((0.046550245699999999 * fTemp38) + (0.042618202500000001 * fTemp40))) - ((((((0.10632593160000001 * fTemp36) + (0.065589734299999994 * fTemp41)) + (0.045030280499999999 * fTemp37)) + (0.025064805999999999 * fTemp42)) + (0.059157188700000002 * fTemp39)) + (0.062925218099999999 * fTemp43))));
			double fTemp211 = (fConst221 * fRec403[1]);
			double fTemp212 = (fConst222 * fRec406[1]);
			fRec408[0] = (fTemp210 + (fTemp211 + (fRec408[1] + fTemp212)));
			fRec406[0] = fRec408[0];
			double fRec407 = ((fTemp212 + fTemp211) + fTemp210);
			fRec405[0] = (fRec406[0] + fRec405[1]);
			fRec403[0] = fRec405[0];
			double fRec404 = fRec407;
			fRec402[0] = (fTemp208 + (fTemp209 + (fRec404 + fRec402[1])));
			fRec400[0] = fRec402[0];
			double fRec401 = (fTemp208 + (fRec404 + fTemp209));
			fRec399[0] = (fRec400[0] + fRec399[1]);
			fRec397[0] = fRec399[0];
			double fRec398 = fRec401;
			fRec396[0] = (fTemp207 + (fRec398 + fRec396[1]));
			fRec394[0] = fRec396[0];
			double fRec395 = (fRec398 + fTemp207);
			double fTemp213 = (fConst224 * fRec409[1]);
			double fTemp214 = (fConst225 * fRec412[1]);
			double fTemp215 = (fConst227 * ((((((0.030828848400000001 * fTemp50) + (0.088794166399999999 * fTemp57)) + (0.026470305600000001 * fTemp51)) + (0.045214322500000001 * fTemp52)) + (0.0014919211 * fTemp58)) - ((0.094860844 * fTemp55) + (((0.027169029599999998 * fTemp56) + (0.031872734100000001 * fTemp53)) + (0.0327140634 * fTemp54)))));
			double fTemp216 = (fConst228 * fRec415[1]);
			double fTemp217 = (fConst229 * fRec418[1]);
			fRec420[0] = (fTemp215 + (fTemp216 + (fRec420[1] + fTemp217)));
			fRec418[0] = fRec420[0];
			double fRec419 = ((fTemp217 + fTemp216) + fTemp215);
			fRec417[0] = (fRec418[0] + fRec417[1]);
			fRec415[0] = fRec417[0];
			double fRec416 = fRec419;
			fRec414[0] = (fTemp213 + (fTemp214 + (fRec416 + fRec414[1])));
			fRec412[0] = fRec414[0];
			double fRec413 = (fTemp213 + (fRec416 + fTemp214));
			fRec411[0] = (fRec412[0] + fRec411[1]);
			fRec409[0] = fRec411[0];
			double fRec410 = fRec413;
			double fTemp218 = (fConst231 * fRec421[1]);
			double fTemp219 = (fConst233 * ((((((0.070602898100000006 * fTemp63) + (0.047706343900000003 * fTemp66)) + (0.030643019800000001 * fTemp64)) + (0.051941071700000001 * fTemp68)) + (0.060745716300000002 * fTemp65)) - (0.0398738431 * fTemp67)));
			double fTemp220 = (fConst234 * fRec424[1]);
			double fTemp221 = (fConst235 * fRec427[1]);
			fRec429[0] = (fTemp219 + (fTemp220 + (fRec429[1] + fTemp221)));
			fRec427[0] = fRec429[0];
			double fRec428 = ((fTemp221 + fTemp220) + fTemp219);
			fRec426[0] = (fRec427[0] + fRec426[1]);
			fRec424[0] = fRec426[0];
			double fRec425 = fRec428;
			fRec423[0] = (fTemp218 + (fRec425 + fRec423[1]));
			fRec421[0] = fRec423[0];
			double fRec422 = (fRec425 + fTemp218);
			double fTemp222 = (fConst237 * ((0.042925372900000001 * fTemp72) - ((0.0224524168 * fTemp74) + (0.058102569299999997 * fTemp73))));
			double fTemp223 = (fConst238 * fRec430[1]);
			fRec432[0] = (fTemp222 + (fRec432[1] + fTemp223));
			fRec430[0] = fRec432[0];
			double fRec431 = (fTemp223 + fTemp222);
			double fTemp224 = (fConst240 * ((0.029949766400000001 * fTemp81) - ((((0.091409349000000001 * fTemp77) + (0.024873280899999999 * fTemp79)) + (0.036533603300000002 * fTemp80)) + (0.0023112743 * fTemp78))));
			double fTemp225 = (fConst241 * fRec433[1]);
			double fTemp226 = (fConst242 * fRec436[1]);
			fRec438[0] = (fTemp224 + (fTemp225 + (fRec438[1] + fTemp226)));
			fRec436[0] = fRec438[0];
			double fRec437 = ((fTemp226 + fTemp225) + fTemp224);
			fRec435[0] = (fRec436[0] + fRec435[1]);
			fRec433[0] = fRec435[0];
			double fRec434 = fRec437;
			output5[i] = FAUSTFLOAT((fRec0[0] * (((0.069240172599999997 * fTemp8) + ((0.064506592900000007 * fTemp89) + ((0.016973777900000001 * fTemp9) + ((0.028937136400000001 * fTemp87) + ((0.068455955700000001 * fTemp10) + (((0.054383521300000001 * fTemp12) + (fRec377 + (fRec395 + (fRec410 + (fRec422 + (fRec431 + fRec434)))))) + (0.094400098500000001 * fTemp86))))))) - ((0.1152724425 * fTemp91) + ((0.055444397899999998 * fTemp7) + ((((0.0129103015 * fTemp85) + (0.048812212000000001 * fTemp11)) + (0.051369802200000002 * fTemp88)) + (0.032091166099999999 * fTemp90)))))));
			double fTemp227 = (fConst244 * fRec439[1]);
			double fTemp228 = (fConst245 * fRec442[1]);
			double fTemp229 = (fConst247 * fRec445[1]);
			double fTemp230 = (fConst248 * fRec448[1]);
			double fTemp231 = (fConst250 * (((0.0014387464 * fTemp25) + (0.0086055155000000008 * fTemp23)) - (((0.0546868384 * fTemp22) + ((0.0072199856000000001 * fTemp28) + ((0.050180671000000003 * fTemp21) + ((0.0063083697000000001 * fTemp27) + ((((((0.12694803690000001 * fTemp17) + (0.0019626550999999998 * fTemp18)) + (0.0612384895 * fTemp24)) + (0.0016466581000000001 * fTemp19)) + (0.010885661200000001 * fTemp20)) + (0.035110757499999999 * fTemp26)))))) + (0.012899734 * fTemp29))));
			double fTemp232 = (fConst251 * fRec451[1]);
			double fTemp233 = (fConst252 * fRec454[1]);
			fRec456[0] = (fTemp231 + (fTemp232 + (fRec456[1] + fTemp233)));
			fRec454[0] = fRec456[0];
			double fRec455 = ((fTemp233 + fTemp232) + fTemp231);
			fRec453[0] = (fRec454[0] + fRec453[1]);
			fRec451[0] = fRec453[0];
			double fRec452 = fRec455;
			fRec450[0] = (fTemp229 + (fTemp230 + (fRec452 + fRec450[1])));
			fRec448[0] = fRec450[0];
			double fRec449 = (fTemp229 + (fRec452 + fTemp230));
			fRec447[0] = (fRec448[0] + fRec447[1]);
			fRec445[0] = fRec447[0];
			double fRec446 = fRec449;
			fRec444[0] = (fTemp227 + (fTemp228 + (fRec446 + fRec444[1])));
			fRec442[0] = fRec444[0];
			double fRec443 = (fTemp227 + (fRec446 + fTemp228));
			fRec441[0] = (fRec442[0] + fRec441[1]);
			fRec439[0] = fRec441[0];
			double fRec440 = fRec443;
			double fTemp234 = (fConst254 * fRec457[1]);
			double fTemp235 = (fConst256 * fRec460[1]);
			double fTemp236 = (fConst257 * fRec463[1]);
			double fTemp237 = (fConst259 * ((((((0.055286106000000002 * fTemp36) + (0.070339624000000003 * fTemp41)) + (0.0119471439 * fTemp37)) + (0.053169417400000002 * fTemp38)) + (0.0076860519999999996 * fTemp40)) - ((((0.0079837580000000005 * fTemp42) + (0.0047723773000000001 * fTemp39)) + (0.0398519476 * fTemp43)) + (0.1051464275 * fTemp44))));
			double fTemp238 = (fConst260 * fRec466[1]);
			double fTemp239 = (fConst261 * fRec469[1]);
			fRec471[0] = (fTemp237 + (fTemp238 + (fRec471[1] + fTemp239)));
			fRec469[0] = fRec471[0];
			double fRec470 = ((fTemp239 + fTemp238) + fTemp237);
			fRec468[0] = (fRec469[0] + fRec468[1]);
			fRec466[0] = fRec468[0];
			double fRec467 = fRec470;
			fRec465[0] = (fTemp235 + (fTemp236 + (fRec467 + fRec465[1])));
			fRec463[0] = fRec465[0];
			double fRec464 = (fTemp235 + (fRec467 + fTemp236));
			fRec462[0] = (fRec463[0] + fRec462[1]);
			fRec460[0] = fRec462[0];
			double fRec461 = fRec464;
			fRec459[0] = (fTemp234 + (fRec461 + fRec459[1]));
			fRec457[0] = fRec459[0];
			double fRec458 = (fRec461 + fTemp234);
			double fTemp240 = (fConst263 * fRec472[1]);
			double fTemp241 = (fConst264 * fRec475[1]);
			double fTemp242 = (fConst266 * (((0.090231101300000005 * fTemp55) + ((0.0085524715000000005 * fTemp54) + ((0.061944365100000003 * fTemp58) + ((0.0083325219000000006 * fTemp53) + ((((0.091288950199999996 * fTemp50) + (0.0019505574 * fTemp56)) + (0.022299506 * fTemp57)) + (0.031722130000000001 * fTemp52)))))) - (0.0019003936 * fTemp51)));
			double fTemp243 = (fConst267 * fRec478[1]);
			double fTemp244 = (fConst268 * fRec481[1]);
			fRec483[0] = (fTemp242 + (fTemp243 + (fRec483[1] + fTemp244)));
			fRec481[0] = fRec483[0];
			double fRec482 = ((fTemp244 + fTemp243) + fTemp242);
			fRec480[0] = (fRec481[0] + fRec480[1]);
			fRec478[0] = fRec480[0];
			double fRec479 = fRec482;
			fRec477[0] = (fTemp240 + (fTemp241 + (fRec479 + fRec477[1])));
			fRec475[0] = fRec477[0];
			double fRec476 = (fTemp240 + (fRec479 + fTemp241));
			fRec474[0] = (fRec475[0] + fRec474[1]);
			fRec472[0] = fRec474[0];
			double fRec473 = fRec476;
			double fTemp245 = (fConst270 * fRec484[1]);
			double fTemp246 = (fConst272 * ((((0.0020629643000000001 * fTemp64) + (0.012020138499999999 * fTemp68)) + (0.069240642899999996 * fTemp65)) - (((0.1042931345 * fTemp63) + (0.0126571398 * fTemp66)) + (0.068619239100000007 * fTemp67))));
			double fTemp247 = (fConst273 * fRec487[1]);
			double fTemp248 = (fConst274 * fRec490[1]);
			fRec492[0] = (fTemp246 + (fTemp247 + (fRec492[1] + fTemp248)));
			fRec490[0] = fRec492[0];
			double fRec491 = ((fTemp248 + fTemp247) + fTemp246);
			fRec489[0] = (fRec490[0] + fRec489[1]);
			fRec487[0] = fRec489[0];
			double fRec488 = fRec491;
			fRec486[0] = (fTemp245 + (fRec488 + fRec486[1]));
			fRec484[0] = fRec486[0];
			double fRec485 = (fRec488 + fTemp245);
			double fTemp249 = (fConst276 * ((0.1136477249 * fTemp72) - ((0.0075126222000000001 * fTemp74) + (0.026613416599999998 * fTemp73))));
			double fTemp250 = (fConst277 * fRec493[1]);
			fRec495[0] = (fTemp249 + (fRec495[1] + fTemp250));
			fRec493[0] = fRec495[0];
			double fRec494 = (fTemp250 + fTemp249);
			double fTemp251 = (fConst279 * ((0.0017857378 * fTemp79) - ((((0.046790461999999998 * fTemp77) + (0.046093823499999999 * fTemp80)) + (0.0078297985000000004 * fTemp81)) + (0.0959637978 * fTemp78))));
			double fTemp252 = (fConst280 * fRec496[1]);
			double fTemp253 = (fConst281 * fRec499[1]);
			fRec501[0] = (fTemp251 + (fTemp252 + (fRec501[1] + fTemp253)));
			fRec499[0] = fRec501[0];
			double fRec500 = ((fTemp253 + fTemp252) + fTemp251);
			fRec498[0] = (fRec499[0] + fRec498[1]);
			fRec496[0] = fRec498[0];
			double fRec497 = fRec500;
			fVec5[(IOTA & 127)] = (((0.1072014716 * fTemp91) + ((0.078241092100000006 * fTemp7) + ((0.028155737100000001 * fTemp8) + ((0.00041737369999999998 * fTemp89) + ((0.012950541600000001 * fTemp11) + ((0.040347696299999999 * fTemp85) + ((0.078427896900000002 * fTemp12) + (fRec440 + (fRec458 + (fRec473 + (fRec485 + (fRec494 + fRec497)))))))))))) - (((0.00040223830000000001 * fTemp9) + ((((0.039038271100000001 * fTemp86) + (0.058835819800000001 * fTemp10)) + (0.0076774145999999998 * fTemp87)) + (0.044567796700000002 * fTemp88))) + (0.0057875358000000002 * fTemp90)));
			output6[i] = FAUSTFLOAT((0.96623222748815174 * (fRec0[0] * fVec5[((IOTA - iConst282) & 127)])));
			double fTemp254 = (fConst284 * fRec502[1]);
			double fTemp255 = (fConst285 * fRec505[1]);
			double fTemp256 = (fConst287 * fRec508[1]);
			double fTemp257 = (fConst288 * fRec511[1]);
			double fTemp258 = (fConst290 * (((0.10348080530000001 * fTemp29) + ((0.018086872699999999 * fTemp23) + ((((((1.6568199999999998e-05 * fTemp17) + (0.013673373399999999 * fTemp18)) + (0.069615897400000001 * fTemp24)) + (0.011471893800000001 * fTemp19)) + (0.077594273800000002 * fTemp20)) + (0.046557062099999998 * fTemp22)))) - ((0.015174798200000001 * fTemp28) + ((0.030458701599999999 * fTemp21) + ((0.013258785 * fTemp27) + ((0.010023419800000001 * fTemp25) + (0.055981096100000002 * fTemp26)))))));
			double fTemp259 = (fConst291 * fRec514[1]);
			double fTemp260 = (fConst292 * fRec517[1]);
			fRec519[0] = (fTemp258 + (fTemp259 + (fRec519[1] + fTemp260)));
			fRec517[0] = fRec519[0];
			double fRec518 = ((fTemp260 + fTemp259) + fTemp258);
			fRec516[0] = (fRec517[0] + fRec516[1]);
			fRec514[0] = fRec516[0];
			double fRec515 = fRec518;
			fRec513[0] = (fTemp256 + (fTemp257 + (fRec515 + fRec513[1])));
			fRec511[0] = fRec513[0];
			double fRec512 = (fTemp256 + (fRec515 + fTemp257));
			fRec510[0] = (fRec511[0] + fRec510[1]);
			fRec508[0] = fRec510[0];
			double fRec509 = fRec512;
			fRec507[0] = (fTemp254 + (fTemp255 + (fRec509 + fRec507[1])));
			fRec505[0] = fRec507[0];
			double fRec506 = (fTemp254 + (fRec509 + fTemp255));
			fRec504[0] = (fRec505[0] + fRec504[1]);
			fRec502[0] = fRec504[0];
			double fRec503 = fRec506;
			double fTemp261 = (fConst294 * fRec520[1]);
			double fTemp262 = (fConst296 * fRec523[1]);
			double fTemp263 = (fConst297 * fRec526[1]);
			double fTemp264 = (fConst299 * (((0.066058618900000005 * fTemp44) + ((0.037281671299999999 * fTemp40) + (((((0.0020940268 * fTemp41) + (0.025169695700000001 * fTemp37)) + (0.0585104948 * fTemp38)) + (0.040696024400000003 * fTemp39)) + (0.081438513099999998 * fTemp43)))) - ((0.078925176599999994 * fTemp36) + (0.023778285 * fTemp42))));
			double fTemp265 = (fConst300 * fRec529[1]);
			double fTemp266 = (fConst301 * fRec532[1]);
			fRec534[0] = (fTemp264 + (fTemp265 + (fRec534[1] + fTemp266)));
			fRec532[0] = fRec534[0];
			double fRec533 = ((fTemp266 + fTemp265) + fTemp264);
			fRec531[0] = (fRec532[0] + fRec531[1]);
			fRec529[0] = fRec531[0];
			double fRec530 = fRec533;
			fRec528[0] = (fTemp262 + (fTemp263 + (fRec530 + fRec528[1])));
			fRec526[0] = fRec528[0];
			double fRec527 = (fTemp262 + (fRec530 + fTemp263));
			fRec525[0] = (fRec526[0] + fRec525[1]);
			fRec523[0] = fRec525[0];
			double fRec524 = fRec527;
			fRec522[0] = (fTemp261 + (fRec524 + fRec522[1]));
			fRec520[0] = fRec522[0];
			double fRec521 = (fRec524 + fTemp261);
			double fTemp267 = (fConst303 * fRec535[1]);
			double fTemp268 = (fConst304 * fRec538[1]);
			double fTemp269 = (fConst306 * (((0.017975386100000001 * fTemp54) + ((0.037599037600000003 * fTemp58) + ((0.017513101100000001 * fTemp53) + ((0.013239611700000001 * fTemp51) + (0.049563527500000003 * fTemp52))))) - ((((0.10377725259999999 * fTemp50) + (0.013589091399999999 * fTemp56)) + (0.077114491899999998 * fTemp57)) + (0.0271607138 * fTemp55))));
			double fTemp270 = (fConst307 * fRec541[1]);
			double fTemp271 = (fConst308 * fRec544[1]);
			fRec546[0] = (fTemp269 + (fTemp270 + (fRec546[1] + fTemp271)));
			fRec544[0] = fRec546[0];
			double fRec545 = ((fTemp271 + fTemp270) + fTemp269);
			fRec543[0] = (fRec544[0] + fRec543[1]);
			fRec541[0] = fRec543[0];
			double fRec542 = fRec545;
			fRec540[0] = (fTemp267 + (fTemp268 + (fRec542 + fRec540[1])));
			fRec538[0] = fRec540[0];
			double fRec539 = (fTemp267 + (fRec542 + fTemp268));
			fRec537[0] = (fRec538[0] + fRec537[1]);
			fRec535[0] = fRec537[0];
			double fRec536 = fRec539;
			double fTemp272 = (fConst310 * fRec547[1]);
			double fTemp273 = (fConst312 * ((0.024953963900000001 * fTemp64) - (((((0.017450411400000001 * fTemp63) + (0.026665482599999998 * fTemp66)) + (0.064503331400000002 * fTemp67)) + (0.038900858199999999 * fTemp68)) + (0.1042281463 * fTemp65))));
			double fTemp274 = (fConst313 * fRec550[1]);
			double fTemp275 = (fConst314 * fRec553[1]);
			fRec555[0] = (fTemp273 + (fTemp274 + (fRec555[1] + fTemp275)));
			fRec553[0] = fRec555[0];
			double fRec554 = ((fTemp275 + fTemp274) + fTemp273);
			fRec552[0] = (fRec553[0] + fRec552[1]);
			fRec550[0] = fRec552[0];
			double fRec551 = fRec554;
			fRec549[0] = (fTemp272 + (fRec551 + fRec549[1]));
			fRec547[0] = fRec549[0];
			double fRec548 = (fRec551 + fTemp272);
			double fTemp276 = (fConst316 * (((0.094235591499999993 * fTemp72) + (0.048844738700000001 * fTemp73)) - (0.0214930118 * fTemp74)));
			double fTemp277 = (fConst317 * fRec556[1]);
			fRec558[0] = (fTemp276 + (fRec558[1] + fTemp277));
			fRec556[0] = fRec558[0];
			double fRec557 = (fTemp277 + fTemp276);
			double fTemp278 = (fConst319 * ((0.093669703800000004 * fTemp77) - ((((0.0124408303 * fTemp79) + (0.049628109599999998 * fTemp80)) + (0.016456488599999999 * fTemp81)) + (0.058248178599999999 * fTemp78))));
			double fTemp279 = (fConst320 * fRec559[1]);
			double fTemp280 = (fConst321 * fRec562[1]);
			fRec564[0] = (fTemp278 + (fTemp279 + (fRec564[1] + fTemp280)));
			fRec562[0] = fRec564[0];
			double fRec563 = ((fTemp280 + fTemp279) + fTemp278);
			fRec561[0] = (fRec562[0] + fRec561[1]);
			fRec559[0] = fRec561[0];
			double fRec560 = fRec563;
			fVec6[(IOTA & 63)] = (((0.046272962799999998 * fTemp91) + ((0.012996345899999999 * fTemp9) + ((0.0055662804999999996 * fTemp10) + ((0.064644924500000006 * fTemp86) + ((0.027283608000000001 * fTemp11) + ((0.090263260200000001 * fTemp85) + ((0.077355982399999995 * fTemp12) + (fRec503 + (fRec521 + (fRec536 + (fRec548 + (fRec557 + fRec560)))))))))))) - ((0.029890447600000002 * fTemp7) + ((0.028072800700000001 * fTemp90) + ((0.076547270099999995 * fTemp8) + (((0.016174425499999999 * fTemp87) + (0.055774785200000003 * fTemp88)) + (0.042438766000000003 * fTemp89))))));
			output7[i] = FAUSTFLOAT((0.976303317535545 * (fRec0[0] * fVec6[((IOTA - iConst322) & 63)])));
			double fTemp281 = (fConst324 * fRec565[1]);
			double fTemp282 = (fConst325 * fRec568[1]);
			double fTemp283 = (fConst327 * fRec571[1]);
			double fTemp284 = (fConst328 * fRec574[1]);
			double fTemp285 = (fConst330 * (((0.056823825600000002 * fTemp28) + ((0.0075870327999999999 * fTemp21) + ((0.049649087799999998 * fTemp27) + ((0.045040491199999998 * fTemp25) + (0.050015590300000003 * fTemp26))))) - ((0.0162744763 * fTemp29) + ((0.067728432800000002 * fTemp23) + ((((((0.0728313716 * fTemp17) + (0.061441650100000002 * fTemp18)) + (0.0038000081000000002 * fTemp24)) + (0.0515492455 * fTemp19)) + (0.053809522700000001 * fTemp20)) + (0.0170817183 * fTemp22))))));
			double fTemp286 = (fConst331 * fRec577[1]);
			double fTemp287 = (fConst332 * fRec580[1]);
			fRec582[0] = (fTemp285 + (fTemp286 + (fRec582[1] + fTemp287)));
			fRec580[0] = fRec582[0];
			double fRec581 = ((fTemp287 + fTemp286) + fTemp285);
			fRec579[0] = (fRec580[0] + fRec579[1]);
			fRec577[0] = fRec579[0];
			double fRec578 = fRec581;
			fRec576[0] = (fTemp283 + (fTemp284 + (fRec578 + fRec576[1])));
			fRec574[0] = fRec576[0];
			double fRec575 = (fTemp283 + (fRec578 + fTemp284));
			fRec573[0] = (fRec574[0] + fRec573[1]);
			fRec571[0] = fRec573[0];
			double fRec572 = fRec575;
			fRec570[0] = (fTemp281 + (fTemp282 + (fRec572 + fRec570[1])));
			fRec568[0] = fRec570[0];
			double fRec569 = (fTemp281 + (fRec572 + fTemp282));
			fRec567[0] = (fRec568[0] + fRec567[1]);
			fRec565[0] = fRec567[0];
			double fRec566 = fRec569;
			double fTemp288 = (fConst334 * fRec583[1]);
			double fTemp289 = (fConst336 * fRec586[1]);
			double fTemp290 = (fConst337 * fRec589[1]);
			double fTemp291 = (fConst339 * ((0.049962677099999998 * fTemp42) - ((0.0543968773 * fTemp44) + ((0.094930701100000001 * fTemp40) + ((((((0.054013144800000003 * fTemp36) + (3.2676799999999999e-05 * fTemp41)) + (0.081718409199999995 * fTemp37)) + (0.029788160599999999 * fTemp38)) + (0.036786027300000003 * fTemp39)) + (0.011325516900000001 * fTemp43))))));
			double fTemp292 = (fConst340 * fRec592[1]);
			double fTemp293 = (fConst341 * fRec595[1]);
			fRec597[0] = (fTemp291 + (fTemp292 + (fRec597[1] + fTemp293)));
			fRec595[0] = fRec597[0];
			double fRec596 = ((fTemp293 + fTemp292) + fTemp291);
			fRec594[0] = (fRec595[0] + fRec594[1]);
			fRec592[0] = fRec594[0];
			double fRec593 = fRec596;
			fRec591[0] = (fTemp289 + (fTemp290 + (fRec593 + fRec591[1])));
			fRec589[0] = fRec591[0];
			double fRec590 = (fTemp289 + (fRec593 + fTemp290));
			fRec588[0] = (fRec589[0] + fRec588[1]);
			fRec586[0] = fRec588[0];
			double fRec587 = fRec590;
			fRec585[0] = (fTemp288 + (fRec587 + fRec585[1]));
			fRec583[0] = fRec585[0];
			double fRec584 = (fRec587 + fTemp288);
			double fTemp294 = (fConst343 * fRec598[1]);
			double fTemp295 = (fConst344 * fRec601[1]);
			double fTemp296 = (fConst346 * ((((0.0056647175999999999 * fTemp50) + (0.061062926699999999 * fTemp56)) + (0.0058081916000000001 * fTemp57)) - ((0.082098477700000005 * fTemp55) + ((0.067310957899999996 * fTemp54) + ((0.0093656365999999994 * fTemp58) + (((0.059492530799999999 * fTemp51) + (0.038453809300000003 * fTemp52)) + (0.065579877300000006 * fTemp53)))))));
			double fTemp297 = (fConst347 * fRec604[1]);
			double fTemp298 = (fConst348 * fRec607[1]);
			fRec609[0] = (fTemp296 + (fTemp297 + (fRec609[1] + fTemp298)));
			fRec607[0] = fRec609[0];
			double fRec608 = ((fTemp298 + fTemp297) + fTemp296);
			fRec606[0] = (fRec607[0] + fRec606[1]);
			fRec604[0] = fRec606[0];
			double fRec605 = fRec608;
			fRec603[0] = (fTemp294 + (fTemp295 + (fRec605 + fRec603[1])));
			fRec601[0] = fRec603[0];
			double fRec602 = (fTemp294 + (fRec605 + fTemp295));
			fRec600[0] = (fRec601[0] + fRec600[1]);
			fRec598[0] = fRec600[0];
			double fRec599 = fRec602;
			double fTemp299 = (fConst350 * fRec610[1]);
			double fTemp300 = (fConst352 * (((0.064237347299999997 * fTemp63) + (0.086574777899999997 * fTemp66)) - ((((0.0050416534000000002 * fTemp67) + (0.074124746899999996 * fTemp64)) + (0.00056124069999999998 * fTemp68)) + (0.053633159299999997 * fTemp65))));
			double fTemp301 = (fConst353 * fRec613[1]);
			double fTemp302 = (fConst354 * fRec616[1]);
			fRec618[0] = (fTemp300 + (fTemp301 + (fRec618[1] + fTemp302)));
			fRec616[0] = fRec618[0];
			double fRec617 = ((fTemp302 + fTemp301) + fTemp300);
			fRec615[0] = (fRec616[0] + fRec615[1]);
			fRec613[0] = fRec615[0];
			double fRec614 = fRec617;
			fRec612[0] = (fTemp299 + (fRec614 + fRec612[1]));
			fRec610[0] = fRec612[0];
			double fRec611 = (fRec614 + fTemp299);
			double fTemp303 = (fConst356 * (((0.0581017151 * fTemp72) + (0.0441436625 * fTemp74)) + (0.055887859599999999 * fTemp73)));
			double fTemp304 = (fConst357 * fRec619[1]);
			fRec621[0] = (fTemp303 + (fRec621[1] + fTemp304));
			fRec619[0] = fRec621[0];
			double fRec620 = (fTemp304 + fTemp303);
			double fTemp305 = (fConst359 * (((((0.074752368499999999 * fTemp77) + (0.0559031865 * fTemp79)) + (0.061623267000000002 * fTemp81)) + (0.0145091818 * fTemp78)) - (0.015328344900000001 * fTemp80)));
			double fTemp306 = (fConst360 * fRec622[1]);
			double fTemp307 = (fConst361 * fRec625[1]);
			fRec627[0] = (fTemp305 + (fTemp306 + (fRec627[1] + fTemp307)));
			fRec625[0] = fRec627[0];
			double fRec626 = ((fTemp307 + fTemp306) + fTemp305);
			fRec624[0] = (fRec625[0] + fRec624[1]);
			fRec622[0] = fRec624[0];
			double fRec623 = fRec626;
			fVec7[(IOTA & 255)] = (((0.042698509599999997 * fTemp91) + ((0.071482059799999997 * fTemp90) + ((0.045398128199999999 * fTemp8) + ((0.060200374100000002 * fTemp89) + ((0.051552578100000003 * fTemp88) + (((0.054668847 * fTemp12) + (fRec566 + (fRec584 + (fRec599 + (fRec611 + (fRec620 + fRec623)))))) + (0.052513480299999998 * fTemp87))))))) - ((((((0.076882275799999997 * fTemp85) + (0.088581644700000003 * fTemp11)) + (0.0138158055 * fTemp86)) + (0.032716120500000001 * fTemp10)) + (0.043676942000000003 * fTemp9)) + (0.0187112532 * fTemp7)));
			output8[i] = FAUSTFLOAT((0.89454976303317535 * (fRec0[0] * fVec7[((IOTA - iConst362) & 255)])));
			double fTemp308 = (fConst324 * fRec628[1]);
			double fTemp309 = (fConst325 * fRec631[1]);
			double fTemp310 = (fConst327 * fRec634[1]);
			double fTemp311 = (fConst328 * fRec637[1]);
			double fTemp312 = (fConst330 * (((0.057368982200000002 * fTemp28) + ((0.0066776346000000002 * fTemp21) + ((0.0501254114 * fTemp27) + ((((((0.070565238399999994 * fTemp17) + (0.062312016400000003 * fTemp18)) + (0.0026252399 * fTemp24)) + (0.052279478599999998 * fTemp19)) + (0.0555277936 * fTemp20)) + (0.051652841099999999 * fTemp26))))) - ((0.0118457565 * fTemp29) + ((0.068378206100000005 * fTemp23) + ((0.045678522899999997 * fTemp25) + (0.0187762686 * fTemp22))))));
			double fTemp313 = (fConst331 * fRec640[1]);
			double fTemp314 = (fConst332 * fRec643[1]);
			fRec645[0] = (fTemp312 + (fTemp313 + (fRec645[1] + fTemp314)));
			fRec643[0] = fRec645[0];
			double fRec644 = ((fTemp314 + fTemp313) + fTemp312);
			fRec642[0] = (fRec643[0] + fRec642[1]);
			fRec640[0] = fRec642[0];
			double fRec641 = fRec644;
			fRec639[0] = (fTemp310 + (fTemp311 + (fRec641 + fRec639[1])));
			fRec637[0] = fRec639[0];
			double fRec638 = (fTemp310 + (fRec641 + fTemp311));
			fRec636[0] = (fRec637[0] + fRec636[1]);
			fRec634[0] = fRec636[0];
			double fRec635 = fRec638;
			fRec633[0] = (fTemp308 + (fTemp309 + (fRec635 + fRec633[1])));
			fRec631[0] = fRec633[0];
			double fRec632 = (fTemp308 + (fRec635 + fTemp309));
			fRec630[0] = (fRec631[0] + fRec630[1]);
			fRec628[0] = fRec630[0];
			double fRec629 = fRec632;
			double fTemp315 = (fConst334 * fRec646[1]);
			double fTemp316 = (fConst336 * fRec649[1]);
			double fTemp317 = (fConst337 * fRec652[1]);
			double fTemp318 = (fConst339 * (((((0.054311706000000001 * fTemp36) + (0.082639660099999998 * fTemp37)) + (0.0307688562 * fTemp38)) + (0.050784806500000002 * fTemp42)) - ((0.050875646500000003 * fTemp44) + ((0.096254829799999997 * fTemp40) + (((0.0017922152000000001 * fTemp41) + (0.038701110099999998 * fTemp39)) + (0.011634407899999999 * fTemp43))))));
			double fTemp319 = (fConst340 * fRec655[1]);
			double fTemp320 = (fConst341 * fRec658[1]);
			fRec660[0] = (fTemp318 + (fTemp319 + (fRec660[1] + fTemp320)));
			fRec658[0] = fRec660[0];
			double fRec659 = ((fTemp320 + fTemp319) + fTemp318);
			fRec657[0] = (fRec658[0] + fRec657[1]);
			fRec655[0] = fRec657[0];
			double fRec656 = fRec659;
			fRec654[0] = (fTemp316 + (fTemp317 + (fRec656 + fRec654[1])));
			fRec652[0] = fRec654[0];
			double fRec653 = (fTemp316 + (fRec656 + fTemp317));
			fRec651[0] = (fRec652[0] + fRec651[1]);
			fRec649[0] = fRec651[0];
			double fRec650 = fRec653;
			fRec648[0] = (fTemp315 + (fRec650 + fRec648[1]));
			fRec646[0] = fRec648[0];
			double fRec647 = (fRec650 + fTemp315);
			double fTemp321 = (fConst343 * fRec661[1]);
			double fTemp322 = (fConst344 * fRec664[1]);
			double fTemp323 = (fConst346 * ((0.060335286299999999 * fTemp51) - ((0.081072711399999997 * fTemp55) + ((0.067956726100000003 * fTemp54) + ((0.0082430511000000008 * fTemp58) + (((((0.0039134766000000001 * fTemp50) + (0.061927928100000001 * fTemp56)) + (0.0072459211000000003 * fTemp57)) + (0.039842206099999999 * fTemp52)) + (0.066209037700000001 * fTemp53)))))));
			double fTemp324 = (fConst347 * fRec667[1]);
			double fTemp325 = (fConst348 * fRec670[1]);
			fRec672[0] = (fTemp323 + (fTemp324 + (fRec672[1] + fTemp325)));
			fRec670[0] = fRec672[0];
			double fRec671 = ((fTemp325 + fTemp324) + fTemp323);
			fRec669[0] = (fRec670[0] + fRec669[1]);
			fRec667[0] = fRec669[0];
			double fRec668 = fRec671;
			fRec666[0] = (fTemp321 + (fTemp322 + (fRec668 + fRec666[1])));
			fRec664[0] = fRec666[0];
			double fRec665 = (fTemp321 + (fRec668 + fTemp322));
			fRec663[0] = (fRec664[0] + fRec663[1]);
			fRec661[0] = fRec663[0];
			double fRec662 = fRec665;
			double fTemp326 = (fConst350 * fRec673[1]);
			double fTemp327 = (fConst352 * (((0.0044063354999999997 * fTemp67) + (0.0014093745000000001 * fTemp68)) - ((((0.062387639500000001 * fTemp63) + (0.087550776900000002 * fTemp66)) + (0.075033435100000004 * fTemp64)) + (0.053844976599999997 * fTemp65))));
			double fTemp328 = (fConst353 * fRec676[1]);
			double fTemp329 = (fConst354 * fRec679[1]);
			fRec681[0] = (fTemp327 + (fTemp328 + (fRec681[1] + fTemp329)));
			fRec679[0] = fRec681[0];
			double fRec680 = ((fTemp329 + fTemp328) + fTemp327);
			fRec678[0] = (fRec679[0] + fRec678[1]);
			fRec676[0] = fRec678[0];
			double fRec677 = fRec680;
			fRec675[0] = (fTemp326 + (fRec677 + fRec675[1]));
			fRec673[0] = fRec675[0];
			double fRec674 = (fRec677 + fTemp326);
			double fTemp330 = (fConst356 * (((0.044884626099999998 * fTemp74) + (0.053197242700000001 * fTemp73)) - (0.057770672699999998 * fTemp72)));
			double fTemp331 = (fConst357 * fRec682[1]);
			fRec684[0] = (fTemp330 + (fRec684[1] + fTemp331));
			fRec682[0] = fRec684[0];
			double fRec683 = (fTemp331 + fTemp330);
			double fTemp332 = (fConst359 * (((0.062214468500000002 * fTemp81) + (0.0127700798 * fTemp78)) - (((0.073469205800000006 * fTemp77) + (0.056695096299999997 * fTemp79)) + (0.014113905499999999 * fTemp80))));
			double fTemp333 = (fConst360 * fRec685[1]);
			double fTemp334 = (fConst361 * fRec688[1]);
			fRec690[0] = (fTemp332 + (fTemp333 + (fRec690[1] + fTemp334)));
			fRec688[0] = fRec690[0];
			double fRec689 = ((fTemp334 + fTemp333) + fTemp332);
			fRec687[0] = (fRec688[0] + fRec687[1]);
			fRec685[0] = fRec687[0];
			double fRec686 = fRec689;
			fVec8[(IOTA & 255)] = (((0.046329073999999998 * fTemp91) + ((0.072479118199999998 * fTemp90) + ((0.045998179799999997 * fTemp8) + ((0.062111877000000003 * fTemp89) + ((0.034679250600000003 * fTemp10) + ((0.014327389100000001 * fTemp86) + ((0.089580268199999993 * fTemp11) + ((0.072030708900000004 * fTemp85) + ((0.052950592800000001 * fTemp12) + (fRec629 + (fRec647 + (fRec662 + (fRec674 + (fRec683 + fRec686)))))))))))))) - (((0.044160932899999998 * fTemp9) + ((0.0531054901 * fTemp87) + (0.052759960199999997 * fTemp88))) + (0.021627959499999998 * fTemp7)));
			output9[i] = FAUSTFLOAT((0.89454976303317535 * (fRec0[0] * fVec8[((IOTA - iConst362) & 255)])));
			double fTemp335 = (fConst365 * ((((((0.018327054499999999 * fTemp50) + (0.012139914999999999 * fTemp57)) + (0.066416860899999999 * fTemp51)) + (0.067113834900000002 * fTemp53)) + (0.068885406800000007 * fTemp54)) - ((((0.0348895309 * fTemp52) + (0.068170035099999998 * fTemp56)) + (0.0065662079999999996 * fTemp58)) + (0.0438092515 * fTemp55))));
			double fTemp336 = (fConst366 * fRec700[1]);
			double fTemp337 = (fConst367 * fRec697[1]);
			fRec702[0] = (((fTemp335 + fRec702[1]) + fTemp336) + fTemp337);
			fRec700[0] = fRec702[0];
			double fRec701 = ((fTemp335 + fTemp336) + fTemp337);
			fRec699[0] = (fRec700[0] + fRec699[1]);
			fRec697[0] = fRec699[0];
			double fRec698 = fRec701;
			double fTemp338 = (fConst368 * fRec694[1]);
			double fTemp339 = (fConst369 * fRec691[1]);
			fRec696[0] = (((fRec698 + fRec696[1]) + fTemp338) + fTemp339);
			fRec694[0] = fRec696[0];
			double fRec695 = ((fRec698 + fTemp338) + fTemp339);
			fRec693[0] = (fRec694[0] + fRec693[1]);
			fRec691[0] = fRec693[0];
			double fRec692 = fRec695;
			double fTemp340 = (fConst371 * fRec703[1]);
			double fTemp341 = (fConst373 * (((((0.0960572274 * fTemp66) + (0.0118776444 * fTemp67)) + (0.015326655200000001 * fTemp68)) + (0.037730190599999998 * fTemp65)) - ((0.045927147699999997 * fTemp63) + (0.077203579899999999 * fTemp64))));
			double fTemp342 = (fConst374 * fRec706[1]);
			double fTemp343 = (fConst375 * fRec709[1]);
			fRec711[0] = (fTemp341 + (fTemp342 + (fRec711[1] + fTemp343)));
			fRec709[0] = fRec711[0];
			double fRec710 = ((fTemp343 + fTemp342) + fTemp341);
			fRec708[0] = (fRec709[0] + fRec708[1]);
			fRec706[0] = fRec708[0];
			double fRec707 = fRec710;
			fRec705[0] = (fTemp340 + (fRec707 + fRec705[1]));
			fRec703[0] = fRec705[0];
			double fRec704 = (fRec707 + fTemp340);
			double fTemp344 = (fConst377 * ((0.044252732699999998 * fTemp74) - ((0.075069058399999999 * fTemp72) + (0.081285497499999998 * fTemp73))));
			double fTemp345 = (fConst378 * fRec712[1]);
			fRec714[0] = (fTemp344 + (fRec714[1] + fTemp345));
			fRec712[0] = fRec714[0];
			double fRec713 = (fTemp345 + fTemp344);
			double fTemp346 = (fConst380 * (((0.074116400900000004 * fTemp77) + (0.0101723257 * fTemp78)) - (((0.062409753200000001 * fTemp79) + (0.0243978088 * fTemp80)) + (0.063064676900000005 * fTemp81))));
			double fTemp347 = (fConst381 * fRec715[1]);
			double fTemp348 = (fConst382 * fRec718[1]);
			fRec720[0] = (fTemp346 + (fTemp347 + (fRec720[1] + fTemp348)));
			fRec718[0] = fRec720[0];
			double fRec719 = ((fTemp348 + fTemp347) + fTemp346);
			fRec717[0] = (fRec718[0] + fRec717[1]);
			fRec715[0] = fRec717[0];
			double fRec716 = fRec719;
			double fTemp349 = (fConst384 * fRec721[1]);
			double fTemp350 = (fConst386 * fRec724[1]);
			double fTemp351 = (fConst387 * fRec727[1]);
			double fTemp352 = (fConst389 * (((((0.025983770699999999 * fTemp39) + (((0.0176633634 * fTemp36) + (0.0283147807 * fTemp38)) + (0.050228597799999997 * fTemp42))) + (0.022939037700000001 * fTemp43)) + (0.049444507300000003 * fTemp44)) - (((0.017019870699999998 * fTemp41) + (0.090668945500000001 * fTemp37)) + (0.097489540700000002 * fTemp40))));
			double fTemp353 = (fConst390 * fRec730[1]);
			double fTemp354 = (fConst391 * fRec733[1]);
			fRec735[0] = (fTemp352 + (fTemp353 + (fRec735[1] + fTemp354)));
			fRec733[0] = fRec735[0];
			double fRec734 = ((fTemp354 + fTemp353) + fTemp352);
			fRec732[0] = (fRec732[1] + fRec733[0]);
			fRec730[0] = fRec732[0];
			double fRec731 = fRec734;
			fRec729[0] = ((fTemp350 + (fRec729[1] + fTemp351)) + fRec731);
			fRec727[0] = fRec729[0];
			double fRec728 = ((fTemp351 + fTemp350) + fRec731);
			fRec726[0] = (fRec726[1] + fRec727[0]);
			fRec724[0] = fRec726[0];
			double fRec725 = fRec728;
			fRec723[0] = ((fRec723[1] + fTemp349) + fRec725);
			fRec721[0] = fRec723[0];
			double fRec722 = (fTemp349 + fRec725);
			double fTemp355 = (fConst393 * fRec736[1]);
			double fTemp356 = (fConst394 * fRec739[1]);
			double fTemp357 = (fConst396 * fRec742[1]);
			double fTemp358 = (fConst397 * fRec745[1]);
			double fTemp359 = (fConst399 * ((((((0.068592838099999998 * fTemp18) + (0.057549057399999999 * fTemp19)) + (0.045548263999999998 * fTemp26)) + (0.0053192363999999999 * fTemp21)) + (0.0693126466 * fTemp23)) - (((0.044711838099999998 * fTemp22) + ((((((0.034268332700000001 * fTemp17) + (0.0122941619 * fTemp24)) + (0.064317155599999995 * fTemp20)) + (0.050282749699999997 * fTemp25)) + (0.050810413499999998 * fTemp27)) + (0.058152973300000001 * fTemp28))) + (0.0314294382 * fTemp29))));
			double fTemp360 = (fConst400 * fRec748[1]);
			double fTemp361 = (fConst401 * fRec751[1]);
			fRec753[0] = (fTemp359 + (fTemp360 + (fRec753[1] + fTemp361)));
			fRec751[0] = fRec753[0];
			double fRec752 = ((fTemp361 + fTemp360) + fTemp359);
			fRec750[0] = (fRec750[1] + fRec751[0]);
			fRec748[0] = fRec750[0];
			double fRec749 = fRec752;
			fRec747[0] = ((fTemp357 + (fRec747[1] + fTemp358)) + fRec749);
			fRec745[0] = fRec747[0];
			double fRec746 = ((fTemp358 + fTemp357) + fRec749);
			fRec744[0] = (fRec744[1] + fRec745[0]);
			fRec742[0] = fRec744[0];
			double fRec743 = fRec746;
			fRec741[0] = ((fTemp355 + (fRec741[1] + fTemp356)) + fRec743);
			fRec739[0] = fRec741[0];
			double fRec740 = ((fTemp356 + fTemp355) + fRec743);
			fRec738[0] = (fRec738[1] + fRec739[0]);
			fRec736[0] = fRec738[0];
			double fRec737 = fRec740;
			fVec9[(IOTA & 255)] = (((0.0233630976 * fTemp7) + ((0.073408845599999994 * fTemp90) + ((0.058265229799999999 * fTemp87) + ((0.050537168899999999 * fTemp10) + ((0.044288782200000001 * fTemp86) + ((0.043312214799999998 * fTemp85) + ((((fRec692 + (fRec704 + (fRec713 + fRec716))) + fRec722) + fRec737) + (0.070212575900000004 * fTemp12)))))))) - (((0.055783855100000002 * fTemp8) + ((0.051649569899999997 * fTemp89) + ((0.04593506 * fTemp9) + ((0.098283904399999997 * fTemp11) + (0.053334090200000003 * fTemp88))))) + (0.0016210045000000001 * fTemp91)));
			output10[i] = FAUSTFLOAT((0.90343601895734593 * (fRec0[0] * fVec9[((IOTA - iConst402) & 255)])));
			double fTemp362 = (fConst356 * (((0.075079327200000004 * fTemp72) + (0.0441755432 * fTemp74)) - (0.080950870600000002 * fTemp73)));
			double fTemp363 = (fConst357 * fRec754[1]);
			fRec756[0] = (fTemp362 + (fRec756[1] + fTemp363));
			fRec754[0] = fRec756[0];
			double fRec755 = (fTemp363 + fTemp362);
			double fTemp364 = (fConst359 * (((0.062267084899999998 * fTemp79) + (0.010406858499999999 * fTemp78)) - (((0.073972949999999996 * fTemp77) + (0.024544420300000001 * fTemp80)) + (0.0631227169 * fTemp81))));
			double fTemp365 = (fConst360 * fRec757[1]);
			double fTemp366 = (fConst361 * fRec760[1]);
			fRec762[0] = (fTemp364 + (fTemp365 + (fRec762[1] + fTemp366)));
			fRec760[0] = fRec762[0];
			double fRec761 = ((fTemp366 + fTemp365) + fTemp364);
			fRec759[0] = (fRec759[1] + fRec760[0]);
			fRec757[0] = fRec759[0];
			double fRec758 = fRec761;
			double fTemp367 = (fConst350 * fRec763[1]);
			double fTemp368 = (fConst352 * ((((0.046140047199999999 * fTemp63) + (0.0150900333 * fTemp68)) + (0.037819828999999999 * fTemp65)) - (((0.096231483699999995 * fTemp66) + (0.0119618681 * fTemp67)) + (0.077116090999999998 * fTemp64))));
			double fTemp369 = (fConst353 * fRec766[1]);
			double fTemp370 = (fConst354 * fRec769[1]);
			fRec771[0] = (fTemp368 + (fTemp369 + (fRec771[1] + fTemp370)));
			fRec769[0] = fRec771[0];
			double fRec770 = ((fTemp370 + fTemp369) + fTemp368);
			fRec768[0] = (fRec768[1] + fRec769[0]);
			fRec766[0] = fRec768[0];
			double fRec767 = fRec770;
			fRec765[0] = ((fRec765[1] + fTemp367) + fRec767);
			fRec763[0] = fRec765[0];
			double fRec764 = (fTemp367 + fRec767);
			double fTemp371 = (fConst343 * fRec772[1]);
			double fTemp372 = (fConst344 * fRec775[1]);
			double fTemp373 = (fConst346 * ((((0.068014198900000003 * fTemp56) + (0.067175601500000001 * fTemp53)) + (0.0689488038 * fTemp54)) - ((((((0.0181585298 * fTemp50) + (0.0123413246 * fTemp57)) + (0.066265032400000007 * fTemp51)) + (0.034737536999999999 * fTemp52)) + (0.0067175982999999996 * fTemp58)) + (0.043812354300000002 * fTemp55))));
			double fTemp374 = (fConst347 * fRec778[1]);
			double fTemp375 = (fConst348 * fRec781[1]);
			fRec783[0] = (fTemp373 + (fTemp374 + (fRec783[1] + fTemp375)));
			fRec781[0] = fRec783[0];
			double fRec782 = ((fTemp375 + fTemp374) + fTemp373);
			fRec780[0] = (fRec780[1] + fRec781[0]);
			fRec778[0] = fRec780[0];
			double fRec779 = fRec782;
			fRec777[0] = ((fTemp371 + (fRec777[1] + fTemp372)) + fRec779);
			fRec775[0] = fRec777[0];
			double fRec776 = ((fTemp372 + fTemp371) + fRec779);
			fRec774[0] = (fRec774[1] + fRec775[0]);
			fRec772[0] = fRec774[0];
			double fRec773 = fRec776;
			double fTemp376 = (fConst334 * fRec784[1]);
			double fTemp377 = (fConst336 * fRec787[1]);
			double fTemp378 = (fConst337 * fRec790[1]);
			double fTemp379 = (fConst339 * (((((0.026205901699999999 * fTemp39) + (((0.0167706998 * fTemp41) + (0.090833426999999994 * fTemp37)) + (0.050143305800000003 * fTemp42))) + (0.0229238267 * fTemp43)) + (0.0491703005 * fTemp44)) - (((0.017777926400000001 * fTemp36) + (0.0281620029 * fTemp38)) + (0.097357358000000005 * fTemp40))));
			double fTemp380 = (fConst340 * fRec793[1]);
			double fTemp381 = (fConst341 * fRec796[1]);
			fRec798[0] = (fTemp379 + (fTemp380 + (fRec798[1] + fTemp381)));
			fRec796[0] = fRec798[0];
			double fRec797 = ((fTemp381 + fTemp380) + fTemp379);
			fRec795[0] = (fRec795[1] + fRec796[0]);
			fRec793[0] = fRec795[0];
			double fRec794 = fRec797;
			fRec792[0] = ((fTemp377 + (fRec792[1] + fTemp378)) + fRec794);
			fRec790[0] = fRec792[0];
			double fRec791 = ((fTemp378 + fTemp377) + fRec794);
			fRec789[0] = (fRec789[1] + fRec790[0]);
			fRec787[0] = fRec789[0];
			double fRec788 = fRec791;
			fRec786[0] = ((fRec786[1] + fTemp376) + fRec788);
			fRec784[0] = fRec786[0];
			double fRec785 = (fTemp376 + fRec788);
			double fTemp382 = (fConst324 * fRec799[1]);
			double fTemp383 = (fConst325 * fRec802[1]);
			double fTemp384 = (fConst327 * fRec805[1]);
			double fTemp385 = (fConst328 * fRec808[1]);
			double fTemp386 = (fConst330 * (((((0.045367753599999998 * fTemp26) + ((0.050167803699999999 * fTemp25) + (((0.033686776199999997 * fTemp17) + (0.0121811121 * fTemp24)) + (0.064579152400000006 * fTemp20)))) + (0.0054418766000000002 * fTemp21)) + (0.069376436900000005 * fTemp23)) - (((0.044609287099999999 * fTemp22) + ((((0.068436035300000003 * fTemp18) + (0.057417500699999999 * fTemp19)) + (0.050857175599999999 * fTemp27)) + (0.058206492999999998 * fTemp28))) + (0.031825901900000002 * fTemp29))));
			double fTemp387 = (fConst331 * fRec811[1]);
			double fTemp388 = (fConst332 * fRec814[1]);
			fRec816[0] = (fTemp386 + (fTemp387 + (fRec816[1] + fTemp388)));
			fRec814[0] = fRec816[0];
			double fRec815 = ((fTemp388 + fTemp387) + fTemp386);
			fRec813[0] = (fRec813[1] + fRec814[0]);
			fRec811[0] = fRec813[0];
			double fRec812 = fRec815;
			fRec810[0] = ((fTemp384 + (fRec810[1] + fTemp385)) + fRec812);
			fRec808[0] = fRec810[0];
			double fRec809 = ((fTemp385 + fTemp384) + fRec812);
			fRec807[0] = (fRec807[1] + fRec808[0]);
			fRec805[0] = fRec807[0];
			double fRec806 = fRec809;
			fRec804[0] = ((fTemp382 + (fRec804[1] + fTemp383)) + fRec806);
			fRec802[0] = fRec804[0];
			double fRec803 = ((fTemp383 + fTemp382) + fRec806);
			fRec801[0] = (fRec801[1] + fRec802[0]);
			fRec799[0] = fRec801[0];
			double fRec800 = fRec803;
			fVec10[(IOTA & 255)] = (((0.0236010452 * fTemp7) + ((0.073309313099999995 * fTemp90) + ((0.053136981600000001 * fTemp88) + (((0.070425193999999997 * fTemp12) + (((((fRec755 + fRec758) + fRec764) + fRec773) + fRec785) + fRec800)) + (0.098462200099999994 * fTemp11))))) - (((0.055805352599999997 * fTemp8) + ((0.051866364700000001 * fTemp89) + (((((0.044339643499999998 * fTemp85) + (0.044082642599999999 * fTemp86)) + (0.050248892099999998 * fTemp10)) + (0.058370928000000002 * fTemp87)) + (0.045889966999999997 * fTemp9)))) + (0.0019855687999999999 * fTemp91)));
			output11[i] = FAUSTFLOAT((0.89454976303317535 * (fRec0[0] * fVec10[((IOTA - iConst362) & 255)])));
			double fTemp389 = (fConst404 * ((0.12579722290000001 * fTemp74) - ((7.9593599999999996e-05 * fTemp72) + (0.0019703695000000002 * fTemp73))));
			double fTemp390 = (fConst405 * fRec817[1]);
			fRec819[0] = (fTemp389 + (fRec819[1] + fTemp390));
			fRec817[0] = fRec819[0];
			double fRec818 = (fTemp390 + fTemp389);
			double fTemp391 = (fConst407 * ((((0.1542508571 * fTemp80) + (0.00094205500000000002 * fTemp81)) + (0.0032535119 * fTemp78)) - ((0.00013484369999999999 * fTemp77) + (5.6883999999999996e-06 * fTemp79))));
			double fTemp392 = (fConst408 * fRec820[1]);
			double fTemp393 = (fConst409 * fRec823[1]);
			fRec825[0] = (fTemp391 + (fTemp392 + (fRec825[1] + fTemp393)));
			fRec823[0] = fRec825[0];
			double fRec824 = ((fTemp393 + fTemp392) + fTemp391);
			fRec822[0] = (fRec822[1] + fRec823[0]);
			fRec820[0] = fRec822[0];
			double fRec821 = fRec824;
			double fTemp394 = (fConst411 * fRec826[1]);
			double fTemp395 = (fConst413 * ((((4.5633600000000003e-05 * fTemp67) + (0.15041258699999999 * fTemp64)) + (0.0017212163999999999 * fTemp68)) - (((0.00017946539999999999 * fTemp63) + (3.8298000000000002e-06 * fTemp66)) + (0.0028618343999999999 * fTemp65))));
			double fTemp396 = (fConst414 * fRec829[1]);
			double fTemp397 = (fConst415 * fRec832[1]);
			fRec834[0] = (fTemp395 + (fTemp396 + (fRec834[1] + fTemp397)));
			fRec832[0] = fRec834[0];
			double fRec833 = ((fTemp397 + fTemp396) + fTemp395);
			fRec831[0] = (fRec831[1] + fRec832[0]);
			fRec829[0] = fRec831[0];
			double fRec830 = fRec833;
			fRec828[0] = ((fRec828[1] + fTemp394) + fRec830);
			fRec826[0] = fRec828[0];
			double fRec827 = (fTemp394 + fRec830);
			double fTemp398 = (fConst417 * fRec835[1]);
			double fTemp399 = (fConst418 * fRec838[1]);
			double fTemp400 = (fConst420 * (((((8.4649799999999997e-05 * fTemp57) + (6.0535999999999999e-06 * fTemp51)) + (0.13093161289999999 * fTemp52)) + (0.019129365799999999 * fTemp55)) - ((0.0010290046 * fTemp54) + ((0.0021001329000000001 * fTemp58) + (((0.0002155639 * fTemp50) + (6.2133999999999997e-06 * fTemp56)) + (0.001002541 * fTemp53))))));
			double fTemp401 = (fConst421 * fRec841[1]);
			double fTemp402 = (fConst422 * fRec844[1]);
			fRec846[0] = (fTemp400 + (fTemp401 + (fRec846[1] + fTemp402)));
			fRec844[0] = fRec846[0];
			double fRec845 = ((fTemp402 + fTemp401) + fTemp400);
			fRec843[0] = (fRec843[1] + fRec844[0]);
			fRec841[0] = fRec843[0];
			double fRec842 = fRec845;
			fRec840[0] = ((fTemp398 + (fRec840[1] + fTemp399)) + fRec842);
			fRec838[0] = fRec840[0];
			double fRec839 = ((fTemp399 + fTemp398) + fRec842);
			fRec837[0] = (fRec837[1] + fRec838[0]);
			fRec835[0] = fRec837[0];
			double fRec836 = fRec839;
			double fTemp403 = (fConst424 * fRec847[1]);
			double fTemp404 = (fConst426 * fRec850[1]);
			double fTemp405 = (fConst427 * fRec853[1]);
			double fTemp406 = (fConst429 * (((0.0049219722000000002 * fTemp44) + ((0.019758055300000001 * fTemp40) + ((((0.0001143851 * fTemp41) + (3.6148999999999999e-06 * fTemp37)) + (0.1245861035 * fTemp42)) + (0.0011774706999999999 * fTemp43)))) - (((0.00025233310000000002 * fTemp36) + (3.2639899999999999e-05 * fTemp38)) + (0.001929884 * fTemp39))));
			double fTemp407 = (fConst430 * fRec856[1]);
			double fTemp408 = (fConst431 * fRec859[1]);
			fRec861[0] = (fTemp406 + (fTemp407 + (fRec861[1] + fTemp408)));
			fRec859[0] = fRec861[0];
			double fRec860 = ((fTemp408 + fTemp407) + fTemp406);
			fRec858[0] = (fRec858[1] + fRec859[0]);
			fRec856[0] = fRec858[0];
			double fRec857 = fRec860;
			fRec855[0] = ((fTemp404 + (fRec855[1] + fTemp405)) + fRec857);
			fRec853[0] = fRec855[0];
			double fRec854 = ((fTemp405 + fTemp404) + fRec857);
			fRec852[0] = (fRec852[1] + fRec853[0]);
			fRec850[0] = fRec852[0];
			double fRec851 = fRec854;
			fRec849[0] = ((fRec849[1] + fTemp403) + fRec851);
			fRec847[0] = fRec849[0];
			double fRec848 = (fTemp403 + fRec851);
			double fTemp409 = (fConst433 * fRec862[1]);
			double fTemp410 = (fConst434 * fRec865[1]);
			double fTemp411 = (fConst436 * fRec868[1]);
			double fTemp412 = (fConst437 * fRec871[1]);
			double fTemp413 = (fConst439 * ((((0.0021853596999999998 * fTemp22) + ((0.00086868440000000002 * fTemp28) + ((0.0017013021000000001 * fTemp21) + ((0.00075900179999999998 * fTemp27) + ((((6.2519000000000002e-06 * fTemp18) + (0.00014460469999999999 * fTemp24)) + (5.2453000000000004e-06 * fTemp19)) + (0.13462236869999999 * fTemp26)))))) + (0.0011824795999999999 * fTemp29)) - ((((0.00027067669999999999 * fTemp17) + (6.6402000000000006e-05 * fTemp20)) + (4.583e-06 * fTemp25)) + (0.0010353866999999999 * fTemp23))));
			double fTemp414 = (fConst440 * fRec874[1]);
			double fTemp415 = (fConst441 * fRec877[1]);
			fRec879[0] = (fTemp413 + (fTemp414 + (fRec879[1] + fTemp415)));
			fRec877[0] = fRec879[0];
			double fRec878 = ((fTemp415 + fTemp414) + fTemp413);
			fRec876[0] = (fRec876[1] + fRec877[0]);
			fRec874[0] = fRec876[0];
			double fRec875 = fRec878;
			fRec873[0] = ((fTemp411 + (fRec873[1] + fTemp412)) + fRec875);
			fRec871[0] = fRec873[0];
			double fRec872 = ((fTemp412 + fTemp411) + fRec875);
			fRec870[0] = (fRec870[1] + fRec871[0]);
			fRec868[0] = fRec870[0];
			double fRec869 = fRec872;
			fRec867[0] = ((fTemp409 + (fRec867[1] + fTemp410)) + fRec869);
			fRec865[0] = fRec867[0];
			double fRec866 = ((fTemp410 + fTemp409) + fRec869);
			fRec864[0] = (fRec864[1] + fRec865[0]);
			fRec862[0] = fRec864[0];
			double fRec863 = fRec866;
			fVec11[(IOTA & 1023)] = (((0.0020880487000000001 * fTemp89) + ((0.14407544410000001 * fTemp9) + ((2.52142e-05 * fTemp88) + ((0.000175957 * fTemp86) + (((0.091455312400000002 * fTemp12) + (((((fRec818 + fRec821) + fRec827) + fRec836) + fRec848) + fRec863)) + (3.9184999999999998e-06 * fTemp11)))))) - ((0.0028722694999999999 * fTemp91) + ((0.0041812202000000003 * fTemp7) + ((0.014877657799999999 * fTemp90) + ((((0.00025229339999999998 * fTemp85) + (9.0645300000000004e-05 * fTemp10)) + (2.323e-06 * fTemp87)) + (0.0004156214 * fTemp8))))));
			output12[i] = FAUSTFLOAT((0.47393364928909959 * (fRec0[0] * fVec11[((IOTA - iConst442) & 1023)])));
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec27[2] = fRec27[1];
			fRec27[1] = fRec27[0];
			fRec28[2] = fRec28[1];
			fRec28[1] = fRec28[0];
			fRec29[2] = fRec29[1];
			fRec29[1] = fRec29[0];
			fRec30[2] = fRec30[1];
			fRec30[1] = fRec30[0];
			fRec31[2] = fRec31[1];
			fRec31[1] = fRec31[0];
			fRec32[2] = fRec32[1];
			fRec32[1] = fRec32[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fRec35[2] = fRec35[1];
			fRec35[1] = fRec35[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			fRec37[2] = fRec37[1];
			fRec37[1] = fRec37[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fRec39[2] = fRec39[1];
			fRec39[1] = fRec39[0];
			fRec26[1] = fRec26[0];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec18[1] = fRec18[0];
			fRec17[1] = fRec17[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			fRec9[1] = fRec9[0];
			fRec55[2] = fRec55[1];
			fRec55[1] = fRec55[0];
			fRec56[2] = fRec56[1];
			fRec56[1] = fRec56[0];
			fRec57[2] = fRec57[1];
			fRec57[1] = fRec57[0];
			fRec58[2] = fRec58[1];
			fRec58[1] = fRec58[0];
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
			fRec54[1] = fRec54[0];
			fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			fRec49[1] = fRec49[0];
			fRec48[1] = fRec48[0];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			fRec43[1] = fRec43[0];
			fRec42[1] = fRec42[0];
			fRec40[1] = fRec40[0];
			fRec76[2] = fRec76[1];
			fRec76[1] = fRec76[0];
			fRec77[2] = fRec77[1];
			fRec77[1] = fRec77[0];
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
			fRec83[2] = fRec83[1];
			fRec83[1] = fRec83[0];
			fRec84[2] = fRec84[1];
			fRec84[1] = fRec84[0];
			fRec75[1] = fRec75[0];
			fRec73[1] = fRec73[0];
			fRec72[1] = fRec72[0];
			fRec70[1] = fRec70[0];
			fRec69[1] = fRec69[0];
			fRec67[1] = fRec67[0];
			fRec66[1] = fRec66[0];
			fRec64[1] = fRec64[0];
			fRec94[2] = fRec94[1];
			fRec94[1] = fRec94[0];
			fRec95[2] = fRec95[1];
			fRec95[1] = fRec95[0];
			fRec96[2] = fRec96[1];
			fRec96[1] = fRec96[0];
			fRec97[2] = fRec97[1];
			fRec97[1] = fRec97[0];
			fRec98[2] = fRec98[1];
			fRec98[1] = fRec98[0];
			fRec99[2] = fRec99[1];
			fRec99[1] = fRec99[0];
			fRec93[1] = fRec93[0];
			fRec91[1] = fRec91[0];
			fRec90[1] = fRec90[0];
			fRec88[1] = fRec88[0];
			fRec87[1] = fRec87[0];
			fRec85[1] = fRec85[0];
			fRec103[2] = fRec103[1];
			fRec103[1] = fRec103[0];
			fRec104[2] = fRec104[1];
			fRec104[1] = fRec104[0];
			fRec105[2] = fRec105[1];
			fRec105[1] = fRec105[0];
			fRec102[1] = fRec102[0];
			fRec100[1] = fRec100[0];
			fRec112[2] = fRec112[1];
			fRec112[1] = fRec112[0];
			fRec113[2] = fRec113[1];
			fRec113[1] = fRec113[0];
			fRec114[2] = fRec114[1];
			fRec114[1] = fRec114[0];
			fRec115[2] = fRec115[1];
			fRec115[1] = fRec115[0];
			fRec116[2] = fRec116[1];
			fRec116[1] = fRec116[0];
			fRec111[1] = fRec111[0];
			fRec109[1] = fRec109[0];
			fRec108[1] = fRec108[0];
			fRec106[1] = fRec106[0];
			fRec117[2] = fRec117[1];
			fRec117[1] = fRec117[0];
			fRec118[2] = fRec118[1];
			fRec118[1] = fRec118[0];
			fRec119[2] = fRec119[1];
			fRec119[1] = fRec119[0];
			fRec120[2] = fRec120[1];
			fRec120[1] = fRec120[0];
			fRec121[2] = fRec121[1];
			fRec121[1] = fRec121[0];
			fRec122[2] = fRec122[1];
			fRec122[1] = fRec122[0];
			fRec123[2] = fRec123[1];
			fRec123[1] = fRec123[0];
			IOTA = (IOTA + 1);
			fRec141[1] = fRec141[0];
			fRec139[1] = fRec139[0];
			fRec138[1] = fRec138[0];
			fRec136[1] = fRec136[0];
			fRec135[1] = fRec135[0];
			fRec133[1] = fRec133[0];
			fRec132[1] = fRec132[0];
			fRec130[1] = fRec130[0];
			fRec129[1] = fRec129[0];
			fRec127[1] = fRec127[0];
			fRec126[1] = fRec126[0];
			fRec124[1] = fRec124[0];
			fRec156[1] = fRec156[0];
			fRec154[1] = fRec154[0];
			fRec153[1] = fRec153[0];
			fRec151[1] = fRec151[0];
			fRec150[1] = fRec150[0];
			fRec148[1] = fRec148[0];
			fRec147[1] = fRec147[0];
			fRec145[1] = fRec145[0];
			fRec144[1] = fRec144[0];
			fRec142[1] = fRec142[0];
			fRec168[1] = fRec168[0];
			fRec166[1] = fRec166[0];
			fRec165[1] = fRec165[0];
			fRec163[1] = fRec163[0];
			fRec162[1] = fRec162[0];
			fRec160[1] = fRec160[0];
			fRec159[1] = fRec159[0];
			fRec157[1] = fRec157[0];
			fRec177[1] = fRec177[0];
			fRec175[1] = fRec175[0];
			fRec174[1] = fRec174[0];
			fRec172[1] = fRec172[0];
			fRec171[1] = fRec171[0];
			fRec169[1] = fRec169[0];
			fRec180[1] = fRec180[0];
			fRec178[1] = fRec178[0];
			fRec186[1] = fRec186[0];
			fRec184[1] = fRec184[0];
			fRec183[1] = fRec183[0];
			fRec181[1] = fRec181[0];
			fRec204[1] = fRec204[0];
			fRec202[1] = fRec202[0];
			fRec201[1] = fRec201[0];
			fRec199[1] = fRec199[0];
			fRec198[1] = fRec198[0];
			fRec196[1] = fRec196[0];
			fRec195[1] = fRec195[0];
			fRec193[1] = fRec193[0];
			fRec192[1] = fRec192[0];
			fRec190[1] = fRec190[0];
			fRec189[1] = fRec189[0];
			fRec187[1] = fRec187[0];
			fRec219[1] = fRec219[0];
			fRec217[1] = fRec217[0];
			fRec216[1] = fRec216[0];
			fRec214[1] = fRec214[0];
			fRec213[1] = fRec213[0];
			fRec211[1] = fRec211[0];
			fRec210[1] = fRec210[0];
			fRec208[1] = fRec208[0];
			fRec207[1] = fRec207[0];
			fRec205[1] = fRec205[0];
			fRec231[1] = fRec231[0];
			fRec229[1] = fRec229[0];
			fRec228[1] = fRec228[0];
			fRec226[1] = fRec226[0];
			fRec225[1] = fRec225[0];
			fRec223[1] = fRec223[0];
			fRec222[1] = fRec222[0];
			fRec220[1] = fRec220[0];
			fRec240[1] = fRec240[0];
			fRec238[1] = fRec238[0];
			fRec237[1] = fRec237[0];
			fRec235[1] = fRec235[0];
			fRec234[1] = fRec234[0];
			fRec232[1] = fRec232[0];
			fRec243[1] = fRec243[0];
			fRec241[1] = fRec241[0];
			fRec249[1] = fRec249[0];
			fRec247[1] = fRec247[0];
			fRec246[1] = fRec246[0];
			fRec244[1] = fRec244[0];
			for (int j0 = 15; (j0 > 0); j0 = (j0 - 1)) {
				fVec2[j0] = fVec2[(j0 - 1)];
				
			}
			fRec267[1] = fRec267[0];
			fRec265[1] = fRec265[0];
			fRec264[1] = fRec264[0];
			fRec262[1] = fRec262[0];
			fRec261[1] = fRec261[0];
			fRec259[1] = fRec259[0];
			fRec258[1] = fRec258[0];
			fRec256[1] = fRec256[0];
			fRec255[1] = fRec255[0];
			fRec253[1] = fRec253[0];
			fRec252[1] = fRec252[0];
			fRec250[1] = fRec250[0];
			fRec282[1] = fRec282[0];
			fRec280[1] = fRec280[0];
			fRec279[1] = fRec279[0];
			fRec277[1] = fRec277[0];
			fRec276[1] = fRec276[0];
			fRec274[1] = fRec274[0];
			fRec273[1] = fRec273[0];
			fRec271[1] = fRec271[0];
			fRec270[1] = fRec270[0];
			fRec268[1] = fRec268[0];
			fRec294[1] = fRec294[0];
			fRec292[1] = fRec292[0];
			fRec291[1] = fRec291[0];
			fRec289[1] = fRec289[0];
			fRec288[1] = fRec288[0];
			fRec286[1] = fRec286[0];
			fRec285[1] = fRec285[0];
			fRec283[1] = fRec283[0];
			fRec303[1] = fRec303[0];
			fRec301[1] = fRec301[0];
			fRec300[1] = fRec300[0];
			fRec298[1] = fRec298[0];
			fRec297[1] = fRec297[0];
			fRec295[1] = fRec295[0];
			fRec306[1] = fRec306[0];
			fRec304[1] = fRec304[0];
			fRec312[1] = fRec312[0];
			fRec310[1] = fRec310[0];
			fRec309[1] = fRec309[0];
			fRec307[1] = fRec307[0];
			fRec330[1] = fRec330[0];
			fRec328[1] = fRec328[0];
			fRec327[1] = fRec327[0];
			fRec325[1] = fRec325[0];
			fRec324[1] = fRec324[0];
			fRec322[1] = fRec322[0];
			fRec321[1] = fRec321[0];
			fRec319[1] = fRec319[0];
			fRec318[1] = fRec318[0];
			fRec316[1] = fRec316[0];
			fRec315[1] = fRec315[0];
			fRec313[1] = fRec313[0];
			fRec345[1] = fRec345[0];
			fRec343[1] = fRec343[0];
			fRec342[1] = fRec342[0];
			fRec340[1] = fRec340[0];
			fRec339[1] = fRec339[0];
			fRec337[1] = fRec337[0];
			fRec336[1] = fRec336[0];
			fRec334[1] = fRec334[0];
			fRec333[1] = fRec333[0];
			fRec331[1] = fRec331[0];
			fRec357[1] = fRec357[0];
			fRec355[1] = fRec355[0];
			fRec354[1] = fRec354[0];
			fRec352[1] = fRec352[0];
			fRec351[1] = fRec351[0];
			fRec349[1] = fRec349[0];
			fRec348[1] = fRec348[0];
			fRec346[1] = fRec346[0];
			fRec366[1] = fRec366[0];
			fRec364[1] = fRec364[0];
			fRec363[1] = fRec363[0];
			fRec361[1] = fRec361[0];
			fRec360[1] = fRec360[0];
			fRec358[1] = fRec358[0];
			fRec369[1] = fRec369[0];
			fRec367[1] = fRec367[0];
			fRec375[1] = fRec375[0];
			fRec373[1] = fRec373[0];
			fRec372[1] = fRec372[0];
			fRec370[1] = fRec370[0];
			for (int j1 = 7; (j1 > 0); j1 = (j1 - 1)) {
				fVec4[j1] = fVec4[(j1 - 1)];
				
			}
			fRec393[1] = fRec393[0];
			fRec391[1] = fRec391[0];
			fRec390[1] = fRec390[0];
			fRec388[1] = fRec388[0];
			fRec387[1] = fRec387[0];
			fRec385[1] = fRec385[0];
			fRec384[1] = fRec384[0];
			fRec382[1] = fRec382[0];
			fRec381[1] = fRec381[0];
			fRec379[1] = fRec379[0];
			fRec378[1] = fRec378[0];
			fRec376[1] = fRec376[0];
			fRec408[1] = fRec408[0];
			fRec406[1] = fRec406[0];
			fRec405[1] = fRec405[0];
			fRec403[1] = fRec403[0];
			fRec402[1] = fRec402[0];
			fRec400[1] = fRec400[0];
			fRec399[1] = fRec399[0];
			fRec397[1] = fRec397[0];
			fRec396[1] = fRec396[0];
			fRec394[1] = fRec394[0];
			fRec420[1] = fRec420[0];
			fRec418[1] = fRec418[0];
			fRec417[1] = fRec417[0];
			fRec415[1] = fRec415[0];
			fRec414[1] = fRec414[0];
			fRec412[1] = fRec412[0];
			fRec411[1] = fRec411[0];
			fRec409[1] = fRec409[0];
			fRec429[1] = fRec429[0];
			fRec427[1] = fRec427[0];
			fRec426[1] = fRec426[0];
			fRec424[1] = fRec424[0];
			fRec423[1] = fRec423[0];
			fRec421[1] = fRec421[0];
			fRec432[1] = fRec432[0];
			fRec430[1] = fRec430[0];
			fRec438[1] = fRec438[0];
			fRec436[1] = fRec436[0];
			fRec435[1] = fRec435[0];
			fRec433[1] = fRec433[0];
			fRec456[1] = fRec456[0];
			fRec454[1] = fRec454[0];
			fRec453[1] = fRec453[0];
			fRec451[1] = fRec451[0];
			fRec450[1] = fRec450[0];
			fRec448[1] = fRec448[0];
			fRec447[1] = fRec447[0];
			fRec445[1] = fRec445[0];
			fRec444[1] = fRec444[0];
			fRec442[1] = fRec442[0];
			fRec441[1] = fRec441[0];
			fRec439[1] = fRec439[0];
			fRec471[1] = fRec471[0];
			fRec469[1] = fRec469[0];
			fRec468[1] = fRec468[0];
			fRec466[1] = fRec466[0];
			fRec465[1] = fRec465[0];
			fRec463[1] = fRec463[0];
			fRec462[1] = fRec462[0];
			fRec460[1] = fRec460[0];
			fRec459[1] = fRec459[0];
			fRec457[1] = fRec457[0];
			fRec483[1] = fRec483[0];
			fRec481[1] = fRec481[0];
			fRec480[1] = fRec480[0];
			fRec478[1] = fRec478[0];
			fRec477[1] = fRec477[0];
			fRec475[1] = fRec475[0];
			fRec474[1] = fRec474[0];
			fRec472[1] = fRec472[0];
			fRec492[1] = fRec492[0];
			fRec490[1] = fRec490[0];
			fRec489[1] = fRec489[0];
			fRec487[1] = fRec487[0];
			fRec486[1] = fRec486[0];
			fRec484[1] = fRec484[0];
			fRec495[1] = fRec495[0];
			fRec493[1] = fRec493[0];
			fRec501[1] = fRec501[0];
			fRec499[1] = fRec499[0];
			fRec498[1] = fRec498[0];
			fRec496[1] = fRec496[0];
			fRec519[1] = fRec519[0];
			fRec517[1] = fRec517[0];
			fRec516[1] = fRec516[0];
			fRec514[1] = fRec514[0];
			fRec513[1] = fRec513[0];
			fRec511[1] = fRec511[0];
			fRec510[1] = fRec510[0];
			fRec508[1] = fRec508[0];
			fRec507[1] = fRec507[0];
			fRec505[1] = fRec505[0];
			fRec504[1] = fRec504[0];
			fRec502[1] = fRec502[0];
			fRec534[1] = fRec534[0];
			fRec532[1] = fRec532[0];
			fRec531[1] = fRec531[0];
			fRec529[1] = fRec529[0];
			fRec528[1] = fRec528[0];
			fRec526[1] = fRec526[0];
			fRec525[1] = fRec525[0];
			fRec523[1] = fRec523[0];
			fRec522[1] = fRec522[0];
			fRec520[1] = fRec520[0];
			fRec546[1] = fRec546[0];
			fRec544[1] = fRec544[0];
			fRec543[1] = fRec543[0];
			fRec541[1] = fRec541[0];
			fRec540[1] = fRec540[0];
			fRec538[1] = fRec538[0];
			fRec537[1] = fRec537[0];
			fRec535[1] = fRec535[0];
			fRec555[1] = fRec555[0];
			fRec553[1] = fRec553[0];
			fRec552[1] = fRec552[0];
			fRec550[1] = fRec550[0];
			fRec549[1] = fRec549[0];
			fRec547[1] = fRec547[0];
			fRec558[1] = fRec558[0];
			fRec556[1] = fRec556[0];
			fRec564[1] = fRec564[0];
			fRec562[1] = fRec562[0];
			fRec561[1] = fRec561[0];
			fRec559[1] = fRec559[0];
			fRec582[1] = fRec582[0];
			fRec580[1] = fRec580[0];
			fRec579[1] = fRec579[0];
			fRec577[1] = fRec577[0];
			fRec576[1] = fRec576[0];
			fRec574[1] = fRec574[0];
			fRec573[1] = fRec573[0];
			fRec571[1] = fRec571[0];
			fRec570[1] = fRec570[0];
			fRec568[1] = fRec568[0];
			fRec567[1] = fRec567[0];
			fRec565[1] = fRec565[0];
			fRec597[1] = fRec597[0];
			fRec595[1] = fRec595[0];
			fRec594[1] = fRec594[0];
			fRec592[1] = fRec592[0];
			fRec591[1] = fRec591[0];
			fRec589[1] = fRec589[0];
			fRec588[1] = fRec588[0];
			fRec586[1] = fRec586[0];
			fRec585[1] = fRec585[0];
			fRec583[1] = fRec583[0];
			fRec609[1] = fRec609[0];
			fRec607[1] = fRec607[0];
			fRec606[1] = fRec606[0];
			fRec604[1] = fRec604[0];
			fRec603[1] = fRec603[0];
			fRec601[1] = fRec601[0];
			fRec600[1] = fRec600[0];
			fRec598[1] = fRec598[0];
			fRec618[1] = fRec618[0];
			fRec616[1] = fRec616[0];
			fRec615[1] = fRec615[0];
			fRec613[1] = fRec613[0];
			fRec612[1] = fRec612[0];
			fRec610[1] = fRec610[0];
			fRec621[1] = fRec621[0];
			fRec619[1] = fRec619[0];
			fRec627[1] = fRec627[0];
			fRec625[1] = fRec625[0];
			fRec624[1] = fRec624[0];
			fRec622[1] = fRec622[0];
			fRec645[1] = fRec645[0];
			fRec643[1] = fRec643[0];
			fRec642[1] = fRec642[0];
			fRec640[1] = fRec640[0];
			fRec639[1] = fRec639[0];
			fRec637[1] = fRec637[0];
			fRec636[1] = fRec636[0];
			fRec634[1] = fRec634[0];
			fRec633[1] = fRec633[0];
			fRec631[1] = fRec631[0];
			fRec630[1] = fRec630[0];
			fRec628[1] = fRec628[0];
			fRec660[1] = fRec660[0];
			fRec658[1] = fRec658[0];
			fRec657[1] = fRec657[0];
			fRec655[1] = fRec655[0];
			fRec654[1] = fRec654[0];
			fRec652[1] = fRec652[0];
			fRec651[1] = fRec651[0];
			fRec649[1] = fRec649[0];
			fRec648[1] = fRec648[0];
			fRec646[1] = fRec646[0];
			fRec672[1] = fRec672[0];
			fRec670[1] = fRec670[0];
			fRec669[1] = fRec669[0];
			fRec667[1] = fRec667[0];
			fRec666[1] = fRec666[0];
			fRec664[1] = fRec664[0];
			fRec663[1] = fRec663[0];
			fRec661[1] = fRec661[0];
			fRec681[1] = fRec681[0];
			fRec679[1] = fRec679[0];
			fRec678[1] = fRec678[0];
			fRec676[1] = fRec676[0];
			fRec675[1] = fRec675[0];
			fRec673[1] = fRec673[0];
			fRec684[1] = fRec684[0];
			fRec682[1] = fRec682[0];
			fRec690[1] = fRec690[0];
			fRec688[1] = fRec688[0];
			fRec687[1] = fRec687[0];
			fRec685[1] = fRec685[0];
			fRec702[1] = fRec702[0];
			fRec700[1] = fRec700[0];
			fRec699[1] = fRec699[0];
			fRec697[1] = fRec697[0];
			fRec696[1] = fRec696[0];
			fRec694[1] = fRec694[0];
			fRec693[1] = fRec693[0];
			fRec691[1] = fRec691[0];
			fRec711[1] = fRec711[0];
			fRec709[1] = fRec709[0];
			fRec708[1] = fRec708[0];
			fRec706[1] = fRec706[0];
			fRec705[1] = fRec705[0];
			fRec703[1] = fRec703[0];
			fRec714[1] = fRec714[0];
			fRec712[1] = fRec712[0];
			fRec720[1] = fRec720[0];
			fRec718[1] = fRec718[0];
			fRec717[1] = fRec717[0];
			fRec715[1] = fRec715[0];
			fRec735[1] = fRec735[0];
			fRec733[1] = fRec733[0];
			fRec732[1] = fRec732[0];
			fRec730[1] = fRec730[0];
			fRec729[1] = fRec729[0];
			fRec727[1] = fRec727[0];
			fRec726[1] = fRec726[0];
			fRec724[1] = fRec724[0];
			fRec723[1] = fRec723[0];
			fRec721[1] = fRec721[0];
			fRec753[1] = fRec753[0];
			fRec751[1] = fRec751[0];
			fRec750[1] = fRec750[0];
			fRec748[1] = fRec748[0];
			fRec747[1] = fRec747[0];
			fRec745[1] = fRec745[0];
			fRec744[1] = fRec744[0];
			fRec742[1] = fRec742[0];
			fRec741[1] = fRec741[0];
			fRec739[1] = fRec739[0];
			fRec738[1] = fRec738[0];
			fRec736[1] = fRec736[0];
			fRec756[1] = fRec756[0];
			fRec754[1] = fRec754[0];
			fRec762[1] = fRec762[0];
			fRec760[1] = fRec760[0];
			fRec759[1] = fRec759[0];
			fRec757[1] = fRec757[0];
			fRec771[1] = fRec771[0];
			fRec769[1] = fRec769[0];
			fRec768[1] = fRec768[0];
			fRec766[1] = fRec766[0];
			fRec765[1] = fRec765[0];
			fRec763[1] = fRec763[0];
			fRec783[1] = fRec783[0];
			fRec781[1] = fRec781[0];
			fRec780[1] = fRec780[0];
			fRec778[1] = fRec778[0];
			fRec777[1] = fRec777[0];
			fRec775[1] = fRec775[0];
			fRec774[1] = fRec774[0];
			fRec772[1] = fRec772[0];
			fRec798[1] = fRec798[0];
			fRec796[1] = fRec796[0];
			fRec795[1] = fRec795[0];
			fRec793[1] = fRec793[0];
			fRec792[1] = fRec792[0];
			fRec790[1] = fRec790[0];
			fRec789[1] = fRec789[0];
			fRec787[1] = fRec787[0];
			fRec786[1] = fRec786[0];
			fRec784[1] = fRec784[0];
			fRec816[1] = fRec816[0];
			fRec814[1] = fRec814[0];
			fRec813[1] = fRec813[0];
			fRec811[1] = fRec811[0];
			fRec810[1] = fRec810[0];
			fRec808[1] = fRec808[0];
			fRec807[1] = fRec807[0];
			fRec805[1] = fRec805[0];
			fRec804[1] = fRec804[0];
			fRec802[1] = fRec802[0];
			fRec801[1] = fRec801[0];
			fRec799[1] = fRec799[0];
			fRec819[1] = fRec819[0];
			fRec817[1] = fRec817[0];
			fRec825[1] = fRec825[0];
			fRec823[1] = fRec823[0];
			fRec822[1] = fRec822[0];
			fRec820[1] = fRec820[0];
			fRec834[1] = fRec834[0];
			fRec832[1] = fRec832[0];
			fRec831[1] = fRec831[0];
			fRec829[1] = fRec829[0];
			fRec828[1] = fRec828[0];
			fRec826[1] = fRec826[0];
			fRec846[1] = fRec846[0];
			fRec844[1] = fRec844[0];
			fRec843[1] = fRec843[0];
			fRec841[1] = fRec841[0];
			fRec840[1] = fRec840[0];
			fRec838[1] = fRec838[0];
			fRec837[1] = fRec837[0];
			fRec835[1] = fRec835[0];
			fRec861[1] = fRec861[0];
			fRec859[1] = fRec859[0];
			fRec858[1] = fRec858[0];
			fRec856[1] = fRec856[0];
			fRec855[1] = fRec855[0];
			fRec853[1] = fRec853[0];
			fRec852[1] = fRec852[0];
			fRec850[1] = fRec850[0];
			fRec849[1] = fRec849[0];
			fRec847[1] = fRec847[0];
			fRec879[1] = fRec879[0];
			fRec877[1] = fRec877[0];
			fRec876[1] = fRec876[0];
			fRec874[1] = fRec874[0];
			fRec873[1] = fRec873[0];
			fRec871[1] = fRec871[0];
			fRec870[1] = fRec870[0];
			fRec868[1] = fRec868[0];
			fRec867[1] = fRec867[0];
			fRec865[1] = fRec865[0];
			fRec864[1] = fRec864[0];
			fRec862[1] = fRec862[0];
			
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
