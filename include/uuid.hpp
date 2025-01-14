#ifndef UUID_H
#define UUID_H

#include <cstdint>

namespace uuid // all UUID's are in little endian 
{
	namespace spawn
	{

		const uint32_t no_name[4] = {0x679df416, 0x70262341, 0xac926ce3, 0x8bf277eb};

		const uint32_t the_catacombs[11][4] = {
			{0xfd5133fb, 0x94c1904d, 0x89ce9a22, 0xc869097f},
			{0x2e37c110, 0x3acde448, 0x9dc58fe4, 0x002452aa},
			{0xdd9644e7, 0xd319d247, 0x86b8d6b8, 0xc3b57ed2},
			{0xe953acdc, 0x35df654f, 0x81d61632, 0xf33345cb},
			{0xc80604e2, 0x92344b41, 0x8ec1c6f8, 0xb6b4f920},
			{0xb9ce403e, 0x7c5c3540, 0x8e488974, 0xb2ac1ada},
			{0x93a90e4f, 0xdc2ac44e, 0x89ba5986, 0x9c660fa9},
			{0xb537349c, 0x22ff7d46, 0x83d8c133, 0x34416b2d},
			{0x2bcefa41, 0x2fa61d42, 0x84aaa9a8, 0xe6a9acf3},
			{0x3d03fb73, 0x13f1a847, 0x9e89b180, 0xc7928638},
			{0x32a6931c, 0x30be9441, 0xa55fde0a, 0x85805cd0}
		};
		const uint32_t twilight_falls[3][4] = {
			{0xbf8e4592, 0x232c744c, 0xb8a21749, 0xe6d97d24},
			{0x6bccc604, 0xf80c3841, 0x8c4e10c9, 0x6f11efe5},
			{0xc95450d3, 0x1b3fbc44, 0xb44f91cd, 0xb6aa1348}
		};
		const uint32_t valley_of_avalar[13][4] = {
			{0x50a27e83, 0xe39bcc47 ,0x88c9fe3d ,0xae45fbfb},
			{0x32e1d182, 0x5b2a6d43 ,0xa7dbb7ec ,0xbc0c76ba},
			{0xc5ae8c0d, 0xe9dd674c ,0xad4642f2 ,0x0003d104},
			{0xd0ac76c2, 0xb8c55c4f ,0xaba36c4f ,0xd202af2c},
			{0x20d8e76d, 0x89ca4543 ,0x8ba5d13e ,0x59a1738b},
			{0xd83ace13, 0xbf360f46 ,0xaef3d60d ,0xa470a596},
			{0xe1634d2d, 0x93c13d45 ,0x9e76ea5e ,0xb13104df},
			{0x898011ac, 0xa22cf04d ,0xbfed8f1f ,0xb4105f80},
			{0xf0295cd6, 0x3e1ca24b ,0x86d65ccf ,0x92110339},
			{0x9ba31948, 0xd3ff0e45 ,0xb9af81c8 ,0xa5a990de},
			{0x25972df3, 0xfebc9644 ,0xa0ac204a ,0x418d79fe},
			{0x840ba76d, 0xf046954f ,0x9557bbac ,0x92cbdb51},
			{0x47993f1c, 0x99b6e54d ,0x88ff3396 ,0x337b2de3}
		};
		const uint32_t dragon_city[11][4] = {
			{0x556a6361, 0xd6b5c74c, 0xbef12ff9, 0x7aa5d598},
			{0x388737c3, 0xd5b0f94b, 0xbefc1f90, 0x34a5a3ee},
			{0x30127d21, 0x009fe345, 0x954404be, 0x63fa068d},
			{0xc0b1930a, 0x8cdfe540, 0xb16b997a, 0xfa02477a},
			{0xdec54424, 0x5336144e, 0x8e12bd4c, 0xfeb9dc1b},
			{0x953d8e91, 0xe4cfac47, 0xb1ec607f, 0x30ba5516},
			{0x3a6ee70a, 0xce05c040, 0xbce412ac, 0x7c47432e},
			{0x60996d9f, 0xce785e40, 0xa83b4879, 0x3f894a1d},
			{0x420013b6, 0x5922e540, 0xacb6e6cf, 0x03938a49},
			{0xdde1fc56, 0xc7880b47, 0x8c878d11, 0xecab0266},
			{0xf84e70fa, 0x4fca4847, 0xbf5c3cf1, 0x04305719}
		};
		const uint32_t attack_of_the_golem[8][4] = {
			{0xf5534229, 0x9ef99e4b, 0x9fe836fd, 0x554fec5d},
			{0x5d41f31d, 0x8f92294a, 0x9a5915c2, 0x6cb5d770},
			{0x6392424f, 0x45542340, 0x9fab9dca, 0x0383d4b9},
			{0x459d265e, 0x98a86a44, 0x923a9f34, 0xbd568388},
			{0x4d20cfe3, 0xe144bf48, 0x8cddebeb, 0xc3389c60},
			{0xc8d0a2c5, 0x827f9e49, 0xbdc2ddbb, 0x12dc20bb},
			{0xb7539310, 0xe19cc046, 0x919500b1, 0x3541e0a1},
			{0x63ca0af2, 0xab149440, 0x8d22ca07, 0xfa0b2cdc}
		};
		const uint32_t ruins_of_warfang[20][4] = {
			{0x45f55f58, 0xdf5ddf44, 0x9f668153, 0xaa1e6b74},
			{0xf2d4d997, 0xa5631542, 0xa00a9b80, 0x23b0ae1c},
			{0x0ae58082, 0xc5cf2a4d, 0xa2830517, 0x85848fa2},
			{0xfb7e7721, 0x43714945, 0x9dbaea7f, 0x944b3232},
			{0x832612d4, 0x851f3d43, 0x98230497, 0x1a08f5a7},
			{0xa68bd7a8, 0xd4050c44, 0x97d39d3d, 0xa0c30053},
			{0x81342cc7, 0x529d8b45, 0xb1d67041, 0x32fce410},
			{0xa7944b62, 0xc4c49e40, 0x99ea05ba, 0xaa00e790},
			{0xd1a8d42d, 0x35541f48, 0x9876b417, 0xae770fdb},
			{0x10e5584c, 0x2217b74d, 0x8cd0c440, 0x9dc81eab},
			{0x8c9b495e, 0x732e0748, 0x8c519329, 0x0eec12e8},
			{0x527991bb, 0x291d7e41, 0x8270f04e, 0xe01f4eb5},
			{0x067caea2, 0x6f4a8b4e, 0x98ee90fb, 0x1758ea3f},
			{0x49820d08, 0x556af941, 0xae96da6e, 0x7e8ffcfe},
			{0xc99c0488, 0x69d22b44, 0xbff0fdf5, 0x765a6058},
			{0x03e89f29, 0xba5c9e48, 0x9e166fa8, 0xc39871ce},
			{0x20d47e7b, 0x6b59c140, 0x97624325, 0x1cbc66b9},
			{0xed85623d, 0xd5738443, 0xaa0d8296, 0x8d830482},
			{0xd9a7dd97, 0x7f215940, 0xb309230e, 0x99142fdd},
			{0x975ccb64, 0xae901047, 0xab8189cb, 0x81768dc3}
		};
		const uint32_t the_dam[12][4] = {
			{0x88b63210, 0xa878bd46, 0x8e23fa52, 0x912dd490},
			{0x0dc16153, 0x75303b45, 0xadaa0001, 0x768e34f9},
			{0x9301fdb5, 0x1e37cf40, 0x83e31022, 0x7f776bc0},
			{0x564b8eb0, 0x08e05b44, 0xaac83eb1, 0xf06bcd83},
			{0x60e086a5, 0xebb71240, 0xbb81c445, 0x78b13c0d},
			{0x881de99c, 0x40163245, 0xb8544bfd, 0xcbdde91b},
			{0x57988368, 0x0b525542, 0xa13386bb, 0xc980e6e4},
			{0xee747ed3, 0x896c2d4c, 0xa7ebeca6, 0x231726f0},
			{0xbd317c24, 0xb9c0ad4a, 0xa3175a9c, 0x8121f3d7},
			{0x01914caf, 0x45854e48, 0x818129f1, 0xb6f02df4},
			{0x0752f410, 0x5e6e8540, 0x81297dce, 0x9fab0a40},
			{0xfe80a1fe, 0x7d74214f, 0xaa9e3d81, 0x36eb076b}
		};
		const uint32_t the_destroyer[14][4] = {
			{0x46cfa384, 0x62d00948, 0xa8c5cd43, 0x33c0d4ae},
			{0x612d6820, 0x82d7e34c, 0x99a501b1, 0xe3456f73},
			{0x05176ed2, 0xd3d1034a, 0x8db20bfe, 0xece89f25},
			{0x08eb64d3, 0x52c5ec43, 0x8d44cc6e, 0x7d752ead},
			{0xcba093d0, 0x453d2f45, 0x8b831a6e, 0x55392ec9},
			{0xfa5d2c0d, 0xa2214846, 0x925dc893, 0x6a77a376},
			{0x6f1ebead, 0x83a1914a, 0x93456d32, 0x8e9ca378},
			{0x2f401a79, 0xfc00c849, 0xab2ee45e, 0x74963db3},
			{0x1a0b404d, 0x1028014d, 0xb22598e4, 0xb5ef4c6b},
			{0x28d1e0c1, 0x12996346, 0xbef0d797, 0xdb031154},
			{0x75a48e03, 0xc3ccf94b, 0xbb3afa9f, 0xb16ec154},
			{0xf215ba2a, 0xa2b20e4a, 0x86ecd107, 0x41bfb445},
			{0x962f2ab3, 0x547eac41, 0xbb00f731, 0xc7f056c9},
			{0x4af0ded2, 0x0e927a44, 0x839ee3ce, 0xe51a3995}
		};
		const uint32_t burned_lands[8][4] = {
			{0xebe3fac0, 0xfd8bb247, 0xbe271c79, 0x9c76b59a},
			{0x929d7f2a, 0x4925ef4c, 0xbd9842be, 0x5d2e70e9},
			{0x381772e4, 0xe6b8bc41, 0xbd9f6eb4, 0x84ef1d88},
			{0x7d7f563a, 0xec53ad42, 0xa532f133, 0xa0e7f928},
			{0xbbb74f10, 0xc011ae4b, 0xbdbd2202, 0x48793ec2},
			{0xa2773105, 0xfc4c0647, 0xba57219c, 0x07a3bb79},
			{0x163c9c45, 0x53656146, 0xaaa47d1c, 0x1cd32879},
			{0xadd961b6, 0x8463fb4f, 0x8b9a87c7, 0xe7964f9c}
		};
		const uint32_t floating_islands[4][4] = {
			{0xc3099d9d, 0xe98f1c4f, 0x84697080, 0x5fd6e369},
			{0x061d88cc, 0xc6e41d45, 0x8215c39c, 0xdcf0b167},
			{0x2edbfc62, 0xf15d7645, 0xb512c674, 0xe660d2c0},
			{0xb6e40813, 0xe10ea249, 0xb1740d64, 0xc6f94e59}
		};
		const uint32_t malefors_lair[3][4] = {
			{0xf6551fd5, 0x2ef40f44, 0xa0641337, 0x52099daf},
			{0x1a482c44, 0x9136bb42, 0xaa2e60d5, 0x7b26a87f},
			{0xefe32aa8, 0x182a504d, 0xa0882549, 0xe6aa4f01}
		};
	}
	namespace game_state
	{
		const uint32_t player_current[4] = {0x679df416, 0x70262341, 0xac926ce3, 0x8bf277eb};
		const uint32_t player_current_temp[4] = {0xae41192e, 0x40766e44, 0x94641367, 0x30c8e07e};
		const uint32_t player_slot[5][4] = {
			{0xd6c177d8, 0xcc32824b, 0xad01b117, 0xa859d694},
			{0xd7651b63, 0x3271ad46, 0x9a645629, 0x30b289db},
			{0x12908612, 0x8c2c4144, 0x840c0fb9, 0x92ea7d34},
			{0x66ea9c9c, 0x47754c44, 0xb197bbf5, 0xfa35eab1},
			{0xbe20b24a, 0x24b43d42, 0x91bb8e6a, 0x97947a83}
		};
		const uint32_t main_menu[4] = {0x6f76117d, 0xdcbe8048, 0xb89c0175, 0x306440fb};
		const uint32_t the_catacombs__new_game[4] = {0xaf609146, 0x5905e042, 0xbc98b937, 0xe209f8e8};
		const uint32_t twilight_falls[4] = {0xd241f201, 0x3ebcea4f, 0x8772a8b9, 0x62ddc5e5};
		const uint32_t valley_of_avalar[4] = {0xad3e7500, 0x3e3aba4e, 0xa203ecea, 0x7f9c6fea};
		const uint32_t dragon_city[4] = {0x18713582, 0xa0e80e46, 0xbc454144, 0x45cf3326};
		const uint32_t attack_of_the_golem[4] = {0x036350ad, 0x656cc540, 0xa4a4de12, 0xa9d32ad0};
		const uint32_t ruins_of_warfang[4] = {0x73b9bb6b, 0x496d7e47, 0xadb84c3d, 0xd834e637};
		const uint32_t the_dam[4] = {0xf69ddf8c, 0x02fca34c, 0x8c20530c, 0x3f278c66};
		const uint32_t the_destroyer[4] = {0xf2771111, 0xa5a44440, 0xb2590b86, 0xfd244221};
		const uint32_t burned_lands[4] = {0xfabc02c3, 0xc64e7943, 0x9380edf1, 0xd3799229};
		const uint32_t floating_islands[4] = {0x57b4e090, 0x5c3b1e4a, 0xa2dd97a5, 0x6fd6f3f6};
		const uint32_t malefors_lair[4] = {0x4a3d2f83, 0x03cf8048, 0x8f1fb817, 0x477c41bf};
	}
}

#endif
