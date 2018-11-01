#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/io/ply_io.h>
#include <pcl/visualization/cloud_viewer.h>

int main(int argc, char** argv)
{
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);

    if (pcl::io::loadPLYFile<pcl::PointXYZRGB>("/home/linlinge/Desktop/1.ply", *cloud) == -1) //* load the file
    {
        PCL_ERROR("Couldn't read file test_pcd.pcd \n");
        return (-1);
    }
    pcl::visualization::CloudViewer viewer("Viewer");
    viewer.showCloud(cloud);

    while(!viewer.wasStopped());
    return (0);
}
