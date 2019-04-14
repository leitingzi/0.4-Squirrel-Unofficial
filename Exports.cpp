#include "Exports.h"
#include "CCore.h"

// God have mercy on our souls
#define SQAPI(sz) sq->sz = sq_ ## sz
#define SQSTDAPI(sz) sqstd->sz = sqstd_ ## sz

extern HSQAPI sq;
extern HSQUIRRELVM v;
extern HSQSTDAPI sqstd;

void InitSQAPI()
{
	if (sq == NULL)
		sq = new sq_api();

	// VM management
	SQAPI(open);
	SQAPI(newthread);
	SQAPI(seterrorhandler);
	SQAPI(close);
	SQAPI(setforeignptr);
	SQAPI(getforeignptr);
	SQAPI(setsharedforeignptr);
	SQAPI(getsharedforeignptr);
	SQAPI(setvmreleasehook);
	SQAPI(getvmreleasehook);
	SQAPI(setsharedreleasehook);
	SQAPI(getsharedreleasehook);
	SQAPI(setprintfunc);
	SQAPI(getprintfunc);
	SQAPI(geterrorfunc);
	SQAPI(suspendvm);
	SQAPI(wakeupvm);
	SQAPI(getvmstate);
	SQAPI(getversion);

	// Compiler
	SQAPI(compile);
	SQAPI(compilebuffer);
	SQAPI(enabledebuginfo);
	SQAPI(notifyallexceptions);
	SQAPI(setcompilererrorhandler);

	// Stack operations
	SQAPI(push);
	SQAPI(pop);
	SQAPI(poptop);
	SQAPI(remove);
	SQAPI(gettop);
	SQAPI(settop);
	SQAPI(reservestack);
	SQAPI(cmp);
	SQAPI(move);

	// Object creation handling
	SQAPI(newuserdata);
	SQAPI(newtable);
	SQAPI(newtableex);
	SQAPI(newarray);
	SQAPI(newclosure);
	SQAPI(setparamscheck);
	SQAPI(bindenv);
	SQAPI(setclosureroot);
	SQAPI(getclosureroot);

	SQAPI(pushstring);
	SQAPI(pushfloat);
	SQAPI(pushinteger);
	SQAPI(pushbool);
	SQAPI(pushuserpointer);
	SQAPI(pushnull);
	SQAPI(pushthread);

	SQAPI(gettype);
	SQAPI(typeof);
	SQAPI(getsize);
	SQAPI(gethash);
	SQAPI(getbase);
	SQAPI(instanceof);

	SQAPI(tostring);
	SQAPI(tobool);
	SQAPI(getstring);
	SQAPI(getinteger);
	SQAPI(getfloat);
	SQAPI(getbool);
	SQAPI(getthread);
	SQAPI(getuserpointer);
	SQAPI(getuserdata);
	SQAPI(settypetag);
	SQAPI(gettypetag);

	SQAPI(setreleasehook);
	SQAPI(getreleasehook);
	SQAPI(getscratchpad);
	SQAPI(getfunctioninfo);
	SQAPI(getclosureinfo);
	SQAPI(getclosurename);
	SQAPI(setnativeclosurename);
	SQAPI(setinstanceup);
	SQAPI(getinstanceup);
	SQAPI(setclassudsize);
	SQAPI(newclass);
	SQAPI(createinstance);
	SQAPI(setattributes);
	SQAPI(getattributes);
	SQAPI(getclass);
	SQAPI(weakref);
	SQAPI(getdefaultdelegate);
	SQAPI(getmemberhandle);
	SQAPI(getbyhandle);
	SQAPI(setbyhandle);

	// Object manipulation
	SQAPI(pushroottable);
	SQAPI(pushregistrytable);
	SQAPI(pushconsttable);
	SQAPI(setroottable);
	SQAPI(setconsttable);
	SQAPI(newslot);
	SQAPI(deleteslot);
	SQAPI(set);
	SQAPI(get);
	SQAPI(rawget);
	SQAPI(rawset);
	SQAPI(rawdeleteslot);
	SQAPI(newmember);
	SQAPI(rawnewmember);

	SQAPI(arrayappend);
	SQAPI(arraypop);
	SQAPI(arrayresize);
	SQAPI(arrayreverse);
	SQAPI(arrayremove);
	SQAPI(arrayinsert);

	SQAPI(setdelegate);
	SQAPI(getdelegate);
	SQAPI(clone);
	SQAPI(setfreevariable);
	SQAPI(next);
	SQAPI(getweakrefval);
	SQAPI(clear);

	// Calls
	SQAPI(call);
	SQAPI(resume);
	SQAPI(getlocal);
	SQAPI(getcallee);
	SQAPI(getfreevariable);
	SQAPI(throwerror);
	SQAPI(throwobject);
	SQAPI(reseterror);
	SQAPI(getlasterror);

	// Raw object handling
	SQAPI(getstackobj);
	SQAPI(pushobject);
	SQAPI(addref);
	SQAPI(release);
	SQAPI(getrefcount);
	SQAPI(resetobject);
	SQAPI(objtostring);
	SQAPI(objtobool);
	SQAPI(objtointeger);
	SQAPI(objtofloat);
	SQAPI(objtouserpointer);
	SQAPI(getobjtypetag);
	SQAPI(getvmrefcount);

	// Garbage collection
	SQAPI(collectgarbage);
	SQAPI(resurrectunreachable);

	// Serialization
	SQAPI(writeclosure);
	SQAPI(readclosure);

	// Memory allocation
	SQAPI(malloc);
	SQAPI(realloc);
	SQAPI(free);

	// Debugging
	SQAPI(stackinfos);
	SQAPI(setdebughook);
	SQAPI(setnativedebughook);
}

void InitSQSTDAPI()
{
	if (sqstd == NULL)
		sqstd = new sqstd_api();

	// sqstdaux
	SQSTDAPI(seterrorhandlers);
	SQSTDAPI(printcallstack);

	// sqstdblob
	SQSTDAPI(createblob);
	SQSTDAPI(getblob);
	SQSTDAPI(getblobsize);

	// sqstdio
	SQSTDAPI(fopen);
	SQSTDAPI(fread);
	SQSTDAPI(fwrite);
	SQSTDAPI(fseek);
	SQSTDAPI(ftell);
	SQSTDAPI(fflush);
	SQSTDAPI(fclose);
	SQSTDAPI(feof);

	SQSTDAPI(createfile);
	SQSTDAPI(getfile);

	// compiler helpers
	SQSTDAPI(loadfile);
	SQSTDAPI(dofile);
	SQSTDAPI(writeclosuretofile);

	// sqstdstring
	SQSTDAPI(rex_compile);
	SQSTDAPI(rex_free);
	SQSTDAPI(rex_match);
	SQSTDAPI(rex_search);
	SQSTDAPI(rex_searchrange);
	SQSTDAPI(rex_getsubexpcount);
	SQSTDAPI(rex_getsubexp);

	SQSTDAPI(format);
}

HSQAPI * pfGetSquirrelAPI()
{
	// Just return whatever we have
	return &sq;
}

HSQUIRRELVM * pfGetSquirrelVM()
{
	// Same as pfGetSquirrelAPI, just a different variable
	return &v;
}

HSQSTDAPI * pfGetSquirrelStdAPI()
{
	// Same as pfGetSquirrelAPI, just a different variable
	return &sqstd;
}
