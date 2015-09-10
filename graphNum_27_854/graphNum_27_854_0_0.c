#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_27_854_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 26;
static uint_fast32_t endhere = 0;
char str[37] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[27][11] = {{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU,0LLU,0LLU,0LLU,0LLU,18446744073709486080LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,16777215LLU,0LLU,18446462598732840960LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{0LLU,0LLU,18446744073692774400LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{0LLU,18446744073709547520LLU,18446744073709551615LLU,18446744073709551615LLU,11527526196208205823LLU,18014292930589620735LLU,18419715877264555935LLU,11527525783790657529LLU,18014292930589620735LLU,18446744073709092767LLU,1048575LLU},{18446744073709551615LLU,4095LLU,2251799796908032LLU,16140901201934809088LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073705881599LLU,1048575LLU},{18446744073642442752LLU,18446744073709551615LLU,18446744073709551615LLU,2305842940494219263LLU,17834254524382969856LLU,9185082091891031927LLU,8644518162991118327LLU,17834104954289649535LLU,9185082091891031927LLU,18446744073696868343LLU,1048575LLU},{67108863LLU,13835058055282163712LLU,18446744073709551615LLU,18446744073709551615LLU,11514015397326094335LLU,14554683785630173692LLU,18203490305704590495LLU,11514011685568159689LLU,14554683785630173692LLU,18446744073658825887LLU,1048575LLU},{18446744073642442752LLU,4611686018427387903LLU,2251799796908032LLU,2305843077933172736LLU,18446744073705357312LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073693822975LLU,1048575LLU},{18446744073709551612LLU,4611686018427387903LLU,18446744073709551615LLU,18446744073709551615LLU,17311836967612186623LLU,4540737002759274243LLU,283796062672454640LLU,17311559823019733055LLU,4540737002759274243LLU,18446744073693758448LLU,1048575LLU},{3377699720527875LLU,13835058261440593920LLU,1125899957174272LLU,2305843077933172736LLU,18446462598745423872LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551614LLU,13835058055282163711LLU,1125899906842623LLU,18446744004990074880LLU,18320643284143177727LLU,4603802794464264163LLU,16428638739149874174LLU,18320612490299571775LLU,4603802794464264163LLU,18446744073637192702LLU,1048575LLU},{18445618173802708989LLU,9223371968135299071LLU,18446744073709551615LLU,18446744073709551615LLU,15127028198384074751LLU,17086324852644769054LLU,2220816807897145041LLU,15126780610382582253LLU,17086324852644769054LLU,18446744073564790481LLU,1048575LLU},{2251799813685246LLU,9223372174293725184LLU,18446744073709551615LLU,18446744073709551615LLU,13752867362082652159LLU,15847532515582467053LLU,17131371846719761854LLU,13752847291095301851LLU,15847532515582467053LLU,18446744073608621502LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU,0LLU,0LLU,18446744073709551615LLU,18446744073709551615LLU,18446739675931475967LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,0LLU,0LLU,18374690877718069248LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU,18446726481523507200LLU,18446744073709551615LLU,17294104044062642175LLU,18374686479672672255LLU,9295429596801400831LLU,1048575LLU},{18311495345378426759LLU,17870275066478861823LLU,18379049339795275745LLU,8935137528944402175LLU,18446708888833622008LLU,17592186044415LLU,0LLU,18446744073709551615LLU,18446744073709551615LLU,9223367673168003071LLU,1048512LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17294104044079415295LLU,72057594037927935LLU,18446742974197989360LLU,17293822569102708735LLU,72040001851883775LLU,17365879199188910064LLU,1047615LLU},{144114915345416319LLU,18445626969879085055LLU,9295429358162276383LLU,18446185521785995263LLU,1152921436424240135LLU,18446726481523507200LLU,18446744073709551615LLU,18446744073709551615LLU,18374704071857668095LLU,10375141221063458815LLU,1033215LLU},{18445618448613523455LLU,13836183886486302720LLU,9222246411809067007LLU,16141463945746577408LLU,18446462667448124415LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17365879199188910079LLU,1047615LLU},{8736974611196419663LLU,18411248539301134304LLU,4368482972647425939LLU,18428996306240880624LLU,18446741907234062820LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17077648186845167615LLU,999231LLU},{18445626969829146623LLU,13871086784118517791LLU,18445626969879085055LLU,16158915394822731791LLU,18446464797751934975LLU,72057594037927935LLU,18446744073709551600LLU,17293822569102708735LLU,18446744073709551615LLU,17581524628306657279LLU,851198LLU},{18158505446925172479LLU,18412949483814649825LLU,18302620635001397183LLU,18429846778510311408LLU,18446742011051476975LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU,0LLU,17006155142904348672LLU,999231LLU},{16645242623262980543LLU,18194432539654291231LLU,17545962548739833455LLU,18320588304802054031LLU,18446728673835646875LLU,18446744073708503295LLU,4503599627370495LLU,18446744004990078975LLU,18446744073709551615LLU,15852553585523949567LLU,718559LLU},{18445686893216432127LLU,14116532967467643129LLU,18445686893263691775LLU,16281638488326011004LLU,18446479778598086655LLU,72057594037927935LLU,18446744073441181680LLU,17293822637822181375LLU,18446744069414584575LLU,17791047976949383167LLU,392634LLU},{17005532797844716287LLU,18203461729276133159LLU,17726108738226650815LLU,18325102899680247699LLU,18446729224933646255LLU,18446744073709551615LLU,18446744073709551615LLU,18446744004990078975LLU,4294967295LLU,14492469251668901888LLU,753279LLU},{18338618098621087647LLU,18284607887638429551LLU,18392661294151303143LLU,18365675979465981879LLU,18446734177702100985LLU,18446744073709551615LLU,268435455LLU,18446744005006852095LLU,72057594037927935LLU,18392626386268258304LLU,753223LLU}};

static uint_fast64_t D[27][11] = {{3377699720527875LLU,13835058261440593920LLU,1125899957174272LLU,2305843077933172736LLU,18446462598745423872LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18443366373989023740LLU,4611685812268957695LLU,18446744073709551615LLU,18446744073709551615LLU,11297842615212310527LLU,14541169687407675852LLU,14743881160745143452LLU,11297786114008194249LLU,14541169687407675852LLU,18446744073709538460LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18445618173752377343LLU,16140900995776378879LLU,7149182933461368831LLU,3905574386301875763LLU,3702862912964408163LLU,7148957959701357366LLU,3905574386301875763LLU,18446744073709499235LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,1125899873288191LLU,16140901133215332352LLU,8914875462371508223LLU,13239311558640383931LLU,13509593523090340731LLU,8914800127441075127LLU,13239311558640383931LLU,18446744073705864059LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073692774399LLU,16140901064495855615LLU,9761833667298066431LLU,8680555758251112567LLU,8612985267138623367LLU,9761683616050939768LLU,8680555758251112567LLU,18446744073709057927LLU,1048575LLU},{18446744073709551615LLU,13835058055282167807LLU,18446744073675997183LLU,18446744073709551615LLU,9207609438150590463LLU,14410533404590196732LLU,18194480906889591935LLU,9207605588928528327LLU,14410533404590196732LLU,18446744073658694783LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU,0LLU,17528009749721776128LLU,4554251100981772083LLU,3743405207631901683LLU,17527785394579698495LLU,4554251100981772083LLU,18446744073693770739LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073659219967LLU,18446744073709551615LLU,1135188581061492735LLU,13906007070950277372LLU,18162948011037096975LLU,1135184250689818560LLU,13906007070950277372LLU,18446744073658825743LLU,1048575LLU},{3377699787636735LLU,13835058261440593920LLU,18445618173819486207LLU,18446744073709551615LLU,18446462598737035263LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073658826751LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU,0LLU,0LLU,0LLU,0LLU,18446744073709486080LLU,1048575LLU},{18444492273962975231LLU,18446743936270602239LLU,18446744073709551615LLU,18446744073709551615LLU,16135553039942549503LLU,17149390644349758974LLU,18365659484374564575LLU,16135833277662420973LLU,17149390644349758974LLU,18446744073558425311LLU,1048575LLU},{4503599627370495LLU,13835058330160066560LLU,16777215LLU,18446744004990074880LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073608626175LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU,17581771470277705728LLU,18392687680819560255LLU,4608307493871763443LLU,17581841787469689855LLU,18392687680819560255LLU,18446744073564798963LLU,1048575LLU},{14694832661567402747LLU,16755413415132654113LLU,16570581906385673406LLU,12989392713392319760LLU,18446640843078534959LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18374690877718134783LLU,1048575LLU},{3755289111862676743LLU,15526388920017491422LLU,1877288067281052481LLU,7763194438250404591LLU,18446565829376440528LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446739675931475967LLU,1048575LLU},{18306881244758769539LLU,17417663022305774701LLU,18376687038994243552LLU,4097145485058248246LLU,18446681263586785272LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,9166298587280179199LLU,1048512LLU},{14699446762187059967LLU,17208025459305741235LLU,16572944207186705599LLU,17827384757278473689LLU,18446668468325371695LLU,18446744073709551615LLU,18446744073709551615LLU,17294104044062642175LLU,18374686479672672255LLU,9280449884475883519LLU,1048575LLU},{4503324816556035LLU,18445618448663842815LLU,9225623561857658880LLU,4611123205896146943LLU,18446744005006851072LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,9185623603649970175LLU,1033165LLU},{18446492835287629823LLU,17417671543521016941LLU,18446492835298861055LLU,17932207800948096566LLU,18446681264106878975LLU,72057594037927935LLU,18446742974197989360LLU,18446462598749618175LLU,72057594036879615LLU,18426265807081177072LLU,1047602LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU,18374686479671623680LLU,1099511562255LLU,1152921504606842880LLU,18374704071857667840LLU,9185623603649904655LLU,1033165LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17587891077375LLU,4503599627370480LLU,17293822569102704640LLU,18446744073709551615LLU,9222813484947865599LLU,845790LLU},{8736983132412042831LLU,18446151436933349375LLU,13591863530717443987LLU,18446447755317035007LLU,1152921468435168740LLU,18446726485818474240LLU,18442241573593743375LLU,1152921504606846975LLU,18374704071857667840LLU,17256103734664953871LLU,990189LLU},{13176819947591429559LLU,15528089864531006943LLU,15811425729635023725LLU,7764044910519835375LLU,18446565933193854683LLU,17587891077375LLU,4503599627370480LLU,18446744073709551615LLU,18446744073709551615LLU,9223369239220453375LLU,845790LLU},{9205355851370356719LLU,18439424624694378489LLU,13826049069052565499LLU,18443084349147430908LLU,18446743626965837310LLU,18446726485818474495LLU,18446744073441116175LLU,1152921504606846975LLU,18446744069414584320LLU,18366242007032004607LLU,499641LLU},{16176929827691952159LLU,18446605535242387455LLU,17311836933789318663LLU,18446674804474937343LLU,1152921496151129985LLU,18446744073708503040LLU,1099511627775LLU,18446744073709551615LLU,18374704071857668095LLU,14951938661799624719LLU,750543LLU},{4583960526618349543LLU,15563594195032577535LLU,11515000353173009401LLU,7781797076035148543LLU,18446568100206214398LLU,1048575LLU,18446744073441116160LLU,18446744073709551615LLU,18446744073709551615LLU,9223371769493061631LLU,380920LLU},{2304997244203354111LLU,14982490746221753339LLU,10375447776489091583LLU,16714617384154954237LLU,18446532632466418815LLU,18446726481524555775LLU,18446744073709551615LLU,17294104044079415295LLU,18446744069415632895LLU,13180611115400298495LLU,380927LLU}};

uint_fast8_t X[27] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[27][11] = {{3377699720527875LLU,13835058261440593920LLU,1125899957174272LLU,2305843077933172736LLU,18446462598745423872LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[27];
    cnt[0] = 0;
    cnt[1] = 0;
    cnt[2] = 0;
    cnt[3] = 0;
    cnt[4] = 0;
    cnt[5] = 0;
    cnt[6] = 0;
    cnt[7] = 0;
    cnt[8] = 0;
    cnt[9] = 0;
    cnt[10] = 0;
    cnt[11] = 0;
    cnt[12] = 0;
    cnt[13] = 0;
    cnt[14] = 0;
    cnt[15] = 0;
    cnt[16] = 0;
    cnt[17] = 0;
    cnt[18] = 0;
    cnt[19] = 0;
    cnt[20] = 0;
    cnt[21] = 0;
    cnt[22] = 0;
    cnt[23] = 0;
    cnt[24] = 0;
    cnt[25] = 0;
    cnt[26] = 0;

    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[0]), "+r" (cnt[1]), "+r" (cnt[2]), "+r" (cnt[3])
            : "r" (buf[0]), "r" (buf[1]), "r" (buf[2]), "r" (buf[3]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[4]), "+r" (cnt[5]), "+r" (cnt[6]), "+r" (cnt[7])
            : "r" (buf[4]), "r" (buf[5]), "r" (buf[6]), "r" (buf[7]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[8]), "+r" (cnt[9]), "+r" (cnt[10]), "+r" (cnt[11])
            : "r" (buf[8]), "r" (buf[9]), "r" (buf[10]), "r" (buf[11]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[12]), "+r" (cnt[13]), "+r" (cnt[14]), "+r" (cnt[15])
            : "r" (buf[12]), "r" (buf[13]), "r" (buf[14]), "r" (buf[15]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[16]), "+r" (cnt[17]), "+r" (cnt[18]), "+r" (cnt[19])
            : "r" (buf[16]), "r" (buf[17]), "r" (buf[18]), "r" (buf[19]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[20]), "+r" (cnt[21]), "+r" (cnt[22]), "+r" (cnt[23])
            : "r" (buf[20]), "r" (buf[21]), "r" (buf[22]), "r" (buf[23]));
    __asm__(
            "popcnt %2, %2  \n\t"
            "add %2, %0     \n\t"
            "popcnt %3, %3  \n\t"
            "add %3, %1     \n\t"
            : "+r" (cnt[24]), "+r" (cnt[25])
            : "r" (buf[24]), "r" (buf[25]));
    __asm__(
           "popcnt %1, %1  \n\t"
           "add %1, %0     \n\t"
            : "+r" (cnt[26])
            : "r" (buf[26]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16] + cnt[17] + cnt[18] + cnt[19] + cnt[20] + cnt[21] + cnt[22] + cnt[23] + cnt[24] + cnt[25] + cnt[26];
}

#elif UINTPTR_MAX == 0xffffffff // 32-bit
int counter (unsigned long long i)
{
  unsigned int i1 = i, i2 = i >> 32;
  i1 = i1 - ((i1 >> 1) & 0x55555555);
  i2 = i2 - ((i2 >> 1) & 0x55555555);
  i1 = (i1 & 0x33333333) + ((i1 >> 2) & 0x33333333);
  i2 = (i2 & 0x33333333) + ((i2 >> 2) & 0x33333333);
  i1 = (i1 + (i1 >> 4)) & 0xF0F0F0F;
  i2 = (i2 + (i2 >> 4)) & 0xF0F0F0F;
  return ((i1 + i2) * 0x1010101) >> 24;
}

#else
#error "this cpu doesn't seem to be 32-bit or 64-bit. I don't know how to deal with this."
#endif
void f(uint_fast8_t i, uint_fast8_t y0){
    if(y0){
        A[i][0] = A[i-1][0] & C[i][0];
        A[i][1] = A[i-1][1] & C[i][1];
        A[i][2] = A[i-1][2] & C[i][2];
        A[i][3] = A[i-1][3] & C[i][3];
        A[i][4] = A[i-1][4] & C[i][4];
        A[i][5] = A[i-1][5] & C[i][5];
        A[i][6] = A[i-1][6] & C[i][6];
        A[i][7] = A[i-1][7] & C[i][7];
        A[i][8] = A[i-1][8] & C[i][8];
        A[i][9] = A[i-1][9] & C[i][9];
        A[i][10] = A[i-1][10] & C[i][10];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];
        A[i][4] = A[i-1][4] & D[i][4];
        A[i][5] = A[i-1][5] & D[i][5];
        A[i][6] = A[i-1][6] & D[i][6];
        A[i][7] = A[i-1][7] & D[i][7];
        A[i][8] = A[i-1][8] & D[i][8];
        A[i][9] = A[i-1][9] & D[i][9];
        A[i][10] = A[i-1][10] & D[i][10];

    }
}

void printout(){
    sprintf(str, "[                           ,%5d]\n", this);
    str[1] = X[0] ^ 48;
    str[2] = X[1] ^ 48;
    str[3] = X[2] ^ 48;
    str[4] = X[3] ^ 48;
    str[5] = X[4] ^ 48;
    str[6] = X[5] ^ 48;
    str[7] = X[6] ^ 48;
    str[8] = X[7] ^ 48;
    str[9] = X[8] ^ 48;
    str[10] = X[9] ^ 48;
    str[11] = X[10] ^ 48;
    str[12] = X[11] ^ 48;
    str[13] = X[12] ^ 48;
    str[14] = X[13] ^ 48;
    str[15] = X[14] ^ 48;
    str[16] = X[15] ^ 48;
    str[17] = X[16] ^ 48;
    str[18] = X[17] ^ 48;
    str[19] = X[18] ^ 48;
    str[20] = X[19] ^ 48;
    str[21] = X[20] ^ 48;
    str[22] = X[21] ^ 48;
    str[23] = X[22] ^ 48;
    str[24] = X[23] ^ 48;
    str[25] = X[24] ^ 48;
    str[26] = X[25] ^ 48;
    str[27] = X[26] ^ 48;

}


void checkifbest(){
    uint_fast64_t * thisbuf = A[maxpos];
    this = counter(thisbuf);

    if(this == best){
        printout();
        fwrite(str, 1, sizeof(str), fout);
    }

    if(this > best){
        printout();
        fwrite(str, 1, sizeof(str), fout);
        best = this;
    }

}

int r(){
    goto startnocarry;
    
    startnocarry:
        if(i == maxpos){
            if(X[i]){
                X[i] = 0;
                i--;
                goto startcarry;
            }else{
                f(i, 0);
                checkifbest();
                X[i] = 1;
                f(i, 1);
                checkifbest();
                X[i] = 0;
                i--;
                goto startcarry;
            }
        }else{
            f(i, X[i]);
            i++;
            goto startnocarry;
        }
        
    startcarry:
        if(X[i] && (i != endhere)){
            X[i] = 0;
            i--;
            goto startcarry;
        }else{
            if(i == endhere){
                goto end;
            }else{
                X[i] = 1;
                f(i, 1);
                i++;
                goto startnocarry;
            }
        }

    end:
        return 0;
}
int main(){
fout = fopener;
    fputs("[[0,1],[0,7],[0,8],[1,2],[1,3],[2,3],[2,6],[3,4],[4,5],[4,11],[5,6],[5,7],[6,7],[8,9],[8,13],[9,10],[9,16],[10,11],[10,17],[11,12],[12,13],[12,14],[13,15],[14,15],[14,17],[15,16],[16,17]]\n", fout);
    if(endhere){
        uint_fast8_t bitpos = 0;
        uint_fast8_t thisbit;
        while(starthere){
            thisbit = starthere & 1;
            X[bitpos] = thisbit;
            f(bitpos, thisbit);
            bitpos++;
            starthere >>= 1;
        }
        i = endhere;
        r();
    }else{
        i = 0;
        r();
    }
    fwrite("FINISHED.", 1, 9, fout);
    fclose(fout);
    return 0;
}

