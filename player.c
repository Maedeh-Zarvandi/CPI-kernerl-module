//OS Final Project
//Maedeh Zarvandi - 9425953
//Zahra Talebi - 9328523

#define pr_fmt(fmt) "[" KBUILD_MODNAME "]: " fmt

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/miscdevice.h>
#include <linux/slab.h>

#include "player.h"

struct player {
	char	*msg;
	bool	first_time;
	int	current_track;
	char Data[6];
	int num;
};
int ret;

#define DEVICE_NAME "player"	/* Dev name as it appears in /proc/devices   */

extern struct song player_cpi_trk1;
extern struct song player_cpi_trk2;
extern struct song player_cpi_trk3;
extern struct song player_cpi_trk4;
extern struct song player_cpi_trk5;
extern struct song player_cpi_trk6;

static struct song *tracks[] = {&player_cpi_trk1,
					&player_cpi_trk2,
					&player_cpi_trk3,
					&player_cpi_trk4,
					&player_cpi_trk5,
					&player_cpi_trk6};

static int device_open(struct inode *inode, struct file *file)
{
	struct player *player;

	player = kzalloc(sizeof(*player), GFP_KERNEL);
	if (!player)
		return -ENOMEM;

	player->first_time = true;
	player->msg = tracks[0]->data;	/* track 1 */
	file->private_data = player;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	struct player *player = file->private_data;

	kfree(player);
	return 0;
}

static ssize_t device_read(struct file *file,
			   char *buffer,
			   size_t length,
			   loff_t *offset)
{
	struct player *player = file->private_data;
	int current_track = player->current_track;

	int bytes_read = 0;

	if (player->first_time == true) {
		pr_info("Now playing track %d - %s\n",
			current_track + 1, tracks[current_track]->name);
		player->first_time = false;
	}

	if (player->msg - tracks[current_track]->data >=
		tracks[current_track]->len) {
		/* End of Track.  Skip to next track, or finish if it's the last track */
		current_track++;
		if (current_track >= ARRAY_SIZE(tracks))
			current_track = 0;
		pr_info("Now playing track %d - %s\n",
			current_track + 1, tracks[current_track]->name);
		player->msg = tracks[current_track]->data;
		player->current_track = current_track;
	}

	while (length &&
		(player->msg - tracks[current_track]->data) <
		 tracks[current_track]->len) {
		put_user(*(player->msg++), buffer++);

		length--;
		bytes_read++;
	}

	return bytes_read;
}

static ssize_t device_write(struct file *filp, const char *buff, size_t len, loff_t *off)
{
	// pr_err("Writing to player - Cycles Per Instruction isn't supported.\n");
	// return -EINVAL;
	ret = copy_from_user(player.Data, buff, len);
	sscanf(player.Data,"%d",&num);
	struct player *player;

	player = kzalloc(sizeof(*player), GFP_KERNEL);
	if (!player)
		return -ENOMEM;

	player->first_time = true;
	player->msg = tracks[num-1]->data;	/* track 1 */
	file->private_data = player;
	return ret;
}

static const struct file_operations fops = {
	.owner = THIS_MODULE,
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static struct miscdevice player_dev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = DEVICE_NAME,
	.fops = &fops,
	.mode = S_IRUGO,
};

static int player_init(void)
{
	int ret;

	ret = misc_register(&player_dev);
	if (ret) {
		pr_err("misc device register failed\n");
		return ret;
	}
	pr_info("player - Cycles Per Instruction - Kernel Module\n");
	pr_info("'ogg123 - < /dev/player' to play.\n");

	return 0;
}

static void player_exit(void)
{
	misc_deregister(&player_dev);
}

module_init(player_init);
module_exit(player_exit);
