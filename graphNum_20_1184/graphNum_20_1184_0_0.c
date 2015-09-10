#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_20_1184_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 19;
static uint_fast32_t endhere = 0;
char str[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[20][17] = {{18410715276694781951LLU,18446744073709551615LLU,18446638520591712255LLU,18446744073709551615LLU,144115188075855871LLU,0LLU,4611686018419006464LLU,18446744073709551600LLU,18302628816645783551LLU,536870909LLU,18446744073709551564LLU,18446744073703260159LLU,18446744073709551615LLU,18446742974197924095LLU,11529188657788354047LLU,18446673706039115775LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,31LLU,0LLU,0LLU,18446744073709550592LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU,0LLU,0LLU,18446744073709027328LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,524287LLU,0LLU,0LLU,18446744004990074880LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18410715276690587648LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504598460415LLU,18446744073709551600LLU,8633400364333005183LLU,18446744073709158396LLU,17126581730898081735LLU,12587558484323580655LLU,66402114395LLU,18446742974197923840LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{36028797018963967LLU,17293822569102704640LLU,18446744073709551615LLU,18374686479537406015LLU,18427602607026339703LLU,18229990747841425339LLU,18446744073709551487LLU,18446744073709551615LLU,18446744073709551615LLU,9204229393384210431LLU,18446672604245524031LLU,9079098484685928413LLU,18446744056256790527LLU,1099511627775LLU,18446744072635809792LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,1152921504606846975LLU,0LLU,18428729675334287328LLU,16717361816799281151LLU,18446743523953737727LLU,17870283321414516731LLU,4611686018427387903LLU,18446708889337462783LLU,18446744073176873983LLU,18158513691115388927LLU,18445899648779157499LLU,18446744039349286911LLU,18446744073709551615LLU,1073741823LLU,18446744073709535232LLU,67108863LLU},{16140901064491663361LLU,13654826108583902711LLU,13821542789432721279LLU,18014398509481967LLU,18302628885633695744LLU,18446744073709551615LLU,15848095603012661247LLU,17869155220324343807LLU,18437521335813929976LLU,18446744073709283198LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU,4611686018427387648LLU,18445618173668425727LLU,18446744072635826159LLU,67108863LLU},{0LLU,0LLU,0LLU,18446744073709551584LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{67551795362136063LLU,18446744073441116160LLU,18446744073709551615LLU,18446744073709420671LLU,2305526332684988413LLU,18428726376530968575LLU,576460752303423463LLU,17293822569102704640LLU,18446744073709551615LLU,16140619587371663359LLU,9772810985235546111LLU,18419722475945328639LLU,17869577434941034303LLU,16140902022204358133LLU,18446744073709551615LLU,18374738703117975551LLU,67108863LLU},{18446462461293887487LLU,1152921504875282431LLU,18446744073709420544LLU,18446744056664031231LLU,18446744073709551615LLU,17149707371363172351LLU,18446744073709551615LLU,1152921504606846975LLU,0LLU,18446744073709027328LLU,18446744073709489791LLU,18446744065606156287LLU,18446744073709551615LLU,2305843009213693951LLU,18446739676736782336LLU,72053058539831295LLU,67108860LLU},{18446638519519539203LLU,18444492273895854079LLU,18435625812129476607LLU,35923243902697471LLU,18446744073692774400LLU,18410996751667267583LLU,18446717685430484991LLU,18446743558313476095LLU,14123288431433482237LLU,18446744073709547519LLU,3LLU,18446744073709027328LLU,18428729743919546367LLU,13821547248346939391LLU,9223371486958452703LLU,8928386261257830376LLU,67108739LLU},{17582052893643509759LLU,18446742974197923839LLU,18446744073543876575LLU,18446743970630336511LLU,18302628885650472959LLU,18446744073443213281LLU,18446744073608888319LLU,18446744073709549695LLU,18446603328168132411LLU,18446744073709551615LLU,18446744073709551615LLU,524287LLU,18014329790005248LLU,9223358842711307008LLU,18445090373861569533LLU,17221553867762696191LLU,67104895LLU},{65865140246913023LLU,18379189873140562944LLU,18446735277616660479LLU,18446726498668769407LLU,13258597298952208383LLU,2305843009213169663LLU,18446741874692521963LLU,13835058050987196431LLU,18446744073680191487LLU,18014398509423262467LLU,18446744073709551615LLU,18446145947973976063LLU,18230571291595716607LLU,18444494438559383551LLU,17293826967098883967LLU,18444536218742947839LLU,67047295LLU},{18446741049767362535LLU,18446711075207382015LLU,8796093022207LLU,9781835982830178272LLU,8070450532247928831LLU,18446741204671397375LLU,17870285520429105151LLU,8070450536542896127LLU,18446700230683379711LLU,18446691296681656319LLU,11240984665353420799LLU,18446744073709551615LLU,18446743249075830783LLU,16143152864292765695LLU,1152921504606822391LLU,18376937444113432576LLU,66125819LLU},{4611686009841541015LLU,18446744073709355007LLU,18320326622910611455LLU,7493531936430743295LLU,144114641809702848LLU,18446744073708503040LLU,4611263804351586303LLU,18446713287383859199LLU,18446744073709551615LLU,18446742974659297279LLU,18446726490109771759LLU,16142026483364265983LLU,14051214069843623935LLU,18410680092318236927LLU,16134066500217602047LLU,18435133163274502046LLU,63893239LLU},{18446726490111999999LLU,8358680892280143871LLU,8214495351579508734LLU,18440551615295995902LLU,18438230005419868159LLU,18446603336222244863LLU,18418033626084147199LLU,18430735184409133052LLU,18302628885633679367LLU,18437737973831704573LLU,18446744073709551615LLU,2305843009209499647LLU,4611686018361327360LLU,18086456102983303116LLU,13835055851157585904LLU,18212554762782504575LLU,54131197LLU},{18410732868876630655LLU,18446321603546447820LLU,18446743646359256313LLU,18446738023701281279LLU,18446744073708560447LLU,140737488355327LLU,18446743964180544512LLU,18446744073649913843LLU,18429011081155330047LLU,9007199237963775LLU,18410732868876632028LLU,18446744073709551111LLU,18443102491198357503LLU,18446391131013906431LLU,18275589549654146319LLU,12969735807152685055LLU,16752591LLU},{18419441000463138815LLU,18446181398382182399LLU,18338657682652658695LLU,18437455396242120673LLU,18311635569492361215LLU,17149707381026847744LLU,13294203887528418335LLU,17311806181286608887LLU,18428729675233624063LLU,4611685954002878463LLU,18446744073709551612LLU,16176929855038816255LLU,14987979491236642815LLU,16681332195146580799LLU,18446743816010989823LLU,10376253945612849087LLU,31913727LLU},{4611672678795835327LLU,17294385519056124991LLU,18446735825761600511LLU,18446734989736277759LLU,18446744073693822915LLU,18446607724602983423LLU,9223369973659238399LLU,18446744069481578493LLU,18014398509481983LLU,18438298793615556608LLU,18446726756401364735LLU,18446744073709027839LLU,18433220080687906815LLU,18445020039074299903LLU,17577545221385224191LLU,9223370748362457087LLU,56586164LLU}};

static uint_fast64_t D[20][17] = {{14123288431433875455LLU,11256614226695752947LLU,11512179109574709023LLU,18446744073709551591LLU,18446744073709551615LLU,18446744073709551615LLU,18007509493105033215LLU,142140495786655871LLU,14987699177981476856LLU,18446744073709543455LLU,2017612624505081471LLU,18445622503615791096LLU,18446744009284007935LLU,975983695418621951LLU,8572846426571028479LLU,18446744072635816931LLU,67108863LLU},{7061644215716937726LLU,15461651734998648409LLU,15777073451717281162LLU,18446744073709551602LLU,18446744073709551615LLU,18446744073709551615LLU,17055909335521032191LLU,17108813613732951391LLU,7452884242384252271LLU,18446744073708879575LLU,5309136308375823991LLU,12587518890586618607LLU,18446744067097138011LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18389066318805467139LLU,17293822569102704639LLU,16689390214802046975LLU,6121267963711455167LLU,18245125315109706343LLU,13468524684517363507LLU,18446744073709551230LLU,18446744073709551615LLU,18446744073709551615LLU,8445280204068225023LLU,18409374955771002254LLU,8788897165198616473LLU,18446744021351268086LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{11442777612896698365LLU,4138013843317750182LLU,4427024480899775093LLU,18414342806203007085LLU,2882303761517117439LLU,14843716460654098942LLU,1967295490491944907LLU,4013791379929800672LLU,18419330809247806454LLU,18446744073709278072LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18428729675200069663LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1935825098474187455LLU,16067662040767848415LLU,18446744073173694895LLU,13835058047027339263LLU,18445662097359044600LLU,18446744013579059199LLU,13835060254305419263LLU,6975187419158353510LLU,18446744073709536051LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,12393906174523604991LLU,16352407232966014430LLU,8635581019006418671LLU,17870283321406128633LLU,18446744073709551615LLU,18446744073709551615LLU,16928845696142934015LLU,17934727845365412861LLU,16710602706103803519LLU,6365440184246333897LLU,18446743400144524890LLU,11471556655234154495LLU,18446744073709550796LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18338657682652659711LLU,16111872187942334257LLU,18175656181326833561LLU,576460752303423287LLU,18446744073709551600LLU,3586976234980112441LLU,2276847566886334460LLU,16690214943428967939LLU,2026619832250134983LLU,12081303954434019135LLU,4611684492969159077LLU,18446744073026595225LLU,18446744073709551615LLU,67108863LLU},{9079256848778919935LLU,17859863616886798173LLU,18086331578457454058LLU,18446744073709551610LLU,18446744073709551615LLU,18446744073709551615LLU,18355259959249207295LLU,18324909363035275167LLU,18192852819587780559LLU,475111LLU,18446744073709551612LLU,18446744073709551615LLU,18446744073709551615LLU,17470762577314185215LLU,9930403750334553190LLU,18446673706039109439LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,12357877377504640991LLU,15766059070792279448LLU,8581247002247640781LLU,17870283321406126517LLU,15770883153756351167LLU,11021273095787044505LLU,10001463869642272175LLU,13174976883272276985LLU,15517072091633868150LLU,18446744063960772013LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18428263255505691451LLU,1152921504606846975LLU,18446744073709420544LLU,18014398492436332543LLU,18331895273610280143LLU,16425648172752805479LLU,18446744073709550847LLU,18446744073709551615LLU,18446744073709551615LLU,18331888212894547967LLU,18445743515980726780LLU,16428849957147741755LLU,6870197075472547832LLU,18446743505422604127LLU,18446739676736782335LLU,72053058539831295LLU,67108860LLU},{18438788522936835271LLU,18446744073709551615LLU,16689390214802046975LLU,572833222925221887LLU,143561000124089340LLU,4580156457114140671LLU,18446744073709551584LLU,18446744073709551615LLU,18446744073709551615LLU,13978627881304063999LLU,9224497666145648591LLU,18411273897310683135LLU,17364820508809297927LLU,18446743826628345072LLU,11471556656307896319LLU,18374738703117974732LLU,67108863LLU},{17351524874794827775LLU,8345167975928627199LLU,8682940081536794566LLU,18432388719602048888LLU,13258597302978740223LLU,14843864371545243616LLU,13697839004003393483LLU,13692917590089791494LLU,18446744065123811079LLU,18446744073709493217LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17473951161030800383LLU,18446183266659594364LLU,17221487789686646591LLU,67104895LLU},{4611555861842624511LLU,18442374550076244748LLU,18444499000351514873LLU,18446606902624510207LLU,8070450532247928831LLU,18410848840509784575LLU,9223338528054919167LLU,9223371490864414713LLU,13851065913789908991LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18430031488914243583LLU,707064170826555335LLU,8928381972737163256LLU,67108739LLU},{18428693458556092387LLU,18446711075475816447LLU,18446744073709551615LLU,9259400833869283327LLU,18303183073853833215LLU,18442521811888342047LLU,18446744073709272127LLU,18446744073709551615LLU,17437928969675063549LLU,4611616684769865727LLU,18446744073441116160LLU,36028797018963967LLU,1152920469520777208LLU,13835057229008408335LLU,18446744073035288531LLU,6485183042506473471LLU,66125817LLU},{18444624191601738559LLU,18379189873140563967LLU,18446744073709551615LLU,18446744073674948607LLU,18446744069414648835LLU,35896855591157729LLU,18446744073707388927LLU,18446744073709551615LLU,4595782680331157307LLU,17870845240567398144LLU,18445618448680615935LLU,18446708889337954311LLU,18159573626767015935LLU,9223371976321594367LLU,18446744073650501949LLU,12033604975771779071LLU,67047294LLU},{17870283321405078527LLU,2305842734588485571LLU,2304716593893998584LLU,18442236075228363774LLU,18438299824407248895LLU,18446744073709551615LLU,18412949355402100735LLU,1135188168691153407LLU,18446744073675997184LLU,18446744073709551615LLU,9223372036619882367LLU,18446713285756583424LLU,18443366373921980415LLU,1864059237173297103LLU,18230289801586671360LLU,17365880162833249275LLU,45857759LLU},{1152921504606838303LLU,18389921312584757244LLU,18446321844098165823LLU,9223334788742511847LLU,18446744072904237056LLU,18446744073709551615LLU,18014389704933244927LLU,17437937654098298879LLU,14969973957472550911LLU,18446744073684385567LLU,18410715276959023103LLU,18446743526067666943LLU,18374406039781980159LLU,17289195824173023231LLU,9187905433836748799LLU,13831961829841821694LLU,32493543LLU},{18158513697557348343LLU,17365852675348905215LLU,17296067771840208863LLU,16715250711457144831LLU,18446673709260341247LLU,18446744073709551615LLU,18444525808966959103LLU,18446463144730558079LLU,18446736370685706239LLU,18446744073507700991LLU,11240984669912579839LLU,35184371597311LLU,288230101273804544LLU,18319512986189823996LLU,17870174434388588543LLU,18419652107131321863LLU,56425725LLU},{18445531312383832575LLU,18446744073709542403LLU,17859508124633792511LLU,18445532411895739391LLU,18446682497820401663LLU,4580020220986392575LLU,18446724291089661951LLU,18446743657098772477LLU,18446744073709551615LLU,18005461678803648511LLU,36028797018963967LLU,18446146489135136768LLU,18284895962100924167LLU,18435625770823974908LLU,12718165347694280703LLU,18423098526361190121LLU,54476703LLU},{17836505740081626863LLU,18446744073442164735LLU,1152921495856480255LLU,11513451279141470176LLU,18302699254377866239LLU,18446743970395455487LLU,17872535121148509184LLU,17294104044079413751LLU,18446744073709551615LLU,576407975460077567LLU,18411841172038221788LLU,18446744073709551615LLU,18446532349001728255LLU,16285006425666617091LLU,18427163970642116607LLU,18409958811751006719LLU,15987711LLU}};

uint_fast8_t X[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[20][17] = {{14123288431433875455LLU,11256614226695752947LLU,11512179109574709023LLU,18446744073709551591LLU,18446744073709551615LLU,18446744073709551615LLU,18007509493105033215LLU,142140495786655871LLU,14987699177981476856LLU,18446744073709543455LLU,2017612624505081471LLU,18445622503615791096LLU,18446744009284007935LLU,975983695418621951LLU,8572846426571028479LLU,18446744072635816931LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[20];
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


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16] + cnt[17] + cnt[18] + cnt[19];
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
        A[i][11] = A[i-1][11] & C[i][11];
        A[i][12] = A[i-1][12] & C[i][12];
        A[i][13] = A[i-1][13] & C[i][13];
        A[i][14] = A[i-1][14] & C[i][14];
        A[i][15] = A[i-1][15] & C[i][15];
        A[i][16] = A[i-1][16] & C[i][16];

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
        A[i][11] = A[i-1][11] & D[i][11];
        A[i][12] = A[i-1][12] & D[i][12];
        A[i][13] = A[i-1][13] & D[i][13];
        A[i][14] = A[i-1][14] & D[i][14];
        A[i][15] = A[i-1][15] & D[i][15];
        A[i][16] = A[i-1][16] & D[i][16];

    }
}

void printout(){
    sprintf(str, "[                    ,%5d]\n", this);
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
    fputs("[[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,5],[2,4],[2,6],[3,5],[3,7],[4,8],[4,9],[5,8],[5,9],[6,7],[6,8],[6,9],[7,8],[7,9]]\n", fout);
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

