function CodeDefine() { 
this.def = new Array();
this.def["IsrOverrun"] = {file: "ert_main_c.html",line:31,type:"var"};
this.def["OverrunFlag"] = {file: "ert_main_c.html",line:32,type:"var"};
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:33,type:"fcn"};
this.def["stopRequested"] = {file: "ert_main_c.html",line:50,type:"var"};
this.def["main"] = {file: "ert_main_c.html",line:51,type:"fcn"};
this.def["stellaris_lp_debug_print_step"] = {file: "stellaris_lp_debug_print_c.html",line:32,type:"fcn"};
this.def["stellaris_lp_debug_print_initialize"] = {file: "stellaris_lp_debug_print_c.html",line:92,type:"fcn"};
this.def["stellaris_lp_debug_print_terminate"] = {file: "stellaris_lp_debug_print_c.html",line:105,type:"fcn"};
this.def["P_stellaris_lp_debug_print"] = {file: "stellaris_lp_debug_print_types_h.html",line:33,type:"type"};
this.def["stellaris_lp_debug_print_P"] = {file: "stellaris_lp_debug_print_data_c.html",line:32,type:"var"};
this.def["int8_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:46,type:"type"};
this.def["uint8_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:47,type:"type"};
this.def["int16_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:48,type:"type"};
this.def["uint16_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:49,type:"type"};
this.def["int32_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:50,type:"type"};
this.def["uint32_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:51,type:"type"};
this.def["real32_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:52,type:"type"};
this.def["real64_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:53,type:"type"};
this.def["real_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:59,type:"type"};
this.def["time_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:60,type:"type"};
this.def["boolean_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:61,type:"type"};
this.def["int_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:62,type:"type"};
this.def["uint_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:63,type:"type"};
this.def["ulong_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:64,type:"type"};
this.def["char_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:65,type:"type"};
this.def["uchar_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:66,type:"type"};
this.def["byte_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:67,type:"type"};
this.def["creal32_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:77,type:"type"};
this.def["creal64_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:82,type:"type"};
this.def["creal_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:87,type:"type"};
this.def["cint8_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:94,type:"type"};
this.def["cuint8_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:101,type:"type"};
this.def["cint16_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:108,type:"type"};
this.def["cuint16_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:115,type:"type"};
this.def["cint32_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:122,type:"type"};
this.def["cuint32_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:129,type:"type"};
this.def["pointer_T"] = {file: "../../slprj/ert/_sharedutils/html/rtwtypes_h.html",line:147,type:"type"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["stellaris_lp_debug_print_c.html"] = "../stellaris_lp_debug_print.c";
	this.html2Root["stellaris_lp_debug_print_c.html"] = "stellaris_lp_debug_print_c.html";
	this.html2SrcPath["stellaris_lp_debug_print_h.html"] = "../stellaris_lp_debug_print.h";
	this.html2Root["stellaris_lp_debug_print_h.html"] = "stellaris_lp_debug_print_h.html";
	this.html2SrcPath["stellaris_lp_debug_print_private_h.html"] = "../stellaris_lp_debug_print_private.h";
	this.html2Root["stellaris_lp_debug_print_private_h.html"] = "stellaris_lp_debug_print_private_h.html";
	this.html2SrcPath["stellaris_lp_debug_print_types_h.html"] = "../stellaris_lp_debug_print_types.h";
	this.html2Root["stellaris_lp_debug_print_types_h.html"] = "stellaris_lp_debug_print_types_h.html";
	this.html2SrcPath["stellaris_lp_debug_print_data_c.html"] = "../stellaris_lp_debug_print_data.c";
	this.html2Root["stellaris_lp_debug_print_data_c.html"] = "stellaris_lp_debug_print_data_c.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "../../slprj/ert/_sharedutils/html/rtwtypes_h.html";
	this.html2SrcPath["rtmodel_h.html"] = "../rtmodel.h";
	this.html2Root["rtmodel_h.html"] = "rtmodel_h.html";
	this.html2SrcPath["MW_target_hardware_resources_h.html"] = "../MW_target_hardware_resources.h";
	this.html2Root["MW_target_hardware_resources_h.html"] = "MW_target_hardware_resources_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_c.html","stellaris_lp_debug_print_c.html","stellaris_lp_debug_print_h.html","stellaris_lp_debug_print_private_h.html","stellaris_lp_debug_print_types_h.html","stellaris_lp_debug_print_data_c.html","rtwtypes_h.html","rtmodel_h.html","MW_target_hardware_resources_h.html"];
