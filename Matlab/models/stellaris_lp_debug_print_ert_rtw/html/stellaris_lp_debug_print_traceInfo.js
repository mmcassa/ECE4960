function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "stellaris_lp_debug_print"};
	this.sidHashMap["stellaris_lp_debug_print"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/BLUE LED"] = {sid: "stellaris_lp_debug_print:65"};
	this.sidHashMap["stellaris_lp_debug_print:65"] = {rtwname: "<Root>/BLUE LED"};
	this.rtwnameHashMap["<Root>/Bitwise Operator1"] = {sid: "stellaris_lp_debug_print:53"};
	this.sidHashMap["stellaris_lp_debug_print:53"] = {rtwname: "<Root>/Bitwise Operator1"};
	this.rtwnameHashMap["<Root>/Bitwise Operator2"] = {sid: "stellaris_lp_debug_print:54"};
	this.sidHashMap["stellaris_lp_debug_print:54"] = {rtwname: "<Root>/Bitwise Operator2"};
	this.rtwnameHashMap["<Root>/Bitwise Operator"] = {sid: "stellaris_lp_debug_print:66"};
	this.sidHashMap["stellaris_lp_debug_print:66"] = {rtwname: "<Root>/Bitwise Operator"};
	this.rtwnameHashMap["<Root>/Bitwise Operator3"] = {sid: "stellaris_lp_debug_print:71"};
	this.sidHashMap["stellaris_lp_debug_print:71"] = {rtwname: "<Root>/Bitwise Operator3"};
	this.rtwnameHashMap["<Root>/Buttons Read"] = {sid: "stellaris_lp_debug_print:52"};
	this.sidHashMap["stellaris_lp_debug_print:52"] = {rtwname: "<Root>/Buttons Read"};
	this.rtwnameHashMap["<Root>/Data Type Conversion1"] = {sid: "stellaris_lp_debug_print:55"};
	this.sidHashMap["stellaris_lp_debug_print:55"] = {rtwname: "<Root>/Data Type Conversion1"};
	this.rtwnameHashMap["<Root>/Data Type Conversion2"] = {sid: "stellaris_lp_debug_print:56"};
	this.sidHashMap["stellaris_lp_debug_print:56"] = {rtwname: "<Root>/Data Type Conversion2"};
	this.rtwnameHashMap["<Root>/Data Type Conversion3"] = {sid: "stellaris_lp_debug_print:57"};
	this.sidHashMap["stellaris_lp_debug_print:57"] = {rtwname: "<Root>/Data Type Conversion3"};
	this.rtwnameHashMap["<Root>/Data Type Conversion4"] = {sid: "stellaris_lp_debug_print:63"};
	this.sidHashMap["stellaris_lp_debug_print:63"] = {rtwname: "<Root>/Data Type Conversion4"};
	this.rtwnameHashMap["<Root>/Debug Print"] = {sid: "stellaris_lp_debug_print:51"};
	this.sidHashMap["stellaris_lp_debug_print:51"] = {rtwname: "<Root>/Debug Print"};
	this.rtwnameHashMap["<Root>/GPIO Setup"] = {sid: "stellaris_lp_debug_print:38"};
	this.sidHashMap["stellaris_lp_debug_print:38"] = {rtwname: "<Root>/GPIO Setup"};
	this.rtwnameHashMap["<Root>/GPIO Write"] = {sid: "stellaris_lp_debug_print:68"};
	this.sidHashMap["stellaris_lp_debug_print:68"] = {rtwname: "<Root>/GPIO Write"};
	this.rtwnameHashMap["<Root>/GREEN LED"] = {sid: "stellaris_lp_debug_print:69"};
	this.sidHashMap["stellaris_lp_debug_print:69"] = {rtwname: "<Root>/GREEN LED"};
	this.rtwnameHashMap["<Root>/Gain"] = {sid: "stellaris_lp_debug_print:61"};
	this.sidHashMap["stellaris_lp_debug_print:61"] = {rtwname: "<Root>/Gain"};
	this.rtwnameHashMap["<Root>/Gain1"] = {sid: "stellaris_lp_debug_print:72"};
	this.sidHashMap["stellaris_lp_debug_print:72"] = {rtwname: "<Root>/Gain1"};
	this.rtwnameHashMap["<Root>/Gain2"] = {sid: "stellaris_lp_debug_print:73"};
	this.sidHashMap["stellaris_lp_debug_print:73"] = {rtwname: "<Root>/Gain2"};
	this.rtwnameHashMap["<Root>/Gain3"] = {sid: "stellaris_lp_debug_print:76"};
	this.sidHashMap["stellaris_lp_debug_print:76"] = {rtwname: "<Root>/Gain3"};
	this.rtwnameHashMap["<Root>/Ground"] = {sid: "stellaris_lp_debug_print:62"};
	this.sidHashMap["stellaris_lp_debug_print:62"] = {rtwname: "<Root>/Ground"};
	this.rtwnameHashMap["<Root>/Logical Operator"] = {sid: "stellaris_lp_debug_print:75"};
	this.sidHashMap["stellaris_lp_debug_print:75"] = {rtwname: "<Root>/Logical Operator"};
	this.rtwnameHashMap["<Root>/RED LED"] = {sid: "stellaris_lp_debug_print:70"};
	this.sidHashMap["stellaris_lp_debug_print:70"] = {rtwname: "<Root>/RED LED"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
