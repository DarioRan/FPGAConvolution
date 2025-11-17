# 2025-11-17T15:32:39.270870
import vitis

client = vitis.create_client()
client.set_workspace(path="convolution")

comp = client.create_hls_component(name = "convolution_hls",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

