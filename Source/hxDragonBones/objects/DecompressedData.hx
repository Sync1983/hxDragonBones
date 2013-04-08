package hxDragonBones.objects;
import haxe.Log;
import nme.utils.ByteArray;

/**
 * @author SlavaRa
 */
class DecompressedData{

	public function new(skeletonXml:Xml, texAtlasXml:Xml, texBytes:ByteArray) {
		this.skeletonXml = skeletonXml;
		this.texAtlasXml = texAtlasXml;
		this.texBytes = texBytes;
	}
	
	public var skeletonXml:Xml;
	public var texAtlasXml:Xml;
	public var texBytes:ByteArray;
	
	public function dispose() {
		skeletonXml = null;
		texAtlasXml = null;
		texBytes = null;
	}
}