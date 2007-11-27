
static int cd_commands[] = {
	INQUIRY,
	TEST_UNIT_READY,
	FORMAT_UNIT,
	RESERVE,
	RELEASE,
	SEND_DIAGNOSTIC,
	REPORT_LUNS,
	READ_CAPACITY,
	READ_6,
	READ_10,
	WRITE_6,
	WRITE_10,
};

static unsigned char cd_inq_00[] = {
	0x05,0x00,0x05,0x02,0x5c,0x00,0x00,0x60,	/* 00 - 07 */
	0x63,0x6f,0x4c,0x69,0x6e,0x75,0x78,0x00,	/* 08 - 15 */
	0x43,0x4f,0x44,0x49,0x53,0x4b,0x00,0x00,	/* 16 - 23 */
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,	/* 24 - 31 */
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,	/* 32 - 39 */
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,	/* 40 - 47 */
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,	/* 48 - 55 */
	0x00,0x00,0x00,0x77,0x00,0x14,0x03,0x3d,	/* 56 - 63 */
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,	/* 64 - 71 */
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,	/* 72 - 79 */
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,	/* 80 - 87 */
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,	/* 88 - 95 */
};

static unsigned char cd_inq_83[] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,	/* 00 - 07 */
};

static scsi_page_t cd_inq_pages[] = {
	{ 0x00, cd_inq_00, sizeof(cd_inq_00) },	/* Standard page */
	{ 0x83, cd_inq_83, sizeof(cd_inq_83) },	/* Device Identification */
	{ 0, 0, 0 }
};

unsigned char cd_mode_2a[] = {
	0x2a,0x1c,0x3f,0x3f,0xf0,0x00,0x21,0x00, 	/* 00 - 07 */
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,	/* 08 - 15 */
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,	/* 16 - 23 */
	0x00,0x1b,0x90,0x00,0x00
};

static scsi_page_t cd_mode_pages[] = {
	{ 0x2a, cd_mode_2a, sizeof(cd_mode_2a) },
	{ 0, 0, 0 }
};

static scsi_rom_t cd_rom = {
	.name =		"COCDROM",
	.commands = 	cd_commands,
	.inq = 		cd_inq_pages,
	.mode =		cd_mode_pages,
};
