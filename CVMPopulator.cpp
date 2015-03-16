/*
   Project: Squirrel Plugin for Vice City Multiplayer (0.4)
   File: CVMPopulator.cpp

   Copyright (c) 2015 Nelson Gomez (Stormeus)

   Licensed under the MIT License. A copy of the License is available in
   LICENSE or at:

       http://opensource.org/licenses/MIT

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
   THE SOFTWARE.
*/

#include "CVMPopulator.h"
#include <sqrat.h>

#include "classes/CObject.h"
#include "classes/CPickup.h"
#include "classes/CPlayer.h"

#include "functions/CCompatFunctions.h"
#include "functions/CEntityFunctions.h"
#include "functions/CMiscFunctions.h"
#include "functions/CRuleFunctions.h"
#include "functions/CServerFunctions.h"
#include "functions/CWorldFunctions.h"

#include "structures/CARGB.h"
#include "structures/CBounds.h"
#include "structures/CQuaternion.h"
#include "structures/CRGB.h"
#include "structures/CRGBA.h"
#include "structures/CVector.h"
#include "structures/CWastedSettings.h"

void CVMPopulator::Populate(HSQUIRRELVM v) {
	RegisterFunctions(v);
	RegisterClasses(v);
	RegisterStructures(v);
	RegisterConstants(v);
}

void CVMPopulator::RegisterFunctions(HSQUIRRELVM v) {
	CCompatFunctions::Register(v);
	CEntityFunctions::Register(v);
	CMiscFunctions::Register(v);
	CRuleFunctions::Register(v);
	CServerFunctions::Register(v);
	CWorldFunctions::Register(v);
}

void CVMPopulator::RegisterStructures(HSQUIRRELVM v) {
	CARGB::Register(v);
	CBounds::Register(v);
	CQuaternion::Register(v);
	CRGB::Register(v);
	CRGBA::Register(v);
	CVector::Register(v);
	// TODO: CWorldSettings::Register(v);
}

void CVMPopulator::RegisterClasses(HSQUIRRELVM v) {
	// TODO: Register other classes here as they're implemented
	CObject::Register(v);
	CPickup::Register(v);
	CPlayer::Register(v);
}

void CVMPopulator::RegisterConstants(HSQUIRRELVM v) {
	Sqrat::ConstTable(v)
		.Const(_SC("WEP_FIST"), 0)
		.Const(_SC("WEP_BRASSKNUCKLES"), 1)
		.Const(_SC("WEP_SCREWDRIVER"), 2)
		.Const(_SC("WEP_GOLFCLUB"), 3)
		.Const(_SC("WEP_NIGHTSTICK"), 4)
		.Const(_SC("WEP_KNIFE"), 5)
		.Const(_SC("WEP_BASEBALLBAT"), 6)
		.Const(_SC("WEP_HAMMER"), 7)
		.Const(_SC("WEP_MEATCLEAVER"), 8)
		.Const(_SC("WEP_MACHETE"), 9)
		.Const(_SC("WEP_KATANA"), 10)
		.Const(_SC("WEP_CHAINSAW"), 11)
		.Const(_SC("WEP_GRENADE"), 12)
		.Const(_SC("WEP_REMOTE"), 13)
		.Const(_SC("WEP_TEARGAS"), 14)
		.Const(_SC("WEP_MOLOTOV"), 15)
		.Const(_SC("WEP_ROCKET"), 16)
		.Const(_SC("WEP_COLT"), 17)
		.Const(_SC("WEP_COLT45"), 17)
		.Const(_SC("WEP_PYTHON"), 18)
		.Const(_SC("WEP_SHOTGUN"), 19)
		.Const(_SC("WEP_SPAZ"), 20)
		.Const(_SC("WEP_SPAS12"), 20)
		.Const(_SC("WEP_STUBBY"), 21)
		.Const(_SC("WEP_TEC9"), 22)
		.Const(_SC("WEP_UZI"), 23)
		.Const(_SC("WEP_INGRAM"), 24)
		.Const(_SC("WEP_MP5"), 25)
		.Const(_SC("WEP_M4"), 26)
		.Const(_SC("WEP_RUGER"), 27)
		.Const(_SC("WEP_SNIPER"), 28)
		.Const(_SC("WEP_LASERSCOPE"), 29)
		.Const(_SC("WEP_ROCKETLAUNCHER"), 30)
		.Const(_SC("WEP_RPG"), 30)
		.Const(_SC("WEP_FLAMETHROWER"), 31)
		.Const(_SC("WEP_M60"), 32)
		.Const(_SC("WEP_MINIGUN"), 33)

		.Const(_SC("WEP_BOMB"), 34)
		.Const(_SC("WEP_HELICANNON"), 35)
		.Const(_SC("WEP_CAMERA"), 36)
		.Const(_SC("WEP_VEHICLE"), 39)
		.Const(_SC("WEP_DRIVEBY"), 42)
		.Const(_SC("WEP_DROWNED"), 43)
		.Const(_SC("WEP_FALL"), 44)
		.Const(_SC("WEP_EXPLOSION"), 51)
		.Const(_SC("WEP_SUICIDE"), 70)

		.Const(_SC("WEATHER_MOSTLYCLEAR"), 0)
		.Const(_SC("WEATHER_OVERCAST"), 1)
		.Const(_SC("WEATHER_THUNDERSTORM"), 2)
		.Const(_SC("WEATHER_STORM"), 2)
		.Const(_SC("WEATHER_STORMY"), 2)
		.Const(_SC("WEATHER_FOGGY"), 3)
		.Const(_SC("WEATHER_FOG"), 3)
		.Const(_SC("WEATHER_CLEAR"), 4)
		.Const(_SC("WEATHER_SUNNY"), 4)
		.Const(_SC("WEATHER_RAIN"), 5)
		.Const(_SC("WEATHER_RAINY"), 5)
		.Const(_SC("WEATHER_DARKCLOUDY"), 6)
		.Const(_SC("WEATHER_LIGHTCLOUDY"), 7)
		.Const(_SC("WEATHER_OVERCASTCLOUDY"), 8)
		.Const(_SC("WEATHER_BLACKCLOUDS"), 9)

		.Const(_SC("VEH_LANDSTALKER"), 130)
		.Const(_SC("VEH_IDAHO"), 131)
		.Const(_SC("VEH_STINGER"), 132)
		.Const(_SC("VEH_LINERUNNER"), 133)
		.Const(_SC("VEH_PERENNIAL"), 134)
		.Const(_SC("VEH_SENTINEL"), 135)
		.Const(_SC("VEH_RIO"), 136)
		.Const(_SC("VEH_FIRETRUCK"), 137)
		.Const(_SC("VEH_TRASHMASTER"), 138)
		.Const(_SC("VEH_STRETCH"), 139)
		.Const(_SC("VEH_MANANA"), 140)
		.Const(_SC("VEH_INFERNUS"), 141)
		.Const(_SC("VEH_VOODOO"), 142)
		.Const(_SC("VEH_PONY"), 143)
		.Const(_SC("VEH_MULE"), 144)
		.Const(_SC("VEH_CHEETAH"), 145)
		.Const(_SC("VEH_AMBULANCE"), 146)
		.Const(_SC("VEH_FBIWASHINGTON"), 147)
		.Const(_SC("VEH_MOONBEAM"), 148)
		.Const(_SC("VEH_ESPERANTO"), 149)
		.Const(_SC("VEH_TAXI"), 150)
		.Const(_SC("VEH_WASHINGTON"), 151)
		.Const(_SC("VEH_BOBCAT"), 152)
		.Const(_SC("VEH_MRWHOOPEE"), 153)
		.Const(_SC("VEH_BFINJECTION"), 154)
		.Const(_SC("VEH_HUNTER"), 155)
		.Const(_SC("VEH_POLICE"), 156)
		.Const(_SC("VEH_ENFORCER"), 157)
		.Const(_SC("VEH_SECURICAR"), 158)
		.Const(_SC("VEH_BANSHEE"), 159)
		.Const(_SC("VEH_PREDATOR"), 160)
		.Const(_SC("VEH_BUS"), 161)
		.Const(_SC("VEH_RHINO"), 162)
		.Const(_SC("VEH_BARRACKSOL"), 163)
		.Const(_SC("VEH_BARRACKS"), 163)
		.Const(_SC("VEH_CUBANHERMES"), 164)
		.Const(_SC("VEH_HELICOPTER"), 165)
		.Const(_SC("VEH_ANGEL"), 166)
		.Const(_SC("VEH_COACH"), 167)
		.Const(_SC("VEH_CABBIE"), 168)
		.Const(_SC("VEH_STALLION"), 169)
		.Const(_SC("VEH_RUMPO"), 170)
		.Const(_SC("VEH_RCBANDIT"), 171)
		.Const(_SC("VEH_HEARSE"), 172)
		.Const(_SC("VEH_PACKER"), 173)
		.Const(_SC("VEH_SENTINELXS"), 174)
		.Const(_SC("VEH_ADMIRAL"), 175)
		.Const(_SC("VEH_SQUALO"), 176)
		.Const(_SC("VEH_SEASPARROW"), 177)
		.Const(_SC("VEH_PIZZABOY"), 178)
		.Const(_SC("VEH_GANGBURRITO"), 179)
		.Const(_SC("VEH_AIRTRAIN"), 180)
		.Const(_SC("VEH_DEADDODO"), 181)
		.Const(_SC("VEH_SPEEDER"), 182)
		.Const(_SC("VEH_REEFER"), 183)
		.Const(_SC("VEH_TROPIC"), 184)
		.Const(_SC("VEH_FLATBED"), 185)
		.Const(_SC("VEH_YANKEE"), 186)
		.Const(_SC("VEH_CADDY"), 187)
		.Const(_SC("VEH_ZEBRA"), 188)
		.Const(_SC("VEH_ZEBRACAB"), 188)
		.Const(_SC("VEH_TOPFUN"), 189)
		.Const(_SC("VEH_SKIMMER"), 190)
		.Const(_SC("VEH_PCJ600"), 191)
		.Const(_SC("VEH_PCJ"), 191)
		.Const(_SC("VEH_FAGGIO"), 192)
		.Const(_SC("VEH_FREEWAY"), 193)
		.Const(_SC("VEH_RCBARON"), 194)
		.Const(_SC("VEH_RCRAIDER"), 195)
		.Const(_SC("VEH_GLENDALE"), 196)
		.Const(_SC("VEH_OCEANIC"), 197)
		.Const(_SC("VEH_SANCHEZ"), 198)
		.Const(_SC("VEH_SPARROW"), 199)
		.Const(_SC("VEH_PATRIOT"), 200)
		.Const(_SC("VEH_LOVEFIST"), 201)
		.Const(_SC("VEH_COASTGUARD"), 202)
		.Const(_SC("VEH_DINGHY"), 203)
		.Const(_SC("VEH_HERMES"), 204)
		.Const(_SC("VEH_SABRE"), 205)
		.Const(_SC("VEH_SABRETURBO"), 206)
		.Const(_SC("VEH_PHOENIX"), 207)
		.Const(_SC("VEH_WALTON"), 208)
		.Const(_SC("VEH_REGINA"), 209)
		.Const(_SC("VEH_COMET"), 210)
		.Const(_SC("VEH_DELUXO"), 211)
		.Const(_SC("VEH_BURRITO"), 212)
		.Const(_SC("VEH_SPANDEX"), 213)
		.Const(_SC("VEH_SPANDEXPRESS"), 213)
		.Const(_SC("VEH_MARQUIS"), 214)
		.Const(_SC("VEH_BAGGAGE"), 215)
		.Const(_SC("VEH_BAGGAGEHANDLER"), 215)
		.Const(_SC("VEH_KAUFMAN"), 216)
		.Const(_SC("VEH_KAUFMANCAB"), 216)
		.Const(_SC("VEH_MAVERICK"), 217)
		.Const(_SC("VEH_VCNMAVERICK"), 218)
		.Const(_SC("VEH_RANCHER"), 219)
		.Const(_SC("VEH_FBIRANCHER"), 220)
		.Const(_SC("VEH_VIRGO"), 221)
		.Const(_SC("VEH_GREENWOOD"), 222)
		.Const(_SC("VEH_CUBANJETMAX"), 223)
		.Const(_SC("VEH_HOTRING1"), 224)
		.Const(_SC("VEH_HOTRINGRACER1"), 224)
		.Const(_SC("VEH_SANDKING"), 225)
		.Const(_SC("VEH_BLISTA"), 226)
		.Const(_SC("VEH_BLISTAC"), 226)
		.Const(_SC("VEH_BLISTACOMPACT"), 226)
		.Const(_SC("VEH_COMPACT"), 226)
		.Const(_SC("VEH_POLICEMAV"), 227)
		.Const(_SC("VEH_POLICEMAVERICK"), 227)
		.Const(_SC("VEH_BOXVILLE"), 228)
		.Const(_SC("VEH_BENSON"), 229)
		.Const(_SC("VEH_MESA"), 230)
		.Const(_SC("VEH_MESAGRANDE"), 230)
		.Const(_SC("VEH_RCGOBLIN"), 231)
		.Const(_SC("VEH_HOTRING2"), 232)
		.Const(_SC("VEH_HOTRINGRACER2"), 232)
		.Const(_SC("VEH_HOTRING3"), 233)
		.Const(_SC("VEH_HOTRINGRACER3"), 233)
		.Const(_SC("VEH_BLOODRING1"), 234)
		.Const(_SC("VEH_BLOODRINGBANGER1"), 234)
		.Const(_SC("VEH_BLOODRING2"), 235)
		.Const(_SC("VEH_BLOODRINGBANGER2"), 235)
		.Const(_SC("VEH_VICECHEE"), 236)
		.Const(_SC("VEH_POLICECHEETAH"), 236)
		.Const(_SC("VEH_FBICHEETAH"), 236)
		.Const(_SC("VEH_CHEETAH2"), 236)

		.Const(_SC("UPDATE_PLAYER_ONFOOT"), 0)
		.Const(_SC("UPDATE_PLAYER_FOOT"), 0)
		.Const(_SC("UPDATE_PLAYER_AIM"), 1)
		.Const(_SC("UPDATE_PLAYER_DRIVER"), 2)
		.Const(_SC("UPDATE_PLAYER_PASSENGER"), 3)

		.Const(_SC("UPDATE_VEHICLE_DRIVER"), 0)
		.Const(_SC("UPDATE_VEHICLE_OTHER"), 1)

		.Const(_SC("BODYPART_BODY"), 0)
		.Const(_SC("BODYPART_TORSO"), 1)
		.Const(_SC("BODYPART_LEFTARM"), 2)
		.Const(_SC("BODYPART_LARM"), 2)
		.Const(_SC("BODYPART_RIGHTARM"), 3)
		.Const(_SC("BODYPART_RARM"), 3)
		.Const(_SC("BODYPART_LEFTLEG"), 4)
		.Const(_SC("BODYPART_LLEG"), 4)
		.Const(_SC("BODYPART_RIGHTLEG"), 5)
		.Const(_SC("BODYPART_RLEG"), 5)
		.Const(_SC("BODYPART_HEAD"), 6)

		.Const(_SC("PARTREASON_QUIT"), 1)
		.Const(_SC("PARTREASON_DISCONNECTED"), 1)
		.Const(_SC("PARTREASON_TIMEOUT"), 0)
		.Const(_SC("PARTREASON_KICKEDBANNED"), 2)
		.Const(_SC("PARTREASON_KICKED"), 2)
		.Const(_SC("PARTREASON_BANNED"), 2)
		.Const(_SC("PARTREASON_CRASHED"), 3)

		.Const(_SC("KEY_ONFOOT_FORWARD"), 32768)
		.Const(_SC("KEY_ONFOOT_BACKWARD"), 16384)
		.Const(_SC("KEY_ONFOOT_LEFT"), 8192)
		.Const(_SC("KEY_ONFOOT_RIGHT"), 4096)
		.Const(_SC("KEY_ONFOOT_JUMP"), 2176)
		.Const(_SC("KEY_ONFOOT_SPRINT"), 1024)
		.Const(_SC("KEY_ONFOOT_FIRE"), 576)
		.Const(_SC("KEY_ONFOOT_CROUCH"), 288)
		.Const(_SC("KEY_ONFOOT_PUNCH"), 64)
		.Const(_SC("KEY_ONFOOT_NEXTWEP"), 2)
		.Const(_SC("KEY_ONFOOT_PREVWEP"), 4)
		.Const(_SC("KEY_ONFOOT_AIM"), 1)

		.Const(_SC("KEY_INCAR_LEFT"), 8192)
		.Const(_SC("KEY_INCAR_RIGHT"), 4096)
		.Const(_SC("KEY_INCAR_BACKWARD"), 2176)
		.Const(_SC("KEY_INCAR_FORWARD"), 1024)
		.Const(_SC("KEY_INCAR_HORN"), 288)
		.Const(_SC("KEY_INCAR_LEANUP"), 16)
		.Const(_SC("KEY_INCAR_LEANDOWN"), 8)
		.Const(_SC("KEY_INCAR_LOOKLEFT"), 4)
		.Const(_SC("KEY_INCAR_LOOKRIGHT"), 2)

		.Const(_SC("SQUIRREL_VERSION"), 39999); // 0.4-squirrel version 3.9.999 (4.0.0-beta)
}