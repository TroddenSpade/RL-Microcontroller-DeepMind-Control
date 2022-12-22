float w0[12][4] = {
{-5.960000753402709961e-01, 3.904157280921936035e-01, -9.172448515892028809e-01, -9.887627363204956055e-01},
{-2.427977472543716431e-01, -8.027581125497817993e-02, 1.163359165191650391e+00, 2.097217291593551636e-01},
{-7.979759573936462402e-01, -5.166348814964294434e-01, -5.130123496055603027e-01, -4.525357186794281006e-01},
{-2.073621153831481934e-01, 1.600238382816314697e-01, 1.197596907615661621e+00, 7.018112540245056152e-01},
{3.335109949111938477e-01, 9.385895729064941406e-02, -1.271461129188537598e+00, -1.012925982475280762e+00},
{-7.121327519416809082e-01, 2.182087600231170654e-01, -4.088866710662841797e-01, 5.241909027099609375e-01},
{2.695289254188537598e-01, 9.319246411323547363e-01, 9.867548346519470215e-01, 1.036515235900878906e+00},
{2.099056094884872437e-01, 1.495818197727203369e-01, -1.220786929130554199e+00, -4.406315088272094727e-01},
{-3.249925374984741211e-02, -3.724269568920135498e-02, -8.069500923156738281e-01, 4.635793268680572510e-01},
{9.752123057842254639e-02, 3.584276735782623291e-01, 1.705273509025573730e+00, 6.320149451494216919e-02},
{3.666295409202575684e-01, 3.438340127468109131e-01, 1.219484210014343262e+00, 4.243036210536956787e-01},
{-1.896682083606719971e-01, 8.697087168693542480e-01, 1.076477646827697754e+00, -1.058627516031265259e-01},
};

float b0[12] = {
9.859697520732879639e-02,
2.243396081030368805e-02,
1.294109821319580078e-01,
-9.331970475614070892e-03,
4.175505787134170532e-02,
-2.089923620223999023e-02,
-4.632144421339035034e-02,
7.311679422855377197e-03,
2.780915051698684692e-02,
-2.135484479367733002e-02,
-8.436851948499679565e-02,
-2.260166592895984650e-02,
};

float w1[12][12] = {
{6.197347640991210938e-01, -1.451818346977233887e-01, 7.782781124114990234e-01, 4.803082942962646484e-01, 7.961587398312985897e-04, -3.366068601608276367e-01, -8.486253023147583008e-01, -2.404943257570266724e-01, 1.354118436574935913e-01, -1.273365497589111328e+00, -7.029747366905212402e-01, 4.304787516593933105e-01},
{4.969363212585449219e-01, -1.362859308719635010e-01, 1.656785309314727783e-01, -1.006205081939697266e+00, -2.940186262130737305e-01, -3.319070041179656982e-01, -1.350353002548217773e+00, -2.532804608345031738e-01, -1.850643157958984375e-01, -8.672229051589965820e-01, -9.270501136779785156e-01, -3.816545605659484863e-01},
{6.784679889678955078e-01, -3.719466030597686768e-01, 6.147118210792541504e-01, -1.024768710136413574e+00, 2.621790170669555664e-01, 1.026140525937080383e-01, 8.797201514244079590e-02, 6.053770184516906738e-01, 9.386909008026123047e-02, -1.167973279953002930e+00, -6.534715890884399414e-01, 9.294724464416503906e-02},
{1.361814886331558228e-01, -6.138120293617248535e-01, 5.773727297782897949e-01, -4.993579685688018799e-01, 2.353732585906982422e-01, 3.681840002536773682e-01, -1.119830608367919922e+00, 2.725411951541900635e-01, 1.058145761489868164e+00, -3.429348170757293701e-01, -1.147153258323669434e+00, 9.520485997200012207e-02},
{3.417345881462097168e-01, 1.633352488279342651e-01, 1.738264262676239014e-01, -2.089170068502426147e-01, 3.915797770023345947e-01, 1.700609549880027771e-02, -6.903469562530517578e-01, 6.761452555656433105e-02, 9.680296182632446289e-01, -9.421370029449462891e-01, 2.768872082233428955e-01, -8.054006695747375488e-01},
{4.303407371044158936e-01, 4.656098783016204834e-01, 3.204184770584106445e-01, -5.103762149810791016e-01, 9.570526480674743652e-01, 5.738299489021301270e-01, -7.875645756721496582e-01, -5.745638012886047363e-01, -1.655740849673748016e-02, -6.434084773063659668e-01, -7.427383661270141602e-01, 1.702962666749954224e-01},
{9.039617180824279785e-01, 5.307884216308593750e-01, 4.717977941036224365e-01, 7.036969810724258423e-02, 2.835573852062225342e-01, 1.421260237693786621e-01, -7.991134524345397949e-01, 5.751250982284545898e-01, -3.011655062437057495e-02, -7.870416045188903809e-01, -1.626623392105102539e+00, -7.221427559852600098e-01},
{-2.856717705726623535e-01, -2.333493717014789581e-02, 5.044448971748352051e-01, 1.800418794155120850e-01, -4.843821823596954346e-01, 4.223258197307586670e-01, 8.961458802223205566e-01, -6.092326641082763672e-01, -1.801184266805648804e-01, 6.151598095893859863e-01, 7.442512512207031250e-01, -3.859997987747192383e-01},
{2.151478976011276245e-01, -2.153532803058624268e-01, 7.437366843223571777e-01, -3.641126155853271484e-01, 7.278187870979309082e-01, -9.122557044029235840e-01, -2.395217120647430420e-01, -1.643609553575515747e-01, 2.612696290016174316e-01, -5.408717691898345947e-02, -7.589933276176452637e-01, -3.320747017860412598e-01},
{9.198116660118103027e-01, -1.422294825315475464e-01, 2.492085099220275879e-01, -2.363679558038711548e-01, -7.093811780214309692e-02, -1.217751279473304749e-01, -4.051782488822937012e-01, 4.391824603080749512e-01, -2.937317360192537308e-03, 4.903946816921234131e-01, 3.560576140880584717e-01, 1.769670844078063965e-01},
{-6.674966961145401001e-02, 6.140069961547851562e-01, -7.001473307609558105e-01, 1.376225203275680542e-01, -8.181080818176269531e-01, -1.262656748294830322e-01, 1.159832835197448730e+00, -6.026823520660400391e-01, 4.129159450531005859e-01, 7.045826315879821777e-01, 3.933734595775604248e-01, 3.373654484748840332e-01},
{-6.895094513893127441e-01, 9.795867800712585449e-01, 3.727977275848388672e-01, -9.676326811313629150e-02, -3.383697867393493652e-01, -2.157272249460220337e-01, 1.998134255409240723e-01, 3.035038709640502930e-01, -1.214450895786285400e-01, 5.124145150184631348e-01, 6.329948306083679199e-01, 5.010049343109130859e-01},
};

float b1[12] = {
9.432256221771240234e-02,
-9.589810855686664581e-03,
-2.296594902873039246e-02,
2.777857705950737000e-02,
-1.013109227642416954e-03,
7.317612320184707642e-02,
9.920119494199752808e-02,
-3.502647951245307922e-02,
1.324880868196487427e-02,
3.606287762522697449e-02,
2.991862222552299500e-02,
4.640213772654533386e-02,
};

float w2[2][12] = {
{4.267984628677368164e-01, 5.094769597053527832e-01, 3.032592236995697021e-01, 6.558960080146789551e-01, 5.211772322654724121e-01, 3.242379128932952881e-01, 6.455044746398925781e-01, -1.189258694648742676e-01, 2.006608545780181885e-01, 1.718918420374393463e-02, -3.946646749973297119e-01, -2.094025909900665283e-01},
{-4.319271147251129150e-01, -5.083940625190734863e-01, -3.086390197277069092e-01, -6.508188247680664062e-01, -5.210681557655334473e-01, -3.253462910652160645e-01, -6.389994621276855469e-01, 1.248543635010719299e-01, -1.960386633872985840e-01, -2.123023755848407745e-02, 3.957821726799011230e-01, 2.098123580217361450e-01},
};

float b2[2] = {
-3.236535564064979553e-02,
3.236536309123039246e-02,
};

int shape[4] = {4,12,12,2};
float *weights[3] = {w0[0],w1[0],w2[0]};
float *biases[3] = {b0,b1,b2};